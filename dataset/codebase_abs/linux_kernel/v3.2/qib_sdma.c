static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_3 * V_3 )
{
struct V_1 * V_2 =
F_4 ( V_3 , struct V_1 , V_3 ) ;
F_5 ( & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_3 , F_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_9 ( & V_2 -> V_4 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 , * V_9 ;
F_11 (txp, txp_next, &ppd->sdma_activelist, list) {
F_12 ( & V_8 -> V_10 ) ;
if ( V_8 -> V_11 & V_12 ) {
unsigned V_13 ;
V_13 = V_8 -> V_14 ;
while ( V_13 != V_8 -> V_15 ) {
F_13 ( V_6 , V_13 ) ;
if ( ++ V_13 == V_6 -> V_16 )
V_13 = 0 ;
}
}
if ( V_8 -> V_17 )
(* V_8 -> V_17 )( V_8 , V_18 ) ;
}
}
static void F_14 ( unsigned long V_19 )
{
struct V_5 * V_6 = (struct V_5 * ) V_19 ;
unsigned long V_11 ;
F_15 ( & V_6 -> V_20 , V_11 ) ;
F_16 ( V_6 ) ;
F_10 ( V_6 ) ;
V_6 -> V_21 = V_6 -> V_22 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_25 [ 0 ] = 0 ;
V_6 -> V_26 = 0 ;
F_17 ( V_6 , V_27 ) ;
F_18 ( & V_6 -> V_20 , V_11 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_28 ;
unsigned V_29 ;
for ( V_29 = V_2 -> V_30 ; V_29 < V_2 -> V_31 ; ++ V_29 )
V_6 -> V_32 -> V_33 ( V_6 , F_20 ( V_29 ) ) ;
V_6 -> V_32 -> V_34 ( V_6 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_28 ;
F_6 ( V_2 ) ;
}
static void F_22 ( struct V_5 * V_6 )
{
F_23 ( & V_6 -> F_14 ) ;
}
static void F_24 ( struct V_5 * V_6 ,
enum V_35 V_36 )
{
struct V_1 * V_2 = & V_6 -> V_28 ;
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned V_40 = 0 ;
V_2 -> V_41 = V_2 -> V_42 ;
V_2 -> V_43 = V_2 -> V_44 ;
V_2 -> V_42 = V_36 ;
if ( V_38 [ V_36 ] . V_45 )
V_40 |= V_46 ;
if ( V_38 [ V_36 ] . V_47 )
V_40 |= V_48 ;
if ( V_38 [ V_36 ] . V_49 )
V_40 |= V_50 ;
if ( V_38 [ V_36 ] . V_51 )
V_40 |= V_52 ;
if ( V_38 [ V_36 ] . V_53 )
V_2 -> V_54 = 0 ;
if ( V_38 [ V_36 ] . V_55 )
V_2 -> V_54 = 1 ;
V_2 -> V_44 = V_40 ;
V_6 -> V_32 -> V_56 ( V_6 , V_2 -> V_44 ) ;
}
static void F_13 ( struct V_5 * V_6 , unsigned V_57 )
{
T_1 * V_58 = & V_6 -> V_59 [ V_57 ] . V_60 [ 0 ] ;
T_2 V_61 [ 2 ] ;
T_3 V_62 ;
T_4 V_63 ;
V_61 [ 0 ] = F_25 ( V_58 [ 0 ] ) ;
V_61 [ 1 ] = F_25 ( V_58 [ 1 ] ) ;
V_62 = ( V_61 [ 1 ] << 32 ) | ( V_61 [ 0 ] >> 32 ) ;
V_63 = ( V_61 [ 0 ] >> 14 ) & ( 0x7ffULL << 2 ) ;
F_26 ( & V_6 -> V_32 -> V_64 -> V_65 , V_62 , V_63 , V_66 ) ;
}
static int F_27 ( struct V_5 * V_6 )
{
V_6 -> V_16 = V_16 ;
if ( ! V_6 -> V_16 )
V_6 -> V_16 = 256 ;
V_6 -> V_59 = F_28 ( & V_6 -> V_32 -> V_64 -> V_65 ,
V_6 -> V_16 * sizeof( T_2 [ 2 ] ) , & V_6 -> V_67 ,
V_68 ) ;
if ( ! V_6 -> V_59 ) {
F_29 ( V_6 -> V_32 , L_1
L_2 ) ;
goto V_69;
}
V_6 -> V_25 = F_28 ( & V_6 -> V_32 -> V_64 -> V_65 ,
V_70 , & V_6 -> V_71 , V_68 ) ;
if ( ! V_6 -> V_25 ) {
F_29 ( V_6 -> V_32 , L_3
L_4 ) ;
goto V_72;
}
V_6 -> V_25 [ 0 ] = 0 ;
return 0 ;
V_72:
F_30 ( & V_6 -> V_32 -> V_64 -> V_65 ,
V_6 -> V_16 * sizeof( T_2 [ 2 ] ) , ( void * ) V_6 -> V_59 ,
V_6 -> V_67 ) ;
V_6 -> V_59 = NULL ;
V_6 -> V_67 = 0 ;
V_69:
V_6 -> V_16 = 0 ;
return - V_73 ;
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_74 * V_32 = V_6 -> V_32 ;
if ( V_6 -> V_25 ) {
F_30 ( & V_32 -> V_64 -> V_65 , V_70 ,
( void * ) V_6 -> V_25 ,
V_6 -> V_71 ) ;
V_6 -> V_25 = NULL ;
V_6 -> V_71 = 0 ;
}
if ( V_6 -> V_59 ) {
F_30 ( & V_32 -> V_64 -> V_65 ,
V_6 -> V_16 * sizeof( T_2 [ 2 ] ) ,
V_6 -> V_59 , V_6 -> V_67 ) ;
V_6 -> V_59 = NULL ;
V_6 -> V_67 = 0 ;
}
}
static inline void F_32 ( struct V_5 * V_6 ,
T_2 * V_75 , T_2 V_62 , T_2 V_76 ,
T_2 V_77 )
{
F_33 ( V_62 & 3 ) ;
V_75 [ 1 ] = V_62 >> 32 ;
V_75 [ 0 ] = ( V_62 & 0xfffffffcULL ) << 32 ;
V_75 [ 0 ] |= ( V_6 -> V_26 & 3ULL ) <<
V_78 ;
V_75 [ 0 ] |= ( V_76 & 0x7ffULL ) << V_79 ;
V_75 [ 0 ] |= V_77 & 0x7ffULL ;
}
int F_16 ( struct V_5 * V_6 )
{
struct V_80 * V_81 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_74 * V_32 = V_6 -> V_32 ;
int V_82 = 0 ;
T_5 V_83 ;
T_5 V_13 = 0 ;
V_83 = V_32 -> V_84 ( V_6 ) ;
if ( ! F_34 ( & V_6 -> V_85 ) ) {
V_81 = V_6 -> V_85 . V_86 ;
V_8 = F_35 ( V_81 , struct V_7 , V_10 ) ;
V_13 = V_8 -> V_14 ;
}
while ( V_6 -> V_24 != V_83 ) {
if ( V_8 && ( V_8 -> V_11 & V_12 ) &&
( V_13 == V_6 -> V_24 ) ) {
F_13 ( V_6 , V_6 -> V_24 ) ;
if ( ++ V_13 == V_6 -> V_16 )
V_13 = 0 ;
}
V_6 -> V_21 ++ ;
if ( ++ V_6 -> V_24 == V_6 -> V_16 )
V_6 -> V_24 = 0 ;
if ( V_8 && V_8 -> V_15 == V_6 -> V_24 ) {
F_12 ( & V_8 -> V_10 ) ;
if ( V_8 -> V_17 )
(* V_8 -> V_17 )( V_8 , V_87 ) ;
if ( F_34 ( & V_6 -> V_85 ) )
V_8 = NULL ;
else {
V_81 = V_6 -> V_85 . V_86 ;
V_8 = F_35 ( V_81 , struct V_7 ,
V_10 ) ;
V_13 = V_8 -> V_14 ;
}
}
V_82 = 1 ;
}
if ( V_82 )
F_36 ( V_6 , F_37 ( V_6 ) ) ;
return V_82 ;
}
void F_38 ( struct V_5 * V_6 )
{
unsigned long V_11 ;
F_15 ( & V_6 -> V_20 , V_11 ) ;
F_39 ( V_6 ) ;
F_18 ( & V_6 -> V_20 , V_11 ) ;
}
void F_39 ( struct V_5 * V_6 )
{
if ( F_40 ( V_6 ) )
F_16 ( V_6 ) ;
}
int F_41 ( struct V_5 * V_6 )
{
struct V_74 * V_32 = V_6 -> V_32 ;
unsigned long V_11 ;
int V_88 = 0 ;
V_88 = F_27 ( V_6 ) ;
if ( V_88 )
goto V_69;
V_6 -> V_32 -> V_89 ( V_6 ) ;
F_15 ( & V_6 -> V_20 , V_11 ) ;
F_24 ( V_6 , V_90 ) ;
F_18 ( & V_6 -> V_20 , V_11 ) ;
F_42 ( & V_6 -> V_28 . V_3 ) ;
F_43 ( & V_6 -> V_28 . V_4 ) ;
V_6 -> V_26 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
F_44 ( & V_6 -> V_85 ) ;
F_45 ( & V_6 -> F_14 , F_14 ,
( unsigned long ) V_6 ) ;
V_88 = V_32 -> V_91 ( V_6 ) ;
if ( V_88 )
goto V_92;
F_46 ( V_6 , V_93 ) ;
return 0 ;
V_92:
F_47 ( V_6 ) ;
V_69:
return V_88 ;
}
void F_47 ( struct V_5 * V_6 )
{
F_46 ( V_6 , V_94 ) ;
F_8 ( & V_6 -> V_28 ) ;
F_31 ( V_6 ) ;
}
int F_48 ( struct V_5 * V_6 )
{
unsigned long V_11 ;
int V_88 ;
F_15 ( & V_6 -> V_20 , V_11 ) ;
V_88 = F_40 ( V_6 ) ;
F_18 ( & V_6 -> V_20 , V_11 ) ;
return V_88 ;
}
static void F_49 ( struct V_5 * V_6 ,
struct V_95 * V_96 )
{
F_50 ( & V_96 -> V_97 -> V_98 ) ;
V_96 -> V_99 . V_14 = 0 ;
V_96 -> V_99 . V_15 = 0 ;
F_51 ( & V_96 -> V_99 . V_10 , & V_6 -> V_85 ) ;
F_10 ( V_6 ) ;
}
int F_52 ( struct V_5 * V_6 ,
struct V_100 * V_2 , T_6 V_101 ,
struct V_95 * V_96 )
{
unsigned long V_11 ;
struct V_102 * V_103 ;
struct V_104 * V_97 ;
int V_88 = 0 ;
T_5 V_105 ;
T_1 * V_58 ;
T_2 V_75 [ 2 ] ;
T_6 V_77 ;
T_3 V_62 ;
F_15 ( & V_6 -> V_20 , V_11 ) ;
V_106:
if ( F_53 ( ! F_40 ( V_6 ) ) ) {
F_49 ( V_6 , V_96 ) ;
goto V_107;
}
if ( V_96 -> V_99 . V_108 > F_37 ( V_6 ) ) {
if ( F_16 ( V_6 ) )
goto V_106;
if ( V_6 -> V_32 -> V_11 & V_109 )
V_6 -> V_32 -> V_110 ( V_6 ,
V_6 -> V_16 / 2 ) ;
goto V_111;
}
V_77 = V_96 -> V_112 ;
F_32 ( V_6 , V_75 , ( T_2 ) V_96 -> V_99 . V_62 , V_77 , 0 ) ;
V_75 [ 0 ] |= V_113 ;
if ( V_96 -> V_99 . V_11 & V_114 )
V_75 [ 0 ] |= V_115 ;
V_105 = V_6 -> V_23 ;
V_58 = & V_6 -> V_59 [ V_105 ] . V_60 [ 0 ] ;
* V_58 ++ = F_54 ( V_75 [ 0 ] ) ;
* V_58 ++ = F_54 ( V_75 [ 1 ] ) ;
if ( ++ V_105 == V_6 -> V_16 ) {
V_105 = 0 ;
V_58 = & V_6 -> V_59 [ 0 ] . V_60 [ 0 ] ;
++ V_6 -> V_26 ;
}
V_96 -> V_99 . V_14 = V_105 ;
V_103 = & V_2 -> V_103 ;
while ( V_101 ) {
T_6 V_116 ;
T_6 V_63 ;
V_63 = V_101 << 2 ;
if ( V_63 > V_103 -> V_117 )
V_63 = V_103 -> V_117 ;
if ( V_63 > V_103 -> V_118 )
V_63 = V_103 -> V_118 ;
F_55 ( V_63 == 0 ) ;
V_116 = ( V_63 + 3 ) >> 2 ;
V_62 = F_56 ( & V_6 -> V_32 -> V_64 -> V_65 , V_103 -> V_119 ,
V_116 << 2 , V_66 ) ;
if ( F_57 ( & V_6 -> V_32 -> V_64 -> V_65 , V_62 ) )
goto V_120;
V_75 [ 0 ] = 0 ;
F_32 ( V_6 , V_75 , ( T_2 ) V_62 , V_116 , V_77 ) ;
if ( V_96 -> V_99 . V_11 & V_114 )
V_75 [ 0 ] |= V_115 ;
* V_58 ++ = F_54 ( V_75 [ 0 ] ) ;
* V_58 ++ = F_54 ( V_75 [ 1 ] ) ;
if ( ++ V_105 == V_6 -> V_16 ) {
V_105 = 0 ;
V_58 = & V_6 -> V_59 [ 0 ] . V_60 [ 0 ] ;
++ V_6 -> V_26 ;
}
V_103 -> V_119 += V_63 ;
V_103 -> V_117 -= V_63 ;
V_103 -> V_118 -= V_63 ;
if ( V_103 -> V_118 == 0 ) {
if ( -- V_2 -> V_121 )
* V_103 = * V_2 -> V_122 ++ ;
} else if ( V_103 -> V_117 == 0 && V_103 -> V_123 -> V_124 ) {
if ( ++ V_103 -> V_125 >= V_126 ) {
if ( ++ V_103 -> V_127 >= V_103 -> V_123 -> V_128 )
break;
V_103 -> V_125 = 0 ;
}
V_103 -> V_119 =
V_103 -> V_123 -> V_129 [ V_103 -> V_127 ] -> V_130 [ V_103 -> V_125 ] . V_119 ;
V_103 -> V_117 =
V_103 -> V_123 -> V_129 [ V_103 -> V_127 ] -> V_130 [ V_103 -> V_125 ] . V_117 ;
}
V_77 += V_116 ;
V_101 -= V_116 ;
}
if ( ! V_105 )
V_58 = & V_6 -> V_59 [ V_6 -> V_16 ] . V_60 [ 0 ] ;
V_58 -= 2 ;
V_58 [ 0 ] |= F_54 ( V_131 ) ;
if ( V_96 -> V_99 . V_11 & V_132 )
V_58 [ 0 ] |= F_54 ( V_133 ) ;
if ( V_96 -> V_99 . V_11 & V_134 )
V_58 [ 0 ] |= F_54 ( V_135 ) ;
F_50 ( & V_96 -> V_97 -> V_98 ) ;
V_96 -> V_99 . V_15 = V_105 ;
V_6 -> V_32 -> V_136 ( V_6 , V_105 ) ;
V_6 -> V_22 += V_96 -> V_99 . V_108 ;
F_51 ( & V_96 -> V_99 . V_10 , & V_6 -> V_85 ) ;
goto V_107;
V_120:
for (; ; ) {
if ( ! V_105 )
V_105 = V_6 -> V_16 - 1 ;
else
V_105 -- ;
if ( V_105 == V_6 -> V_23 )
break;
F_13 ( V_6 , V_105 ) ;
}
V_97 = V_96 -> V_97 ;
F_58 ( V_96 ) ;
F_59 ( & V_97 -> V_137 ) ;
F_59 ( & V_97 -> V_138 ) ;
if ( V_97 -> V_139 . V_140 == V_141 ) {
if ( V_142 [ V_97 -> V_143 ] & V_144 )
F_60 ( V_97 , V_145 ) ;
} else if ( V_97 -> V_146 )
F_61 ( V_97 , V_97 -> V_146 , V_145 ) ;
F_62 ( & V_97 -> V_138 ) ;
F_62 ( & V_97 -> V_137 ) ;
goto V_107;
V_111:
V_97 = V_96 -> V_97 ;
F_59 ( & V_97 -> V_138 ) ;
if ( V_142 [ V_97 -> V_143 ] & V_144 ) {
struct V_147 * V_65 ;
V_96 -> V_2 = V_2 ;
V_96 -> V_101 = V_101 ;
V_97 -> V_148 = V_96 ;
V_65 = & V_6 -> V_32 -> V_149 ;
F_59 ( & V_65 -> V_150 ) ;
if ( F_34 ( & V_97 -> V_151 ) ) {
struct V_152 * V_153 ;
V_153 = & V_6 -> V_154 ;
V_153 -> V_155 ++ ;
V_97 -> V_156 |= V_157 ;
F_51 ( & V_97 -> V_151 , & V_65 -> V_158 ) ;
}
F_62 ( & V_65 -> V_150 ) ;
V_97 -> V_156 &= ~ V_159 ;
F_62 ( & V_97 -> V_138 ) ;
V_88 = - V_160 ;
} else {
F_62 ( & V_97 -> V_138 ) ;
F_58 ( V_96 ) ;
}
V_107:
F_18 ( & V_6 -> V_20 , V_11 ) ;
return V_88 ;
}
void F_46 ( struct V_5 * V_6 ,
enum V_161 V_162 )
{
unsigned long V_11 ;
F_15 ( & V_6 -> V_20 , V_11 ) ;
F_17 ( V_6 , V_162 ) ;
if ( V_6 -> V_28 . V_42 == V_163 )
F_36 ( V_6 , F_37 ( V_6 ) ) ;
F_18 ( & V_6 -> V_20 , V_11 ) ;
}
void F_17 ( struct V_5 * V_6 ,
enum V_161 V_162 )
{
struct V_1 * V_2 = & V_6 -> V_28 ;
switch ( V_2 -> V_42 ) {
case V_90 :
switch ( V_162 ) {
case V_94 :
break;
case V_164 :
V_2 -> V_54 = 1 ;
case V_93 :
F_1 ( & V_6 -> V_28 ) ;
F_24 ( V_6 ,
V_165 ) ;
break;
case V_166 :
break;
case V_27 :
F_21 ( V_6 ) ;
break;
case V_167 :
break;
case V_168 :
break;
case V_169 :
break;
case V_170 :
break;
case V_171 :
break;
case V_172 :
break;
}
break;
case V_165 :
switch ( V_162 ) {
case V_94 :
F_24 ( V_6 , V_90 ) ;
F_21 ( V_6 ) ;
break;
case V_93 :
break;
case V_166 :
F_24 ( V_6 , V_2 -> V_54 ?
V_163 :
V_173 ) ;
break;
case V_164 :
V_2 -> V_54 = 1 ;
break;
case V_27 :
break;
case V_167 :
break;
case V_168 :
break;
case V_169 :
V_2 -> V_54 = 0 ;
break;
case V_170 :
break;
case V_171 :
break;
case V_172 :
break;
}
break;
case V_173 :
switch ( V_162 ) {
case V_94 :
F_24 ( V_6 , V_90 ) ;
F_21 ( V_6 ) ;
break;
case V_93 :
break;
case V_166 :
break;
case V_164 :
F_24 ( V_6 , V_163 ) ;
V_2 -> V_54 = 1 ;
break;
case V_27 :
break;
case V_167 :
break;
case V_168 :
break;
case V_169 :
break;
case V_170 :
break;
case V_171 :
break;
case V_172 :
break;
}
break;
case V_174 :
switch ( V_162 ) {
case V_94 :
F_24 ( V_6 , V_90 ) ;
break;
case V_93 :
break;
case V_166 :
break;
case V_164 :
V_2 -> V_54 = 1 ;
break;
case V_27 :
F_24 ( V_6 ,
V_165 ) ;
F_19 ( V_6 ) ;
break;
case V_167 :
break;
case V_168 :
break;
case V_169 :
V_2 -> V_54 = 0 ;
break;
case V_170 :
break;
case V_171 :
break;
case V_172 :
break;
}
break;
case V_175 :
switch ( V_162 ) {
case V_94 :
F_24 ( V_6 , V_90 ) ;
F_22 ( V_6 ) ;
break;
case V_93 :
break;
case V_166 :
break;
case V_164 :
V_2 -> V_54 = 1 ;
break;
case V_27 :
break;
case V_167 :
F_24 ( V_6 ,
V_174 ) ;
F_22 ( V_6 ) ;
break;
case V_168 :
break;
case V_169 :
V_2 -> V_54 = 0 ;
break;
case V_170 :
break;
case V_171 :
break;
case V_172 :
break;
}
break;
case V_176 :
switch ( V_162 ) {
case V_94 :
F_24 ( V_6 , V_90 ) ;
F_22 ( V_6 ) ;
break;
case V_93 :
break;
case V_166 :
break;
case V_164 :
V_2 -> V_54 = 1 ;
break;
case V_27 :
break;
case V_167 :
break;
case V_168 :
F_24 ( V_6 ,
V_175 ) ;
V_6 -> V_32 -> V_177 ( V_6 ) ;
break;
case V_169 :
V_2 -> V_54 = 0 ;
break;
case V_170 :
break;
case V_171 :
break;
case V_172 :
break;
}
break;
case V_163 :
switch ( V_162 ) {
case V_94 :
F_24 ( V_6 , V_90 ) ;
F_22 ( V_6 ) ;
break;
case V_93 :
break;
case V_166 :
break;
case V_164 :
break;
case V_27 :
break;
case V_167 :
break;
case V_168 :
F_24 ( V_6 ,
V_174 ) ;
F_22 ( V_6 ) ;
break;
case V_169 :
F_24 ( V_6 , V_176 ) ;
V_2 -> V_54 = 0 ;
break;
case V_170 :
F_24 ( V_6 ,
V_174 ) ;
F_22 ( V_6 ) ;
break;
case V_171 :
F_24 ( V_6 , V_176 ) ;
break;
case V_172 :
break;
}
break;
}
V_2 -> V_178 = V_162 ;
}
