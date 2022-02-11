void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 ++ ;
#ifdef F_2
if ( V_2 -> V_6 . V_7 & F_3 ( V_8 ) ) {
F_4 ( & V_2 -> V_9 ) ;
V_2 -> V_10 . V_11 ++ ;
F_5 ( & V_2 -> V_9 ) ;
}
#endif
}
static inline int F_6 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 = (struct V_19 * ) V_13 -> V_21 ;
struct V_22 * V_23 = F_7 ( V_13 ) ;
struct V_24 * V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 [ V_29 ] ;
T_1 * V_30 ;
if ( ! F_8 ( V_20 -> V_31 ) ||
F_9 ( V_20 -> V_32 ) )
return 0 ;
if ( ! ( V_23 -> V_33 & V_34 ) )
return 0 ;
if ( V_14 == 0 )
return 0 ;
if ( F_10 ( V_16 ) ) {
F_11 ( V_2 ,
L_1 ) ;
return - 1 ;
}
V_18 = F_12 ( V_16 ) ;
V_30 = ( T_1 * ) V_20 + F_13 ( V_20 -> V_31 ) ;
V_27 = V_30 [ 3 ] >> 6 ;
V_25 = F_14 ( V_18 -> V_25 [ V_27 ] ) ;
if ( ! V_25 )
return - 1 ;
if ( F_15 ( V_20 -> V_31 ) )
V_26 = * F_16 ( V_20 ) & V_35 ;
else
V_26 = 0 ;
if ( V_26 >= V_36 )
return - 1 ;
V_28 [ 0 ] = V_30 [ 7 ] ;
V_28 [ 1 ] = V_30 [ 6 ] ;
V_28 [ 2 ] = V_30 [ 5 ] ;
V_28 [ 3 ] = V_30 [ 4 ] ;
V_28 [ 4 ] = V_30 [ 1 ] ;
V_28 [ 5 ] = V_30 [ 0 ] ;
if ( memcmp ( V_28 , V_25 -> V_37 [ V_14 ] . V_28 [ V_26 ] ,
V_29 ) <= 0 )
return - 1 ;
memcpy ( V_25 -> V_37 [ V_14 ] . V_28 [ V_26 ] , V_28 , V_29 ) ;
V_23 -> V_33 |= V_38 ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 , struct V_19 * V_20 ,
T_2 V_39 , T_1 V_40 ,
struct V_3 * V_4 )
{
struct V_41 * V_42 = F_18 ( V_4 ) ;
struct V_43 * V_44 = ( void * ) V_42 -> V_21 ;
unsigned int V_45 , V_46 , V_47 = 0 ;
unsigned int V_48 = F_13 ( V_20 -> V_31 ) ;
if ( V_44 -> V_49 & V_50 )
V_47 = 2 ;
V_39 -= V_47 ;
V_45 = ( V_39 <= F_19 ( V_13 ) ) ? V_39 :
V_48 + V_40 + 8 ;
V_48 += V_40 ;
memcpy ( F_20 ( V_13 , V_48 ) , V_20 , V_48 ) ;
memcpy ( F_20 ( V_13 , V_45 - V_48 ) , ( T_1 * ) V_20 + V_48 + V_47 ,
V_45 - V_48 ) ;
V_46 = V_39 - V_45 ;
if ( V_46 ) {
int V_51 = ( void * ) V_20 + V_45 + V_47 -
F_18 ( V_4 ) + F_21 ( V_4 ) ;
F_22 ( V_13 , 0 , F_23 ( V_4 ) , V_51 ,
V_46 , V_4 -> V_52 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_12 * V_13 , int V_14 ,
struct V_15 * V_16 )
{
if ( F_6 ( V_2 , V_13 , V_14 , V_16 ) )
F_25 ( V_13 ) ;
else
F_26 ( V_2 -> V_55 , V_13 , V_54 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_22 * V_56 )
{
int V_57 , V_58 , V_59 ;
V_57 = V_44 -> V_57 ;
V_57 = V_57 ? - V_57 : V_60 ;
V_58 = V_44 -> V_58 ;
V_58 = V_58 ? - V_58 : V_60 ;
V_59 = F_28 ( V_57 , V_58 ) ;
F_29 ( V_2 , L_2 ,
V_57 , V_58 , V_59 ) ;
V_56 -> signal = V_59 ;
V_56 -> V_61 = 0 ;
V_56 -> V_62 [ 0 ] = V_57 ;
V_56 -> V_62 [ 1 ] = V_58 ;
V_56 -> V_62 [ 2 ] = V_60 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_22 * V_23 ,
struct V_43 * V_44 , int V_14 ,
T_1 * V_40 )
{
T_2 V_63 = F_31 ( V_44 -> V_63 ) ;
if ( ! F_32 ( V_20 -> V_31 ) ||
( V_63 & V_64 ) ==
V_65 )
return 0 ;
switch ( V_63 & V_64 ) {
case V_66 :
case V_67 :
F_33 ( V_29 != V_68 ) ;
if ( ! ( V_63 & V_69 ) )
return - 1 ;
V_23 -> V_33 |= V_34 ;
* V_40 = V_70 ;
return 0 ;
case V_71 :
if ( ! ( V_63 & V_72 ) )
return 0 ;
* V_40 = V_73 ;
case V_74 :
if ( ! ( V_63 & V_75 ) )
return - 1 ;
V_23 -> V_33 |= V_34 ;
if ( ( V_63 & V_64 ) ==
V_74 )
* V_40 = V_76 ;
return 0 ;
case V_77 :
if ( ! ( V_63 & V_69 ) )
return - 1 ;
V_23 -> V_33 |= V_34 ;
return 0 ;
default:
F_11 ( V_2 , L_3 , V_63 ) ;
}
return 0 ;
}
static void F_34 ( struct V_15 * V_16 ,
struct V_12 * V_13 ,
struct V_43 * V_44 )
{
struct V_17 * V_18 = F_12 ( V_16 ) ;
struct V_78 * V_79 = F_35 ( V_18 -> V_80 ) ;
if ( V_79 -> V_81 & V_82 &&
V_44 -> V_83 & F_3 ( V_84 ) &&
V_44 -> V_83 & F_3 ( V_85 ) )
V_13 -> V_86 = V_87 ;
}
static bool F_36 ( struct V_15 * V_16 , int V_14 ,
struct V_22 * V_56 ,
struct V_19 * V_20 ,
struct V_43 * V_44 )
{
struct V_17 * V_88 ;
struct V_89 * V_90 ;
T_1 V_91 , V_26 , V_92 ;
if ( F_37 ( F_10 ( V_16 ) ) )
return false ;
V_91 = ( F_38 ( V_44 -> V_93 ) &
V_94 ) >>
V_95 ;
if ( V_91 != V_96 )
return false ;
V_88 = F_12 ( V_16 ) ;
V_90 = & V_88 -> V_90 [ V_14 ] ;
if ( F_39 ( V_20 -> V_31 ) ||
F_40 ( V_20 -> V_31 ) ||
F_9 ( V_20 -> V_32 ) ) {
V_56 -> V_33 |= V_97 ;
return false ;
}
if ( F_15 ( V_20 -> V_31 ) )
V_26 = * F_16 ( V_20 ) &
V_35 ;
else
V_26 = V_36 ;
V_92 = V_44 -> V_98 & V_99 ;
if ( F_41 ( F_42 ( V_20 -> V_31 ) &&
V_90 -> V_100 [ V_26 ] == V_20 -> V_101 &&
V_90 -> V_102 [ V_26 ] >= V_92 ) )
return true ;
V_90 -> V_100 [ V_26 ] = V_20 -> V_101 ;
V_90 -> V_102 [ V_26 ] = V_92 ;
V_56 -> V_33 |= V_97 ;
return false ;
}
int F_43 ( struct V_1 * V_2 , T_3 V_103 ,
const T_1 * V_21 , T_3 V_104 )
{
struct V_105 * V_106 ;
T_3 V_107 = sizeof( * V_106 ) + V_104 ;
int V_108 ;
if ( F_37 ( V_104 & 3 || V_104 > V_109 ) )
return - V_110 ;
V_106 = F_44 ( V_107 , V_111 ) ;
if ( ! V_106 )
return - V_112 ;
V_106 -> V_103 = F_45 ( V_103 ) ;
V_106 -> V_104 = F_45 ( V_104 ) ;
V_106 -> V_113 = 0 ;
memcpy ( V_106 -> V_114 , V_21 , V_104 ) ;
V_108 = F_46 ( V_2 ,
F_47 ( V_115 ,
V_116 ) ,
0 , V_107 , V_106 ) ;
F_48 ( V_106 ) ;
return V_108 ;
}
void F_49 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_14 )
{
struct V_41 * V_42 = F_18 ( V_4 ) ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
V_118 = ( void * ) V_42 -> V_21 ;
V_120 = ( void * ) V_118 -> V_114 ;
switch ( V_120 -> type ) {
case V_121 :
break;
default:
F_50 ( 1 , L_4 , V_120 -> type ) ;
}
}
void F_51 ( struct V_1 * V_2 , struct V_53 * V_54 ,
struct V_3 * V_4 , int V_14 )
{
struct V_22 * V_56 ;
struct V_41 * V_42 = F_18 ( V_4 ) ;
struct V_43 * V_44 = ( void * ) V_42 -> V_21 ;
struct V_19 * V_20 = ( void * ) ( V_42 -> V_21 + sizeof( * V_44 ) ) ;
T_3 V_39 = F_31 ( V_44 -> V_122 ) ;
T_3 V_123 = F_38 ( V_44 -> V_123 ) ;
struct V_15 * V_16 = NULL ;
struct V_12 * V_13 ;
T_1 V_40 = 0 ;
V_13 = F_52 ( 128 , V_124 ) ;
if ( ! V_13 ) {
F_11 ( V_2 , L_5 ) ;
return;
}
V_56 = F_7 ( V_13 ) ;
if ( F_30 ( V_2 , V_20 , V_56 , V_44 , V_14 , & V_40 ) ) {
F_25 ( V_13 ) ;
return;
}
if ( ! ( V_44 -> V_63 & F_3 ( V_125 ) ) ||
! ( V_44 -> V_63 & F_3 ( V_126 ) ) ) {
F_53 ( V_2 , L_6 ,
F_31 ( V_44 -> V_63 ) ) ;
V_56 -> V_33 |= V_127 ;
}
V_56 -> V_128 = F_54 ( V_44 -> V_129 ) ;
V_56 -> V_130 = F_38 ( V_44 -> V_131 ) ;
V_56 -> V_132 = V_44 -> V_133 > 14 ? V_134 :
V_135 ;
V_56 -> V_136 = F_55 ( V_44 -> V_133 ,
V_56 -> V_132 ) ;
F_27 ( V_2 , V_44 , V_56 ) ;
V_56 -> V_33 |= V_137 ;
F_56 () ;
if ( F_31 ( V_44 -> V_63 ) & V_138 ) {
T_1 V_139 = V_44 -> V_140 & V_141 ;
if ( ! F_57 ( V_139 >= V_142 ) ) {
V_16 = F_14 ( V_2 -> V_143 [ V_139 ] ) ;
if ( F_58 ( V_16 ) )
V_16 = NULL ;
}
} else if ( ! F_9 ( V_20 -> V_144 ) ) {
V_16 = F_59 ( V_2 -> V_55 , V_20 -> V_144 , NULL ) ;
}
if ( V_16 ) {
struct V_17 * V_18 = F_12 ( V_16 ) ;
if ( F_41 ( V_2 -> V_145 ) )
F_60 ( V_2 , V_16 , false ) ;
F_61 ( V_2 , & V_18 -> V_146 , V_56 ) ;
if ( F_62 ( V_2 -> V_147 , V_148 ) &&
F_63 ( V_20 -> V_31 ) ) {
struct V_149 * V_150 ;
struct V_151 * V_152 ;
bool V_153 ;
T_4 V_154 ;
V_150 = F_64 ( V_2 -> V_147 ,
V_148 ) ;
V_152 = ( void * ) V_150 -> V_21 ;
V_154 = F_38 ( V_152 -> V_154 ) ;
V_153 =
F_65 ( V_2 , V_18 -> V_80 ,
V_150 ) ;
if ( V_153 && V_56 -> signal < V_154 )
F_66 ( V_2 , V_150 , NULL ) ;
}
if ( F_8 ( V_20 -> V_31 ) )
F_34 ( V_16 , V_13 , V_44 ) ;
if ( F_36 ( V_16 , V_14 , V_56 , V_20 , V_44 ) ) {
F_25 ( V_13 ) ;
F_67 () ;
return;
}
if ( ( V_44 -> V_49 & V_155 ) &&
! F_37 ( ! F_15 ( V_20 -> V_31 ) ) ) {
T_1 * V_156 = F_16 ( V_20 ) ;
* V_156 &= ~ V_157 ;
}
}
switch ( V_123 & V_158 ) {
case V_159 :
break;
case V_160 :
V_56 -> V_33 |= V_161 ;
break;
case V_162 :
V_56 -> V_163 |= V_164 ;
break;
case V_165 :
V_56 -> V_163 |= V_166 ;
break;
}
if ( V_123 & V_167 )
V_56 -> V_33 |= V_168 ;
if ( V_123 & V_169 )
V_56 -> V_33 |= V_170 ;
if ( V_123 & V_171 )
V_56 -> V_33 |= V_172 ;
if ( V_123 & V_173 ) {
T_1 V_174 = ( V_123 & V_175 ) >>
V_176 ;
V_56 -> V_33 |= V_177 ;
V_56 -> V_178 = V_123 & V_179 ;
V_56 -> V_33 |= V_174 << V_180 ;
} else if ( V_123 & V_181 ) {
T_1 V_174 = ( V_123 & V_182 ) >>
V_176 ;
V_56 -> V_183 =
( ( V_123 & V_184 ) >>
V_185 ) + 1 ;
V_56 -> V_178 = V_123 & V_186 ;
V_56 -> V_33 |= V_187 ;
V_56 -> V_33 |= V_174 << V_180 ;
if ( V_123 & V_188 )
V_56 -> V_163 |= V_189 ;
} else {
V_56 -> V_178 =
F_68 ( V_123 ,
V_56 -> V_132 ) ;
}
F_17 ( V_13 , V_20 , V_39 , V_40 , V_4 ) ;
F_24 ( V_2 , V_54 , V_13 , V_14 , V_16 ) ;
F_67 () ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_14 )
{
}
