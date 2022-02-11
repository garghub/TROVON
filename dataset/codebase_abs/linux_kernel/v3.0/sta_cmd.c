static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_7 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_9 ) +
V_10 ) ;
V_4 -> V_11 . V_12 . V_13 = F_2 ( V_5 ) ;
V_4 -> V_11 . V_12 . V_14 = F_2 ( V_2 -> V_15 ) ;
V_4 -> V_11 . V_12 . V_16 = F_2 ( V_2 -> V_17 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_27 * V_28 = & V_4 -> V_11 . V_28 ;
T_1 V_13 = * ( ( T_1 * ) V_26 ) ;
if ( V_5 != V_29 ) {
F_4 ( V_2 -> V_30 -> V_31 ,
L_1 ) ;
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_32 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_27 ) + V_10 ) ;
V_28 -> V_13 = F_2 ( V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_33 ,
void * V_26 )
{
struct V_34 * V_35 = & V_4 -> V_11 . V_36 ;
T_2 V_37 ;
F_6 ( V_2 -> V_30 -> V_31 , L_2 , V_33 ) ;
V_4 -> V_6 = F_2 ( V_38 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_34 )
- 1 + V_10 ) ;
if ( V_5 == V_39 ) {
V_35 -> V_40 = F_2 ( V_39 ) ;
V_35 -> V_41 = F_2 ( V_42 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ V_42 ) ;
}
switch ( V_33 ) {
case V_43 :
V_35 -> V_44 = F_2 ( ( T_1 ) V_43 ) ;
if ( V_5 == V_29 ) {
V_35 -> V_40 = F_2 ( V_29 ) ;
V_35 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
V_37 = * ( ( T_2 * ) V_26 ) ;
* ( ( V_45 * ) ( V_35 -> V_46 ) ) =
F_2 ( ( T_1 ) V_37 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
case V_47 :
V_35 -> V_44 = F_2 ( ( T_1 ) V_47 ) ;
if ( V_5 == V_29 ) {
V_35 -> V_40 = F_2 ( V_29 ) ;
V_35 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
V_37 = * ( ( T_2 * ) V_26 ) ;
* ( V_45 * ) ( V_35 -> V_46 ) =
F_2 ( ( T_1 ) V_37 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
case V_48 :
V_35 -> V_44 = F_2 ( ( T_1 ) V_48 ) ;
if ( V_5 == V_29 ) {
V_35 -> V_40 = F_2 ( V_29 ) ;
V_35 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
V_37 = ( * ( T_2 * ) V_26 ) ;
* ( ( V_45 * ) ( V_35 -> V_46 ) ) =
F_2 ( ( T_1 ) V_37 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
case V_49 :
V_35 -> V_44 = F_2 ( ( T_1 ) V_49 ) ;
if ( V_5 == V_29 ) {
V_35 -> V_40 = F_2 ( V_29 ) ;
V_35 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
V_37 = * ( T_2 * ) V_26 ;
* ( ( V_45 * ) ( V_35 -> V_46 ) ) =
F_2 ( ( T_1 ) V_37 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
default:
break;
}
F_6 ( V_2 -> V_30 -> V_31 ,
L_3
L_4 ,
V_5 , V_33 , F_7 ( V_35 -> V_41 ) ,
F_7 ( * ( V_45 * ) V_35 -> V_46 ) ) ;
return 0 ;
}
static int
F_8 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_50 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_51 ) +
V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_52 * V_53 = & V_4 -> V_11 . V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_1 * V_59 = ( T_1 * ) V_26 ;
T_2 V_60 ;
V_4 -> V_6 = F_2 ( V_61 ) ;
V_53 -> V_13 = F_2 ( V_5 ) ;
V_53 -> V_62 = 0 ;
V_56 = (struct V_55 * ) ( ( V_63 * ) V_53 +
sizeof( struct V_52 ) ) ;
V_56 -> type = F_2 ( V_64 ) ;
V_56 -> V_65 = F_2 ( sizeof( struct V_55 ) -
sizeof( struct V_66 ) ) ;
if ( V_59 != NULL ) {
V_56 -> V_67 = F_2 ( V_59 [ 0 ] ) ;
V_56 -> V_68 = F_2 ( V_59 [ 1 ] ) ;
for ( V_60 = 0 ;
V_60 < sizeof( V_56 -> V_69 ) / sizeof( T_1 ) ;
V_60 ++ )
V_56 -> V_69 [ V_60 ] =
F_2 ( V_59 [ 2 + V_60 ] ) ;
} else {
V_56 -> V_67 =
F_2 ( V_2 -> V_70 [ 0 ] ) ;
V_56 -> V_68 =
F_2 ( V_2 -> V_70 [ 1 ] ) ;
for ( V_60 = 0 ;
V_60 < sizeof( V_56 -> V_69 ) / sizeof( T_1 ) ;
V_60 ++ )
V_56 -> V_69 [ V_60 ] =
F_2 ( V_2 -> V_70 [ 2 + V_60 ] ) ;
}
V_58 = (struct V_57 * ) ( ( V_63 * ) V_56 +
sizeof( struct V_55 ) ) ;
V_58 -> type = F_2 ( V_71 ) ;
V_58 -> V_65 = F_2 ( sizeof( V_58 -> V_72 ) ) ;
V_58 -> V_72 = 0 ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_52 ) +
sizeof( struct V_55 ) +
sizeof( struct V_57 ) ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_75 * V_77 = & V_4 -> V_11 . V_78 ;
V_4 -> V_6 = F_2 ( V_79 ) ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_75 ) ) ;
switch ( V_5 ) {
case V_29 :
V_76 = (struct V_75 * ) V_26 ;
if ( V_76 -> V_80 ) {
V_74 = (struct V_73
* ) ( ( unsigned long ) V_26 +
sizeof( struct V_75 ) ) ;
memmove ( V_77 , V_26 ,
sizeof( struct V_75 ) +
sizeof( struct V_73 ) +
V_74 -> V_65 ) ;
V_74 = (struct V_73 * ) ( ( V_63 * )
V_77 +
sizeof( struct V_75 ) ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 ) +
sizeof( struct V_73 ) +
V_74 -> V_65 ) ;
} else {
memmove ( V_77 , V_26 ,
sizeof( struct V_75 ) ) ;
}
V_77 -> V_13 = F_2 ( V_5 ) ;
break;
case V_39 :
V_77 -> V_13 = F_2 ( V_5 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_81 * V_26 )
{
struct V_82 * V_30 = V_2 -> V_30 ;
struct V_83 * V_84 = & V_4 -> V_11 . V_85 ;
T_1 V_86 = false ;
if ( V_26 == NULL )
V_86 = true ;
V_4 -> V_6 = F_2 ( V_87 ) ;
if ( ! V_86 &&
( V_26 -> V_88
!= F_12 ( V_89 ) )
&& ( ( V_30 -> V_90 > 0 )
&& ( V_30 -> V_90 <= V_91 ) ) ) {
F_6 ( V_30 -> V_31 ,
L_5 ,
V_30 -> V_90 ) ;
memcpy ( ( ( V_63 * ) V_84 ) +
sizeof( struct V_83 ) ,
V_30 -> V_92 , V_30 -> V_90 ) ;
V_4 -> V_8 = F_2 ( V_30 -> V_90 +
sizeof( struct V_83 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( V_10 + sizeof( struct
V_83 ) ) ;
}
if ( V_86 ) {
V_84 -> V_13 = F_2 ( V_93 ) ;
V_84 -> V_11 . V_86 . V_94 = V_95 ;
} else {
V_84 -> V_13 = F_2 ( V_96 ) ;
V_84 -> V_11 . V_97 . V_88 = V_26 -> V_88 ;
V_84 -> V_11 . V_97 . V_98 = V_26 -> V_98 ;
V_84 -> V_11 . V_97 . V_99 = V_26 -> V_99 ;
F_6 ( V_30 -> V_31 ,
L_6 ,
V_84 -> V_11 . V_97 . V_88 ,
V_84 -> V_11 . V_97 . V_98 ,
V_84 -> V_11 . V_97 . V_99 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_100 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_101 ) +
V_10 ) ;
V_4 -> V_102 = 0 ;
V_4 -> V_11 . V_103 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_29 )
memcpy ( V_4 -> V_11 . V_103 . V_103 , V_2 -> V_104 ,
V_105 ) ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_26 ;
struct V_108 * V_109 = & V_4 -> V_11 . V_110 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_108 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_111 ) ;
V_109 -> V_13 = F_2 ( V_5 ) ;
V_109 -> V_112 =
F_2 ( ( T_1 ) V_107 -> V_113 ) ;
memcpy ( V_109 -> V_114 , V_107 -> V_114 ,
V_107 -> V_113 * V_105 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_26 )
{
struct V_115 * V_116 = & V_4 -> V_11 . V_116 ;
V_4 -> V_6 = F_2 ( V_117 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_115 )
+ V_10 ) ;
memcpy ( V_116 -> V_103 , ( V_63 * ) V_26 , V_105 ) ;
F_6 ( V_2 -> V_30 -> V_31 , L_7 , V_116 -> V_103 ) ;
V_116 -> V_118 = F_2 ( V_119 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_120 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_121 * V_122 ,
T_1 * V_123 )
{
int V_124 ;
V_63 V_60 ;
for ( V_60 = 0 ; V_60 < V_125 ; V_60 ++ ) {
if ( ( V_2 -> V_126 [ V_60 ] . V_127 == V_128 ) ||
( V_2 -> V_126 [ V_60 ] . V_127 == V_129 ) ) {
V_122 -> type =
F_2 ( V_130 ) ;
#define F_18 8
V_122 -> V_65 = F_2 ( ( T_1 )
( V_2 -> V_126 [ V_60 ] .
V_127 +
F_18 ) ) ;
V_122 -> V_131 =
F_2 ( V_132 ) ;
V_122 -> V_133 =
F_2 ( V_134 | V_135 |
V_136 ) ;
V_122 -> V_137 =
F_2 ( V_2 -> V_126 [ V_60 ] . V_127 ) ;
V_122 -> V_138 [ 0 ] = V_60 ;
if ( V_60 ==
( V_2 ->
V_139 & V_140 ) )
V_122 -> V_138 [ 1 ] = 1 ;
else
V_122 -> V_138 [ 1 ] = 0 ;
memmove ( & V_122 -> V_138 [ 2 ] ,
V_2 -> V_126 [ V_60 ] . V_141 ,
V_2 -> V_126 [ V_60 ] . V_127 ) ;
V_124 = V_2 -> V_126 [ V_60 ] . V_127 +
F_18 +
sizeof( struct V_66 ) ;
* V_123 += ( T_1 ) V_124 ;
V_122 =
(struct V_121 * )
( ( V_63 * ) V_122 +
V_124 ) ;
} else if ( ! V_2 -> V_126 [ V_60 ] . V_127 ) {
continue;
} else {
F_4 ( V_2 -> V_30 -> V_31 ,
L_8 ,
( V_60 + 1 ) , V_2 -> V_126 [ V_60 ] . V_127 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
T_2 V_33 , void * V_26 )
{
struct V_142 * V_141 =
& V_4 -> V_11 . V_141 ;
struct V_143 * V_144 =
(struct V_143 * ) V_26 ;
T_1 V_123 = 0 ;
int V_145 = 0 ;
const V_63 V_146 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_6 = F_2 ( V_147 ) ;
V_141 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_141 -> V_13 ) + V_10 ) ;
return V_145 ;
}
if ( ! V_144 ) {
memset ( & V_141 -> V_122 , 0 ,
( V_125 *
sizeof( struct V_121 ) ) ) ;
V_145 = F_17 ( V_2 ,
& V_141 -> V_122 ,
& V_123 ) ;
V_4 -> V_8 = F_2 ( V_123 +
sizeof( V_141 -> V_13 ) + V_10 ) ;
return V_145 ;
} else
memset ( & V_141 -> V_122 , 0 ,
sizeof( struct V_121 ) ) ;
if ( V_144 -> V_148 ) {
F_6 ( V_2 -> V_30 -> V_31 , L_9 ) ;
V_141 -> V_122 . V_131 =
F_2 ( V_149 ) ;
if ( V_33 == V_150 )
V_141 -> V_122 . V_133 =
F_2 ( V_134 ) ;
else
V_141 -> V_122 . V_133 =
F_2 ( ! V_134 ) ;
V_141 -> V_122 . V_138 [ 0 ] = V_144 -> V_151 ;
if ( ! V_2 -> V_152 . V_153 )
V_141 -> V_122 . V_138 [ 1 ] = 1 ;
else
V_141 -> V_122 . V_138 [ 1 ] = 0 ;
if ( 0 != memcmp ( V_144 -> V_103 , V_146 , sizeof( V_146 ) ) ) {
V_141 -> V_122 . V_133 |=
F_2 ( V_135 ) ;
} else {
V_141 -> V_122 . V_133 |=
F_2 ( V_136 ) ;
V_2 -> V_152 . V_153 = true ;
}
V_141 -> V_122 . type =
F_2 ( V_130 ) ;
V_141 -> V_122 . V_137 =
F_2 ( V_154 ) ;
memcpy ( & V_141 -> V_122 . V_138 [ 2 ] ,
V_144 -> V_141 , V_144 -> V_137 ) ;
memcpy ( & V_141 -> V_122 . V_138 [ 2 + V_144 -> V_137 ] ,
V_144 -> V_155 , V_156 ) ;
V_141 -> V_122 . V_65 =
F_2 ( V_154 + V_157 ) ;
V_123 = ( V_154 + V_157 ) +
sizeof( struct V_66 ) ;
V_4 -> V_8 = F_2 ( V_123 +
sizeof( V_141 -> V_13 ) + V_10 ) ;
return V_145 ;
}
if ( V_144 -> V_137 == V_158 ) {
F_6 ( V_2 -> V_30 -> V_31 , L_10 ) ;
V_141 -> V_122 . V_131 =
F_2 ( V_159 ) ;
if ( V_33 == V_150 )
V_141 -> V_122 . V_133 =
F_2 ( V_134 ) ;
else
V_141 -> V_122 . V_133 =
F_2 ( ! V_134 ) ;
if ( V_144 -> V_151 & V_160 )
V_141 -> V_122 . V_133 |=
F_2 ( V_135 ) ;
else
V_141 -> V_122 . V_133 |=
F_2 ( V_136 ) ;
} else if ( V_144 -> V_137 == V_161 ) {
F_6 ( V_2 -> V_30 -> V_31 , L_11 ) ;
V_141 -> V_122 . V_131 =
F_2 ( V_162 ) ;
V_141 -> V_122 . V_133 =
F_2 ( V_134 ) ;
if ( V_144 -> V_151 & V_160 )
V_141 -> V_122 . V_133 |=
F_2 ( V_135 ) ;
else
V_141 -> V_122 . V_133 |=
F_2 ( V_136 ) ;
}
if ( V_141 -> V_122 . V_131 ) {
V_141 -> V_122 . type =
F_2 ( V_130 ) ;
V_141 -> V_122 . V_137 =
F_2 ( ( T_1 ) V_144 -> V_137 ) ;
memcpy ( V_141 -> V_122 . V_138 , V_144 -> V_141 ,
V_144 -> V_137 ) ;
V_141 -> V_122 . V_65 =
F_2 ( ( T_1 ) V_144 -> V_137 +
V_157 ) ;
V_123 = ( T_1 ) ( V_144 -> V_137 + V_157 )
+ sizeof( struct V_66 ) ;
V_4 -> V_8 = F_2 ( V_123 +
sizeof( V_141 -> V_13 ) + V_10 ) ;
}
return V_145 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_82 * V_30 = V_2 -> V_30 ;
struct V_163 * V_164 =
& V_4 -> V_11 . V_164 ;
struct V_165 * V_166 =
& V_164 -> V_166 ;
V_63 V_167 = V_30 -> V_168 . V_167 ;
F_6 ( V_30 -> V_31 , L_12 , V_167 ) ;
V_4 -> V_6 = F_2 ( V_169 ) ;
V_164 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_164 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_166 -> V_170 . type = F_2 ( V_171 ) ;
memcpy ( V_166 -> V_172 , V_30 -> V_168 . V_172 ,
sizeof( V_166 -> V_172 ) ) ;
V_166 -> V_170 . V_173 = F_2 ( ( V_167 *
sizeof( struct V_174 ) ) +
sizeof( V_166 -> V_172 ) ) ;
if ( V_167 ) {
memcpy ( V_166 -> V_175 , V_30 -> V_168 . V_175 ,
V_167 *
sizeof( struct V_174 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_164 -> V_13 ) +
F_7 ( V_166 -> V_170 . V_173 ) +
sizeof( struct V_66 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_164 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_176 * V_177 =
& V_4 -> V_11 . V_178 ;
T_3 V_179 = F_7 ( V_177 -> V_179 ) ;
V_4 -> V_6 = F_2 ( V_180 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_176 )
+ V_10 ) ;
if ( V_5 == V_29 ) {
if ( ( V_2 -> V_30 -> V_181 & V_182 )
|| ( V_2 -> V_30 -> V_181 & V_183 ) )
V_177 -> V_179 =
F_2 ( V_184 ) ;
V_179 = F_7 ( V_177 -> V_179 ) ;
F_22 ( V_179 , V_2 -> V_30 -> V_185 ) ;
V_177 -> V_186 = F_2 ( * ( ( T_1 * ) V_26 ) ) ;
}
V_177 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_187 * V_188 =
& ( V_4 -> V_11 . V_189 ) ;
T_1 V_190 = 0 ;
V_4 -> V_6 = F_2 ( V_191 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_187 ) +
V_10 ) ;
V_4 -> V_102 = 0 ;
V_188 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_29 :
if ( V_26 != NULL )
V_190 = * ( T_1 * ) V_26 ;
V_188 -> V_190 = F_2 ( V_190 ) ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_26 )
{
struct V_192 * V_193 ;
V_193 = (struct V_192 * ) V_26 ;
switch ( F_7 ( V_4 -> V_6 ) ) {
case V_194 :
{
struct V_195 * V_196 ;
V_4 -> V_8 = F_2 ( sizeof( * V_196 ) + V_10 ) ;
V_196 = (struct V_195 * ) & V_4 ->
V_11 . V_196 ;
V_196 -> V_13 = F_2 ( V_5 ) ;
V_196 -> V_197 =
F_2 ( ( T_1 ) F_25 ( V_193 -> V_197 ) ) ;
V_196 -> V_46 = V_193 -> V_46 ;
break;
}
case V_198 :
{
struct V_199 * V_200 ;
V_4 -> V_8 = F_2 ( sizeof( * V_200 ) + V_10 ) ;
V_200 = (struct V_199 * ) & V_4 ->
V_11 . V_200 ;
V_200 -> V_13 = F_2 ( V_5 ) ;
V_200 -> V_197 =
F_2 ( ( T_1 ) F_25 ( V_193 -> V_197 ) ) ;
V_200 -> V_46 = ( V_63 ) F_25 ( V_193 -> V_46 ) ;
break;
}
case V_201 :
{
struct V_202 * V_203 ;
V_4 -> V_8 = F_2 ( sizeof( * V_203 ) + V_10 ) ;
V_203 = (struct V_202 * ) & V_4 ->
V_11 . V_203 ;
V_203 -> V_13 = F_2 ( V_5 ) ;
V_203 -> V_197 =
F_2 ( ( T_1 ) F_25 ( V_193 -> V_197 ) ) ;
V_203 -> V_46 = ( V_63 ) F_25 ( V_193 -> V_46 ) ;
break;
}
case V_204 :
{
struct V_205 * V_206 ;
V_4 -> V_8 = F_2 ( sizeof( * V_206 ) + V_10 ) ;
V_206 = (struct V_205 * ) & V_4 ->
V_11 . V_206 ;
V_206 -> V_13 = F_2 ( V_5 ) ;
V_206 -> V_197 =
F_2 ( ( T_1 ) F_25 ( V_193 -> V_197 ) ) ;
V_206 -> V_46 = ( V_63 ) F_25 ( V_193 -> V_46 ) ;
break;
}
case V_207 :
{
struct V_202 * V_208 ;
V_4 -> V_8 = F_2 ( sizeof( * V_208 ) + V_10 ) ;
V_208 = (struct V_202 * ) & V_4 ->
V_11 . V_203 ;
V_208 -> V_13 = F_2 ( V_5 ) ;
V_208 -> V_197 =
F_2 ( ( T_1 ) F_25 ( V_193 -> V_197 ) ) ;
V_208 -> V_46 = ( V_63 ) F_25 ( V_193 -> V_46 ) ;
break;
}
case V_209 :
{
struct V_210 * V_211 =
(struct V_210 * ) V_26 ;
struct V_212 * V_213 =
(struct V_212 * )
& V_4 -> V_11 . V_214 ;
V_4 -> V_8 = F_2 ( sizeof( * V_213 ) + V_10 ) ;
V_213 -> V_13 = F_2 ( V_5 ) ;
V_213 -> V_197 = V_211 -> V_197 ;
V_213 -> V_215 = V_211 -> V_215 ;
V_213 -> V_46 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 , T_3 V_216 ,
T_1 V_5 , T_2 V_33 ,
void * V_26 , void * V_217 )
{
struct V_3 * V_218 =
(struct V_3 * ) V_217 ;
int V_145 = 0 ;
switch ( V_216 ) {
case V_219 :
V_145 = F_27 ( V_2 , V_218 ) ;
break;
case V_32 :
V_145 = F_3 ( V_2 , V_218 , V_5 ,
V_26 ) ;
break;
case V_100 :
V_145 = F_13 ( V_2 , V_218 ,
V_5 ) ;
break;
case V_111 :
V_145 = F_14 ( V_218 , V_5 ,
V_26 ) ;
break;
case V_61 :
V_145 = F_9 ( V_2 , V_218 , V_5 ,
V_26 ) ;
break;
case V_79 :
V_145 = F_10 ( V_218 , V_5 ,
V_26 ) ;
break;
case V_220 :
V_145 = F_28 ( V_2 , V_218 , V_5 ,
( T_3 ) V_33 , V_26 ) ;
break;
case V_87 :
V_145 = F_11 ( V_2 , V_218 , V_5 ,
(struct V_81 * ) V_26 ) ;
break;
case V_221 :
V_145 = F_29 ( V_218 , V_26 ) ;
break;
case V_222 :
V_145 = F_30 ( V_218 ) ;
break;
case V_223 :
V_145 = F_31 ( V_2 , V_218 , V_26 ) ;
break;
case V_117 :
V_145 = F_15 ( V_2 , V_218 ,
V_26 ) ;
break;
case V_224 :
V_145 = F_32 ( V_2 , V_218 ,
V_26 ) ;
break;
case V_50 :
V_145 = F_8 ( V_218 ) ;
break;
case V_225 :
V_145 = F_33 ( V_2 , V_218 ,
V_26 ) ;
break;
case V_120 :
V_145 = F_16 ( V_218 ) ;
break;
case V_7 :
V_145 = F_1 ( V_2 , V_218 , V_5 ) ;
break;
case V_38 :
V_145 = F_5 ( V_2 , V_218 , V_5 ,
V_33 , V_26 ) ;
break;
case V_226 :
V_218 -> V_6 =
F_2 ( V_226 ) ;
V_218 -> V_8 =
F_2 ( sizeof( struct V_227 ) +
V_10 ) ;
V_2 -> V_228 = 0 ;
V_145 = 0 ;
break;
case V_229 :
V_218 -> V_6 = F_2 ( V_216 ) ;
V_218 -> V_11 . V_230 . V_231 =
( V_63 ) ( * ( ( T_2 * ) V_26 ) ) ;
memcpy ( & V_218 -> V_11 , V_26 ,
sizeof( struct V_232 ) ) ;
V_218 -> V_8 =
F_2 ( sizeof( struct V_232 ) +
V_10 ) ;
V_145 = 0 ;
break;
case V_180 :
V_145 = F_21 ( V_2 , V_218 , V_5 ,
V_26 ) ;
break;
case V_233 :
if ( V_2 -> V_30 -> V_234 == V_235 )
V_2 -> V_30 -> V_234 = V_236 ;
V_218 -> V_6 = F_2 ( V_216 ) ;
V_218 -> V_8 = F_2 ( V_10 ) ;
break;
case V_237 :
V_2 -> V_30 -> V_234 = V_235 ;
V_218 -> V_6 = F_2 ( V_216 ) ;
V_218 -> V_8 = F_2 ( V_10 ) ;
break;
case V_238 :
V_145 = F_34 ( V_218 , V_26 ) ;
break;
case V_239 :
V_145 = F_35 ( V_218 , V_26 ) ;
break;
case V_240 :
V_145 = F_36 ( V_2 , V_218 , V_26 ) ;
break;
case V_147 :
V_145 = F_19 ( V_2 , V_218 ,
V_5 , V_33 ,
V_26 ) ;
break;
case V_169 :
V_145 = F_20 ( V_2 , V_218 ,
V_5 ) ;
break;
case V_241 :
V_145 = F_37 ( V_2 , V_218 , V_5 ,
V_26 ) ;
break;
case V_242 :
V_145 = F_38 ( V_218 , V_5 ,
V_26 ) ;
break;
case V_243 :
V_145 = F_39 ( V_218 , V_5 ,
V_26 ) ;
break;
case V_244 :
F_6 ( V_2 -> V_30 -> V_31 ,
L_13 ) ;
V_218 -> V_6 = F_2 ( V_244 ) ;
V_218 -> V_8 =
F_2 ( sizeof( struct V_245 ) +
V_10 ) ;
V_145 = 0 ;
break;
case V_191 :
V_145 = F_23 ( V_218 , V_5 ,
V_26 ) ;
break;
case V_194 :
case V_198 :
case V_201 :
case V_204 :
case V_207 :
case V_209 :
V_145 = F_24 ( V_218 , V_5 , V_26 ) ;
break;
case V_246 :
V_218 -> V_6 = F_2 ( V_216 ) ;
if ( V_2 -> V_247 == V_248 )
V_218 -> V_11 . V_247 . V_249 =
V_250 ;
else if ( V_2 -> V_247 == V_251 )
V_218 -> V_11 . V_247 . V_249 =
V_252 ;
V_218 -> V_8 = F_2 ( sizeof( struct
V_253 ) + V_10 ) ;
V_145 = 0 ;
break;
default:
F_4 ( V_2 -> V_30 -> V_31 ,
L_14 , V_216 ) ;
V_145 = - 1 ;
break;
}
return V_145 ;
}
int F_40 ( struct V_1 * V_2 , V_63 V_254 )
{
int V_145 ;
T_1 V_190 = true ;
struct V_255 V_256 ;
struct V_257 V_258 ;
enum V_259 V_260 ;
if ( V_254 ) {
V_145 = F_41 ( V_2 , V_233 ,
V_29 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_145 = F_41 ( V_2 , V_219 ,
V_39 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_145 = F_41 ( V_2 ,
V_241 ,
V_29 , 0 ,
& V_2 -> V_30 -> V_261 ) ;
if ( V_145 )
return - 1 ;
V_2 -> V_30 -> V_262 = V_263 ;
V_145 = F_41 ( V_2 ,
V_220 ,
V_264 , V_265 , NULL ) ;
if ( V_145 )
return - 1 ;
}
V_145 = F_41 ( V_2 , V_61 ,
V_39 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_2 -> V_266 = 0 ;
V_145 = F_41 ( V_2 , V_79 ,
V_39 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_145 = F_41 ( V_2 ,
V_191 ,
V_29 , 0 , & V_190 ) ;
if ( V_145 )
return - 1 ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_256 . V_190 = true ;
V_145 = F_41 ( V_2 , V_242 ,
V_29 , 0 ,
( void * ) & V_256 ) ;
if ( V_145 )
return - 1 ;
V_145 = F_41 ( V_2 , V_32 ,
V_29 , 0 ,
& V_2 -> V_267 ) ;
if ( V_145 )
return - 1 ;
if ( V_254 ) {
V_258 . V_258 = V_268 ;
V_258 . V_269 = V_270 ;
V_145 = F_41 ( V_2 ,
V_220 ,
V_264 , V_271 ,
& V_258 ) ;
if ( V_145 )
return - 1 ;
}
V_260 = V_272 ;
V_145 = F_41 ( V_2 , V_38 ,
V_29 , V_49 , & V_260 ) ;
if ( V_145 )
F_4 ( V_2 -> V_30 -> V_31 , L_15 ) ;
V_2 -> V_30 -> V_273 = V_38 ;
V_145 = - V_274 ;
return V_145 ;
}
