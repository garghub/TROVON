static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_2 -> V_4 ) ;
}
static struct V_5 * F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return NULL ;
return & V_2 -> V_2 [ V_2 -> V_4 ++ ] ;
}
static struct V_5 * F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_6 - 1 )
return NULL ;
return & V_2 -> V_2 [ V_2 -> V_3 ++ ] ;
}
static struct V_5 * F_5 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_5 * V_13 ;
V_2 = F_6 ( V_14 ) ;
V_13 = F_4 ( V_2 ) ;
if ( V_13 ) {
V_13 -> V_8 = V_8 ;
V_13 -> V_15 = V_12 ;
V_13 -> V_16 = * V_10 ;
}
return V_13 ;
}
static void F_7 ( struct V_9 * V_10 )
{
V_10 -> V_17 . type = F_8 ( 0 ) ;
}
static bool F_9 ( const struct V_9 * V_10 )
{
return ! ! V_10 -> V_17 . type ;
}
static int F_10 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_18 * V_19 )
{
T_1 * V_20 ;
struct V_21 * V_22 ;
if ( V_8 -> V_23 )
return - V_24 ;
if ( F_11 ( V_8 , V_25 ) < 0 )
return - V_26 ;
F_12 ( V_8 , V_25 ) ;
memmove ( F_13 ( V_8 ) - V_25 , F_13 ( V_8 ) ,
V_8 -> V_27 ) ;
F_14 ( V_8 ) ;
V_20 = ( T_1 * ) F_15 ( V_8 ) ;
* V_20 = V_19 -> V_28 ;
if ( V_8 -> V_29 == V_30 )
V_8 -> V_31 = F_16 ( V_8 -> V_31 , F_17 ( V_20 ,
V_25 , 0 ) ) ;
V_22 = F_18 ( V_8 ) ;
V_22 -> V_32 = V_19 -> V_33 ;
if ( ! V_8 -> V_34 )
F_19 ( V_8 , V_8 -> V_35 ) ;
V_8 -> V_35 = V_19 -> V_33 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const T_2 V_36 )
{
struct V_21 * V_22 ;
int V_37 ;
V_37 = F_21 ( V_8 , V_8 -> V_27 + V_25 ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
F_23 ( V_8 , F_15 ( V_8 ) , V_25 ) ;
memmove ( F_13 ( V_8 ) + V_25 , F_13 ( V_8 ) ,
V_8 -> V_27 ) ;
F_24 ( V_8 , V_25 ) ;
F_14 ( V_8 ) ;
V_22 = (struct V_21 * ) ( F_15 ( V_8 ) - V_38 ) ;
V_22 -> V_32 = V_36 ;
if ( F_25 ( V_8 -> V_35 ) )
V_8 -> V_35 = V_36 ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const T_1 * V_28 )
{
T_1 * V_39 ;
int V_37 ;
V_37 = F_21 ( V_8 , V_8 -> V_27 + V_25 ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_39 = ( T_1 * ) F_15 ( V_8 ) ;
if ( V_8 -> V_29 == V_30 ) {
T_1 V_40 [] = { ~ ( * V_39 ) , * V_28 } ;
V_8 -> V_31 = ~ F_17 ( ( char * ) V_40 , sizeof( V_40 ) ,
~ V_8 -> V_31 ) ;
}
* V_39 = * V_28 ;
V_10 -> V_19 . V_41 = * V_28 ;
return 0 ;
}
static int F_27 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_37 ;
V_37 = F_28 ( V_8 ) ;
if ( F_29 ( V_8 ) )
F_7 ( V_10 ) ;
else
V_10 -> V_17 . V_42 = 0 ;
return V_37 ;
}
static int F_30 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_43 * V_44 )
{
if ( F_29 ( V_8 ) )
F_7 ( V_10 ) ;
else
V_10 -> V_17 . V_42 = V_44 -> V_45 ;
return F_31 ( V_8 , V_44 -> V_46 ,
F_32 ( V_44 -> V_45 ) & ~ V_47 ) ;
}
static int F_33 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_48 * V_49 )
{
int V_37 ;
V_37 = F_21 ( V_8 , V_38 ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
F_23 ( V_8 , F_18 ( V_8 ) , V_50 * 2 ) ;
F_34 ( F_18 ( V_8 ) -> V_51 , V_49 -> V_52 ) ;
F_34 ( F_18 ( V_8 ) -> V_53 , V_49 -> V_54 ) ;
F_35 ( V_8 , F_18 ( V_8 ) , V_50 * 2 ) ;
F_34 ( V_10 -> V_17 . V_55 , V_49 -> V_52 ) ;
F_34 ( V_10 -> V_17 . V_56 , V_49 -> V_54 ) ;
return 0 ;
}
static void F_36 ( struct V_7 * V_8 , struct V_57 * V_58 ,
T_1 * V_59 , T_1 V_60 )
{
int V_61 = V_8 -> V_62 - F_37 ( V_8 ) ;
if ( V_58 -> V_35 == V_63 ) {
if ( F_38 ( V_61 >= sizeof( struct V_64 ) ) )
F_39 ( & F_40 ( V_8 ) -> V_65 , V_8 ,
* V_59 , V_60 , 1 ) ;
} else if ( V_58 -> V_35 == V_66 ) {
if ( F_38 ( V_61 >= sizeof( struct V_67 ) ) ) {
struct V_67 * V_68 = F_41 ( V_8 ) ;
if ( V_68 -> V_65 || V_8 -> V_29 == V_69 ) {
F_39 ( & V_68 -> V_65 , V_8 ,
* V_59 , V_60 , 1 ) ;
if ( ! V_68 -> V_65 )
V_68 -> V_65 = V_70 ;
}
}
}
F_42 ( & V_58 -> V_65 , * V_59 , V_60 ) ;
F_43 ( V_8 ) ;
* V_59 = V_60 ;
}
static void F_44 ( struct V_7 * V_8 , T_3 V_71 ,
T_1 V_59 [ 4 ] , const T_1 V_60 [ 4 ] )
{
int V_61 = V_8 -> V_62 - F_37 ( V_8 ) ;
if ( V_71 == V_72 ) {
if ( F_38 ( V_61 >= sizeof( struct V_64 ) ) )
F_45 ( & F_40 ( V_8 ) -> V_65 , V_8 ,
V_59 , V_60 , 1 ) ;
} else if ( V_71 == V_73 ) {
if ( F_38 ( V_61 >= sizeof( struct V_67 ) ) ) {
struct V_67 * V_68 = F_41 ( V_8 ) ;
if ( V_68 -> V_65 || V_8 -> V_29 == V_69 ) {
F_45 ( & V_68 -> V_65 , V_8 ,
V_59 , V_60 , 1 ) ;
if ( ! V_68 -> V_65 )
V_68 -> V_65 = V_70 ;
}
}
} else if ( V_71 == V_74 ) {
if ( F_38 ( V_61 >= sizeof( struct V_75 ) ) )
F_45 ( & F_46 ( V_8 ) -> V_76 ,
V_8 , V_59 , V_60 , 1 ) ;
}
}
static void F_47 ( struct V_7 * V_8 , T_3 V_71 ,
T_1 V_59 [ 4 ] , const T_1 V_60 [ 4 ] ,
bool V_77 )
{
if ( V_77 )
F_44 ( V_8 , V_71 , V_59 , V_60 ) ;
F_43 ( V_8 ) ;
memcpy ( V_59 , V_60 , sizeof( T_1 [ 4 ] ) ) ;
}
static void F_48 ( struct V_78 * V_58 , T_3 V_79 )
{
V_58 -> V_80 = V_79 >> 4 ;
V_58 -> V_81 [ 0 ] = ( V_58 -> V_81 [ 0 ] & 0x0F ) | ( ( V_79 & 0x0F ) << 4 ) ;
}
static void F_49 ( struct V_78 * V_58 , T_4 V_82 )
{
V_58 -> V_81 [ 0 ] = ( V_58 -> V_81 [ 0 ] & 0xF0 ) | ( V_82 & 0x000F0000 ) >> 16 ;
V_58 -> V_81 [ 1 ] = ( V_82 & 0x0000FF00 ) >> 8 ;
V_58 -> V_81 [ 2 ] = V_82 & 0x000000FF ;
}
static void F_50 ( struct V_7 * V_8 , struct V_57 * V_58 , T_3 V_83 )
{
F_51 ( & V_58 -> V_65 , F_8 ( V_58 -> V_84 << 8 ) , F_8 ( V_83 << 8 ) ) ;
V_58 -> V_84 = V_83 ;
}
static int F_52 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_85 * V_86 )
{
struct V_57 * V_58 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_53 ( V_8 ) +
sizeof( struct V_57 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_58 = F_54 ( V_8 ) ;
if ( V_86 -> V_87 != V_58 -> V_88 ) {
F_36 ( V_8 , V_58 , & V_58 -> V_88 , V_86 -> V_87 ) ;
V_10 -> V_89 . V_59 . V_55 = V_86 -> V_87 ;
}
if ( V_86 -> V_90 != V_58 -> V_91 ) {
F_36 ( V_8 , V_58 , & V_58 -> V_91 , V_86 -> V_90 ) ;
V_10 -> V_89 . V_59 . V_56 = V_86 -> V_90 ;
}
if ( V_86 -> V_92 != V_58 -> V_93 ) {
F_55 ( V_58 , 0 , V_86 -> V_92 ) ;
V_10 -> V_94 . V_93 = V_58 -> V_93 ;
}
if ( V_86 -> V_95 != V_58 -> V_84 ) {
F_50 ( V_8 , V_58 , V_86 -> V_95 ) ;
V_10 -> V_94 . V_84 = V_86 -> V_95 ;
}
return 0 ;
}
static int F_56 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_96 * V_97 )
{
struct V_78 * V_58 ;
int V_37 ;
T_1 * V_88 ;
T_1 * V_91 ;
V_37 = F_21 ( V_8 , F_53 ( V_8 ) +
sizeof( struct V_78 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_58 = F_57 ( V_8 ) ;
V_88 = ( T_1 * ) & V_58 -> V_88 ;
V_91 = ( T_1 * ) & V_58 -> V_91 ;
if ( memcmp ( V_97 -> V_98 , V_88 , sizeof( V_97 -> V_98 ) ) ) {
F_47 ( V_8 , V_97 -> V_99 , V_88 ,
V_97 -> V_98 , true ) ;
memcpy ( & V_10 -> V_100 . V_59 . V_55 , V_97 -> V_98 ,
sizeof( V_97 -> V_98 ) ) ;
}
if ( memcmp ( V_97 -> V_101 , V_91 , sizeof( V_97 -> V_101 ) ) ) {
unsigned int V_102 = 0 ;
int V_103 = V_104 ;
bool V_105 = true ;
if ( F_58 ( V_58 -> V_106 ) )
V_105 = F_59 ( V_8 , & V_102 ,
V_107 , NULL ,
& V_103 ) != V_107 ;
F_47 ( V_8 , V_97 -> V_99 , V_91 ,
V_97 -> V_101 , V_105 ) ;
memcpy ( & V_10 -> V_100 . V_59 . V_56 , V_97 -> V_101 ,
sizeof( V_97 -> V_101 ) ) ;
}
F_48 ( V_58 , V_97 -> V_108 ) ;
V_10 -> V_94 . V_93 = F_60 ( V_58 ) ;
F_49 ( V_58 , F_61 ( V_97 -> V_109 ) ) ;
V_10 -> V_100 . V_110 = * ( T_1 * ) V_58 & F_62 ( V_111 ) ;
V_58 -> V_112 = V_97 -> V_113 ;
V_10 -> V_94 . V_84 = V_97 -> V_113 ;
return 0 ;
}
static void F_63 ( struct V_7 * V_8 , T_2 * V_114 ,
T_2 V_115 , T_5 * V_65 )
{
F_64 ( V_65 , V_8 , * V_114 , V_115 , 0 ) ;
* V_114 = V_115 ;
F_43 ( V_8 ) ;
}
static void F_65 ( struct V_7 * V_8 , T_2 * V_114 , T_2 V_115 )
{
struct V_67 * V_68 = F_41 ( V_8 ) ;
if ( V_68 -> V_65 && V_8 -> V_29 != V_69 ) {
F_63 ( V_8 , V_114 , V_115 , & V_68 -> V_65 ) ;
if ( ! V_68 -> V_65 )
V_68 -> V_65 = V_70 ;
} else {
* V_114 = V_115 ;
F_43 ( V_8 ) ;
}
}
static int F_66 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_116 * V_117 )
{
struct V_67 * V_68 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_37 ( V_8 ) +
sizeof( struct V_67 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_68 = F_41 ( V_8 ) ;
if ( V_117 -> V_118 != V_68 -> V_119 ) {
F_65 ( V_8 , & V_68 -> V_119 , V_117 -> V_118 ) ;
V_10 -> V_120 . V_55 = V_117 -> V_118 ;
}
if ( V_117 -> V_121 != V_68 -> V_122 ) {
F_65 ( V_8 , & V_68 -> V_122 , V_117 -> V_121 ) ;
V_10 -> V_120 . V_56 = V_117 -> V_121 ;
}
return 0 ;
}
static int F_67 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_123 * V_124 )
{
struct V_64 * V_125 ;
int V_37 ;
V_37 = F_21 ( V_8 , F_37 ( V_8 ) +
sizeof( struct V_64 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_125 = F_40 ( V_8 ) ;
if ( V_124 -> V_126 != V_125 -> V_119 ) {
F_63 ( V_8 , & V_125 -> V_119 , V_124 -> V_126 , & V_125 -> V_65 ) ;
V_10 -> V_120 . V_55 = V_124 -> V_126 ;
}
if ( V_124 -> V_127 != V_125 -> V_122 ) {
F_63 ( V_8 , & V_125 -> V_122 , V_124 -> V_127 , & V_125 -> V_65 ) ;
V_10 -> V_120 . V_56 = V_124 -> V_127 ;
}
return 0 ;
}
static int F_68 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_128 * V_129 )
{
struct V_130 * V_131 ;
int V_37 ;
unsigned int V_132 = F_37 ( V_8 ) ;
V_37 = F_21 ( V_8 , V_132 + sizeof( struct V_130 ) ) ;
if ( F_22 ( V_37 ) )
return V_37 ;
V_131 = F_69 ( V_8 ) ;
if ( V_129 -> V_133 != V_131 -> V_119 ||
V_129 -> V_134 != V_131 -> V_122 ) {
T_6 V_135 , V_136 , V_137 ;
V_137 = V_131 -> V_138 ;
V_135 = F_70 ( V_8 , V_132 ) ;
V_131 -> V_119 = V_129 -> V_133 ;
V_131 -> V_122 = V_129 -> V_134 ;
V_136 = F_70 ( V_8 , V_132 ) ;
V_131 -> V_138 = V_137 ^ V_135 ^ V_136 ;
F_43 ( V_8 ) ;
V_10 -> V_120 . V_55 = V_129 -> V_133 ;
V_10 -> V_120 . V_56 = V_129 -> V_134 ;
}
return 0 ;
}
static void F_71 ( struct V_139 * V_140 , struct V_7 * V_8 , int V_141 )
{
struct V_142 * V_142 = F_72 ( V_140 , V_141 ) ;
if ( F_38 ( V_142 ) )
F_73 ( V_142 , V_8 ) ;
else
F_74 ( V_8 ) ;
}
static int F_75 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
struct V_143 V_144 ;
struct V_145 V_146 ;
const struct V_11 * V_147 ;
int V_148 ;
V_146 . V_149 = V_150 ;
V_146 . V_151 = NULL ;
V_146 . V_152 = 0 ;
V_146 . V_153 = NULL ;
for ( V_147 = F_76 ( V_12 ) , V_148 = F_77 ( V_12 ) ; V_148 > 0 ;
V_147 = F_78 ( V_147 , & V_148 ) ) {
switch ( F_79 ( V_147 ) ) {
case V_154 :
V_146 . V_151 = V_147 ;
break;
case V_155 :
V_146 . V_152 = F_80 ( V_147 ) ;
break;
case V_156 : {
struct V_142 * V_142 ;
V_142 = F_72 ( V_140 , F_80 ( V_147 ) ) ;
if ( V_142 ) {
int V_37 ;
V_37 = F_81 ( V_142 , V_8 ,
& V_144 ) ;
if ( ! V_37 )
V_146 . V_153 = & V_144 ;
}
break;
}
}
}
return F_82 ( V_140 , V_8 , V_10 , & V_146 ) ;
}
static int F_83 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
const struct V_11 * V_157 = NULL ;
const struct V_11 * V_147 ;
int V_148 ;
for ( V_147 = F_76 ( V_12 ) , V_148 = F_77 ( V_12 ) ; V_148 > 0 ;
V_147 = F_78 ( V_147 , & V_148 ) ) {
switch ( F_79 ( V_147 ) ) {
case V_158 :
if ( F_84 () >= F_80 ( V_147 ) )
return 0 ;
break;
case V_159 :
V_157 = V_147 ;
break;
}
}
V_148 = F_77 ( V_157 ) ;
V_147 = F_76 ( V_157 ) ;
if ( F_22 ( ! V_148 ) )
return 0 ;
if ( F_38 ( F_79 ( V_147 ) == V_160 &&
F_85 ( V_147 , V_148 ) ) )
return F_75 ( V_140 , V_8 , V_10 , V_147 ) ;
V_8 = F_86 ( V_8 , V_161 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_5 ( V_8 , V_10 , V_147 ) ) {
if ( F_87 () )
F_88 ( L_1 ,
F_89 ( V_140 ) ) ;
F_74 ( V_8 ) ;
}
return 0 ;
}
static void F_90 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_162 * V_163 = F_76 ( V_12 ) ;
T_4 V_164 = 0 ;
V_164 = F_91 ( V_8 ) ;
V_164 = F_92 ( V_164 , V_163 -> V_165 ) ;
if ( ! V_164 )
V_164 = 0x1 ;
V_10 -> V_166 = V_164 ;
}
static int F_93 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_167 )
{
int V_37 = 0 ;
switch ( F_79 ( V_167 ) ) {
case V_168 :
V_8 -> V_80 = F_80 ( V_167 ) ;
V_10 -> V_169 . V_80 = V_8 -> V_80 ;
break;
case V_170 :
V_8 -> V_171 = F_80 ( V_167 ) ;
V_10 -> V_169 . V_172 = V_8 -> V_171 ;
break;
case V_173 :
F_94 ( V_8 ) -> V_153 = F_76 ( V_167 ) ;
break;
case V_174 :
V_37 = F_33 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
case V_175 :
V_37 = F_52 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
case V_176 :
V_37 = F_56 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
case V_177 :
V_37 = F_67 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
case V_178 :
V_37 = F_66 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
case V_179 :
V_37 = F_68 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
case V_180 :
V_37 = F_26 ( V_8 , V_10 , F_76 ( V_167 ) ) ;
break;
}
return V_37 ;
}
static int F_95 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_147 , int V_148 )
{
struct V_5 * V_13 ;
if ( ! F_9 ( V_10 ) ) {
int V_37 ;
V_37 = F_96 ( V_8 , V_10 ) ;
if ( V_37 )
return V_37 ;
}
F_97 ( ! F_9 ( V_10 ) ) ;
if ( ! F_85 ( V_147 , V_148 ) ) {
V_8 = F_86 ( V_8 , V_161 ) ;
if ( ! V_8 )
return 0 ;
}
V_13 = F_5 ( V_8 , V_10 , NULL ) ;
if ( V_13 ) {
V_13 -> V_16 . V_181 = F_80 ( V_147 ) ;
} else {
F_74 ( V_8 ) ;
if ( F_87 () )
F_88 ( L_2 ,
F_89 ( V_140 ) ) ;
}
return 0 ;
}
static int F_98 ( struct V_139 * V_140 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 , int V_62 )
{
int V_182 = - 1 ;
const struct V_11 * V_147 ;
int V_148 ;
for ( V_147 = V_12 , V_148 = V_62 ; V_148 > 0 ;
V_147 = F_78 ( V_147 , & V_148 ) ) {
int V_37 = 0 ;
if ( F_22 ( V_182 != - 1 ) ) {
struct V_7 * V_183 = F_86 ( V_8 , V_161 ) ;
if ( V_183 )
F_71 ( V_140 , V_183 , V_182 ) ;
V_182 = - 1 ;
}
switch ( F_79 ( V_147 ) ) {
case V_184 :
V_182 = F_80 ( V_147 ) ;
break;
case V_160 :
F_75 ( V_140 , V_8 , V_10 , V_147 ) ;
break;
case V_185 :
F_90 ( V_8 , V_10 , V_147 ) ;
break;
case V_186 :
V_37 = F_10 ( V_8 , V_10 , F_76 ( V_147 ) ) ;
break;
case V_187 :
V_37 = F_20 ( V_8 , V_10 , F_99 ( V_147 ) ) ;
break;
case V_188 :
V_37 = F_30 ( V_8 , V_10 , F_76 ( V_147 ) ) ;
break;
case V_189 :
V_37 = F_27 ( V_8 , V_10 ) ;
break;
case V_190 :
V_37 = F_95 ( V_140 , V_8 , V_10 , V_147 , V_148 ) ;
if ( F_85 ( V_147 , V_148 ) ) {
return V_37 ;
}
break;
case V_191 :
V_37 = F_93 ( V_8 , V_10 , F_76 ( V_147 ) ) ;
break;
case V_192 :
V_37 = F_83 ( V_140 , V_8 , V_10 , V_147 ) ;
break;
}
if ( F_22 ( V_37 ) ) {
F_74 ( V_8 ) ;
return V_37 ;
}
}
if ( V_182 != - 1 )
F_71 ( V_140 , V_8 , V_182 ) ;
else
F_100 ( V_8 ) ;
return 0 ;
}
static void F_101 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
if ( F_2 ( V_2 ) )
return;
do {
struct V_5 * V_13 = F_3 ( V_2 ) ;
struct V_7 * V_8 = V_13 -> V_8 ;
struct V_9 * V_10 = & V_13 -> V_16 ;
const struct V_11 * V_15 = V_13 -> V_15 ;
if ( V_15 )
F_98 ( V_140 , V_8 , V_10 , V_15 ,
F_77 ( V_15 ) ) ;
else
F_102 ( V_8 , V_10 ) ;
} while ( ! F_2 ( V_2 ) );
F_1 ( V_2 ) ;
}
int F_103 ( struct V_139 * V_140 , struct V_7 * V_8 ,
const struct V_193 * V_194 ,
struct V_9 * V_10 )
{
int V_195 = F_104 ( V_196 ) ;
int V_37 ;
F_105 ( V_196 ) ;
F_94 ( V_8 ) -> V_153 = NULL ;
V_37 = F_98 ( V_140 , V_8 , V_10 ,
V_194 -> V_15 , V_194 -> V_197 ) ;
if ( ! V_195 )
F_101 ( V_140 ) ;
F_106 ( V_196 ) ;
return V_37 ;
}
int F_107 ( void )
{
V_14 = F_108 ( struct V_1 ) ;
if ( ! V_14 )
return - V_26 ;
return 0 ;
}
void F_109 ( void )
{
F_110 ( V_14 ) ;
}
