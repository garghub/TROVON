static inline
struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = V_2 + 1 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 + 1 ;
struct V_6 * V_8 ;
struct V_1 * V_9 ;
int V_10 ;
if ( V_2 >= V_4 -> V_11 ) {
V_9 = V_4 -> V_11 ;
V_10 = V_4 -> V_12 ;
V_8 = (struct V_6 * ) V_4 -> V_11 ;
} else {
V_9 = V_4 -> V_13 ;
V_10 = V_4 -> V_14 ;
V_8 = (struct V_6 * ) V_4 -> V_13 ;
}
if ( V_4 -> V_6 )
return (struct V_1 * ) ( ( V_7 >= ( V_8 + V_10 ) ) ?
V_8 : V_7 ) ;
else
return ( V_5 >= ( V_9 + V_10 ) ) ?
V_9 : V_5 ;
}
static inline
struct V_1 * F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = V_2 - 1 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 - 1 ;
struct V_6 * V_8 ;
struct V_1 * V_9 ;
int V_10 ;
if ( V_2 >= V_4 -> V_11 ) {
V_9 = V_4 -> V_11 ;
V_10 = V_4 -> V_12 ;
V_8 = (struct V_6 * ) V_4 -> V_11 ;
} else {
V_9 = V_4 -> V_13 ;
V_10 = V_4 -> V_14 ;
V_8 = (struct V_6 * ) V_4 -> V_13 ;
}
if ( V_4 -> V_6 )
return (struct V_1 * ) ( ( V_7 < V_8 ) ?
( V_7 + V_10 ) : V_7 ) ;
else
return ( V_5 < V_9 ) ? ( V_5 + V_10 ) : V_5 ;
}
static void * F_3 ( void * V_15 , int V_16 )
{
int V_17 ;
unsigned int * V_18 = V_15 ;
for ( V_17 = 0 ; V_17 < F_4 ( V_16 , 4 ) ; V_17 ++ , V_18 ++ )
* V_18 = F_5 ( * V_18 ) ;
return V_15 ;
}
static int
F_6 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
if ( V_20 -> V_23 != V_24 )
return 0 ;
if ( F_7 ( F_8 ( V_20 , 0 ) ) )
return - 1 ;
* ( V_25 * ) ( V_20 -> V_26 + V_20 -> V_27 + V_20 -> V_28 ) = 0 ;
return 0 ;
}
static T_1
F_9 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
struct V_1 * V_2 , * V_32 ;
void * V_15 ;
unsigned short V_33 ;
unsigned int V_34 ;
V_2 = V_4 -> V_35 ;
V_33 = V_2 -> V_36 ;
if ( V_33 & V_37 ) {
F_12 ( V_22 , L_1 ) ;
return V_38 ;
}
if ( F_6 ( V_20 , V_22 ) ) {
F_13 ( V_20 ) ;
return V_39 ;
}
V_33 &= ~ V_40 ;
V_15 = V_20 -> V_41 ;
V_2 -> V_42 = V_20 -> V_16 ;
if ( V_4 -> V_6 )
V_34 = (struct V_6 * ) V_2 -
(struct V_6 * ) V_4 -> V_11 ;
else
V_34 = V_2 - V_4 -> V_11 ;
if ( ( ( unsigned long ) V_15 ) & V_43 ) {
memcpy ( V_4 -> V_44 [ V_34 ] , V_20 -> V_41 , V_20 -> V_16 ) ;
V_15 = V_4 -> V_44 [ V_34 ] ;
}
if ( V_30 -> V_45 & V_46 )
F_3 ( V_15 , V_20 -> V_16 ) ;
V_4 -> V_47 [ V_34 ] = V_20 ;
V_2 -> V_48 = F_14 ( & V_4 -> V_31 -> V_49 , V_15 ,
V_20 -> V_16 , V_50 ) ;
if ( F_15 ( & V_4 -> V_31 -> V_49 , V_2 -> V_48 ) ) {
V_2 -> V_48 = 0 ;
V_4 -> V_47 [ V_34 ] = NULL ;
F_16 ( V_20 ) ;
if ( F_17 () )
F_12 ( V_22 , L_2 ) ;
return V_39 ;
}
if ( V_4 -> V_6 ) {
struct V_6 * V_51 = (struct V_6 * ) V_2 ;
V_51 -> V_52 = 0 ;
if ( F_7 ( F_18 ( V_20 ) -> V_53 & V_54 &&
V_4 -> V_55 ) ) {
V_51 -> V_56 = ( V_57 | V_58 ) ;
F_18 ( V_20 ) -> V_53 |= V_59 ;
} else {
V_51 -> V_56 = V_58 ;
if ( V_20 -> V_23 == V_24 )
V_51 -> V_56 |= V_60 ;
}
}
V_33 |= ( V_37 | V_61
| V_62 | V_63 ) ;
V_2 -> V_36 = V_33 ;
V_32 = F_2 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_45 & V_64 ) &&
! ( V_32 -> V_36 & V_37 ) ) {
V_4 -> V_65 . V_66 = true ;
F_19 ( & ( V_4 -> V_65 . V_65 ) ,
F_20 ( 1 ) ) ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
F_21 ( V_20 ) ;
V_4 -> V_35 = V_2 ;
if ( V_4 -> V_35 == V_4 -> V_67 )
F_22 ( V_22 ) ;
F_23 ( 0 , V_4 -> V_68 + V_69 ) ;
return V_39 ;
}
static void F_24 ( struct V_21 * V_49 )
{
struct V_3 * V_4 = F_10 ( V_49 ) ;
struct V_1 * V_2 ;
unsigned int V_17 ;
V_2 = V_4 -> V_13 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_14 ; V_17 ++ ) {
if ( V_2 -> V_48 )
V_2 -> V_36 = V_70 ;
else
V_2 -> V_36 = 0 ;
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_36 |= V_71 ;
V_4 -> V_72 = V_4 -> V_13 ;
V_2 = V_4 -> V_11 ;
V_4 -> V_35 = V_2 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_12 ; V_17 ++ ) {
V_2 -> V_36 = 0 ;
if ( V_2 -> V_48 && V_4 -> V_47 [ V_17 ] ) {
F_16 ( V_4 -> V_47 [ V_17 ] ) ;
V_4 -> V_47 [ V_17 ] = NULL ;
}
V_2 -> V_48 = 0 ;
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_36 |= V_71 ;
V_4 -> V_67 = V_2 ;
}
static void
F_25 ( struct V_21 * V_22 , int V_73 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
int V_17 ;
T_2 V_74 ;
T_2 V_75 [ 2 ] ;
T_2 V_76 = V_77 | 0x04 ;
T_2 V_78 = 0x2 ;
if ( F_26 ( V_22 ) ) {
F_27 ( V_22 ) ;
F_28 ( & V_4 -> V_79 ) ;
F_22 ( V_22 ) ;
F_29 ( V_22 ) ;
}
F_23 ( 1 , V_4 -> V_68 + V_80 ) ;
F_30 ( 10 ) ;
if ( V_30 -> V_45 & V_81 ) {
memcpy ( & V_75 , V_22 -> V_82 , V_83 ) ;
F_23 ( F_5 ( V_75 [ 0 ] ) , V_4 -> V_68 + V_84 ) ;
F_23 ( F_5 ( V_75 [ 1 ] ) , V_4 -> V_68 + V_85 ) ;
}
F_23 ( 0xffc00000 , V_4 -> V_68 + V_86 ) ;
F_23 ( V_87 , V_4 -> V_68 + V_88 ) ;
F_24 ( V_22 ) ;
F_23 ( V_4 -> V_89 , V_4 -> V_68 + V_90 ) ;
if ( V_4 -> V_6 )
F_23 ( ( unsigned long ) V_4 -> V_89 + sizeof( struct V_6 )
* V_4 -> V_14 , V_4 -> V_68 + V_91 ) ;
else
F_23 ( ( unsigned long ) V_4 -> V_89 + sizeof( struct V_1 )
* V_4 -> V_14 , V_4 -> V_68 + V_91 ) ;
for ( V_17 = 0 ; V_17 <= V_92 ; V_17 ++ ) {
if ( V_4 -> V_47 [ V_17 ] ) {
F_16 ( V_4 -> V_47 [ V_17 ] ) ;
V_4 -> V_47 [ V_17 ] = NULL ;
}
}
if ( V_73 ) {
F_23 ( 0x04 , V_4 -> V_68 + V_93 ) ;
} else {
V_76 |= 0x02 ;
F_23 ( 0x0 , V_4 -> V_68 + V_93 ) ;
}
V_4 -> V_94 = V_73 ;
F_23 ( V_4 -> V_95 , V_4 -> V_68 + V_96 ) ;
#if ! F_31 ( V_97 )
V_74 = F_32 ( V_4 -> V_68 + V_98 ) ;
if ( V_4 -> V_99 & V_100 )
V_74 |= V_101 ;
else
V_74 &= ~ V_101 ;
F_23 ( V_74 , V_4 -> V_68 + V_98 ) ;
#endif
if ( V_30 -> V_45 & V_81 ) {
V_76 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_102 == V_103 )
V_76 |= ( 1 << 6 ) ;
else if ( V_4 -> V_102 == V_104 )
V_76 |= ( 1 << 8 ) ;
else
V_76 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_105 ) {
if ( V_4 -> V_105 -> V_106 == V_107 )
V_78 |= ( 1 << 5 ) ;
else if ( V_4 -> V_105 -> V_106 == V_108 )
V_76 &= ~ ( 1 << 9 ) ;
else
V_76 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_33
if ( V_30 -> V_45 & V_109 ) {
T_2 V_110 ;
F_23 ( 0 , V_4 -> V_68 + F_33 ) ;
while ( F_32 ( V_4 -> V_68 + F_33 ) & 4 )
F_30 ( 1 ) ;
V_110 = ( V_4 -> V_102 == V_104 )
? V_111 : V_112 ;
if ( V_4 -> V_105 && V_4 -> V_105 -> V_106 == V_113 )
V_110 |= V_114 ;
F_23 ( V_110 , V_4 -> V_68 + V_115 ) ;
F_23 ( 2 , V_4 -> V_68 + F_33 ) ;
}
#endif
}
#if ! F_31 ( V_97 )
if ( ( V_4 -> V_116 & V_117 ) ||
( ( V_4 -> V_116 & V_118 ) &&
V_4 -> V_105 && V_4 -> V_105 -> V_119 ) ) {
V_76 |= V_120 ;
F_23 ( V_121 , V_4 -> V_68 + V_122 ) ;
F_23 ( V_123 , V_4 -> V_68 + V_124 ) ;
F_23 ( V_125 , V_4 -> V_68 + V_126 ) ;
F_23 ( V_127 , V_4 -> V_68 + V_128 ) ;
F_23 ( V_129 , V_4 -> V_68 + V_130 ) ;
} else {
V_76 &= ~ V_120 ;
}
#endif
F_23 ( V_76 , V_4 -> V_68 + V_131 ) ;
F_34 ( V_22 ) ;
#ifndef V_97
F_23 ( 0 , V_4 -> V_68 + V_132 ) ;
F_23 ( 0 , V_4 -> V_68 + V_133 ) ;
#endif
if ( V_30 -> V_45 & V_81 ) {
V_78 |= ( 1 << 8 ) ;
F_23 ( 1 << 8 , V_4 -> V_68 + V_134 ) ;
}
if ( V_4 -> V_6 )
V_78 |= ( 1 << 4 ) ;
#ifndef V_97
F_23 ( 0 << 31 , V_4 -> V_68 + V_135 ) ;
#endif
F_23 ( V_78 , V_4 -> V_68 + V_80 ) ;
F_23 ( 0 , V_4 -> V_68 + V_136 ) ;
if ( V_4 -> V_6 )
F_35 ( V_22 ) ;
F_23 ( V_137 , V_4 -> V_68 + V_138 ) ;
if ( F_26 ( V_22 ) ) {
F_36 ( V_22 ) ;
F_37 ( V_22 ) ;
F_38 ( & V_4 -> V_79 ) ;
F_39 ( V_22 ) ;
}
}
static void
F_40 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
T_2 V_139 = F_32 ( V_4 -> V_68 + V_131 ) & ( 1 << 8 ) ;
if ( V_4 -> V_140 ) {
F_23 ( 1 , V_4 -> V_68 + V_93 ) ;
F_30 ( 10 ) ;
if ( ! ( F_32 ( V_4 -> V_68 + V_86 ) & V_141 ) )
F_12 ( V_22 , L_3 ) ;
}
F_23 ( 1 , V_4 -> V_68 + V_80 ) ;
F_30 ( 10 ) ;
F_23 ( V_4 -> V_95 , V_4 -> V_68 + V_96 ) ;
F_23 ( V_137 , V_4 -> V_68 + V_138 ) ;
if ( V_30 -> V_45 & V_81 ) {
F_23 ( 2 , V_4 -> V_68 + V_80 ) ;
F_23 ( V_139 , V_4 -> V_68 + V_131 ) ;
}
}
static void
F_41 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
V_22 -> V_142 . V_143 ++ ;
V_4 -> V_65 . V_144 = true ;
F_19 ( & ( V_4 -> V_65 . V_65 ) , 0 ) ;
}
static void F_42 ( struct V_145 * V_146 )
{
struct V_3 * V_4 =
F_43 ( V_146 ,
struct V_3 ,
V_65 . V_65 . V_146 ) ;
if ( V_4 -> V_65 . V_144 ) {
V_4 -> V_65 . V_144 = false ;
F_25 ( V_4 -> V_147 , V_4 -> V_94 ) ;
F_37 ( V_4 -> V_147 ) ;
}
if ( V_4 -> V_65 . V_66 ) {
V_4 -> V_65 . V_66 = false ;
F_23 ( 0 , V_4 -> V_68 + V_69 ) ;
}
}
static void
F_44 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned short V_33 ;
struct V_19 * V_20 ;
int V_34 = 0 ;
V_4 = F_10 ( V_22 ) ;
V_2 = V_4 -> V_67 ;
V_2 = F_1 ( V_2 , V_4 ) ;
while ( ( ( V_33 = V_2 -> V_36 ) & V_37 ) == 0 ) {
if ( V_2 == V_4 -> V_35 )
break;
if ( V_4 -> V_6 )
V_34 = (struct V_6 * ) V_2 -
(struct V_6 * ) V_4 -> V_11 ;
else
V_34 = V_2 - V_4 -> V_11 ;
V_20 = V_4 -> V_47 [ V_34 ] ;
F_45 ( & V_4 -> V_31 -> V_49 , V_2 -> V_48 , V_20 -> V_16 ,
V_50 ) ;
V_2 -> V_48 = 0 ;
if ( V_33 & ( V_148 | V_149 |
V_150 | V_151 |
V_152 ) ) {
V_22 -> V_142 . V_143 ++ ;
if ( V_33 & V_148 )
V_22 -> V_142 . V_153 ++ ;
if ( V_33 & V_149 )
V_22 -> V_142 . V_154 ++ ;
if ( V_33 & V_150 )
V_22 -> V_142 . V_155 ++ ;
if ( V_33 & V_151 )
V_22 -> V_142 . V_156 ++ ;
if ( V_33 & V_152 )
V_22 -> V_142 . V_157 ++ ;
} else {
V_22 -> V_142 . V_158 ++ ;
V_22 -> V_142 . V_159 += V_2 -> V_42 ;
}
if ( F_7 ( F_18 ( V_20 ) -> V_53 & V_59 ) &&
V_4 -> V_6 ) {
struct V_160 V_161 ;
unsigned long V_162 ;
struct V_6 * V_51 = (struct V_6 * ) V_2 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
F_46 ( & V_4 -> V_163 , V_162 ) ;
V_161 . V_164 = F_47 (
F_48 ( & V_4 -> V_165 , V_51 -> V_166 ) ) ;
F_49 ( & V_4 -> V_163 , V_162 ) ;
F_50 ( V_20 , & V_161 ) ;
}
if ( V_33 & V_37 )
F_12 ( V_22 , L_4 ) ;
if ( V_33 & V_167 )
V_22 -> V_142 . V_168 ++ ;
F_16 ( V_20 ) ;
V_4 -> V_47 [ V_34 ] = NULL ;
V_4 -> V_67 = V_2 ;
V_2 = F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_67 != V_4 -> V_35 ) {
if ( F_51 ( V_22 ) )
F_37 ( V_22 ) ;
}
}
return;
}
static int
F_52 ( struct V_21 * V_22 , int V_169 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
struct V_1 * V_2 ;
unsigned short V_33 ;
struct V_19 * V_20 ;
T_3 V_170 ;
T_4 * V_41 ;
int V_171 = 0 ;
struct V_6 * V_51 = NULL ;
bool V_172 = false ;
T_5 V_173 ;
int V_34 = 0 ;
#ifdef F_53
F_54 () ;
#endif
V_2 = V_4 -> V_72 ;
while ( ! ( ( V_33 = V_2 -> V_36 ) & V_70 ) ) {
if ( V_171 >= V_169 )
break;
V_171 ++ ;
if ( ( V_33 & V_174 ) == 0 )
F_12 ( V_22 , L_5 ) ;
if ( ! V_4 -> V_175 )
goto V_176;
if ( V_33 & ( V_177 | V_178 | V_179 |
V_180 | V_181 ) ) {
V_22 -> V_142 . V_182 ++ ;
if ( V_33 & ( V_177 | V_178 ) ) {
V_22 -> V_142 . V_183 ++ ;
}
if ( V_33 & V_179 )
V_22 -> V_142 . V_184 ++ ;
if ( V_33 & V_180 )
V_22 -> V_142 . V_185 ++ ;
if ( V_33 & V_181 )
V_22 -> V_142 . V_186 ++ ;
}
if ( V_33 & V_187 ) {
V_22 -> V_142 . V_182 ++ ;
V_22 -> V_142 . V_184 ++ ;
goto V_176;
}
V_22 -> V_142 . V_188 ++ ;
V_170 = V_2 -> V_42 ;
V_22 -> V_142 . V_189 += V_170 ;
if ( V_4 -> V_6 )
V_34 = (struct V_6 * ) V_2 -
(struct V_6 * ) V_4 -> V_13 ;
else
V_34 = V_2 - V_4 -> V_13 ;
V_41 = V_4 -> V_190 [ V_34 ] -> V_41 ;
F_55 ( & V_4 -> V_31 -> V_49 , V_2 -> V_48 ,
V_191 , V_192 ) ;
if ( V_30 -> V_45 & V_46 )
F_3 ( V_41 , V_170 ) ;
V_51 = NULL ;
if ( V_4 -> V_6 )
V_51 = (struct V_6 * ) V_2 ;
V_172 = false ;
if ( ( V_22 -> V_193 & V_194 ) &&
V_4 -> V_6 && ( V_51 -> V_56 & V_195 ) ) {
struct V_196 * V_197 =
(struct V_196 * ) ( V_41 + V_198 ) ;
V_173 = F_56 ( V_197 -> V_199 ) ;
V_170 -= V_200 ;
V_172 = true ;
}
V_20 = F_57 ( V_22 , V_170 - 4 + V_201 ) ;
if ( F_7 ( ! V_20 ) ) {
V_22 -> V_142 . V_202 ++ ;
} else {
int V_203 = ( 2 * V_83 ) ;
F_58 ( V_20 , V_201 ) ;
F_59 ( V_20 , V_170 - 4 ) ;
F_60 ( V_20 , V_41 , ( 2 * V_83 ) ) ;
if ( V_172 )
V_203 = ( 2 * V_83 ) + V_200 ;
F_61 ( V_20 , ( 2 * V_83 ) ,
V_41 + V_203 ,
V_170 - 4 - ( 2 * V_83 ) ) ;
V_20 -> V_204 = F_62 ( V_20 , V_22 ) ;
if ( V_4 -> V_205 && V_4 -> V_6 ) {
struct V_160 * V_161 =
F_63 ( V_20 ) ;
unsigned long V_162 ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
F_46 ( & V_4 -> V_163 , V_162 ) ;
V_161 -> V_164 = F_47 (
F_48 ( & V_4 -> V_165 , V_51 -> V_166 ) ) ;
F_49 ( & V_4 -> V_163 , V_162 ) ;
}
if ( V_4 -> V_6 &&
( V_4 -> V_99 & V_100 ) ) {
if ( ! ( V_51 -> V_56 & V_206 ) ) {
V_20 -> V_23 = V_207 ;
} else {
F_64 ( V_20 ) ;
}
}
if ( V_172 )
F_65 ( V_20 ,
F_66 ( V_208 ) ,
V_173 ) ;
F_67 ( & V_4 -> V_79 , V_20 ) ;
}
F_68 ( & V_4 -> V_31 -> V_49 , V_2 -> V_48 ,
V_191 , V_192 ) ;
V_176:
V_33 &= ~ V_209 ;
V_33 |= V_70 ;
V_2 -> V_36 = V_33 ;
if ( V_4 -> V_6 ) {
struct V_6 * V_51 = (struct V_6 * ) V_2 ;
V_51 -> V_56 = V_210 ;
V_51 -> V_211 = 0 ;
V_51 -> V_52 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
F_23 ( 0 , V_4 -> V_68 + V_136 ) ;
}
V_4 -> V_72 = V_2 ;
return V_171 ;
}
static T_6
F_69 ( int V_212 , void * V_213 )
{
struct V_21 * V_22 = V_213 ;
struct V_3 * V_4 = F_10 ( V_22 ) ;
T_7 V_214 ;
T_6 V_215 = V_216 ;
do {
V_214 = F_32 ( V_4 -> V_68 + V_86 ) ;
F_23 ( V_214 , V_4 -> V_68 + V_86 ) ;
if ( V_214 & ( V_217 | V_218 ) ) {
V_215 = V_219 ;
if ( F_70 ( & V_4 -> V_79 ) ) {
F_23 ( V_220 ,
V_4 -> V_68 + V_138 ) ;
F_71 ( & V_4 -> V_79 ) ;
}
}
if ( V_214 & V_221 ) {
V_215 = V_219 ;
F_72 ( & V_4 -> V_222 ) ;
}
} while ( V_214 );
return V_215 ;
}
static int F_73 ( struct V_223 * V_79 , int V_169 )
{
struct V_21 * V_22 = V_79 -> V_49 ;
int V_224 = F_52 ( V_22 , V_169 ) ;
struct V_3 * V_4 = F_10 ( V_22 ) ;
F_44 ( V_22 ) ;
if ( V_224 < V_169 ) {
F_74 ( V_79 ) ;
F_23 ( V_137 , V_4 -> V_68 + V_138 ) ;
}
return V_224 ;
}
static void F_75 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_225 * V_226 = F_76 ( & V_4 -> V_31 -> V_49 ) ;
unsigned char * V_227 , V_228 [ V_83 ] ;
V_227 = V_229 ;
if ( ! F_77 ( V_227 ) ) {
struct V_230 * V_231 = V_4 -> V_31 -> V_49 . V_232 ;
if ( V_231 ) {
const char * V_233 = F_78 ( V_231 ) ;
if ( V_233 )
V_227 = ( unsigned char * ) V_233 ;
}
}
if ( ! F_77 ( V_227 ) ) {
#ifdef V_97
if ( V_234 )
V_227 = ( unsigned char * ) V_234 ;
#else
if ( V_226 )
V_227 = ( unsigned char * ) & V_226 -> V_233 ;
#endif
}
if ( ! F_77 ( V_227 ) ) {
* ( ( V_235 * ) & V_228 [ 0 ] ) =
F_5 ( F_32 ( V_4 -> V_68 + V_84 ) ) ;
* ( ( V_236 * ) & V_228 [ 4 ] ) =
F_79 ( F_32 ( V_4 -> V_68 + V_85 ) >> 16 ) ;
V_227 = & V_228 [ 0 ] ;
}
if ( ! F_77 ( V_227 ) ) {
F_12 ( V_22 , L_6 , V_227 ) ;
F_80 ( V_22 ) ;
F_81 ( V_22 , L_7 ,
V_22 -> V_82 ) ;
return;
}
memcpy ( V_22 -> V_82 , V_227 , V_83 ) ;
if ( V_227 == V_229 )
V_22 -> V_82 [ V_83 - 1 ] = V_229 [ V_83 - 1 ] + V_4 -> V_213 ;
}
static void F_82 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_237 * V_105 = V_4 -> V_105 ;
int V_238 = 0 ;
if ( V_4 -> V_239 && V_105 -> V_240 == V_241 ) {
V_105 -> V_240 = V_242 ;
return;
}
if ( V_105 -> V_140 ) {
if ( ! V_4 -> V_140 ) {
V_4 -> V_140 = V_105 -> V_140 ;
V_238 = 1 ;
}
if ( V_4 -> V_94 != V_105 -> V_73 )
V_238 = 1 ;
if ( V_105 -> V_106 != V_4 -> V_106 ) {
V_4 -> V_106 = V_105 -> V_106 ;
V_238 = 1 ;
}
if ( V_238 )
F_25 ( V_22 , V_105 -> V_73 ) ;
} else {
if ( V_4 -> V_140 ) {
F_40 ( V_22 ) ;
V_4 -> V_140 = V_105 -> V_140 ;
V_238 = 1 ;
}
}
if ( V_238 )
F_83 ( V_105 ) ;
}
static int F_84 ( struct V_243 * V_244 , int V_245 , int V_246 )
{
struct V_3 * V_4 = V_244 -> V_247 ;
unsigned long V_248 ;
V_4 -> V_239 = 0 ;
F_85 ( & V_4 -> V_222 ) ;
F_23 ( V_249 | V_250 |
F_86 ( V_245 ) | F_87 ( V_246 ) |
V_251 , V_4 -> V_68 + V_252 ) ;
V_248 = F_88 ( & V_4 -> V_222 ,
F_89 ( V_253 ) ) ;
if ( V_248 == 0 ) {
V_4 -> V_239 = 1 ;
F_12 ( V_4 -> V_147 , L_8 ) ;
return - V_254 ;
}
return F_90 ( F_32 ( V_4 -> V_68 + V_252 ) ) ;
}
static int F_91 ( struct V_243 * V_244 , int V_245 , int V_246 ,
T_5 V_255 )
{
struct V_3 * V_4 = V_244 -> V_247 ;
unsigned long V_248 ;
V_4 -> V_239 = 0 ;
F_85 ( & V_4 -> V_222 ) ;
F_23 ( V_249 | V_256 |
F_86 ( V_245 ) | F_87 ( V_246 ) |
V_251 | F_90 ( V_255 ) ,
V_4 -> V_68 + V_252 ) ;
V_248 = F_88 ( & V_4 -> V_222 ,
F_89 ( V_253 ) ) ;
if ( V_248 == 0 ) {
V_4 -> V_239 = 1 ;
F_12 ( V_4 -> V_147 , L_9 ) ;
return - V_254 ;
}
return 0 ;
}
static int F_92 ( struct V_243 * V_244 )
{
return 0 ;
}
static int F_93 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
struct V_237 * V_105 = NULL ;
char V_257 [ V_258 ] ;
char V_259 [ V_258 + 3 ] ;
int V_260 ;
int V_213 = V_4 -> V_213 ;
V_4 -> V_105 = NULL ;
for ( V_260 = 0 ; ( V_260 < V_261 ) ; V_260 ++ ) {
if ( ( V_4 -> V_243 -> V_262 & ( 1 << V_260 ) ) )
continue;
if ( V_4 -> V_243 -> V_263 [ V_260 ] == NULL )
continue;
if ( V_4 -> V_243 -> V_263 [ V_260 ] -> V_260 == 0 )
continue;
if ( V_213 -- )
continue;
strncpy ( V_257 , V_4 -> V_243 -> V_264 , V_258 ) ;
break;
}
if ( V_260 >= V_261 ) {
F_81 ( V_22 , L_10 ) ;
strncpy ( V_257 , L_11 , V_258 ) ;
V_260 = 0 ;
}
snprintf ( V_259 , sizeof( V_259 ) , V_265 , V_257 , V_260 ) ;
V_105 = F_94 ( V_22 , V_259 , & F_82 ,
V_4 -> V_102 ) ;
if ( F_95 ( V_105 ) ) {
F_12 ( V_22 , L_12 ) ;
return F_96 ( V_105 ) ;
}
if ( V_30 -> V_45 & V_266 ) {
V_105 -> V_267 &= V_268 ;
#if ! F_31 ( V_97 )
V_105 -> V_267 |= V_269 ;
#endif
}
else
V_105 -> V_267 &= V_270 ;
V_105 -> V_271 = V_105 -> V_267 ;
V_4 -> V_105 = V_105 ;
V_4 -> V_140 = 0 ;
V_4 -> V_94 = 0 ;
F_81 ( V_22 , L_13 ,
V_4 -> V_105 -> V_272 -> V_273 , F_97 ( & V_4 -> V_105 -> V_49 ) ,
V_4 -> V_105 -> V_212 ) ;
return 0 ;
}
static int F_98 ( struct V_274 * V_31 )
{
static struct V_243 * V_275 ;
struct V_21 * V_22 = F_99 ( V_31 ) ;
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
int V_276 = - V_277 , V_17 ;
if ( ( V_30 -> V_45 & V_81 ) && V_4 -> V_213 > 0 ) {
if ( V_278 && V_275 ) {
V_4 -> V_243 = V_275 ;
V_278 ++ ;
return 0 ;
}
return - V_279 ;
}
V_4 -> V_239 = 0 ;
V_4 -> V_95 = F_4 ( F_100 ( V_4 -> V_280 ) , 5000000 ) ;
if ( V_30 -> V_45 & V_81 )
V_4 -> V_95 -- ;
V_4 -> V_95 <<= 1 ;
F_23 ( V_4 -> V_95 , V_4 -> V_68 + V_96 ) ;
V_4 -> V_243 = F_101 () ;
if ( V_4 -> V_243 == NULL ) {
V_276 = - V_281 ;
goto V_282;
}
V_4 -> V_243 -> V_273 = L_14 ;
V_4 -> V_243 -> V_283 = F_84 ;
V_4 -> V_243 -> V_284 = F_91 ;
V_4 -> V_243 -> V_285 = F_92 ;
snprintf ( V_4 -> V_243 -> V_264 , V_258 , L_15 ,
V_31 -> V_273 , V_4 -> V_213 + 1 ) ;
V_4 -> V_243 -> V_247 = V_4 ;
V_4 -> V_243 -> V_286 = & V_31 -> V_49 ;
V_4 -> V_243 -> V_212 = F_102 ( sizeof( int ) * V_261 , V_287 ) ;
if ( ! V_4 -> V_243 -> V_212 ) {
V_276 = - V_281 ;
goto V_288;
}
for ( V_17 = 0 ; V_17 < V_261 ; V_17 ++ )
V_4 -> V_243 -> V_212 [ V_17 ] = V_289 ;
if ( F_103 ( V_4 -> V_243 ) )
goto V_290;
V_278 ++ ;
if ( V_30 -> V_45 & V_81 )
V_275 = V_4 -> V_243 ;
return 0 ;
V_290:
F_104 ( V_4 -> V_243 -> V_212 ) ;
V_288:
F_105 ( V_4 -> V_243 ) ;
V_282:
return V_276 ;
}
static void F_106 ( struct V_3 * V_4 )
{
if ( -- V_278 == 0 ) {
F_107 ( V_4 -> V_243 ) ;
F_104 ( V_4 -> V_243 -> V_212 ) ;
F_105 ( V_4 -> V_243 ) ;
}
}
static int F_108 ( struct V_21 * V_22 ,
struct V_291 * V_292 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_237 * V_293 = V_4 -> V_105 ;
if ( ! V_293 )
return - V_294 ;
return F_109 ( V_293 , V_292 ) ;
}
static int F_110 ( struct V_21 * V_22 ,
struct V_291 * V_292 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_237 * V_293 = V_4 -> V_105 ;
if ( ! V_293 )
return - V_294 ;
return F_111 ( V_293 , V_292 ) ;
}
static void F_112 ( struct V_21 * V_22 ,
struct V_295 * V_296 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
F_113 ( V_296 -> V_297 , V_4 -> V_31 -> V_49 . V_297 -> V_273 ,
sizeof( V_296 -> V_297 ) ) ;
F_113 ( V_296 -> V_298 , L_16 , sizeof( V_296 -> V_298 ) ) ;
F_113 ( V_296 -> V_299 , F_97 ( & V_22 -> V_49 ) , sizeof( V_296 -> V_299 ) ) ;
}
static int F_114 ( struct V_21 * V_22 ,
struct V_300 * V_296 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
if ( V_4 -> V_6 ) {
V_296 -> V_301 = V_302 |
V_303 |
V_304 |
V_305 |
V_306 |
V_307 ;
if ( V_4 -> V_308 )
V_296 -> V_309 = F_115 ( V_4 -> V_308 ) ;
else
V_296 -> V_309 = - 1 ;
V_296 -> V_310 = ( 1 << V_311 ) |
( 1 << V_312 ) ;
V_296 -> V_313 = ( 1 << V_314 ) |
( 1 << V_315 ) ;
return 0 ;
} else {
return F_116 ( V_22 , V_296 ) ;
}
}
static void F_117 ( struct V_21 * V_22 ,
struct V_316 * V_119 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
V_119 -> V_317 = ( V_4 -> V_116 & V_118 ) != 0 ;
V_119 -> V_318 = ( V_4 -> V_116 & V_117 ) != 0 ;
V_119 -> V_319 = V_119 -> V_318 ;
}
static int F_118 ( struct V_21 * V_22 ,
struct V_316 * V_119 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
if ( V_119 -> V_318 != V_119 -> V_319 ) {
F_81 ( V_22 ,
L_17 ) ;
return - V_320 ;
}
V_4 -> V_116 = 0 ;
V_4 -> V_116 |= V_119 -> V_319 ? V_117 : 0 ;
V_4 -> V_116 |= V_119 -> V_317 ? V_118 : 0 ;
if ( V_119 -> V_319 || V_119 -> V_317 ) {
V_4 -> V_105 -> V_267 |= V_321 ;
V_4 -> V_105 -> V_271 |= V_321 ;
} else {
V_4 -> V_105 -> V_267 &= ~ V_321 ;
V_4 -> V_105 -> V_271 &= ~ V_321 ;
}
if ( V_119 -> V_317 ) {
if ( F_26 ( V_22 ) )
F_40 ( V_22 ) ;
F_119 ( V_4 -> V_105 ) ;
}
if ( F_26 ( V_22 ) )
F_25 ( V_22 , 0 ) ;
return 0 ;
}
static void F_120 ( struct V_21 * V_49 ,
struct V_322 * V_142 , T_8 * V_41 )
{
struct V_3 * V_4 = F_10 ( V_49 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_121 ( V_323 ) ; V_17 ++ )
V_41 [ V_17 ] = F_32 ( V_4 -> V_68 + V_323 [ V_17 ] . V_324 ) ;
}
static void F_122 ( struct V_21 * V_147 ,
T_2 V_325 , T_9 * V_41 )
{
int V_17 ;
switch ( V_325 ) {
case V_326 :
for ( V_17 = 0 ; V_17 < F_121 ( V_323 ) ; V_17 ++ )
memcpy ( V_41 + V_17 * V_327 ,
V_323 [ V_17 ] . V_273 , V_327 ) ;
break;
}
}
static int F_123 ( struct V_21 * V_49 , int V_328 )
{
switch ( V_328 ) {
case V_326 :
return F_121 ( V_323 ) ;
default:
return - V_329 ;
}
}
static int F_124 ( struct V_21 * V_49 )
{
struct V_3 * V_4 = F_10 ( V_49 ) ;
struct V_237 * V_293 = V_4 -> V_105 ;
if ( ! V_293 )
return - V_294 ;
return F_125 ( V_293 ) ;
}
static int F_126 ( struct V_21 * V_22 , struct V_330 * V_331 , int V_292 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_237 * V_293 = V_4 -> V_105 ;
if ( ! F_26 ( V_22 ) )
return - V_320 ;
if ( ! V_293 )
return - V_294 ;
if ( V_4 -> V_6 ) {
if ( V_292 == V_332 )
return F_127 ( V_22 , V_331 ) ;
if ( V_292 == V_333 )
return F_128 ( V_22 , V_331 ) ;
}
return F_129 ( V_293 , V_331 , V_292 ) ;
}
static void F_130 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
unsigned int V_17 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
V_2 = V_4 -> V_13 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_14 ; V_17 ++ ) {
V_20 = V_4 -> V_190 [ V_17 ] ;
if ( V_2 -> V_48 )
F_45 ( & V_4 -> V_31 -> V_49 , V_2 -> V_48 ,
V_191 , V_192 ) ;
if ( V_20 )
F_131 ( V_20 ) ;
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = V_4 -> V_11 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_12 ; V_17 ++ )
F_104 ( V_4 -> V_44 [ V_17 ] ) ;
}
static int F_132 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
unsigned int V_17 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
V_2 = V_4 -> V_13 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_14 ; V_17 ++ ) {
V_20 = F_57 ( V_22 , V_191 ) ;
if ( ! V_20 ) {
F_130 ( V_22 ) ;
return - V_281 ;
}
V_4 -> V_190 [ V_17 ] = V_20 ;
V_2 -> V_48 = F_14 ( & V_4 -> V_31 -> V_49 , V_20 -> V_41 ,
V_191 , V_192 ) ;
if ( F_15 ( & V_4 -> V_31 -> V_49 , V_2 -> V_48 ) ) {
F_130 ( V_22 ) ;
if ( F_17 () )
F_12 ( V_22 , L_18 ) ;
return - V_281 ;
}
V_2 -> V_36 = V_70 ;
if ( V_4 -> V_6 ) {
struct V_6 * V_51 = (struct V_6 * ) V_2 ;
V_51 -> V_56 = V_210 ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_36 |= V_71 ;
V_2 = V_4 -> V_11 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_12 ; V_17 ++ ) {
V_4 -> V_44 [ V_17 ] = F_102 ( V_334 , V_287 ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_48 = 0 ;
if ( V_4 -> V_6 ) {
struct V_6 * V_51 = (struct V_6 * ) V_2 ;
V_51 -> V_56 = V_58 ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_36 |= V_71 ;
return 0 ;
}
static int
F_133 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
int V_215 ;
V_215 = F_132 ( V_22 ) ;
if ( V_215 )
return V_215 ;
V_215 = F_93 ( V_22 ) ;
if ( V_215 ) {
F_130 ( V_22 ) ;
return V_215 ;
}
F_38 ( & V_4 -> V_79 ) ;
F_134 ( V_4 -> V_105 ) ;
F_135 ( V_22 ) ;
V_4 -> V_175 = 1 ;
return 0 ;
}
static int
F_136 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
F_28 ( & V_4 -> V_79 ) ;
V_4 -> V_175 = 0 ;
F_22 ( V_22 ) ;
F_40 ( V_22 ) ;
if ( V_4 -> V_105 ) {
F_137 ( V_4 -> V_105 ) ;
F_138 ( V_4 -> V_105 ) ;
}
F_130 ( V_22 ) ;
return 0 ;
}
static void F_34 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_335 * V_336 ;
unsigned int V_17 , V_337 , V_41 , V_338 , V_339 ;
unsigned char V_340 ;
if ( V_22 -> V_162 & V_341 ) {
V_339 = F_32 ( V_4 -> V_68 + V_131 ) ;
V_339 |= 0x8 ;
F_23 ( V_339 , V_4 -> V_68 + V_131 ) ;
return;
}
V_339 = F_32 ( V_4 -> V_68 + V_131 ) ;
V_339 &= ~ 0x8 ;
F_23 ( V_339 , V_4 -> V_68 + V_131 ) ;
if ( V_22 -> V_162 & V_342 ) {
F_23 ( 0xffffffff , V_4 -> V_68 + V_343 ) ;
F_23 ( 0xffffffff , V_4 -> V_68 + V_344 ) ;
return;
}
F_23 ( 0 , V_4 -> V_68 + V_343 ) ;
F_23 ( 0 , V_4 -> V_68 + V_344 ) ;
F_139 (ha, ndev) {
V_338 = 0xffffffff ;
for ( V_17 = 0 ; V_17 < V_22 -> V_345 ; V_17 ++ ) {
V_41 = V_336 -> V_346 [ V_17 ] ;
for ( V_337 = 0 ; V_337 < 8 ; V_337 ++ , V_41 >>= 1 ) {
V_338 = ( V_338 >> 1 ) ^
( ( ( V_338 ^ V_41 ) & 1 ) ? V_347 : 0 ) ;
}
}
V_340 = ( V_338 >> ( 32 - V_348 ) ) & 0x3f ;
if ( V_340 > 31 ) {
V_339 = F_32 ( V_4 -> V_68 + V_343 ) ;
V_339 |= 1 << ( V_340 - 32 ) ;
F_23 ( V_339 , V_4 -> V_68 + V_343 ) ;
} else {
V_339 = F_32 ( V_4 -> V_68 + V_344 ) ;
V_339 |= 1 << V_340 ;
F_23 ( V_339 , V_4 -> V_68 + V_344 ) ;
}
}
}
static int
F_140 ( struct V_21 * V_22 , void * V_349 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
struct V_350 * V_346 = V_349 ;
if ( ! F_77 ( V_346 -> V_351 ) )
return - V_352 ;
memcpy ( V_22 -> V_82 , V_346 -> V_351 , V_22 -> V_345 ) ;
F_23 ( V_22 -> V_82 [ 3 ] | ( V_22 -> V_82 [ 2 ] << 8 ) |
( V_22 -> V_82 [ 1 ] << 16 ) | ( V_22 -> V_82 [ 0 ] << 24 ) ,
V_4 -> V_68 + V_84 ) ;
F_23 ( ( V_22 -> V_82 [ 5 ] << 16 ) | ( V_22 -> V_82 [ 4 ] << 24 ) ,
V_4 -> V_68 + V_85 ) ;
return 0 ;
}
static void F_141 ( struct V_21 * V_49 )
{
int V_17 ;
struct V_3 * V_4 = F_10 ( V_49 ) ;
for ( V_17 = 0 ; V_17 < V_353 ; V_17 ++ ) {
if ( V_4 -> V_212 [ V_17 ] > 0 ) {
F_142 ( V_4 -> V_212 [ V_17 ] ) ;
F_69 ( V_4 -> V_212 [ V_17 ] , V_49 ) ;
F_143 ( V_4 -> V_212 [ V_17 ] ) ;
}
}
}
static int F_144 ( struct V_21 * V_147 ,
T_10 V_193 )
{
struct V_3 * V_4 = F_10 ( V_147 ) ;
T_10 V_354 = V_193 ^ V_147 -> V_193 ;
V_147 -> V_193 = V_193 ;
if ( V_354 & V_355 ) {
if ( V_193 & V_355 )
V_4 -> V_99 |= V_100 ;
else
V_4 -> V_99 &= ~ V_100 ;
if ( F_26 ( V_147 ) ) {
F_40 ( V_147 ) ;
F_25 ( V_147 , V_4 -> V_105 -> V_73 ) ;
F_37 ( V_147 ) ;
} else {
F_25 ( V_147 , V_4 -> V_105 -> V_73 ) ;
}
}
return 0 ;
}
static int F_145 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_22 ) ;
const struct V_29 * V_30 =
F_11 ( V_4 -> V_31 ) ;
struct V_1 * V_356 ;
V_356 = F_146 ( NULL , V_357 , & V_4 -> V_89 ,
V_287 ) ;
if ( ! V_356 )
return - V_281 ;
memset ( V_356 , 0 , V_357 ) ;
V_4 -> V_147 = V_22 ;
F_75 ( V_22 ) ;
V_4 -> V_12 = V_358 ;
V_4 -> V_14 = V_359 ;
V_4 -> V_13 = V_356 ;
if ( V_4 -> V_6 )
V_4 -> V_11 = (struct V_1 * )
( ( (struct V_6 * ) V_356 ) + V_4 -> V_14 ) ;
else
V_4 -> V_11 = V_356 + V_4 -> V_14 ;
V_22 -> V_360 = V_361 ;
V_22 -> V_362 = & V_363 ;
V_22 -> V_364 = & V_365 ;
F_23 ( V_220 , V_4 -> V_68 + V_138 ) ;
F_147 ( V_22 , & V_4 -> V_79 , F_73 , V_366 ) ;
if ( V_30 -> V_45 & V_367 ) {
V_22 -> V_193 |= V_194 ;
V_22 -> V_368 |= V_194 ;
}
if ( V_30 -> V_45 & V_369 ) {
V_22 -> V_193 |= ( V_370 | V_371
| V_355 ) ;
V_22 -> V_368 |= ( V_370 | V_371
| V_355 ) ;
V_4 -> V_99 |= V_100 ;
}
F_25 ( V_22 , 0 ) ;
return 0 ;
}
static void F_148 ( struct V_274 * V_31 )
{
int V_276 , V_372 ;
int V_373 = 1 ;
struct V_230 * V_231 = V_31 -> V_49 . V_232 ;
if ( ! V_231 )
return;
F_149 ( V_231 , L_19 , & V_373 ) ;
if ( V_373 > 1000 )
V_373 = 1 ;
V_372 = F_150 ( V_231 , L_20 , 0 ) ;
if ( ! F_151 ( V_372 ) )
return;
V_276 = F_152 ( & V_31 -> V_49 , V_372 ,
V_374 , L_21 ) ;
if ( V_276 ) {
F_153 ( & V_31 -> V_49 , L_22 , V_276 ) ;
return;
}
F_154 ( V_373 ) ;
F_155 ( V_372 , 1 ) ;
}
static void F_148 ( struct V_274 * V_31 )
{
}
static int
F_156 ( struct V_274 * V_31 )
{
struct V_3 * V_4 ;
struct V_225 * V_226 ;
struct V_21 * V_22 ;
int V_17 , V_212 , V_215 = 0 ;
struct V_375 * V_376 ;
const struct V_377 * V_378 ;
static int V_213 ;
V_378 = F_157 ( V_379 , & V_31 -> V_49 ) ;
if ( V_378 )
V_31 -> V_30 = V_378 -> V_41 ;
V_22 = F_158 ( sizeof( struct V_3 ) ) ;
if ( ! V_22 )
return - V_281 ;
F_159 ( V_22 , & V_31 -> V_49 ) ;
V_4 = F_10 ( V_22 ) ;
#if ! F_31 ( V_97 )
if ( V_31 -> V_30 &&
( V_31 -> V_30 -> V_45 & V_266 ) )
V_4 -> V_116 |= V_118 ;
#endif
V_376 = F_160 ( V_31 , V_380 , 0 ) ;
V_4 -> V_68 = F_161 ( & V_31 -> V_49 , V_376 ) ;
if ( F_95 ( V_4 -> V_68 ) ) {
V_215 = F_96 ( V_4 -> V_68 ) ;
goto V_381;
}
V_4 -> V_31 = V_31 ;
V_4 -> V_213 = V_213 ++ ;
V_4 -> V_6 = 0 ;
F_162 ( V_31 , V_22 ) ;
V_215 = F_163 ( V_31 -> V_49 . V_232 ) ;
if ( V_215 < 0 ) {
V_226 = F_76 ( & V_31 -> V_49 ) ;
if ( V_226 )
V_4 -> V_102 = V_226 -> V_382 ;
else
V_4 -> V_102 = V_383 ;
} else {
V_4 -> V_102 = V_215 ;
}
V_4 -> V_384 = F_164 ( & V_31 -> V_49 , L_23 ) ;
if ( F_95 ( V_4 -> V_384 ) ) {
V_215 = F_96 ( V_4 -> V_384 ) ;
goto V_385;
}
V_4 -> V_280 = F_164 ( & V_31 -> V_49 , L_24 ) ;
if ( F_95 ( V_4 -> V_280 ) ) {
V_215 = F_96 ( V_4 -> V_280 ) ;
goto V_385;
}
V_4 -> V_386 = F_164 ( & V_31 -> V_49 , L_25 ) ;
if ( F_95 ( V_4 -> V_386 ) )
V_4 -> V_386 = NULL ;
V_4 -> V_387 = F_164 ( & V_31 -> V_49 , L_26 ) ;
V_4 -> V_6 =
V_31 -> V_30 -> V_45 & V_388 ;
if ( F_95 ( V_4 -> V_387 ) ) {
V_4 -> V_387 = NULL ;
V_4 -> V_6 = 0 ;
}
V_215 = F_165 ( V_4 -> V_280 ) ;
if ( V_215 )
goto V_385;
V_215 = F_165 ( V_4 -> V_384 ) ;
if ( V_215 )
goto V_389;
if ( V_4 -> V_386 ) {
V_215 = F_165 ( V_4 -> V_386 ) ;
if ( V_215 )
goto V_390;
}
if ( V_4 -> V_387 ) {
V_215 = F_165 ( V_4 -> V_387 ) ;
if ( V_215 )
goto V_391;
}
V_4 -> V_392 = F_166 ( & V_31 -> V_49 , L_27 ) ;
if ( ! F_95 ( V_4 -> V_392 ) ) {
V_215 = F_167 ( V_4 -> V_392 ) ;
if ( V_215 ) {
F_153 ( & V_31 -> V_49 ,
L_28 , V_215 ) ;
goto V_393;
}
} else {
V_4 -> V_392 = NULL ;
}
F_148 ( V_31 ) ;
if ( V_4 -> V_6 )
F_168 ( V_31 ) ;
V_215 = F_145 ( V_22 ) ;
if ( V_215 )
goto V_394;
for ( V_17 = 0 ; V_17 < V_353 ; V_17 ++ ) {
V_212 = F_169 ( V_31 , V_17 ) ;
if ( V_212 < 0 ) {
if ( V_17 )
break;
V_215 = V_212 ;
goto V_395;
}
V_215 = F_170 ( & V_31 -> V_49 , V_212 , F_69 ,
0 , V_31 -> V_273 , V_22 ) ;
if ( V_215 )
goto V_395;
}
V_215 = F_98 ( V_31 ) ;
if ( V_215 )
goto V_396;
F_171 ( V_22 ) ;
V_215 = F_172 ( V_22 ) ;
if ( V_215 )
goto V_397;
if ( V_4 -> V_6 && V_4 -> V_308 )
F_81 ( V_22 , L_29 , V_4 -> V_213 ) ;
F_173 ( & ( V_4 -> V_65 . V_65 ) , F_42 ) ;
return 0 ;
V_397:
F_106 ( V_4 ) ;
V_396:
V_395:
V_394:
if ( V_4 -> V_392 )
F_174 ( V_4 -> V_392 ) ;
V_393:
if ( V_4 -> V_387 )
F_175 ( V_4 -> V_387 ) ;
V_391:
if ( V_4 -> V_386 )
F_175 ( V_4 -> V_386 ) ;
V_390:
F_175 ( V_4 -> V_384 ) ;
V_389:
F_175 ( V_4 -> V_280 ) ;
V_385:
V_381:
F_176 ( V_22 ) ;
return V_215 ;
}
static int
F_177 ( struct V_274 * V_31 )
{
struct V_21 * V_22 = F_99 ( V_31 ) ;
struct V_3 * V_4 = F_10 ( V_22 ) ;
F_178 ( & ( V_4 -> V_65 . V_65 ) ) ;
F_179 ( V_22 ) ;
F_106 ( V_4 ) ;
F_180 ( & V_4 -> V_398 ) ;
if ( V_4 -> V_392 )
F_174 ( V_4 -> V_392 ) ;
if ( V_4 -> V_387 )
F_175 ( V_4 -> V_387 ) ;
if ( V_4 -> V_308 )
F_181 ( V_4 -> V_308 ) ;
if ( V_4 -> V_386 )
F_175 ( V_4 -> V_386 ) ;
F_175 ( V_4 -> V_384 ) ;
F_175 ( V_4 -> V_280 ) ;
F_176 ( V_22 ) ;
return 0 ;
}
static int
F_182 ( struct V_399 * V_49 )
{
struct V_21 * V_22 = F_183 ( V_49 ) ;
struct V_3 * V_4 = F_10 ( V_22 ) ;
if ( F_26 ( V_22 ) ) {
F_40 ( V_22 ) ;
F_27 ( V_22 ) ;
}
if ( V_4 -> V_387 )
F_175 ( V_4 -> V_387 ) ;
if ( V_4 -> V_386 )
F_175 ( V_4 -> V_386 ) ;
F_175 ( V_4 -> V_384 ) ;
F_175 ( V_4 -> V_280 ) ;
if ( V_4 -> V_392 )
F_174 ( V_4 -> V_392 ) ;
return 0 ;
}
static int
F_184 ( struct V_399 * V_49 )
{
struct V_21 * V_22 = F_183 ( V_49 ) ;
struct V_3 * V_4 = F_10 ( V_22 ) ;
int V_215 ;
if ( V_4 -> V_392 ) {
V_215 = F_167 ( V_4 -> V_392 ) ;
if ( V_215 )
return V_215 ;
}
V_215 = F_165 ( V_4 -> V_280 ) ;
if ( V_215 )
goto V_400;
V_215 = F_165 ( V_4 -> V_384 ) ;
if ( V_215 )
goto V_389;
if ( V_4 -> V_386 ) {
V_215 = F_165 ( V_4 -> V_386 ) ;
if ( V_215 )
goto V_390;
}
if ( V_4 -> V_387 ) {
V_215 = F_165 ( V_4 -> V_387 ) ;
if ( V_215 )
goto V_391;
}
if ( F_26 ( V_22 ) ) {
F_25 ( V_22 , V_4 -> V_94 ) ;
F_39 ( V_22 ) ;
}
return 0 ;
V_391:
if ( V_4 -> V_386 )
F_175 ( V_4 -> V_386 ) ;
V_390:
F_175 ( V_4 -> V_384 ) ;
V_389:
F_175 ( V_4 -> V_280 ) ;
V_400:
if ( V_4 -> V_392 )
F_174 ( V_4 -> V_392 ) ;
return V_215 ;
}
