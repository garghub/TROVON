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
struct V_56 * V_28 ,
struct V_3 * V_4 , T_3 V_12 )
{
struct V_3 * V_129 ;
struct V_3 * V_130 ;
bool V_131 = false ;
F_41 ( & V_28 -> V_61 . V_132 . V_133 ) ;
V_129 = V_28 -> V_61 . V_132 . V_129 ;
V_130 = V_28 -> V_61 . V_132 . V_130 ;
if ( ( V_4 == V_130 ) && V_129 ) {
V_28 -> V_61 . V_132 . V_129 = NULL ;
V_28 -> V_61 . V_132 . V_130 = NULL ;
V_131 = true ;
}
F_42 ( & V_28 -> V_61 . V_132 . V_133 ) ;
if ( V_131 ) {
F_43 ( ! ( V_6 -> V_2 . V_12 &
V_57 ) ) ;
if ( V_12 & V_105 ) {
F_44 ( V_129 ) ;
} else {
F_45 ( V_28 ,
L_2 ) ;
F_46 ( V_129 , V_4 -> V_134 ) ;
}
}
}
static void F_47 ( struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_135 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
bool V_136 = V_8 -> V_12 & V_105 ;
if ( V_135 )
V_136 = false ;
if ( V_8 -> V_12 & ( V_137 |
V_138 ) ) {
struct V_56 * V_28 = NULL ;
struct V_56 * V_139 ;
T_4 V_140 = ( unsigned long ) V_4 ;
F_48 () ;
if ( V_4 -> V_134 ) {
F_49 (iter_sdata, &local->interfaces,
list) {
if ( ! V_139 -> V_134 )
continue;
if ( V_4 -> V_134 == V_139 -> V_134 ) {
V_28 = V_139 ;
break;
}
}
} else {
V_28 = F_23 ( V_6 -> V_141 ) ;
}
if ( ! V_28 ) {
V_4 -> V_134 = NULL ;
} else if ( V_8 -> V_12 & V_138 ) {
unsigned int V_142 =
F_50 ( V_22 -> V_33 ) ;
if ( F_51 ( V_22 -> V_33 ) &&
( F_52 ( V_4 , V_142 ) ==
V_143 ) )
F_40 ( V_6 , V_28 , V_4 ,
V_8 -> V_12 ) ;
else
F_53 ( V_28 ,
V_22 -> V_33 ,
V_136 ) ;
} else if ( F_54 ( V_22 -> V_33 ) ||
F_55 ( V_22 -> V_33 ) ) {
F_56 ( V_28 -> V_134 , V_22 -> V_60 ,
V_140 , V_136 , V_144 ) ;
} else {
F_57 ( & V_28 -> V_145 , V_140 , V_4 -> V_23 ,
V_4 -> V_82 , V_136 , V_144 ) ;
}
F_58 () ;
}
if ( F_59 ( V_8 -> V_146 ) ) {
struct V_3 * V_147 ;
unsigned long V_12 ;
F_60 ( & V_6 -> V_148 , V_12 ) ;
V_147 = F_61 ( & V_6 -> V_149 ,
V_8 -> V_146 ) ;
if ( V_147 )
F_62 ( & V_6 -> V_149 ,
V_8 -> V_146 ) ;
F_63 ( & V_6 -> V_148 , V_12 ) ;
if ( V_147 ) {
if ( ! V_135 ) {
F_64 ( V_147 , V_136 ) ;
} else {
F_44 ( V_147 ) ;
}
}
}
}
static void F_65 ( struct V_19 * V_20 ,
struct V_7 * V_8 )
{
if ( ( V_8 -> V_12 & V_150 ) &&
! ( V_8 -> V_12 & V_151 ) )
return;
V_20 -> V_152 ++ ;
if ( ! V_20 -> V_20 . V_153 && V_20 -> V_152 < V_154 )
return;
if ( V_20 -> V_20 . V_153 &&
( V_20 -> V_152 < V_155 ||
F_66 ( V_26 ,
V_20 -> V_156 + V_157 ) ) )
return;
F_67 ( V_20 -> V_28 -> V_134 , V_20 -> V_20 . V_48 ,
V_20 -> V_152 , V_144 ) ;
V_20 -> V_152 = 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
int * V_91 )
{
int V_158 = - 1 ;
int V_159 = - 1 ;
int V_160 ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
if ( ( V_8 -> V_12 & V_150 ) &&
! ( V_8 -> V_12 & V_151 ) ) {
V_8 -> V_84 . V_85 [ V_160 ] . V_86 = - 1 ;
V_8 -> V_84 . V_85 [ V_160 ] . V_159 = 0 ;
break;
} else if ( V_8 -> V_84 . V_85 [ V_160 ] . V_86 < 0 ) {
break;
} else if ( V_160 >= V_2 -> V_162 ) {
V_8 -> V_84 . V_85 [ V_160 ] . V_86 = - 1 ;
V_8 -> V_84 . V_85 [ V_160 ] . V_159 = 0 ;
break;
}
V_159 += V_8 -> V_84 . V_85 [ V_160 ] . V_159 ;
}
V_158 = V_160 - 1 ;
if ( V_159 < 0 )
V_159 = 0 ;
* V_91 = V_159 ;
return V_158 ;
}
void F_69 ( struct V_1 * V_2 ,
struct V_163 * V_164 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_89 * V_90 ;
int V_91 ;
int V_158 ;
bool V_136 , V_165 ;
V_158 = F_68 ( V_2 , V_8 , & V_91 ) ;
V_90 = V_2 -> V_166 -> V_167 [ V_8 -> V_168 ] ;
V_136 = ! ! ( V_8 -> V_12 & V_105 ) ;
V_165 = ! ! ( V_8 -> V_12 & V_169 ) ;
if ( V_164 ) {
struct V_19 * V_20 ;
V_20 = F_70 ( V_164 , struct V_19 , V_20 ) ;
if ( ! V_136 )
V_20 -> V_170 ++ ;
V_20 -> V_171 += V_91 ;
if ( V_136 ) {
V_20 -> V_58 = V_26 ;
if ( V_20 -> V_152 )
V_20 -> V_152 = 0 ;
if ( F_15 ( V_20 , V_172 ) )
V_20 -> V_156 = V_26 ;
} else {
F_65 ( V_20 , V_8 ) ;
}
F_71 ( V_6 , V_90 , V_20 , V_8 ) ;
}
if ( V_136 || V_165 ) {
V_6 -> V_173 ++ ;
if ( ! V_164 )
V_6 -> V_174 ++ ;
if ( V_91 > 0 )
V_6 -> V_175 ++ ;
if ( V_91 > 1 )
V_6 -> V_176 ++ ;
} else {
V_6 -> V_177 ++ ;
}
}
void F_72 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_178 ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_5 V_179 ;
struct V_89 * V_90 ;
struct V_56 * V_28 ;
struct V_180 * V_181 = NULL ;
struct V_19 * V_20 ;
struct V_182 * V_9 ;
int V_91 ;
int V_158 ;
bool V_183 ;
bool V_136 ;
struct V_184 * V_185 ;
int V_92 ;
int V_93 = 0 ;
int V_36 = V_186 ;
const struct V_187 * V_188 ;
V_158 = F_68 ( V_2 , V_8 , & V_91 ) ;
F_48 () ;
V_90 = V_6 -> V_2 . V_166 -> V_167 [ V_8 -> V_168 ] ;
V_179 = V_22 -> V_33 ;
V_188 = F_73 ( V_6 -> V_189 . V_188 , & V_6 -> V_189 ) ;
F_74 (local, tbl, hdr->addr1, sta, tmp) {
if ( ! F_75 ( V_22 -> V_190 , V_20 -> V_28 -> V_27 . V_48 ) )
continue;
V_93 = F_76 ( & V_20 -> V_28 -> V_27 ) ;
if ( V_8 -> V_12 & V_191 )
F_77 ( V_20 , V_192 ) ;
V_136 = ! ! ( V_8 -> V_12 & V_105 ) ;
if ( ! V_136 && F_15 ( V_20 , V_42 ) ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_58 () ;
return;
}
if ( F_78 ( & V_20 -> V_28 -> V_27 ) &&
F_12 ( V_179 ) )
F_79 (
F_13 ( V_22 ) ,
V_20 , true , V_136 ) ;
if ( ( V_6 -> V_2 . V_12 & V_193 ) &&
( F_51 ( V_22 -> V_33 ) ) &&
( V_158 != - 1 ) )
V_20 -> V_194 = V_8 -> V_84 . V_85 [ V_158 ] ;
if ( ( V_8 -> V_12 & V_195 ) &&
( F_12 ( V_179 ) ) ) {
T_2 V_81 ;
T_1 * V_59 ;
V_59 = F_13 ( V_22 ) ;
V_36 = V_59 [ 0 ] & 0xf ;
V_81 = ( ( F_80 ( V_22 -> V_196 ) + 0x10 )
& V_197 ) ;
F_24 ( & V_20 -> V_28 -> V_27 , V_22 -> V_60 ,
V_36 , V_81 ) ;
} else if ( F_12 ( V_179 ) ) {
T_1 * V_59 = F_13 ( V_22 ) ;
V_36 = V_59 [ 0 ] & 0xf ;
}
if ( ! V_136 && F_81 ( V_179 ) ) {
T_2 V_25 ;
V_185 = (struct V_184 * ) V_4 -> V_23 ;
V_25 = F_80 ( V_185 -> V_25 ) ;
if ( ! ( V_25 & V_198 ) ) {
T_2 V_81 = F_80 ( V_185 -> V_199 ) ;
V_36 = ( V_25 &
V_200 ) >>
V_201 ;
F_29 ( V_20 , V_36 , V_81 ) ;
}
}
if ( V_8 -> V_12 & V_202 ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_58 () ;
return;
} else {
if ( ! V_136 )
V_20 -> V_170 ++ ;
V_20 -> V_171 += V_91 ;
if ( F_82 ( V_179 ) ) {
if ( ! V_136 )
V_20 -> V_203 [ V_36 ] ++ ;
V_20 -> V_204 [ V_36 ] += V_91 ;
}
}
F_83 ( V_6 , V_90 , V_20 , V_4 ) ;
if ( F_78 ( & V_20 -> V_28 -> V_27 ) )
F_84 ( V_6 , V_20 , V_4 ) ;
if ( ! ( V_8 -> V_12 & V_205 ) && V_136 )
F_25 ( V_20 , V_4 ) ;
if ( ( V_20 -> V_28 -> V_27 . type == V_76 ) &&
( V_6 -> V_2 . V_12 & V_57 ) )
F_85 ( V_20 -> V_28 , ( void * ) V_4 -> V_23 ,
V_136 , V_8 -> V_84 . V_206 ) ;
if ( V_6 -> V_2 . V_12 & V_57 ) {
if ( V_8 -> V_12 & V_105 ) {
if ( V_20 -> V_152 )
V_20 -> V_152 = 0 ;
if ( F_15 ( V_20 , V_172 ) )
V_20 -> V_156 = V_26 ;
} else {
F_65 ( V_20 , V_8 ) ;
}
}
if ( V_136 )
V_20 -> V_207 = V_8 -> V_84 . V_208 ;
}
F_58 () ;
F_86 ( V_6 ) ;
if ( ( V_8 -> V_12 & V_105 ) ||
( V_8 -> V_12 & V_169 ) ) {
if ( F_87 ( V_22 -> V_196 ) ) {
V_6 -> V_173 ++ ;
if ( F_36 ( F_88 ( V_22 ) ) )
V_6 -> V_174 ++ ;
if ( V_91 > 0 )
V_6 -> V_175 ++ ;
if ( V_91 > 1 )
V_6 -> V_176 ++ ;
}
if ( ! F_36 ( V_22 -> V_60 ) ||
F_51 ( V_179 ) ||
F_89 ( V_179 ) )
V_6 -> V_209 ++ ;
} else {
if ( F_87 ( V_22 -> V_196 ) )
V_6 -> V_177 ++ ;
}
if ( F_54 ( V_179 ) && F_90 ( V_179 ) &&
( V_6 -> V_2 . V_12 & V_57 ) &&
! ( V_8 -> V_12 & V_205 ) &&
V_6 -> V_210 && ! ( V_6 -> V_211 ) ) {
if ( V_8 -> V_12 & V_105 ) {
V_6 -> V_210 -> V_61 . V_132 . V_12 |=
V_212 ;
} else
F_18 ( & V_6 -> V_213 , V_26 +
F_91 ( 10 ) ) ;
}
F_47 ( V_6 , V_4 , false ) ;
F_92 ( V_4 ) ;
V_183 = ! ! ( V_8 -> V_12 & V_205 ) ||
! ( F_51 ( V_179 ) ) ;
if ( ! V_6 -> V_214 && ( ! V_183 || ! V_6 -> V_215 ) ) {
F_93 ( V_4 ) ;
return;
}
V_92 = F_30 ( V_8 ) ;
if ( F_94 ( F_95 ( V_4 ) < V_92 ) ) {
F_96 ( L_3 ) ;
F_93 ( V_4 ) ;
return;
}
F_32 ( V_6 , V_90 , V_4 , V_91 ,
V_92 , V_93 ) ;
F_97 ( V_4 , 0 ) ;
V_4 -> V_216 = V_217 ;
V_4 -> V_10 = V_218 ;
V_4 -> V_219 = F_98 ( V_220 ) ;
memset ( V_4 -> V_221 , 0 , sizeof( V_4 -> V_221 ) ) ;
F_48 () ;
F_49 (sdata, &local->interfaces, list) {
if ( V_28 -> V_27 . type == V_222 ) {
if ( ! F_27 ( V_28 ) )
continue;
if ( ( V_28 -> V_61 . V_223 & V_224 ) &&
! V_183 )
continue;
if ( V_181 ) {
V_178 = F_99 ( V_4 , V_144 ) ;
if ( V_178 ) {
V_178 -> V_134 = V_181 ;
F_100 ( V_178 ) ;
}
}
V_181 = V_28 -> V_134 ;
}
}
if ( V_181 ) {
V_4 -> V_134 = V_181 ;
F_100 ( V_4 ) ;
V_4 = NULL ;
}
F_58 () ;
F_93 ( V_4 ) ;
}
void F_101 ( struct V_163 * V_164 , T_3 V_225 )
{
struct V_19 * V_20 = F_70 ( V_164 , struct V_19 , V_20 ) ;
F_67 ( V_20 -> V_28 -> V_134 , V_20 -> V_20 . V_48 ,
V_225 , V_144 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_47 ( V_6 , V_4 , true ) ;
F_44 ( V_4 ) ;
}
void F_102 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_103 ( V_227 ) ) )
F_7 ( V_2 , V_4 ) ;
}
