void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_9 ;
V_4 -> V_10 = V_11 ;
F_4 ( V_8 -> V_12 & V_13 ?
& V_6 -> V_14 : & V_6 -> V_15 , V_4 ) ;
V_9 = F_5 ( & V_6 -> V_14 ) +
F_5 ( & V_6 -> V_15 ) ;
while ( V_9 > V_16 &&
( V_4 = F_6 ( & V_6 -> V_15 ) ) ) {
F_7 ( V_2 , V_4 ) ;
V_9 -- ;
F_8 ( V_6 -> V_17 ) ;
}
F_9 ( & V_6 -> V_18 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
int V_24 ;
memset ( & V_8 -> V_25 , 0 , sizeof( V_8 -> V_25 ) ) ;
V_8 -> V_25 . V_26 = V_26 ;
V_8 -> V_25 . V_27 = & V_20 -> V_28 -> V_27 ;
V_8 -> V_12 |= V_29 |
V_30 ;
V_8 -> V_12 &= ~ V_31 ;
V_20 -> V_32 ++ ;
if ( V_22 -> V_33 & F_11 ( V_34 ) )
V_22 -> V_33 &= ~ F_11 ( V_34 ) ;
if ( F_12 ( V_22 -> V_33 ) ) {
T_1 * V_35 = F_13 ( V_22 ) ;
int V_36 = * V_35 & V_37 ;
if ( * V_35 & V_38 )
* V_35 &= ~ V_38 ;
V_24 = V_39 [ V_36 & 7 ] ;
} else {
V_24 = V_40 ;
}
F_14 ( V_20 , V_41 ) ;
if ( F_15 ( V_20 , V_42 ) &&
F_5 ( & V_20 -> V_43 [ V_24 ] ) < V_44 ) {
F_4 ( & V_20 -> V_43 [ V_24 ] , V_4 ) ;
F_16 ( V_20 ) ;
if ( ! F_17 ( & V_6 -> V_45 ) )
F_18 ( & V_6 -> V_45 ,
F_19 ( V_26 +
V_46 ) ) ;
return;
}
if ( ! F_15 ( V_20 , V_42 ) &&
! ( V_8 -> V_12 & V_47 ) ) {
V_8 -> V_12 |= V_47 ;
F_20 ( V_6 , V_4 ) ;
return;
}
F_21 ( V_20 -> V_28 ,
L_1 ,
F_5 ( & V_20 -> V_43 [ V_24 ] ) ,
! ! F_15 ( V_20 , V_42 ) , V_26 ) ;
F_7 ( & V_6 -> V_2 , V_4 ) ;
}
static void F_22 ( struct V_19 * V_20 , T_1 * V_48 , T_1 V_36 )
{
struct V_49 * V_50 ;
V_50 = F_23 ( V_20 -> V_51 . V_50 [ V_36 ] ) ;
if ( ! V_50 || ! V_50 -> V_52 )
return;
V_50 -> V_52 = false ;
F_24 ( & V_20 -> V_28 -> V_27 , V_48 , V_36 , V_50 -> V_53 ) ;
}
static void F_25 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_54 * V_55 = ( void * ) V_4 -> V_23 ;
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_56 * V_28 = V_20 -> V_28 ;
if ( V_6 -> V_2 . V_12 & V_57 )
V_20 -> V_58 = V_26 ;
if ( F_12 ( V_55 -> V_33 ) ) {
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
T_1 * V_59 = F_13 ( V_22 ) ;
T_2 V_36 = V_59 [ 0 ] & 0xf ;
F_22 ( V_20 , V_22 -> V_60 , V_36 ) ;
}
if ( F_26 ( V_55 -> V_33 ) &&
V_55 -> V_61 . V_62 . V_63 == V_64 &&
V_55 -> V_61 . V_62 . V_61 . V_65 . V_62 == V_66 &&
F_27 ( V_28 ) ) {
enum V_67 V_68 ;
switch ( V_55 -> V_61 . V_62 . V_61 . V_65 . V_69 ) {
case V_70 :
V_68 = V_71 ;
break;
case V_72 :
V_68 = V_73 ;
break;
case V_74 :
default:
V_68 = V_75 ;
break;
}
if ( V_28 -> V_27 . type == V_76 ) {
V_28 -> V_68 = V_68 ;
F_28 ( & V_6 -> V_2 , & V_28 -> V_77 ) ;
} else if ( V_28 -> V_27 . type == V_78 ||
V_28 -> V_27 . type == V_79 ) {
V_20 -> V_80 = V_68 ;
}
}
}
static void F_29 ( struct V_19 * V_20 , T_1 V_36 , T_2 V_81 )
{
struct V_49 * V_50 ;
V_50 = F_23 ( V_20 -> V_51 . V_50 [ V_36 ] ) ;
if ( ! V_50 )
return;
V_50 -> V_53 = V_81 ;
V_50 -> V_52 = true ;
}
static int F_30 ( struct V_7 * V_8 )
{
int V_82 = sizeof( struct V_83 ) ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_86 >= 0 &&
! ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & ( V_87 |
V_88 ) ) )
V_82 += 2 ;
V_82 += 2 ;
V_82 += 1 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_86 >= 0 ) {
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_87 )
V_82 += 3 ;
else if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_88 )
V_82 = F_31 ( V_82 , 2 ) + 12 ;
}
return V_82 ;
}
static void
F_32 ( struct V_5 * V_6 ,
struct V_89 * V_90 ,
struct V_3 * V_4 , int V_91 ,
int V_92 , int V_93 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_83 * V_94 ;
unsigned char * V_95 ;
T_2 V_96 ;
V_94 = (struct V_83 * ) F_33 ( V_4 , V_92 ) ;
memset ( V_94 , 0 , V_92 ) ;
V_94 -> V_97 = F_11 ( V_92 ) ;
V_94 -> V_98 =
F_34 ( ( 1 << V_99 ) |
( 1 << V_100 ) ) ;
V_95 = ( unsigned char * ) ( V_94 + 1 ) ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_86 >= 0 &&
! ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & ( V_87 |
V_88 ) ) ) {
T_2 V_101 ;
V_94 -> V_98 |= F_34 ( 1 << V_102 ) ;
V_101 = V_90 -> V_103 [ V_8 -> V_84 . V_85 [ 0 ] . V_86 ] . V_104 ;
* V_95 = F_35 ( V_101 , 5 * ( 1 << V_93 ) ) ;
V_95 += 2 ;
}
V_96 = 0 ;
if ( ! ( V_8 -> V_12 & V_105 ) &&
! F_36 ( V_22 -> V_60 ) )
V_96 |= V_106 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_107 )
V_96 |= V_108 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_109 )
V_96 |= V_110 ;
F_37 ( V_96 , V_95 ) ;
V_95 += 2 ;
* V_95 = V_91 ;
V_95 ++ ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_86 < 0 )
return;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_87 ) {
V_94 -> V_98 |= F_34 ( 1 << V_111 ) ;
V_95 [ 0 ] = V_112 |
V_113 |
V_114 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_115 )
V_95 [ 1 ] |= V_116 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_117 )
V_95 [ 1 ] |= V_118 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_119 )
V_95 [ 1 ] |= V_120 ;
V_95 [ 2 ] = V_8 -> V_84 . V_85 [ 0 ] . V_86 ;
V_95 += 3 ;
} else if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_88 ) {
T_2 V_121 = V_6 -> V_2 . V_122 &
( V_123 |
V_124 ) ;
V_94 -> V_98 |= F_34 ( 1 << V_125 ) ;
V_95 = ( T_1 * ) V_94 + F_31 ( V_95 - ( T_1 * ) V_94 , 2 ) ;
F_37 ( V_121 , V_95 ) ;
V_95 += 2 ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_115 )
* V_95 |= V_126 ;
V_95 ++ ;
if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_117 )
* V_95 = 1 ;
else if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_127 )
* V_95 = 4 ;
else if ( V_8 -> V_84 . V_85 [ 0 ] . V_12 & V_128 )
* V_95 = 11 ;
else
* V_95 = 0 ;
V_95 ++ ;
* V_95 = ( F_38 ( & V_8 -> V_84 . V_85 [ 0 ] ) << 4 ) |
F_39 ( & V_8 -> V_84 . V_85 [ 0 ] ) ;
V_95 += 4 ;
V_95 ++ ;
V_95 ++ ;
V_95 += 2 ;
}
}
static void F_40 ( struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_129 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
bool V_130 = V_8 -> V_12 & V_105 ;
if ( V_129 )
V_130 = false ;
if ( V_8 -> V_12 & ( V_131 |
V_132 ) ) {
struct V_56 * V_28 = NULL ;
struct V_56 * V_133 ;
T_3 V_134 = ( unsigned long ) V_4 ;
F_41 () ;
if ( V_4 -> V_135 ) {
F_42 (iter_sdata, &local->interfaces,
list) {
if ( ! V_133 -> V_135 )
continue;
if ( V_4 -> V_135 == V_133 -> V_135 ) {
V_28 = V_133 ;
break;
}
}
} else {
V_28 = F_23 ( V_6 -> V_136 ) ;
}
if ( ! V_28 ) {
V_4 -> V_135 = NULL ;
} else if ( V_8 -> V_12 & V_132 ) {
F_43 ( V_28 , V_22 -> V_33 ,
V_130 ) ;
} else if ( F_44 ( V_22 -> V_33 ) ||
F_45 ( V_22 -> V_33 ) ) {
F_46 ( V_28 -> V_135 , V_22 -> V_60 ,
V_134 , V_130 , V_137 ) ;
} else {
F_47 ( & V_28 -> V_138 , V_134 , V_4 -> V_23 ,
V_4 -> V_82 , V_130 , V_137 ) ;
}
F_48 () ;
}
if ( F_49 ( V_8 -> V_139 ) ) {
struct V_3 * V_140 ;
unsigned long V_12 ;
F_50 ( & V_6 -> V_141 , V_12 ) ;
V_140 = F_51 ( & V_6 -> V_142 ,
V_8 -> V_139 ) ;
if ( V_140 )
F_52 ( & V_6 -> V_142 ,
V_8 -> V_139 ) ;
F_53 ( & V_6 -> V_141 , V_12 ) ;
if ( V_140 ) {
if ( ! V_129 ) {
F_54 ( V_140 , V_130 ) ;
} else {
F_55 ( V_140 ) ;
}
}
}
}
static void F_56 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
T_4 V_143 ;
struct V_144 V_145 ;
T_5 V_146 ;
T_2 V_36 ;
T_1 * V_59 ;
int V_147 , V_148 ;
T_5 * V_149 ;
T_6 V_150 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
T_4 V_155 = V_4 -> V_156 ;
V_154 = F_23 ( V_6 -> V_154 ) ;
if ( ! V_154 || ! F_57 ( V_155 ) )
return;
V_150 = V_22 -> V_33 ;
if ( ! F_58 ( V_150 ) )
return;
if ( F_12 ( V_22 -> V_33 ) ) {
V_59 = F_13 ( V_22 ) ;
V_36 = V_59 [ 0 ] & V_37 ;
} else {
V_36 = 0 ;
}
V_152 = & V_20 -> V_152 [ V_36 ] ;
F_59 ( & V_145 ) ;
V_143 = F_60 ( V_145 . V_157 , V_145 . V_158 ) ;
V_146 = F_61 ( F_62 ( V_143 , V_155 ) ) ;
if ( V_152 -> V_159 < V_146 )
V_152 -> V_159 = V_146 ;
V_152 -> V_160 ++ ;
V_152 -> V_161 += V_146 ;
if ( ! V_152 -> V_162 )
return;
V_148 = V_154 -> V_163 ;
V_149 = V_154 -> V_164 ;
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
if ( V_146 <= V_149 [ V_147 ] ) {
V_152 -> V_162 [ V_147 ] ++ ;
break;
}
}
if ( V_147 == V_148 )
V_152 -> V_162 [ V_147 ] ++ ;
}
static void F_63 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( ( V_8 -> V_12 & V_165 ) &&
! ( V_8 -> V_12 & V_166 ) )
return;
if ( ++ V_20 -> V_167 < V_168 )
return;
F_64 ( V_20 -> V_28 -> V_135 , V_20 -> V_20 . V_48 ,
V_20 -> V_167 , V_137 ) ;
V_20 -> V_167 = 0 ;
}
void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_169 ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_6 V_150 ;
struct V_89 * V_90 ;
struct V_56 * V_28 ;
struct V_170 * V_171 = NULL ;
struct V_19 * V_20 , * V_9 ;
int V_91 = - 1 , V_147 ;
int V_172 = - 1 ;
bool V_173 ;
bool V_130 ;
struct V_174 * V_175 ;
int V_92 ;
int V_93 = 0 ;
for ( V_147 = 0 ; V_147 < V_176 ; V_147 ++ ) {
if ( ( V_8 -> V_12 & V_165 ) &&
! ( V_8 -> V_12 & V_166 ) ) {
V_8 -> V_84 . V_85 [ V_147 ] . V_86 = - 1 ;
V_8 -> V_84 . V_85 [ V_147 ] . V_177 = 0 ;
break;
} else if ( V_8 -> V_84 . V_85 [ V_147 ] . V_86 < 0 ) {
break;
} else if ( V_147 >= V_2 -> V_178 ) {
V_8 -> V_84 . V_85 [ V_147 ] . V_86 = - 1 ;
V_8 -> V_84 . V_85 [ V_147 ] . V_177 = 0 ;
break;
}
V_91 += V_8 -> V_84 . V_85 [ V_147 ] . V_177 ;
}
V_172 = V_147 - 1 ;
if ( V_91 < 0 )
V_91 = 0 ;
F_41 () ;
V_90 = V_6 -> V_2 . V_179 -> V_180 [ V_8 -> V_181 ] ;
V_150 = V_22 -> V_33 ;
F_66 (local, hdr->addr1, sta, tmp) {
if ( ! F_67 ( V_22 -> V_182 , V_20 -> V_28 -> V_27 . V_48 ) )
continue;
V_93 = F_68 ( & V_20 -> V_28 -> V_27 ) ;
if ( V_8 -> V_12 & V_183 )
F_69 ( V_20 , V_184 ) ;
V_130 = ! ! ( V_8 -> V_12 & V_105 ) ;
if ( ! V_130 && F_15 ( V_20 , V_42 ) ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_48 () ;
return;
}
if ( F_70 ( & V_20 -> V_28 -> V_27 ) &&
F_12 ( V_150 ) )
F_71 (
F_13 ( V_22 ) ,
V_20 , true , V_130 ) ;
if ( ( V_6 -> V_2 . V_12 & V_185 ) &&
( F_58 ( V_22 -> V_33 ) ) &&
( V_172 != - 1 ) )
V_20 -> V_186 = V_8 -> V_84 . V_85 [ V_172 ] ;
if ( ( V_8 -> V_12 & V_187 ) &&
( F_12 ( V_150 ) ) ) {
T_2 V_36 , V_81 ;
T_1 * V_59 ;
V_59 = F_13 ( V_22 ) ;
V_36 = V_59 [ 0 ] & 0xf ;
V_81 = ( ( F_72 ( V_22 -> V_188 ) + 0x10 )
& V_189 ) ;
F_24 ( & V_20 -> V_28 -> V_27 , V_22 -> V_60 ,
V_36 , V_81 ) ;
}
if ( ! V_130 && F_73 ( V_150 ) ) {
T_2 V_36 , V_25 ;
V_175 = (struct V_174 * ) V_4 -> V_23 ;
V_25 = F_72 ( V_175 -> V_25 ) ;
if ( ! ( V_25 & V_190 ) ) {
T_2 V_81 = F_72 ( V_175 -> V_191 ) ;
V_36 = ( V_25 &
V_192 ) >>
V_193 ;
F_29 ( V_20 , V_36 , V_81 ) ;
}
}
if ( V_8 -> V_12 & V_194 ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_48 () ;
return;
} else {
if ( ! V_130 )
V_20 -> V_195 ++ ;
V_20 -> V_196 += V_91 ;
}
F_74 ( V_6 , V_90 , V_20 , V_4 ) ;
if ( F_70 ( & V_20 -> V_28 -> V_27 ) )
F_75 ( V_6 , V_20 , V_4 ) ;
if ( ! ( V_8 -> V_12 & V_197 ) && V_130 )
F_25 ( V_20 , V_4 ) ;
if ( ( V_20 -> V_28 -> V_27 . type == V_76 ) &&
( V_6 -> V_2 . V_12 & V_57 ) )
F_76 ( V_20 -> V_28 , ( void * ) V_4 -> V_23 , V_130 ) ;
if ( V_6 -> V_2 . V_12 & V_57 ) {
if ( V_8 -> V_12 & V_105 ) {
if ( V_20 -> V_167 )
V_20 -> V_167 = 0 ;
} else {
F_63 ( V_20 , V_4 ) ;
}
}
if ( V_130 )
V_20 -> V_198 = V_8 -> V_84 . V_199 ;
F_56 ( V_6 , V_4 , V_20 , V_22 ) ;
}
F_48 () ;
F_77 ( V_6 ) ;
if ( V_8 -> V_12 & V_105 ) {
if ( F_78 ( V_22 -> V_188 ) ) {
V_6 -> V_200 ++ ;
if ( F_36 ( V_22 -> V_60 ) )
V_6 -> V_201 ++ ;
if ( V_91 > 0 )
V_6 -> V_202 ++ ;
if ( V_91 > 1 )
V_6 -> V_203 ++ ;
}
if ( ! F_36 ( V_22 -> V_60 ) ||
F_58 ( V_150 ) ||
F_79 ( V_150 ) )
V_6 -> V_204 ++ ;
} else {
if ( F_78 ( V_22 -> V_188 ) )
V_6 -> V_205 ++ ;
}
if ( F_44 ( V_150 ) && F_80 ( V_150 ) &&
( V_6 -> V_2 . V_12 & V_57 ) &&
! ( V_8 -> V_12 & V_197 ) &&
V_6 -> V_206 && ! ( V_6 -> V_207 ) ) {
if ( V_8 -> V_12 & V_105 ) {
V_6 -> V_206 -> V_61 . V_208 . V_12 |=
V_209 ;
} else
F_18 ( & V_6 -> V_210 , V_26 +
F_81 ( 10 ) ) ;
}
F_40 ( V_6 , V_4 , false ) ;
F_82 ( V_4 ) ;
V_173 = ! ! ( V_8 -> V_12 & V_197 ) ||
! ( F_58 ( V_150 ) ) ;
if ( ! V_6 -> V_211 && ( ! V_173 || ! V_6 -> V_212 ) ) {
F_83 ( V_4 ) ;
return;
}
V_92 = F_30 ( V_8 ) ;
if ( F_84 ( F_85 ( V_4 ) < V_92 ) ) {
F_86 ( L_2 ) ;
F_83 ( V_4 ) ;
return;
}
F_32 ( V_6 , V_90 , V_4 , V_91 ,
V_92 , V_93 ) ;
F_87 ( V_4 , 0 ) ;
V_4 -> V_213 = V_214 ;
V_4 -> V_10 = V_215 ;
V_4 -> V_216 = F_88 ( V_217 ) ;
memset ( V_4 -> V_218 , 0 , sizeof( V_4 -> V_218 ) ) ;
F_41 () ;
F_42 (sdata, &local->interfaces, list) {
if ( V_28 -> V_27 . type == V_219 ) {
if ( ! F_27 ( V_28 ) )
continue;
if ( ( V_28 -> V_61 . V_220 & V_221 ) &&
! V_173 )
continue;
if ( V_171 ) {
V_169 = F_89 ( V_4 , V_137 ) ;
if ( V_169 ) {
V_169 -> V_135 = V_171 ;
F_90 ( V_169 ) ;
}
}
V_171 = V_28 -> V_135 ;
}
}
if ( V_171 ) {
V_4 -> V_135 = V_171 ;
F_90 ( V_4 ) ;
V_4 = NULL ;
}
F_48 () ;
F_83 ( V_4 ) ;
}
void F_91 ( struct V_222 * V_223 , T_5 V_224 )
{
struct V_19 * V_20 = F_92 ( V_223 , struct V_19 , V_20 ) ;
F_64 ( V_20 -> V_28 -> V_135 , V_20 -> V_20 . V_48 ,
V_224 , V_137 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_40 ( V_6 , V_4 , true ) ;
F_55 ( V_4 ) ;
}
void F_93 ( struct V_1 * V_2 ,
struct V_225 * V_226 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_94 ( V_226 ) ) )
F_7 ( V_2 , V_4 ) ;
}
