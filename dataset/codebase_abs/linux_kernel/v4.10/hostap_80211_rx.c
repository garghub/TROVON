void F_1 ( const char * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
T_1 V_8 ;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
F_2 ( V_10 L_1
L_2 ,
V_1 , V_5 -> signal , V_5 -> V_11 , V_5 -> V_12 ,
V_3 -> V_13 , V_14 ) ;
if ( V_3 -> V_13 < 2 )
return;
V_8 = F_3 ( V_7 -> V_15 ) ;
F_2 ( V_10 L_3 ,
V_8 , ( V_8 & V_16 ) >> 2 ,
( V_8 & V_17 ) >> 4 ,
V_8 & V_18 ? L_4 : L_5 ,
V_8 & V_19 ? L_6 : L_5 ) ;
if ( V_3 -> V_13 < V_20 ) {
F_2 ( L_7 ) ;
return;
}
F_2 ( L_8 , F_3 ( V_7 -> V_21 ) ,
F_3 ( V_7 -> V_22 ) ) ;
F_2 ( V_10 L_9 , V_7 -> V_23 ) ;
F_2 ( L_10 , V_7 -> V_24 ) ;
F_2 ( L_11 , V_7 -> V_25 ) ;
if ( V_3 -> V_13 >= 30 )
F_2 ( L_12 , V_7 -> V_26 ) ;
F_2 ( L_7 ) ;
}
int F_4 ( struct V_27 * V_28 , struct V_2 * V_3 ,
struct V_4 * V_5 , int type )
{
struct V_29 * V_30 ;
T_2 * V_31 ;
int V_32 , V_33 , V_34 , V_35 ;
T_1 V_8 ;
int V_36 , V_37 ;
struct V_6 * V_38 ;
V_30 = F_5 ( V_28 ) ;
V_31 = V_30 -> V_31 ;
if ( V_28 -> type == V_39 ) {
if ( V_31 -> V_40 == V_41 ) {
V_36 = 1 ;
V_33 = sizeof( struct V_42 ) ;
} else {
V_36 = 2 ;
V_33 = sizeof( struct V_43 ) ;
}
} else if ( V_28 -> type == V_44 ) {
V_36 = 3 ;
V_33 = sizeof( struct V_45 ) ;
} else {
V_36 = 0 ;
V_33 = 0 ;
}
V_38 = (struct V_6 * ) V_3 -> V_9 ;
V_8 = F_3 ( V_38 -> V_15 ) ;
if ( type == V_46 && ( V_8 & V_47 ) ) {
F_2 ( V_10 L_13
L_14 , V_28 -> V_1 , V_8 & V_47 ) ;
F_6 ( V_3 ) ;
return 0 ;
}
V_32 = F_7 ( V_38 -> V_15 ) ;
V_34 = V_33 ;
V_35 = 0 ;
#ifdef F_8
V_35 += 4 ;
#endif
V_34 -= F_9 ( V_3 ) ;
V_35 -= F_10 ( V_3 ) ;
if ( V_34 > 0 || V_35 > 0 ) {
if ( F_11 ( V_3 , V_34 > 0 ? V_34 : 0 ,
V_35 > 0 ? V_35 : 0 ,
V_48 ) ) {
F_2 ( V_10 L_15
L_16 , V_28 -> V_1 ) ;
F_6 ( V_3 ) ;
return 0 ;
}
}
#ifdef F_8
memset ( F_12 ( V_3 , 4 ) , 0xff , 4 ) ;
#endif
if ( V_36 == 1 ) {
struct V_42 * V_7 ;
V_7 = (struct V_42 * )
F_13 ( V_3 , V_33 ) ;
memset ( V_7 , 0 , V_33 ) ;
V_7 -> V_49 = V_50 ;
V_7 -> V_51 = sizeof( * V_7 ) ;
memcpy ( V_7 -> V_52 , V_28 -> V_1 , sizeof( V_7 -> V_52 ) ) ;
#define F_14 ( T_3 , T_4 , T_5 , T_6 , T_7 ) \
hdr->f.did = LWNG_CAP_DID_BASE | (i << 12); \
hdr->f.status = s; hdr->f.len = l; hdr->f.data = d
F_14 ( V_53 , 1 , 0 , 4 , V_14 ) ;
F_14 ( V_54 , 2 , 0 , 4 , V_5 -> V_55 ) ;
F_14 ( V_56 , 3 , 1 , 4 , 0 ) ;
F_14 ( V_57 , 4 , 1 , 4 , 0 ) ;
F_14 ( V_58 , 5 , 1 , 4 , 0 ) ;
F_14 ( signal , 6 , 0 , 4 , V_5 -> signal ) ;
F_14 ( V_11 , 7 , 0 , 4 , V_5 -> V_11 ) ;
F_14 ( V_12 , 8 , 0 , 4 , V_5 -> V_12 / 5 ) ;
F_14 ( V_59 , 9 , 0 , 4 , 0 ) ;
F_14 ( V_60 , 10 , 0 , 4 , V_3 -> V_13 - V_33 ) ;
#undef F_14
} else if ( V_36 == 2 ) {
struct V_43 * V_7 ;
V_7 = (struct V_43 * )
F_13 ( V_3 , V_33 ) ;
memset ( V_7 , 0 , V_33 ) ;
V_7 -> V_61 = F_15 ( V_62 ) ;
V_7 -> V_63 = F_15 ( V_33 ) ;
V_7 -> V_54 = F_16 ( V_5 -> V_55 ) ;
V_7 -> V_53 = F_16 ( V_14 ) ;
V_7 -> V_64 = F_15 ( 4 ) ;
V_7 -> V_56 = F_15 ( V_31 -> V_56 ) ;
V_7 -> V_65 = F_15 ( V_5 -> V_12 ) ;
V_7 -> V_66 = F_15 ( 0 ) ;
V_7 -> V_67 = F_15 ( 0 ) ;
V_7 -> V_68 = F_15 ( 3 ) ;
V_7 -> V_69 = F_15 ( V_5 -> signal ) ;
V_7 -> V_70 = F_15 ( V_5 -> V_11 ) ;
V_7 -> V_71 = F_15 ( 0 ) ;
V_7 -> V_72 = F_15 ( 1 ) ;
} else if ( V_36 == 3 ) {
struct V_45 * V_7 ;
V_7 = (struct V_45 * ) F_13 ( V_3 , V_33 ) ;
memset ( V_7 , 0 , V_33 ) ;
V_7 -> V_7 . V_73 = F_17 ( V_33 ) ;
V_7 -> V_7 . V_74 =
F_18 ( ( 1 << V_75 ) |
( 1 << V_76 ) |
( 1 << V_77 ) |
( 1 << V_78 ) |
( 1 << V_79 ) ) ;
V_7 -> V_80 = F_19 ( V_5 -> V_55 ) ;
V_7 -> V_81 = F_17 ( V_82 [ V_31 -> V_56 - 1 ] ) ;
V_7 -> V_83 = F_17 ( V_84 |
V_85 ) ;
V_7 -> V_12 = V_5 -> V_12 / 5 ;
V_7 -> V_86 = V_5 -> signal ;
V_7 -> V_87 = V_5 -> V_11 ;
}
V_37 = V_3 -> V_13 - V_33 ;
V_3 -> V_28 = V_28 ;
F_20 ( V_3 ) ;
F_21 ( V_3 , V_32 ) ;
if ( V_36 )
F_21 ( V_3 , V_33 ) ;
V_3 -> V_88 = V_89 ;
V_3 -> V_90 = F_22 ( V_91 ) ;
memset ( V_3 -> V_92 , 0 , sizeof( V_3 -> V_92 ) ) ;
F_23 ( V_3 ) ;
return V_37 ;
}
static void F_24 ( struct V_27 * V_28 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_13 ;
V_13 = F_4 ( V_28 , V_3 , V_5 , V_93 ) ;
V_28 -> V_94 . V_95 ++ ;
V_28 -> V_94 . V_96 += V_13 ;
}
static struct V_97 *
F_25 ( T_2 * V_31 , unsigned int V_98 ,
unsigned int V_99 , T_8 * V_100 , T_8 * V_101 )
{
struct V_97 * V_102 ;
int T_4 ;
for ( T_4 = 0 ; T_4 < V_103 ; T_4 ++ ) {
V_102 = & V_31 -> V_104 [ T_4 ] ;
if ( V_102 -> V_3 != NULL &&
F_26 ( V_14 , V_102 -> V_105 + 2 * V_106 ) ) {
F_2 ( V_10 L_17
L_18 ,
V_31 -> V_28 -> V_1 , V_102 -> V_98 , V_102 -> V_107 ) ;
F_27 ( V_102 -> V_3 ) ;
V_102 -> V_3 = NULL ;
}
if ( V_102 -> V_3 != NULL && V_102 -> V_98 == V_98 &&
( V_102 -> V_107 + 1 == V_99 || V_99 == - 1 ) &&
memcmp ( V_102 -> V_108 , V_100 , V_109 ) == 0 &&
memcmp ( V_102 -> V_110 , V_101 , V_109 ) == 0 )
return V_102 ;
}
return NULL ;
}
static struct V_2 *
F_28 ( T_2 * V_31 , struct V_6 * V_7 )
{
struct V_2 * V_3 = NULL ;
T_1 V_111 ;
unsigned int V_99 , V_98 ;
struct V_97 * V_102 ;
V_111 = F_3 ( V_7 -> V_22 ) ;
V_99 = V_111 & V_112 ;
V_98 = ( V_111 & V_113 ) >> 4 ;
if ( V_99 == 0 ) {
V_3 = F_29 ( V_31 -> V_28 -> V_114 +
sizeof( struct V_6 ) +
8 +
2 +
8 + V_109 ) ;
if ( V_3 == NULL )
return NULL ;
V_102 = & V_31 -> V_104 [ V_31 -> V_115 ] ;
V_31 -> V_115 ++ ;
if ( V_31 -> V_115 >= V_103 )
V_31 -> V_115 = 0 ;
if ( V_102 -> V_3 != NULL )
F_27 ( V_102 -> V_3 ) ;
V_102 -> V_105 = V_14 ;
V_102 -> V_98 = V_98 ;
V_102 -> V_107 = V_99 ;
V_102 -> V_3 = V_3 ;
memcpy ( V_102 -> V_108 , V_7 -> V_24 , V_109 ) ;
memcpy ( V_102 -> V_110 , V_7 -> V_23 , V_109 ) ;
} else {
V_102 = F_25 ( V_31 , V_98 , V_99 , V_7 -> V_24 ,
V_7 -> V_23 ) ;
if ( V_102 != NULL ) {
V_102 -> V_107 = V_99 ;
V_3 = V_102 -> V_3 ;
}
}
return V_3 ;
}
static int F_30 ( T_2 * V_31 ,
struct V_6 * V_7 )
{
T_1 V_111 ;
unsigned int V_98 ;
struct V_97 * V_102 ;
V_111 = F_3 ( V_7 -> V_22 ) ;
V_98 = ( V_111 & V_113 ) >> 4 ;
V_102 = F_25 ( V_31 , V_98 , - 1 , V_7 -> V_24 , V_7 -> V_23 ) ;
if ( V_102 == NULL ) {
F_2 ( V_10 L_19
L_20 ,
V_31 -> V_28 -> V_1 , V_98 ) ;
return - 1 ;
}
V_102 -> V_3 = NULL ;
return 0 ;
}
static struct V_116 * F_31 ( T_2 * V_31 , T_8 * V_117 ,
T_8 * V_118 , T_9 V_119 )
{
struct V_120 * V_121 ;
struct V_116 * V_122 ;
F_32 (ptr, &local->bss_list) {
V_122 = F_33 ( V_121 , struct V_116 , V_123 ) ;
if ( memcmp ( V_122 -> V_117 , V_117 , V_109 ) == 0 &&
( V_118 == NULL ||
( V_119 == V_122 -> V_119 &&
memcmp ( V_118 , V_122 -> V_118 , V_119 ) == 0 ) ) ) {
F_34 ( & V_122 -> V_123 , & V_31 -> V_124 ) ;
return V_122 ;
}
}
return NULL ;
}
static struct V_116 * F_35 ( T_2 * V_31 , T_8 * V_117 ,
T_8 * V_118 , T_9 V_119 )
{
struct V_116 * V_122 ;
if ( V_31 -> V_125 >= V_126 ) {
V_122 = F_33 ( V_31 -> V_124 . V_127 ,
struct V_116 , V_123 ) ;
F_36 ( & V_122 -> V_123 ) ;
V_31 -> V_125 -- ;
} else {
V_122 = F_37 ( sizeof( * V_122 ) , V_48 ) ;
if ( V_122 == NULL )
return NULL ;
}
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
memcpy ( V_122 -> V_117 , V_117 , V_109 ) ;
memcpy ( V_122 -> V_118 , V_118 , V_119 ) ;
V_122 -> V_119 = V_119 ;
V_31 -> V_125 ++ ;
F_38 ( & V_122 -> V_123 , & V_31 -> V_124 ) ;
return V_122 ;
}
static void F_39 ( T_2 * V_31 )
{
struct V_116 * V_122 ;
while ( V_31 -> V_125 > 0 ) {
V_122 = F_33 ( V_31 -> V_124 . V_127 ,
struct V_116 , V_123 ) ;
if ( ! F_26 ( V_14 , V_122 -> V_128 + 60 * V_106 ) )
break;
F_36 ( & V_122 -> V_123 ) ;
V_31 -> V_125 -- ;
F_40 ( V_122 ) ;
}
}
static void F_41 ( T_2 * V_31 , struct V_2 * V_3 ,
int V_129 )
{
struct V_130 * V_131 ;
int V_132 , V_133 = 0 ;
T_8 * V_134 ;
T_8 * V_118 = NULL , * V_135 = NULL , * V_136 = NULL ;
T_9 V_119 = 0 , V_137 = 0 , V_138 = 0 ;
struct V_116 * V_122 ;
if ( V_3 -> V_13 < V_139 + sizeof( V_131 -> V_140 . V_141 ) )
return;
V_131 = (struct V_130 * ) V_3 -> V_9 ;
V_134 = V_131 -> V_140 . V_141 . V_142 ;
V_132 = V_3 -> V_13 - ( V_134 - V_3 -> V_9 ) ;
while ( V_132 >= 2 ) {
if ( 2 + V_134 [ 1 ] > V_132 )
return;
switch ( * V_134 ) {
case V_143 :
V_118 = V_134 + 2 ;
V_119 = V_134 [ 1 ] ;
break;
case V_144 :
if ( V_134 [ 1 ] >= 4 &&
V_134 [ 2 ] == 0x00 && V_134 [ 3 ] == 0x50 &&
V_134 [ 4 ] == 0xf2 && V_134 [ 5 ] == 1 ) {
V_135 = V_134 ;
V_137 = V_134 [ 1 ] + 2 ;
}
break;
case V_145 :
V_136 = V_134 ;
V_138 = V_134 [ 1 ] + 2 ;
break;
case V_146 :
if ( V_134 [ 1 ] >= 1 )
V_133 = V_134 [ 2 ] ;
break;
}
V_132 -= 2 + V_134 [ 1 ] ;
V_134 += 2 + V_134 [ 1 ] ;
}
if ( V_137 > V_147 )
V_137 = V_147 ;
if ( V_138 > V_147 )
V_138 = V_147 ;
if ( V_119 > sizeof( V_122 -> V_118 ) )
V_119 = sizeof( V_122 -> V_118 ) ;
F_42 ( & V_31 -> V_148 ) ;
V_122 = F_31 ( V_31 , V_131 -> V_117 , V_118 , V_119 ) ;
if ( V_122 == NULL )
V_122 = F_35 ( V_31 , V_131 -> V_117 , V_118 , V_119 ) ;
if ( V_122 ) {
V_122 -> V_128 = V_14 ;
V_122 -> V_149 ++ ;
V_122 -> V_150 = F_3 ( V_131 -> V_140 . V_141 . V_150 ) ;
if ( V_135 ) {
memcpy ( V_122 -> V_151 , V_135 , V_137 ) ;
V_122 -> V_152 = V_137 ;
} else
V_122 -> V_152 = 0 ;
if ( V_136 ) {
memcpy ( V_122 -> V_153 , V_136 , V_138 ) ;
V_122 -> V_154 = V_138 ;
} else
V_122 -> V_154 = 0 ;
V_122 -> V_133 = V_133 ;
}
F_39 ( V_31 ) ;
F_43 ( & V_31 -> V_148 ) ;
}
static int
F_44 ( T_2 * V_31 , struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 type ,
T_1 V_129 )
{
if ( V_31 -> V_155 == V_156 )
F_45 ( V_31 , (struct V_6 * ) V_3 -> V_9 ) ;
if ( V_31 -> V_157 && type == V_158 ) {
if ( V_129 == V_159 &&
V_31 -> V_155 == V_156 ) {
struct V_2 * V_160 ;
V_160 = F_46 ( V_3 , V_48 ) ;
if ( V_160 )
F_47 ( V_160 -> V_28 , V_160 , V_5 ) ;
}
V_31 -> V_161 . V_95 ++ ;
V_31 -> V_161 . V_96 += V_3 -> V_13 ;
if ( V_31 -> V_162 == NULL )
return - 1 ;
F_4 ( V_31 -> V_162 , V_3 , V_5 , V_46 ) ;
return 0 ;
}
if ( V_31 -> V_155 == V_156 ) {
if ( type != V_158 &&
type != V_163 ) {
F_2 ( V_10 L_21
L_22 ,
V_3 -> V_28 -> V_1 , type >> 2 , V_129 >> 4 ) ;
return - 1 ;
}
F_47 ( V_3 -> V_28 , V_3 , V_5 ) ;
return 0 ;
} else if ( type == V_158 &&
( V_129 == V_159 ||
V_129 == V_164 ) ) {
F_41 ( V_31 , V_3 , V_129 ) ;
return - 1 ;
} else if ( type == V_158 &&
( V_129 == V_165 ||
V_129 == V_166 ) ) {
return - 1 ;
} else {
F_2 ( V_10 L_23
L_24 ,
V_3 -> V_28 -> V_1 , type >> 2 , V_129 >> 4 ) ;
return - 1 ;
}
}
static struct V_27 * F_48 ( T_2 * V_31 ,
T_8 * V_167 )
{
struct V_29 * V_30 = NULL ;
struct V_120 * V_121 ;
F_49 ( & V_31 -> V_168 ) ;
F_32 (ptr, &local->hostap_interfaces) {
V_30 = F_33 ( V_121 , struct V_29 , V_123 ) ;
if ( V_30 -> type == V_169 &&
memcmp ( V_30 -> V_140 . V_170 . V_171 , V_167 , V_109 ) == 0 )
break;
V_30 = NULL ;
}
F_50 ( & V_31 -> V_168 ) ;
return V_30 ? V_30 -> V_28 : NULL ;
}
static int
F_51 ( T_2 * V_31 , struct V_6 * V_7 , T_1 V_8 ,
struct V_27 * * V_170 )
{
if ( ( V_8 & ( V_18 | V_19 ) ) !=
( V_18 | V_19 ) &&
( V_31 -> V_155 != V_156 || ! ( V_8 & V_18 ) ) )
return 0 ;
if ( ! F_52 ( V_7 -> V_23 , V_31 -> V_28 -> V_172 ) &&
( V_7 -> V_23 [ 0 ] != 0xff || V_7 -> V_23 [ 1 ] != 0xff ||
V_7 -> V_23 [ 2 ] != 0xff || V_7 -> V_23 [ 3 ] != 0xff ||
V_7 -> V_23 [ 4 ] != 0xff || V_7 -> V_23 [ 5 ] != 0xff ) ) {
F_53 ( V_173 , L_25
L_26 ,
V_31 -> V_28 -> V_1 ,
V_8 & V_19 ? L_27 : L_28 ,
V_7 -> V_23 ) ;
return - 1 ;
}
* V_170 = F_48 ( V_31 , V_7 -> V_24 ) ;
if ( * V_170 == NULL && V_8 & V_19 &&
( V_31 -> V_155 != V_174 ||
! ( V_31 -> V_175 & V_176 ) ||
memcmp ( V_7 -> V_24 , V_31 -> V_117 , V_109 ) != 0 ) ) {
F_53 ( V_177 , L_29
L_30 ,
V_31 -> V_28 -> V_1 , V_7 -> V_24 ) ;
if ( V_31 -> V_178 && V_31 -> V_178 -> V_179 )
F_54 ( V_31 , V_7 -> V_24 , V_180 ) ;
return - 1 ;
}
if ( * V_170 && ! ( V_8 & V_19 ) && V_31 -> V_178 &&
F_55 ( V_31 -> V_178 , V_7 -> V_24 ) ) {
* V_170 = NULL ;
}
return 0 ;
}
static int F_56 ( T_2 * V_31 , struct V_2 * V_3 )
{
struct V_27 * V_28 = V_31 -> V_28 ;
T_1 V_8 , V_181 ;
struct V_6 * V_7 ;
T_8 * V_134 ;
if ( V_3 -> V_13 < 24 )
return 0 ;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
V_8 = F_3 ( V_7 -> V_15 ) ;
if ( ( V_8 & ( V_18 | V_19 ) ) ==
V_18 &&
F_52 ( V_7 -> V_23 , V_28 -> V_172 ) &&
F_52 ( V_7 -> V_25 , V_28 -> V_172 ) ) {
} else if ( ( V_8 & ( V_18 | V_19 ) ) ==
V_19 &&
F_52 ( V_7 -> V_23 , V_28 -> V_172 ) ) {
} else
return 0 ;
if ( V_3 -> V_13 < 24 + 8 )
return 0 ;
V_134 = V_3 -> V_9 + 24 ;
V_181 = ( V_134 [ 6 ] << 8 ) | V_134 [ 7 ] ;
if ( V_181 == V_182 )
return 1 ;
return 0 ;
}
static int
F_57 ( T_2 * V_31 , struct V_2 * V_3 ,
struct V_183 * V_184 )
{
struct V_6 * V_7 ;
int V_185 , V_32 ;
if ( V_184 == NULL || V_184 -> V_186 -> V_187 == NULL )
return 0 ;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
V_32 = F_7 ( V_7 -> V_15 ) ;
if ( V_31 -> V_188 &&
strcmp ( V_184 -> V_186 -> V_1 , L_31 ) == 0 ) {
if ( F_58 () ) {
F_2 ( V_10 L_32
L_33 ,
V_31 -> V_28 -> V_1 , V_7 -> V_24 ) ;
}
return - 1 ;
}
F_59 ( & V_184 -> V_189 ) ;
V_185 = V_184 -> V_186 -> V_187 ( V_3 , V_32 , V_184 -> V_190 ) ;
F_60 ( & V_184 -> V_189 ) ;
if ( V_185 < 0 ) {
F_2 ( V_10 L_34 ,
V_31 -> V_28 -> V_1 , V_7 -> V_24 , V_185 ) ;
V_31 -> V_191 . V_192 ++ ;
return - 1 ;
}
return V_185 ;
}
static int
F_61 ( T_2 * V_31 , struct V_2 * V_3 ,
int V_193 , struct V_183 * V_184 )
{
struct V_6 * V_7 ;
int V_185 , V_32 ;
if ( V_184 == NULL || V_184 -> V_186 -> V_194 == NULL )
return 0 ;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
V_32 = F_7 ( V_7 -> V_15 ) ;
F_59 ( & V_184 -> V_189 ) ;
V_185 = V_184 -> V_186 -> V_194 ( V_3 , V_193 , V_32 , V_184 -> V_190 ) ;
F_60 ( & V_184 -> V_189 ) ;
if ( V_185 < 0 ) {
F_2 ( V_10 L_35
L_36 ,
V_31 -> V_28 -> V_1 , V_7 -> V_24 , V_193 ) ;
return - 1 ;
}
return 0 ;
}
void F_62 ( struct V_27 * V_28 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_29 * V_30 ;
T_2 * V_31 ;
struct V_6 * V_7 ;
T_9 V_32 ;
T_1 V_8 , type , V_129 , V_111 ;
struct V_27 * V_170 = NULL ;
unsigned int V_99 ;
T_8 * V_195 ;
struct V_2 * V_160 = NULL ;
T_1 V_181 ;
int V_196 = 0 ;
int V_197 = 0 ;
T_8 V_101 [ V_109 ] ;
T_8 V_100 [ V_109 ] ;
struct V_183 * V_184 = NULL ;
void * V_198 = NULL ;
int V_193 = 0 ;
V_30 = F_5 ( V_28 ) ;
V_31 = V_30 -> V_31 ;
V_30 -> V_94 . V_95 ++ ;
V_30 -> V_94 . V_96 += V_3 -> V_13 ;
V_28 = V_31 -> V_199 ;
V_30 = F_5 ( V_28 ) ;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
if ( V_3 -> V_13 < 10 )
goto V_200;
V_8 = F_3 ( V_7 -> V_15 ) ;
type = V_8 & V_16 ;
V_129 = V_8 & V_17 ;
V_111 = F_3 ( V_7 -> V_22 ) ;
V_99 = V_111 & V_112 ;
V_32 = F_7 ( V_7 -> V_15 ) ;
#ifdef F_63
if ( V_30 -> V_201 . V_202 > 0 ) {
struct V_203 V_204 ;
V_204 . V_205 = V_5 -> signal ;
V_204 . V_11 = V_5 -> V_11 ;
V_204 . V_206 = V_207 | V_208
| V_209 | V_210 ;
F_64 ( V_28 , V_7 -> V_24 , & V_204 ) ;
}
#endif
F_65 ( V_31 -> V_178 , V_7 , V_5 ) ;
if ( V_31 -> V_155 == V_211 ) {
F_24 ( V_28 , V_3 , V_5 ) ;
return;
}
if ( V_31 -> V_212 ) {
int V_213 = 0 ;
if ( V_3 -> V_13 >= V_32 + 3 )
V_213 = V_3 -> V_9 [ V_32 + 3 ] >> 6 ;
V_184 = V_31 -> V_214 . V_184 [ V_213 ] ;
V_198 = NULL ;
if ( ! ( V_7 -> V_23 [ 0 ] & 0x01 ) || V_31 -> V_215 )
( void ) F_66 ( V_31 , V_7 , & V_184 ,
& V_198 ) ;
if ( V_184 && ( V_184 -> V_186 == NULL ||
V_184 -> V_186 -> V_187 == NULL ) )
V_184 = NULL ;
if ( ! V_184 && ( V_8 & V_216 ) ) {
#if 0
printk(KERN_DEBUG "%s: WEP decryption failed (not set)"
" (SA=%pM)\n",
local->dev->name, hdr->addr2);
#endif
V_31 -> V_191 . V_192 ++ ;
goto V_200;
}
}
if ( type != V_217 ) {
if ( type == V_158 &&
V_129 == V_218 &&
V_8 & V_216 && V_31 -> V_212 &&
( V_193 = F_57 ( V_31 , V_3 , V_184 ) ) < 0 )
{
F_2 ( V_10 L_37
L_38 , V_28 -> V_1 , V_7 -> V_24 ) ;
goto V_200;
}
if ( F_44 ( V_31 , V_3 , V_5 , type , V_129 ) )
goto V_200;
else
goto V_219;
}
if ( V_3 -> V_13 < V_20 )
goto V_200;
switch ( V_8 & ( V_19 | V_18 ) ) {
case V_19 :
memcpy ( V_101 , V_7 -> V_23 , V_109 ) ;
memcpy ( V_100 , V_7 -> V_25 , V_109 ) ;
break;
case V_18 :
memcpy ( V_101 , V_7 -> V_25 , V_109 ) ;
memcpy ( V_100 , V_7 -> V_24 , V_109 ) ;
break;
case V_19 | V_18 :
if ( V_3 -> V_13 < V_220 )
goto V_200;
memcpy ( V_101 , V_7 -> V_25 , V_109 ) ;
memcpy ( V_100 , V_7 -> V_26 , V_109 ) ;
break;
default:
memcpy ( V_101 , V_7 -> V_23 , V_109 ) ;
memcpy ( V_100 , V_7 -> V_24 , V_109 ) ;
break;
}
if ( F_51 ( V_31 , V_7 , V_8 , & V_170 ) )
goto V_200;
if ( V_170 )
V_3 -> V_28 = V_28 = V_170 ;
if ( V_31 -> V_155 == V_156 && ! V_170 &&
( V_8 & ( V_18 | V_19 ) ) ==
V_19 &&
V_31 -> V_221 &&
memcmp ( V_7 -> V_24 , V_31 -> V_222 , V_109 ) == 0 ) {
V_3 -> V_28 = V_28 = V_31 -> V_221 ;
V_197 = 1 ;
}
if ( ( V_31 -> V_155 == V_156 ||
V_31 -> V_155 == V_223 ) &&
! V_197 ) {
switch ( F_67 ( V_31 , V_28 , V_3 , V_5 ,
V_170 != NULL ) ) {
case V_224 :
V_196 = 0 ;
break;
case V_225 :
V_196 = 1 ;
break;
case V_226 :
goto V_200;
case V_227 :
goto V_219;
}
}
if ( V_129 != V_228 &&
V_129 != V_229 &&
V_129 != V_230 &&
V_129 != V_231 ) {
if ( V_129 != V_232 )
F_2 ( V_10 L_39
L_40 ,
V_28 -> V_1 , type >> 2 , V_129 >> 4 ) ;
goto V_200;
}
if ( V_31 -> V_212 && ( V_8 & V_216 ) &&
( V_193 = F_57 ( V_31 , V_3 , V_184 ) ) < 0 )
goto V_200;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
if ( V_31 -> V_212 && ( V_8 & V_216 ) &&
( V_99 != 0 || ( V_8 & V_233 ) ) ) {
int V_234 ;
struct V_2 * V_235 =
F_28 ( V_31 , V_7 ) ;
if ( ! V_235 ) {
F_2 ( V_10 L_41
L_42 ,
V_28 -> V_1 , ( V_8 & V_233 ) != 0 ,
( V_111 & V_113 ) >> 4 , V_99 ) ;
goto V_200;
}
V_234 = V_3 -> V_13 ;
if ( V_99 != 0 )
V_234 -= V_32 ;
if ( V_235 -> V_236 + V_234 > V_235 -> V_237 ) {
F_2 ( V_238 L_43
L_44 ,
V_28 -> V_1 ) ;
F_30 ( V_31 , V_7 ) ;
goto V_200;
}
if ( V_99 == 0 ) {
F_68 ( V_3 , F_12 ( V_235 , V_234 ) ,
V_234 ) ;
} else {
F_69 ( V_3 , V_32 ,
F_12 ( V_235 ,
V_234 ) , V_234 ) ;
}
F_27 ( V_3 ) ;
V_3 = NULL ;
if ( V_8 & V_233 ) {
goto V_219;
}
V_3 = V_235 ;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
F_30 ( V_31 , V_7 ) ;
}
if ( V_31 -> V_212 && ( V_8 & V_216 ) &&
F_61 ( V_31 , V_3 , V_193 , V_184 ) )
goto V_200;
V_7 = (struct V_6 * ) V_3 -> V_9 ;
if ( V_184 && ! ( V_8 & V_216 ) && ! V_31 -> V_239 ) {
if ( V_31 -> V_240 &&
F_56 ( V_31 , V_3 ) ) {
F_53 ( V_173 , L_45
L_46 , V_31 -> V_28 -> V_1 ) ;
} else {
F_2 ( V_10 L_47
L_48 ,
V_31 -> V_28 -> V_1 , V_7 -> V_24 ) ;
goto V_200;
}
}
if ( V_31 -> V_241 && ! ( V_8 & V_216 ) &&
! F_56 ( V_31 , V_3 ) ) {
if ( F_58 () ) {
F_2 ( V_10 L_49
L_50 ,
V_28 -> V_1 , V_7 -> V_24 ) ;
}
goto V_200;
}
V_195 = V_3 -> V_9 + V_32 ;
V_181 = ( V_195 [ 6 ] << 8 ) | V_195 [ 7 ] ;
if ( V_31 -> V_240 && V_31 -> V_155 == V_156 ) {
if ( V_181 == V_182 ) {
F_53 ( V_173 , L_51 ,
V_28 -> V_1 ) ;
if ( V_31 -> V_157 && V_31 -> V_162 ) {
F_4 ( V_31 -> V_162 , V_3 , V_5 ,
V_46 ) ;
V_31 -> V_161 . V_95 ++ ;
V_31 -> V_161 . V_96 += V_3 -> V_13 ;
goto V_219;
}
} else if ( ! V_196 ) {
F_2 ( V_10 L_52
L_53
L_54 ,
V_28 -> V_1 , V_181 ) ;
goto V_200;
}
}
if ( V_3 -> V_13 - V_32 >= 8 &&
( ( memcmp ( V_195 , V_242 , 6 ) == 0 &&
V_181 != V_243 && V_181 != V_244 ) ||
memcmp ( V_195 , V_245 , 6 ) == 0 ) ) {
F_21 ( V_3 , V_32 + 6 ) ;
memcpy ( F_13 ( V_3 , V_109 ) , V_100 , V_109 ) ;
memcpy ( F_13 ( V_3 , V_109 ) , V_101 , V_109 ) ;
} else {
T_10 V_13 ;
F_21 ( V_3 , V_32 ) ;
V_13 = F_70 ( V_3 -> V_13 ) ;
memcpy ( F_13 ( V_3 , 2 ) , & V_13 , 2 ) ;
memcpy ( F_13 ( V_3 , V_109 ) , V_100 , V_109 ) ;
memcpy ( F_13 ( V_3 , V_109 ) , V_101 , V_109 ) ;
}
if ( V_170 && ( ( V_8 & ( V_18 | V_19 ) ) ==
V_18 ) &&
V_3 -> V_13 >= V_246 + V_109 ) {
F_69 ( V_3 , V_3 -> V_13 - V_109 ,
V_3 -> V_9 + V_109 ,
V_109 ) ;
F_71 ( V_3 , V_3 -> V_13 - V_109 ) ;
}
V_28 -> V_94 . V_95 ++ ;
V_28 -> V_94 . V_96 += V_3 -> V_13 ;
if ( V_31 -> V_155 == V_156 && ! V_170 &&
V_31 -> V_178 -> V_247 ) {
if ( V_101 [ 0 ] & 0x01 ) {
V_31 -> V_178 -> V_248 ++ ;
V_160 = F_46 ( V_3 , V_48 ) ;
if ( V_160 == NULL )
F_2 ( V_10 L_55
L_56 , V_28 -> V_1 ) ;
} else if ( F_72 ( V_31 -> V_178 , V_101 ) ) {
V_31 -> V_178 -> V_249 ++ ;
V_160 = V_3 ;
V_3 = NULL ;
}
}
if ( V_160 != NULL ) {
V_160 -> V_28 = V_28 ;
V_160 -> V_90 = F_22 ( V_250 ) ;
F_20 ( V_160 ) ;
F_73 ( V_160 ) ;
F_74 ( V_160 ) ;
}
if ( V_3 ) {
V_3 -> V_90 = F_75 ( V_3 , V_28 ) ;
memset ( V_3 -> V_92 , 0 , sizeof( V_3 -> V_92 ) ) ;
F_23 ( V_3 ) ;
}
V_219:
if ( V_198 )
F_76 ( V_198 ) ;
return;
V_200:
F_27 ( V_3 ) ;
V_28 -> V_94 . V_200 ++ ;
goto V_219;
}
