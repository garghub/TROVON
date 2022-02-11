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
F_12 ( 10 ) ;
do {
V_3 = F_2 ( V_26 ) ;
if ( ! ( V_3 & V_27 ) )
return V_29 ;
F_12 ( 100 ) ;
} while ( ++ V_22 <= 9 );
V_22 = 0 ;
do {
V_3 = F_2 ( V_26 ) ;
if ( ! ( V_3 & V_27 ) )
return V_29 ;
F_7 ( 1 ) ;
} while ( ++ V_22 <= V_28 );
return V_30 ;
}
static inline enum V_25
F_13 ( T_2 V_3 , void T_1 * V_31 ,
T_2 V_27 , T_3 V_28 )
{
F_14 ( ( T_3 ) F_15 ( V_3 , 32 , 32 ) , V_31 ) ;
F_16 () ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) , V_31 ) ;
F_16 () ;
return F_11 ( V_31 , V_27 , V_28 ) ;
}
static enum V_25
F_18 ( struct V_8 * V_9 , T_3 V_32 ,
T_3 V_33 , T_3 V_34 , T_2 * V_35 , T_2 * V_36 ,
T_2 * V_37 )
{
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
enum V_25 V_38 ;
T_2 V_3 ;
T_3 V_39 = 0 , V_40 = 3 ;
F_19 ( & V_9 -> V_41 ) ;
if ( ! V_9 -> V_42 ) {
F_20 ( & V_9 -> V_41 ) ;
V_40 = 100 ;
}
F_4 ( * V_35 , & V_2 -> V_43 ) ;
F_4 ( * V_36 , & V_2 -> V_44 ) ;
F_16 () ;
V_3 = F_21 ( V_32 ) |
F_22 ( V_33 ) |
F_23 ( V_34 ) |
V_45 |
* V_37 ;
V_38 = F_13 ( V_3 ,
& V_2 -> V_46 ,
V_45 ,
V_47 ) ;
while ( ( V_38 != V_29 ) && V_39 ++ < V_40 ) {
if ( ! V_9 -> V_42 )
F_24 ( 20 ) ;
V_38 = F_11 (
& V_2 -> V_46 ,
V_45 ,
V_47 ) ;
}
if ( V_38 != V_29 )
goto V_48;
V_3 = F_2 ( & V_2 -> V_46 ) ;
if ( V_3 & V_49 ) {
* V_35 = F_2 ( & V_2 -> V_43 ) ;
* V_36 = F_2 ( & V_2 -> V_44 ) ;
* V_37 = V_3 ;
} else
V_38 = V_30 ;
V_48:
if ( V_9 -> V_42 )
F_20 ( & V_9 -> V_41 ) ;
return V_38 ;
}
enum V_25
F_25 ( struct V_5 * V_6 , T_3 * V_50 ,
T_3 * V_51 , T_3 * V_52 )
{
T_2 V_35 = 0 , V_36 = 0 , V_37 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_38 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_53 ] ;
V_38 = F_18 ( V_9 ,
V_54 ,
V_55 ,
V_56 ,
& V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
return V_38 ;
* V_50 = F_26 ( V_35 ) ;
* V_51 = F_27 ( V_35 ) ;
* V_52 = F_28 ( V_35 ) ;
return V_38 ;
}
enum V_25 F_29 ( struct V_5 * V_6 )
{
T_2 V_35 = 0 , V_36 = 0 , V_37 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_38 ;
T_3 V_57 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_53 ] ;
V_38 = F_18 ( V_9 ,
V_54 ,
V_55 ,
V_58 ,
& V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 ) {
F_30 ( V_59 , L_2 , V_21 ) ;
goto exit;
}
V_57 = F_31 ( V_37 ) & 0x7F ;
if ( V_57 != 1 ) {
F_30 ( V_59 , L_3 ,
V_21 , V_57 ) ;
V_38 = V_30 ;
}
exit:
return V_38 ;
}
enum V_25
F_32 ( struct V_5 * V_6 , const T_4 * V_60 , int V_61 )
{
T_2 V_35 = 0 , V_36 = 0 , V_37 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_38 ;
int V_62 , V_63 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_53 ] ;
V_38 = F_18 ( V_9 ,
V_54 ,
V_55 ,
V_64 ,
& V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 ) {
F_30 ( V_59 , L_4 ,
V_21 ) ;
return V_38 ;
}
for (; V_61 > 0 ; V_61 -= V_65 ) {
V_37 = 0 ;
V_35 = * ( ( T_2 * ) V_60 ) ;
V_36 = * ( ( T_2 * ) V_60 + 1 ) ;
V_38 = F_18 ( V_9 ,
V_54 ,
V_55 ,
V_66 ,
& V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 ) {
F_30 ( V_59 , L_5 ,
V_21 ) ;
goto V_48;
}
V_62 = F_33 ( V_35 ) ;
switch ( V_62 ) {
case V_67 :
break;
case V_68 :
V_60 += ( V_35 >> 8 ) & 0xFFFFFFFF ;
break;
case V_69 :
goto V_48;
case V_70 :
V_63 = F_34 ( V_35 ) ;
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
V_38 = V_30 ;
goto V_48;
default:
F_8 ( V_73 L_12 , V_62 ) ;
V_38 = V_30 ;
goto V_48;
}
V_60 += V_65 ;
}
V_48:
return V_38 ;
}
enum V_25
F_35 ( struct V_5 * V_6 ,
struct V_82 * V_83 )
{
T_2 V_35 = 0 , V_36 = 0 , V_37 = 0 ;
struct V_8 * V_9 ;
enum V_25 V_38 ;
int V_22 ;
V_9 = & V_6 -> V_14 [ V_6 -> V_53 ] ;
for ( V_22 = 0 ; V_22 < V_84 ; V_22 ++ ) {
V_35 = F_36 ( V_22 ) ;
V_36 = V_37 = 0 ;
V_38 = F_18 ( V_9 ,
V_85 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
break;
V_83 [ V_22 ] . V_87 = F_37 ( V_35 ) ;
V_83 [ V_22 ] . V_88 = F_38 ( V_35 ) ;
V_83 [ V_22 ] . type = F_39 ( V_35 ) ;
V_83 [ V_22 ] . V_89 = F_40 ( V_35 ) ;
}
return V_38 ;
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
return V_29 ;
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
return V_29 ;
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
enum V_25 V_38 ;
V_38 = F_11 ( V_114 ,
F_50 ( 0x1ffff ) ,
V_47 ) ;
return V_38 ;
}
static enum V_25
F_51 ( struct V_115 T_1 * V_116 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
V_3 = F_2 ( & V_116 -> V_117 ) ;
F_16 () ;
switch ( V_3 ) {
case V_118 :
return V_38 ;
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
V_38 = V_130 ;
return V_38 ;
}
static struct V_131 T_1 *
F_52 ( void T_1 * V_132 )
{
T_2 V_3 ;
struct V_131 T_1 * V_133 = NULL ;
enum V_25 V_38 ;
struct V_115 T_1 * V_116 =
(struct V_115 T_1 * ) V_132 ;
V_38 = F_51 ( V_116 ) ;
if ( V_38 != V_29 )
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
enum V_25 V_38 = V_29 ;
V_6 -> V_116 = V_6 -> V_132 ;
V_6 -> V_135 = F_52 ( V_6 -> V_132 ) ;
if ( V_6 -> V_135 == NULL ) {
V_38 = V_30 ;
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
V_38 = F_49 (
( T_2 T_1 * ) & V_6 -> V_137 -> V_114 ) ;
exit:
return V_38 ;
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
return V_29 ;
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
V_6 -> V_14 [ V_22 ] . V_42 = V_170 ;
V_6 -> V_14 [ V_22 ] . V_2 = V_6 -> V_148 [ V_22 ] ;
V_6 -> V_53 = V_22 ;
break;
}
}
static enum V_25
F_62 ( struct V_5 * V_6 )
{
struct V_171 * V_172 = V_6 -> V_112 ;
T_5 V_173 ;
F_63 ( V_172 , V_174 , & V_173 ) ;
if ( ( V_173 & V_175 ) != 1 )
return V_176 ;
switch ( ( V_173 & V_177 ) >> 4 ) {
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
break;
default:
return V_176 ;
}
return V_29 ;
}
static enum V_25
F_64 ( struct V_5 * V_6 )
{
enum V_25 V_38 = V_29 ;
if ( V_29 == F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ) {
V_38 = F_62 ( V_6 ) ;
if ( V_38 != V_29 )
goto exit;
}
exit:
return V_38 ;
}
static enum V_25
F_65 ( struct V_8 * V_9 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 = & V_184 -> V_186 ;
struct V_187 * V_188 = & V_184 -> V_188 ;
struct V_185 * V_189 = & V_184 -> V_189 ;
struct V_187 * V_190 = & V_184 -> V_190 ;
T_2 V_35 , V_36 = 0 , V_37 = 0 ;
enum V_25 V_38 ;
V_38 = F_18 ( V_9 ,
V_191 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
goto exit;
V_188 -> V_192 =
( T_3 ) F_66 ( V_35 ) ;
V_188 -> V_193 =
( T_3 ) F_67 ( V_35 ) ;
V_188 -> V_194 =
( T_3 ) F_68 ( V_35 ) ;
snprintf ( V_188 -> V_195 , V_196 , L_13 ,
V_188 -> V_193 , V_188 -> V_192 , V_188 -> V_194 ) ;
V_186 -> V_50 =
( T_3 ) F_26 ( V_35 ) ;
V_186 -> V_51 =
( T_3 ) F_27 ( V_35 ) ;
V_186 -> V_52 =
( T_3 ) F_28 ( V_35 ) ;
snprintf ( V_186 -> V_89 , V_196 , L_14 ,
V_186 -> V_50 , V_186 -> V_51 , V_186 -> V_52 ) ;
V_190 -> V_192 =
( T_3 ) F_69 ( V_36 ) ;
V_190 -> V_193 =
( T_3 ) F_70 ( V_36 ) ;
V_190 -> V_194 =
( T_3 ) F_71 ( V_36 ) ;
snprintf ( V_190 -> V_195 , V_196 , L_13 ,
V_190 -> V_193 , V_190 -> V_192 , V_190 -> V_194 ) ;
V_189 -> V_50 =
( T_3 ) F_72 ( V_36 ) ;
V_189 -> V_51 =
( T_3 ) F_73 ( V_36 ) ;
V_189 -> V_52 =
( T_3 ) F_74 ( V_36 ) ;
snprintf ( V_189 -> V_89 , V_196 , L_14 ,
V_189 -> V_50 , V_189 -> V_51 ,
V_189 -> V_52 ) ;
exit:
return V_38 ;
}
static enum V_25
F_75 ( struct V_8 * V_9 ,
struct V_183 * V_184 )
{
enum V_25 V_38 ;
T_2 V_35 , V_36 = 0 , V_37 = 0 ;
T_4 * V_197 = V_184 -> V_197 ;
T_4 * V_198 = V_184 -> V_198 ;
T_4 * V_199 = V_184 -> V_199 ;
T_3 V_22 , V_200 = 0 ;
V_35 = V_201 ;
V_38 = F_18 ( V_9 ,
V_202 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
return V_38 ;
( ( T_2 * ) V_197 ) [ 0 ] = F_76 ( V_35 ) ;
( ( T_2 * ) V_197 ) [ 1 ] = F_76 ( V_36 ) ;
V_35 = V_203 ;
V_36 = V_37 = 0 ;
V_38 = F_18 ( V_9 ,
V_202 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
return V_38 ;
( ( T_2 * ) V_198 ) [ 0 ] = F_76 ( V_35 ) ;
( ( T_2 * ) V_198 ) [ 1 ] = F_76 ( V_36 ) ;
for ( V_22 = V_204 ;
V_22 <= V_205 ; V_22 ++ ) {
V_35 = V_22 ;
V_36 = V_37 = 0 ;
V_38 = F_18 ( V_9 ,
V_202 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
return V_38 ;
( ( T_2 * ) V_199 ) [ V_200 ++ ] = F_76 ( V_35 ) ;
( ( T_2 * ) V_199 ) [ V_200 ++ ] = F_76 ( V_36 ) ;
}
return V_38 ;
}
static enum V_25
F_77 ( struct V_8 * V_9 ,
struct V_183 * V_184 )
{
T_2 V_35 , V_36 = 0 , V_37 = 0 ;
enum V_25 V_38 ;
V_35 = 0 ;
V_38 = F_18 ( V_9 ,
V_206 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
return V_38 ;
V_184 -> V_207 = F_78 ( V_35 ) ;
return V_38 ;
}
static enum V_25
F_79 ( struct V_8 * V_9 ,
T_4 * V_208 , T_4 * V_209 )
{
T_2 V_32 = V_210 ,
V_35 = 0 , V_36 = 0 , V_37 = 0 ;
enum V_25 V_38 ;
int V_22 ;
do {
V_38 = F_18 ( V_9 , V_32 ,
V_211 ,
0 , & V_35 , & V_36 , & V_37 ) ;
if ( V_38 != V_29 )
goto exit;
V_35 = F_80 ( V_35 ) ;
V_36 = F_81 (
V_36 ) ;
for ( V_22 = V_212 ; V_22 > 0 ; V_22 -- ) {
V_208 [ V_22 - 1 ] = ( T_4 ) ( V_35 & 0xFF ) ;
V_35 >>= 8 ;
V_209 [ V_22 - 1 ] = ( T_4 ) ( V_36 & 0xFF ) ;
V_36 >>= 8 ;
}
V_32 = V_213 ;
V_35 = 0 , V_36 = 0 , V_37 = 0 ;
} while ( ! F_82 ( V_208 ) );
exit:
return V_38 ;
}
enum V_25
F_83 ( void T_1 * V_132 ,
struct V_183 * V_184 )
{
T_3 V_22 ;
T_2 V_3 ;
struct V_131 T_1 * V_133 ;
struct V_214 T_1 * V_139 ;
struct V_215 T_1 * V_137 ;
struct V_166 T_1 * V_145 ;
enum V_25 V_38 ;
struct V_8 V_9 ;
memset ( V_184 , 0 , sizeof( struct V_183 ) ) ;
V_133 = F_52 ( V_132 ) ;
if ( V_133 == NULL ) {
V_38 = V_216 ;
goto exit;
}
V_3 = F_2 ( & V_133 -> V_136 ) ;
V_137 = V_132 + V_3 ;
V_38 = F_49 (
( T_2 T_1 * ) & V_137 -> V_114 ) ;
if ( V_38 != V_29 )
goto exit;
V_184 -> V_217 = F_2 ( & V_137 -> V_169 ) ;
V_3 = F_2 ( & V_137 -> V_168 ) ;
V_184 -> V_151 =
( T_3 ) F_61 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_184 -> V_217 ) & F_10 ( V_22 ) ) )
continue;
V_3 = F_2 ( & V_133 -> V_144 [ V_22 ] ) ;
V_145 = V_132 + V_3 ;
V_184 -> V_152 = F_58 ( V_145 ) ;
if ( F_56 ( V_184 -> V_151 ,
V_184 -> V_152 ) &
V_156 ) {
V_3 = F_2 ( & V_133 -> V_138 ) ;
V_139 = V_132 + V_3 ;
F_4 ( 0 , & V_139 -> V_218 ) ;
F_16 () ;
}
V_3 = F_2 ( & V_133 -> V_147 [ V_22 ] ) ;
F_84 ( & V_9 . V_41 ) ;
V_9 . V_2 = V_132 + V_3 ;
V_9 . V_42 = V_170 ;
V_38 = F_77 ( & V_9 , V_184 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_65 ( & V_9 , V_184 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_75 ( & V_9 , V_184 ) ;
if ( V_38 != V_29 )
goto exit;
break;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_184 -> V_217 ) & F_10 ( V_22 ) ) )
continue;
V_3 = F_2 ( & V_133 -> V_147 [ V_22 ] ) ;
V_9 . V_2 = V_132 + V_3 ;
V_9 . V_42 = V_170 ;
V_38 = F_79 ( & V_9 ,
V_184 -> V_219 [ V_22 ] ,
V_184 -> V_220 [ V_22 ] ) ;
if ( V_38 != V_29 )
goto exit;
}
exit:
return V_38 ;
}
static void F_85 ( struct V_221 * V_222 )
{
struct V_5 * V_6 ;
struct V_223 * V_224 , * V_225 ;
T_5 V_57 ;
if ( V_222 == NULL ) {
V_57 = 1 ;
goto exit;
}
V_6 = V_222 -> V_6 ;
F_86 (p, n, &blockpool->free_block_list) {
F_87 ( V_6 -> V_112 ,
( (struct V_226 * ) V_224 ) -> V_227 ,
( (struct V_226 * ) V_224 ) -> V_97 ,
V_228 ) ;
F_88 ( V_6 -> V_112 ,
( (struct V_226 * ) V_224 ) -> V_229 ,
& ( (struct V_226 * ) V_224 ) -> V_230 ) ;
F_89 ( & ( (struct V_226 * ) V_224 ) -> V_231 ) ;
F_42 ( V_224 ) ;
V_222 -> V_232 -- ;
}
F_86 (p, n, &blockpool->free_entry_list) {
F_89 ( & ( (struct V_226 * ) V_224 ) -> V_231 ) ;
F_42 ( ( void * ) V_224 ) ;
}
V_57 = 0 ;
exit:
return;
}
static enum V_25
F_90 ( struct V_5 * V_6 ,
struct V_221 * V_222 ,
T_3 V_232 ,
T_3 V_233 )
{
T_3 V_22 ;
struct V_226 * V_234 = NULL ;
void * V_229 ;
T_6 V_227 ;
struct V_171 * V_235 ;
struct V_171 * V_230 ;
enum V_25 V_38 = V_29 ;
if ( V_222 == NULL ) {
V_38 = V_30 ;
goto V_236;
}
V_222 -> V_6 = V_6 ;
V_222 -> V_237 = V_238 ;
V_222 -> V_232 = 0 ;
V_222 -> V_233 = V_233 ;
V_222 -> V_239 = 0 ;
F_91 ( & V_222 -> V_240 ) ;
F_91 ( & V_222 -> V_241 ) ;
for ( V_22 = 0 ; V_22 < V_232 + V_233 ; V_22 ++ ) {
V_234 = F_92 ( sizeof( struct V_226 ) ,
V_242 ) ;
if ( V_234 == NULL ) {
F_85 ( V_222 ) ;
V_38 = V_243 ;
goto V_236;
}
F_93 ( & V_234 -> V_231 , & V_222 -> V_241 ) ;
}
for ( V_22 = 0 ; V_22 < V_232 ; V_22 ++ ) {
V_229 = F_94 (
V_6 -> V_112 ,
V_238 ,
& V_235 ,
& V_230 ) ;
if ( V_229 == NULL ) {
F_85 ( V_222 ) ;
V_38 = V_243 ;
goto V_236;
}
V_227 = F_95 ( V_6 -> V_112 , V_229 ,
V_238 , V_228 ) ;
if ( F_96 ( F_97 ( V_6 -> V_112 ,
V_227 ) ) ) {
F_88 ( V_6 -> V_112 , V_229 , & V_230 ) ;
F_85 ( V_222 ) ;
V_38 = V_243 ;
goto V_236;
}
if ( ! F_98 ( & V_222 -> V_241 ) )
V_234 = (struct V_226 * )
F_99 ( & V_222 -> V_241 ,
struct V_226 ,
V_231 ) ;
if ( V_234 == NULL )
V_234 =
F_92 ( sizeof( struct V_226 ) ,
V_242 ) ;
if ( V_234 != NULL ) {
F_89 ( & V_234 -> V_231 ) ;
V_234 -> V_97 = V_238 ;
V_234 -> V_229 = V_229 ;
V_234 -> V_227 = V_227 ;
V_234 -> V_230 = V_230 ;
V_234 -> V_235 = V_235 ;
F_93 ( & V_234 -> V_231 ,
& V_222 -> V_240 ) ;
V_222 -> V_232 ++ ;
} else {
F_85 ( V_222 ) ;
V_38 = V_243 ;
goto V_236;
}
}
V_236:
return V_38 ;
}
static enum V_25
F_100 ( struct V_244 * V_245 )
{
if ( ( V_245 -> V_246 < V_247 ) ||
( V_245 -> V_246 > V_248 ) )
return V_249 ;
return V_29 ;
}
static enum V_25
F_101 ( struct V_250 * V_251 )
{
enum V_25 V_38 ;
if ( ( V_251 -> V_252 < V_253 ) ||
( V_251 -> V_252 > V_254 ) )
return V_255 ;
V_38 = F_100 ( & V_251 -> V_256 ) ;
if ( V_38 != V_29 )
return V_38 ;
if ( ( V_251 -> V_257 != V_258 ) &&
( ( V_251 -> V_257 < V_259 ) ||
( V_251 -> V_257 > V_260 ) ) )
return V_261 ;
if ( ( V_251 -> V_262 !=
V_263 ) &&
( V_251 -> V_262 !=
V_264 ) &&
( V_251 -> V_262 !=
V_265 ) )
return V_266 ;
return V_29 ;
}
static enum V_25
F_102 ( struct V_267 * V_268 )
{
T_3 V_22 ;
enum V_25 V_38 ;
if ( ( V_268 -> V_269 != V_270 ) &&
( V_268 -> V_269 != V_271 ) &&
( V_268 -> V_269 != V_272 ) &&
( V_268 -> V_269 != V_273 ) )
return V_274 ;
if ( ( V_268 -> V_275 != V_276 ) &&
( V_268 -> V_275 != V_277 ) )
return V_278 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_38 = F_101 (
& V_268 -> V_251 [ V_22 ] ) ;
if ( V_38 != V_29 )
return V_38 ;
}
return V_29 ;
}
enum V_25
F_103 (
struct V_5 * * V_279 ,
struct V_280 * V_281 ,
struct V_267 * V_282 )
{
T_3 V_22 ;
T_3 V_283 = 0 ;
struct V_5 * V_6 = NULL ;
enum V_25 V_38 = V_29 ;
V_38 = F_102 ( V_282 ) ;
if ( V_38 != V_29 )
goto exit;
V_6 = F_104 ( sizeof( struct V_5 ) ) ;
if ( V_6 == NULL ) {
V_38 = V_243 ;
goto exit;
}
V_6 -> V_284 = V_285 ;
F_105 ( V_6 , V_59 , V_286 ) ;
memcpy ( & V_6 -> V_287 , V_282 ,
sizeof( struct V_267 ) ) ;
V_6 -> V_132 = V_281 -> V_132 ;
V_6 -> V_112 = V_281 -> V_112 ;
V_6 -> V_288 = V_281 -> V_288 ;
F_45 ( V_6 ) ;
V_38 = F_53 ( V_6 ) ;
if ( V_38 != V_29 ) {
F_106 ( V_6 ) ;
goto exit;
}
F_60 ( V_6 ) ;
V_283 ++ ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_169 & F_10 ( V_22 ) ) )
continue;
if ( V_282 -> V_251 [ V_22 ] . V_289 . V_290 ==
V_291 )
V_283 += V_282 -> V_251 [ V_22 ] . V_289 . V_292 ;
if ( V_282 -> V_251 [ V_22 ] . V_256 . V_290 ==
V_293 )
V_283 += V_282 -> V_251 [ V_22 ] . V_256 . V_246 ;
V_283 ++ ;
}
if ( F_90 ( V_6 ,
& V_6 -> V_294 ,
V_282 -> V_295 + V_283 ,
V_282 -> V_296 + V_283 ) != V_29 ) {
F_107 ( V_6 ) ;
V_38 = V_243 ;
goto exit;
}
V_38 = F_64 ( V_6 ) ;
if ( V_38 != V_29 ) {
F_107 ( V_6 ) ;
goto exit;
}
* V_279 = V_6 ;
exit:
return V_38 ;
}
void
F_107 ( struct V_5 * V_6 )
{
F_108 ( V_6 -> V_284 == V_285 ) ;
V_6 -> V_284 = V_297 ;
F_85 ( & V_6 -> V_294 ) ;
F_106 ( V_6 ) ;
}
static enum V_25
F_109 ( struct V_8 * V_9 ,
T_3 V_298 , T_3 V_34 , T_2 * V_299 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
struct V_1 T_1 * V_2 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto V_301;
}
V_2 = V_9 -> V_2 ;
V_3 = F_110 ( V_298 ) |
V_302 |
F_111 ( V_34 ) ;
V_38 = F_13 ( V_3 ,
& V_2 -> V_303 ,
V_302 ,
V_9 -> V_6 -> V_287 . V_304 ) ;
if ( ( V_38 == V_29 ) && ( V_298 == V_305 ) )
* V_299 = F_2 ( & V_2 -> V_306 ) ;
else
* V_299 = 0 ;
V_301:
return V_38 ;
}
static enum V_25
F_112 ( struct V_8 * V_9 ,
struct V_307 * V_308 )
{
T_2 * V_3 ;
int V_22 ;
T_3 V_34 = V_309 ;
enum V_25 V_38 = V_29 ;
V_3 = ( T_2 * ) V_308 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto exit;
}
for ( V_22 = 0 ; V_22 < sizeof( struct V_307 ) / 8 ; V_22 ++ ) {
V_38 = F_109 ( V_9 ,
V_305 ,
V_34 , V_3 ) ;
if ( V_38 != V_29 )
goto exit;
V_34 ++ ;
V_3 ++ ;
}
exit:
return V_38 ;
}
static enum V_25
F_113 ( struct V_8 * V_9 ,
struct V_310 * V_311 )
{
T_2 * V_3 ;
enum V_25 V_38 = V_29 ;
int V_22 ;
T_3 V_34 = V_312 ;
V_3 = ( T_2 * ) V_311 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto exit;
}
for ( V_22 = 0 ; V_22 < sizeof( struct V_310 ) / 8 ; V_22 ++ ) {
V_38 = F_109 ( V_9 ,
V_305 ,
V_34 >> 3 , V_3 ) ;
if ( V_38 != V_29 )
goto exit;
V_34 += 8 ;
V_3 ++ ;
}
exit:
return V_38 ;
}
static enum V_25
F_114 ( struct V_8 * V_9 ,
struct V_313 * V_314 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
struct V_1 T_1 * V_2 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto exit;
}
V_2 = V_9 -> V_2 ;
V_3 = F_2 ( & V_2 -> V_315 ) ;
V_314 -> V_316 =
( T_3 ) F_115 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_317 ) ;
V_314 -> V_318 =
( T_3 ) F_116 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_319 ) ;
V_314 -> V_320 =
( T_3 ) F_117 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_321 ) ;
V_314 -> V_322 =
F_118 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_323 ) ;
V_314 -> V_324 =
F_119 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_325 ) ;
V_314 -> V_326 =
( T_3 ) F_120 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_327 ) ;
V_314 -> V_328 =
( T_3 ) F_121 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_329 ) ;
V_314 -> V_330 =
( T_3 ) F_122 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_329 ) ;
V_314 -> V_331 =
( T_3 ) F_123 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_332 ) ;
V_314 -> V_333 =
( T_3 ) F_124 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_329 ) ;
V_314 -> V_334 =
( T_3 ) F_125 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_335 ) ;
V_314 -> V_335 =
( T_3 ) F_126 (
V_3 ) ;
V_3 = F_2 ( & V_2 -> V_336 ) ;
V_314 -> V_336 =
( T_3 ) F_127 (
V_3 ) ;
V_38 = F_112 ( V_9 , & V_314 -> V_337 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_113 ( V_9 , & V_314 -> V_338 ) ;
if ( V_38 != V_29 )
goto exit;
F_128 (
V_339 ) ;
V_314 -> V_340 =
( T_3 ) F_129 ( V_3 ) ;
V_314 -> V_341 =
( T_3 ) F_130 ( V_3 ) ;
F_128 (
V_342 ) ;
V_314 -> V_343 =
( T_3 ) F_131 ( V_3 ) ;
V_314 -> V_344 =
( T_3 ) F_132 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_345 ) ;
V_314 -> V_346 =
( T_5 ) F_133 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_347 ) ;
V_314 -> V_347 =
( T_3 ) F_134 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_348 ) ;
V_314 -> V_348 =
( T_5 ) F_135 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_349 ) ;
V_314 -> V_350 =
( T_5 ) F_136 ( V_3 ) ;
V_314 -> V_351 =
( T_5 ) F_137 ( V_3 ) ;
V_314 -> V_352 =
( T_5 ) F_138 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_353 ) ;
V_314 -> V_354 =
( T_5 ) F_139 ( V_3 ) ;
V_314 -> V_355 =
( T_5 ) F_140 ( V_3 ) ;
V_314 -> V_356 =
( T_5 ) F_141 ( V_3 ) ;
V_3 = F_2 ( & V_2 -> V_357 ) ;
V_314 -> V_357 =
( T_5 ) F_142 (
V_3 ) ;
exit:
return V_38 ;
}
enum V_25
F_143 ( struct V_5 * V_6 ,
struct V_358 * V_314 )
{
T_3 V_22 ;
enum V_25 V_38 = V_29 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) ||
( V_6 -> V_14 [ V_22 ] . V_42 ==
V_170 ) )
continue;
memcpy ( V_6 -> V_14 [ V_22 ] . V_359 ,
V_6 -> V_14 [ V_22 ] . V_314 ,
sizeof( struct V_313 ) ) ;
V_38 = F_114 (
& V_6 -> V_14 [ V_22 ] ,
V_6 -> V_14 [ V_22 ] . V_314 ) ;
}
memcpy ( V_314 , & V_6 -> V_101 . V_360 ,
sizeof( struct V_358 ) ) ;
return V_38 ;
}
enum V_25 F_144 (
struct V_5 * V_6 ,
struct V_361 * V_362 )
{
memcpy ( V_362 , & V_6 -> V_101 . V_363 ,
sizeof( struct V_361 ) ) ;
return V_29 ;
}
enum V_25
F_145 ( struct V_5 * V_6 ,
T_3 V_298 , T_3 V_364 , T_3 V_34 , T_2 * V_299 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
V_38 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_38 != V_29 )
goto exit;
V_3 = F_146 ( V_298 ) |
V_365 |
F_147 ( V_364 ) |
F_148 ( V_34 ) ;
V_38 = F_13 ( V_3 ,
& V_6 -> V_139 -> V_366 ,
V_365 ,
V_6 -> V_287 . V_304 ) ;
if ( ( V_38 == V_29 ) && ( V_298 == V_305 ) )
* V_299 = F_2 ( & V_6 -> V_139 -> V_367 ) ;
else
* V_299 = 0 ;
exit:
return V_38 ;
}
static enum V_25
F_149 ( struct V_5 * V_6 , T_3 V_368 ,
struct V_369 * V_370 )
{
T_2 * V_3 ;
int V_22 ;
T_3 V_34 = V_371 ;
enum V_25 V_38 = V_29 ;
V_3 = ( T_2 * ) V_370 ;
V_38 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_38 != V_29 )
goto exit;
for ( V_22 = 0 ; V_22 < sizeof( struct V_369 ) / 8 ; V_22 ++ ) {
V_38 = F_145 ( V_6 ,
V_305 ,
V_372 ,
( ( V_34 + ( 104 * V_368 ) ) >> 3 ) , V_3 ) ;
if ( V_38 != V_29 )
goto exit;
V_34 += 8 ;
V_3 ++ ;
}
exit:
return V_38 ;
}
static enum V_25
F_150 ( struct V_5 * V_6 , T_3 V_368 ,
struct V_373 * V_374 )
{
T_2 * V_3 ;
enum V_25 V_38 = V_29 ;
int V_22 ;
T_3 V_34 = 0x0 ;
V_3 = ( T_2 * ) V_374 ;
V_38 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_38 != V_29 )
goto exit;
for ( V_22 = 0 ; V_22 < sizeof( struct V_373 ) / 8 ; V_22 ++ ) {
V_38 = F_145 ( V_6 ,
V_305 ,
V_372 ,
( ( V_34 + ( 608 * V_368 ) ) >> 3 ) , V_3 ) ;
if ( V_38 != V_29 )
goto exit;
V_34 += 8 ;
V_3 ++ ;
}
exit:
return V_38 ;
}
enum V_25
F_151 ( struct V_5 * V_6 ,
struct V_375 * V_376 )
{
enum V_25 V_38 = V_29 ;
T_3 V_22 ;
V_38 = F_149 ( V_6 ,
0 , & V_376 -> V_370 [ 0 ] ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_149 ( V_6 ,
1 , & V_376 -> V_370 [ 1 ] ) ;
if ( V_38 != V_29 )
goto exit;
for ( V_22 = 0 ; V_22 <= V_377 ; V_22 ++ ) {
V_38 = F_150 ( V_6 ,
V_22 , & V_376 -> V_374 [ V_22 ] ) ;
if ( V_38 != V_29 )
goto exit;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( V_6 -> V_24 & F_10 ( V_22 ) ) )
continue;
V_38 = F_112 (
& V_6 -> V_14 [ V_22 ] ,
& V_376 -> V_308 [ V_22 ] ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_113 (
& V_6 -> V_14 [ V_22 ] ,
& V_376 -> V_311 [ V_22 ] ) ;
if ( V_38 != V_29 )
goto exit;
}
exit:
return V_38 ;
}
void F_105 ( struct V_5 * V_6 ,
enum V_378 V_379 , T_3 V_27 )
{
if ( V_6 == NULL )
return;
#if F_152 ( V_380 ) || \
F_152 ( V_381 )
V_6 -> V_382 = V_27 ;
V_6 -> V_383 = V_379 ;
#endif
#if F_152 ( V_381 )
V_6 -> V_384 = V_379 & V_59 ;
#endif
#if F_152 ( V_380 )
V_6 -> V_385 = V_379 & V_386 ;
#endif
}
T_3 F_153 ( struct V_5 * V_6 )
{
#if F_152 ( V_381 )
if ( V_6 == NULL )
return V_59 ;
else
return V_6 -> V_384 ;
#else
return 0 ;
#endif
}
T_3 F_154 ( struct V_5 * V_6 )
{
#if F_152 ( V_380 )
if ( V_6 == NULL )
return V_386 ;
else
return V_6 -> V_385 ;
#else
return 0 ;
#endif
}
enum V_25 F_155 ( struct V_5 * V_6 ,
T_3 V_368 , T_3 * V_387 , T_3 * V_388 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_284 != V_285 ) ) {
V_38 = V_389 ;
goto exit;
}
if ( V_368 > V_377 ) {
V_38 = V_390 ;
goto exit;
}
if ( ! ( V_6 -> V_153 & V_156 ) ) {
V_38 = V_165 ;
goto exit;
}
V_3 = F_2 ( & V_6 -> V_139 -> V_391 [ V_368 ] ) ;
if ( V_3 & V_392 )
* V_387 = 1 ;
if ( V_3 & V_393 )
* V_388 = 1 ;
exit:
return V_38 ;
}
enum V_25 F_156 ( struct V_5 * V_6 ,
T_3 V_368 , T_3 V_387 , T_3 V_388 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_284 != V_285 ) ) {
V_38 = V_389 ;
goto exit;
}
if ( V_368 > V_377 ) {
V_38 = V_390 ;
goto exit;
}
V_38 = F_57 ( V_6 -> V_151 ,
V_6 -> V_152 ) ;
if ( V_38 != V_29 )
goto exit;
V_3 = F_2 ( & V_6 -> V_139 -> V_391 [ V_368 ] ) ;
if ( V_387 )
V_3 |= V_392 ;
else
V_3 &= ~ V_392 ;
if ( V_388 )
V_3 |= V_393 ;
else
V_3 &= ~ V_393 ;
F_4 ( V_3 , & V_6 -> V_139 -> V_391 [ V_368 ] ) ;
exit:
return V_38 ;
}
T_5 F_157 ( struct V_5 * V_6 )
{
struct V_171 * V_172 = V_6 -> V_112 ;
T_5 V_173 ;
F_63 ( V_172 , V_174 , & V_173 ) ;
return ( V_173 & V_394 ) >> 4 ;
}
static inline T_3
F_158 ( T_4 * V_395 )
{
return ( T_3 ) * ( ( T_2 * ) ( V_395 + V_396 ) ) ;
}
static inline void
F_159 ( T_4 * V_395 , T_3 V_397 )
{
* ( ( T_2 * ) ( V_395 + V_396 ) ) = V_397 ;
}
static inline void
F_160 ( T_4 * V_395 , T_6 V_398 )
{
* ( ( T_2 * ) ( V_395 + V_399 ) ) = V_398 ;
}
static T_2 F_161 ( struct V_105 * V_289 )
{
struct V_400 * V_401 ;
V_401 = V_289 -> V_402 -> V_403 ;
F_108 ( V_401 != NULL ) ;
return V_401 -> V_31 ;
}
static T_6 F_162 ( struct V_404 * V_405 ,
void * V_231 )
{
T_3 V_397 ;
void * V_229 ;
struct V_400 * V_406 ;
T_7 V_407 ;
V_397 = F_158 ( V_231 ) ;
V_229 = V_405 -> V_408 [ V_397 ] ;
V_406 = V_405 -> V_403 + V_397 ;
V_407 = ( T_4 * ) V_231 - ( T_4 * ) V_229 ;
return V_406 -> V_31 + V_407 ;
}
static void F_163 ( struct V_404 * V_405 ,
struct V_105 * V_289 , T_3 V_409 ,
T_3 V_410 )
{
T_4 * V_411 , * V_412 ;
T_6 V_413 ;
V_412 = V_405 -> V_414 [ V_409 ] ;
F_108 ( V_412 ) ;
V_411 = V_405 -> V_414 [ V_410 ] ;
F_108 ( V_411 ) ;
V_413 = F_162 ( V_405 , V_411 ) ;
F_160 ( V_412 , V_413 ) ;
}
static void
F_164 ( struct V_404 * V_405 ,
T_3 V_415 ,
struct V_400 * V_401 ,
T_3 V_88 , T_3 V_416 )
{
T_3 V_22 ;
void * V_231 = V_405 -> V_414 [ V_88 ] ;
struct V_105 * V_289 =
(struct V_105 * ) V_405 -> V_417 ;
for ( V_22 = 0 ; V_22 < V_289 -> V_418 ; V_22 ++ ) {
void * V_419 ;
void * V_420 ;
struct V_421 * V_422 ;
T_3 V_423 = V_289 -> V_91 . V_107 -
( V_88 * V_289 -> V_418 + V_22 + 1 ) ;
T_3 V_424 ;
V_289 -> V_91 . V_94 [ V_423 ] = ( ( T_4 * ) V_231 ) +
V_22 * V_289 -> V_425 ;
V_419 = F_165 ( V_405 ,
V_415 , V_231 ,
& V_424 ) ;
V_422 = V_289 -> V_91 . V_94 [ V_423 ] ;
V_420 = ( ( T_4 * ) V_419 + V_289 -> V_426 * V_22 ) ;
V_422 -> V_427 = ( T_2 ) ( V_428 ) V_420 ;
}
F_159 ( V_231 , V_415 ) ;
if ( V_416 ) {
F_163 ( V_405 , V_289 , V_88 , 0 ) ;
}
if ( V_88 > 0 ) {
F_163 ( V_405 , V_289 , V_88 - 1 , V_88 ) ;
}
}
static enum V_25
F_166 ( struct V_105 * V_289 )
{
void * V_429 ;
struct V_90 * V_91 ;
enum V_25 V_38 = V_29 ;
V_91 = & V_289 -> V_91 ;
while ( F_167 ( V_91 ) > 0 ) {
V_38 = F_168 ( V_289 , & V_429 ) ;
F_108 ( V_38 == V_29 ) ;
if ( V_289 -> V_430 ) {
V_38 = V_289 -> V_430 ( V_429 , V_91 -> V_417 ) ;
if ( V_38 != V_29 ) {
F_169 ( V_289 , V_429 ) ;
goto exit;
}
}
F_170 ( V_289 , V_429 ) ;
}
V_38 = V_29 ;
exit:
return V_38 ;
}
static struct V_90 *
F_171 ( struct V_431 * V_96 ,
enum V_432 type ,
T_3 V_97 , T_3 V_433 ,
void * V_417 )
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
V_91 = F_92 ( V_61 , V_242 ) ;
if ( V_91 == NULL )
goto V_434;
F_91 ( & V_91 -> V_231 ) ;
V_91 -> V_137 = V_6 -> V_137 ;
V_91 -> V_53 = V_6 -> V_53 ;
V_91 -> type = type ;
V_91 -> V_279 = V_6 ;
V_91 -> V_96 = V_96 ;
V_91 -> V_417 = V_417 ;
V_91 -> V_433 = V_433 ;
V_91 -> V_97 = V_97 ;
V_91 -> V_7 = V_7 ;
V_91 -> V_92 = F_92 ( sizeof( void * ) * V_97 , V_242 ) ;
if ( V_91 -> V_92 == NULL )
goto V_435;
V_91 -> V_93 = F_92 ( sizeof( void * ) * V_97 , V_242 ) ;
if ( V_91 -> V_93 == NULL )
goto V_435;
V_91 -> V_106 = V_97 ;
V_91 -> V_94 = F_92 ( sizeof( void * ) * V_97 , V_242 ) ;
if ( V_91 -> V_94 == NULL )
goto V_435;
V_91 -> V_107 = V_97 ;
V_91 -> V_108 = 0 ;
V_91 -> V_95 = F_92 ( sizeof( void * ) * V_97 , V_242 ) ;
if ( V_91 -> V_95 == NULL )
goto V_435;
return V_91 ;
V_435:
F_41 ( V_91 ) ;
V_434:
return NULL ;
}
static void F_172 ( struct V_5 * V_279 ,
void * V_436 ,
T_3 V_97 ,
struct V_171 * V_437 ,
struct V_171 * V_230 )
{
struct V_221 * V_222 ;
struct V_226 * V_234 = NULL ;
T_6 V_227 ;
enum V_25 V_38 = V_29 ;
T_3 V_239 ;
V_222 = & V_279 -> V_294 ;
if ( V_436 == NULL ) {
V_222 -> V_239 -- ;
V_38 = V_30 ;
goto exit;
}
V_227 = F_95 ( V_279 -> V_112 , V_436 , V_97 ,
V_228 ) ;
if ( F_96 ( F_97 ( V_279 -> V_112 , V_227 ) ) ) {
F_88 ( V_279 -> V_112 , V_436 , & V_230 ) ;
V_222 -> V_239 -- ;
V_38 = V_30 ;
goto exit;
}
if ( ! F_98 ( & V_222 -> V_241 ) )
V_234 = (struct V_226 * )
F_99 ( & V_222 -> V_241 ,
struct V_226 ,
V_231 ) ;
if ( V_234 == NULL )
V_234 = F_173 ( sizeof( struct V_226 ) ) ;
else
F_89 ( & V_234 -> V_231 ) ;
if ( V_234 != NULL ) {
V_234 -> V_97 = V_97 ;
V_234 -> V_229 = V_436 ;
V_234 -> V_227 = V_227 ;
V_234 -> V_230 = V_230 ;
V_234 -> V_235 = V_437 ;
F_93 ( & V_234 -> V_231 , & V_222 -> V_240 ) ;
V_222 -> V_232 ++ ;
V_38 = V_29 ;
} else
V_38 = V_243 ;
V_222 -> V_239 -- ;
V_239 = V_222 -> V_239 ;
exit:
return;
}
static inline void
F_174 ( struct V_171 * V_112 , void * V_279 , unsigned long V_61 )
{
T_8 V_438 ;
void * V_439 ;
if ( F_175 () )
V_438 = V_440 | V_441 ;
else
V_438 = V_242 | V_441 ;
V_439 = F_176 ( ( V_61 ) , V_438 ) ;
F_172 ( V_279 , V_439 , V_61 , V_112 , V_112 ) ;
}
static
void F_177 ( struct V_221 * V_222 )
{
T_3 V_442 = 0 , V_22 ;
if ( ( V_222 -> V_232 + V_222 -> V_239 ) <
V_443 ) {
V_442 = V_444 ;
V_222 -> V_239 += V_442 ;
}
for ( V_22 = 0 ; V_22 < V_442 ; V_22 ++ )
F_174 (
( V_222 -> V_6 ) -> V_112 ,
V_222 -> V_6 , V_238 ) ;
}
static void * F_178 ( struct V_5 * V_279 , T_3 V_61 ,
struct V_400 * V_401 )
{
struct V_226 * V_234 = NULL ;
struct V_221 * V_222 ;
void * V_229 = NULL ;
enum V_25 V_38 = V_29 ;
V_222 = & V_279 -> V_294 ;
if ( V_61 != V_222 -> V_237 ) {
V_229 = F_94 ( V_279 -> V_112 , V_61 ,
& V_401 -> V_445 ,
& V_401 -> V_230 ) ;
if ( V_229 == NULL ) {
V_38 = V_243 ;
goto exit;
}
V_401 -> V_31 = F_95 ( V_279 -> V_112 , V_229 , V_61 ,
V_228 ) ;
if ( F_96 ( F_97 ( V_279 -> V_112 ,
V_401 -> V_31 ) ) ) {
F_88 ( V_279 -> V_112 , V_229 ,
& V_401 -> V_230 ) ;
V_38 = V_243 ;
goto exit;
}
} else {
if ( ! F_98 ( & V_222 -> V_240 ) )
V_234 = (struct V_226 * )
F_99 ( & V_222 -> V_240 ,
struct V_226 ,
V_231 ) ;
if ( V_234 != NULL ) {
F_89 ( & V_234 -> V_231 ) ;
V_401 -> V_31 = V_234 -> V_227 ;
V_401 -> V_445 = V_234 -> V_235 ;
V_401 -> V_230 = V_234 -> V_230 ;
V_229 = V_234 -> V_229 ;
F_93 ( & V_234 -> V_231 ,
& V_222 -> V_241 ) ;
V_222 -> V_232 -- ;
}
if ( V_229 != NULL )
F_177 ( V_222 ) ;
}
exit:
return V_229 ;
}
static void
F_179 ( struct V_221 * V_222 )
{
struct V_223 * V_224 , * V_225 ;
F_86 (p, n, &blockpool->free_block_list) {
if ( V_222 -> V_232 < V_222 -> V_233 )
break;
F_87 (
( V_222 -> V_6 ) -> V_112 ,
( (struct V_226 * ) V_224 ) -> V_227 ,
( (struct V_226 * ) V_224 ) -> V_97 ,
V_228 ) ;
F_88 (
( V_222 -> V_6 ) -> V_112 ,
( (struct V_226 * ) V_224 ) -> V_229 ,
& ( (struct V_226 * ) V_224 ) -> V_230 ) ;
F_89 ( & ( (struct V_226 * ) V_224 ) -> V_231 ) ;
F_93 ( V_224 , & V_222 -> V_241 ) ;
V_222 -> V_232 -- ;
}
}
static void F_180 ( struct V_5 * V_279 ,
void * V_229 , T_3 V_61 ,
struct V_400 * V_401 )
{
struct V_226 * V_234 = NULL ;
struct V_221 * V_222 ;
enum V_25 V_38 = V_29 ;
V_222 = & V_279 -> V_294 ;
if ( V_61 != V_222 -> V_237 ) {
F_87 ( V_279 -> V_112 , V_401 -> V_31 , V_61 ,
V_228 ) ;
F_88 ( V_279 -> V_112 , V_229 , & V_401 -> V_230 ) ;
} else {
if ( ! F_98 ( & V_222 -> V_241 ) )
V_234 = (struct V_226 * )
F_99 ( & V_222 -> V_241 ,
struct V_226 ,
V_231 ) ;
if ( V_234 == NULL )
V_234 = F_173 ( sizeof(
struct V_226 ) ) ;
else
F_89 ( & V_234 -> V_231 ) ;
if ( V_234 != NULL ) {
V_234 -> V_97 = V_61 ;
V_234 -> V_229 = V_229 ;
V_234 -> V_227 = V_401 -> V_31 ;
V_234 -> V_230 = V_401 -> V_230 ;
V_234 -> V_235 = V_401 -> V_445 ;
F_93 ( & V_234 -> V_231 ,
& V_222 -> V_240 ) ;
V_222 -> V_232 ++ ;
V_38 = V_29 ;
} else
V_38 = V_243 ;
if ( V_38 == V_29 )
F_179 ( V_222 ) ;
}
}
static void F_181 ( struct V_404 * V_402 )
{
T_3 V_22 , V_200 ;
struct V_5 * V_279 = V_402 -> V_279 ;
for ( V_22 = 0 ; V_22 < V_402 -> V_446 ; V_22 ++ ) {
struct V_400 * V_401 ;
F_108 ( V_402 -> V_408 [ V_22 ] ) ;
F_108 ( V_402 -> V_403 + V_22 ) ;
V_401 = V_402 -> V_403 + V_22 ;
for ( V_200 = 0 ; V_200 < V_402 -> V_447 ; V_200 ++ ) {
T_3 V_88 = V_22 * V_402 -> V_447 + V_200 ;
if ( V_88 >= V_402 -> V_448 )
break;
}
F_106 ( V_402 -> V_449 [ V_22 ] ) ;
F_180 ( V_279 , V_402 -> V_408 [ V_22 ] ,
V_402 -> V_450 , V_401 ) ;
}
F_106 ( V_402 -> V_414 ) ;
F_106 ( V_402 -> V_403 ) ;
F_106 ( V_402 -> V_449 ) ;
F_106 ( V_402 -> V_408 ) ;
F_106 ( V_402 ) ;
}
static enum V_25
F_182 ( struct V_404 * V_402 , T_3 V_451 ,
T_3 * V_452 )
{
T_3 V_22 , V_453 = V_402 -> V_446 == 0 ? 1 : 0 ;
T_3 V_454 = V_402 -> V_447 ;
T_3 V_455 = V_402 -> V_446 ;
T_3 V_456 = V_402 -> V_446 + V_451 ;
enum V_25 V_38 = V_29 ;
* V_452 = 0 ;
if ( V_456 > V_402 -> V_457 ) {
V_38 = V_243 ;
goto exit;
}
for ( V_22 = V_455 ; V_22 < V_456 ; V_22 ++ ) {
T_3 V_200 ;
T_3 V_416 = ( ( V_456 - 1 ) == V_22 ) ;
struct V_400 * V_401 =
V_402 -> V_403 + V_22 ;
void * V_458 ;
V_402 -> V_449 [ V_22 ] =
F_104 ( V_402 -> V_459 * V_454 ) ;
if ( V_402 -> V_449 [ V_22 ] == NULL ) {
V_38 = V_243 ;
goto exit;
}
V_402 -> V_408 [ V_22 ] =
F_178 ( V_402 -> V_279 ,
V_402 -> V_450 , V_401 ) ;
if ( V_402 -> V_408 [ V_22 ] == NULL ) {
F_106 ( V_402 -> V_449 [ V_22 ] ) ;
V_38 = V_243 ;
goto exit;
}
( * V_452 ) ++ ;
V_402 -> V_446 ++ ;
memset ( V_402 -> V_408 [ V_22 ] , 0 , V_402 -> V_450 ) ;
V_458 = V_402 -> V_408 [ V_22 ] ;
for ( V_200 = 0 ; V_200 < V_454 ; V_200 ++ ) {
T_3 V_88 = V_22 * V_454 + V_200 ;
if ( V_453 && V_88 >= V_402 -> V_460 )
break;
V_402 -> V_414 [ V_88 ] =
( ( char * ) V_458 + V_200 * V_402 -> V_461 ) ;
if ( V_402 -> V_462 != NULL )
V_402 -> V_462 ( V_402 , V_22 ,
V_401 , V_88 , V_416 ) ;
V_402 -> V_448 = V_88 + 1 ;
}
if ( V_453 && V_402 -> V_448 ==
V_402 -> V_460 )
break;
}
exit:
return V_38 ;
}
static struct V_404 *
F_183 ( struct V_5 * V_279 ,
T_3 V_450 ,
T_3 V_461 ,
T_3 V_459 ,
T_3 V_460 ,
T_3 V_463 ,
const struct V_464 * V_465 ,
void * V_417 )
{
enum V_25 V_38 = V_29 ;
T_3 V_466 ;
struct V_404 * V_402 = NULL ;
T_3 V_467 ;
if ( V_450 < V_461 ) {
V_38 = V_30 ;
goto exit;
}
V_402 = F_104 ( sizeof( struct V_404 ) ) ;
if ( V_402 == NULL ) {
V_38 = V_243 ;
goto exit;
}
V_402 -> V_279 = V_279 ;
V_402 -> V_450 = V_450 ;
V_402 -> V_463 = V_463 ;
V_402 -> V_460 = V_460 ;
V_402 -> V_461 = V_461 ;
V_402 -> V_459 = V_459 ;
V_402 -> V_462 = V_465 -> V_462 ;
V_402 -> V_417 = V_417 ;
V_402 -> V_446 = 0 ;
V_402 -> V_447 = V_450 / V_461 ;
V_402 -> V_457 = ( V_463 + V_402 -> V_447 - 1 ) /
V_402 -> V_447 ;
V_402 -> V_408 =
F_104 ( sizeof( void * ) * V_402 -> V_457 ) ;
if ( V_402 -> V_408 == NULL ) {
F_181 ( V_402 ) ;
V_38 = V_243 ;
V_402 = NULL ;
goto exit;
}
V_402 -> V_449 =
F_104 ( sizeof( void * ) * V_402 -> V_457 ) ;
if ( V_402 -> V_449 == NULL ) {
F_181 ( V_402 ) ;
V_38 = V_243 ;
V_402 = NULL ;
goto exit;
}
V_402 -> V_403 =
F_104 ( sizeof( struct V_400 ) *
V_402 -> V_457 ) ;
if ( V_402 -> V_403 == NULL ) {
F_181 ( V_402 ) ;
V_38 = V_243 ;
V_402 = NULL ;
goto exit;
}
V_402 -> V_414 = F_104 ( sizeof( void * ) * V_402 -> V_463 ) ;
if ( V_402 -> V_414 == NULL ) {
F_181 ( V_402 ) ;
V_38 = V_243 ;
V_402 = NULL ;
goto exit;
}
V_466 = ( V_402 -> V_460 +
V_402 -> V_447 - 1 ) /
V_402 -> V_447 ;
V_38 = F_182 ( V_402 , V_466 ,
& V_467 ) ;
if ( V_38 != V_29 ) {
F_181 ( V_402 ) ;
V_38 = V_243 ;
V_402 = NULL ;
goto exit;
}
exit:
return V_402 ;
}
static enum V_25 F_184 ( struct V_105 * V_289 )
{
void * V_468 ;
struct V_90 * V_91 ;
V_91 = & V_289 -> V_91 ;
for (; ; ) {
F_185 ( V_91 , & V_468 ) ;
if ( V_468 == NULL )
break;
F_186 ( V_91 ) ;
if ( V_289 -> V_469 )
V_289 -> V_469 ( V_468 , V_470 ,
V_91 -> V_417 ) ;
F_187 ( V_91 , V_468 ) ;
}
return V_29 ;
}
static enum V_25 F_188 ( struct V_105 * V_289 )
{
enum V_25 V_38 = V_29 ;
struct V_90 * V_91 ;
V_91 = & V_289 -> V_91 ;
F_184 ( V_289 ) ;
V_38 = F_44 ( V_91 ) ;
if ( V_38 != V_29 )
goto exit;
if ( V_289 -> V_430 ) {
V_38 = F_166 ( V_289 ) ;
if ( V_38 != V_29 )
goto exit;
}
exit:
return V_38 ;
}
static enum V_25
F_189 ( struct V_431 * V_471 )
{
struct V_105 * V_289 = V_471 -> V_9 -> V_104 ;
F_184 ( V_289 ) ;
if ( V_289 -> V_402 )
F_181 ( V_289 -> V_402 ) ;
V_471 -> V_9 -> V_104 = NULL ;
F_41 ( & V_289 -> V_91 ) ;
return V_29 ;
}
static enum V_25
F_190 ( struct V_431 * V_471 ,
struct V_472 * V_281 )
{
enum V_25 V_38 = V_29 ;
struct V_105 * V_289 ;
T_3 V_473 ;
struct V_474 * V_287 ;
struct V_5 * V_6 ;
T_3 V_7 ;
static const struct V_464 V_475 = {
. V_462 = F_164 ,
} ;
if ( ( V_471 == NULL ) || ( V_281 == NULL ) ) {
V_38 = V_30 ;
goto exit;
}
V_6 = V_471 -> V_9 -> V_6 ;
V_7 = V_471 -> V_9 -> V_7 ;
V_287 = & V_6 -> V_287 . V_251 [ V_7 ] . V_289 ;
V_473 = V_287 -> V_292 *
F_191 ( V_287 -> V_476 ) ;
V_289 = (struct V_105 * ) F_171 ( V_471 ,
V_103 ,
V_473 ,
V_281 -> V_477 ,
V_281 -> V_417 ) ;
if ( V_289 == NULL ) {
V_38 = V_243 ;
goto exit;
}
V_471 -> V_9 -> V_104 = V_289 ;
V_289 -> V_7 = V_7 ;
V_289 -> V_2 = V_471 -> V_9 -> V_2 ;
V_289 -> V_137 = V_6 -> V_137 ;
V_289 -> V_101 = & V_471 -> V_9 -> V_362 -> V_478 ;
V_289 -> V_287 = V_287 ;
V_289 -> V_479 = V_281 -> V_479 ;
V_289 -> V_430 = V_281 -> V_430 ;
V_289 -> V_469 = V_281 -> V_469 ;
V_289 -> V_476 = V_287 -> V_476 ;
V_289 -> V_480 = V_471 -> V_9 -> V_480 ;
V_289 -> V_481 = V_471 -> V_9 -> V_481 ;
V_289 -> V_482 = V_287 -> V_482 ;
V_289 -> V_425 = F_192 ( V_287 -> V_476 ) ;
V_289 -> V_426 =
sizeof( struct V_483 ) + V_281 -> V_477 ;
V_289 -> V_477 = V_281 -> V_477 ;
V_289 -> V_426 =
( ( V_289 -> V_426 + V_484 - 1 ) /
V_484 ) * V_484 ;
V_289 -> V_418 =
F_191 ( V_287 -> V_476 ) ;
V_289 -> V_485 = V_289 -> V_426 * V_289 -> V_418 ;
V_289 -> V_402 = F_183 ( V_6 ,
V_238 ,
V_238 ,
V_289 -> V_485 ,
V_289 -> V_287 -> V_292 ,
V_289 -> V_287 -> V_292 ,
& V_475 ,
V_289 ) ;
if ( V_289 -> V_402 == NULL ) {
F_189 ( V_471 ) ;
return V_243 ;
}
V_38 = F_43 ( & V_289 -> V_91 ) ;
if ( V_38 != V_29 ) {
F_189 ( V_471 ) ;
goto exit;
}
if ( V_289 -> V_430 ) {
V_38 = F_166 ( V_289 ) ;
if ( V_38 != V_29 ) {
F_189 ( V_471 ) ;
goto exit;
}
}
V_289 -> V_101 -> V_102 . V_486 = 0 ;
exit:
return V_38 ;
}
enum V_25
F_193 ( struct V_267 * V_282 )
{
T_3 V_22 ;
V_282 -> V_295 =
V_487 ;
V_282 -> V_296 = V_488 ;
V_282 -> V_269 = V_273 ;
V_282 -> V_489 = V_490 ;
V_282 -> V_491 = V_492 ;
V_282 -> V_304 = V_47 ;
V_282 -> V_275 = V_493 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_282 -> V_251 [ V_22 ] . V_7 = V_22 ;
V_282 -> V_251 [ V_22 ] . V_252 =
V_494 ;
V_282 -> V_251 [ V_22 ] . V_289 . V_290 = V_495 ;
V_282 -> V_251 [ V_22 ] . V_289 . V_292 =
V_496 ;
V_282 -> V_251 [ V_22 ] . V_289 . V_476 =
V_497 ;
V_282 -> V_251 [ V_22 ] . V_289 . V_498 =
V_499 ;
V_282 -> V_251 [ V_22 ] . V_289 . V_482 =
V_500 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_290 = V_293 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_246 =
V_247 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_501 =
V_502 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_450 =
V_503 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_504 =
V_505 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_506 =
V_507 ;
V_282 -> V_251 [ V_22 ] . V_256 . V_508 =
V_509 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_511 =
V_512 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_513 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_515 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_516 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_517 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_518 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_519 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_520 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_521 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_522 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_523 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_524 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_525 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_526 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_510 . V_527 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_511 =
V_512 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_513 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_515 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_516 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_517 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_518 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_519 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_520 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_521 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_522 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_523 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_524 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_525 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_526 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_528 . V_527 =
V_514 ;
V_282 -> V_251 [ V_22 ] . V_257 =
V_258 ;
V_282 -> V_251 [ V_22 ] . V_262 =
V_263 ;
}
return V_29 ;
}
static enum V_25
F_194 ( struct V_1 T_1 * V_148 )
{
#ifndef F_195
T_2 V_3 ;
V_3 = F_2 ( & V_148 -> V_529 ) ;
F_16 () ;
V_3 |= V_530 ;
F_4 ( V_3 , & V_148 -> V_529 ) ;
F_16 () ;
#endif
return V_29 ;
}
static enum V_25
F_196 ( struct V_115 T_1 * V_116 ,
struct V_1 T_1 * V_148 )
{
T_2 V_3 ;
V_3 = F_2 ( & V_116 -> V_125 ) ;
if ( V_3 == V_124 ) {
V_3 = F_2 ( & V_148 -> V_531 ) ;
F_16 () ;
V_3 |= V_532 |
V_533 |
V_534 ;
F_4 ( V_3 , & V_148 -> V_531 ) ;
F_16 () ;
}
return V_29 ;
}
enum V_25
F_197 ( struct V_5 * V_6 ,
enum V_535 type ,
T_3 V_88 , T_3 V_34 , T_2 * V_536 )
{
enum V_25 V_38 = V_29 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_284 != V_285 ) ) {
V_38 = V_389 ;
goto exit;
}
switch ( type ) {
case V_537 :
if ( V_34 > sizeof( struct V_115 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_116 + V_34 ) ;
break;
case V_539 :
if ( V_34 > sizeof( struct V_131 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_135 + V_34 ) ;
break;
case V_540 :
if ( V_34 > sizeof( struct V_215 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_137 + V_34 ) ;
break;
case V_541 :
if ( ! ( V_6 -> V_153 &
V_156 ) ) {
V_38 = V_165 ;
break;
}
if ( V_34 > sizeof( struct V_214 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_139 + V_34 ) ;
break;
case V_542 :
if ( ! ( V_6 -> V_153 &
V_157 ) ) {
V_38 = V_165 ;
break;
}
if ( V_88 > V_140 - 1 ) {
V_38 = V_543 ;
break;
}
if ( V_34 > sizeof( struct V_544 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_142 [ V_88 ] +
V_34 ) ;
break;
case V_545 :
if ( ( V_88 > V_143 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_38 = V_543 ;
break;
}
if ( V_34 > sizeof( struct V_166 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_145 [ V_88 ] +
V_34 ) ;
break;
case V_546 :
if ( ( V_88 > V_146 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_38 = V_543 ;
break;
}
if ( V_88 > V_146 - 1 ) {
V_38 = V_543 ;
break;
}
if ( V_34 > sizeof( struct V_1 ) - 8 ) {
V_38 = V_538 ;
break;
}
* V_536 = F_2 ( ( void T_1 * ) V_6 -> V_148 [ V_88 ] +
V_34 ) ;
break;
default:
V_38 = V_547 ;
break;
}
exit:
return V_38 ;
}
enum V_25
F_198 ( struct V_5 * V_6 , T_2 V_217 )
{
struct V_166 T_1 * V_145 ;
int V_22 = 0 , V_200 = 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( ! ( ( V_217 ) & F_10 ( V_22 ) ) )
continue;
V_145 = V_6 -> V_145 [ V_22 ] ;
for ( V_200 = 0 ; V_200 < V_377 ; V_200 ++ ) {
if ( F_2 ( & V_145 -> V_548 [ V_200 ] )
& V_549 )
return V_30 ;
}
}
return V_29 ;
}
enum V_25
F_199 ( struct V_5 * V_6 ,
enum V_535 type ,
T_3 V_88 , T_3 V_34 , T_2 V_536 )
{
enum V_25 V_38 = V_29 ;
if ( ( V_6 == NULL ) || ( V_6 -> V_284 != V_285 ) ) {
V_38 = V_389 ;
goto exit;
}
switch ( type ) {
case V_537 :
if ( V_34 > sizeof( struct V_115 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_116 + V_34 ) ;
break;
case V_539 :
if ( V_34 > sizeof( struct V_131 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_135 + V_34 ) ;
break;
case V_540 :
if ( V_34 > sizeof( struct V_215 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_137 + V_34 ) ;
break;
case V_541 :
if ( ! ( V_6 -> V_153 &
V_156 ) ) {
V_38 = V_165 ;
break;
}
if ( V_34 > sizeof( struct V_214 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_139 + V_34 ) ;
break;
case V_542 :
if ( ! ( V_6 -> V_153 &
V_157 ) ) {
V_38 = V_165 ;
break;
}
if ( V_88 > V_140 - 1 ) {
V_38 = V_543 ;
break;
}
if ( V_34 > sizeof( struct V_544 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_142 [ V_88 ] +
V_34 ) ;
break;
case V_545 :
if ( ( V_88 > V_143 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_38 = V_543 ;
break;
}
if ( V_34 > sizeof( struct V_166 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_145 [ V_88 ] +
V_34 ) ;
break;
case V_546 :
if ( ( V_88 > V_146 - 1 ) ||
( ! ( V_6 -> V_169 & F_10 ( V_88 ) ) ) ) {
V_38 = V_543 ;
break;
}
if ( V_34 > sizeof( struct V_1 ) - 8 ) {
V_38 = V_538 ;
break;
}
F_4 ( V_536 , ( void T_1 * ) V_6 -> V_148 [ V_88 ] +
V_34 ) ;
break;
default:
V_38 = V_547 ;
break;
}
exit:
return V_38 ;
}
static enum V_25 F_200 ( struct V_100 * V_256 )
{
void * V_550 ;
for (; ; ) {
F_185 ( & V_256 -> V_91 , & V_550 ) ;
if ( V_550 == NULL )
break;
F_186 ( & V_256 -> V_91 ) ;
if ( V_256 -> V_551 ) {
V_256 -> V_551 ( V_550 ,
V_552 ,
V_256 -> V_91 . V_417 ) ;
}
F_187 ( & V_256 -> V_91 , V_550 ) ;
}
return V_29 ;
}
static enum V_25 F_201 ( struct V_100 * V_256 )
{
enum V_25 V_38 = V_29 ;
F_200 ( V_256 ) ;
V_38 = F_44 ( & V_256 -> V_91 ) ;
return V_38 ;
}
static enum V_25
F_202 ( struct V_431 * V_471 )
{
struct V_100 * V_256 = V_471 -> V_9 -> V_99 ;
F_200 ( V_256 ) ;
if ( V_256 -> V_402 )
F_181 ( V_256 -> V_402 ) ;
V_471 -> V_9 -> V_99 = NULL ;
F_41 ( & V_256 -> V_91 ) ;
return V_29 ;
}
static void
F_203 (
struct V_404 * V_405 ,
T_3 V_415 , struct V_400 * V_401 ,
T_3 V_88 , T_3 V_416 )
{
T_3 V_424 ;
struct V_553 * V_554 ;
struct V_555 * V_556 =
(struct V_555 * ) V_405 -> V_414 [ V_88 ] ;
struct V_100 * V_256 =
(struct V_100 * ) V_405 -> V_417 ;
void * V_229 = V_405 -> V_408 [ V_415 ] ;
F_108 ( V_556 ) ;
V_556 -> V_427 = ( T_2 ) ( V_428 )
F_165 ( V_405 , V_415 , V_556 ,
& V_424 ) ;
V_554 = V_553 ( V_256 , V_556 ) ;
F_108 ( V_554 ) ;
V_256 -> V_91 . V_94 [ V_256 -> V_91 . V_107 - 1 - V_88 ] = V_556 ;
V_554 -> V_557 = ( char * ) V_556 - ( char * ) V_229 ;
V_554 -> V_227 = V_401 -> V_31 + V_554 -> V_557 ;
V_554 -> V_235 = V_401 -> V_445 ;
V_554 -> V_229 = V_229 ;
V_554 -> V_558 = V_556 ;
V_554 -> V_559 = NULL ;
V_554 -> V_560 = 0 ;
}
static enum V_25
F_204 ( struct V_431 * V_471 ,
struct V_561 * V_281 )
{
enum V_25 V_38 = V_29 ;
struct V_100 * V_256 ;
struct V_244 * V_287 ;
T_3 V_562 , V_563 ;
struct V_464 V_564 ;
struct V_8 * V_9 ;
if ( ( V_471 == NULL ) || ( V_281 == NULL ) ) {
V_38 = V_565 ;
goto exit;
}
V_9 = V_471 -> V_9 ;
V_287 = & V_9 -> V_6 -> V_287 . V_251 [ V_9 -> V_7 ] . V_256 ;
V_562 = V_287 -> V_501 * sizeof( struct V_555 ) ;
V_563 = V_287 -> V_450 / V_562 ;
V_256 = (struct V_100 * ) F_171 ( V_471 ,
V_98 ,
V_287 -> V_246 * V_563 ,
V_281 -> V_566 , V_281 -> V_417 ) ;
if ( V_256 == NULL ) {
V_38 = V_243 ;
goto exit;
}
V_9 -> V_99 = V_256 ;
V_256 -> V_567 = V_9 -> V_567 ;
V_256 -> V_7 = V_9 -> V_7 ;
V_256 -> V_2 = V_9 -> V_2 ;
V_256 -> V_101 = & V_9 -> V_362 -> V_568 ;
V_256 -> V_287 = V_287 ;
V_256 -> V_569 = V_570 ;
V_256 -> V_571 = V_9 -> V_571 ;
V_256 -> V_572 = V_9 -> V_572 ;
if ( V_256 -> V_287 -> V_506 )
V_256 -> V_569 = V_573 ;
V_256 -> V_508 = V_287 -> V_508 ;
V_256 -> V_574 =
sizeof( struct V_553 ) + V_281 -> V_566 ;
V_256 -> V_574 = ( ( V_256 -> V_574 + V_484 - 1 ) /
V_484 ) * V_484 ;
V_256 -> V_566 = V_281 -> V_566 ;
V_256 -> V_562 = V_562 ;
V_256 -> V_563 = V_563 ;
V_256 -> V_551 = V_281 -> V_551 ;
V_256 -> V_479 = V_281 -> V_479 ;
if ( V_256 -> V_563 == 0 ) {
F_202 ( V_471 ) ;
V_38 = V_575 ;
goto exit;
}
V_564 . V_462 = F_203 ;
V_256 -> V_402 =
F_183 ( V_9 -> V_6 ,
V_256 -> V_287 -> V_450 ,
V_256 -> V_562 ,
V_256 -> V_574 ,
( V_256 -> V_287 -> V_246 * V_256 -> V_563 ) ,
( V_256 -> V_287 -> V_246 * V_256 -> V_563 ) ,
& V_564 ,
V_256 ) ;
if ( V_256 -> V_402 == NULL ) {
F_202 ( V_471 ) ;
V_38 = V_243 ;
goto exit;
}
V_38 = F_43 ( & V_256 -> V_91 ) ;
if ( V_38 != V_29 ) {
F_202 ( V_471 ) ;
goto exit;
}
F_108 ( V_256 -> V_91 . V_107 ) ;
exit:
return V_38 ;
}
static enum V_25
F_205 ( struct V_8 * V_9 ,
T_3 V_576 , T_3 V_34 , T_3 * V_577 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
V_3 = F_206 ( V_34 ) ;
if ( V_576 )
V_3 |= V_578 ;
F_4 ( V_3 , & V_2 -> V_579 ) ;
F_16 () ;
F_4 ( V_580 ,
& V_2 -> V_581 ) ;
F_16 () ;
V_38 = F_11 (
& V_2 -> V_581 ,
V_582 , V_47 ) ;
if ( V_38 != V_29 )
goto exit;
V_3 = F_2 ( & V_2 -> V_583 ) ;
if ( V_3 & V_584 ) {
V_38 = V_30 ;
* V_577 = 0 ;
} else
* V_577 = ( T_3 ) F_15 ( V_3 , 32 , 32 ) ;
exit:
return V_38 ;
}
enum V_25
F_207 ( struct V_5 * V_6 , T_2 V_585 )
{
struct V_8 * V_9 ;
T_2 V_35 , V_36 = 0 , V_37 = 0 ;
enum V_25 V_38 ;
if ( V_6 == NULL ) {
V_38 = V_389 ;
goto exit;
}
V_9 = & V_6 -> V_14 [ V_6 -> V_53 ] ;
V_35 = V_585 ;
V_38 = F_18 ( V_9 ,
V_586 ,
V_86 ,
0 , & V_35 , & V_36 , & V_37 ) ;
exit:
return V_38 ;
}
enum V_25
F_208 ( struct V_431 * V_471 ,
T_3 V_32 , T_3 V_587 , T_3 V_34 ,
T_2 * V_35 , T_2 * V_36 )
{
enum V_25 V_38 ;
T_2 V_37 = 0 ;
if ( V_471 == NULL ) {
V_38 = V_565 ;
goto exit;
}
if ( ( V_587 ==
V_588 ) ||
( V_587 ==
V_589 ) ||
( V_587 ==
V_590 ) ||
( V_587 ==
V_591 ) ) {
V_37 = V_592 ;
}
V_38 = F_18 ( V_471 -> V_9 , V_32 , V_587 , V_34 ,
V_35 , V_36 , & V_37 ) ;
if ( V_38 != V_29 )
goto exit;
if ( ( V_587 != V_211 ) &&
( V_587 !=
V_589 ) )
* V_36 = 0 ;
exit:
return V_38 ;
}
enum V_25
F_209 ( struct V_431 * V_471 , T_3 V_32 ,
T_3 V_587 , T_3 V_34 , T_2 V_593 ,
T_2 V_594 )
{
T_2 V_35 , V_36 = 0 , V_37 = 0 ;
enum V_25 V_38 ;
if ( V_471 == NULL ) {
V_38 = V_565 ;
goto exit;
}
V_35 = V_593 ;
if ( ( V_587 == V_211 ) ||
( V_587 ==
V_589 ) )
V_36 = V_594 ;
V_38 = F_18 ( V_471 -> V_9 , V_32 , V_587 , V_34 ,
& V_35 , & V_36 , & V_37 ) ;
exit:
return V_38 ;
}
enum V_25 F_210 (
struct V_431 * V_471 ,
enum V_595 V_596 ,
struct V_597 * V_598 ,
T_5 V_599 )
{
T_2 V_35 , V_36 ;
enum V_25 V_38 = V_29 ;
if ( V_471 == NULL ) {
V_38 = V_565 ;
goto exit;
}
V_38 = F_208 ( V_471 ,
V_191 ,
V_600 ,
0 , & V_35 , & V_36 ) ;
if ( V_38 != V_29 )
goto exit;
V_35 &= ~ ( F_211 ( 0xf ) |
F_212 ( 0x3 ) ) ;
V_35 |= V_601 |
F_211 ( V_599 ) |
F_212 ( V_596 ) ;
if ( V_598 -> V_602 )
V_35 |= V_603 ;
if ( V_598 -> V_604 )
V_35 |= V_605 ;
if ( V_598 -> V_606 )
V_35 |= V_607 ;
if ( V_598 -> V_608 )
V_35 |= V_609 ;
if ( V_598 -> V_610 )
V_35 |=
V_611 ;
if ( V_598 -> V_612 )
V_35 |= V_613 ;
if ( F_213 ( V_35 ) )
V_35 &= ~ V_614 ;
else
V_35 |= V_614 ;
V_38 = F_209 ( V_471 ,
V_615 ,
V_600 ,
0 , V_35 , 0 ) ;
exit:
return V_38 ;
}
static void
F_214 ( T_3 V_200 , T_2 * V_35 , T_2 * V_36 ,
T_5 V_616 , T_4 * V_617 )
{
switch ( V_616 ) {
case 1 :
* V_35 = F_215 ( V_200 ) |
V_618 |
F_216 (
V_617 [ V_200 ] ) ;
case 2 :
* V_35 |=
F_217 ( V_200 ) |
V_619 |
F_218 (
V_617 [ V_200 ] ) ;
case 3 :
* V_36 = F_219 ( V_200 ) |
V_620 |
F_220 (
V_617 [ V_200 ] ) ;
case 4 :
* V_36 |=
F_221 ( V_200 ) |
V_621 |
F_222 (
V_617 [ V_200 ] ) ;
default:
return;
}
}
enum V_25 F_223 (
struct V_431 * * V_622 ,
T_3 V_623 ,
T_4 * V_624 ,
T_4 * V_617 ,
T_3 V_625 )
{
T_3 V_22 , V_200 , V_32 , V_587 ;
T_2 V_35 ;
T_2 V_36 ;
T_3 V_626 ;
enum V_25 V_38 = V_29 ;
struct V_431 * V_471 = V_622 [ 0 ] ;
if ( V_471 == NULL ) {
V_38 = V_565 ;
goto exit;
}
V_626 = ( ( ( T_3 ) 1 ) << V_625 ) ;
if ( V_471 -> V_9 -> V_6 -> V_287 . V_491
== V_627 ) {
V_32 = V_615 ;
V_587 =
V_588 ;
for ( V_200 = 0 ; V_200 < V_626 ; V_200 ++ ) {
V_36 = 0 ;
V_35 =
F_224 (
V_617 [ V_200 ] ) ;
V_38 = F_209 ( V_622 [ 0 ] ,
V_32 , V_587 , V_200 , V_35 , V_36 ) ;
if ( V_38 != V_29 )
goto exit;
}
for ( V_200 = 0 ; V_200 < V_626 ; V_200 ++ ) {
V_36 = 0 ;
V_35 =
V_628 |
F_224 (
V_617 [ V_200 ] ) ;
V_38 = F_209 (
V_622 [ V_624 [ V_617 [ V_200 ] ] ] , V_32 ,
V_587 , V_200 , V_35 , V_36 ) ;
if ( V_38 != V_29 )
goto exit;
}
} else {
V_32 = V_615 ;
V_587 =
V_589 ;
for ( V_22 = 0 ; V_22 < V_623 ; V_22 ++ ) {
for ( V_200 = 0 ; V_200 < V_626 ; ) {
V_35 = 0 ;
V_36 = 0 ;
while ( V_200 < V_626 ) {
if ( V_624 [ V_617 [ V_200 ] ] != V_22 ) {
V_200 ++ ;
continue;
}
F_214 ( V_200 ,
& V_35 , & V_36 , 1 , V_617 ) ;
V_200 ++ ;
break;
}
while ( V_200 < V_626 ) {
if ( V_624 [ V_617 [ V_200 ] ] != V_22 ) {
V_200 ++ ;
continue;
}
F_214 ( V_200 ,
& V_35 , & V_36 , 2 , V_617 ) ;
V_200 ++ ;
break;
}
while ( V_200 < V_626 ) {
if ( V_624 [ V_617 [ V_200 ] ] != V_22 ) {
V_200 ++ ;
continue;
}
F_214 ( V_200 ,
& V_35 , & V_36 , 3 , V_617 ) ;
V_200 ++ ;
break;
}
while ( V_200 < V_626 ) {
if ( V_624 [ V_617 [ V_200 ] ] != V_22 ) {
V_200 ++ ;
continue;
}
F_214 ( V_200 ,
& V_35 , & V_36 , 4 , V_617 ) ;
V_200 ++ ;
break;
}
if ( V_35 != 0 ) {
V_38 = F_209 (
V_622 [ V_22 ] ,
V_32 , V_587 ,
0 , V_35 , V_36 ) ;
if ( V_38 != V_29 )
goto exit;
}
}
}
}
exit:
return V_38 ;
}
enum V_25
F_225 ( struct V_105 * V_289 )
{
enum V_25 V_38 = V_29 ;
T_2 V_629 , V_11 ;
if ( V_289 == NULL )
return V_38 ;
V_629 = F_226 ( & V_289 -> V_2 -> V_16 ) ;
V_11 = F_2 ( & V_289 -> V_2 -> V_15 ) ;
V_11 = F_227 ( V_11 ) ;
if ( V_629 >= V_11 )
V_38 = V_30 ;
return V_38 ;
}
static enum V_25
F_228 (
struct V_5 * V_6 ,
struct V_8 * V_9 )
{
T_3 V_22 , V_257 = 0 , V_630 = 0 ;
T_2 V_3 ;
for ( V_22 = 0 ; V_22 < V_377 ; V_22 ++ ) {
V_3 = F_2 ( & V_9 -> V_145 ->
V_548 [ V_22 ] ) ;
V_630 =
( T_3 )
F_229
( V_3 ) ;
if ( V_257 < V_630 )
V_257 = V_630 ;
}
V_9 -> V_631 = V_257 + V_632 ;
V_3 = F_2 ( & V_9 -> V_145 -> V_633 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_3 & F_10 ( V_22 ) )
V_9 -> V_634 = V_22 ;
}
V_3 = F_2 ( & V_9 -> V_145 -> V_635 ) ;
if ( V_3 & V_636 )
F_230 ( V_9 -> V_6 , V_637 ) ;
else
F_230 ( V_9 -> V_6 , V_638 ) ;
return V_29 ;
}
static enum V_25
F_231 ( struct V_8 * V_9 )
{
enum V_25 V_38 ;
V_38 = F_11 (
& V_9 -> V_6 -> V_137 -> V_114 ,
F_50 (
1 << ( 16 - V_9 -> V_7 ) ) ,
V_9 -> V_6 -> V_287 . V_304 ) ;
return V_38 ;
}
static enum V_25
F_232 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
V_3 = F_233 ( 1 << ( 16 - V_7 ) ) ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) ,
& V_6 -> V_137 -> V_639 ) ;
return V_29 ;
}
static enum V_25
F_234 ( struct V_5 * V_6 , T_3 V_7 )
{
enum V_25 V_38 = V_29 ;
struct V_8 * V_9 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( V_9 -> V_104 ) {
V_38 = F_188 ( V_9 -> V_104 ) ;
if ( V_38 != V_29 )
goto exit;
}
if ( V_9 -> V_99 )
V_38 = F_201 ( V_9 -> V_99 ) ;
exit:
return V_38 ;
}
static void
F_235 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
struct V_8 * V_9 ;
struct V_250 * V_251 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_251 = V_9 -> V_251 ;
if ( V_251 -> V_289 . V_290 == V_640 )
return;
V_3 = F_2 ( & V_2 -> V_641 ) ;
V_3 |= V_642 ;
F_4 ( V_3 , & V_2 -> V_641 ) ;
V_3 = F_2 ( & V_9 -> V_2 -> V_15 ) ;
V_3 |= V_643 ;
F_4 ( V_3 , & V_9 -> V_2 -> V_15 ) ;
V_3 = F_2 ( & V_2 -> V_644 ) ;
if ( V_9 -> V_251 -> V_289 . V_498 !=
V_499 ) {
V_3 &= ~ F_236 ( 0x3 ) ;
switch ( V_9 -> V_251 -> V_289 . V_498 ) {
case V_645 :
V_3 |= F_236 (
V_646 ) ;
break;
case V_647 :
V_3 |= F_236 (
V_648 ) ;
break;
case V_649 :
V_3 |= F_236 (
V_650 ) ;
break;
}
}
F_4 ( V_3 , & V_2 -> V_644 ) ;
F_4 ( F_237 (
F_161 (
V_9 -> V_104 ) >> 3 ) , & V_2 -> V_651 ) ;
V_3 = F_2 ( & V_2 -> V_652 ) ;
V_3 |= V_653 ;
V_3 &= ~ F_238 ( 0x3 ) ;
V_3 |= F_238 (
V_654 ) ;
if ( V_6 -> V_287 . V_489 == V_655 )
V_3 |= V_656 ;
else
V_3 &= ~ V_656 ;
F_4 ( V_3 , & V_2 -> V_652 ) ;
}
static enum V_25
F_239 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
T_2 V_657 ;
enum V_25 V_38 = V_29 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_38 = F_196 ( V_6 -> V_116 , V_2 ) ;
if ( V_38 != V_29 )
goto exit;
V_3 = F_2 ( & V_2 -> V_658 ) ;
V_9 -> V_659 =
( T_3 ) F_240 (
V_3 + 1 ) / 2 ;
if ( V_9 -> V_251 -> V_256 . V_290 == V_293 ) {
V_9 -> V_660 = V_9 -> V_659 ;
if ( V_9 -> V_660 <
( ( V_9 -> V_251 -> V_256 . V_450 /
( V_9 -> V_251 -> V_256 . V_501 *
sizeof( struct V_555 ) ) ) *
V_9 -> V_251 -> V_256 . V_246 ) ) {
return V_249 ;
}
V_3 = F_241 (
( V_9 -> V_660 * 2 ) - 1 ) ;
}
F_4 ( V_3 , & V_2 -> V_661 ) ;
F_4 ( V_662 ,
& V_2 -> V_663 ) ;
V_3 = F_2 ( & V_2 -> V_664 ) ;
V_3 &= ~ ( F_242 ( 0x3 ) |
F_243 ( 0xFF ) ) ;
V_3 |= F_242 (
V_665 ) |
#ifndef F_195
V_666 |
#endif
F_243 ( 0 ) ;
F_4 ( V_3 , & V_2 -> V_664 ) ;
F_4 ( ( T_2 ) 0 , & V_2 -> V_667 ) ;
F_16 () ;
V_657 = F_2 ( & V_6 -> V_135 -> V_668 ) ;
V_9 -> V_567 =
(struct V_669 T_1 * )
( V_6 -> V_150 + ( V_7 *
F_244 (
V_657 ) ) ) ;
exit:
return V_38 ;
}
static enum V_25
F_245 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
struct V_8 * V_9 ;
struct V_250 * V_251 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_251 = V_9 -> V_251 ;
F_4 ( F_246 (
V_9 -> V_634 ) , & V_2 -> V_670 ) ;
if ( V_251 -> V_289 . V_290 == V_291 ) {
V_3 = F_2 ( & V_2 -> V_671 ) ;
if ( V_251 -> V_262 !=
V_263 ) {
if ( V_251 -> V_262 )
V_3 |= V_672 ;
else
V_3 &= ~ V_672 ;
}
F_4 ( V_3 , & V_2 -> V_671 ) ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_251 -> V_257 !=
V_258 ) {
V_3 &= ~ F_3 ( 0x3fff ) ;
if ( ( V_251 -> V_257 +
V_632 ) < V_9 -> V_631 )
V_3 |= F_3 (
V_251 -> V_257 +
V_632 ) ;
else
V_3 |= F_3 (
V_9 -> V_631 ) ;
}
F_4 ( V_3 , & V_2 -> V_4 ) ;
V_3 = F_2 ( & V_2 -> V_673 ) ;
V_3 &= ~ ( F_247 ( 0x3 ) |
V_674 ) ;
if ( V_6 -> V_287 . V_491 ==
V_675 ) {
V_3 |= F_247 (
0x2 ) |
V_674 ;
}
F_4 ( V_3 , & V_2 -> V_673 ) ;
}
return V_29 ;
}
static enum V_25
F_248 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
struct V_250 * V_287 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
V_2 = V_9 -> V_2 ;
V_287 = V_9 -> V_251 ;
F_4 ( 0 , & V_2 -> V_676 ) ;
F_4 ( 0 , & V_2 -> V_677 ) ;
F_4 ( 0 , & V_2 -> V_678 ) ;
F_4 ( 0 , & V_2 -> V_679 ) ;
if ( V_287 -> V_289 . V_290 == V_291 )
F_4 ( F_249 (
( V_7 * V_680 ) +
V_681 ) , & V_2 -> V_682 ) ;
V_3 = F_2 ( & V_2 -> V_683 ) ;
V_3 |= V_684 ;
F_4 ( V_3 , & V_2 -> V_683 ) ;
if ( V_287 -> V_256 . V_290 == V_293 ) {
V_3 = F_2 ( & V_2 -> V_685 [ V_686 ] ) ;
if ( V_287 -> V_510 . V_513 != V_514 ) {
V_3 &= ~ F_250 (
0x3ffffff ) ;
V_3 |= F_250 (
V_287 -> V_510 . V_513 ) ;
}
V_3 &= ~ V_687 ;
if ( V_287 -> V_510 . V_515 != V_514 ) {
if ( V_287 -> V_510 . V_515 )
V_3 |= V_688 ;
else
V_3 &= ~ V_688 ;
}
if ( V_287 -> V_510 . V_516 != V_514 ) {
if ( V_287 -> V_510 . V_516 )
V_3 |= V_689 ;
else
V_3 &= ~ V_689 ;
}
if ( V_287 -> V_510 . V_521 != V_514 ) {
V_3 &= ~ F_251 ( 0x3f ) ;
V_3 |= F_251 (
V_287 -> V_510 . V_521 ) ;
}
if ( V_287 -> V_510 . V_523 != V_514 ) {
V_3 &= ~ F_252 ( 0x3f ) ;
V_3 |= F_252 (
V_287 -> V_510 . V_523 ) ;
}
if ( V_287 -> V_510 . V_525 != V_514 ) {
V_3 &= ~ F_253 ( 0x3f ) ;
V_3 |= F_253 (
V_287 -> V_510 . V_525 ) ;
}
F_4 ( V_3 , & V_2 -> V_685 [ V_686 ] ) ;
V_9 -> V_571 = V_3 ;
V_3 = F_2 ( & V_2 -> V_690 [ V_686 ] ) ;
if ( V_287 -> V_510 . V_522 != V_514 ) {
V_3 &= ~ F_254 ( 0xffff ) ;
V_3 |= F_254 (
V_287 -> V_510 . V_522 ) ;
}
if ( V_287 -> V_510 . V_524 != V_514 ) {
V_3 &= ~ F_255 ( 0xffff ) ;
V_3 |= F_255 (
V_287 -> V_510 . V_524 ) ;
}
if ( V_287 -> V_510 . V_526 != V_514 ) {
V_3 &= ~ F_256 ( 0xffff ) ;
V_3 |= F_256 (
V_287 -> V_510 . V_526 ) ;
}
if ( V_287 -> V_510 . V_527 != V_514 ) {
V_3 &= ~ F_257 ( 0xffff ) ;
V_3 |= F_257 (
V_287 -> V_510 . V_527 ) ;
}
F_4 ( V_3 , & V_2 -> V_690 [ V_686 ] ) ;
V_3 = F_2 ( & V_2 -> V_691 [ V_686 ] ) ;
if ( V_287 -> V_510 . V_517 != V_514 ) {
if ( V_287 -> V_510 . V_517 )
V_3 |= V_692 ;
else
V_3 &= ~ V_692 ;
}
if ( V_287 -> V_510 . V_518 != V_514 ) {
V_3 &= ~ F_258 (
0x3ffffff ) ;
V_3 |= F_258 (
V_287 -> V_510 . V_518 ) ;
}
if ( V_287 -> V_510 . V_519 != V_514 ) {
V_3 &= ~ F_259 ( 0x3f ) ;
V_3 |= F_259 ( V_7 ) ;
}
if ( V_287 -> V_510 . V_520 != V_514 ) {
V_3 &= ~ F_260 (
0x3ffffff ) ;
V_3 |= F_260 (
V_287 -> V_510 . V_520 ) ;
}
F_4 ( V_3 , & V_2 -> V_691 [ V_686 ] ) ;
V_9 -> V_572 = V_3 ;
}
if ( V_287 -> V_289 . V_290 == V_291 ) {
V_3 = F_2 ( & V_2 -> V_685 [ V_681 ] ) ;
if ( V_287 -> V_528 . V_513 != V_514 ) {
V_3 &= ~ F_250 (
0x3ffffff ) ;
V_3 |= F_250 (
V_287 -> V_528 . V_513 ) ;
}
V_3 &= ~ V_687 ;
if ( V_287 -> V_528 . V_515 != V_514 ) {
if ( V_287 -> V_528 . V_515 )
V_3 |= V_688 ;
else
V_3 &= ~ V_688 ;
}
if ( V_287 -> V_528 . V_516 != V_514 ) {
if ( V_287 -> V_528 . V_516 )
V_3 |= V_689 ;
else
V_3 &= ~ V_689 ;
}
if ( V_287 -> V_528 . V_521 != V_514 ) {
V_3 &= ~ F_251 ( 0x3f ) ;
V_3 |= F_251 (
V_287 -> V_528 . V_521 ) ;
}
if ( V_287 -> V_528 . V_523 != V_514 ) {
V_3 &= ~ F_252 ( 0x3f ) ;
V_3 |= F_252 (
V_287 -> V_528 . V_523 ) ;
}
if ( V_287 -> V_528 . V_525 != V_514 ) {
V_3 &= ~ F_253 ( 0x3f ) ;
V_3 |= F_253 (
V_287 -> V_528 . V_525 ) ;
}
F_4 ( V_3 , & V_2 -> V_685 [ V_681 ] ) ;
V_9 -> V_480 = V_3 ;
V_3 = F_2 ( & V_2 -> V_690 [ V_681 ] ) ;
if ( V_287 -> V_528 . V_522 != V_514 ) {
V_3 &= ~ F_254 ( 0xffff ) ;
V_3 |= F_254 (
V_287 -> V_528 . V_522 ) ;
}
if ( V_287 -> V_528 . V_524 != V_514 ) {
V_3 &= ~ F_255 ( 0xffff ) ;
V_3 |= F_255 (
V_287 -> V_528 . V_524 ) ;
}
if ( V_287 -> V_528 . V_526 != V_514 ) {
V_3 &= ~ F_256 ( 0xffff ) ;
V_3 |= F_256 (
V_287 -> V_528 . V_526 ) ;
}
if ( V_287 -> V_528 . V_527 != V_514 ) {
V_3 &= ~ F_257 ( 0xffff ) ;
V_3 |= F_257 (
V_287 -> V_528 . V_527 ) ;
}
F_4 ( V_3 , & V_2 -> V_690 [ V_681 ] ) ;
V_3 = F_2 ( & V_2 -> V_691 [ V_681 ] ) ;
if ( V_287 -> V_528 . V_517 != V_514 ) {
if ( V_287 -> V_528 . V_517 )
V_3 |= V_692 ;
else
V_3 &= ~ V_692 ;
}
if ( V_287 -> V_528 . V_518 != V_514 ) {
V_3 &= ~ F_258 (
0x3ffffff ) ;
V_3 |= F_258 (
V_287 -> V_528 . V_518 ) ;
}
if ( V_287 -> V_528 . V_519 != V_514 ) {
V_3 &= ~ F_259 ( 0x3f ) ;
V_3 |= F_259 ( V_7 ) ;
}
if ( V_287 -> V_528 . V_520 != V_514 ) {
V_3 &= ~ F_260 (
0x3ffffff ) ;
V_3 |= F_260 (
V_287 -> V_528 . V_520 ) ;
}
F_4 ( V_3 , & V_2 -> V_691 [ V_681 ] ) ;
V_9 -> V_481 = V_3 ;
}
V_3 = 0 ;
F_4 ( V_3 , & V_2 -> V_685 [ V_693 ] ) ;
F_4 ( V_3 , & V_2 -> V_690 [ V_693 ] ) ;
F_4 ( V_3 , & V_2 -> V_691 [ V_693 ] ) ;
F_4 ( V_3 , & V_2 -> V_685 [ V_694 ] ) ;
F_4 ( V_3 , & V_2 -> V_690 [ V_694 ] ) ;
F_4 ( V_3 , & V_2 -> V_691 [ V_694 ] ) ;
V_3 = F_261 ( 150 ) ;
V_3 |= F_262 ( 0 ) ;
V_3 |= F_263 ( 3 ) ;
F_4 ( V_3 , & V_2 -> V_695 ) ;
return V_29 ;
}
static enum V_25
F_264 ( struct V_5 * V_6 , T_3 V_7 )
{
T_2 V_3 ;
T_3 V_696 ;
enum V_25 V_38 = V_29 ;
struct V_8 * V_9 ;
struct V_1 T_1 * V_2 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( ! ( V_6 -> V_169 & F_10 ( V_7 ) ) ) {
V_38 = V_697 ;
goto exit;
}
V_2 = V_9 -> V_2 ;
V_38 = F_194 ( V_9 -> V_2 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_245 ( V_6 , V_7 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_239 ( V_6 , V_7 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_248 ( V_6 , V_7 ) ;
if ( V_38 != V_29 )
goto exit;
V_3 = F_2 ( & V_2 -> V_698 ) ;
V_38 = F_205 ( V_9 , 1 , 0x78 , & V_696 ) ;
if ( V_38 == V_29 ) {
V_696 = ( V_696 & V_699 ) >> 12 ;
V_3 &=
~ ( F_265 ( 7 ) ) ;
V_3 |=
F_265 ( V_696 ) ;
V_3 |= V_700 ;
}
V_3 &= ~ ( F_266 ( 7 ) ) ;
V_3 |=
F_266 (
V_701 ) ;
V_3 |= V_702 ;
F_4 ( V_3 , & V_2 -> V_698 ) ;
exit:
return V_38 ;
}
static void F_267 ( struct V_5 * V_6 , T_3 V_7 )
{
struct V_8 * V_9 ;
V_9 = & V_6 -> V_14 [ V_7 ] ;
if ( V_9 -> V_42 == V_170 )
goto exit;
F_268 ( V_9 -> V_6 -> V_703 ,
V_9 -> V_6 -> V_704 , V_9 -> V_7 ) ;
V_6 -> V_101 . V_360 . V_705 [ V_9 -> V_7 ] = NULL ;
F_19 ( & V_9 -> V_41 ) ;
V_9 -> V_42 = V_170 ;
F_20 ( & V_9 -> V_41 ) ;
V_9 -> V_145 = NULL ;
V_9 -> V_567 = NULL ;
V_9 -> V_631 = 0 ;
V_9 -> V_634 = 0 ;
V_9 -> V_659 = 0 ;
V_9 -> V_660 = 0 ;
V_9 -> V_104 = NULL ;
V_9 -> V_99 = NULL ;
memset ( & V_9 -> V_622 , 0 , sizeof( struct V_223 ) ) ;
V_9 -> V_706 = 0 ;
V_9 -> V_314 = NULL ;
V_9 -> V_359 = NULL ;
V_9 -> V_362 = NULL ;
exit:
return;
}
static enum V_25
F_269 ( struct V_5 * V_6 , T_3 V_7 ,
struct V_250 * V_287 )
{
struct V_8 * V_9 ;
enum V_25 V_38 = V_29 ;
if ( ! ( V_6 -> V_169 & F_10 ( V_7 ) ) ) {
V_38 = V_697 ;
goto exit;
}
V_9 = & V_6 -> V_14 [ V_7 ] ;
F_84 ( & V_9 -> V_41 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_42 = V_707 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_251 = V_287 ;
V_9 -> V_2 = V_6 -> V_148 [ V_7 ] ;
V_9 -> V_145 = V_6 -> V_145 [ V_7 ] ;
F_232 ( V_6 , V_7 ) ;
V_38 = F_231 ( V_9 ) ;
if ( V_38 != V_29 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
goto exit;
}
V_38 = F_228 ( V_6 , V_9 ) ;
if ( V_38 != V_29 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
goto exit;
}
F_91 ( & V_9 -> V_622 ) ;
V_9 -> V_362 = & V_6 -> V_101 . V_363 . V_705 [ V_7 ] ;
F_270 ( V_6 -> V_703 ,
V_6 -> V_704 , V_7 ) ;
V_38 = F_264 ( V_6 , V_7 ) ;
if ( V_38 != V_29 )
F_267 ( V_6 , V_7 ) ;
exit:
return V_38 ;
}
enum V_25
F_271 ( struct V_431 * V_471 , T_3 V_708 )
{
T_2 V_3 ;
enum V_25 V_38 = V_29 ;
struct V_8 * V_9 ;
if ( V_471 == NULL ) {
V_38 = V_565 ;
goto exit;
}
V_9 = V_471 -> V_9 ;
V_708 += V_632 ;
if ( ( V_708 < V_709 ) || ( V_708 > V_9 -> V_631 ) )
V_38 = V_710 ;
V_3 = F_2 ( & V_9 -> V_2 -> V_4 ) ;
V_3 &= ~ F_3 ( 0x3fff ) ;
V_3 |= F_3 ( V_708 ) ;
F_4 ( V_3 , & V_9 -> V_2 -> V_4 ) ;
V_9 -> V_251 -> V_257 = V_708 - V_632 ;
exit:
return V_38 ;
}
static enum V_25
F_272 ( struct V_431 * V_471 )
{
enum V_25 V_38 = V_29 ;
struct V_8 * V_9 ;
V_9 = V_471 -> V_9 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto exit;
}
memcpy ( V_9 -> V_359 , V_9 -> V_314 ,
sizeof( struct V_313 ) ) ;
V_38 = F_114 ( V_9 , V_9 -> V_314 ) ;
exit:
return V_38 ;
}
static struct V_226 *
F_273 ( struct V_5 * V_279 , T_3 V_61 )
{
struct V_226 * V_234 = NULL ;
struct V_221 * V_222 ;
V_222 = & V_279 -> V_294 ;
if ( V_61 == V_222 -> V_237 ) {
if ( ! F_98 ( & V_222 -> V_240 ) )
V_234 = (struct V_226 * )
F_99 ( & V_222 -> V_240 ,
struct V_226 ,
V_231 ) ;
if ( V_234 != NULL ) {
F_89 ( & V_234 -> V_231 ) ;
V_222 -> V_232 -- ;
}
}
if ( V_234 != NULL )
F_177 ( V_222 ) ;
return V_234 ;
}
enum V_25
F_274 ( struct V_5 * V_6 ,
struct V_711 * V_281 ,
struct V_431 * * V_712 )
{
struct V_8 * V_9 ;
struct V_431 * V_471 ;
enum V_25 V_38 ;
V_9 = & V_6 -> V_14 [ V_281 -> V_7 ] ;
if ( V_9 -> V_42 == V_707 ) {
V_38 = V_713 ;
goto V_714;
}
V_38 = F_269 ( V_6 , V_281 -> V_7 ,
& V_6 -> V_287 . V_251 [ V_281 -> V_7 ] ) ;
if ( V_38 != V_29 )
goto V_714;
V_471 = F_104 ( sizeof( struct V_431 ) ) ;
if ( V_471 == NULL ) {
V_38 = V_243 ;
goto V_715;
}
V_471 -> V_9 = V_9 ;
if ( V_9 -> V_251 -> V_256 . V_290 == V_293 ) {
V_38 = F_204 ( V_471 , & V_281 -> V_716 ) ;
if ( V_38 != V_29 )
goto V_717;
}
if ( V_9 -> V_251 -> V_289 . V_290 == V_291 ) {
V_38 = F_190 ( V_471 , & V_281 -> V_718 ) ;
if ( V_38 != V_29 )
goto V_719;
F_235 ( V_6 , V_281 -> V_7 ) ;
}
V_9 -> V_99 -> V_720 =
( V_281 -> V_7 * V_680 ) +
V_686 ;
V_9 -> V_706 = F_273 ( V_6 ,
V_238 ) ;
if ( V_9 -> V_706 == NULL ) {
V_38 = V_243 ;
goto V_721;
}
V_9 -> V_314 = V_9 -> V_706 -> V_229 ;
memset ( V_9 -> V_314 , 0 ,
sizeof( struct V_313 ) ) ;
V_6 -> V_101 . V_360 . V_705 [ V_281 -> V_7 ] =
V_9 -> V_314 ;
V_9 -> V_359 =
& V_6 -> V_101 . V_360 . V_722 [ V_281 -> V_7 ] ;
memset ( V_9 -> V_359 , 0 ,
sizeof( struct V_313 ) ) ;
F_4 ( V_9 -> V_706 -> V_227 , & V_9 -> V_2 -> V_723 ) ;
V_38 = F_272 ( V_471 ) ;
if ( V_38 != V_29 )
goto V_721;
F_93 ( & V_471 -> V_231 , & V_9 -> V_622 ) ;
V_6 -> V_24 |= F_10 ( V_9 -> V_7 ) ;
* V_712 = V_471 ;
V_281 -> V_716 . V_417 = V_9 -> V_99 ;
V_281 -> V_718 . V_417 = V_9 -> V_104 ;
return V_29 ;
V_721:
if ( V_9 -> V_104 != NULL )
F_189 ( V_471 ) ;
V_719:
if ( V_9 -> V_99 != NULL )
F_202 ( V_471 ) ;
V_717:
F_106 ( V_471 ) ;
V_715:
F_267 ( V_6 , V_281 -> V_7 ) ;
V_714:
return V_38 ;
}
void F_275 ( struct V_431 * V_471 )
{
struct V_8 * V_9 = V_471 -> V_9 ;
struct V_105 * V_289 = V_9 -> V_104 ;
struct V_724 * V_725 = F_276 ( V_9 -> V_6 -> V_726 ) ;
T_2 V_727 , V_3 , V_728 ;
if ( V_725 -> V_729 ) {
V_727 = F_2 ( & V_9 -> V_2 -> V_730 ) ;
V_727 &= 0x1fff ;
} else
V_727 = V_289 -> V_287 -> V_292 * V_238 / 8 ;
V_728 = F_277 ( V_727 ) ;
F_4 ( F_278 ( V_728 ) ,
& V_9 -> V_2 -> V_16 ) ;
F_226 ( & V_9 -> V_2 -> V_16 ) ;
V_728 /= 2 ;
V_3 = F_2 ( & V_9 -> V_2 -> V_15 ) ;
V_3 = F_227 ( V_3 ) ;
V_3 &= 0x1ff ;
V_727 -= ( V_3 + 1 ) ;
V_3 = F_279 ( V_728 , V_727 ) / 4 ;
V_289 -> V_482 = F_279 ( V_289 -> V_482 , V_3 ) ;
if ( V_289 -> V_482 < 4 )
V_289 -> V_482 = 4 ;
}
static void
F_280 ( struct V_5 * V_279 ,
struct V_226 * V_234 )
{
struct V_221 * V_222 ;
V_222 = & V_279 -> V_294 ;
if ( V_234 -> V_97 == V_222 -> V_237 ) {
F_93 ( & V_234 -> V_231 , & V_222 -> V_240 ) ;
V_222 -> V_232 ++ ;
}
F_179 ( V_222 ) ;
}
enum V_25 F_281 ( struct V_431 * V_471 )
{
struct V_8 * V_9 = NULL ;
struct V_5 * V_279 = NULL ;
T_3 V_7 = V_471 -> V_9 -> V_7 ;
T_3 V_731 = TRUE ;
enum V_25 V_38 = V_29 ;
V_9 = V_471 -> V_9 ;
V_279 = V_9 -> V_6 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto V_732;
}
F_89 ( & V_471 -> V_231 ) ;
if ( ! F_98 ( & V_9 -> V_622 ) ) {
F_93 ( & V_471 -> V_231 , & V_9 -> V_622 ) ;
V_731 = FALSE ;
}
if ( ! V_731 ) {
V_38 = V_30 ;
goto V_732;
}
V_279 -> V_24 &= ~ F_10 ( V_7 ) ;
if ( V_9 -> V_104 != NULL )
F_189 ( V_471 ) ;
if ( V_9 -> V_99 != NULL )
F_202 ( V_471 ) ;
if ( V_9 -> V_706 != NULL )
F_280 ( V_279 , V_9 -> V_706 ) ;
F_106 ( V_471 ) ;
F_267 ( V_279 , V_7 ) ;
V_732:
return V_38 ;
}
enum V_25 F_282 ( struct V_431 * V_471 )
{
enum V_25 V_38 ;
T_3 V_7 ;
struct V_8 * V_9 = V_471 -> V_9 ;
V_7 = V_9 -> V_7 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto exit;
}
V_38 = F_232 ( V_9 -> V_6 , V_7 ) ;
if ( V_38 == V_29 )
V_9 -> V_362 -> V_733 ++ ;
exit:
return V_38 ;
}
enum V_25
F_283 ( struct V_431 * V_471 )
{
struct V_8 * V_9 = NULL ;
enum V_25 V_38 ;
struct V_5 * V_6 ;
T_3 V_7 ;
V_7 = V_471 -> V_9 -> V_7 ;
V_9 = V_471 -> V_9 ;
V_6 = V_9 -> V_6 ;
if ( V_9 -> V_42 == V_170 ) {
V_38 = V_300 ;
goto exit;
}
V_38 = F_231 ( V_9 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_234 ( V_6 , V_7 ) ;
if ( V_38 != V_29 )
goto exit;
V_38 = F_264 ( V_6 , V_7 ) ;
if ( V_38 != V_29 )
goto exit;
if ( V_9 -> V_104 != NULL )
F_235 ( V_6 , V_7 ) ;
memset ( V_9 -> V_314 , 0 ,
sizeof( struct V_313 ) ) ;
memset ( V_9 -> V_359 , 0 ,
sizeof( struct V_313 ) ) ;
F_4 ( V_9 -> V_706 -> V_227 ,
& V_9 -> V_2 -> V_723 ) ;
V_38 = F_272 ( V_471 ) ;
exit:
return V_38 ;
}
void
F_284 ( struct V_431 * V_471 )
{
struct V_5 * V_6 ;
T_2 V_3 ;
V_6 = V_471 -> V_9 -> V_6 ;
V_3 = F_285 (
1 << ( 16 - V_471 -> V_9 -> V_7 ) ) ;
F_17 ( ( T_3 ) F_15 ( V_3 , 0 , 32 ) ,
& V_6 -> V_137 -> V_734 ) ;
}
