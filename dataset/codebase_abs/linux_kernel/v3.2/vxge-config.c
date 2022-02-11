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
V_133 = V_132 + V_3 ;
exit:
return V_133 ;
}
static enum V_25
F_53 ( struct V_5 * V_6 )
{
T_2 V_3 ;
T_3 V_22 ;
enum V_25 V_39 = V_31 ;
V_6 -> V_116 = V_6 -> V_132 ;
V_6 -> V_135 = F_52 ( V_6 -> V_132 ) ;
if ( V_6 -> V_135 == NULL ) {
V_39 = V_30 ;
goto exit;
}
V_3 = F_2 ( & V_6 -> V_135 -> V_136 ) ;
V_6 -> V_137 = V_6 -> V_132 + V_3 ;
V_3 = F_2 ( & V_6 -> V_135 -> V_138 ) ;
V_6 -> V_139 = V_6 -> V_132 + V_3 ;
for ( V_22 = 0 ; V_22 < V_140 ; V_22 ++ ) {
V_3 = F_2 ( & V_6 -> V_135 -> V_141 [ V_22 ] ) ;
V_6 -> V_142 [ V_22 ] = V_6 -> V_132 + V_3 ;
}
for ( V_22 = 0 ; V_22 < V_143 ; V_22 ++ ) {
V_3 = F_2 ( & V_6 -> V_135 -> V_144 [ V_22 ] ) ;
V_6 -> V_145 [ V_22 ] = V_6 -> V_132 + V_3 ;
}
for ( V_22 = 0 ; V_22 < V_146 ; V_22 ++ ) {
V_3 = F_2 ( & V_6 -> V_135 -> V_147 [ V_22 ] ) ;
V_6 -> V_148 [ V_22 ] = V_6 -> V_132 + V_3 ;
}
V_3 = F_2 ( & V_6 -> V_135 -> V_149 ) ;
switch ( F_54 ( V_3 ) ) {
case 0 :
V_6 -> V_150 = V_6 -> V_132 + F_55 ( V_3 ) ;
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
F_56 ( T_3 V_151 , T_3 V_152 )
{
T_3 V_153 = V_154 ;
switch ( V_151 ) {
case V_155 :
if ( V_152 == 0 ) {
V_153 |= V_156 |
V_157 ;
}
break;
case V_158 :
V_153 |= V_156 |
V_157 ;
break;
case V_159 :
V_153 |= V_156 |
V_157 ;
break;
case V_160 :
case V_161 :
case V_162 :
break;
case V_163 :
case V_164 :
V_153 |= V_157 ;
break;
}
return V_153 ;
}
enum V_25
F_57 ( T_3 V_151 , T_3 V_152 )
{
if ( F_56 ( V_151 ,
V_152 ) &
V_156 )
return V_31 ;
else
return V_165 ;
}
static T_3
F_58 ( struct V_166 T_1 * V_145 )
{
T_2 V_3 ;
V_3 = F_2 ( & V_145 -> V_167 ) ;
return
( T_3 ) F_59 ( V_3 ) ;
}
static void F_60 ( struct V_5 * V_6 )
{
T_2 V_3 ;
T_3 V_22 ;
V_3 = F_2 ( & V_6 -> V_137 -> V_168 ) ;
V_6 -> V_151 =
( T_3 ) F_61 ( V_3 ) ;
V_6 -> V_169 = F_2 ( & V_6 -> V_137 -> V_169 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_169 & F_10 ( V_22 ) ) )
continue;
V_6 -> V_152 =
F_58 ( V_6 -> V_145 [ V_22 ] ) ;
V_6 -> V_153 = F_56 (
V_6 -> V_151 , V_6 -> V_152 ) ;
V_6 -> V_14 [ V_22 ] . V_43 = V_170 ;
V_6 -> V_14 [ V_22 ] . V_2 = V_6 -> V_148 [ V_22 ] ;
V_6 -> V_54 = V_22 ;
break;
}
}
static enum V_25
F_62 ( struct V_5 * V_6 )
{
struct V_171 * V_172 = V_6 -> V_112 ;
T_5 V_173 ;
F_46 ( V_172 , V_172 -> V_174 + V_175 , & V_173 ) ;
if ( ( V_173 & V_176 ) != 1 )
return V_177 ;
switch ( ( V_173 & V_178 ) >> 4 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
break;
default:
return V_177 ;
}
return V_31 ;
}
static enum V_25
F_63 ( struct V_5 * V_6 )
{
enum V_25 V_39 = V_31 ;
if ( V_31 == F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ) {
V_39 = F_62 ( V_6 ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
static enum V_25
F_64 ( struct V_8 * V_9 ,
struct V_184 * V_185 )
{
struct V_186 * V_187 = & V_185 -> V_187 ;
struct V_188 * V_189 = & V_185 -> V_189 ;
struct V_186 * V_190 = & V_185 -> V_190 ;
struct V_188 * V_191 = & V_185 -> V_191 ;
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
V_39 = F_18 ( V_9 ,
V_192 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
goto exit;
V_189 -> V_193 =
( T_3 ) F_65 ( V_36 ) ;
V_189 -> V_194 =
( T_3 ) F_66 ( V_36 ) ;
V_189 -> V_195 =
( T_3 ) F_67 ( V_36 ) ;
snprintf ( V_189 -> V_196 , V_197 , L_13 ,
V_189 -> V_194 , V_189 -> V_193 , V_189 -> V_195 ) ;
V_187 -> V_51 =
( T_3 ) F_26 ( V_36 ) ;
V_187 -> V_52 =
( T_3 ) F_27 ( V_36 ) ;
V_187 -> V_53 =
( T_3 ) F_28 ( V_36 ) ;
snprintf ( V_187 -> V_89 , V_197 , L_14 ,
V_187 -> V_51 , V_187 -> V_52 , V_187 -> V_53 ) ;
V_191 -> V_193 =
( T_3 ) F_68 ( V_37 ) ;
V_191 -> V_194 =
( T_3 ) F_69 ( V_37 ) ;
V_191 -> V_195 =
( T_3 ) F_70 ( V_37 ) ;
snprintf ( V_191 -> V_196 , V_197 , L_13 ,
V_191 -> V_194 , V_191 -> V_193 , V_191 -> V_195 ) ;
V_190 -> V_51 =
( T_3 ) F_71 ( V_37 ) ;
V_190 -> V_52 =
( T_3 ) F_72 ( V_37 ) ;
V_190 -> V_53 =
( T_3 ) F_73 ( V_37 ) ;
snprintf ( V_190 -> V_89 , V_197 , L_14 ,
V_190 -> V_51 , V_190 -> V_52 ,
V_190 -> V_53 ) ;
exit:
return V_39 ;
}
static enum V_25
F_74 ( struct V_8 * V_9 ,
struct V_184 * V_185 )
{
enum V_25 V_39 ;
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
T_4 * V_198 = V_185 -> V_198 ;
T_4 * V_199 = V_185 -> V_199 ;
T_4 * V_200 = V_185 -> V_200 ;
T_3 V_22 , V_201 = 0 ;
V_36 = V_202 ;
V_39 = F_18 ( V_9 ,
V_203 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
( ( T_2 * ) V_198 ) [ 0 ] = F_75 ( V_36 ) ;
( ( T_2 * ) V_198 ) [ 1 ] = F_75 ( V_37 ) ;
V_36 = V_204 ;
V_37 = V_38 = 0 ;
V_39 = F_18 ( V_9 ,
V_203 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
( ( T_2 * ) V_199 ) [ 0 ] = F_75 ( V_36 ) ;
( ( T_2 * ) V_199 ) [ 1 ] = F_75 ( V_37 ) ;
for ( V_22 = V_205 ;
V_22 <= V_206 ; V_22 ++ ) {
V_36 = V_22 ;
V_37 = V_38 = 0 ;
V_39 = F_18 ( V_9 ,
V_203 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
( ( T_2 * ) V_200 ) [ V_201 ++ ] = F_75 ( V_36 ) ;
( ( T_2 * ) V_200 ) [ V_201 ++ ] = F_75 ( V_37 ) ;
}
return V_39 ;
}
static enum V_25
F_76 ( struct V_8 * V_9 ,
struct V_184 * V_185 )
{
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
V_36 = 0 ;
V_39 = F_18 ( V_9 ,
V_207 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
return V_39 ;
V_185 -> V_208 = F_77 ( V_36 ) ;
return V_39 ;
}
static enum V_25
F_78 ( struct V_8 * V_9 ,
T_4 * V_209 , T_4 * V_210 )
{
T_2 V_33 = V_211 ,
V_36 = 0 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
int V_22 ;
do {
V_39 = F_18 ( V_9 , V_33 ,
V_212 ,
0 , & V_36 , & V_37 , & V_38 ) ;
if ( V_39 != V_31 )
goto exit;
V_36 = F_79 ( V_36 ) ;
V_37 = F_80 (
V_37 ) ;
for ( V_22 = V_213 ; V_22 > 0 ; V_22 -- ) {
V_209 [ V_22 - 1 ] = ( T_4 ) ( V_36 & 0xFF ) ;
V_36 >>= 8 ;
V_210 [ V_22 - 1 ] = ( T_4 ) ( V_37 & 0xFF ) ;
V_37 >>= 8 ;
}
V_33 = V_214 ;
V_36 = 0 , V_37 = 0 , V_38 = 0 ;
} while ( ! F_81 ( V_209 ) );
exit:
return V_39 ;
}
enum V_25 T_6
F_82 ( void T_1 * V_132 ,
struct V_184 * V_185 )
{
T_3 V_22 ;
T_2 V_3 ;
struct V_131 T_1 * V_133 ;
struct V_215 T_1 * V_139 ;
struct V_216 T_1 * V_137 ;
struct V_166 T_1 * V_145 ;
enum V_25 V_39 ;
struct V_8 V_9 ;
memset ( V_185 , 0 , sizeof( struct V_184 ) ) ;
V_133 = F_52 ( V_132 ) ;
if ( V_133 == NULL ) {
V_39 = V_217 ;
goto exit;
}
V_3 = F_2 ( & V_133 -> V_136 ) ;
V_137 = V_132 + V_3 ;
V_39 = F_49 (
( T_2 T_1 * ) & V_137 -> V_114 ) ;
if ( V_39 != V_31 )
goto exit;
V_185 -> V_218 = F_2 ( & V_137 -> V_169 ) ;
V_3 = F_2 ( & V_137 -> V_168 ) ;
V_185 -> V_151 =
( T_3 ) F_61 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_185 -> V_218 ) & F_10 ( V_22 ) ) )
continue;
V_3 = F_2 ( & V_133 -> V_144 [ V_22 ] ) ;
V_145 = V_132 + V_3 ;
V_185 -> V_152 = F_58 ( V_145 ) ;
if ( F_56 ( V_185 -> V_151 ,
V_185 -> V_152 ) &
V_156 ) {
V_3 = F_2 ( & V_133 -> V_138 ) ;
V_139 = V_132 + V_3 ;
F_4 ( 0 , & V_139 -> V_219 ) ;
F_16 () ;
}
V_3 = F_2 ( & V_133 -> V_147 [ V_22 ] ) ;
F_83 ( & V_9 . V_42 ) ;
V_9 . V_2 = V_132 + V_3 ;
V_9 . V_43 = V_170 ;
V_39 = F_76 ( & V_9 , V_185 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_64 ( & V_9 , V_185 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_74 ( & V_9 , V_185 ) ;
if ( V_39 != V_31 )
goto exit;
break;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_185 -> V_218 ) & F_10 ( V_22 ) ) )
continue;
V_3 = F_2 ( & V_133 -> V_147 [ V_22 ] ) ;
V_9 . V_2 = V_132 + V_3 ;
V_9 . V_43 = V_170 ;
V_39 = F_78 ( & V_9 ,
V_185 -> V_220 [ V_22 ] ,
V_185 -> V_221 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
static void F_84 ( struct V_222 * V_223 )
{
struct V_5 * V_6 ;
struct V_224 * V_225 , * V_226 ;
T_5 V_29 ;
if ( V_223 == NULL ) {
V_29 = 1 ;
goto exit;
}
V_6 = V_223 -> V_6 ;
F_85 (p, n, &blockpool->free_block_list) {
F_86 ( V_6 -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_228 ,
( (struct V_227 * ) V_225 ) -> V_97 ,
V_229 ) ;
F_87 ( V_6 -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_230 ,
& ( (struct V_227 * ) V_225 ) -> V_231 ) ;
F_88 ( & ( (struct V_227 * ) V_225 ) -> V_232 ) ;
F_42 ( V_225 ) ;
V_223 -> V_233 -- ;
}
F_85 (p, n, &blockpool->free_entry_list) {
F_88 ( & ( (struct V_227 * ) V_225 ) -> V_232 ) ;
F_42 ( ( void * ) V_225 ) ;
}
V_29 = 0 ;
exit:
return;
}
static enum V_25
F_89 ( struct V_5 * V_6 ,
struct V_222 * V_223 ,
T_3 V_233 ,
T_3 V_234 )
{
T_3 V_22 ;
struct V_227 * V_235 = NULL ;
void * V_230 ;
T_7 V_228 ;
struct V_171 * V_236 ;
struct V_171 * V_231 ;
enum V_25 V_39 = V_31 ;
if ( V_223 == NULL ) {
V_39 = V_30 ;
goto V_237;
}
V_223 -> V_6 = V_6 ;
V_223 -> V_238 = V_239 ;
V_223 -> V_233 = 0 ;
V_223 -> V_234 = V_234 ;
V_223 -> V_240 = 0 ;
F_90 ( & V_223 -> V_241 ) ;
F_90 ( & V_223 -> V_242 ) ;
for ( V_22 = 0 ; V_22 < V_233 + V_234 ; V_22 ++ ) {
V_235 = F_91 ( sizeof( struct V_227 ) ,
V_243 ) ;
if ( V_235 == NULL ) {
F_84 ( V_223 ) ;
V_39 = V_244 ;
goto V_237;
}
F_92 ( & V_235 -> V_232 , & V_223 -> V_242 ) ;
}
for ( V_22 = 0 ; V_22 < V_233 ; V_22 ++ ) {
V_230 = F_93 (
V_6 -> V_112 ,
V_239 ,
& V_236 ,
& V_231 ) ;
if ( V_230 == NULL ) {
F_84 ( V_223 ) ;
V_39 = V_244 ;
goto V_237;
}
V_228 = F_94 ( V_6 -> V_112 , V_230 ,
V_239 , V_229 ) ;
if ( F_95 ( F_96 ( V_6 -> V_112 ,
V_228 ) ) ) {
F_87 ( V_6 -> V_112 , V_230 , & V_231 ) ;
F_84 ( V_223 ) ;
V_39 = V_244 ;
goto V_237;
}
if ( ! F_97 ( & V_223 -> V_242 ) )
V_235 = (struct V_227 * )
F_98 ( & V_223 -> V_242 ,
struct V_227 ,
V_232 ) ;
if ( V_235 == NULL )
V_235 =
F_91 ( sizeof( struct V_227 ) ,
V_243 ) ;
if ( V_235 != NULL ) {
F_88 ( & V_235 -> V_232 ) ;
V_235 -> V_97 = V_239 ;
V_235 -> V_230 = V_230 ;
V_235 -> V_228 = V_228 ;
V_235 -> V_231 = V_231 ;
V_235 -> V_236 = V_236 ;
F_92 ( & V_235 -> V_232 ,
& V_223 -> V_241 ) ;
V_223 -> V_233 ++ ;
} else {
F_84 ( V_223 ) ;
V_39 = V_244 ;
goto V_237;
}
}
V_237:
return V_39 ;
}
static enum V_25
F_99 ( struct V_245 * V_246 )
{
if ( ( V_246 -> V_247 < V_248 ) ||
( V_246 -> V_247 > V_249 ) )
return V_250 ;
return V_31 ;
}
static enum V_25
F_100 ( struct V_251 * V_252 )
{
enum V_25 V_39 ;
if ( ( V_252 -> V_253 < V_254 ) ||
( V_252 -> V_253 > V_255 ) )
return V_256 ;
V_39 = F_99 ( & V_252 -> V_257 ) ;
if ( V_39 != V_31 )
return V_39 ;
if ( ( V_252 -> V_258 != V_259 ) &&
( ( V_252 -> V_258 < V_260 ) ||
( V_252 -> V_258 > V_261 ) ) )
return V_262 ;
if ( ( V_252 -> V_263 !=
V_264 ) &&
( V_252 -> V_263 !=
V_265 ) &&
( V_252 -> V_263 !=
V_266 ) )
return V_267 ;
return V_31 ;
}
static enum V_25
F_101 ( struct V_268 * V_269 )
{
T_3 V_22 ;
enum V_25 V_39 ;
if ( ( V_269 -> V_270 != V_271 ) &&
( V_269 -> V_270 != V_272 ) &&
( V_269 -> V_270 != V_273 ) &&
( V_269 -> V_270 != V_274 ) )
return V_275 ;
if ( ( V_269 -> V_276 != V_277 ) &&
( V_269 -> V_276 != V_278 ) )
return V_279 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_39 = F_100 (
& V_269 -> V_252 [ V_22 ] ) ;
if ( V_39 != V_31 )
return V_39 ;
}
return V_31 ;
}
enum V_25 T_6
F_102 (
struct V_5 * * V_280 ,
struct V_281 * V_282 ,
struct V_268 * V_283 )
{
T_3 V_22 ;
T_3 V_284 = 0 ;
struct V_5 * V_6 = NULL ;
enum V_25 V_39 = V_31 ;
V_39 = F_101 ( V_283 ) ;
if ( V_39 != V_31 )
goto exit;
V_6 = F_103 ( sizeof( struct V_5 ) ) ;
if ( V_6 == NULL ) {
V_39 = V_244 ;
goto exit;
}
V_6 -> V_285 = V_286 ;
F_104 ( V_6 , V_59 , V_287 ) ;
memcpy ( & V_6 -> V_288 , V_283 ,
sizeof( struct V_268 ) ) ;
V_6 -> V_132 = V_282 -> V_132 ;
V_6 -> V_112 = V_282 -> V_112 ;
V_6 -> V_289 = V_282 -> V_289 ;
F_45 ( V_6 ) ;
V_39 = F_53 ( V_6 ) ;
if ( V_39 != V_31 ) {
F_105 ( V_6 ) ;
goto exit;
}
F_60 ( V_6 ) ;
V_284 ++ ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_169 & F_10 ( V_22 ) ) )
continue;
if ( V_283 -> V_252 [ V_22 ] . V_290 . V_291 ==
V_292 )
V_284 += V_283 -> V_252 [ V_22 ] . V_290 . V_293 ;
if ( V_283 -> V_252 [ V_22 ] . V_257 . V_291 ==
V_294 )
V_284 += V_283 -> V_252 [ V_22 ] . V_257 . V_247 ;
V_284 ++ ;
}
if ( F_89 ( V_6 ,
& V_6 -> V_295 ,
V_283 -> V_296 + V_284 ,
V_283 -> V_297 + V_284 ) != V_31 ) {
F_106 ( V_6 ) ;
V_39 = V_244 ;
goto exit;
}
V_39 = F_63 ( V_6 ) ;
if ( V_39 != V_31 ) {
F_106 ( V_6 ) ;
goto exit;
}
* V_280 = V_6 ;
exit:
return V_39 ;
}
void
F_106 ( struct V_5 * V_6 )
{
F_107 ( V_6 -> V_285 == V_286 ) ;
V_6 -> V_285 = V_298 ;
F_84 ( & V_6 -> V_295 ) ;
F_105 ( V_6 ) ;
}
static enum V_25
F_108 ( struct V_8 * V_9 ,
T_3 V_299 , T_3 V_35 , T_2 * V_300 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_1 T_1 * V_2 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto V_302;
}
V_2 = V_9 -> V_2 ;
V_3 = F_109 ( V_299 ) |
V_303 |
F_110 ( V_35 ) ;
V_39 = F_13 ( V_3 ,
& V_2 -> V_304 ,
V_303 ,
V_9 -> V_6 -> V_288 . V_305 ) ;
if ( ( V_39 == V_31 ) && ( V_299 == V_306 ) )
* V_300 = F_2 ( & V_2 -> V_307 ) ;
else
* V_300 = 0 ;
V_302:
return V_39 ;
}
static enum V_25
F_111 ( struct V_8 * V_9 ,
struct V_308 * V_309 )
{
T_2 * V_3 ;
int V_22 ;
T_3 V_35 = V_310 ;
enum V_25 V_39 = V_31 ;
V_3 = ( T_2 * ) V_309 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto exit;
}
for ( V_22 = 0 ; V_22 < sizeof( struct V_308 ) / 8 ; V_22 ++ ) {
V_39 = F_108 ( V_9 ,
V_306 ,
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
F_112 ( struct V_8 * V_9 ,
struct V_311 * V_312 )
{
T_2 * V_3 ;
enum V_25 V_39 = V_31 ;
int V_22 ;
T_3 V_35 = V_313 ;
V_3 = ( T_2 * ) V_312 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto exit;
}
for ( V_22 = 0 ; V_22 < sizeof( struct V_311 ) / 8 ; V_22 ++ ) {
V_39 = F_108 ( V_9 ,
V_306 ,
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
F_113 ( struct V_8 * V_9 ,
struct V_314 * V_315 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_1 T_1 * V_2 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto exit;
}
V_2 = V_9 -> V_2 ;
V_3 = F_2 ( & V_2 -> V_316 ) ;
V_315 -> V_317 =
( T_3 ) F_114 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_318 ) ;
V_315 -> V_319 =
( T_3 ) F_115 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_320 ) ;
V_315 -> V_321 =
( T_3 ) F_116 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_322 ) ;
V_315 -> V_323 =
F_117 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_324 ) ;
V_315 -> V_325 =
F_118 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_326 ) ;
V_315 -> V_327 =
( T_3 ) F_119 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_328 ) ;
V_315 -> V_329 =
( T_3 ) F_120 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_330 ) ;
V_315 -> V_331 =
( T_3 ) F_121 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_330 ) ;
V_315 -> V_332 =
( T_3 ) F_122 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_333 ) ;
V_315 -> V_334 =
( T_3 ) F_123 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_330 ) ;
V_315 -> V_335 =
( T_3 ) F_124 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_336 ) ;
V_315 -> V_336 =
( T_3 ) F_125 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_337 ) ;
V_315 -> V_337 =
( T_3 ) F_126 (
V_3 ) ;
V_39 = F_111 ( V_9 , & V_315 -> V_338 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_112 ( V_9 , & V_315 -> V_339 ) ;
if ( V_39 != V_31 )
goto exit;
F_127 (
V_340 ) ;
V_315 -> V_341 =
( T_3 ) F_128 ( V_3 ) ;
V_315 -> V_342 =
( T_3 ) F_129 ( V_3 ) ;
F_127 (
V_343 ) ;
V_315 -> V_344 =
( T_3 ) F_130 ( V_3 ) ;
V_315 -> V_345 =
( T_3 ) F_131 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_346 ) ;
V_315 -> V_347 =
( T_5 ) F_132 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_348 ) ;
V_315 -> V_348 =
( T_3 ) F_133 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_349 ) ;
V_315 -> V_349 =
( T_5 ) F_134 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_350 ) ;
V_315 -> V_351 =
( T_5 ) F_135 ( V_3 ) ;
V_315 -> V_352 =
( T_5 ) F_136 ( V_3 ) ;
V_315 -> V_353 =
( T_5 ) F_137 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_354 ) ;
V_315 -> V_355 =
( T_5 ) F_138 ( V_3 ) ;
V_315 -> V_356 =
( T_5 ) F_139 ( V_3 ) ;
V_315 -> V_357 =
( T_5 ) F_140 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_358 ) ;
V_315 -> V_358 =
( T_5 ) F_141 (
V_3 ) ;
exit:
return V_39 ;
}
enum V_25
F_142 ( struct V_5 * V_6 ,
struct V_359 * V_315 )
{
T_3 V_22 ;
enum V_25 V_39 = V_31 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) ||
( V_6 -> V_14 [ V_22 ] . V_43 ==
V_170 ) )
continue;
memcpy ( V_6 -> V_14 [ V_22 ] . V_360 ,
V_6 -> V_14 [ V_22 ] . V_315 ,
sizeof( struct V_314 ) ) ;
V_39 = F_113 (
& V_6 -> V_14 [ V_22 ] ,
V_6 -> V_14 [ V_22 ] . V_315 ) ;
}
memcpy ( V_315 , & V_6 -> V_101 . V_361 ,
sizeof( struct V_359 ) ) ;
return V_39 ;
}
enum V_25 F_143 (
struct V_5 * V_6 ,
struct V_362 * V_363 )
{
enum V_25 V_39 = V_31 ;
memcpy ( V_363 , & V_6 -> V_101 . V_364 ,
sizeof( struct V_362 ) ) ;
return V_39 ;
}
enum V_25
F_144 ( struct V_5 * V_6 ,
T_3 V_299 , T_3 V_365 , T_3 V_35 , T_2 * V_300 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
V_39 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_145 ( V_299 ) |
V_366 |
F_146 ( V_365 ) |
F_147 ( V_35 ) ;
V_39 = F_13 ( V_3 ,
& V_6 -> V_139 -> V_367 ,
V_366 ,
V_6 -> V_288 . V_305 ) ;
if ( ( V_39 == V_31 ) && ( V_299 == V_306 ) )
* V_300 = F_2 ( & V_6 -> V_139 -> V_368 ) ;
else
* V_300 = 0 ;
exit:
return V_39 ;
}
static enum V_25
F_148 ( struct V_5 * V_6 , T_3 V_369 ,
struct V_370 * V_371 )
{
T_2 * V_3 ;
int V_22 ;
T_3 V_35 = V_372 ;
enum V_25 V_39 = V_31 ;
V_3 = ( T_2 * ) V_371 ;
V_39 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_39 != V_31 )
goto exit;
for ( V_22 = 0 ; V_22 < sizeof( struct V_370 ) / 8 ; V_22 ++ ) {
V_39 = F_144 ( V_6 ,
V_306 ,
V_373 ,
( ( V_35 + ( 104 * V_369 ) ) >> 3 ) , V_3 ) ;
if ( V_39 != V_31 )
goto exit;
V_35 += 8 ;
V_3 ++ ;
}
exit:
return V_39 ;
}
static enum V_25
F_149 ( struct V_5 * V_6 , T_3 V_369 ,
struct V_374 * V_375 )
{
T_2 * V_3 ;
enum V_25 V_39 = V_31 ;
int V_22 ;
T_3 V_35 = 0x0 ;
V_3 = ( T_2 * ) V_375 ;
V_39 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_39 != V_31 )
goto exit;
for ( V_22 = 0 ; V_22 < sizeof( struct V_374 ) / 8 ; V_22 ++ ) {
V_39 = F_144 ( V_6 ,
V_306 ,
V_373 ,
( ( V_35 + ( 608 * V_369 ) ) >> 3 ) , V_3 ) ;
if ( V_39 != V_31 )
goto exit;
V_35 += 8 ;
V_3 ++ ;
}
exit:
return V_39 ;
}
enum V_25
F_150 ( struct V_5 * V_6 ,
struct V_376 * V_377 )
{
enum V_25 V_39 = V_31 ;
T_3 V_22 ;
V_39 = F_148 ( V_6 ,
0 , & V_377 -> V_371 [ 0 ] ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_148 ( V_6 ,
1 , & V_377 -> V_371 [ 1 ] ) ;
if ( V_39 != V_31 )
goto exit;
for ( V_22 = 0 ; V_22 <= V_378 ; V_22 ++ ) {
V_39 = F_149 ( V_6 ,
V_22 , & V_377 -> V_375 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) )
continue;
V_39 = F_111 (
& V_6 -> V_14 [ V_22 ] ,
& V_377 -> V_309 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_112 (
& V_6 -> V_14 [ V_22 ] ,
& V_377 -> V_312 [ V_22 ] ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
void F_104 ( struct V_5 * V_6 ,
enum V_379 V_380 , T_3 V_27 )
{
if ( V_6 == NULL )
return;
#if F_151 ( V_381 ) || \
F_151 ( V_382 )
V_6 -> V_383 = V_27 ;
V_6 -> V_384 = V_380 ;
#endif
#if F_151 ( V_382 )
V_6 -> V_385 = V_380 & V_59 ;
#endif
#if F_151 ( V_381 )
V_6 -> V_386 = V_380 & V_387 ;
#endif
}
T_3 F_152 ( struct V_5 * V_6 )
{
#if F_151 ( V_382 )
if ( V_6 == NULL )
return V_59 ;
else
return V_6 -> V_385 ;
#else
return 0 ;
#endif
}
T_3 F_153 ( struct V_5 * V_6 )
{
#if F_151 ( V_381 )
if ( V_6 == NULL )
return V_387 ;
else
return V_6 -> V_386 ;
#else
return 0 ;
#endif
}
enum V_25 F_154 ( struct V_5 * V_6 ,
T_3 V_369 , T_3 * V_388 , T_3 * V_389 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_285 != V_286 ) ) {
V_39 = V_390 ;
goto exit;
}
if ( V_369 > V_378 ) {
V_39 = V_391 ;
goto exit;
}
if ( ! ( V_6 -> V_153 & V_156 ) ) {
V_39 = V_165 ;
goto exit;
}
V_3 = F_2 ( & V_6 -> V_139 -> V_392 [ V_369 ] ) ;
if ( V_3 & V_393 )
* V_388 = 1 ;
if ( V_3 & V_394 )
* V_389 = 1 ;
exit:
return V_39 ;
}
enum V_25 F_155 ( struct V_5 * V_6 ,
T_3 V_369 , T_3 V_388 , T_3 V_389 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_285 != V_286 ) ) {
V_39 = V_390 ;
goto exit;
}
if ( V_369 > V_378 ) {
V_39 = V_391 ;
goto exit;
}
V_39 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_6 -> V_139 -> V_392 [ V_369 ] ) ;
if ( V_388 )
V_3 |= V_393 ;
else
V_3 &= ~ V_393 ;
if ( V_389 )
V_3 |= V_394 ;
else
V_3 &= ~ V_394 ;
F_4 ( V_3 , & V_6 -> V_139 -> V_392 [ V_369 ] ) ;
exit:
return V_39 ;
}
T_5 F_156 ( struct V_5 * V_6 )
{
struct V_171 * V_172 = V_6 -> V_112 ;
T_5 V_173 ;
F_46 ( V_172 , V_172 -> V_174 + V_175 , & V_173 ) ;
return ( V_173 & V_395 ) >> 4 ;
}
static inline T_3
F_157 ( T_4 * V_396 )
{
return ( T_3 ) * ( ( T_2 * ) ( V_396 + V_397 ) ) ;
}
static inline void
F_158 ( T_4 * V_396 , T_3 V_398 )
{
* ( ( T_2 * ) ( V_396 + V_397 ) ) = V_398 ;
}
static inline void
F_159 ( T_4 * V_396 , T_7 V_399 )
{
* ( ( T_2 * ) ( V_396 + V_400 ) ) = V_399 ;
}
static T_2 F_160 ( struct V_105 * V_290 )
{
struct V_401 * V_402 ;
V_402 = V_290 -> V_403 -> V_404 ;
F_107 ( V_402 != NULL ) ;
return V_402 -> V_32 ;
}
static T_7 F_161 ( struct V_405 * V_406 ,
void * V_232 )
{
T_3 V_398 ;
void * V_230 ;
struct V_401 * V_407 ;
T_8 V_408 ;
V_398 = F_157 ( V_232 ) ;
V_230 = V_406 -> V_409 [ V_398 ] ;
V_407 = V_406 -> V_404 + V_398 ;
V_408 = ( T_4 * ) V_232 - ( T_4 * ) V_230 ;
return V_407 -> V_32 + V_408 ;
}
static void F_162 ( struct V_405 * V_406 ,
struct V_105 * V_290 , T_3 V_410 ,
T_3 V_411 )
{
T_4 * V_412 , * V_413 ;
T_7 V_414 ;
V_413 = V_406 -> V_415 [ V_410 ] ;
F_107 ( V_413 ) ;
V_412 = V_406 -> V_415 [ V_411 ] ;
F_107 ( V_412 ) ;
V_414 = F_161 ( V_406 , V_412 ) ;
F_159 ( V_413 , V_414 ) ;
}
static void
F_163 ( struct V_405 * V_406 ,
T_3 V_416 ,
struct V_401 * V_402 ,
T_3 V_88 , T_3 V_417 )
{
T_3 V_22 ;
void * V_232 = V_406 -> V_415 [ V_88 ] ;
struct V_105 * V_290 =
(struct V_105 * ) V_406 -> V_418 ;
for ( V_22 = 0 ; V_22 < V_290 -> V_419 ; V_22 ++ ) {
void * V_420 ;
void * V_421 ;
struct V_422 * V_423 ;
T_3 V_424 = V_290 -> V_91 . V_107 -
( V_88 * V_290 -> V_419 + V_22 + 1 ) ;
T_3 V_425 ;
V_290 -> V_91 . V_94 [ V_424 ] = ( ( T_4 * ) V_232 ) +
V_22 * V_290 -> V_426 ;
V_420 = F_164 ( V_406 ,
V_416 , V_232 ,
& V_425 ) ;
V_423 = V_290 -> V_91 . V_94 [ V_424 ] ;
V_421 = ( ( T_4 * ) V_420 + V_290 -> V_427 * V_22 ) ;
V_423 -> V_428 = ( T_2 ) ( V_429 ) V_421 ;
}
F_158 ( V_232 , V_416 ) ;
if ( V_417 ) {
F_162 ( V_406 , V_290 , V_88 , 0 ) ;
}
if ( V_88 > 0 ) {
F_162 ( V_406 , V_290 , V_88 - 1 , V_88 ) ;
}
}
enum V_25
F_165 ( struct V_105 * V_290 )
{
void * V_430 ;
struct V_90 * V_91 ;
enum V_25 V_39 = V_31 ;
V_91 = & V_290 -> V_91 ;
while ( F_166 ( V_91 ) > 0 ) {
V_39 = F_167 ( V_290 , & V_430 ) ;
F_107 ( V_39 == V_31 ) ;
if ( V_290 -> V_431 ) {
V_39 = V_290 -> V_431 ( V_430 , V_91 -> V_418 ) ;
if ( V_39 != V_31 ) {
F_168 ( V_290 , V_430 ) ;
goto exit;
}
}
F_169 ( V_290 , V_430 ) ;
}
V_39 = V_31 ;
exit:
return V_39 ;
}
static struct V_90 *
F_170 ( struct V_432 * V_96 ,
enum V_433 type ,
T_3 V_97 , T_3 V_434 ,
void * V_418 )
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
V_91 = F_91 ( V_61 , V_243 ) ;
if ( V_91 == NULL )
goto V_435;
F_90 ( & V_91 -> V_232 ) ;
V_91 -> V_137 = V_6 -> V_137 ;
V_91 -> V_54 = V_6 -> V_54 ;
V_91 -> type = type ;
V_91 -> V_280 = V_6 ;
V_91 -> V_96 = V_96 ;
V_91 -> V_418 = V_418 ;
V_91 -> V_434 = V_434 ;
V_91 -> V_97 = V_97 ;
V_91 -> V_7 = V_7 ;
V_91 -> V_92 = F_91 ( sizeof( void * ) * V_97 , V_243 ) ;
if ( V_91 -> V_92 == NULL )
goto V_436;
V_91 -> V_93 = F_91 ( sizeof( void * ) * V_97 , V_243 ) ;
if ( V_91 -> V_93 == NULL )
goto V_436;
V_91 -> V_106 = V_97 ;
V_91 -> V_94 = F_91 ( sizeof( void * ) * V_97 , V_243 ) ;
if ( V_91 -> V_94 == NULL )
goto V_436;
V_91 -> V_107 = V_97 ;
V_91 -> V_108 = 0 ;
V_91 -> V_95 = F_91 ( sizeof( void * ) * V_97 , V_243 ) ;
if ( V_91 -> V_95 == NULL )
goto V_436;
return V_91 ;
V_436:
F_41 ( V_91 ) ;
V_435:
return NULL ;
}
static void F_171 ( struct V_5 * V_280 ,
void * V_437 ,
T_3 V_97 ,
struct V_171 * V_438 ,
struct V_171 * V_231 )
{
struct V_222 * V_223 ;
struct V_227 * V_235 = NULL ;
T_7 V_228 ;
enum V_25 V_39 = V_31 ;
T_3 V_240 ;
V_223 = & V_280 -> V_295 ;
if ( V_437 == NULL ) {
V_223 -> V_240 -- ;
V_39 = V_30 ;
goto exit;
}
V_228 = F_94 ( V_280 -> V_112 , V_437 , V_97 ,
V_229 ) ;
if ( F_95 ( F_96 ( V_280 -> V_112 , V_228 ) ) ) {
F_87 ( V_280 -> V_112 , V_437 , & V_231 ) ;
V_223 -> V_240 -- ;
V_39 = V_30 ;
goto exit;
}
if ( ! F_97 ( & V_223 -> V_242 ) )
V_235 = (struct V_227 * )
F_98 ( & V_223 -> V_242 ,
struct V_227 ,
V_232 ) ;
if ( V_235 == NULL )
V_235 = F_172 ( sizeof( struct V_227 ) ) ;
else
F_88 ( & V_235 -> V_232 ) ;
if ( V_235 != NULL ) {
V_235 -> V_97 = V_97 ;
V_235 -> V_230 = V_437 ;
V_235 -> V_228 = V_228 ;
V_235 -> V_231 = V_231 ;
V_235 -> V_236 = V_438 ;
F_92 ( & V_235 -> V_232 , & V_223 -> V_241 ) ;
V_223 -> V_233 ++ ;
V_39 = V_31 ;
} else
V_39 = V_244 ;
V_223 -> V_240 -- ;
V_240 = V_223 -> V_240 ;
exit:
return;
}
static inline void
F_173 ( struct V_171 * V_112 , void * V_280 , unsigned long V_61 )
{
T_9 V_439 ;
void * V_440 ;
if ( F_174 () )
V_439 = V_441 | V_442 ;
else
V_439 = V_243 | V_442 ;
V_440 = F_175 ( ( V_61 ) , V_439 ) ;
F_171 ( V_280 , V_440 , V_61 , V_112 , V_112 ) ;
}
static
void F_176 ( struct V_222 * V_223 )
{
T_3 V_443 = 0 , V_22 ;
if ( ( V_223 -> V_233 + V_223 -> V_240 ) <
V_444 ) {
V_443 = V_445 ;
V_223 -> V_240 += V_443 ;
}
for ( V_22 = 0 ; V_22 < V_443 ; V_22 ++ )
F_173 (
( (struct V_5 * ) V_223 -> V_6 ) -> V_112 ,
V_223 -> V_6 , V_239 ) ;
}
static void * F_177 ( struct V_5 * V_280 , T_3 V_61 ,
struct V_401 * V_402 )
{
struct V_227 * V_235 = NULL ;
struct V_222 * V_223 ;
void * V_230 = NULL ;
enum V_25 V_39 = V_31 ;
V_223 = & V_280 -> V_295 ;
if ( V_61 != V_223 -> V_238 ) {
V_230 = F_93 ( V_280 -> V_112 , V_61 ,
& V_402 -> V_446 ,
& V_402 -> V_231 ) ;
if ( V_230 == NULL ) {
V_39 = V_244 ;
goto exit;
}
V_402 -> V_32 = F_94 ( V_280 -> V_112 , V_230 , V_61 ,
V_229 ) ;
if ( F_95 ( F_96 ( V_280 -> V_112 ,
V_402 -> V_32 ) ) ) {
F_87 ( V_280 -> V_112 , V_230 ,
& V_402 -> V_231 ) ;
V_39 = V_244 ;
goto exit;
}
} else {
if ( ! F_97 ( & V_223 -> V_241 ) )
V_235 = (struct V_227 * )
F_98 ( & V_223 -> V_241 ,
struct V_227 ,
V_232 ) ;
if ( V_235 != NULL ) {
F_88 ( & V_235 -> V_232 ) ;
V_402 -> V_32 = V_235 -> V_228 ;
V_402 -> V_446 = V_235 -> V_236 ;
V_402 -> V_231 = V_235 -> V_231 ;
V_230 = V_235 -> V_230 ;
F_92 ( & V_235 -> V_232 ,
& V_223 -> V_242 ) ;
V_223 -> V_233 -- ;
}
if ( V_230 != NULL )
F_176 ( V_223 ) ;
}
exit:
return V_230 ;
}
static void
F_178 ( struct V_222 * V_223 )
{
struct V_224 * V_225 , * V_226 ;
F_85 (p, n, &blockpool->free_block_list) {
if ( V_223 -> V_233 < V_223 -> V_234 )
break;
F_86 (
( (struct V_5 * ) V_223 -> V_6 ) -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_228 ,
( (struct V_227 * ) V_225 ) -> V_97 ,
V_229 ) ;
F_87 (
( (struct V_5 * ) V_223 -> V_6 ) -> V_112 ,
( (struct V_227 * ) V_225 ) -> V_230 ,
& ( (struct V_227 * ) V_225 ) -> V_231 ) ;
F_88 ( & ( (struct V_227 * ) V_225 ) -> V_232 ) ;
F_92 ( V_225 , & V_223 -> V_242 ) ;
V_223 -> V_233 -- ;
}
}
static void F_179 ( struct V_5 * V_280 ,
void * V_230 , T_3 V_61 ,
struct V_401 * V_402 )
{
struct V_227 * V_235 = NULL ;
struct V_222 * V_223 ;
enum V_25 V_39 = V_31 ;
V_223 = & V_280 -> V_295 ;
if ( V_61 != V_223 -> V_238 ) {
F_86 ( V_280 -> V_112 , V_402 -> V_32 , V_61 ,
V_229 ) ;
F_87 ( V_280 -> V_112 , V_230 , & V_402 -> V_231 ) ;
} else {
if ( ! F_97 ( & V_223 -> V_242 ) )
V_235 = (struct V_227 * )
F_98 ( & V_223 -> V_242 ,
struct V_227 ,
V_232 ) ;
if ( V_235 == NULL )
V_235 = F_172 ( sizeof(
struct V_227 ) ) ;
else
F_88 ( & V_235 -> V_232 ) ;
if ( V_235 != NULL ) {
V_235 -> V_97 = V_61 ;
V_235 -> V_230 = V_230 ;
V_235 -> V_228 = V_402 -> V_32 ;
V_235 -> V_231 = V_402 -> V_231 ;
V_235 -> V_236 = V_402 -> V_446 ;
F_92 ( & V_235 -> V_232 ,
& V_223 -> V_241 ) ;
V_223 -> V_233 ++ ;
V_39 = V_31 ;
} else
V_39 = V_244 ;
if ( V_39 == V_31 )
F_178 ( V_223 ) ;
}
}
static void F_180 ( struct V_405 * V_403 )
{
T_3 V_22 , V_201 ;
struct V_5 * V_280 = V_403 -> V_280 ;
for ( V_22 = 0 ; V_22 < V_403 -> V_447 ; V_22 ++ ) {
struct V_401 * V_402 ;
F_107 ( V_403 -> V_409 [ V_22 ] ) ;
F_107 ( V_403 -> V_404 + V_22 ) ;
V_402 = V_403 -> V_404 + V_22 ;
for ( V_201 = 0 ; V_201 < V_403 -> V_448 ; V_201 ++ ) {
T_3 V_88 = V_22 * V_403 -> V_448 + V_201 ;
if ( V_88 >= V_403 -> V_449 )
break;
}
F_105 ( V_403 -> V_450 [ V_22 ] ) ;
F_179 ( V_280 , V_403 -> V_409 [ V_22 ] ,
V_403 -> V_451 , V_402 ) ;
}
F_105 ( V_403 -> V_415 ) ;
F_105 ( V_403 -> V_404 ) ;
F_105 ( V_403 -> V_450 ) ;
F_105 ( V_403 -> V_409 ) ;
F_105 ( V_403 ) ;
}
static enum V_25
F_181 ( struct V_405 * V_403 , T_3 V_452 ,
T_3 * V_453 )
{
T_3 V_22 , V_454 = V_403 -> V_447 == 0 ? 1 : 0 ;
T_3 V_455 = V_403 -> V_448 ;
T_3 V_456 = V_403 -> V_447 ;
T_3 V_457 = V_403 -> V_447 + V_452 ;
enum V_25 V_39 = V_31 ;
* V_453 = 0 ;
if ( V_457 > V_403 -> V_458 ) {
V_39 = V_244 ;
goto exit;
}
for ( V_22 = V_456 ; V_22 < V_457 ; V_22 ++ ) {
T_3 V_201 ;
T_3 V_417 = ( ( V_457 - 1 ) == V_22 ) ;
struct V_401 * V_402 =
V_403 -> V_404 + V_22 ;
void * V_459 ;
V_403 -> V_450 [ V_22 ] =
F_103 ( V_403 -> V_460 * V_455 ) ;
if ( V_403 -> V_450 [ V_22 ] == NULL ) {
V_39 = V_244 ;
goto exit;
}
V_403 -> V_409 [ V_22 ] =
F_177 ( V_403 -> V_280 ,
V_403 -> V_451 , V_402 ) ;
if ( V_403 -> V_409 [ V_22 ] == NULL ) {
F_105 ( V_403 -> V_450 [ V_22 ] ) ;
V_39 = V_244 ;
goto exit;
}
( * V_453 ) ++ ;
V_403 -> V_447 ++ ;
memset ( V_403 -> V_409 [ V_22 ] , 0 , V_403 -> V_451 ) ;
V_459 = V_403 -> V_409 [ V_22 ] ;
for ( V_201 = 0 ; V_201 < V_455 ; V_201 ++ ) {
T_3 V_88 = V_22 * V_455 + V_201 ;
if ( V_454 && V_88 >= V_403 -> V_461 )
break;
V_403 -> V_415 [ V_88 ] =
( ( char * ) V_459 + V_201 * V_403 -> V_462 ) ;
if ( V_403 -> V_463 != NULL )
V_403 -> V_463 ( V_403 , V_22 ,
V_402 , V_88 , V_417 ) ;
V_403 -> V_449 = V_88 + 1 ;
}
if ( V_454 && V_403 -> V_449 ==
V_403 -> V_461 )
break;
}
exit:
return V_39 ;
}
static struct V_405 *
F_182 ( struct V_5 * V_280 ,
T_3 V_451 ,
T_3 V_462 ,
T_3 V_460 ,
T_3 V_461 ,
T_3 V_464 ,
const struct V_465 * V_466 ,
void * V_418 )
{
enum V_25 V_39 = V_31 ;
T_3 V_467 ;
struct V_405 * V_403 = NULL ;
T_3 V_468 ;
if ( V_451 < V_462 ) {
V_39 = V_30 ;
goto exit;
}
V_403 = F_103 ( sizeof( struct V_405 ) ) ;
if ( V_403 == NULL ) {
V_39 = V_244 ;
goto exit;
}
V_403 -> V_280 = V_280 ;
V_403 -> V_451 = V_451 ;
V_403 -> V_464 = V_464 ;
V_403 -> V_461 = V_461 ;
V_403 -> V_462 = V_462 ;
V_403 -> V_460 = V_460 ;
V_403 -> V_463 = V_466 -> V_463 ;
V_403 -> V_418 = V_418 ;
V_403 -> V_447 = 0 ;
V_403 -> V_448 = V_451 / V_462 ;
V_403 -> V_458 = ( V_464 + V_403 -> V_448 - 1 ) /
V_403 -> V_448 ;
V_403 -> V_409 =
F_103 ( sizeof( void * ) * V_403 -> V_458 ) ;
if ( V_403 -> V_409 == NULL ) {
F_180 ( V_403 ) ;
V_39 = V_244 ;
V_403 = NULL ;
goto exit;
}
V_403 -> V_450 =
F_103 ( sizeof( void * ) * V_403 -> V_458 ) ;
if ( V_403 -> V_450 == NULL ) {
F_180 ( V_403 ) ;
V_39 = V_244 ;
V_403 = NULL ;
goto exit;
}
V_403 -> V_404 =
F_103 ( sizeof( struct V_401 ) *
V_403 -> V_458 ) ;
if ( V_403 -> V_404 == NULL ) {
F_180 ( V_403 ) ;
V_39 = V_244 ;
V_403 = NULL ;
goto exit;
}
V_403 -> V_415 = F_103 ( sizeof( void * ) * V_403 -> V_464 ) ;
if ( V_403 -> V_415 == NULL ) {
F_180 ( V_403 ) ;
V_39 = V_244 ;
V_403 = NULL ;
goto exit;
}
V_467 = ( V_403 -> V_461 +
V_403 -> V_448 - 1 ) /
V_403 -> V_448 ;
V_39 = F_181 ( V_403 , V_467 ,
& V_468 ) ;
if ( V_39 != V_31 ) {
F_180 ( V_403 ) ;
V_39 = V_244 ;
V_403 = NULL ;
goto exit;
}
exit:
return V_403 ;
}
static enum V_25 F_183 ( struct V_105 * V_290 )
{
void * V_469 ;
struct V_90 * V_91 ;
V_91 = & V_290 -> V_91 ;
for (; ; ) {
F_184 ( V_91 , & V_469 ) ;
if ( V_469 == NULL )
break;
F_185 ( V_91 ) ;
if ( V_290 -> V_470 )
V_290 -> V_470 ( V_469 , V_471 ,
V_91 -> V_418 ) ;
F_186 ( V_91 , V_469 ) ;
}
return V_31 ;
}
static enum V_25 F_187 ( struct V_105 * V_290 )
{
enum V_25 V_39 = V_31 ;
struct V_90 * V_91 ;
V_91 = & V_290 -> V_91 ;
F_183 ( V_290 ) ;
V_39 = F_44 ( V_91 ) ;
if ( V_39 != V_31 )
goto exit;
if ( V_290 -> V_431 ) {
V_39 = F_165 ( V_290 ) ;
if ( V_39 != V_31 )
goto exit;
}
exit:
return V_39 ;
}
static enum V_25
F_188 ( struct V_432 * V_472 )
{
struct V_105 * V_290 = V_472 -> V_9 -> V_104 ;
F_183 ( V_290 ) ;
if ( V_290 -> V_403 )
F_180 ( V_290 -> V_403 ) ;
V_472 -> V_9 -> V_104 = NULL ;
F_41 ( & V_290 -> V_91 ) ;
return V_31 ;
}
static enum V_25
F_189 ( struct V_432 * V_472 ,
struct V_473 * V_282 )
{
enum V_25 V_39 = V_31 ;
struct V_105 * V_290 ;
T_3 V_474 ;
struct V_475 * V_288 ;
struct V_5 * V_6 ;
T_3 V_7 ;
static const struct V_465 V_476 = {
. V_463 = F_163 ,
} ;
if ( ( V_472 == NULL ) || ( V_282 == NULL ) ) {
V_39 = V_30 ;
goto exit;
}
V_6 = V_472 -> V_9 -> V_6 ;
V_7 = V_472 -> V_9 -> V_7 ;
V_288 = & V_6 -> V_288 . V_252 [ V_7 ] . V_290 ;
V_474 = V_288 -> V_293 *
F_190 ( V_288 -> V_477 ) ;
V_290 = (struct V_105 * ) F_170 ( V_472 ,
V_103 ,
V_474 ,
V_282 -> V_478 ,
V_282 -> V_418 ) ;
if ( V_290 == NULL ) {
V_39 = V_244 ;
goto exit;
}
V_472 -> V_9 -> V_104 = V_290 ;
V_290 -> V_7 = V_7 ;
V_290 -> V_2 = V_472 -> V_9 -> V_2 ;
V_290 -> V_137 = V_6 -> V_137 ;
V_290 -> V_101 = & V_472 -> V_9 -> V_363 -> V_479 ;
V_290 -> V_288 = V_288 ;
V_290 -> V_480 = V_282 -> V_480 ;
V_290 -> V_431 = V_282 -> V_431 ;
V_290 -> V_470 = V_282 -> V_470 ;
V_290 -> V_477 = V_288 -> V_477 ;
V_290 -> V_481 = V_472 -> V_9 -> V_481 ;
V_290 -> V_482 = V_472 -> V_9 -> V_482 ;
V_290 -> V_483 = V_288 -> V_483 ;
V_290 -> V_426 = F_191 ( V_288 -> V_477 ) ;
V_290 -> V_427 =
sizeof( struct V_484 ) + V_282 -> V_478 ;
V_290 -> V_478 = V_282 -> V_478 ;
V_290 -> V_427 =
( ( V_290 -> V_427 + V_485 - 1 ) /
V_485 ) * V_485 ;
V_290 -> V_419 =
F_190 ( V_288 -> V_477 ) ;
V_290 -> V_486 = V_290 -> V_427 * V_290 -> V_419 ;
V_290 -> V_403 = F_182 ( V_6 ,
V_239 ,
V_239 ,
V_290 -> V_486 ,
V_290 -> V_288 -> V_293 ,
V_290 -> V_288 -> V_293 ,
& V_476 ,
V_290 ) ;
if ( V_290 -> V_403 == NULL ) {
F_188 ( V_472 ) ;
return V_244 ;
}
V_39 = F_43 ( & V_290 -> V_91 ) ;
if ( V_39 != V_31 ) {
F_188 ( V_472 ) ;
goto exit;
}
if ( V_290 -> V_431 ) {
V_39 = F_165 ( V_290 ) ;
if ( V_39 != V_31 ) {
F_188 ( V_472 ) ;
goto exit;
}
}
V_290 -> V_101 -> V_102 . V_487 = 0 ;
exit:
return V_39 ;
}
enum V_25 T_6
F_192 ( struct V_268 * V_283 )
{
T_3 V_22 ;
V_283 -> V_296 =
V_488 ;
V_283 -> V_297 = V_489 ;
V_283 -> V_270 = V_274 ;
V_283 -> V_490 = V_491 ;
V_283 -> V_492 = V_493 ;
V_283 -> V_305 = V_48 ;
V_283 -> V_276 = V_494 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_283 -> V_252 [ V_22 ] . V_7 = V_22 ;
V_283 -> V_252 [ V_22 ] . V_253 =
V_495 ;
V_283 -> V_252 [ V_22 ] . V_290 . V_291 = V_496 ;
V_283 -> V_252 [ V_22 ] . V_290 . V_293 =
V_497 ;
V_283 -> V_252 [ V_22 ] . V_290 . V_477 =
V_498 ;
V_283 -> V_252 [ V_22 ] . V_290 . V_499 =
V_500 ;
V_283 -> V_252 [ V_22 ] . V_290 . V_483 =
V_501 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_291 = V_294 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_247 =
V_248 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_502 =
V_503 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_451 =
V_504 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_505 =
V_506 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_507 =
V_508 ;
V_283 -> V_252 [ V_22 ] . V_257 . V_509 =
V_510 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_512 =
V_513 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_514 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_516 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_517 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_518 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_519 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_520 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_521 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_522 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_523 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_524 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_525 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_526 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_527 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_511 . V_528 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_512 =
V_513 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_514 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_516 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_517 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_518 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_519 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_520 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_521 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_522 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_523 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_524 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_525 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_526 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_527 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_529 . V_528 =
V_515 ;
V_283 -> V_252 [ V_22 ] . V_258 =
V_259 ;
V_283 -> V_252 [ V_22 ] . V_263 =
V_264 ;
}
return V_31 ;
}
static enum V_25
F_193 ( struct V_1 T_1 * V_148 )
{
#ifndef F_194
T_2 V_3 ;
V_3 = F_2 ( & V_148 -> V_530 ) ;
F_16 () ;
V_3 |= V_531 ;
F_4 ( V_3 , & V_148 -> V_530 ) ;
F_16 () ;
#endif
return V_31 ;
}
static enum V_25
F_195 ( struct V_115 T_1 * V_116 ,
struct V_1 T_1 * V_148 )
{
T_2 V_3 ;
V_3 = F_2 ( & V_116 -> V_125 ) ;
if ( V_3 == V_124 ) {
V_3 = F_2 ( & V_148 -> V_532 ) ;
F_16 () ;
V_3 |= V_533 |
V_534 |
V_535 ;
F_4 ( V_3 , & V_148 -> V_532 ) ;
F_16 () ;
}
return V_31 ;
}
enum V_25
F_196 ( struct V_5 * V_6 ,
enum V_536 type ,
T_3 V_88 , T_3 V_35 , T_2 * V_537 )
{
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_285 != V_286 ) ) {
V_39 = V_390 ;
goto exit;
}
switch ( type ) {
case V_538 :
if ( V_35 > sizeof( struct V_115 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_116 + V_35 ) ;
break;
case V_540 :
if ( V_35 > sizeof( struct V_131 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_135 + V_35 ) ;
break;
case V_541 :
if ( V_35 > sizeof( struct V_216 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_137 + V_35 ) ;
break;
case V_542 :
if ( ! ( V_6 -> V_153 &
V_156 ) ) {
V_39 = V_165 ;
break;
}
if ( V_35 > sizeof( struct V_215 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_139 + V_35 ) ;
break;
case V_543 :
if ( ! ( V_6 -> V_153 &
V_157 ) ) {
V_39 = V_165 ;
break;
}
if ( V_88 > V_140 - 1 ) {
V_39 = V_544 ;
break;
}
if ( V_35 > sizeof( struct V_545 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_142 [ V_88 ] +
V_35 ) ;
break;
case V_546 :
if ( ( V_88 > V_143 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_39 = V_544 ;
break;
}
if ( V_35 > sizeof( struct V_166 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_145 [ V_88 ] +
V_35 ) ;
break;
case V_547 :
if ( ( V_88 > V_146 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_39 = V_544 ;
break;
}
if ( V_88 > V_146 - 1 ) {
V_39 = V_544 ;
break;
}
if ( V_35 > sizeof( struct V_1 ) - 8 ) {
V_39 = V_539 ;
break;
}
* V_537 = F_2 ( ( void T_1 * ) V_6 -> V_148 [ V_88 ] +
V_35 ) ;
break;
default:
V_39 = V_548 ;
break;
}
exit:
return V_39 ;
}
enum V_25
F_197 ( struct V_5 * V_6 , T_2 V_218 )
{
struct V_166 T_1 * V_145 ;
enum V_25 V_39 = V_31 ;
int V_22 = 0 , V_201 = 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_218 ) & F_10 ( V_22 ) ) )
continue;
V_145 = V_6 -> V_145 [ V_22 ] ;
for ( V_201 = 0 ; V_201 < V_378 ; V_201 ++ ) {
if ( F_2 ( & V_145 -> V_549 [ V_201 ] )
& V_550 )
return V_30 ;
}
}
return V_39 ;
}
enum V_25
F_198 ( struct V_5 * V_6 ,
enum V_536 type ,
T_3 V_88 , T_3 V_35 , T_2 V_537 )
{
enum V_25 V_39 = V_31 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_285 != V_286 ) ) {
V_39 = V_390 ;
goto exit;
}
switch ( type ) {
case V_538 :
if ( V_35 > sizeof( struct V_115 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_116 + V_35 ) ;
break;
case V_540 :
if ( V_35 > sizeof( struct V_131 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_135 + V_35 ) ;
break;
case V_541 :
if ( V_35 > sizeof( struct V_216 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_137 + V_35 ) ;
break;
case V_542 :
if ( ! ( V_6 -> V_153 &
V_156 ) ) {
V_39 = V_165 ;
break;
}
if ( V_35 > sizeof( struct V_215 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_139 + V_35 ) ;
break;
case V_543 :
if ( ! ( V_6 -> V_153 &
V_157 ) ) {
V_39 = V_165 ;
break;
}
if ( V_88 > V_140 - 1 ) {
V_39 = V_544 ;
break;
}
if ( V_35 > sizeof( struct V_545 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_142 [ V_88 ] +
V_35 ) ;
break;
case V_546 :
if ( ( V_88 > V_143 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_39 = V_544 ;
break;
}
if ( V_35 > sizeof( struct V_166 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_145 [ V_88 ] +
V_35 ) ;
break;
case V_547 :
if ( ( V_88 > V_146 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_39 = V_544 ;
break;
}
if ( V_35 > sizeof( struct V_1 ) - 8 ) {
V_39 = V_539 ;
break;
}
F_4 ( V_537 , ( void T_1 * ) V_6 -> V_148 [ V_88 ] +
V_35 ) ;
break;
default:
V_39 = V_548 ;
break;
}
exit:
return V_39 ;
}
static enum V_25 F_199 ( struct V_100 * V_257 )
{
void * V_551 ;
for (; ; ) {
F_184 ( & V_257 -> V_91 , & V_551 ) ;
if ( V_551 == NULL )
break;
F_185 ( & V_257 -> V_91 ) ;
if ( V_257 -> V_552 ) {
V_257 -> V_552 ( V_551 ,
V_553 ,
V_257 -> V_91 . V_418 ) ;
}
F_186 ( & V_257 -> V_91 , V_551 ) ;
}
return V_31 ;
}
static enum V_25 F_200 ( struct V_100 * V_257 )
{
enum V_25 V_39 = V_31 ;
F_199 ( V_257 ) ;
V_39 = F_44 ( & V_257 -> V_91 ) ;
return V_39 ;
}
static enum V_25
F_201 ( struct V_432 * V_472 )
{
struct V_100 * V_257 = V_472 -> V_9 -> V_99 ;
F_199 ( V_257 ) ;
if ( V_257 -> V_403 )
F_180 ( V_257 -> V_403 ) ;
V_472 -> V_9 -> V_99 = NULL ;
F_41 ( & V_257 -> V_91 ) ;
return V_31 ;
}
static void
F_202 (
struct V_405 * V_406 ,
T_3 V_416 , struct V_401 * V_402 ,
T_3 V_88 , T_3 V_417 )
{
T_3 V_425 ;
struct V_554 * V_555 ;
struct V_556 * V_557 =
(struct V_556 * ) V_406 -> V_415 [ V_88 ] ;
struct V_100 * V_257 =
(struct V_100 * ) V_406 -> V_418 ;
void * V_230 = V_406 -> V_409 [ V_416 ] ;
F_107 ( V_557 ) ;
V_557 -> V_428 = ( T_2 ) ( V_429 )
F_164 ( V_406 , V_416 , V_557 ,
& V_425 ) ;
V_555 = V_554 ( V_257 , V_557 ) ;
F_107 ( V_555 ) ;
V_257 -> V_91 . V_94 [ V_257 -> V_91 . V_107 - 1 - V_88 ] = V_557 ;
V_555 -> V_558 = ( char * ) V_557 - ( char * ) V_230 ;
V_555 -> V_228 = V_402 -> V_32 + V_555 -> V_558 ;
V_555 -> V_236 = V_402 -> V_446 ;
V_555 -> V_230 = V_230 ;
V_555 -> V_559 = V_557 ;
V_555 -> V_560 = NULL ;
V_555 -> V_561 = 0 ;
}
static enum V_25
F_203 ( struct V_432 * V_472 ,
struct V_562 * V_282 )
{
enum V_25 V_39 = V_31 ;
struct V_100 * V_257 ;
struct V_245 * V_288 ;
T_3 V_563 , V_564 ;
struct V_465 V_565 ;
struct V_8 * V_9 ;
if ( ( V_472 == NULL ) || ( V_282 == NULL ) ) {
V_39 = V_566 ;
goto exit;
}
V_9 = V_472 -> V_9 ;
V_288 = & V_9 -> V_6 -> V_288 . V_252 [ V_9 -> V_7 ] . V_257 ;
V_563 = V_288 -> V_502 * sizeof( struct V_556 ) ;
V_564 = V_288 -> V_451 / V_563 ;
V_257 = (struct V_100 * ) F_170 ( V_472 ,
V_98 ,
V_288 -> V_247 * V_564 ,
V_282 -> V_567 , V_282 -> V_418 ) ;
if ( V_257 == NULL ) {
V_39 = V_244 ;
goto exit;
}
V_9 -> V_99 = V_257 ;
V_257 -> V_568 = V_9 -> V_568 ;
V_257 -> V_7 = V_9 -> V_7 ;
V_257 -> V_2 = V_9 -> V_2 ;
V_257 -> V_101 = & V_9 -> V_363 -> V_569 ;
V_257 -> V_288 = V_288 ;
V_257 -> V_570 = V_571 ;
V_257 -> V_572 = V_9 -> V_572 ;
V_257 -> V_573 = V_9 -> V_573 ;
if ( V_257 -> V_288 -> V_507 )
V_257 -> V_570 = V_574 ;
V_257 -> V_509 = V_288 -> V_509 ;
V_257 -> V_575 =
sizeof( struct V_554 ) + V_282 -> V_567 ;
V_257 -> V_575 = ( ( V_257 -> V_575 + V_485 - 1 ) /
V_485 ) * V_485 ;
V_257 -> V_567 = V_282 -> V_567 ;
V_257 -> V_563 = V_563 ;
V_257 -> V_564 = V_564 ;
V_257 -> V_552 = V_282 -> V_552 ;
V_257 -> V_480 = V_282 -> V_480 ;
if ( V_257 -> V_564 == 0 ) {
F_201 ( V_472 ) ;
V_39 = V_576 ;
goto exit;
}
V_565 . V_463 = F_202 ;
V_257 -> V_403 =
F_182 ( V_9 -> V_6 ,
V_257 -> V_288 -> V_451 ,
V_257 -> V_563 ,
V_257 -> V_575 ,
( V_257 -> V_288 -> V_247 * V_257 -> V_564 ) ,
( V_257 -> V_288 -> V_247 * V_257 -> V_564 ) ,
& V_565 ,
V_257 ) ;
if ( V_257 -> V_403 == NULL ) {
F_201 ( V_472 ) ;
V_39 = V_244 ;
goto exit;
}
V_39 = F_43 ( & V_257 -> V_91 ) ;
if ( V_39 != V_31 ) {
F_201 ( V_472 ) ;
goto exit;
}
F_107 ( V_257 -> V_91 . V_107 ) ;
exit:
return V_39 ;
}
static enum V_25
F_204 ( struct V_8 * V_9 ,
T_3 V_577 , T_3 V_35 , T_3 * V_578 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
V_3 = F_205 ( V_35 ) ;
if ( V_577 )
V_3 |= V_579 ;
F_4 ( V_3 , & V_2 -> V_580 ) ;
F_16 () ;
F_4 ( V_581 ,
& V_2 -> V_582 ) ;
F_16 () ;
V_39 = F_11 (
& V_2 -> V_582 ,
V_583 , V_48 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_2 -> V_584 ) ;
if ( V_3 & V_585 ) {
V_39 = V_30 ;
* V_578 = 0 ;
} else
* V_578 = ( T_3 ) F_15 ( V_3 , 32 , 32 ) ;
exit:
return V_39 ;
}
enum V_25
F_206 ( struct V_5 * V_6 , T_2 V_586 )
{
struct V_8 * V_9 ;
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
if ( V_6 == NULL ) {
V_39 = V_390 ;
goto exit;
}
V_9 = & V_6 -> V_14 [ V_6 -> V_54 ] ;
V_36 = V_586 ;
V_39 = F_18 ( V_9 ,
V_587 ,
V_86 ,
0 , & V_36 , & V_37 , & V_38 ) ;
exit:
return V_39 ;
}
enum V_25
F_207 ( struct V_432 * V_472 ,
T_3 V_33 , T_3 V_588 , T_3 V_35 ,
T_2 * V_36 , T_2 * V_37 )
{
enum V_25 V_39 ;
T_2 V_38 = 0 ;
if ( V_472 == NULL ) {
V_39 = V_566 ;
goto exit;
}
if ( ( V_588 ==
V_589 ) ||
( V_588 ==
V_590 ) ||
( V_588 ==
V_591 ) ||
( V_588 ==
V_592 ) ) {
V_38 = V_593 ;
}
V_39 = F_18 ( V_472 -> V_9 , V_33 , V_588 , V_35 ,
V_36 , V_37 , & V_38 ) ;
if ( V_39 != V_31 )
goto exit;
if ( ( V_588 != V_212 ) &&
( V_588 !=
V_590 ) )
* V_37 = 0 ;
exit:
return V_39 ;
}
enum V_25
F_208 ( struct V_432 * V_472 , T_3 V_33 ,
T_3 V_588 , T_3 V_35 , T_2 V_594 ,
T_2 V_595 )
{
T_2 V_36 , V_37 = 0 , V_38 = 0 ;
enum V_25 V_39 ;
if ( V_472 == NULL ) {
V_39 = V_566 ;
goto exit;
}
V_36 = V_594 ;
if ( ( V_588 == V_212 ) ||
( V_588 ==
V_590 ) )
V_37 = V_595 ;
V_39 = F_18 ( V_472 -> V_9 , V_33 , V_588 , V_35 ,
& V_36 , & V_37 , & V_38 ) ;
exit:
return V_39 ;
}
enum V_25 F_209 (
struct V_432 * V_472 ,
enum V_596 V_597 ,
struct V_598 * V_599 ,
T_5 V_600 )
{
T_2 V_36 , V_37 ;
enum V_25 V_39 = V_31 ;
if ( V_472 == NULL ) {
V_39 = V_566 ;
goto exit;
}
V_39 = F_207 ( V_472 ,
V_192 ,
V_601 ,
0 , & V_36 , & V_37 ) ;
if ( V_39 != V_31 )
goto exit;
V_36 &= ~ ( F_210 ( 0xf ) |
F_211 ( 0x3 ) ) ;
V_36 |= V_602 |
F_210 ( V_600 ) |
F_211 ( V_597 ) ;
if ( V_599 -> V_603 )
V_36 |= V_604 ;
if ( V_599 -> V_605 )
V_36 |= V_606 ;
if ( V_599 -> V_607 )
V_36 |= V_608 ;
if ( V_599 -> V_609 )
V_36 |= V_610 ;
if ( V_599 -> V_611 )
V_36 |=
V_612 ;
if ( V_599 -> V_613 )
V_36 |= V_614 ;
if ( F_212 ( V_36 ) )
V_36 &= ~ V_615 ;
else
V_36 |= V_615 ;
V_39 = F_208 ( V_472 ,
V_616 ,
V_601 ,
0 , V_36 , 0 ) ;
exit:
return V_39 ;
}
static void
F_213 ( T_3 V_201 , T_2 * V_36 , T_2 * V_37 ,
T_5 V_617 , T_4 * V_618 )
{
switch ( V_617 ) {
case 1 :
* V_36 = F_214 ( V_201 ) |
V_619 |
F_215 (
V_618 [ V_201 ] ) ;
case 2 :
* V_36 |=
F_216 ( V_201 ) |
V_620 |
F_217 (
V_618 [ V_201 ] ) ;
case 3 :
* V_37 = F_218 ( V_201 ) |
V_621 |
F_219 (
V_618 [ V_201 ] ) ;
case 4 :
* V_37 |=
F_220 ( V_201 ) |
V_622 |
F_221 (
V_618 [ V_201 ] ) ;
default:
return;
}
}
enum V_25 F_222 (
struct V_432 * * V_623 ,
T_3 V_624 ,
T_4 * V_625 ,
T_4 * V_618 ,
T_3 V_626 )
{
T_3 V_22 , V_201 , V_33 , V_588 ;
T_2 V_36 ;
T_2 V_37 ;
T_3 V_627 ;
enum V_25 V_39 = V_31 ;
struct V_432 * V_472 = V_623 [ 0 ] ;
if ( V_472 == NULL ) {
V_39 = V_566 ;
goto exit;
}
V_627 = ( ( ( T_3 ) 1 ) << V_626 ) ;
if ( V_472 -> V_9 -> V_6 -> V_288 . V_492
== V_628 ) {
V_33 = V_616 ;
V_588 =
V_589 ;
for ( V_201 = 0 ; V_201 < V_627 ; V_201 ++ ) {
V_37 = 0 ;
V_36 =
F_223 (
V_618 [ V_201 ] ) ;
V_39 = F_208 ( V_623 [ 0 ] ,
V_33 , V_588 , V_201 , V_36 , V_37 ) ;
if ( V_39 != V_31 )
goto exit;
}
for ( V_201 = 0 ; V_201 < V_627 ; V_201 ++ ) {
V_37 = 0 ;
V_36 =
V_629 |
F_223 (
V_618 [ V_201 ] ) ;
V_39 = F_208 (
V_623 [ V_625 [ V_618 [ V_201 ] ] ] , V_33 ,
V_588 , V_201 , V_36 , V_37 ) ;
if ( V_39 != V_31 )
goto exit;
}
} else {
V_33 = V_616 ;
V_588 =
V_590 ;
for ( V_22 = 0 ; V_22 < V_624 ; V_22 ++ ) {
for ( V_201 = 0 ; V_201 < V_627 ; ) {
V_36 = 0 ;
V_37 = 0 ;
while ( V_201 < V_627 ) {
if ( V_625 [ V_618 [ V_201 ] ] != V_22 ) {
V_201 ++ ;
continue;
}
F_213 ( V_201 ,
& V_36 , & V_37 , 1 , V_618 ) ;
V_201 ++ ;
break;
}
while ( V_201 < V_627 ) {
if ( V_625 [ V_618 [ V_201 ] ] != V_22 ) {
V_201 ++ ;
continue;
}
F_213 ( V_201 ,
& V_36 , & V_37 , 2 , V_618 ) ;
V_201 ++ ;
break;
}
while ( V_201 < V_627 ) {
if ( V_625 [ V_618 [ V_201 ] ] != V_22 ) {
V_201 ++ ;
continue;
}
F_213 ( V_201 ,
& V_36 , & V_37 , 3 , V_618 ) ;
V_201 ++ ;
break;
}
while ( V_201 < V_627 ) {
if ( V_625 [ V_618 [ V_201 ] ] != V_22 ) {
V_201 ++ ;
continue;
}
F_213 ( V_201 ,
& V_36 , & V_37 , 4 , V_618 ) ;
V_201 ++ ;
break;
}
if ( V_36 != 0 ) {
V_39 = F_208 (
V_623 [ V_22 ] ,
V_33 , V_588 ,
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
F_224 ( struct V_105 * V_290 )
{
enum V_25 V_39 = V_31 ;
T_2 V_630 , V_11 ;
if ( V_290 == NULL )
return V_39 ;
V_630 = F_225 ( & V_290 -> V_2 -> V_16 ) ;
V_11 = F_2 ( & V_290 -> V_2 -> V_15 ) ;
V_11 = F_226 ( V_11 ) ;
if ( V_630 >= V_11 )
V_39 = V_30 ;
return V_39 ;
}
static enum V_25
F_227 (
struct V_5 * V_6 ,
struct V_8 * V_9 )
{
T_3 V_22 , V_258 = 0 , V_631 = 0 ;
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
for ( V_22 = 0 ; V_22 < V_378 ; V_22 ++ ) {
V_3 = F_2 ( & V_9 -> V_145 ->
V_549 [ V_22 ] ) ;
V_631 =
( T_3 )
F_228
( V_3 ) ;
if ( V_258 < V_631 )
V_258 = V_631 ;
}
V_9 -> V_632 = V_258 + V_633 ;
V_3 = F_2 ( & V_9 -> V_145 -> V_634 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_3 & F_10 ( V_22 ) )
V_9 -> V_635 = V_22 ;
}
V_3 = F_2 ( & V_9 -> V_145 -> V_636 ) ;
if ( V_3 & V_637 )
F_229 ( V_9 -> V_6 , V_638 ) ;
else
F_229 ( V_9 -> V_6 , V_639 ) ;
return V_39 ;
}
static enum V_25
F_230 ( struct V_8 * V_9 )
{
enum V_25 V_39 ;
V_39 = F_11 (
& V_9 -> V_6 -> V_137 -> V_114 ,
F_50 (
1 << ( 16 - V_9 -> V_7 ) ) ,
V_9 -> V_6 -> V_288 . V_305 ) ;
return V_39 ;
}
static enum V_25
F_231 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
V_3 = F_232 ( 1 << ( 16 - V_7 ) ) ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) ,
& V_6 -> V_137 -> V_640 ) ;
return V_39 ;
}
static enum V_25
F_233 ( struct V_5 * V_6 , T_3 V_7 )
{
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) & V_6 -> V_14 [ V_7 ] ;
if ( V_9 -> V_104 ) {
V_39 = F_187 ( V_9 -> V_104 ) ;
if ( V_39 != V_31 )
goto exit;
}
if ( V_9 -> V_99 )
V_39 = F_200 ( V_9 -> V_99 ) ;
exit:
return V_39 ;
}
static void
F_234 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
struct V_8 * V_9 ;
struct V_251 * V_252 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_252 = V_9 -> V_252 ;
if ( V_252 -> V_290 . V_291 == V_641 )
return;
V_3 = F_2 ( & V_2 -> V_642 ) ;
V_3 |= V_643 ;
F_4 ( V_3 , & V_2 -> V_642 ) ;
V_3 = F_2 ( & V_9 -> V_2 -> V_15 ) ;
V_3 |= V_644 ;
F_4 ( V_3 , & V_9 -> V_2 -> V_15 ) ;
V_3 = F_2 ( & V_2 -> V_645 ) ;
if ( V_9 -> V_252 -> V_290 . V_499 !=
V_500 ) {
V_3 &= ~ F_235 ( 0x3 ) ;
switch ( V_9 -> V_252 -> V_290 . V_499 ) {
case V_646 :
V_3 |= F_235 (
V_647 ) ;
break;
case V_648 :
V_3 |= F_235 (
V_649 ) ;
break;
case V_650 :
V_3 |= F_235 (
V_651 ) ;
break;
}
}
F_4 ( V_3 , & V_2 -> V_645 ) ;
F_4 ( F_236 (
F_160 (
V_9 -> V_104 ) >> 3 ) , & V_2 -> V_652 ) ;
V_3 = F_2 ( & V_2 -> V_653 ) ;
V_3 |= V_654 ;
V_3 &= ~ F_237 ( 0x3 ) ;
V_3 |= F_237 (
V_655 ) ;
if ( V_6 -> V_288 . V_490 == V_656 )
V_3 |= V_657 ;
else
V_3 &= ~ V_657 ;
F_4 ( V_3 , & V_2 -> V_653 ) ;
}
static enum V_25
F_238 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
T_2 V_658 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_39 = F_195 ( V_6 -> V_116 , V_2 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_2 -> V_659 ) ;
V_9 -> V_660 =
( T_3 ) F_239 (
V_3 + 1 ) / 2 ;
if ( V_9 -> V_252 -> V_257 . V_291 == V_294 ) {
V_9 -> V_661 = V_9 -> V_660 ;
if ( V_9 -> V_661 <
( ( V_9 -> V_252 -> V_257 . V_451 /
( V_9 -> V_252 -> V_257 . V_502 *
sizeof( struct V_556 ) ) ) *
V_9 -> V_252 -> V_257 . V_247 ) ) {
return V_250 ;
}
V_3 = F_240 (
( V_9 -> V_661 * 2 ) - 1 ) ;
}
F_4 ( V_3 , & V_2 -> V_662 ) ;
F_4 ( V_663 ,
& V_2 -> V_664 ) ;
V_3 = F_2 ( & V_2 -> V_665 ) ;
V_3 &= ~ ( F_241 ( 0x3 ) |
F_242 ( 0xFF ) ) ;
V_3 |= F_241 (
V_666 ) |
#ifndef F_194
V_667 |
#endif
F_242 ( 0 ) ;
F_4 ( V_3 , & V_2 -> V_665 ) ;
F_4 ( ( T_2 ) 0 , & V_2 -> V_668 ) ;
F_16 () ;
V_658 = F_2 ( & V_6 -> V_135 -> V_669 ) ;
V_9 -> V_568 =
(struct V_670 T_1 * )
( V_6 -> V_150 + ( V_7 *
F_243 (
V_658 ) ) ) ;
exit:
return V_39 ;
}
static enum V_25
F_244 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_251 * V_252 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_252 = V_9 -> V_252 ;
F_4 ( F_245 (
V_9 -> V_635 ) , & V_2 -> V_671 ) ;
if ( V_252 -> V_290 . V_291 == V_292 ) {
V_3 = F_2 ( & V_2 -> V_672 ) ;
if ( V_252 -> V_263 !=
V_264 ) {
if ( V_252 -> V_263 )
V_3 |= V_673 ;
else
V_3 &= ~ V_673 ;
}
F_4 ( V_3 , & V_2 -> V_672 ) ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_252 -> V_258 !=
V_259 ) {
V_3 &= ~ F_3 ( 0x3fff ) ;
if ( ( V_252 -> V_258 +
V_633 ) < V_9 -> V_632 )
V_3 |= F_3 (
V_252 -> V_258 +
V_633 ) ;
else
V_3 |= F_3 (
V_9 -> V_632 ) ;
}
F_4 ( V_3 , & V_2 -> V_4 ) ;
V_3 = F_2 ( & V_2 -> V_674 ) ;
V_3 &= ~ ( F_246 ( 0x3 ) |
V_675 ) ;
if ( V_6 -> V_288 . V_492 ==
V_676 ) {
V_3 |= F_246 (
0x2 ) |
V_675 ;
}
F_4 ( V_3 , & V_2 -> V_674 ) ;
}
return V_39 ;
}
static enum V_25
F_247 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
struct V_251 * V_288 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_288 = V_9 -> V_252 ;
F_4 ( 0 , & V_2 -> V_677 ) ;
F_4 ( 0 , & V_2 -> V_678 ) ;
F_4 ( 0 , & V_2 -> V_679 ) ;
F_4 ( 0 , & V_2 -> V_680 ) ;
if ( V_288 -> V_290 . V_291 == V_292 )
F_4 ( F_248 (
( V_7 * V_681 ) +
V_682 ) , & V_2 -> V_683 ) ;
V_3 = F_2 ( & V_2 -> V_684 ) ;
V_3 |= V_685 ;
F_4 ( V_3 , & V_2 -> V_684 ) ;
if ( V_288 -> V_257 . V_291 == V_294 ) {
V_3 = F_2 ( & V_2 -> V_686 [ V_687 ] ) ;
if ( V_288 -> V_511 . V_514 != V_515 ) {
V_3 &= ~ F_249 (
0x3ffffff ) ;
V_3 |= F_249 (
V_288 -> V_511 . V_514 ) ;
}
V_3 &= ~ V_688 ;
if ( V_288 -> V_511 . V_516 != V_515 ) {
if ( V_288 -> V_511 . V_516 )
V_3 |= V_689 ;
else
V_3 &= ~ V_689 ;
}
if ( V_288 -> V_511 . V_517 != V_515 ) {
if ( V_288 -> V_511 . V_517 )
V_3 |= V_690 ;
else
V_3 &= ~ V_690 ;
}
if ( V_288 -> V_511 . V_522 != V_515 ) {
V_3 &= ~ F_250 ( 0x3f ) ;
V_3 |= F_250 (
V_288 -> V_511 . V_522 ) ;
}
if ( V_288 -> V_511 . V_524 != V_515 ) {
V_3 &= ~ F_251 ( 0x3f ) ;
V_3 |= F_251 (
V_288 -> V_511 . V_524 ) ;
}
if ( V_288 -> V_511 . V_526 != V_515 ) {
V_3 &= ~ F_252 ( 0x3f ) ;
V_3 |= F_252 (
V_288 -> V_511 . V_526 ) ;
}
F_4 ( V_3 , & V_2 -> V_686 [ V_687 ] ) ;
V_9 -> V_572 = V_3 ;
V_3 = F_2 ( & V_2 -> V_691 [ V_687 ] ) ;
if ( V_288 -> V_511 . V_523 != V_515 ) {
V_3 &= ~ F_253 ( 0xffff ) ;
V_3 |= F_253 (
V_288 -> V_511 . V_523 ) ;
}
if ( V_288 -> V_511 . V_525 != V_515 ) {
V_3 &= ~ F_254 ( 0xffff ) ;
V_3 |= F_254 (
V_288 -> V_511 . V_525 ) ;
}
if ( V_288 -> V_511 . V_527 != V_515 ) {
V_3 &= ~ F_255 ( 0xffff ) ;
V_3 |= F_255 (
V_288 -> V_511 . V_527 ) ;
}
if ( V_288 -> V_511 . V_528 != V_515 ) {
V_3 &= ~ F_256 ( 0xffff ) ;
V_3 |= F_256 (
V_288 -> V_511 . V_528 ) ;
}
F_4 ( V_3 , & V_2 -> V_691 [ V_687 ] ) ;
V_3 = F_2 ( & V_2 -> V_692 [ V_687 ] ) ;
if ( V_288 -> V_511 . V_518 != V_515 ) {
if ( V_288 -> V_511 . V_518 )
V_3 |= V_693 ;
else
V_3 &= ~ V_693 ;
}
if ( V_288 -> V_511 . V_519 != V_515 ) {
V_3 &= ~ F_257 (
0x3ffffff ) ;
V_3 |= F_257 (
V_288 -> V_511 . V_519 ) ;
}
if ( V_288 -> V_511 . V_520 != V_515 ) {
V_3 &= ~ F_258 ( 0x3f ) ;
V_3 |= F_258 ( V_7 ) ;
}
if ( V_288 -> V_511 . V_521 != V_515 ) {
V_3 &= ~ F_259 (
0x3ffffff ) ;
V_3 |= F_259 (
V_288 -> V_511 . V_521 ) ;
}
F_4 ( V_3 , & V_2 -> V_692 [ V_687 ] ) ;
V_9 -> V_573 = V_3 ;
}
if ( V_288 -> V_290 . V_291 == V_292 ) {
V_3 = F_2 ( & V_2 -> V_686 [ V_682 ] ) ;
if ( V_288 -> V_529 . V_514 != V_515 ) {
V_3 &= ~ F_249 (
0x3ffffff ) ;
V_3 |= F_249 (
V_288 -> V_529 . V_514 ) ;
}
V_3 &= ~ V_688 ;
if ( V_288 -> V_529 . V_516 != V_515 ) {
if ( V_288 -> V_529 . V_516 )
V_3 |= V_689 ;
else
V_3 &= ~ V_689 ;
}
if ( V_288 -> V_529 . V_517 != V_515 ) {
if ( V_288 -> V_529 . V_517 )
V_3 |= V_690 ;
else
V_3 &= ~ V_690 ;
}
if ( V_288 -> V_529 . V_522 != V_515 ) {
V_3 &= ~ F_250 ( 0x3f ) ;
V_3 |= F_250 (
V_288 -> V_529 . V_522 ) ;
}
if ( V_288 -> V_529 . V_524 != V_515 ) {
V_3 &= ~ F_251 ( 0x3f ) ;
V_3 |= F_251 (
V_288 -> V_529 . V_524 ) ;
}
if ( V_288 -> V_529 . V_526 != V_515 ) {
V_3 &= ~ F_252 ( 0x3f ) ;
V_3 |= F_252 (
V_288 -> V_529 . V_526 ) ;
}
F_4 ( V_3 , & V_2 -> V_686 [ V_682 ] ) ;
V_9 -> V_481 = V_3 ;
V_3 = F_2 ( & V_2 -> V_691 [ V_682 ] ) ;
if ( V_288 -> V_529 . V_523 != V_515 ) {
V_3 &= ~ F_253 ( 0xffff ) ;
V_3 |= F_253 (
V_288 -> V_529 . V_523 ) ;
}
if ( V_288 -> V_529 . V_525 != V_515 ) {
V_3 &= ~ F_254 ( 0xffff ) ;
V_3 |= F_254 (
V_288 -> V_529 . V_525 ) ;
}
if ( V_288 -> V_529 . V_527 != V_515 ) {
V_3 &= ~ F_255 ( 0xffff ) ;
V_3 |= F_255 (
V_288 -> V_529 . V_527 ) ;
}
if ( V_288 -> V_529 . V_528 != V_515 ) {
V_3 &= ~ F_256 ( 0xffff ) ;
V_3 |= F_256 (
V_288 -> V_529 . V_528 ) ;
}
F_4 ( V_3 , & V_2 -> V_691 [ V_682 ] ) ;
V_3 = F_2 ( & V_2 -> V_692 [ V_682 ] ) ;
if ( V_288 -> V_529 . V_518 != V_515 ) {
if ( V_288 -> V_529 . V_518 )
V_3 |= V_693 ;
else
V_3 &= ~ V_693 ;
}
if ( V_288 -> V_529 . V_519 != V_515 ) {
V_3 &= ~ F_257 (
0x3ffffff ) ;
V_3 |= F_257 (
V_288 -> V_529 . V_519 ) ;
}
if ( V_288 -> V_529 . V_520 != V_515 ) {
V_3 &= ~ F_258 ( 0x3f ) ;
V_3 |= F_258 ( V_7 ) ;
}
if ( V_288 -> V_529 . V_521 != V_515 ) {
V_3 &= ~ F_259 (
0x3ffffff ) ;
V_3 |= F_259 (
V_288 -> V_529 . V_521 ) ;
}
F_4 ( V_3 , & V_2 -> V_692 [ V_682 ] ) ;
V_9 -> V_482 = V_3 ;
}
V_3 = 0 ;
F_4 ( V_3 , & V_2 -> V_686 [ V_694 ] ) ;
F_4 ( V_3 , & V_2 -> V_691 [ V_694 ] ) ;
F_4 ( V_3 , & V_2 -> V_692 [ V_694 ] ) ;
F_4 ( V_3 , & V_2 -> V_686 [ V_695 ] ) ;
F_4 ( V_3 , & V_2 -> V_691 [ V_695 ] ) ;
F_4 ( V_3 , & V_2 -> V_692 [ V_695 ] ) ;
V_3 = F_260 ( 150 ) ;
V_3 |= F_261 ( 0 ) ;
V_3 |= F_262 ( 3 ) ;
F_4 ( V_3 , & V_2 -> V_696 ) ;
return V_39 ;
}
static enum V_25
F_263 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
T_3 V_697 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( ! ( V_6 -> V_169 & F_10 ( V_7 ) ) ) {
V_39 = V_698 ;
goto exit;
}
V_2 = V_9 -> V_2 ;
V_39 = F_193 ( V_9 -> V_2 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_244 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_238 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_247 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_3 = F_2 ( & V_2 -> V_699 ) ;
V_39 = F_204 ( V_9 , 1 , 0x78 , & V_697 ) ;
if ( V_39 == V_31 ) {
V_697 = ( V_697 & V_700 ) >> 12 ;
V_3 &=
~ ( F_264 ( 7 ) ) ;
V_3 |=
F_264 ( V_697 ) ;
V_3 |= V_701 ;
}
V_3 &= ~ ( F_265 ( 7 ) ) ;
V_3 |=
F_265 (
V_702 ) ;
V_3 |= V_703 ;
F_4 ( V_3 , & V_2 -> V_699 ) ;
exit:
return V_39 ;
}
static void F_266 ( struct V_5 * V_6 , T_3 V_7 )
{
struct V_8 * V_9 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( V_9 -> V_43 == V_170 )
goto exit;
F_267 ( V_9 -> V_6 -> V_704 ,
V_9 -> V_6 -> V_705 , V_9 -> V_7 ) ;
V_6 -> V_101 . V_361 . V_706 [ V_9 -> V_7 ] = NULL ;
F_19 ( & V_9 -> V_42 ) ;
V_9 -> V_43 = V_170 ;
F_20 ( & V_9 -> V_42 ) ;
V_9 -> V_145 = NULL ;
V_9 -> V_568 = NULL ;
V_9 -> V_632 = 0 ;
V_9 -> V_635 = 0 ;
V_9 -> V_660 = 0 ;
V_9 -> V_661 = 0 ;
V_9 -> V_104 = NULL ;
V_9 -> V_99 = NULL ;
memset ( & V_9 -> V_623 , 0 , sizeof( struct V_224 ) ) ;
V_9 -> V_707 = 0 ;
V_9 -> V_315 = NULL ;
V_9 -> V_360 = NULL ;
V_9 -> V_363 = NULL ;
exit:
return;
}
static enum V_25
F_268 ( struct V_5 * V_6 , T_3 V_7 ,
struct V_251 * V_288 )
{
struct V_8 * V_9 ;
enum V_25 V_39 = V_31 ;
if ( ! ( V_6 -> V_169 & F_10 ( V_7 ) ) ) {
V_39 = V_698 ;
goto exit;
}
V_9 = & V_6 -> V_14 [ V_7 ] ;
F_83 ( & V_9 -> V_42 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_43 = V_708 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_252 = V_288 ;
V_9 -> V_2 = V_6 -> V_148 [ V_7 ] ;
V_9 -> V_145 = V_6 -> V_145 [ V_7 ] ;
F_231 ( V_6 , V_7 ) ;
V_39 = F_230 ( V_9 ) ;
if ( V_39 != V_31 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
goto exit;
}
V_39 = F_227 ( V_6 , V_9 ) ;
if ( V_39 != V_31 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
goto exit;
}
F_90 ( & V_9 -> V_623 ) ;
V_9 -> V_363 = & V_6 -> V_101 . V_364 . V_706 [ V_7 ] ;
F_269 ( V_6 -> V_704 ,
V_6 -> V_705 , V_7 ) ;
V_39 = F_263 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
F_266 ( V_6 , V_7 ) ;
exit:
return V_39 ;
}
enum V_25
F_270 ( struct V_432 * V_472 , T_3 V_709 )
{
T_2 V_3 ;
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
if ( V_472 == NULL ) {
V_39 = V_566 ;
goto exit;
}
V_9 = V_472 -> V_9 ;
V_709 += V_633 ;
if ( ( V_709 < V_710 ) || ( V_709 > V_9 -> V_632 ) )
V_39 = V_711 ;
V_3 = F_2 ( & V_9 -> V_2 -> V_4 ) ;
V_3 &= ~ F_3 ( 0x3fff ) ;
V_3 |= F_3 ( V_709 ) ;
F_4 ( V_3 , & V_9 -> V_2 -> V_4 ) ;
V_9 -> V_252 -> V_258 = V_709 - V_633 ;
exit:
return V_39 ;
}
static enum V_25
F_271 ( struct V_432 * V_472 )
{
enum V_25 V_39 = V_31 ;
struct V_8 * V_9 ;
V_9 = V_472 -> V_9 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto exit;
}
memcpy ( V_9 -> V_360 , V_9 -> V_315 ,
sizeof( struct V_314 ) ) ;
V_39 = F_113 ( V_9 , V_9 -> V_315 ) ;
exit:
return V_39 ;
}
static struct V_227 *
F_272 ( struct V_5 * V_280 , T_3 V_61 )
{
struct V_227 * V_235 = NULL ;
struct V_222 * V_223 ;
V_223 = & V_280 -> V_295 ;
if ( V_61 == V_223 -> V_238 ) {
if ( ! F_97 ( & V_223 -> V_241 ) )
V_235 = (struct V_227 * )
F_98 ( & V_223 -> V_241 ,
struct V_227 ,
V_232 ) ;
if ( V_235 != NULL ) {
F_88 ( & V_235 -> V_232 ) ;
V_223 -> V_233 -- ;
}
}
if ( V_235 != NULL )
F_176 ( V_223 ) ;
return V_235 ;
}
enum V_25
F_273 ( struct V_5 * V_6 ,
struct V_712 * V_282 ,
struct V_432 * * V_713 )
{
struct V_8 * V_9 ;
struct V_432 * V_472 ;
enum V_25 V_39 ;
V_9 = & V_6 -> V_14 [ V_282 -> V_7 ] ;
if ( V_9 -> V_43 == V_708 ) {
V_39 = V_714 ;
goto V_715;
}
V_39 = F_268 ( V_6 , V_282 -> V_7 ,
& V_6 -> V_288 . V_252 [ V_282 -> V_7 ] ) ;
if ( V_39 != V_31 )
goto V_715;
V_472 = F_103 ( sizeof( struct V_432 ) ) ;
if ( V_472 == NULL ) {
V_39 = V_244 ;
goto V_716;
}
V_472 -> V_9 = V_9 ;
if ( V_9 -> V_252 -> V_257 . V_291 == V_294 ) {
V_39 = F_203 ( V_472 , & V_282 -> V_717 ) ;
if ( V_39 != V_31 )
goto V_718;
}
if ( V_9 -> V_252 -> V_290 . V_291 == V_292 ) {
V_39 = F_189 ( V_472 , & V_282 -> V_719 ) ;
if ( V_39 != V_31 )
goto V_720;
F_234 ( V_6 , V_282 -> V_7 ) ;
}
V_9 -> V_99 -> V_721 =
( V_282 -> V_7 * V_681 ) +
V_687 ;
V_9 -> V_707 = F_272 ( V_6 ,
V_239 ) ;
if ( V_9 -> V_707 == NULL ) {
V_39 = V_244 ;
goto V_722;
}
V_9 -> V_315 = V_9 -> V_707 -> V_230 ;
memset ( V_9 -> V_315 , 0 ,
sizeof( struct V_314 ) ) ;
V_6 -> V_101 . V_361 . V_706 [ V_282 -> V_7 ] =
V_9 -> V_315 ;
V_9 -> V_360 =
& V_6 -> V_101 . V_361 . V_723 [ V_282 -> V_7 ] ;
memset ( V_9 -> V_360 , 0 ,
sizeof( struct V_314 ) ) ;
F_4 ( V_9 -> V_707 -> V_228 , & V_9 -> V_2 -> V_724 ) ;
V_39 = F_271 ( V_472 ) ;
if ( V_39 != V_31 )
goto V_722;
F_92 ( & V_472 -> V_232 , & V_9 -> V_623 ) ;
V_6 -> V_24 |= F_10 ( V_9 -> V_7 ) ;
* V_713 = V_472 ;
V_282 -> V_717 . V_418 = V_9 -> V_99 ;
V_282 -> V_719 . V_418 = V_9 -> V_104 ;
return V_31 ;
V_722:
if ( V_9 -> V_104 != NULL )
F_188 ( V_472 ) ;
V_720:
if ( V_9 -> V_99 != NULL )
F_201 ( V_472 ) ;
V_718:
F_105 ( V_472 ) ;
V_716:
F_266 ( V_6 , V_282 -> V_7 ) ;
V_715:
return V_39 ;
}
void F_274 ( struct V_432 * V_472 )
{
struct V_8 * V_9 = V_472 -> V_9 ;
struct V_105 * V_290 = V_9 -> V_104 ;
struct V_725 * V_726 = F_275 ( V_9 -> V_6 -> V_727 ) ;
T_2 V_728 , V_3 , V_729 ;
if ( V_726 -> V_730 ) {
V_728 = F_2 ( & V_9 -> V_2 -> V_731 ) ;
V_728 &= 0x1fff ;
} else
V_728 = V_290 -> V_288 -> V_293 * V_239 / 8 ;
V_729 = F_276 ( V_728 ) ;
F_4 ( F_277 ( V_729 ) ,
& V_9 -> V_2 -> V_16 ) ;
F_225 ( & V_9 -> V_2 -> V_16 ) ;
V_729 /= 2 ;
V_3 = F_2 ( & V_9 -> V_2 -> V_15 ) ;
V_3 = F_226 ( V_3 ) ;
V_3 &= 0x1ff ;
V_728 -= ( V_3 + 1 ) ;
V_3 = F_278 ( V_729 , V_728 ) / 4 ;
V_290 -> V_483 = F_278 ( V_290 -> V_483 , V_3 ) ;
if ( V_290 -> V_483 < 4 )
V_290 -> V_483 = 4 ;
}
static void
F_279 ( struct V_5 * V_280 ,
struct V_227 * V_235 )
{
struct V_222 * V_223 ;
V_223 = & V_280 -> V_295 ;
if ( V_235 -> V_97 == V_223 -> V_238 ) {
F_92 ( & V_235 -> V_232 , & V_223 -> V_241 ) ;
V_223 -> V_233 ++ ;
}
F_178 ( V_223 ) ;
}
enum V_25 F_280 ( struct V_432 * V_472 )
{
struct V_8 * V_9 = NULL ;
struct V_5 * V_280 = NULL ;
T_3 V_7 = V_472 -> V_9 -> V_7 ;
T_3 V_732 = TRUE ;
enum V_25 V_39 = V_31 ;
V_9 = V_472 -> V_9 ;
V_280 = V_9 -> V_6 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto V_733;
}
F_88 ( & V_472 -> V_232 ) ;
if ( ! F_97 ( & V_9 -> V_623 ) ) {
F_92 ( & V_472 -> V_232 , & V_9 -> V_623 ) ;
V_732 = FALSE ;
}
if ( ! V_732 ) {
V_39 = V_30 ;
goto V_733;
}
V_280 -> V_24 &= ~ F_10 ( V_7 ) ;
if ( V_9 -> V_104 != NULL )
F_188 ( V_472 ) ;
if ( V_9 -> V_99 != NULL )
F_201 ( V_472 ) ;
if ( V_9 -> V_707 != NULL )
F_279 ( V_280 , V_9 -> V_707 ) ;
F_105 ( V_472 ) ;
F_266 ( V_280 , V_7 ) ;
V_733:
return V_39 ;
}
enum V_25 F_281 ( struct V_432 * V_472 )
{
enum V_25 V_39 ;
T_3 V_7 ;
struct V_8 * V_9 = V_472 -> V_9 ;
V_7 = V_9 -> V_7 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto exit;
}
V_39 = F_231 ( V_9 -> V_6 , V_7 ) ;
if ( V_39 == V_31 )
V_9 -> V_363 -> V_734 ++ ;
exit:
return V_39 ;
}
enum V_25
F_282 ( struct V_432 * V_472 )
{
struct V_8 * V_9 = NULL ;
enum V_25 V_39 ;
struct V_5 * V_6 ;
T_3 V_7 ;
V_7 = V_472 -> V_9 -> V_7 ;
V_9 = V_472 -> V_9 ;
V_6 = V_9 -> V_6 ;
if ( V_9 -> V_43 == V_170 ) {
V_39 = V_301 ;
goto exit;
}
V_39 = F_230 ( V_9 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_233 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
V_39 = F_263 ( V_6 , V_7 ) ;
if ( V_39 != V_31 )
goto exit;
if ( V_9 -> V_104 != NULL )
F_234 ( V_6 , V_7 ) ;
memset ( V_9 -> V_315 , 0 ,
sizeof( struct V_314 ) ) ;
memset ( V_9 -> V_360 , 0 ,
sizeof( struct V_314 ) ) ;
F_4 ( V_9 -> V_707 -> V_228 ,
& V_9 -> V_2 -> V_724 ) ;
V_39 = F_271 ( V_472 ) ;
exit:
return V_39 ;
}
void
F_283 ( struct V_432 * V_472 )
{
struct V_5 * V_6 ;
T_2 V_3 ;
V_6 = V_472 -> V_9 -> V_6 ;
V_3 = F_284 (
1 << ( 16 - V_472 -> V_9 -> V_7 ) ) ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) ,
& V_6 -> V_137 -> V_735 ) ;
}
