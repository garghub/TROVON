static void
F_1 ( struct V_1 T_1 * V_2 )
{
T_2 V_3 ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
V_3 &= ~ F_3 ( 0x3fff ) ;
F_4 ( V_3 , & V_2 -> V_4 ) ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
}
int F_5 ( struct V_5 * V_6 , T_3 V_7 )
{
struct V_1 T_1 * V_2 ;
struct V_8 * V_9 ;
T_2 V_3 , V_10 , V_11 ;
int V_12 = 0 , V_13 = 0 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
F_1 ( V_2 ) ;
V_3 = F_2 ( & V_2 -> V_15 ) ;
V_11 = F_6 ( V_3 ) + 1 ;
V_11 *= 2 ;
do {
F_7 ( 1 ) ;
V_10 = F_2 ( & V_2 -> V_16 ) ;
V_3 = F_2 ( & V_2 -> V_17 ) ;
if ( ( V_10 <= V_11 ) || ( V_3 > 0 ) )
V_12 = 0 ;
else
V_12 ++ ;
V_13 ++ ;
} while ( ( V_12 < V_18 ) &&
( V_13 < V_19 ) );
if ( V_13 >= V_19 )
F_8 ( V_20 L_1 ,
V_21 ) ;
return V_13 ;
}
void F_9 ( struct V_5 * V_6 )
{
int V_22 , V_13 = 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) )
continue;
V_13 += F_5 ( V_6 , V_22 ) ;
if ( V_13 >= V_19 )
break;
}
}
static enum V_25
F_11 ( void T_1 * V_26 , T_2 V_27 , T_3 V_28 )
{
T_2 V_3 ;
T_3 V_22 = 0 ;
enum V_25 V_29 = V_30 ;
F_12 ( 10 ) ;
do {
V_3 = F_2 ( V_26 ) ;
if ( ! ( V_3 & V_27 ) )
return V_31 ;
F_12 ( 100 ) ;
} while ( ++ V_22 <= 9 );
V_22 = 0 ;
do {
V_3 = F_2 ( V_26 ) ;
if ( ! ( V_3 & V_27 ) )
return V_31 ;
F_7 ( 1 ) ;
} while ( ++ V_22 <= V_28 );
return V_29 ;
}
static inline enum V_25
F_13 ( T_2 V_3 , void T_1 * V_32 ,
T_2 V_27 , T_3 V_28 )
{
F_14 ( ( T_3 ) F_15 ( V_3 , 32 , 32 ) , V_32 ) ;
F_16 () ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) , V_32 ) ;
F_16 () ;
return F_11 ( V_32 , V_27 , V_28 ) ;
}
static enum V_25
F_18 ( struct V_8 * V_9 , T_3 V_33 ,
T_3 V_34 , T_3 V_35 , T_2 * V_36 , T_2 * V_37 ,
T_2 * V_38 )
{
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
enum V_25 V_39 ;
T_2 V_3 ;
T_3 V_40 = 0 , V_41 = 3 ;
F_19 ( & V_9 -> V_42 ) ;
if ( ! V_9 -> V_43 ) {
F_20 ( & V_9 -> V_42 ) ;
V_41 = 100 ;
}
F_4 ( * V_36 , & V_2 -> V_44 ) ;
F_4 ( * V_37 , & V_2 -> V_45 ) ;
F_16 () ;
V_3 = F_21 ( V_33 ) |
F_22 ( V_34 ) |
F_23 ( V_35 ) |
V_46 |
* V_38 ;
V_39 = F_13 ( V_3 ,
& V_2 -> V_47 ,
V_46 ,
V_48 ) ;
while ( ( V_39 != V_31 ) && V_40 ++ < V_41 ) {
if ( ! V_9 -> V_43 )
F_24 ( 20 ) ;
V_39 = F_11 (
& V_2 -> V_47 ,
V_46 ,
V_48 ) ;
}
if ( V_39 != V_31 )
goto V_49;
V_3 = F_2 ( & V_2 -> V_47 ) ;
if ( V_3 & V_50 ) {
* V_36 = F_2 ( & V_2 -> V_44 ) ;
* V_37 = F_2 ( & V_2 -> V_45 ) ;
* V_38 = V_3 ;
} else
V_39 = V_30 ;
V_49:
if ( V_9 -> V_43 )
F_20 ( & V_9 -> V_42 ) ;
return V_39 ;
}
enum V_25
F_25 ( struct V_5 * V_6 , T_3 * V_51 ,
T_3 * V_52 , T_3 * V_53 )
{
T_2 V_36 = 0 , V_37 = 0 , V_38 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_39 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_54 ] ;
V_39 = F_18 ( V_9 ,
V_55 ,
V_56 ,
V_57 ,
& V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
* V_51 = F_26 ( V_36 ) ;
* V_52 = F_27 ( V_36 ) ;
* V_53 = F_28 ( V_36 ) ;
return V_39 ;
}
enum V_25 F_29 ( struct V_5 * V_6 )
{
T_2 V_36 = 0 , V_37 = 0 , V_38 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_39 ;
T_3 V_29 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_54 ] ;
V_39 = F_18 ( V_9 ,
V_55 ,
V_56 ,
V_58 ,
& V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 ) {
F_30 ( V_59 , L_2 , V_21 ) ;
goto exit;
}
V_29 = F_31 ( V_38 ) & 0x7F ;
if ( V_29 != 1 ) {
F_30 ( V_59 , L_3 ,
V_21 , V_29 ) ;
V_39 = V_30 ;
}
exit:
return V_39 ;
}
enum V_25
F_32 ( struct V_5 * V_6 , const T_4 * V_60 , int V_61 )
{
T_2 V_36 = 0 , V_37 = 0 , V_38 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_39 ;
int V_62 , V_63 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_54 ] ;
V_39 = F_18 ( V_9 ,
V_55 ,
V_56 ,
V_64 ,
& V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 ) {
F_30 ( V_59 , L_4 ,
V_21 ) ;
return V_39 ;
}
for (; V_61 > 0 ; V_61 -= V_65 ) {
V_38 = 0 ;
V_36 = * ( ( T_2 * ) V_60 ) ;
V_37 = * ( ( T_2 * ) V_60 + 1 ) ;
V_39 = F_18 ( V_9 ,
V_55 ,
V_56 ,
V_66 ,
& V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 ) {
F_30 ( V_59 , L_5 ,
V_21 ) ;
goto V_49;
}
V_62 = F_33 ( V_36 ) ;
switch ( V_62 ) {
case V_67 :
break;
case V_68 :
V_60 += ( V_36 >> 8 ) & 0xFFFFFFFF ;
break;
case V_69 :
goto V_49;
case V_70 :
V_63 = F_34 ( V_36 ) ;
switch ( V_63 ) {
case V_71 :
case V_72 :
F_8 ( V_73
L_6 ) ;
break;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
F_8 ( V_73 L_7 ) ;
break;
case V_79 :
F_8 ( V_73 L_8 ) ;
break;
case V_80 :
F_8 ( V_73 L_9 ) ;
break;
case V_81 :
F_8 ( V_73
L_10 ) ;
break;
default:
F_8 ( V_73 L_11 ,
V_63 ) ;
break;
}
V_39 = V_30 ;
goto V_49;
default:
F_8 ( V_73 L_12 , V_62 ) ;
V_39 = V_30 ;
goto V_49;
}
V_60 += V_65 ;
}
V_49:
return V_39 ;
}
enum V_25
F_35 ( struct V_5 * V_6 ,
struct V_82 * V_83 )
{
T_2 V_36 = 0 , V_37 = 0 , V_38 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_39 ;
int V_22 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_54 ] ;
for ( V_22 = 0 ; V_22 < V_84 ; V_22 ++ ) {
V_36 = F_36 ( V_22 ) ;
V_37 = V_38 = 0 ;
V_39 = F_18 ( V_9 ,
V_85 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
break;
V_83 [ V_22 ] . V_87 = F_37 ( V_36 ) ;
V_83 [ V_22 ] . V_88 = F_38 ( V_36 ) ;
V_83 [ V_22 ] . type = F_39 ( V_36 ) ;
V_83 [ V_22 ] . V_89 = F_40 ( V_36 ) ;
}
return V_39 ;
}
static void F_41 ( struct V_90 * V_91 )
{
F_42 ( V_91 -> V_92 ) ;
F_42 ( V_91 -> V_93 ) ;
F_42 ( V_91 -> V_94 ) ;
F_42 ( V_91 -> V_95 ) ;
F_42 ( V_91 ) ;
}
static enum V_25
F_43 ( struct V_90 * V_91 )
{
T_3 V_22 ;
struct V_8 * V_9 ;
V_9 = V_91 -> V_96 -> V_9 ;
if ( ( V_91 -> V_94 != NULL ) && ( V_91 -> V_95 != NULL ) ) {
for ( V_22 = 0 ; V_22 < V_91 -> V_97 ; V_22 ++ )
V_91 -> V_95 [ V_22 ] = V_91 -> V_94 [ V_22 ] ;
}
switch ( V_91 -> type ) {
case V_98 :
V_9 -> V_99 = (struct V_100 * ) V_91 ;
V_91 -> V_101 = & ( (struct V_100 * )
V_91 ) -> V_101 -> V_102 ;
break;
case V_103 :
V_9 -> V_104 = (struct V_105 * ) V_91 ;
V_91 -> V_101 = & ( (struct V_105 * )
V_91 ) -> V_101 -> V_102 ;
break;
default:
break;
}
return V_31 ;
}
static enum V_25
F_44 ( struct V_90 * V_91 )
{
T_3 V_22 ;
for ( V_22 = 0 ; V_22 < V_91 -> V_97 ; V_22 ++ ) {
if ( V_91 -> V_94 != NULL )
V_91 -> V_94 [ V_22 ] = V_91 -> V_95 [ V_22 ] ;
if ( V_91 -> V_93 != NULL )
V_91 -> V_93 [ V_22 ] = NULL ;
if ( V_91 -> V_92 != NULL )
V_91 -> V_92 [ V_22 ] = NULL ;
}
V_91 -> V_106 = V_91 -> V_97 ;
V_91 -> V_107 = V_91 -> V_97 ;
V_91 -> V_108 = 0 ;
V_91 -> V_109 = 0 ;
V_91 -> V_110 = 0 ;
return V_31 ;
}
static void F_45 ( struct V_5 * V_6 )
{
T_5 V_111 = 0 ;
F_46 ( V_6 -> V_112 , V_113 , & V_111 ) ;
V_111 |= 0x140 ;
F_47 ( V_6 -> V_112 , V_113 , V_111 ) ;
F_48 ( V_6 -> V_112 ) ;
}
static enum V_25
F_49 ( T_2 T_1 * V_114 )
{
enum V_25 V_39 ;
V_39 = F_11 ( V_114 ,
F_50 ( 0x1ffff ) ,
V_48 ) ;
return V_39 ;
}
static enum V_25
F_51 ( struct V_115 T_1 * V_116 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
V_3 = F_2 ( & V_116 -> V_117 ) ;
F_16 () ;
switch ( V_3 ) {
case V_118 :
return V_39 ;
case V_119 :
F_4 ( V_120 ,
& V_116 -> V_121 ) ;
F_4 ( V_122 ,
& V_116 -> V_123 ) ;
F_4 ( V_124 ,
& V_116 -> V_125 ) ;
F_4 ( V_126 ,
& V_116 -> V_127 ) ;
break;
case V_128 :
F_4 ( V_120 ,
& V_116 -> V_121 ) ;
F_4 ( V_124 ,
& V_116 -> V_125 ) ;
break;
case V_129 :
F_4 ( V_122 ,
& V_116 -> V_123 ) ;
F_4 ( V_126 ,
& V_116 -> V_127 ) ;
break;
}
F_16 () ;
V_3 = F_2 ( & V_116 -> V_117 ) ;
if ( V_3 != V_118 )
V_39 = V_130 ;
return V_39 ;
}
static struct V_131 T_1 *
F_52 ( void T_1 * V_132 )
{
T_2 V_3 ;
struct V_131 T_1 * V_133 = NULL ;
enum V_25 V_39 ;
struct V_115 T_1 * V_116 =
(struct V_115 T_1 * ) V_132 ;
V_39 = F_51 ( V_116 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_116 -> V_134 ) ;
V_133 = (struct V_131 T_1 * ) ( V_132 + V_3 ) ;
exit:
return V_133 ;
}
static enum V_25
F_53 ( struct V_5 * V_6 )
{
T_2 V_3 ;
T_3 V_22 ;
enum V_25 V_39 = V_31 ;
V_6 -> V_116 = (struct V_115 T_1 * ) V_6 -> V_132 ;
V_6 -> V_135 = F_52 ( V_6 -> V_132 ) ;
if ( V_6 -> V_135 == NULL ) {
V_39 = V_30 ;
goto exit;
}
V_3 = F_2 ( & V_6 -> V_135 -> V_136 ) ;
V_6 -> V_137 =
(struct V_138 T_1 * ) ( V_6 -> V_132 + V_3 ) ;
V_3 = F_2 ( & V_6 -> V_135 -> V_139 ) ;
V_6 -> V_140 =
(struct V_141 T_1 * ) ( V_6 -> V_132 + V_3 ) ;
for ( V_22 = 0 ; V_22 < V_142 ; V_22 ++ ) {
V_3 = F_2 ( & V_6 -> V_135 -> V_143 [ V_22 ] ) ;
V_6 -> V_144 [ V_22 ] =
(struct V_145 T_1 * )
( V_6 -> V_132 + V_3 ) ;
}
for ( V_22 = 0 ; V_22 < V_146 ; V_22 ++ ) {
V_3 = F_2 ( & V_6 -> V_135 -> V_147 [ V_22 ] ) ;
V_6 -> V_148 [ V_22 ] =
(struct V_149 T_1 * ) ( V_6 -> V_132 + V_3 ) ;
}
for ( V_22 = 0 ; V_22 < V_150 ; V_22 ++ ) {
V_3 = F_2 ( & V_6 -> V_135 -> V_151 [ V_22 ] ) ;
V_6 -> V_152 [ V_22 ] =
(struct V_1 T_1 * )
( V_6 -> V_132 + V_3 ) ;
}
V_3 = F_2 ( & V_6 -> V_135 -> V_153 ) ;
switch ( F_54 ( V_3 ) ) {
case 0 :
V_6 -> V_154 = ( T_4 T_1 * ) ( V_6 -> V_132 +
F_55 ( V_3 ) ) ;
break;
default:
break;
}
V_39 = F_49 (
( T_2 T_1 * ) & V_6 -> V_137 -> V_114 ) ;
exit:
return V_39 ;
}
static T_3
F_56 ( T_3 V_155 , T_3 V_156 )
{
T_3 V_157 = V_158 ;
switch ( V_155 ) {
case V_159 :
if ( V_156 == 0 ) {
V_157 |= V_160 |
V_161 ;
}
break;
case V_162 :
V_157 |= V_160 |
V_161 ;
break;
case V_163 :
V_157 |= V_160 |
V_161 ;
break;
case V_164 :
case V_165 :
case V_166 :
break;
case V_167 :
case V_168 :
V_157 |= V_161 ;
break;
}
return V_157 ;
}
enum V_25
F_57 ( T_3 V_155 , T_3 V_156 )
{
if ( F_56 ( V_155 ,
V_156 ) &
V_160 )
return V_31 ;
else
return V_169 ;
}
static T_3
F_58 ( struct V_149 T_1 * V_148 )
{
T_2 V_3 ;
V_3 = F_2 ( & V_148 -> V_170 ) ;
return
( T_3 ) F_59 ( V_3 ) ;
}
static void F_60 ( struct V_5 * V_6 )
{
T_2 V_3 ;
T_3 V_22 ;
V_3 = F_2 ( & V_6 -> V_137 -> V_171 ) ;
V_6 -> V_155 =
( T_3 ) F_61 ( V_3 ) ;
V_6 -> V_172 = F_2 ( & V_6 -> V_137 -> V_172 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_172 & F_10 ( V_22 ) ) )
continue;
V_6 -> V_156 =
F_58 ( V_6 -> V_148 [ V_22 ] ) ;
V_6 -> V_157 = F_56 (
V_6 -> V_155 , V_6 -> V_156 ) ;
V_6 -> V_14 [ V_22 ] . V_43 = V_173 ;
V_6 -> V_14 [ V_22 ] . V_2 = V_6 -> V_152 [ V_22 ] ;
V_6 -> V_54 = V_22 ;
break;
}
}
static enum V_25
F_62 ( struct V_5 * V_6 )
{
int V_174 ;
T_5 V_175 ;
V_174 = F_63 ( V_6 -> V_112 , V_176 ) ;
F_46 ( V_6 -> V_112 , V_174 + V_177 , & V_175 ) ;
if ( ( V_175 & V_178 ) != 1 )
return V_179 ;
switch ( ( V_175 & V_180 ) >> 4 ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
break;
default:
return V_179 ;
}
return V_31 ;
}
static enum V_25
F_64 ( struct V_5 * V_6 )
{
enum V_25 V_39 = V_31 ;
if ( V_31 == F_57 ( V_6 -> V_155 ,
V_6 -> V_156 ) ) {
V_39 = F_62 ( V_6 ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
static enum V_25
F_65 ( struct V_8 * V_9 ,
struct V_186 * V_187 )
{
struct V_188 * V_189 = & V_187 -> V_189 ;
struct V_190 * V_191 = & V_187 -> V_191 ;
struct V_188 * V_192 = & V_187 -> V_192 ;
struct V_190 * V_193 = & V_187 -> V_193 ;
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
V_39 = F_18 ( V_9 ,
V_194 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
goto exit;
V_191 -> V_195 =
( T_3 ) F_66 ( V_36 ) ;
V_191 -> V_196 =
( T_3 ) F_67 ( V_36 ) ;
V_191 -> V_197 =
( T_3 ) F_68 ( V_36 ) ;
snprintf ( V_191 -> V_198 , V_199 , L_13 ,
V_191 -> V_196 , V_191 -> V_195 , V_191 -> V_197 ) ;
V_189 -> V_51 =
( T_3 ) F_26 ( V_36 ) ;
V_189 -> V_52 =
( T_3 ) F_27 ( V_36 ) ;
V_189 -> V_53 =
( T_3 ) F_28 ( V_36 ) ;
snprintf ( V_189 -> V_89 , V_199 , L_14 ,
V_189 -> V_51 , V_189 -> V_52 , V_189 -> V_53 ) ;
V_193 -> V_195 =
( T_3 ) F_69 ( V_37 ) ;
V_193 -> V_196 =
( T_3 ) F_70 ( V_37 ) ;
V_193 -> V_197 =
( T_3 ) F_71 ( V_37 ) ;
snprintf ( V_193 -> V_198 , V_199 , L_13 ,
V_193 -> V_196 , V_193 -> V_195 , V_193 -> V_197 ) ;
V_192 -> V_51 =
( T_3 ) F_72 ( V_37 ) ;
V_192 -> V_52 =
( T_3 ) F_73 ( V_37 ) ;
V_192 -> V_53 =
( T_3 ) F_74 ( V_37 ) ;
snprintf ( V_192 -> V_89 , V_199 , L_14 ,
V_192 -> V_51 , V_192 -> V_52 ,
V_192 -> V_53 ) ;
exit:
return V_39 ;
}
static enum V_25
F_75 ( struct V_8 * V_9 ,
struct V_186 * V_187 )
{
enum V_25 V_39 ;
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
T_4 * V_200 = V_187 -> V_200 ;
T_4 * V_201 = V_187 -> V_201 ;
T_4 * V_202 = V_187 -> V_202 ;
T_3 V_22 , V_203 = 0 ;
V_36 = V_204 ;
V_39 = F_18 ( V_9 ,
V_205 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
( ( T_2 * ) V_200 ) [ 0 ] = F_76 ( V_36 ) ;
( ( T_2 * ) V_200 ) [ 1 ] = F_76 ( V_37 ) ;
V_36 = V_206 ;
V_37 = V_38 = 0 ;
V_39 = F_18 ( V_9 ,
V_205 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
( ( T_2 * ) V_201 ) [ 0 ] = F_76 ( V_36 ) ;
( ( T_2 * ) V_201 ) [ 1 ] = F_76 ( V_37 ) ;
for ( V_22 = V_207 ;
V_22 <= V_208 ; V_22 ++ ) {
V_36 = V_22 ;
V_37 = V_38 = 0 ;
V_39 = F_18 ( V_9 ,
V_205 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
( ( T_2 * ) V_202 ) [ V_203 ++ ] = F_76 ( V_36 ) ;
( ( T_2 * ) V_202 ) [ V_203 ++ ] = F_76 ( V_37 ) ;
}
return V_39 ;
}
static enum V_25
F_77 ( struct V_8 * V_9 ,
struct V_186 * V_187 )
{
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
V_36 = 0 ;
V_39 = F_18 ( V_9 ,
V_209 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
V_187 -> V_210 = F_78 ( V_36 ) ;
return V_39 ;
}
static enum V_25
F_79 ( struct V_8 * V_9 ,
T_4 * V_211 , T_4 * V_212 )
{
T_2 V_33 = V_213 ,
V_36 = 0 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
int V_22 ;
do {
V_39 = F_18 ( V_9 , V_33 ,
V_214 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
goto exit;
V_36 = F_80 ( V_36 ) ;
V_37 = F_81 (
V_37 ) ;
for ( V_22 = V_215 ; V_22 > 0 ; V_22 -- ) {
V_211 [ V_22 - 1 ] = ( T_4 ) ( V_36 & 0xFF ) ;
V_36 >>= 8 ;
V_212 [ V_22 - 1 ] = ( T_4 ) ( V_37 & 0xFF ) ;
V_37 >>= 8 ;
}
V_33 = V_216 ;
V_36 = 0 , V_37 = 0 , V_38 = 0 ;
} while ( ! F_82 ( V_211 ) );
exit:
return V_39 ;
}
enum V_25 T_6
F_83 ( void T_1 * V_132 ,
struct V_186 * V_187 )
{
T_3 V_22 ;
T_2 V_3 ;
struct V_131 T_1 * V_133 ;
struct V_141 T_1 * V_140 ;
struct V_138 T_1 * V_137 ;
struct V_149 T_1 * V_148 ;
enum V_25 V_39 ;
struct V_8 V_9 ;
memset ( V_187 , 0 , sizeof( struct V_186 ) ) ;
V_133 = F_52 ( V_132 ) ;
if ( V_133 == NULL ) {
V_39 = V_217 ;
goto exit;
}
V_3 = F_2 ( & V_133 -> V_136 ) ;
V_137 = (struct V_138 T_1 * ) ( V_132 + V_3 ) ;
V_39 = F_49 (
( T_2 T_1 * ) & V_137 -> V_114 ) ;
if ( V_39 != V_31 )
goto exit;
V_187 -> V_218 = F_2 ( & V_137 -> V_172 ) ;
V_3 = F_2 ( & V_137 -> V_171 ) ;
V_187 -> V_155 =
( T_3 ) F_61 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_187 -> V_218 ) & F_10 ( V_22 ) ) )
continue;
V_3 = F_2 ( & V_133 -> V_147 [ V_22 ] ) ;
V_148 = (struct V_149 T_1 * )
( V_132 + V_3 ) ;
V_187 -> V_156 = F_58 ( V_148 ) ;
if ( F_56 ( V_187 -> V_155 ,
V_187 -> V_156 ) &
V_160 ) {
V_3 = F_2 ( & V_133 -> V_139 ) ;
V_140 = (struct V_141 T_1 * )
( V_132 + V_3 ) ;
F_4 ( 0 , & V_140 -> V_219 ) ;
F_16 () ;
}
V_3 = F_2 ( & V_133 -> V_151 [ V_22 ] ) ;
F_84 ( & V_9 . V_42 ) ;
V_9 . V_2 = (struct V_1 T_1 * )
( V_132 + V_3 ) ;
V_9 . V_43 = V_173 ;
V_39 = F_77 ( & V_9 , V_187 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_65 ( & V_9 , V_187 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_75 ( & V_9 , V_187 ) ;
if ( V_39 != V_31 )
goto exit;
break;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_187 -> V_218 ) & F_10 ( V_22 ) ) )
continue;
V_3 = F_2 ( & V_133 -> V_151 [ V_22 ] ) ;
V_9 . V_2 = (struct V_1 T_1 * )
( V_132 + V_3 ) ;
V_9 . V_43 = V_173 ;
V_39 = F_79 ( & V_9 ,
V_187 -> V_220 [ V_22 ] ,
V_187 -> V_221 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
static void F_85 ( struct V_222 * V_223 )
{
struct V_5 * V_6 ;
struct V_224 * V_225 , * V_226 ;
T_5 V_29 ;
if ( V_223 == NULL ) {
V_29 = 1 ;
goto exit;
}
V_6 = V_223 -> V_6 ;
F_86 (p, n, &blockpool->free_block_list) {
F_87 ( V_6 -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_228 ,
( (struct V_227 * ) V_225 ) -> V_97 ,
V_229 ) ;
F_88 ( V_6 -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_230 ,
& ( (struct V_227 * ) V_225 ) -> V_231 ) ;
F_89 ( & ( (struct V_227 * ) V_225 ) -> V_232 ) ;
F_42 ( V_225 ) ;
V_223 -> V_233 -- ;
}
F_86 (p, n, &blockpool->free_entry_list) {
F_89 ( & ( (struct V_227 * ) V_225 ) -> V_232 ) ;
F_42 ( ( void * ) V_225 ) ;
}
V_29 = 0 ;
exit:
return;
}
static enum V_25
F_90 ( struct V_5 * V_6 ,
struct V_222 * V_223 ,
T_3 V_233 ,
T_3 V_234 )
{
T_3 V_22 ;
struct V_227 * V_235 = NULL ;
void * V_230 ;
T_7 V_228 ;
struct V_236 * V_237 ;
struct V_236 * V_231 ;
enum V_25 V_39 = V_31 ;
if ( V_223 == NULL ) {
V_39 = V_30 ;
goto V_238;
}
V_223 -> V_6 = V_6 ;
V_223 -> V_239 = V_240 ;
V_223 -> V_233 = 0 ;
V_223 -> V_234 = V_234 ;
V_223 -> V_241 = 0 ;
F_91 ( & V_223 -> V_242 ) ;
F_91 ( & V_223 -> V_243 ) ;
for ( V_22 = 0 ; V_22 < V_233 + V_234 ; V_22 ++ ) {
V_235 = F_92 ( sizeof( struct V_227 ) ,
V_244 ) ;
if ( V_235 == NULL ) {
F_85 ( V_223 ) ;
V_39 = V_245 ;
goto V_238;
}
F_93 ( & V_235 -> V_232 , & V_223 -> V_243 ) ;
}
for ( V_22 = 0 ; V_22 < V_233 ; V_22 ++ ) {
V_230 = F_94 (
V_6 -> V_112 ,
V_240 ,
& V_237 ,
& V_231 ) ;
if ( V_230 == NULL ) {
F_85 ( V_223 ) ;
V_39 = V_245 ;
goto V_238;
}
V_228 = F_95 ( V_6 -> V_112 , V_230 ,
V_240 , V_229 ) ;
if ( F_96 ( F_97 ( V_6 -> V_112 ,
V_228 ) ) ) {
F_88 ( V_6 -> V_112 , V_230 , & V_231 ) ;
F_85 ( V_223 ) ;
V_39 = V_245 ;
goto V_238;
}
if ( ! F_98 ( & V_223 -> V_243 ) )
V_235 = (struct V_227 * )
F_99 ( & V_223 -> V_243 ,
struct V_227 ,
V_232 ) ;
if ( V_235 == NULL )
V_235 =
F_92 ( sizeof( struct V_227 ) ,
V_244 ) ;
if ( V_235 != NULL ) {
F_89 ( & V_235 -> V_232 ) ;
V_235 -> V_97 = V_240 ;
V_235 -> V_230 = V_230 ;
V_235 -> V_228 = V_228 ;
V_235 -> V_231 = V_231 ;
V_235 -> V_237 = V_237 ;
F_93 ( & V_235 -> V_232 ,
& V_223 -> V_242 ) ;
V_223 -> V_233 ++ ;
} else {
F_85 ( V_223 ) ;
V_39 = V_245 ;
goto V_238;
}
}
V_238:
return V_39 ;
}
static enum V_25
F_100 ( struct V_246 * V_247 )
{
if ( ( V_247 -> V_248 < V_249 ) ||
( V_247 -> V_248 > V_250 ) )
return V_251 ;
return V_31 ;
}
static enum V_25
F_101 ( struct V_252 * V_253 )
{
enum V_25 V_39 ;
if ( ( V_253 -> V_254 < V_255 ) ||
( V_253 -> V_254 > V_256 ) )
return V_257 ;
V_39 = F_100 ( & V_253 -> V_258 ) ;
if ( V_39 != V_31 )
return V_39 ;
if ( ( V_253 -> V_259 != V_260 ) &&
( ( V_253 -> V_259 < V_261 ) ||
( V_253 -> V_259 > V_262 ) ) )
return V_263 ;
if ( ( V_253 -> V_264 !=
V_265 ) &&
( V_253 -> V_264 !=
V_266 ) &&
( V_253 -> V_264 !=
V_267 ) )
return V_268 ;
return V_31 ;
}
static enum V_25
F_102 ( struct V_269 * V_270 )
{
T_3 V_22 ;
enum V_25 V_39 ;
if ( ( V_270 -> V_271 != V_272 ) &&
( V_270 -> V_271 != V_273 ) &&
( V_270 -> V_271 != V_274 ) &&
( V_270 -> V_271 != V_275 ) )
return V_276 ;
if ( ( V_270 -> V_277 != V_278 ) &&
( V_270 -> V_277 != V_279 ) )
return V_280 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_39 = F_101 (
& V_270 -> V_253 [ V_22 ] ) ;
if ( V_39 != V_31 )
return V_39 ;
}
return V_31 ;
}
enum V_25 T_6
F_103 (
struct V_5 * * V_281 ,
struct V_282 * V_283 ,
struct V_269 * V_284 )
{
T_3 V_22 ;
T_3 V_285 = 0 ;
struct V_5 * V_6 = NULL ;
enum V_25 V_39 = V_31 ;
V_39 = F_102 ( V_284 ) ;
if ( V_39 != V_31 )
goto exit;
V_6 = F_104 ( sizeof( struct V_5 ) ) ;
if ( V_6 == NULL ) {
V_39 = V_245 ;
goto exit;
}
V_6 -> V_286 = V_287 ;
F_105 ( V_6 , V_59 , V_288 ) ;
memcpy ( & V_6 -> V_289 , V_284 ,
sizeof( struct V_269 ) ) ;
V_6 -> V_132 = V_283 -> V_132 ;
V_6 -> V_112 = V_283 -> V_112 ;
V_6 -> V_290 . V_291 = V_283 -> V_290 . V_291 ;
V_6 -> V_290 . V_292 = V_283 -> V_290 . V_292 ;
V_6 -> V_290 . V_293 = V_283 -> V_290 . V_293 ;
F_45 ( V_6 ) ;
V_39 = F_53 ( V_6 ) ;
if ( V_39 != V_31 ) {
F_106 ( V_6 ) ;
goto exit;
}
F_60 ( V_6 ) ;
V_285 ++ ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_172 & F_10 ( V_22 ) ) )
continue;
if ( V_284 -> V_253 [ V_22 ] . V_294 . V_295 ==
V_296 )
V_285 += V_284 -> V_253 [ V_22 ] . V_294 . V_297 ;
if ( V_284 -> V_253 [ V_22 ] . V_258 . V_295 ==
V_298 )
V_285 += V_284 -> V_253 [ V_22 ] . V_258 . V_248 ;
V_285 ++ ;
}
if ( F_90 ( V_6 ,
& V_6 -> V_299 ,
V_284 -> V_300 + V_285 ,
V_284 -> V_301 + V_285 ) != V_31 ) {
F_107 ( V_6 ) ;
V_39 = V_245 ;
goto exit;
}
V_39 = F_64 ( V_6 ) ;
if ( V_39 != V_31 ) {
F_107 ( V_6 ) ;
goto exit;
}
* V_281 = V_6 ;
exit:
return V_39 ;
}
void
F_107 ( struct V_5 * V_6 )
{
F_108 ( V_6 -> V_286 == V_287 ) ;
V_6 -> V_286 = V_302 ;
F_85 ( & V_6 -> V_299 ) ;
F_106 ( V_6 ) ;
}
static enum V_25
F_109 ( struct V_8 * V_9 ,
T_3 V_303 , T_3 V_35 , T_2 * V_304 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_1 T_1 * V_2 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto V_306;
}
V_2 = V_9 -> V_2 ;
V_3 = F_110 ( V_303 ) |
V_307 |
F_111 ( V_35 ) ;
V_39 = F_13 ( V_3 ,
& V_2 -> V_308 ,
V_307 ,
V_9 -> V_6 -> V_289 . V_309 ) ;
if ( ( V_39 == V_31 ) && ( V_303 == V_310 ) )
* V_304 = F_2 ( & V_2 -> V_311 ) ;
else
* V_304 = 0 ;
V_306:
return V_39 ;
}
static enum V_25
F_112 ( struct V_8 * V_9 ,
struct V_312 * V_313 )
{
T_2 * V_3 ;
int V_22 ;
T_3 V_35 = V_314 ;
enum V_25 V_39 = V_31 ;
V_3 = ( T_2 * ) V_313 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto exit;
}
for ( V_22 = 0 ; V_22 < sizeof( struct V_312 ) / 8 ; V_22 ++ ) {
V_39 = F_109 ( V_9 ,
V_310 ,
V_35 , V_3 ) ;
if ( V_39 != V_31 )
goto exit;
V_35 ++ ;
V_3 ++ ;
}
exit:
return V_39 ;
}
static enum V_25
F_113 ( struct V_8 * V_9 ,
struct V_315 * V_316 )
{
T_2 * V_3 ;
enum V_25 V_39 = V_31 ;
int V_22 ;
T_3 V_35 = V_317 ;
V_3 = ( T_2 * ) V_316 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto exit;
}
for ( V_22 = 0 ; V_22 < sizeof( struct V_315 ) / 8 ; V_22 ++ ) {
V_39 = F_109 ( V_9 ,
V_310 ,
V_35 >> 3 , V_3 ) ;
if ( V_39 != V_31 )
goto exit;
V_35 += 8 ;
V_3 ++ ;
}
exit:
return V_39 ;
}
static enum V_25
F_114 ( struct V_8 * V_9 ,
struct V_318 * V_319 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_1 T_1 * V_2 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto exit;
}
V_2 = V_9 -> V_2 ;
V_3 = F_2 ( & V_2 -> V_320 ) ;
V_319 -> V_321 =
( T_3 ) F_115 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_322 ) ;
V_319 -> V_323 =
( T_3 ) F_116 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_324 ) ;
V_319 -> V_325 =
( T_3 ) F_117 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_326 ) ;
V_319 -> V_327 =
F_118 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_328 ) ;
V_319 -> V_329 =
F_119 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_330 ) ;
V_319 -> V_331 =
( T_3 ) F_120 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_332 ) ;
V_319 -> V_333 =
( T_3 ) F_121 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_334 ) ;
V_319 -> V_335 =
( T_3 ) F_122 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_334 ) ;
V_319 -> V_336 =
( T_3 ) F_123 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_337 ) ;
V_319 -> V_338 =
( T_3 ) F_124 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_334 ) ;
V_319 -> V_339 =
( T_3 ) F_125 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_340 ) ;
V_319 -> V_340 =
( T_3 ) F_126 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_341 ) ;
V_319 -> V_341 =
( T_3 ) F_127 (
V_3 ) ;
V_39 = F_112 ( V_9 , & V_319 -> V_342 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_113 ( V_9 , & V_319 -> V_343 ) ;
if ( V_39 != V_31 )
goto exit;
F_128 (
V_344 ) ;
V_319 -> V_345 =
( T_3 ) F_129 ( V_3 ) ;
V_319 -> V_346 =
( T_3 ) F_130 ( V_3 ) ;
F_128 (
V_347 ) ;
V_319 -> V_348 =
( T_3 ) F_131 ( V_3 ) ;
V_319 -> V_349 =
( T_3 ) F_132 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_350 ) ;
V_319 -> V_351 =
( T_5 ) F_133 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_352 ) ;
V_319 -> V_352 =
( T_3 ) F_134 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_353 ) ;
V_319 -> V_353 =
( T_5 ) F_135 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_354 ) ;
V_319 -> V_355 =
( T_5 ) F_136 ( V_3 ) ;
V_319 -> V_356 =
( T_5 ) F_137 ( V_3 ) ;
V_319 -> V_357 =
( T_5 ) F_138 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_358 ) ;
V_319 -> V_359 =
( T_5 ) F_139 ( V_3 ) ;
V_319 -> V_360 =
( T_5 ) F_140 ( V_3 ) ;
V_319 -> V_361 =
( T_5 ) F_141 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_362 ) ;
V_319 -> V_362 =
( T_5 ) F_142 (
V_3 ) ;
exit:
return V_39 ;
}
enum V_25
F_143 ( struct V_5 * V_6 ,
struct V_363 * V_319 )
{
T_3 V_22 ;
enum V_25 V_39 = V_31 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) ||
( V_6 -> V_14 [ V_22 ] . V_43 ==
V_173 ) )
continue;
memcpy ( V_6 -> V_14 [ V_22 ] . V_364 ,
V_6 -> V_14 [ V_22 ] . V_319 ,
sizeof( struct V_318 ) ) ;
V_39 = F_114 (
& V_6 -> V_14 [ V_22 ] ,
V_6 -> V_14 [ V_22 ] . V_319 ) ;
}
memcpy ( V_319 , & V_6 -> V_101 . V_365 ,
sizeof( struct V_363 ) ) ;
return V_39 ;
}
enum V_25 F_144 (
struct V_5 * V_6 ,
struct V_366 * V_367 )
{
enum V_25 V_39 = V_31 ;
memcpy ( V_367 , & V_6 -> V_101 . V_368 ,
sizeof( struct V_366 ) ) ;
return V_39 ;
}
enum V_25
F_145 ( struct V_5 * V_6 ,
T_3 V_303 , T_3 V_369 , T_3 V_35 , T_2 * V_304 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
V_39 = F_57 ( V_6 -> V_155 ,
V_6 -> V_156 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_146 ( V_303 ) |
V_370 |
F_147 ( V_369 ) |
F_148 ( V_35 ) ;
V_39 = F_13 ( V_3 ,
& V_6 -> V_140 -> V_371 ,
V_370 ,
V_6 -> V_289 . V_309 ) ;
if ( ( V_39 == V_31 ) && ( V_303 == V_310 ) )
* V_304 = F_2 ( & V_6 -> V_140 -> V_372 ) ;
else
* V_304 = 0 ;
exit:
return V_39 ;
}
static enum V_25
F_149 ( struct V_5 * V_6 , T_3 V_373 ,
struct V_374 * V_375 )
{
T_2 * V_3 ;
int V_22 ;
T_3 V_35 = V_376 ;
enum V_25 V_39 = V_31 ;
V_3 = ( T_2 * ) V_375 ;
V_39 = F_57 ( V_6 -> V_155 ,
V_6 -> V_156 ) ;
if ( V_39 != V_31 )
goto exit;
for ( V_22 = 0 ; V_22 < sizeof( struct V_374 ) / 8 ; V_22 ++ ) {
V_39 = F_145 ( V_6 ,
V_310 ,
V_377 ,
( ( V_35 + ( 104 * V_373 ) ) >> 3 ) , V_3 ) ;
if ( V_39 != V_31 )
goto exit;
V_35 += 8 ;
V_3 ++ ;
}
exit:
return V_39 ;
}
static enum V_25
F_150 ( struct V_5 * V_6 , T_3 V_373 ,
struct V_378 * V_379 )
{
T_2 * V_3 ;
enum V_25 V_39 = V_31 ;
int V_22 ;
T_3 V_35 = 0x0 ;
V_3 = ( T_2 * ) V_379 ;
V_39 = F_57 ( V_6 -> V_155 ,
V_6 -> V_156 ) ;
if ( V_39 != V_31 )
goto exit;
for ( V_22 = 0 ; V_22 < sizeof( struct V_378 ) / 8 ; V_22 ++ ) {
V_39 = F_145 ( V_6 ,
V_310 ,
V_377 ,
( ( V_35 + ( 608 * V_373 ) ) >> 3 ) , V_3 ) ;
if ( V_39 != V_31 )
goto exit;
V_35 += 8 ;
V_3 ++ ;
}
exit:
return V_39 ;
}
enum V_25
F_151 ( struct V_5 * V_6 ,
struct V_380 * V_381 )
{
enum V_25 V_39 = V_31 ;
T_3 V_22 ;
V_39 = F_149 ( V_6 ,
0 , & V_381 -> V_375 [ 0 ] ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_149 ( V_6 ,
1 , & V_381 -> V_375 [ 1 ] ) ;
if ( V_39 != V_31 )
goto exit;
for ( V_22 = 0 ; V_22 <= V_382 ; V_22 ++ ) {
V_39 = F_150 ( V_6 ,
V_22 , & V_381 -> V_379 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) )
continue;
V_39 = F_112 (
& V_6 -> V_14 [ V_22 ] ,
& V_381 -> V_313 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_113 (
& V_6 -> V_14 [ V_22 ] ,
& V_381 -> V_316 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
void F_105 ( struct V_5 * V_6 ,
enum V_383 V_384 , T_3 V_27 )
{
if ( V_6 == NULL )
return;
#if F_152 ( V_385 ) || \
F_152 ( V_386 )
V_6 -> V_387 = V_27 ;
V_6 -> V_388 = V_384 ;
#endif
#if F_152 ( V_386 )
V_6 -> V_389 = V_384 & V_59 ;
#endif
#if F_152 ( V_385 )
V_6 -> V_390 = V_384 & V_391 ;
#endif
}
T_3 F_153 ( struct V_5 * V_6 )
{
#if F_152 ( V_386 )
if ( V_6 == NULL )
return V_59 ;
else
return V_6 -> V_389 ;
#else
return 0 ;
#endif
}
T_3 F_154 ( struct V_5 * V_6 )
{
#if F_152 ( V_385 )
if ( V_6 == NULL )
return V_391 ;
else
return V_6 -> V_390 ;
#else
return 0 ;
#endif
}
enum V_25 F_155 ( struct V_5 * V_6 ,
T_3 V_373 , T_3 * V_392 , T_3 * V_393 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_286 != V_287 ) ) {
V_39 = V_394 ;
goto exit;
}
if ( V_373 > V_382 ) {
V_39 = V_395 ;
goto exit;
}
if ( ! ( V_6 -> V_157 & V_160 ) ) {
V_39 = V_169 ;
goto exit;
}
V_3 = F_2 ( & V_6 -> V_140 -> V_396 [ V_373 ] ) ;
if ( V_3 & V_397 )
* V_392 = 1 ;
if ( V_3 & V_398 )
* V_393 = 1 ;
exit:
return V_39 ;
}
enum V_25 F_156 ( struct V_5 * V_6 ,
T_3 V_373 , T_3 V_392 , T_3 V_393 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_286 != V_287 ) ) {
V_39 = V_394 ;
goto exit;
}
if ( V_373 > V_382 ) {
V_39 = V_395 ;
goto exit;
}
V_39 = F_57 ( V_6 -> V_155 ,
V_6 -> V_156 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_6 -> V_140 -> V_396 [ V_373 ] ) ;
if ( V_392 )
V_3 |= V_397 ;
else
V_3 &= ~ V_397 ;
if ( V_393 )
V_3 |= V_398 ;
else
V_3 &= ~ V_398 ;
F_4 ( V_3 , & V_6 -> V_140 -> V_396 [ V_373 ] ) ;
exit:
return V_39 ;
}
T_5 F_157 ( struct V_5 * V_6 )
{
int V_399 , V_174 ;
T_5 V_175 ;
V_174 = F_63 ( V_6 -> V_112 , V_176 ) ;
F_46 ( V_6 -> V_112 , V_174 + V_177 , & V_175 ) ;
V_399 = ( V_175 & V_400 ) >> 4 ;
return V_399 ;
}
static inline T_3
F_158 ( T_4 * V_401 )
{
return ( T_3 ) * ( ( T_2 * ) ( V_401 + V_402 ) ) ;
}
static inline void
F_159 ( T_4 * V_401 , T_3 V_403 )
{
* ( ( T_2 * ) ( V_401 + V_402 ) ) = V_403 ;
}
static inline void
F_160 ( T_4 * V_401 , T_7 V_404 )
{
* ( ( T_2 * ) ( V_401 + V_405 ) ) = V_404 ;
}
static T_2 F_161 ( struct V_105 * V_294 )
{
struct V_406 * V_407 ;
V_407 = V_294 -> V_408 -> V_409 ;
F_108 ( V_407 != NULL ) ;
return V_407 -> V_32 ;
}
static T_7 F_162 ( struct V_410 * V_411 ,
void * V_232 )
{
T_3 V_403 ;
void * V_230 ;
struct V_406 * V_412 ;
T_8 V_413 ;
V_403 = F_158 ( V_232 ) ;
V_230 = V_411 -> V_414 [ V_403 ] ;
V_412 = V_411 -> V_409 + V_403 ;
V_413 = ( T_4 * ) V_232 - ( T_4 * ) V_230 ;
return V_412 -> V_32 + V_413 ;
}
static void F_163 ( struct V_410 * V_411 ,
struct V_105 * V_294 , T_3 V_415 ,
T_3 V_416 )
{
T_4 * V_417 , * V_418 ;
T_7 V_419 ;
V_418 = V_411 -> V_420 [ V_415 ] ;
F_108 ( V_418 ) ;
V_417 = V_411 -> V_420 [ V_416 ] ;
F_108 ( V_417 ) ;
V_419 = F_162 ( V_411 , V_417 ) ;
F_160 ( V_418 , V_419 ) ;
}
static void
F_164 ( struct V_410 * V_411 ,
T_3 V_421 ,
struct V_406 * V_407 ,
T_3 V_88 , T_3 V_422 )
{
T_3 V_22 ;
void * V_232 = V_411 -> V_420 [ V_88 ] ;
struct V_105 * V_294 =
(struct V_105 * ) V_411 -> V_423 ;
for ( V_22 = 0 ; V_22 < V_294 -> V_424 ; V_22 ++ ) {
void * V_425 ;
void * V_426 ;
struct V_427 * V_428 ;
T_3 V_429 = V_294 -> V_91 . V_107 -
( V_88 * V_294 -> V_424 + V_22 + 1 ) ;
T_3 V_430 ;
V_294 -> V_91 . V_94 [ V_429 ] = ( ( T_4 * ) V_232 ) +
V_22 * V_294 -> V_431 ;
V_425 = F_165 ( V_411 ,
V_421 , V_232 ,
& V_430 ) ;
V_428 = (struct V_427 * )
V_294 -> V_91 . V_94 [ V_429 ] ;
V_426 = ( ( T_4 * ) V_425 + V_294 -> V_432 * V_22 ) ;
V_428 -> V_433 = ( T_2 ) ( V_434 ) V_426 ;
}
F_159 ( V_232 , V_421 ) ;
if ( V_422 ) {
F_163 ( V_411 , V_294 , V_88 , 0 ) ;
}
if ( V_88 > 0 ) {
F_163 ( V_411 , V_294 , V_88 - 1 , V_88 ) ;
}
}
enum V_25
F_166 ( struct V_105 * V_294 )
{
void * V_435 ;
struct V_90 * V_91 ;
enum V_25 V_39 = V_31 ;
V_91 = & V_294 -> V_91 ;
while ( F_167 ( V_91 ) > 0 ) {
V_39 = F_168 ( V_294 , & V_435 ) ;
F_108 ( V_39 == V_31 ) ;
if ( V_294 -> V_436 ) {
V_39 = V_294 -> V_436 ( V_435 , V_91 -> V_423 ) ;
if ( V_39 != V_31 ) {
F_169 ( V_294 , V_435 ) ;
goto exit;
}
}
F_170 ( V_294 , V_435 ) ;
}
V_39 = V_31 ;
exit:
return V_39 ;
}
static struct V_90 *
F_171 ( struct V_437 * V_96 ,
enum V_438 type ,
T_3 V_97 , T_3 V_439 ,
void * V_423 )
{
struct V_90 * V_91 ;
struct V_5 * V_6 ;
int V_61 = 0 ;
T_3 V_7 ;
V_6 = V_96 -> V_9 -> V_6 ;
V_7 = V_96 -> V_9 -> V_7 ;
switch ( type ) {
case V_98 :
V_61 = sizeof( struct V_100 ) ;
break;
case V_103 :
V_61 = sizeof( struct V_105 ) ;
break;
default:
break;
}
V_91 = F_92 ( V_61 , V_244 ) ;
if ( V_91 == NULL )
goto V_440;
F_91 ( & V_91 -> V_232 ) ;
V_91 -> V_137 = V_6 -> V_137 ;
V_91 -> V_54 = V_6 -> V_54 ;
V_91 -> type = type ;
V_91 -> V_281 = V_6 ;
V_91 -> V_96 = V_96 ;
V_91 -> V_423 = V_423 ;
V_91 -> V_439 = V_439 ;
V_91 -> V_97 = V_97 ;
V_91 -> V_7 = V_7 ;
V_91 -> V_92 = F_92 ( sizeof( void * ) * V_97 , V_244 ) ;
if ( V_91 -> V_92 == NULL )
goto V_441;
V_91 -> V_93 = F_92 ( sizeof( void * ) * V_97 , V_244 ) ;
if ( V_91 -> V_93 == NULL )
goto V_441;
V_91 -> V_106 = V_97 ;
V_91 -> V_94 = F_92 ( sizeof( void * ) * V_97 , V_244 ) ;
if ( V_91 -> V_94 == NULL )
goto V_441;
V_91 -> V_107 = V_97 ;
V_91 -> V_108 = 0 ;
V_91 -> V_95 = F_92 ( sizeof( void * ) * V_97 , V_244 ) ;
if ( V_91 -> V_95 == NULL )
goto V_441;
return V_91 ;
V_441:
F_41 ( V_91 ) ;
V_440:
return NULL ;
}
static void F_172 ( struct V_5 * V_281 ,
void * V_442 ,
T_3 V_97 ,
struct V_236 * V_443 ,
struct V_236 * V_231 )
{
struct V_222 * V_223 ;
struct V_227 * V_235 = NULL ;
T_7 V_228 ;
enum V_25 V_39 = V_31 ;
T_3 V_241 ;
V_223 = & V_281 -> V_299 ;
if ( V_442 == NULL ) {
V_223 -> V_241 -- ;
V_39 = V_30 ;
goto exit;
}
V_228 = F_95 ( V_281 -> V_112 , V_442 , V_97 ,
V_229 ) ;
if ( F_96 ( F_97 ( V_281 -> V_112 , V_228 ) ) ) {
F_88 ( V_281 -> V_112 , V_442 , & V_231 ) ;
V_223 -> V_241 -- ;
V_39 = V_30 ;
goto exit;
}
if ( ! F_98 ( & V_223 -> V_243 ) )
V_235 = (struct V_227 * )
F_99 ( & V_223 -> V_243 ,
struct V_227 ,
V_232 ) ;
if ( V_235 == NULL )
V_235 = F_173 ( sizeof( struct V_227 ) ) ;
else
F_89 ( & V_235 -> V_232 ) ;
if ( V_235 != NULL ) {
V_235 -> V_97 = V_97 ;
V_235 -> V_230 = V_442 ;
V_235 -> V_228 = V_228 ;
V_235 -> V_231 = V_231 ;
V_235 -> V_237 = V_443 ;
F_93 ( & V_235 -> V_232 , & V_223 -> V_242 ) ;
V_223 -> V_233 ++ ;
V_39 = V_31 ;
} else
V_39 = V_245 ;
V_223 -> V_241 -- ;
V_241 = V_223 -> V_241 ;
exit:
return;
}
static inline void
F_174 ( struct V_236 * V_112 , void * V_281 , unsigned long V_61 )
{
T_9 V_444 ;
void * V_445 ;
if ( F_175 () )
V_444 = V_446 | V_447 ;
else
V_444 = V_244 | V_447 ;
V_445 = F_176 ( ( V_61 ) , V_444 ) ;
F_172 ( V_281 , V_445 , V_61 , V_112 , V_112 ) ;
}
static
void F_177 ( struct V_222 * V_223 )
{
T_3 V_448 = 0 , V_22 ;
if ( ( V_223 -> V_233 + V_223 -> V_241 ) <
V_449 ) {
V_448 = V_450 ;
V_223 -> V_241 += V_448 ;
}
for ( V_22 = 0 ; V_22 < V_448 ; V_22 ++ )
F_174 (
( (struct V_5 * ) V_223 -> V_6 ) -> V_112 ,
V_223 -> V_6 , V_240 ) ;
}
static void * F_178 ( struct V_5 * V_281 , T_3 V_61 ,
struct V_406 * V_407 )
{
struct V_227 * V_235 = NULL ;
struct V_222 * V_223 ;
void * V_230 = NULL ;
enum V_25 V_39 = V_31 ;
V_223 = & V_281 -> V_299 ;
if ( V_61 != V_223 -> V_239 ) {
V_230 = F_94 ( V_281 -> V_112 , V_61 ,
& V_407 -> V_451 ,
& V_407 -> V_231 ) ;
if ( V_230 == NULL ) {
V_39 = V_245 ;
goto exit;
}
V_407 -> V_32 = F_95 ( V_281 -> V_112 , V_230 , V_61 ,
V_229 ) ;
if ( F_96 ( F_97 ( V_281 -> V_112 ,
V_407 -> V_32 ) ) ) {
F_88 ( V_281 -> V_112 , V_230 ,
& V_407 -> V_231 ) ;
V_39 = V_245 ;
goto exit;
}
} else {
if ( ! F_98 ( & V_223 -> V_242 ) )
V_235 = (struct V_227 * )
F_99 ( & V_223 -> V_242 ,
struct V_227 ,
V_232 ) ;
if ( V_235 != NULL ) {
F_89 ( & V_235 -> V_232 ) ;
V_407 -> V_32 = V_235 -> V_228 ;
V_407 -> V_451 = V_235 -> V_237 ;
V_407 -> V_231 = V_235 -> V_231 ;
V_230 = V_235 -> V_230 ;
F_93 ( & V_235 -> V_232 ,
& V_223 -> V_243 ) ;
V_223 -> V_233 -- ;
}
if ( V_230 != NULL )
F_177 ( V_223 ) ;
}
exit:
return V_230 ;
}
static void
F_179 ( struct V_222 * V_223 )
{
struct V_224 * V_225 , * V_226 ;
F_86 (p, n, &blockpool->free_block_list) {
if ( V_223 -> V_233 < V_223 -> V_234 )
break;
F_87 (
( (struct V_5 * ) V_223 -> V_6 ) -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_228 ,
( (struct V_227 * ) V_225 ) -> V_97 ,
V_229 ) ;
F_88 (
( (struct V_5 * ) V_223 -> V_6 ) -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_230 ,
& ( (struct V_227 * ) V_225 ) -> V_231 ) ;
F_89 ( & ( (struct V_227 * ) V_225 ) -> V_232 ) ;
F_93 ( V_225 , & V_223 -> V_243 ) ;
V_223 -> V_233 -- ;
}
}
static void F_180 ( struct V_5 * V_281 ,
void * V_230 , T_3 V_61 ,
struct V_406 * V_407 )
{
struct V_227 * V_235 = NULL ;
struct V_222 * V_223 ;
enum V_25 V_39 = V_31 ;
V_223 = & V_281 -> V_299 ;
if ( V_61 != V_223 -> V_239 ) {
F_87 ( V_281 -> V_112 , V_407 -> V_32 , V_61 ,
V_229 ) ;
F_88 ( V_281 -> V_112 , V_230 , & V_407 -> V_231 ) ;
} else {
if ( ! F_98 ( & V_223 -> V_243 ) )
V_235 = (struct V_227 * )
F_99 ( & V_223 -> V_243 ,
struct V_227 ,
V_232 ) ;
if ( V_235 == NULL )
V_235 = F_173 ( sizeof(
struct V_227 ) ) ;
else
F_89 ( & V_235 -> V_232 ) ;
if ( V_235 != NULL ) {
V_235 -> V_97 = V_61 ;
V_235 -> V_230 = V_230 ;
V_235 -> V_228 = V_407 -> V_32 ;
V_235 -> V_231 = V_407 -> V_231 ;
V_235 -> V_237 = V_407 -> V_451 ;
F_93 ( & V_235 -> V_232 ,
& V_223 -> V_242 ) ;
V_223 -> V_233 ++ ;
V_39 = V_31 ;
} else
V_39 = V_245 ;
if ( V_39 == V_31 )
F_179 ( V_223 ) ;
}
}
static void F_181 ( struct V_410 * V_408 )
{
T_3 V_22 , V_203 ;
struct V_5 * V_281 = V_408 -> V_281 ;
for ( V_22 = 0 ; V_22 < V_408 -> V_452 ; V_22 ++ ) {
struct V_406 * V_407 ;
F_108 ( V_408 -> V_414 [ V_22 ] ) ;
F_108 ( V_408 -> V_409 + V_22 ) ;
V_407 = V_408 -> V_409 + V_22 ;
for ( V_203 = 0 ; V_203 < V_408 -> V_453 ; V_203 ++ ) {
T_3 V_88 = V_22 * V_408 -> V_453 + V_203 ;
if ( V_88 >= V_408 -> V_454 )
break;
}
F_106 ( V_408 -> V_455 [ V_22 ] ) ;
F_180 ( V_281 , V_408 -> V_414 [ V_22 ] ,
V_408 -> V_456 , V_407 ) ;
}
F_106 ( V_408 -> V_420 ) ;
F_106 ( V_408 -> V_409 ) ;
F_106 ( V_408 -> V_455 ) ;
F_106 ( V_408 -> V_414 ) ;
F_106 ( V_408 ) ;
}
static enum V_25
F_182 ( struct V_410 * V_408 , T_3 V_457 ,
T_3 * V_458 )
{
T_3 V_22 , V_459 = V_408 -> V_452 == 0 ? 1 : 0 ;
T_3 V_460 = V_408 -> V_453 ;
T_3 V_461 = V_408 -> V_452 ;
T_3 V_462 = V_408 -> V_452 + V_457 ;
enum V_25 V_39 = V_31 ;
* V_458 = 0 ;
if ( V_462 > V_408 -> V_463 ) {
V_39 = V_245 ;
goto exit;
}
for ( V_22 = V_461 ; V_22 < V_462 ; V_22 ++ ) {
T_3 V_203 ;
T_3 V_422 = ( ( V_462 - 1 ) == V_22 ) ;
struct V_406 * V_407 =
V_408 -> V_409 + V_22 ;
void * V_464 ;
V_408 -> V_455 [ V_22 ] =
F_104 ( V_408 -> V_465 * V_460 ) ;
if ( V_408 -> V_455 [ V_22 ] == NULL ) {
V_39 = V_245 ;
goto exit;
}
V_408 -> V_414 [ V_22 ] =
F_178 ( V_408 -> V_281 ,
V_408 -> V_456 , V_407 ) ;
if ( V_408 -> V_414 [ V_22 ] == NULL ) {
F_106 ( V_408 -> V_455 [ V_22 ] ) ;
V_39 = V_245 ;
goto exit;
}
( * V_458 ) ++ ;
V_408 -> V_452 ++ ;
memset ( V_408 -> V_414 [ V_22 ] , 0 , V_408 -> V_456 ) ;
V_464 = V_408 -> V_414 [ V_22 ] ;
for ( V_203 = 0 ; V_203 < V_460 ; V_203 ++ ) {
T_3 V_88 = V_22 * V_460 + V_203 ;
if ( V_459 && V_88 >= V_408 -> V_466 )
break;
V_408 -> V_420 [ V_88 ] =
( ( char * ) V_464 + V_203 * V_408 -> V_467 ) ;
if ( V_408 -> V_468 != NULL )
V_408 -> V_468 ( V_408 , V_22 ,
V_407 , V_88 , V_422 ) ;
V_408 -> V_454 = V_88 + 1 ;
}
if ( V_459 && V_408 -> V_454 ==
V_408 -> V_466 )
break;
}
exit:
return V_39 ;
}
static struct V_410 *
F_183 ( struct V_5 * V_281 ,
T_3 V_456 ,
T_3 V_467 ,
T_3 V_465 ,
T_3 V_466 ,
T_3 V_469 ,
struct V_470 * V_471 ,
void * V_423 )
{
enum V_25 V_39 = V_31 ;
T_3 V_472 ;
struct V_410 * V_408 = NULL ;
T_3 V_473 ;
if ( V_456 < V_467 ) {
V_39 = V_30 ;
goto exit;
}
V_408 = F_104 ( sizeof( struct V_410 ) ) ;
if ( V_408 == NULL ) {
V_39 = V_245 ;
goto exit;
}
V_408 -> V_281 = V_281 ;
V_408 -> V_456 = V_456 ;
V_408 -> V_469 = V_469 ;
V_408 -> V_466 = V_466 ;
V_408 -> V_467 = V_467 ;
V_408 -> V_465 = V_465 ;
V_408 -> V_468 = V_471 -> V_468 ;
V_408 -> V_423 = V_423 ;
V_408 -> V_452 = 0 ;
V_408 -> V_453 = V_456 / V_467 ;
V_408 -> V_463 = ( V_469 + V_408 -> V_453 - 1 ) /
V_408 -> V_453 ;
V_408 -> V_414 =
F_104 ( sizeof( void * ) * V_408 -> V_463 ) ;
if ( V_408 -> V_414 == NULL ) {
F_181 ( V_408 ) ;
V_39 = V_245 ;
V_408 = NULL ;
goto exit;
}
V_408 -> V_455 =
F_104 ( sizeof( void * ) * V_408 -> V_463 ) ;
if ( V_408 -> V_455 == NULL ) {
F_181 ( V_408 ) ;
V_39 = V_245 ;
V_408 = NULL ;
goto exit;
}
V_408 -> V_409 =
F_104 ( sizeof( struct V_406 ) *
V_408 -> V_463 ) ;
if ( V_408 -> V_409 == NULL ) {
F_181 ( V_408 ) ;
V_39 = V_245 ;
V_408 = NULL ;
goto exit;
}
V_408 -> V_420 = F_104 ( sizeof( void * ) * V_408 -> V_469 ) ;
if ( V_408 -> V_420 == NULL ) {
F_181 ( V_408 ) ;
V_39 = V_245 ;
V_408 = NULL ;
goto exit;
}
V_472 = ( V_408 -> V_466 +
V_408 -> V_453 - 1 ) /
V_408 -> V_453 ;
V_39 = F_182 ( V_408 , V_472 ,
& V_473 ) ;
if ( V_39 != V_31 ) {
F_181 ( V_408 ) ;
V_39 = V_245 ;
V_408 = NULL ;
goto exit;
}
exit:
return V_408 ;
}
static enum V_25 F_184 ( struct V_105 * V_294 )
{
void * V_474 ;
struct V_90 * V_91 ;
V_91 = & V_294 -> V_91 ;
for (; ; ) {
F_185 ( V_91 , & V_474 ) ;
if ( V_474 == NULL )
break;
F_186 ( V_91 ) ;
if ( V_294 -> V_475 )
V_294 -> V_475 ( V_474 , V_476 ,
V_91 -> V_423 ) ;
F_187 ( V_91 , V_474 ) ;
}
return V_31 ;
}
static enum V_25 F_188 ( struct V_105 * V_294 )
{
enum V_25 V_39 = V_31 ;
struct V_90 * V_91 ;
V_91 = & V_294 -> V_91 ;
F_184 ( V_294 ) ;
V_39 = F_44 ( V_91 ) ;
if ( V_39 != V_31 )
goto exit;
if ( V_294 -> V_436 ) {
V_39 = F_166 ( V_294 ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
static enum V_25
F_189 ( struct V_437 * V_477 )
{
struct V_105 * V_294 = V_477 -> V_9 -> V_104 ;
F_184 ( V_294 ) ;
if ( V_294 -> V_408 )
F_181 ( V_294 -> V_408 ) ;
V_477 -> V_9 -> V_104 = NULL ;
F_41 ( & V_294 -> V_91 ) ;
return V_31 ;
}
static enum V_25
F_190 ( struct V_437 * V_477 ,
struct V_478 * V_283 )
{
enum V_25 V_39 = V_31 ;
struct V_105 * V_294 ;
T_3 V_479 ;
struct V_480 * V_289 ;
struct V_5 * V_6 ;
T_3 V_7 ;
struct V_470 V_481 ;
if ( ( V_477 == NULL ) || ( V_283 == NULL ) ) {
V_39 = V_30 ;
goto exit;
}
V_6 = V_477 -> V_9 -> V_6 ;
V_7 = V_477 -> V_9 -> V_7 ;
V_289 = & V_6 -> V_289 . V_253 [ V_7 ] . V_294 ;
V_479 = V_289 -> V_297 *
F_191 ( V_289 -> V_482 ) ;
V_294 = (struct V_105 * ) F_171 ( V_477 ,
V_103 ,
V_479 ,
V_283 -> V_483 ,
V_283 -> V_423 ) ;
if ( V_294 == NULL ) {
V_39 = V_245 ;
goto exit;
}
V_477 -> V_9 -> V_104 = V_294 ;
V_294 -> V_7 = V_7 ;
V_294 -> V_2 = V_477 -> V_9 -> V_2 ;
V_294 -> V_137 = V_6 -> V_137 ;
V_294 -> V_101 = & V_477 -> V_9 -> V_367 -> V_484 ;
V_294 -> V_289 = V_289 ;
V_294 -> V_485 = V_283 -> V_485 ;
V_294 -> V_436 = V_283 -> V_436 ;
V_294 -> V_475 = V_283 -> V_475 ;
V_294 -> V_482 = V_289 -> V_482 ;
V_294 -> V_486 = V_477 -> V_9 -> V_486 ;
V_294 -> V_487 = V_477 -> V_9 -> V_487 ;
V_294 -> V_488 = V_289 -> V_488 ;
V_294 -> V_431 = F_192 ( V_289 -> V_482 ) ;
V_294 -> V_432 =
sizeof( struct V_489 ) + V_283 -> V_483 ;
V_294 -> V_483 = V_283 -> V_483 ;
V_294 -> V_432 =
( ( V_294 -> V_432 + V_490 - 1 ) /
V_490 ) * V_490 ;
V_294 -> V_424 =
F_191 ( V_289 -> V_482 ) ;
V_294 -> V_491 = V_294 -> V_432 * V_294 -> V_424 ;
V_481 . V_468 = F_164 ;
V_294 -> V_408 = F_183 ( V_6 ,
V_240 ,
V_240 ,
V_294 -> V_491 ,
V_294 -> V_289 -> V_297 ,
V_294 -> V_289 -> V_297 ,
& V_481 ,
V_294 ) ;
if ( V_294 -> V_408 == NULL ) {
F_189 ( V_477 ) ;
return V_245 ;
}
V_39 = F_43 ( & V_294 -> V_91 ) ;
if ( V_39 != V_31 ) {
F_189 ( V_477 ) ;
goto exit;
}
if ( V_294 -> V_436 ) {
V_39 = F_166 ( V_294 ) ;
if ( V_39 != V_31 ) {
F_189 ( V_477 ) ;
goto exit;
}
}
V_294 -> V_101 -> V_102 . V_492 = 0 ;
exit:
return V_39 ;
}
enum V_25 T_6
F_193 ( struct V_269 * V_284 )
{
T_3 V_22 ;
V_284 -> V_300 =
V_493 ;
V_284 -> V_301 = V_494 ;
V_284 -> V_271 = V_275 ;
V_284 -> V_495 = V_496 ;
V_284 -> V_497 = V_498 ;
V_284 -> V_309 = V_48 ;
V_284 -> V_277 = V_499 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_284 -> V_253 [ V_22 ] . V_7 = V_22 ;
V_284 -> V_253 [ V_22 ] . V_254 =
V_500 ;
V_284 -> V_253 [ V_22 ] . V_294 . V_295 = V_501 ;
V_284 -> V_253 [ V_22 ] . V_294 . V_297 =
V_502 ;
V_284 -> V_253 [ V_22 ] . V_294 . V_482 =
V_503 ;
V_284 -> V_253 [ V_22 ] . V_294 . V_504 =
V_505 ;
V_284 -> V_253 [ V_22 ] . V_294 . V_488 =
V_506 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_295 = V_298 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_248 =
V_249 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_507 =
V_508 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_456 =
V_509 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_510 =
V_511 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_512 =
V_513 ;
V_284 -> V_253 [ V_22 ] . V_258 . V_514 =
V_515 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_517 =
V_518 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_519 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_521 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_522 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_523 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_524 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_525 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_526 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_527 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_528 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_529 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_530 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_531 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_532 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_516 . V_533 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_517 =
V_518 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_519 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_521 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_522 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_523 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_524 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_525 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_526 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_527 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_528 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_529 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_530 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_531 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_532 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_534 . V_533 =
V_520 ;
V_284 -> V_253 [ V_22 ] . V_259 =
V_260 ;
V_284 -> V_253 [ V_22 ] . V_264 =
V_265 ;
}
return V_31 ;
}
static enum V_25
F_194 ( struct V_1 T_1 * V_152 )
{
#ifndef F_195
T_2 V_3 ;
V_3 = F_2 ( & V_152 -> V_535 ) ;
F_16 () ;
V_3 |= V_536 ;
F_4 ( V_3 , & V_152 -> V_535 ) ;
F_16 () ;
#endif
return V_31 ;
}
static enum V_25
F_196 ( struct V_115 T_1 * V_116 ,
struct V_1 T_1 * V_152 )
{
T_2 V_3 ;
V_3 = F_2 ( & V_116 -> V_125 ) ;
if ( V_3 == V_124 ) {
V_3 = F_2 ( & V_152 -> V_537 ) ;
F_16 () ;
V_3 |= V_538 |
V_539 |
V_540 ;
F_4 ( V_3 , & V_152 -> V_537 ) ;
F_16 () ;
}
return V_31 ;
}
enum V_25
F_197 ( struct V_5 * V_6 ,
enum V_541 type ,
T_3 V_88 , T_3 V_35 , T_2 * V_542 )
{
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_286 != V_287 ) ) {
V_39 = V_394 ;
goto exit;
}
switch ( type ) {
case V_543 :
if ( V_35 > sizeof( struct V_115 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_116 + V_35 ) ;
break;
case V_545 :
if ( V_35 > sizeof( struct V_131 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_135 + V_35 ) ;
break;
case V_546 :
if ( V_35 > sizeof( struct V_138 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_137 + V_35 ) ;
break;
case V_547 :
if ( ! ( V_6 -> V_157 &
V_160 ) ) {
V_39 = V_169 ;
break;
}
if ( V_35 > sizeof( struct V_141 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_140 + V_35 ) ;
break;
case V_548 :
if ( ! ( V_6 -> V_157 &
V_161 ) ) {
V_39 = V_169 ;
break;
}
if ( V_88 > V_142 - 1 ) {
V_39 = V_549 ;
break;
}
if ( V_35 > sizeof( struct V_145 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_144 [ V_88 ] +
V_35 ) ;
break;
case V_550 :
if ( ( V_88 > V_146 - 1 ) ||
( ! ( V_6 -> V_172 & F_10 ( V_88 ) ) ) ) {
V_39 = V_549 ;
break;
}
if ( V_35 > sizeof( struct V_149 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_148 [ V_88 ] +
V_35 ) ;
break;
case V_551 :
if ( ( V_88 > V_150 - 1 ) ||
( ! ( V_6 -> V_172 & F_10 ( V_88 ) ) ) ) {
V_39 = V_549 ;
break;
}
if ( V_88 > V_150 - 1 ) {
V_39 = V_549 ;
break;
}
if ( V_35 > sizeof( struct V_1 ) - 8 ) {
V_39 = V_544 ;
break;
}
* V_542 = F_2 ( ( void T_1 * ) V_6 -> V_152 [ V_88 ] +
V_35 ) ;
break;
default:
V_39 = V_552 ;
break;
}
exit:
return V_39 ;
}
enum V_25
F_198 ( struct V_5 * V_6 , T_2 V_218 )
{
struct V_149 T_1 * V_148 ;
enum V_25 V_39 = V_31 ;
int V_22 = 0 , V_203 = 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_218 ) & F_10 ( V_22 ) ) )
continue;
V_148 = V_6 -> V_148 [ V_22 ] ;
for ( V_203 = 0 ; V_203 < V_382 ; V_203 ++ ) {
if ( F_2 ( & V_148 -> V_553 [ V_203 ] )
& V_554 )
return V_30 ;
}
}
return V_39 ;
}
enum V_25
F_199 ( struct V_5 * V_6 ,
enum V_541 type ,
T_3 V_88 , T_3 V_35 , T_2 V_542 )
{
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_286 != V_287 ) ) {
V_39 = V_394 ;
goto exit;
}
switch ( type ) {
case V_543 :
if ( V_35 > sizeof( struct V_115 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_116 + V_35 ) ;
break;
case V_545 :
if ( V_35 > sizeof( struct V_131 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_135 + V_35 ) ;
break;
case V_546 :
if ( V_35 > sizeof( struct V_138 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_137 + V_35 ) ;
break;
case V_547 :
if ( ! ( V_6 -> V_157 &
V_160 ) ) {
V_39 = V_169 ;
break;
}
if ( V_35 > sizeof( struct V_141 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_140 + V_35 ) ;
break;
case V_548 :
if ( ! ( V_6 -> V_157 &
V_161 ) ) {
V_39 = V_169 ;
break;
}
if ( V_88 > V_142 - 1 ) {
V_39 = V_549 ;
break;
}
if ( V_35 > sizeof( struct V_145 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_144 [ V_88 ] +
V_35 ) ;
break;
case V_550 :
if ( ( V_88 > V_146 - 1 ) ||
( ! ( V_6 -> V_172 & F_10 ( V_88 ) ) ) ) {
V_39 = V_549 ;
break;
}
if ( V_35 > sizeof( struct V_149 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_148 [ V_88 ] +
V_35 ) ;
break;
case V_551 :
if ( ( V_88 > V_150 - 1 ) ||
( ! ( V_6 -> V_172 & F_10 ( V_88 ) ) ) ) {
V_39 = V_549 ;
break;
}
if ( V_35 > sizeof( struct V_1 ) - 8 ) {
V_39 = V_544 ;
break;
}
F_4 ( V_542 , ( void T_1 * ) V_6 -> V_152 [ V_88 ] +
V_35 ) ;
break;
default:
V_39 = V_552 ;
break;
}
exit:
return V_39 ;
}
static enum V_25 F_200 ( struct V_100 * V_258 )
{
void * V_555 ;
for (; ; ) {
F_185 ( & V_258 -> V_91 , & V_555 ) ;
if ( V_555 == NULL )
break;
F_186 ( & V_258 -> V_91 ) ;
if ( V_258 -> V_556 ) {
V_258 -> V_556 ( V_555 ,
V_557 ,
V_258 -> V_91 . V_423 ) ;
}
F_187 ( & V_258 -> V_91 , V_555 ) ;
}
return V_31 ;
}
static enum V_25 F_201 ( struct V_100 * V_258 )
{
enum V_25 V_39 = V_31 ;
F_200 ( V_258 ) ;
V_39 = F_44 ( & V_258 -> V_91 ) ;
return V_39 ;
}
static enum V_25
F_202 ( struct V_437 * V_477 )
{
struct V_100 * V_258 = V_477 -> V_9 -> V_99 ;
F_200 ( V_258 ) ;
if ( V_258 -> V_408 )
F_181 ( V_258 -> V_408 ) ;
V_477 -> V_9 -> V_99 = NULL ;
F_41 ( & V_258 -> V_91 ) ;
return V_31 ;
}
static void
F_203 (
struct V_410 * V_411 ,
T_3 V_421 , struct V_406 * V_407 ,
T_3 V_88 , T_3 V_422 )
{
T_3 V_430 ;
struct V_558 * V_559 ;
struct V_560 * V_561 =
(struct V_560 * ) V_411 -> V_420 [ V_88 ] ;
struct V_100 * V_258 =
(struct V_100 * ) V_411 -> V_423 ;
void * V_230 = V_411 -> V_414 [ V_421 ] ;
F_108 ( V_561 ) ;
V_561 -> V_433 = ( T_2 ) ( V_434 )
F_165 ( V_411 , V_421 , V_561 ,
& V_430 ) ;
V_559 = V_558 ( V_258 , V_561 ) ;
F_108 ( V_559 ) ;
V_258 -> V_91 . V_94 [ V_258 -> V_91 . V_107 - 1 - V_88 ] = V_561 ;
V_559 -> V_562 = ( char * ) V_561 - ( char * ) V_230 ;
V_559 -> V_228 = V_407 -> V_32 + V_559 -> V_562 ;
V_559 -> V_237 = V_407 -> V_451 ;
V_559 -> V_230 = V_230 ;
V_559 -> V_563 = V_561 ;
V_559 -> V_564 = NULL ;
V_559 -> V_565 = 0 ;
}
static enum V_25
F_204 ( struct V_437 * V_477 ,
struct V_566 * V_283 )
{
enum V_25 V_39 = V_31 ;
struct V_100 * V_258 ;
struct V_246 * V_289 ;
T_3 V_567 , V_568 ;
struct V_470 V_569 ;
struct V_8 * V_9 ;
if ( ( V_477 == NULL ) || ( V_283 == NULL ) ) {
V_39 = V_570 ;
goto exit;
}
V_9 = V_477 -> V_9 ;
V_289 = & V_9 -> V_6 -> V_289 . V_253 [ V_9 -> V_7 ] . V_258 ;
V_567 = V_289 -> V_507 * sizeof( struct V_560 ) ;
V_568 = V_289 -> V_456 / V_567 ;
V_258 = (struct V_100 * ) F_171 ( V_477 ,
V_98 ,
V_289 -> V_248 * V_568 ,
V_283 -> V_571 , V_283 -> V_423 ) ;
if ( V_258 == NULL ) {
V_39 = V_245 ;
goto exit;
}
V_9 -> V_99 = V_258 ;
V_258 -> V_572 = V_9 -> V_572 ;
V_258 -> V_7 = V_9 -> V_7 ;
V_258 -> V_2 = V_9 -> V_2 ;
V_258 -> V_101 = & V_9 -> V_367 -> V_573 ;
V_258 -> V_289 = V_289 ;
V_258 -> V_574 = V_575 ;
V_258 -> V_576 = V_9 -> V_576 ;
V_258 -> V_577 = V_9 -> V_577 ;
if ( V_258 -> V_289 -> V_512 )
V_258 -> V_574 = V_578 ;
V_258 -> V_514 = V_289 -> V_514 ;
V_258 -> V_579 =
sizeof( struct V_558 ) + V_283 -> V_571 ;
V_258 -> V_579 = ( ( V_258 -> V_579 + V_490 - 1 ) /
V_490 ) * V_490 ;
V_258 -> V_571 = V_283 -> V_571 ;
V_258 -> V_567 = V_567 ;
V_258 -> V_568 = V_568 ;
V_258 -> V_556 = V_283 -> V_556 ;
V_258 -> V_485 = V_283 -> V_485 ;
if ( V_258 -> V_568 == 0 ) {
F_202 ( V_477 ) ;
V_39 = V_580 ;
goto exit;
}
V_569 . V_468 = F_203 ;
V_258 -> V_408 =
F_183 ( V_9 -> V_6 ,
V_258 -> V_289 -> V_456 ,
V_258 -> V_567 ,
V_258 -> V_579 ,
( V_258 -> V_289 -> V_248 * V_258 -> V_568 ) ,
( V_258 -> V_289 -> V_248 * V_258 -> V_568 ) ,
& V_569 ,
V_258 ) ;
if ( V_258 -> V_408 == NULL ) {
F_202 ( V_477 ) ;
V_39 = V_245 ;
goto exit;
}
V_39 = F_43 ( & V_258 -> V_91 ) ;
if ( V_39 != V_31 ) {
F_202 ( V_477 ) ;
goto exit;
}
F_108 ( V_258 -> V_91 . V_107 ) ;
exit:
return V_39 ;
}
static enum V_25
F_205 ( struct V_8 * V_9 ,
T_3 V_581 , T_3 V_35 , T_3 * V_582 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
V_3 = F_206 ( V_35 ) ;
if ( V_581 )
V_3 |= V_583 ;
F_4 ( V_3 , & V_2 -> V_584 ) ;
F_16 () ;
F_4 ( V_585 ,
& V_2 -> V_586 ) ;
F_16 () ;
V_39 = F_11 (
& V_2 -> V_586 ,
V_587 , V_48 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_2 -> V_588 ) ;
if ( V_3 & V_589 ) {
V_39 = V_30 ;
* V_582 = 0 ;
} else
* V_582 = ( T_3 ) F_15 ( V_3 , 32 , 32 ) ;
exit:
return V_39 ;
}
enum V_25
F_207 ( struct V_5 * V_6 , T_2 V_590 )
{
struct V_8 * V_9 ;
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
if ( V_6 == NULL ) {
V_39 = V_394 ;
goto exit;
}
V_9 = & V_6 -> V_14 [ V_6 -> V_54 ] ;
V_36 = V_590 ;
V_39 = F_18 ( V_9 ,
V_591 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
exit:
return V_39 ;
}
enum V_25
F_208 ( struct V_437 * V_477 ,
T_3 V_33 , T_3 V_592 , T_3 V_35 ,
T_2 * V_36 , T_2 * V_37 )
{
enum V_25 V_39 ;
T_2 V_38 = 0 ;
if ( V_477 == NULL ) {
V_39 = V_570 ;
goto exit;
}
if ( ( V_592 ==
V_593 ) ||
( V_592 ==
V_594 ) ||
( V_592 ==
V_595 ) ||
( V_592 ==
V_596 ) ) {
V_38 = V_597 ;
}
V_39 = F_18 ( V_477 -> V_9 , V_33 , V_592 , V_35 ,
V_36 , V_37 , & V_38 ) ;
if ( V_39 != V_31 )
goto exit;
if ( ( V_592 != V_214 ) &&
( V_592 !=
V_594 ) )
* V_37 = 0 ;
exit:
return V_39 ;
}
enum V_25
F_209 ( struct V_437 * V_477 , T_3 V_33 ,
T_3 V_592 , T_3 V_35 , T_2 V_598 ,
T_2 V_599 )
{
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
if ( V_477 == NULL ) {
V_39 = V_570 ;
goto exit;
}
V_36 = V_598 ;
if ( ( V_592 == V_214 ) ||
( V_592 ==
V_594 ) )
V_37 = V_599 ;
V_39 = F_18 ( V_477 -> V_9 , V_33 , V_592 , V_35 ,
& V_36 , & V_37 , & V_38 ) ;
exit:
return V_39 ;
}
enum V_25 F_210 (
struct V_437 * V_477 ,
enum V_600 V_601 ,
struct V_602 * V_603 ,
T_5 V_604 )
{
T_2 V_36 , V_37 ;
enum V_25 V_39 = V_31 ;
if ( V_477 == NULL ) {
V_39 = V_570 ;
goto exit;
}
V_39 = F_208 ( V_477 ,
V_194 ,
V_605 ,
0 , & V_36 , & V_37 ) ;
if ( V_39 != V_31 )
goto exit;
V_36 &= ~ ( F_211 ( 0xf ) |
F_212 ( 0x3 ) ) ;
V_36 |= V_606 |
F_211 ( V_604 ) |
F_212 ( V_601 ) ;
if ( V_603 -> V_607 )
V_36 |= V_608 ;
if ( V_603 -> V_609 )
V_36 |= V_610 ;
if ( V_603 -> V_611 )
V_36 |= V_612 ;
if ( V_603 -> V_613 )
V_36 |= V_614 ;
if ( V_603 -> V_615 )
V_36 |=
V_616 ;
if ( V_603 -> V_617 )
V_36 |= V_618 ;
if ( F_213 ( V_36 ) )
V_36 &= ~ V_619 ;
else
V_36 |= V_619 ;
V_39 = F_209 ( V_477 ,
V_620 ,
V_605 ,
0 , V_36 , 0 ) ;
exit:
return V_39 ;
}
static void
F_214 ( T_3 V_203 , T_2 * V_36 , T_2 * V_37 ,
T_5 V_621 , T_4 * V_622 )
{
switch ( V_621 ) {
case 1 :
* V_36 = F_215 ( V_203 ) |
V_623 |
F_216 (
V_622 [ V_203 ] ) ;
case 2 :
* V_36 |=
F_217 ( V_203 ) |
V_624 |
F_218 (
V_622 [ V_203 ] ) ;
case 3 :
* V_37 = F_219 ( V_203 ) |
V_625 |
F_220 (
V_622 [ V_203 ] ) ;
case 4 :
* V_37 |=
F_221 ( V_203 ) |
V_626 |
F_222 (
V_622 [ V_203 ] ) ;
default:
return;
}
}
enum V_25 F_223 (
struct V_437 * * V_627 ,
T_3 V_628 ,
T_4 * V_629 ,
T_4 * V_622 ,
T_3 V_630 )
{
T_3 V_22 , V_203 , V_33 , V_592 ;
T_2 V_36 ;
T_2 V_37 ;
T_3 V_631 ;
enum V_25 V_39 = V_31 ;
struct V_437 * V_477 = V_627 [ 0 ] ;
if ( V_477 == NULL ) {
V_39 = V_570 ;
goto exit;
}
V_631 = ( ( ( T_3 ) 1 ) << V_630 ) ;
if ( V_477 -> V_9 -> V_6 -> V_289 . V_497
== V_632 ) {
V_33 = V_620 ;
V_592 =
V_593 ;
for ( V_203 = 0 ; V_203 < V_631 ; V_203 ++ ) {
V_37 = 0 ;
V_36 =
F_224 (
V_622 [ V_203 ] ) ;
V_39 = F_209 ( V_627 [ 0 ] ,
V_33 , V_592 , V_203 , V_36 , V_37 ) ;
if ( V_39 != V_31 )
goto exit;
}
for ( V_203 = 0 ; V_203 < V_631 ; V_203 ++ ) {
V_37 = 0 ;
V_36 =
V_633 |
F_224 (
V_622 [ V_203 ] ) ;
V_39 = F_209 (
V_627 [ V_629 [ V_622 [ V_203 ] ] ] , V_33 ,
V_592 , V_203 , V_36 , V_37 ) ;
if ( V_39 != V_31 )
goto exit;
}
} else {
V_33 = V_620 ;
V_592 =
V_594 ;
for ( V_22 = 0 ; V_22 < V_628 ; V_22 ++ ) {
for ( V_203 = 0 ; V_203 < V_631 ; ) {
V_36 = 0 ;
V_37 = 0 ;
while ( V_203 < V_631 ) {
if ( V_629 [ V_622 [ V_203 ] ] != V_22 ) {
V_203 ++ ;
continue;
}
F_214 ( V_203 ,
& V_36 , & V_37 , 1 , V_622 ) ;
V_203 ++ ;
break;
}
while ( V_203 < V_631 ) {
if ( V_629 [ V_622 [ V_203 ] ] != V_22 ) {
V_203 ++ ;
continue;
}
F_214 ( V_203 ,
& V_36 , & V_37 , 2 , V_622 ) ;
V_203 ++ ;
break;
}
while ( V_203 < V_631 ) {
if ( V_629 [ V_622 [ V_203 ] ] != V_22 ) {
V_203 ++ ;
continue;
}
F_214 ( V_203 ,
& V_36 , & V_37 , 3 , V_622 ) ;
V_203 ++ ;
break;
}
while ( V_203 < V_631 ) {
if ( V_629 [ V_622 [ V_203 ] ] != V_22 ) {
V_203 ++ ;
continue;
}
F_214 ( V_203 ,
& V_36 , & V_37 , 4 , V_622 ) ;
V_203 ++ ;
break;
}
if ( V_36 != 0 ) {
V_39 = F_209 (
V_627 [ V_22 ] ,
V_33 , V_592 ,
0 , V_36 , V_37 ) ;
if ( V_39 != V_31 )
goto exit;
}
}
}
}
exit:
return V_39 ;
}
enum V_25
F_225 ( struct V_105 * V_294 )
{
enum V_25 V_39 = V_31 ;
T_2 V_634 , V_11 ;
if ( V_294 == NULL )
return V_39 ;
V_634 = F_226 ( & V_294 -> V_2 -> V_16 ) ;
V_11 = F_2 ( & V_294 -> V_2 -> V_15 ) ;
V_11 = F_227 ( V_11 ) ;
if ( V_634 >= V_11 )
V_39 = V_30 ;
return V_39 ;
}
static enum V_25
F_228 (
struct V_5 * V_6 ,
struct V_8 * V_9 )
{
T_3 V_22 , V_259 = 0 , V_635 = 0 ;
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
for ( V_22 = 0 ; V_22 < V_382 ; V_22 ++ ) {
V_3 = F_2 ( & V_9 -> V_148 ->
V_553 [ V_22 ] ) ;
V_635 =
( T_3 )
F_229
( V_3 ) ;
if ( V_259 < V_635 )
V_259 = V_635 ;
}
V_9 -> V_636 = V_259 + V_637 ;
V_3 = F_2 ( & V_9 -> V_148 -> V_638 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_3 & F_10 ( V_22 ) )
V_9 -> V_639 = V_22 ;
}
V_3 = F_2 ( & V_9 -> V_148 -> V_640 ) ;
if ( V_3 & V_641 )
F_230 ( V_9 -> V_6 , V_642 ) ;
else
F_230 ( V_9 -> V_6 , V_643 ) ;
return V_39 ;
}
static enum V_25
F_231 ( struct V_8 * V_9 )
{
enum V_25 V_39 ;
V_39 = F_11 (
& V_9 -> V_6 -> V_137 -> V_114 ,
F_50 (
1 << ( 16 - V_9 -> V_7 ) ) ,
V_9 -> V_6 -> V_289 . V_309 ) ;
return V_39 ;
}
static enum V_25
F_232 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
V_3 = F_233 ( 1 << ( 16 - V_7 ) ) ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) ,
& V_6 -> V_137 -> V_644 ) ;
return V_39 ;
}
static enum V_25
F_234 ( struct V_5 * V_6 , T_3 V_7 )
{
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) & V_6 -> V_14 [ V_7 ] ;
if ( V_9 -> V_104 ) {
V_39 = F_188 ( V_9 -> V_104 ) ;
if ( V_39 != V_31 )
goto exit;
}
if ( V_9 -> V_99 )
V_39 = F_201 ( V_9 -> V_99 ) ;
exit:
return V_39 ;
}
static void
F_235 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
struct V_8 * V_9 ;
struct V_252 * V_253 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_253 = V_9 -> V_253 ;
if ( V_253 -> V_294 . V_295 == V_645 )
return;
V_3 = F_2 ( & V_2 -> V_646 ) ;
V_3 |= V_647 ;
F_4 ( V_3 , & V_2 -> V_646 ) ;
V_3 = F_2 ( & V_9 -> V_2 -> V_15 ) ;
V_3 |= V_648 ;
F_4 ( V_3 , & V_9 -> V_2 -> V_15 ) ;
V_3 = F_2 ( & V_2 -> V_649 ) ;
if ( V_9 -> V_253 -> V_294 . V_504 !=
V_505 ) {
V_3 &= ~ F_236 ( 0x3 ) ;
switch ( V_9 -> V_253 -> V_294 . V_504 ) {
case V_650 :
V_3 |= F_236 (
V_651 ) ;
break;
case V_652 :
V_3 |= F_236 (
V_653 ) ;
break;
case V_654 :
V_3 |= F_236 (
V_655 ) ;
break;
}
}
F_4 ( V_3 , & V_2 -> V_649 ) ;
F_4 ( F_237 (
F_161 (
V_9 -> V_104 ) >> 3 ) , & V_2 -> V_656 ) ;
V_3 = F_2 ( & V_2 -> V_657 ) ;
V_3 |= V_658 ;
V_3 &= ~ F_238 ( 0x3 ) ;
V_3 |= F_238 (
V_659 ) ;
if ( V_6 -> V_289 . V_495 == V_660 )
V_3 |= V_661 ;
else
V_3 &= ~ V_661 ;
F_4 ( V_3 , & V_2 -> V_657 ) ;
}
static enum V_25
F_239 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
T_2 V_662 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_39 = F_196 ( V_6 -> V_116 , V_2 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_2 -> V_663 ) ;
V_9 -> V_664 =
( T_3 ) F_240 (
V_3 + 1 ) / 2 ;
if ( V_9 -> V_253 -> V_258 . V_295 == V_298 ) {
V_9 -> V_665 = V_9 -> V_664 ;
if ( V_9 -> V_665 <
( ( V_9 -> V_253 -> V_258 . V_456 /
( V_9 -> V_253 -> V_258 . V_507 *
sizeof( struct V_560 ) ) ) *
V_9 -> V_253 -> V_258 . V_248 ) ) {
return V_251 ;
}
V_3 = F_241 (
( V_9 -> V_665 * 2 ) - 1 ) ;
}
F_4 ( V_3 , & V_2 -> V_666 ) ;
F_4 ( V_667 ,
& V_2 -> V_668 ) ;
V_3 = F_2 ( & V_2 -> V_669 ) ;
V_3 &= ~ ( F_242 ( 0x3 ) |
F_243 ( 0xFF ) ) ;
V_3 |= F_242 (
V_670 ) |
#ifndef F_195
V_671 |
#endif
F_243 ( 0 ) ;
F_4 ( V_3 , & V_2 -> V_669 ) ;
F_4 ( ( T_2 ) 0 , & V_2 -> V_672 ) ;
F_16 () ;
V_662 = F_2 ( & V_6 -> V_135 -> V_673 ) ;
V_9 -> V_572 =
(struct V_674 T_1 * )
( V_6 -> V_154 + ( V_7 *
F_244 (
V_662 ) ) ) ;
exit:
return V_39 ;
}
static enum V_25
F_245 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_252 * V_253 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_253 = V_9 -> V_253 ;
F_4 ( F_246 (
V_9 -> V_639 ) , & V_2 -> V_675 ) ;
if ( V_253 -> V_294 . V_295 == V_296 ) {
V_3 = F_2 ( & V_2 -> V_676 ) ;
if ( V_253 -> V_264 !=
V_265 ) {
if ( V_253 -> V_264 )
V_3 |= V_677 ;
else
V_3 &= ~ V_677 ;
}
F_4 ( V_3 , & V_2 -> V_676 ) ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_253 -> V_259 !=
V_260 ) {
V_3 &= ~ F_3 ( 0x3fff ) ;
if ( ( V_253 -> V_259 +
V_637 ) < V_9 -> V_636 )
V_3 |= F_3 (
V_253 -> V_259 +
V_637 ) ;
else
V_3 |= F_3 (
V_9 -> V_636 ) ;
}
F_4 ( V_3 , & V_2 -> V_4 ) ;
V_3 = F_2 ( & V_2 -> V_678 ) ;
V_3 &= ~ ( F_247 ( 0x3 ) |
V_679 ) ;
if ( V_6 -> V_289 . V_497 ==
V_680 ) {
V_3 |= F_247 (
0x2 ) |
V_679 ;
}
F_4 ( V_3 , & V_2 -> V_678 ) ;
}
return V_39 ;
}
static enum V_25
F_248 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
struct V_252 * V_289 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_289 = V_9 -> V_253 ;
F_4 ( 0 , & V_2 -> V_681 ) ;
F_4 ( 0 , & V_2 -> V_682 ) ;
F_4 ( 0 , & V_2 -> V_683 ) ;
F_4 ( 0 , & V_2 -> V_684 ) ;
if ( V_289 -> V_294 . V_295 == V_296 )
F_4 ( F_249 (
( V_7 * V_685 ) +
V_686 ) , & V_2 -> V_687 ) ;
V_3 = F_2 ( & V_2 -> V_688 ) ;
V_3 |= V_689 ;
F_4 ( V_3 , & V_2 -> V_688 ) ;
if ( V_289 -> V_258 . V_295 == V_298 ) {
V_3 = F_2 ( & V_2 -> V_690 [ V_691 ] ) ;
if ( V_289 -> V_516 . V_519 != V_520 ) {
V_3 &= ~ F_250 (
0x3ffffff ) ;
V_3 |= F_250 (
V_289 -> V_516 . V_519 ) ;
}
V_3 &= ~ V_692 ;
if ( V_289 -> V_516 . V_521 != V_520 ) {
if ( V_289 -> V_516 . V_521 )
V_3 |= V_693 ;
else
V_3 &= ~ V_693 ;
}
if ( V_289 -> V_516 . V_522 != V_520 ) {
if ( V_289 -> V_516 . V_522 )
V_3 |= V_694 ;
else
V_3 &= ~ V_694 ;
}
if ( V_289 -> V_516 . V_527 != V_520 ) {
V_3 &= ~ F_251 ( 0x3f ) ;
V_3 |= F_251 (
V_289 -> V_516 . V_527 ) ;
}
if ( V_289 -> V_516 . V_529 != V_520 ) {
V_3 &= ~ F_252 ( 0x3f ) ;
V_3 |= F_252 (
V_289 -> V_516 . V_529 ) ;
}
if ( V_289 -> V_516 . V_531 != V_520 ) {
V_3 &= ~ F_253 ( 0x3f ) ;
V_3 |= F_253 (
V_289 -> V_516 . V_531 ) ;
}
F_4 ( V_3 , & V_2 -> V_690 [ V_691 ] ) ;
V_9 -> V_576 = V_3 ;
V_3 = F_2 ( & V_2 -> V_695 [ V_691 ] ) ;
if ( V_289 -> V_516 . V_528 != V_520 ) {
V_3 &= ~ F_254 ( 0xffff ) ;
V_3 |= F_254 (
V_289 -> V_516 . V_528 ) ;
}
if ( V_289 -> V_516 . V_530 != V_520 ) {
V_3 &= ~ F_255 ( 0xffff ) ;
V_3 |= F_255 (
V_289 -> V_516 . V_530 ) ;
}
if ( V_289 -> V_516 . V_532 != V_520 ) {
V_3 &= ~ F_256 ( 0xffff ) ;
V_3 |= F_256 (
V_289 -> V_516 . V_532 ) ;
}
if ( V_289 -> V_516 . V_533 != V_520 ) {
V_3 &= ~ F_257 ( 0xffff ) ;
V_3 |= F_257 (
V_289 -> V_516 . V_533 ) ;
}
F_4 ( V_3 , & V_2 -> V_695 [ V_691 ] ) ;
V_3 = F_2 ( & V_2 -> V_696 [ V_691 ] ) ;
if ( V_289 -> V_516 . V_523 != V_520 ) {
if ( V_289 -> V_516 . V_523 )
V_3 |= V_697 ;
else
V_3 &= ~ V_697 ;
}
if ( V_289 -> V_516 . V_524 != V_520 ) {
V_3 &= ~ F_258 (
0x3ffffff ) ;
V_3 |= F_258 (
V_289 -> V_516 . V_524 ) ;
}
if ( V_289 -> V_516 . V_525 != V_520 ) {
V_3 &= ~ F_259 ( 0x3f ) ;
V_3 |= F_259 ( V_7 ) ;
}
if ( V_289 -> V_516 . V_526 != V_520 ) {
V_3 &= ~ F_260 (
0x3ffffff ) ;
V_3 |= F_260 (
V_289 -> V_516 . V_526 ) ;
}
F_4 ( V_3 , & V_2 -> V_696 [ V_691 ] ) ;
V_9 -> V_577 = V_3 ;
}
if ( V_289 -> V_294 . V_295 == V_296 ) {
V_3 = F_2 ( & V_2 -> V_690 [ V_686 ] ) ;
if ( V_289 -> V_534 . V_519 != V_520 ) {
V_3 &= ~ F_250 (
0x3ffffff ) ;
V_3 |= F_250 (
V_289 -> V_534 . V_519 ) ;
}
V_3 &= ~ V_692 ;
if ( V_289 -> V_534 . V_521 != V_520 ) {
if ( V_289 -> V_534 . V_521 )
V_3 |= V_693 ;
else
V_3 &= ~ V_693 ;
}
if ( V_289 -> V_534 . V_522 != V_520 ) {
if ( V_289 -> V_534 . V_522 )
V_3 |= V_694 ;
else
V_3 &= ~ V_694 ;
}
if ( V_289 -> V_534 . V_527 != V_520 ) {
V_3 &= ~ F_251 ( 0x3f ) ;
V_3 |= F_251 (
V_289 -> V_534 . V_527 ) ;
}
if ( V_289 -> V_534 . V_529 != V_520 ) {
V_3 &= ~ F_252 ( 0x3f ) ;
V_3 |= F_252 (
V_289 -> V_534 . V_529 ) ;
}
if ( V_289 -> V_534 . V_531 != V_520 ) {
V_3 &= ~ F_253 ( 0x3f ) ;
V_3 |= F_253 (
V_289 -> V_534 . V_531 ) ;
}
F_4 ( V_3 , & V_2 -> V_690 [ V_686 ] ) ;
V_9 -> V_486 = V_3 ;
V_3 = F_2 ( & V_2 -> V_695 [ V_686 ] ) ;
if ( V_289 -> V_534 . V_528 != V_520 ) {
V_3 &= ~ F_254 ( 0xffff ) ;
V_3 |= F_254 (
V_289 -> V_534 . V_528 ) ;
}
if ( V_289 -> V_534 . V_530 != V_520 ) {
V_3 &= ~ F_255 ( 0xffff ) ;
V_3 |= F_255 (
V_289 -> V_534 . V_530 ) ;
}
if ( V_289 -> V_534 . V_532 != V_520 ) {
V_3 &= ~ F_256 ( 0xffff ) ;
V_3 |= F_256 (
V_289 -> V_534 . V_532 ) ;
}
if ( V_289 -> V_534 . V_533 != V_520 ) {
V_3 &= ~ F_257 ( 0xffff ) ;
V_3 |= F_257 (
V_289 -> V_534 . V_533 ) ;
}
F_4 ( V_3 , & V_2 -> V_695 [ V_686 ] ) ;
V_3 = F_2 ( & V_2 -> V_696 [ V_686 ] ) ;
if ( V_289 -> V_534 . V_523 != V_520 ) {
if ( V_289 -> V_534 . V_523 )
V_3 |= V_697 ;
else
V_3 &= ~ V_697 ;
}
if ( V_289 -> V_534 . V_524 != V_520 ) {
V_3 &= ~ F_258 (
0x3ffffff ) ;
V_3 |= F_258 (
V_289 -> V_534 . V_524 ) ;
}
if ( V_289 -> V_534 . V_525 != V_520 ) {
V_3 &= ~ F_259 ( 0x3f ) ;
V_3 |= F_259 ( V_7 ) ;
}
if ( V_289 -> V_534 . V_526 != V_520 ) {
V_3 &= ~ F_260 (
0x3ffffff ) ;
V_3 |= F_260 (
V_289 -> V_534 . V_526 ) ;
}
F_4 ( V_3 , & V_2 -> V_696 [ V_686 ] ) ;
V_9 -> V_487 = V_3 ;
}
V_3 = 0 ;
F_4 ( V_3 , & V_2 -> V_690 [ V_698 ] ) ;
F_4 ( V_3 , & V_2 -> V_695 [ V_698 ] ) ;
F_4 ( V_3 , & V_2 -> V_696 [ V_698 ] ) ;
F_4 ( V_3 , & V_2 -> V_690 [ V_699 ] ) ;
F_4 ( V_3 , & V_2 -> V_695 [ V_699 ] ) ;
F_4 ( V_3 , & V_2 -> V_696 [ V_699 ] ) ;
V_3 = F_261 ( 150 ) ;
V_3 |= F_262 ( 0 ) ;
V_3 |= F_263 ( 3 ) ;
F_4 ( V_3 , & V_2 -> V_700 ) ;
return V_39 ;
}
static enum V_25
F_264 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
T_3 V_701 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( ! ( V_6 -> V_172 & F_10 ( V_7 ) ) ) {
V_39 = V_702 ;
goto exit;
}
V_2 = V_9 -> V_2 ;
V_39 = F_194 ( V_9 -> V_2 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_245 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_239 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_248 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_2 -> V_703 ) ;
V_39 = F_205 ( V_9 , 1 , 0x78 , & V_701 ) ;
if ( V_39 == V_31 ) {
V_701 = ( V_701 & V_704 ) >> 12 ;
V_3 &=
~ ( F_265 ( 7 ) ) ;
V_3 |=
F_265 ( V_701 ) ;
V_3 |= V_705 ;
}
V_3 &= ~ ( F_266 ( 7 ) ) ;
V_3 |=
F_266 (
V_706 ) ;
V_3 |= V_707 ;
F_4 ( V_3 , & V_2 -> V_703 ) ;
exit:
return V_39 ;
}
static void F_267 ( struct V_5 * V_6 , T_3 V_7 )
{
struct V_8 * V_9 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( V_9 -> V_43 == V_173 )
goto exit;
F_268 ( V_9 -> V_6 -> V_708 ,
V_9 -> V_6 -> V_709 , V_9 -> V_7 ) ;
V_6 -> V_101 . V_365 . V_710 [ V_9 -> V_7 ] = NULL ;
F_19 ( & V_9 -> V_42 ) ;
V_9 -> V_43 = V_173 ;
F_20 ( & V_9 -> V_42 ) ;
V_9 -> V_148 = NULL ;
V_9 -> V_572 = NULL ;
V_9 -> V_636 = 0 ;
V_9 -> V_639 = 0 ;
V_9 -> V_664 = 0 ;
V_9 -> V_665 = 0 ;
V_9 -> V_104 = NULL ;
V_9 -> V_99 = NULL ;
memset ( & V_9 -> V_627 , 0 , sizeof( struct V_224 ) ) ;
V_9 -> V_711 = 0 ;
V_9 -> V_319 = NULL ;
V_9 -> V_364 = NULL ;
V_9 -> V_367 = NULL ;
exit:
return;
}
static enum V_25
F_269 ( struct V_5 * V_6 , T_3 V_7 ,
struct V_252 * V_289 )
{
struct V_8 * V_9 ;
enum V_25 V_39 = V_31 ;
if ( ! ( V_6 -> V_172 & F_10 ( V_7 ) ) ) {
V_39 = V_702 ;
goto exit;
}
V_9 = & V_6 -> V_14 [ V_7 ] ;
F_84 ( & V_9 -> V_42 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_43 = V_712 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_253 = V_289 ;
V_9 -> V_2 = V_6 -> V_152 [ V_7 ] ;
V_9 -> V_148 = V_6 -> V_148 [ V_7 ] ;
F_232 ( V_6 , V_7 ) ;
V_39 = F_231 ( V_9 ) ;
if ( V_39 != V_31 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
goto exit;
}
V_39 = F_228 ( V_6 , V_9 ) ;
if ( V_39 != V_31 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
goto exit;
}
F_91 ( & V_9 -> V_627 ) ;
V_9 -> V_367 = & V_6 -> V_101 . V_368 . V_710 [ V_7 ] ;
F_270 ( V_6 -> V_708 ,
V_6 -> V_709 , V_7 ) ;
V_39 = F_264 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
F_267 ( V_6 , V_7 ) ;
exit:
return V_39 ;
}
enum V_25
F_271 ( struct V_437 * V_477 , T_3 V_713 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
if ( V_477 == NULL ) {
V_39 = V_570 ;
goto exit;
}
V_9 = V_477 -> V_9 ;
V_713 += V_637 ;
if ( ( V_713 < V_714 ) || ( V_713 > V_9 -> V_636 ) )
V_39 = V_715 ;
V_3 = F_2 ( & V_9 -> V_2 -> V_4 ) ;
V_3 &= ~ F_3 ( 0x3fff ) ;
V_3 |= F_3 ( V_713 ) ;
F_4 ( V_3 , & V_9 -> V_2 -> V_4 ) ;
V_9 -> V_253 -> V_259 = V_713 - V_637 ;
exit:
return V_39 ;
}
static enum V_25
F_272 ( struct V_437 * V_477 )
{
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
V_9 = V_477 -> V_9 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto exit;
}
memcpy ( V_9 -> V_364 , V_9 -> V_319 ,
sizeof( struct V_318 ) ) ;
V_39 = F_114 ( V_9 , V_9 -> V_319 ) ;
exit:
return V_39 ;
}
static struct V_227 *
F_273 ( struct V_5 * V_281 , T_3 V_61 )
{
struct V_227 * V_235 = NULL ;
struct V_222 * V_223 ;
V_223 = & V_281 -> V_299 ;
if ( V_61 == V_223 -> V_239 ) {
if ( ! F_98 ( & V_223 -> V_242 ) )
V_235 = (struct V_227 * )
F_99 ( & V_223 -> V_242 ,
struct V_227 ,
V_232 ) ;
if ( V_235 != NULL ) {
F_89 ( & V_235 -> V_232 ) ;
V_223 -> V_233 -- ;
}
}
if ( V_235 != NULL )
F_177 ( V_223 ) ;
return V_235 ;
}
enum V_25
F_274 ( struct V_5 * V_6 ,
struct V_716 * V_283 ,
struct V_437 * * V_717 )
{
struct V_8 * V_9 ;
struct V_437 * V_477 ;
enum V_25 V_39 ;
V_9 = & V_6 -> V_14 [ V_283 -> V_7 ] ;
if ( V_9 -> V_43 == V_712 ) {
V_39 = V_718 ;
goto V_719;
}
V_39 = F_269 ( V_6 , V_283 -> V_7 ,
& V_6 -> V_289 . V_253 [ V_283 -> V_7 ] ) ;
if ( V_39 != V_31 )
goto V_719;
V_477 = F_104 ( sizeof( struct V_437 ) ) ;
if ( V_477 == NULL ) {
V_39 = V_245 ;
goto V_720;
}
V_477 -> V_9 = V_9 ;
if ( V_9 -> V_253 -> V_258 . V_295 == V_298 ) {
V_39 = F_204 ( V_477 , & V_283 -> V_721 ) ;
if ( V_39 != V_31 )
goto V_722;
}
if ( V_9 -> V_253 -> V_294 . V_295 == V_296 ) {
V_39 = F_190 ( V_477 , & V_283 -> V_723 ) ;
if ( V_39 != V_31 )
goto V_724;
F_235 ( V_6 , V_283 -> V_7 ) ;
}
V_9 -> V_99 -> V_725 =
( V_283 -> V_7 * V_685 ) +
V_691 ;
V_9 -> V_711 = F_273 ( V_6 ,
V_240 ) ;
if ( V_9 -> V_711 == NULL ) {
V_39 = V_245 ;
goto V_726;
}
V_9 -> V_319 = (struct V_318 * ) V_9 ->
V_711 -> V_230 ;
memset ( V_9 -> V_319 , 0 ,
sizeof( struct V_318 ) ) ;
V_6 -> V_101 . V_365 . V_710 [ V_283 -> V_7 ] =
V_9 -> V_319 ;
V_9 -> V_364 =
& V_6 -> V_101 . V_365 . V_727 [ V_283 -> V_7 ] ;
memset ( V_9 -> V_364 , 0 ,
sizeof( struct V_318 ) ) ;
F_4 ( V_9 -> V_711 -> V_228 , & V_9 -> V_2 -> V_728 ) ;
V_39 = F_272 ( V_477 ) ;
if ( V_39 != V_31 )
goto V_726;
F_93 ( & V_477 -> V_232 , & V_9 -> V_627 ) ;
V_6 -> V_24 |= F_10 ( V_9 -> V_7 ) ;
* V_717 = V_477 ;
V_283 -> V_721 . V_423 = V_9 -> V_99 ;
V_283 -> V_723 . V_423 = V_9 -> V_104 ;
return V_31 ;
V_726:
if ( V_9 -> V_104 != NULL )
F_189 ( V_477 ) ;
V_724:
if ( V_9 -> V_99 != NULL )
F_202 ( V_477 ) ;
V_722:
F_106 ( V_477 ) ;
V_720:
F_267 ( V_6 , V_283 -> V_7 ) ;
V_719:
return V_39 ;
}
void F_275 ( struct V_437 * V_477 )
{
struct V_8 * V_9 = V_477 -> V_9 ;
struct V_105 * V_294 = V_9 -> V_104 ;
struct V_729 * V_730 = F_276 ( V_9 -> V_6 -> V_731 ) ;
T_2 V_732 , V_3 , V_733 ;
if ( V_730 -> V_734 ) {
V_732 = F_2 ( & V_9 -> V_2 -> V_735 ) ;
V_732 &= 0x1fff ;
} else
V_732 = V_294 -> V_289 -> V_297 * V_240 / 8 ;
V_733 = F_277 ( V_732 ) ;
F_4 ( F_278 ( V_733 ) ,
& V_9 -> V_2 -> V_16 ) ;
F_226 ( & V_9 -> V_2 -> V_16 ) ;
V_733 /= 2 ;
V_3 = F_2 ( & V_9 -> V_2 -> V_15 ) ;
V_3 = F_227 ( V_3 ) ;
V_3 &= 0x1ff ;
V_732 -= ( V_3 + 1 ) ;
V_3 = F_279 ( V_733 , V_732 ) / 4 ;
V_294 -> V_488 = F_279 ( V_294 -> V_488 , V_3 ) ;
if ( V_294 -> V_488 < 4 )
V_294 -> V_488 = 4 ;
}
static void
F_280 ( struct V_5 * V_281 ,
struct V_227 * V_235 )
{
struct V_222 * V_223 ;
V_223 = & V_281 -> V_299 ;
if ( V_235 -> V_97 == V_223 -> V_239 ) {
F_93 ( & V_235 -> V_232 , & V_223 -> V_242 ) ;
V_223 -> V_233 ++ ;
}
F_179 ( V_223 ) ;
}
enum V_25 F_281 ( struct V_437 * V_477 )
{
struct V_8 * V_9 = NULL ;
struct V_5 * V_281 = NULL ;
T_3 V_7 = V_477 -> V_9 -> V_7 ;
T_3 V_736 = TRUE ;
enum V_25 V_39 = V_31 ;
V_9 = V_477 -> V_9 ;
V_281 = V_9 -> V_6 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto V_737;
}
F_89 ( & V_477 -> V_232 ) ;
if ( ! F_98 ( & V_9 -> V_627 ) ) {
F_93 ( & V_477 -> V_232 , & V_9 -> V_627 ) ;
V_736 = FALSE ;
}
if ( ! V_736 ) {
V_39 = V_30 ;
goto V_737;
}
V_281 -> V_24 &= ~ F_10 ( V_7 ) ;
if ( V_9 -> V_104 != NULL )
F_189 ( V_477 ) ;
if ( V_9 -> V_99 != NULL )
F_202 ( V_477 ) ;
if ( V_9 -> V_711 != NULL )
F_280 ( V_281 , V_9 -> V_711 ) ;
F_106 ( V_477 ) ;
F_267 ( V_281 , V_7 ) ;
V_737:
return V_39 ;
}
enum V_25 F_282 ( struct V_437 * V_477 )
{
enum V_25 V_39 ;
T_3 V_7 ;
struct V_8 * V_9 = V_477 -> V_9 ;
V_7 = V_9 -> V_7 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto exit;
}
V_39 = F_232 ( V_9 -> V_6 , V_7 ) ;
if ( V_39 == V_31 )
V_9 -> V_367 -> V_738 ++ ;
exit:
return V_39 ;
}
enum V_25
F_283 ( struct V_437 * V_477 )
{
struct V_8 * V_9 = NULL ;
enum V_25 V_39 ;
struct V_5 * V_6 ;
T_3 V_7 ;
V_7 = V_477 -> V_9 -> V_7 ;
V_9 = V_477 -> V_9 ;
V_6 = V_9 -> V_6 ;
if ( V_9 -> V_43 == V_173 ) {
V_39 = V_305 ;
goto exit;
}
V_39 = F_231 ( V_9 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_234 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_264 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
if ( V_9 -> V_104 != NULL )
F_235 ( V_6 , V_7 ) ;
memset ( V_9 -> V_319 , 0 ,
sizeof( struct V_318 ) ) ;
memset ( V_9 -> V_364 , 0 ,
sizeof( struct V_318 ) ) ;
F_4 ( V_9 -> V_711 -> V_228 ,
& V_9 -> V_2 -> V_728 ) ;
V_39 = F_272 ( V_477 ) ;
exit:
return V_39 ;
}
void
F_284 ( struct V_437 * V_477 )
{
struct V_5 * V_6 ;
T_2 V_3 ;
V_6 = V_477 -> V_9 -> V_6 ;
V_3 = F_285 (
1 << ( 16 - V_477 -> V_9 -> V_7 ) ) ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) ,
& V_6 -> V_137 -> V_739 ) ;
}
