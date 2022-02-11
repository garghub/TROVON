struct V_1 * F_1 ( T_1 V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (top_dev, &topology_device_list, list)
if ( V_4 -> V_2 == V_2 ) {
V_5 = V_4 -> V_7 ;
break;
}
F_4 ( & V_6 ) ;
return V_5 ;
}
struct V_1 * F_5 ( const struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (top_dev, &topology_device_list, list)
if ( V_4 -> V_7 -> V_9 == V_9 ) {
V_5 = V_4 -> V_7 ;
break;
}
F_4 ( & V_6 ) ;
return V_5 ;
}
static int F_6 ( void * V_10 , T_2 * V_11 )
{
struct V_12 * V_13 ;
T_3 V_14 ;
if ( ! V_11 )
return - V_15 ;
V_14 = F_7 ( V_16 , 0 , & V_13 ) ;
if ( V_14 == V_17 ) {
F_8 ( L_1 ) ;
return - V_18 ;
} else if ( F_9 ( V_14 ) ) {
const char * V_19 = F_10 ( V_14 ) ;
F_11 ( L_2 , V_19 ) ;
return - V_15 ;
}
if ( * V_11 >= V_13 -> V_20 && V_10 != NULL )
memcpy ( V_10 , V_13 , V_13 -> V_20 ) ;
* V_11 = V_13 -> V_20 ;
return 0 ;
}
static void F_12 ( struct V_3 * V_21 ,
struct V_22 * V_23 )
{
F_13 ( ! V_21 ) ;
F_13 ( ! V_23 ) ;
V_21 -> V_24 . V_25 = V_23 -> V_26 ;
V_21 -> V_24 . V_27 = V_23 -> V_28 ;
if ( V_23 -> V_29 & V_30 )
V_21 -> V_24 . V_31 |= V_32 ;
F_14 ( L_3 , V_23 -> V_26 ,
V_23 -> V_28 ) ;
}
static void F_15 ( struct V_3 * V_21 ,
struct V_22 * V_23 )
{
F_13 ( ! V_21 ) ;
F_13 ( ! V_23 ) ;
V_21 -> V_24 . V_33 = V_23 -> V_28 ;
V_21 -> V_24 . V_34 = V_23 -> V_35 ;
V_21 -> V_24 . V_36 = V_23 -> V_36 ;
V_21 -> V_24 . V_37 = V_23 -> V_38 ;
V_21 -> V_24 . V_39 = V_23 -> V_39 ;
V_21 -> V_24 . V_40 = V_23 -> V_41 ;
V_21 -> V_24 . V_42 = V_23 -> V_43 ;
V_21 -> V_24 . V_44 = V_23 -> V_45 ;
V_21 -> V_24 . V_46 = V_23 -> V_47 ;
V_21 -> V_24 . V_48 = V_23 -> V_49 ;
if ( V_23 -> V_29 & V_50 )
V_21 -> V_24 . V_31 |= V_51 ;
F_14 ( L_4 , V_23 -> V_35 ,
V_23 -> V_28 ) ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_3 * V_21 ;
int V_52 = 0 ;
F_13 ( ! V_23 ) ;
F_14 ( L_5 ,
V_23 -> V_53 , V_23 -> V_29 ) ;
F_3 (dev, &topology_device_list, list) {
if ( V_23 -> V_53 == V_52 ) {
if ( V_23 -> V_54 & V_55 )
F_12 ( V_21 , V_23 ) ;
if ( V_23 -> V_54 & V_56 )
F_15 ( V_21 , V_23 ) ;
break;
}
V_52 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_3 * V_21 ;
int V_52 = 0 ;
F_13 ( ! V_58 ) ;
F_14 ( L_6 ,
V_58 -> V_61 ) ;
F_3 (dev, &topology_device_list, list) {
if ( V_58 -> V_61 == V_52 ) {
V_60 = F_18 ( V_60 ) ;
if ( V_60 == NULL )
return - V_62 ;
if ( V_21 -> V_24 . V_25 == 0 )
V_60 -> V_63 = V_64 ;
else
V_60 -> V_63 = V_65 ;
if ( V_58 -> V_54 & V_66 )
V_60 -> V_54 |= V_67 ;
if ( V_58 -> V_54 & V_68 )
V_60 -> V_54 |= V_69 ;
V_60 -> V_70 =
( ( V_71 ) V_58 -> V_72 << 32 ) +
V_58 -> V_73 ;
V_60 -> V_74 = V_58 -> V_74 ;
V_21 -> V_75 ++ ;
F_19 ( & V_60 -> V_76 , & V_21 -> V_77 ) ;
break;
}
V_52 ++ ;
}
return 0 ;
}
static int F_20 ( struct V_78 * V_79 )
{
struct V_80 * V_60 ;
struct V_3 * V_21 ;
T_1 V_81 ;
F_13 ( ! V_79 ) ;
V_81 = V_79 -> V_28 ;
F_14 ( L_7 , V_81 ) ;
F_3 (dev, &topology_device_list, list)
if ( V_81 == V_21 -> V_24 . V_27 ||
V_81 == V_21 -> V_24 . V_33 ) {
V_60 = F_18 ( V_60 ) ;
if ( V_60 == NULL )
return - V_62 ;
V_60 -> V_28 = V_81 ;
V_60 -> V_82 = V_79 -> V_82 ;
V_60 -> V_83 = V_79 -> V_83 ;
V_60 -> V_84 = V_79 -> V_85 ;
V_60 -> V_86 = V_79 -> V_87 ;
V_60 -> V_88 = V_79 -> V_89 ;
V_60 -> V_90 = V_79 -> V_90 ;
if ( V_79 -> V_54 & V_91 )
V_60 -> V_92 |= V_93 ;
if ( V_79 -> V_54 & V_94 )
V_60 -> V_92 |= V_95 ;
if ( V_79 -> V_54 & V_96 )
V_60 -> V_92 |= V_97 ;
if ( V_79 -> V_54 & V_98 )
V_60 -> V_92 |= V_99 ;
V_21 -> V_100 ++ ;
V_21 -> V_24 . V_101 ++ ;
F_19 ( & V_60 -> V_76 , & V_21 -> V_102 ) ;
break;
}
return 0 ;
}
static int F_21 ( struct V_103 * V_104 )
{
struct V_105 * V_60 ;
struct V_3 * V_21 ;
T_1 V_52 = 0 ;
T_1 V_106 ;
T_1 V_107 ;
F_13 ( ! V_104 ) ;
V_106 = V_104 -> V_108 ;
V_107 = V_104 -> V_109 ;
F_14 ( L_8 , V_106 ) ;
F_3 (dev, &topology_device_list, list) {
if ( V_106 == V_52 ) {
V_60 = F_18 ( V_60 ) ;
if ( V_60 == NULL )
return - V_62 ;
V_60 -> V_110 = V_106 ;
V_60 -> V_111 = V_107 ;
V_60 -> V_112 = V_104 -> V_113 ;
V_60 -> V_114 = V_104 -> V_115 ;
V_60 -> V_116 = 1 ;
V_60 -> V_117 = V_104 -> V_118 ;
V_60 -> V_119 = V_104 -> V_120 ;
V_60 -> V_121 = V_104 -> V_122 ;
V_60 -> V_123 = V_104 -> V_124 ;
V_60 -> V_125 =
V_104 -> V_126 ;
V_21 -> V_127 ++ ;
V_21 -> V_24 . V_128 ++ ;
F_19 ( & V_60 -> V_76 , & V_21 -> V_129 ) ;
break;
}
V_52 ++ ;
}
return 0 ;
}
static int F_22 ( struct V_130 * V_131 )
{
struct V_22 * V_23 ;
struct V_57 * V_58 ;
struct V_78 * V_79 ;
struct V_103 * V_104 ;
int V_132 = 0 ;
F_13 ( ! V_131 ) ;
switch ( V_131 -> type ) {
case V_133 :
V_23 = (struct V_22 * ) V_131 ;
V_132 = F_16 ( V_23 ) ;
break;
case V_134 :
V_58 = (struct V_57 * ) V_131 ;
V_132 = F_17 ( V_58 ) ;
break;
case V_135 :
V_79 = (struct V_78 * ) V_131 ;
V_132 = F_20 ( V_79 ) ;
break;
case V_136 :
F_14 ( L_9 ) ;
break;
case V_137 :
F_14 ( L_10 ) ;
break;
case V_138 :
V_104 = (struct V_103 * ) V_131 ;
V_132 = F_21 ( V_104 ) ;
break;
default:
F_8 ( L_11 ,
V_131 -> type ) ;
}
return V_132 ;
}
static void F_23 ( struct V_3 * V_21 )
{
struct V_59 * V_58 ;
struct V_80 * V_79 ;
struct V_105 * V_104 ;
F_13 ( ! V_21 ) ;
F_24 ( & V_21 -> V_76 ) ;
while ( V_21 -> V_77 . V_139 != & V_21 -> V_77 ) {
V_58 = F_25 ( V_21 -> V_77 . V_139 ,
struct V_59 , V_76 ) ;
F_24 ( & V_58 -> V_76 ) ;
F_26 ( V_58 ) ;
}
while ( V_21 -> V_102 . V_139 != & V_21 -> V_102 ) {
V_79 = F_25 ( V_21 -> V_102 . V_139 ,
struct V_80 , V_76 ) ;
F_24 ( & V_79 -> V_76 ) ;
F_26 ( V_79 ) ;
}
while ( V_21 -> V_129 . V_139 != & V_21 -> V_129 ) {
V_104 = F_25 ( V_21 -> V_129 . V_139 ,
struct V_105 , V_76 ) ;
F_24 ( & V_104 -> V_76 ) ;
F_26 ( V_104 ) ;
}
F_26 ( V_21 ) ;
V_140 . V_141 -- ;
}
static void F_27 ( void )
{
struct V_3 * V_21 ;
while ( V_142 . V_139 != & V_142 ) {
V_21 = F_25 ( V_142 . V_139 ,
struct V_3 , V_76 ) ;
F_23 ( V_21 ) ;
}
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
}
static struct V_3 * F_28 ( void )
{
struct V_3 * V_21 ;
V_21 = F_18 ( V_21 ) ;
if ( V_21 == NULL ) {
F_11 ( L_12 ) ;
return NULL ;
}
F_29 ( & V_21 -> V_77 ) ;
F_29 ( & V_21 -> V_102 ) ;
F_29 ( & V_21 -> V_129 ) ;
F_19 ( & V_21 -> V_76 , & V_142 ) ;
V_140 . V_141 ++ ;
return V_21 ;
}
static int F_30 ( void * V_10 )
{
struct V_3 * V_4 ;
struct V_130 * V_131 ;
T_4 V_143 ;
int V_132 ;
struct V_144 * V_13 = (struct V_144 * ) V_10 ;
T_4 V_145 ;
T_1 V_146 ;
if ( ! V_10 )
return - V_15 ;
V_145 = V_13 -> V_147 ;
V_146 = V_13 -> V_20 ;
F_14 ( L_13 , V_145 ) ;
for ( V_143 = 0 ; V_143 < V_145 ; V_143 ++ ) {
V_4 = F_28 () ;
if ( ! V_4 ) {
F_27 () ;
return - V_62 ;
}
}
V_140 . V_148 =
( * ( ( V_71 * ) V_13 -> V_149 ) ) & V_150 ;
V_140 . V_151 = * ( ( V_71 * ) V_13 -> V_152 ) ;
V_140 . V_153 = V_13 -> V_154 ;
V_131 = (struct V_130 * ) ( V_13 + 1 ) ;
while ( ( char * ) V_131 + sizeof( struct V_130 ) <
( ( char * ) V_10 ) + V_146 ) {
if ( V_131 -> V_54 & V_155 ) {
V_132 = F_22 ( V_131 ) ;
if ( V_132 != 0 ) {
F_27 () ;
return V_132 ;
}
}
V_131 = ( F_31 ( V_131 ) ) ( ( char * ) V_131 +
V_131 -> V_20 ) ;
}
V_140 . V_156 ++ ;
V_157 = 1 ;
return 0 ;
}
static T_5 F_32 ( struct V_158 * V_159 , struct V_160 * V_161 ,
char * V_162 )
{
T_5 V_132 ;
V_162 [ 0 ] = 0 ;
if ( V_161 == & V_140 . V_163 ) {
V_132 = F_33 ( V_162 , V_140 . V_156 ) ;
} else if ( V_161 == & V_140 . V_164 ) {
F_34 ( V_162 , L_14 ,
V_140 . V_151 ) ;
F_34 ( V_162 , L_15 ,
V_140 . V_148 ) ;
V_132 = F_34 ( V_162 , L_16 ,
V_140 . V_153 ) ;
} else {
V_132 = - V_15 ;
}
return V_132 ;
}
static T_5 F_35 ( struct V_158 * V_159 , struct V_160 * V_161 ,
char * V_162 )
{
T_5 V_132 ;
struct V_105 * V_104 ;
V_162 [ 0 ] = 0 ;
V_104 = F_25 ( V_161 , struct V_105 , V_161 ) ;
F_36 ( V_162 , L_17 , V_104 -> V_165 ) ;
F_36 ( V_162 , L_18 , V_104 -> V_112 ) ;
F_36 ( V_162 , L_19 , V_104 -> V_114 ) ;
F_36 ( V_162 , L_20 , V_104 -> V_110 ) ;
F_36 ( V_162 , L_21 , V_104 -> V_111 ) ;
F_36 ( V_162 , L_22 , V_104 -> V_116 ) ;
F_36 ( V_162 , L_23 , V_104 -> V_117 ) ;
F_36 ( V_162 , L_24 , V_104 -> V_119 ) ;
F_36 ( V_162 , L_25 , V_104 -> V_121 ) ;
F_36 ( V_162 , L_26 , V_104 -> V_123 ) ;
F_36 ( V_162 , L_27 ,
V_104 -> V_125 ) ;
V_132 = F_36 ( V_162 , L_28 , V_104 -> V_54 ) ;
return V_132 ;
}
static T_5 F_37 ( struct V_158 * V_159 , struct V_160 * V_161 ,
char * V_162 )
{
T_5 V_132 ;
struct V_59 * V_58 ;
V_162 [ 0 ] = 0 ;
V_58 = F_25 ( V_161 , struct V_59 , V_161 ) ;
F_36 ( V_162 , L_29 , V_58 -> V_63 ) ;
F_34 ( V_162 , L_30 , V_58 -> V_70 ) ;
F_36 ( V_162 , L_28 , V_58 -> V_54 ) ;
F_36 ( V_162 , L_31 , V_58 -> V_74 ) ;
V_132 = F_36 ( V_162 , L_32 , V_58 -> V_166 ) ;
return V_132 ;
}
static T_5 F_38 ( struct V_158 * V_159 , struct V_160 * V_161 ,
char * V_162 )
{
T_5 V_132 ;
T_1 V_52 ;
struct V_80 * V_79 ;
V_162 [ 0 ] = 0 ;
V_79 = F_25 ( V_161 , struct V_80 , V_161 ) ;
F_36 ( V_162 , L_33 ,
V_79 -> V_28 ) ;
F_36 ( V_162 , L_34 , V_79 -> V_82 ) ;
F_36 ( V_162 , L_35 , V_79 -> V_83 ) ;
F_36 ( V_162 , L_36 , V_79 -> V_84 ) ;
F_36 ( V_162 , L_37 ,
V_79 -> V_86 ) ;
F_36 ( V_162 , L_38 , V_79 -> V_88 ) ;
F_36 ( V_162 , L_39 , V_79 -> V_90 ) ;
F_36 ( V_162 , L_17 , V_79 -> V_92 ) ;
snprintf ( V_162 , V_167 , L_40 , V_162 ) ;
for ( V_52 = 0 ; V_52 < V_168 ; V_52 ++ )
V_132 = snprintf ( V_162 , V_167 , L_41 ,
V_162 , V_79 -> V_169 [ V_52 ] ,
( V_52 == V_168 - 1 ) ?
L_42 : L_43 ) ;
return V_132 ;
}
static T_5 F_39 ( struct V_158 * V_159 , struct V_160 * V_161 ,
char * V_162 )
{
struct V_3 * V_21 ;
char V_170 [ V_171 ] ;
T_1 V_52 ;
T_1 V_172 ;
V_162 [ 0 ] = 0 ;
if ( strcmp ( V_161 -> V_173 , L_44 ) == 0 ) {
V_21 = F_25 ( V_161 , struct V_3 ,
V_174 ) ;
return F_33 ( V_162 , V_21 -> V_2 ) ;
}
if ( strcmp ( V_161 -> V_173 , L_45 ) == 0 ) {
V_21 = F_25 ( V_161 , struct V_3 ,
V_175 ) ;
for ( V_52 = 0 ; V_52 < V_171 ; V_52 ++ ) {
V_170 [ V_52 ] =
( char ) V_21 -> V_24 . V_176 [ V_52 ] ;
if ( V_21 -> V_24 . V_176 [ V_52 ] == 0 )
break;
}
V_170 [ V_171 - 1 ] = 0x0 ;
return F_40 ( V_162 , V_170 ) ;
}
V_21 = F_25 ( V_161 , struct V_3 ,
V_164 ) ;
F_36 ( V_162 , L_46 ,
V_21 -> V_24 . V_25 ) ;
F_36 ( V_162 , L_47 ,
V_21 -> V_24 . V_34 ) ;
if ( V_21 -> V_75 < V_21 -> V_24 . V_40 ) {
F_8 ( L_48 ,
V_21 -> V_24 . V_40 ,
V_21 -> V_75 ) ;
F_36 ( V_162 , L_49 ,
V_21 -> V_75 ) ;
} else {
F_36 ( V_162 , L_49 ,
V_21 -> V_24 . V_40 ) ;
}
F_36 ( V_162 , L_50 ,
V_21 -> V_24 . V_101 ) ;
F_36 ( V_162 , L_51 ,
V_21 -> V_24 . V_128 ) ;
F_36 ( V_162 , L_52 ,
V_21 -> V_24 . V_27 ) ;
F_36 ( V_162 , L_53 ,
V_21 -> V_24 . V_33 ) ;
F_36 ( V_162 , L_54 ,
V_21 -> V_24 . V_31 ) ;
F_36 ( V_162 , L_55 ,
V_21 -> V_24 . V_37 ) ;
F_36 ( V_162 , L_56 ,
V_21 -> V_24 . V_36 ) ;
F_36 ( V_162 , L_57 ,
V_21 -> V_24 . V_177 ) ;
F_36 ( V_162 , L_58 ,
V_21 -> V_24 . V_39 ) ;
F_36 ( V_162 , L_59 ,
V_21 -> V_24 . V_42 ) ;
F_36 ( V_162 , L_60 ,
V_21 -> V_24 . V_178 ) ;
F_36 ( V_162 , L_61 ,
V_21 -> V_24 . V_44 ) ;
F_36 ( V_162 , L_62 ,
V_21 -> V_24 . V_46 ) ;
F_36 ( V_162 , L_63 ,
V_21 -> V_24 . V_48 ) ;
F_36 ( V_162 , L_64 ,
V_21 -> V_24 . V_179 ) ;
F_36 ( V_162 , L_65 ,
V_21 -> V_24 . V_180 ) ;
F_36 ( V_162 , L_66 ,
V_21 -> V_24 . V_181 ) ;
if ( V_21 -> V_7 ) {
V_172 =
F_41 ( V_21 -> V_7 -> V_182 -> V_183 ) ;
if ( V_172 ) {
V_21 -> V_24 . V_31 |=
V_184 ;
V_21 -> V_24 . V_31 |=
( ( V_172 <<
V_185 ) &
V_186 ) ;
}
F_36 ( V_162 , L_67 ,
V_187 -> V_188 (
V_21 -> V_7 -> V_189 ) ) ;
F_34 ( V_162 , L_68 ,
V_187 -> V_190 ( V_21 -> V_7 -> V_189 ) ) ;
F_36 ( V_162 , L_69 ,
V_187 -> V_191 (
V_21 -> V_7 -> V_189 ,
V_192 ) ) ;
}
return F_36 ( V_162 , L_70 ,
F_42 ( 0 ) / 1000 ) ;
}
static void F_43 ( struct V_158 * V_159 , struct V_160 * V_161 )
{
F_44 ( V_159 , V_161 ) ;
F_45 ( V_159 ) ;
F_46 ( V_159 ) ;
}
static void F_47 ( struct V_3 * V_21 )
{
struct V_105 * V_104 ;
struct V_80 * V_79 ;
struct V_59 * V_58 ;
F_13 ( ! V_21 ) ;
if ( V_21 -> V_193 ) {
F_3 (iolink, &dev->io_link_props, list)
if ( V_104 -> V_159 ) {
F_43 ( V_104 -> V_159 ,
& V_104 -> V_161 ) ;
V_104 -> V_159 = NULL ;
}
F_45 ( V_21 -> V_193 ) ;
F_46 ( V_21 -> V_193 ) ;
V_21 -> V_193 = NULL ;
}
if ( V_21 -> V_194 ) {
F_3 (cache, &dev->cache_props, list)
if ( V_79 -> V_159 ) {
F_43 ( V_79 -> V_159 ,
& V_79 -> V_161 ) ;
V_79 -> V_159 = NULL ;
}
F_45 ( V_21 -> V_194 ) ;
F_46 ( V_21 -> V_194 ) ;
V_21 -> V_194 = NULL ;
}
if ( V_21 -> V_195 ) {
F_3 (mem, &dev->mem_props, list)
if ( V_58 -> V_159 ) {
F_43 ( V_58 -> V_159 , & V_58 -> V_161 ) ;
V_58 -> V_159 = NULL ;
}
F_45 ( V_21 -> V_195 ) ;
F_46 ( V_21 -> V_195 ) ;
V_21 -> V_195 = NULL ;
}
if ( V_21 -> V_196 ) {
F_44 ( V_21 -> V_196 , & V_21 -> V_174 ) ;
F_44 ( V_21 -> V_196 , & V_21 -> V_175 ) ;
F_44 ( V_21 -> V_196 , & V_21 -> V_164 ) ;
F_45 ( V_21 -> V_196 ) ;
F_46 ( V_21 -> V_196 ) ;
V_21 -> V_196 = NULL ;
}
}
static int F_48 ( struct V_3 * V_21 ,
T_1 V_81 )
{
struct V_105 * V_104 ;
struct V_80 * V_79 ;
struct V_59 * V_58 ;
int V_132 ;
T_1 V_52 ;
F_13 ( ! V_21 ) ;
F_13 ( V_21 -> V_196 ) ;
V_21 -> V_196 = F_18 ( V_21 -> V_196 ) ;
if ( ! V_21 -> V_196 )
return - V_62 ;
V_132 = F_49 ( V_21 -> V_196 , & V_197 ,
V_140 . V_198 , L_71 , V_81 ) ;
if ( V_132 < 0 )
return V_132 ;
V_21 -> V_195 = F_50 ( L_72 , V_21 -> V_196 ) ;
if ( ! V_21 -> V_195 )
return - V_62 ;
V_21 -> V_194 = F_50 ( L_73 , V_21 -> V_196 ) ;
if ( ! V_21 -> V_194 )
return - V_62 ;
V_21 -> V_193 = F_50 ( L_74 , V_21 -> V_196 ) ;
if ( ! V_21 -> V_193 )
return - V_62 ;
V_21 -> V_174 . V_173 = L_44 ;
V_21 -> V_174 . V_199 = V_200 ;
F_51 ( & V_21 -> V_174 ) ;
V_21 -> V_175 . V_173 = L_45 ;
V_21 -> V_175 . V_199 = V_200 ;
F_51 ( & V_21 -> V_175 ) ;
V_21 -> V_164 . V_173 = L_75 ;
V_21 -> V_164 . V_199 = V_200 ;
F_51 ( & V_21 -> V_164 ) ;
V_132 = F_52 ( V_21 -> V_196 , & V_21 -> V_174 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_52 ( V_21 -> V_196 , & V_21 -> V_175 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_52 ( V_21 -> V_196 , & V_21 -> V_164 ) ;
if ( V_132 < 0 )
return V_132 ;
V_52 = 0 ;
F_3 (mem, &dev->mem_props, list) {
V_58 -> V_159 = F_53 ( sizeof( struct V_158 ) , V_201 ) ;
if ( ! V_58 -> V_159 )
return - V_62 ;
V_132 = F_49 ( V_58 -> V_159 , & V_202 ,
V_21 -> V_195 , L_71 , V_52 ) ;
if ( V_132 < 0 )
return V_132 ;
V_58 -> V_161 . V_173 = L_75 ;
V_58 -> V_161 . V_199 = V_200 ;
F_51 ( & V_58 -> V_161 ) ;
V_132 = F_52 ( V_58 -> V_159 , & V_58 -> V_161 ) ;
if ( V_132 < 0 )
return V_132 ;
V_52 ++ ;
}
V_52 = 0 ;
F_3 (cache, &dev->cache_props, list) {
V_79 -> V_159 = F_53 ( sizeof( struct V_158 ) , V_201 ) ;
if ( ! V_79 -> V_159 )
return - V_62 ;
V_132 = F_49 ( V_79 -> V_159 , & V_92 ,
V_21 -> V_194 , L_71 , V_52 ) ;
if ( V_132 < 0 )
return V_132 ;
V_79 -> V_161 . V_173 = L_75 ;
V_79 -> V_161 . V_199 = V_200 ;
F_51 ( & V_79 -> V_161 ) ;
V_132 = F_52 ( V_79 -> V_159 , & V_79 -> V_161 ) ;
if ( V_132 < 0 )
return V_132 ;
V_52 ++ ;
}
V_52 = 0 ;
F_3 (iolink, &dev->io_link_props, list) {
V_104 -> V_159 = F_53 ( sizeof( struct V_158 ) , V_201 ) ;
if ( ! V_104 -> V_159 )
return - V_62 ;
V_132 = F_49 ( V_104 -> V_159 , & V_165 ,
V_21 -> V_193 , L_71 , V_52 ) ;
if ( V_132 < 0 )
return V_132 ;
V_104 -> V_161 . V_173 = L_75 ;
V_104 -> V_161 . V_199 = V_200 ;
F_51 ( & V_104 -> V_161 ) ;
V_132 = F_52 ( V_104 -> V_159 , & V_104 -> V_161 ) ;
if ( V_132 < 0 )
return V_132 ;
V_52 ++ ;
}
return 0 ;
}
static int F_54 ( void )
{
struct V_3 * V_21 ;
int V_132 ;
T_1 V_52 = 0 ;
F_3 (dev, &topology_device_list, list) {
V_132 = F_48 ( V_21 , V_52 ) ;
if ( V_132 < 0 )
return V_132 ;
V_52 ++ ;
}
return 0 ;
}
static void F_55 ( void )
{
struct V_3 * V_21 ;
F_3 (dev, &topology_device_list, list)
F_47 ( V_21 ) ;
}
static int F_56 ( void )
{
int V_132 ;
F_14 ( L_76 ) ;
if ( V_140 . V_203 == NULL ) {
V_140 . V_203 =
F_18 ( V_140 . V_203 ) ;
if ( ! V_140 . V_203 )
return - V_62 ;
V_132 = F_49 ( V_140 . V_203 ,
& V_204 , & V_205 -> V_159 ,
L_77 ) ;
if ( V_132 < 0 )
return V_132 ;
V_140 . V_198 = F_50 ( L_78 ,
V_140 . V_203 ) ;
if ( ! V_140 . V_198 )
return - V_62 ;
V_140 . V_163 . V_173 = L_79 ;
V_140 . V_163 . V_199 = V_200 ;
F_51 ( & V_140 . V_163 ) ;
V_132 = F_52 ( V_140 . V_203 ,
& V_140 . V_163 ) ;
if ( V_132 < 0 )
return V_132 ;
V_140 . V_164 . V_173 = L_80 ;
V_140 . V_164 . V_199 = V_200 ;
F_51 ( & V_140 . V_164 ) ;
V_132 = F_52 ( V_140 . V_203 ,
& V_140 . V_164 ) ;
if ( V_132 < 0 )
return V_132 ;
}
F_55 () ;
return F_54 () ;
}
static void F_57 ( void )
{
F_55 () ;
if ( V_140 . V_203 ) {
F_44 ( V_140 . V_203 ,
& V_140 . V_163 ) ;
F_44 ( V_140 . V_203 ,
& V_140 . V_164 ) ;
if ( V_140 . V_198 ) {
F_45 ( V_140 . V_198 ) ;
F_46 ( V_140 . V_198 ) ;
V_140 . V_198 = NULL ;
}
F_45 ( V_140 . V_203 ) ;
F_46 ( V_140 . V_203 ) ;
V_140 . V_203 = NULL ;
}
}
int F_58 ( void )
{
void * V_10 = NULL ;
T_2 V_206 = 0 ;
int V_132 ;
F_29 ( & V_142 ) ;
F_59 ( & V_6 ) ;
V_157 = 0 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_132 = F_6 ( V_10 , & V_206 ) ;
if ( V_132 == 0 && V_206 > 0 ) {
F_14 ( L_81 , V_206 ) ;
V_10 = F_60 ( V_206 , V_201 ) ;
if ( ! V_10 ) {
V_132 = - V_62 ;
F_11 ( L_82 ) ;
goto V_19;
}
V_132 = F_6 ( V_10 , & V_206 ) ;
if ( V_132 == 0 ) {
F_61 ( & V_6 ) ;
V_132 = F_30 ( V_10 ) ;
if ( V_132 == 0 )
V_132 = F_56 () ;
F_62 ( & V_6 ) ;
} else {
F_11 ( L_83 ) ;
}
F_26 ( V_10 ) ;
} else if ( V_132 == - V_18 ) {
V_132 = 0 ;
} else {
F_11 ( L_83 ) ;
}
V_19:
F_14 ( L_84 , V_132 ) ;
return V_132 ;
}
void F_63 ( void )
{
F_57 () ;
F_27 () ;
}
static void F_64 ( void )
{
struct V_3 * V_21 ;
T_1 V_52 = 0 ;
F_14 ( L_85 ) ;
F_3 (dev, &topology_device_list, list) {
F_14 ( L_86 , V_52 ) ;
F_14 ( L_87 , ( V_21 -> V_7 ? L_88 : L_89 ) ) ;
F_14 ( L_90 , V_21 -> V_24 . V_25 ) ;
F_14 ( L_91 , V_21 -> V_24 . V_34 ) ;
V_52 ++ ;
}
}
static T_1 F_65 ( struct V_1 * V_7 )
{
T_1 V_207 ;
T_1 V_208 [ 7 ] ;
int V_52 ;
if ( ! V_7 )
return 0 ;
V_208 [ 0 ] = V_7 -> V_9 -> V_209 ;
V_208 [ 1 ] = V_7 -> V_9 -> V_210 ;
V_208 [ 2 ] = V_7 -> V_9 -> V_211 ;
V_208 [ 3 ] = V_7 -> V_9 -> V_5 ;
V_208 [ 4 ] = V_7 -> V_9 -> V_212 -> V_213 ;
V_208 [ 5 ] = ( T_1 ) ( V_187 -> V_190 ( V_7 -> V_189 ) & 0xffffffff ) ;
V_208 [ 6 ] = ( T_1 ) ( V_187 -> V_190 ( V_7 -> V_189 ) >> 32 ) ;
for ( V_52 = 0 , V_207 = 0 ; V_52 < 7 ; V_52 ++ )
V_207 ^= F_66 ( V_208 [ V_52 ] , V_214 ) ;
return V_207 ;
}
static struct V_3 * F_67 ( struct V_1 * V_7 )
{
struct V_3 * V_21 ;
struct V_3 * V_215 = NULL ;
F_13 ( ! V_7 ) ;
F_3 (dev, &topology_device_list, list)
if ( V_21 -> V_7 == NULL && V_21 -> V_24 . V_34 > 0 ) {
V_21 -> V_7 = V_7 ;
V_215 = V_21 ;
break;
}
return V_215 ;
}
static void F_68 ( T_1 V_2 , int V_216 )
{
}
int F_69 ( struct V_1 * V_7 )
{
T_1 V_2 ;
struct V_3 * V_21 ;
int V_217 ;
F_13 ( ! V_7 ) ;
V_2 = F_65 ( V_7 ) ;
F_70 ( L_92 , V_2 ) ;
F_61 ( & V_6 ) ;
V_21 = F_67 ( V_7 ) ;
if ( ! V_21 ) {
F_14 ( L_93 ) ;
F_64 () ;
V_21 = F_28 () ;
if ( ! V_21 ) {
V_217 = - V_62 ;
goto V_19;
}
V_21 -> V_7 = V_7 ;
if ( F_56 () < 0 )
F_57 () ;
}
V_21 -> V_2 = V_2 ;
V_7 -> V_81 = V_2 ;
V_21 -> V_24 . V_179 = V_7 -> V_9 -> V_218 ;
V_21 -> V_24 . V_180 = V_7 -> V_9 -> V_5 ;
V_21 -> V_24 . V_181 = ( V_7 -> V_9 -> V_212 -> V_213 << 24 ) +
( V_7 -> V_9 -> V_209 & 0xffffff ) ;
V_217 = 0 ;
V_19:
F_62 ( & V_6 ) ;
if ( V_217 == 0 )
F_68 ( V_2 , 1 ) ;
return V_217 ;
}
int F_71 ( struct V_1 * V_7 )
{
struct V_3 * V_21 ;
T_1 V_2 ;
int V_217 = - V_219 ;
F_13 ( ! V_7 ) ;
F_61 ( & V_6 ) ;
F_3 (dev, &topology_device_list, list)
if ( V_21 -> V_7 == V_7 ) {
V_2 = V_21 -> V_2 ;
F_47 ( V_21 ) ;
F_23 ( V_21 ) ;
V_217 = 0 ;
if ( F_56 () < 0 )
F_57 () ;
break;
}
F_62 ( & V_6 ) ;
if ( V_217 == 0 )
F_68 ( V_2 , 0 ) ;
return V_217 ;
}
struct V_1 * F_72 ( T_6 V_220 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 = NULL ;
T_6 V_221 = 0 ;
F_2 ( & V_6 ) ;
F_3 (top_dev, &topology_device_list, list) {
if ( V_221 == V_220 ) {
V_5 = V_4 -> V_7 ;
break;
}
V_221 ++ ;
}
F_4 ( & V_6 ) ;
return V_5 ;
}
