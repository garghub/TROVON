static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
}
static bool F_2 ( struct V_1 * V_2 )
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
struct V_9 * V_10 ,
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
static int F_7 ( struct V_7 * V_8 , int V_17 )
{
if ( ! F_8 ( V_8 , V_17 ) )
return - V_18 ;
if ( ! F_9 ( V_8 ) || F_10 ( V_8 , V_17 ) )
return 0 ;
return F_11 ( V_8 , 0 , 0 , V_19 ) ;
}
static int F_12 ( struct V_7 * V_8 , T_1 * V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
V_23 = F_7 ( V_8 , V_24 ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
if ( V_8 -> V_25 == V_26 )
V_8 -> V_27 = F_14 ( V_8 -> V_27 , F_15 ( V_8 -> V_28
+ ( 2 * V_29 ) , V_30 , 0 ) ) ;
V_22 = (struct V_21 * ) ( V_8 -> V_28 + V_31 ) ;
* V_20 = V_22 -> V_32 ;
memmove ( V_8 -> V_28 + V_30 , V_8 -> V_28 , 2 * V_29 ) ;
F_16 ( V_8 , V_30 ) ;
F_17 ( V_8 , V_22 ) ;
V_8 -> V_33 += V_30 ;
if ( F_18 ( V_8 ) < V_31 )
F_19 ( V_8 , V_31 ) ;
F_20 ( V_8 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 )
{
T_1 V_34 ;
int V_23 ;
if ( F_22 ( F_23 ( V_8 ) ) ) {
V_8 -> V_35 = 0 ;
} else {
if ( F_13 ( V_8 -> V_36 != F_24 ( V_37 ) ||
V_8 -> V_38 < V_24 ) )
return 0 ;
V_23 = F_12 ( V_8 , & V_34 ) ;
if ( V_23 )
return V_23 ;
}
if ( F_22 ( V_8 -> V_36 != F_24 ( V_37 ) ||
V_8 -> V_38 < V_24 ) )
return 0 ;
V_23 = F_12 ( V_8 , & V_34 ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
F_25 ( V_8 , F_24 ( V_37 ) , F_26 ( V_34 ) ) ;
return 0 ;
}
static int F_27 ( struct V_7 * V_8 , const struct V_39 * V_40 )
{
if ( F_13 ( F_23 ( V_8 ) ) ) {
T_2 V_41 ;
V_41 = F_28 ( V_8 ) ;
if ( ! F_29 ( V_8 , V_8 -> V_42 , V_41 ) )
return - V_18 ;
if ( V_8 -> V_25 == V_26 )
V_8 -> V_27 = F_30 ( V_8 -> V_27 , F_15 ( V_8 -> V_28
+ ( 2 * V_29 ) , V_30 , 0 ) ) ;
}
F_25 ( V_8 , V_40 -> V_43 , F_26 ( V_40 -> V_35 ) & ~ V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 ,
const struct V_45 * V_46 )
{
int V_23 ;
V_23 = F_7 ( V_8 , V_31 ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
F_32 ( V_8 , F_33 ( V_8 ) , V_29 * 2 ) ;
F_34 ( F_33 ( V_8 ) -> V_47 , V_46 -> V_48 ) ;
F_34 ( F_33 ( V_8 ) -> V_49 , V_46 -> V_50 ) ;
F_35 ( V_8 , F_33 ( V_8 ) , V_29 * 2 ) ;
return 0 ;
}
static void F_36 ( struct V_7 * V_8 , struct V_51 * V_52 ,
T_3 * V_53 , T_3 V_54 )
{
int V_55 = V_8 -> V_38 - F_37 ( V_8 ) ;
if ( V_52 -> V_36 == V_56 ) {
if ( F_22 ( V_55 >= sizeof( struct V_57 ) ) )
F_38 ( & F_39 ( V_8 ) -> V_58 , V_8 ,
* V_53 , V_54 , 1 ) ;
} else if ( V_52 -> V_36 == V_59 ) {
if ( F_22 ( V_55 >= sizeof( struct V_60 ) ) ) {
struct V_60 * V_61 = F_40 ( V_8 ) ;
if ( V_61 -> V_58 || V_8 -> V_25 == V_62 ) {
F_38 ( & V_61 -> V_58 , V_8 ,
* V_53 , V_54 , 1 ) ;
if ( ! V_61 -> V_58 )
V_61 -> V_58 = V_63 ;
}
}
}
F_41 ( & V_52 -> V_58 , * V_53 , V_54 ) ;
F_42 ( V_8 ) ;
* V_53 = V_54 ;
}
static void F_43 ( struct V_7 * V_8 , T_4 V_64 ,
T_3 V_53 [ 4 ] , const T_3 V_54 [ 4 ] )
{
int V_55 = V_8 -> V_38 - F_37 ( V_8 ) ;
if ( V_64 == V_65 ) {
if ( F_22 ( V_55 >= sizeof( struct V_57 ) ) )
F_44 ( & F_39 ( V_8 ) -> V_58 , V_8 ,
V_53 , V_54 , 1 ) ;
} else if ( V_64 == V_66 ) {
if ( F_22 ( V_55 >= sizeof( struct V_60 ) ) ) {
struct V_60 * V_61 = F_40 ( V_8 ) ;
if ( V_61 -> V_58 || V_8 -> V_25 == V_62 ) {
F_44 ( & V_61 -> V_58 , V_8 ,
V_53 , V_54 , 1 ) ;
if ( ! V_61 -> V_58 )
V_61 -> V_58 = V_63 ;
}
}
} else if ( V_64 == V_67 ) {
if ( F_22 ( V_55 >= sizeof( struct V_68 ) ) )
F_44 ( & F_45 ( V_8 ) -> V_69 ,
V_8 , V_53 , V_54 , 1 ) ;
}
}
static void F_46 ( struct V_7 * V_8 , T_4 V_64 ,
T_3 V_53 [ 4 ] , const T_3 V_54 [ 4 ] ,
bool V_70 )
{
if ( V_70 )
F_43 ( V_8 , V_64 , V_53 , V_54 ) ;
F_42 ( V_8 ) ;
memcpy ( V_53 , V_54 , sizeof( T_3 [ 4 ] ) ) ;
}
static void F_47 ( struct V_71 * V_52 , T_4 V_72 )
{
V_52 -> V_73 = V_72 >> 4 ;
V_52 -> V_74 [ 0 ] = ( V_52 -> V_74 [ 0 ] & 0x0F ) | ( ( V_72 & 0x0F ) << 4 ) ;
}
static void F_48 ( struct V_71 * V_52 , T_5 V_75 )
{
V_52 -> V_74 [ 0 ] = ( V_52 -> V_74 [ 0 ] & 0xF0 ) | ( V_75 & 0x000F0000 ) >> 16 ;
V_52 -> V_74 [ 1 ] = ( V_75 & 0x0000FF00 ) >> 8 ;
V_52 -> V_74 [ 2 ] = V_75 & 0x000000FF ;
}
static void F_49 ( struct V_7 * V_8 , struct V_51 * V_52 , T_4 V_76 )
{
F_50 ( & V_52 -> V_58 , F_24 ( V_52 -> V_77 << 8 ) , F_24 ( V_76 << 8 ) ) ;
V_52 -> V_77 = V_76 ;
}
static int F_51 ( struct V_7 * V_8 , const struct V_78 * V_79 )
{
struct V_51 * V_52 ;
int V_23 ;
V_23 = F_7 ( V_8 , F_18 ( V_8 ) +
sizeof( struct V_51 ) ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
V_52 = F_52 ( V_8 ) ;
if ( V_79 -> V_80 != V_52 -> V_81 )
F_36 ( V_8 , V_52 , & V_52 -> V_81 , V_79 -> V_80 ) ;
if ( V_79 -> V_82 != V_52 -> V_83 )
F_36 ( V_8 , V_52 , & V_52 -> V_83 , V_79 -> V_82 ) ;
if ( V_79 -> V_84 != V_52 -> V_85 )
F_53 ( V_52 , 0 , V_79 -> V_84 ) ;
if ( V_79 -> V_86 != V_52 -> V_77 )
F_49 ( V_8 , V_52 , V_79 -> V_86 ) ;
return 0 ;
}
static int F_54 ( struct V_7 * V_8 , const struct V_87 * V_88 )
{
struct V_71 * V_52 ;
int V_23 ;
T_3 * V_81 ;
T_3 * V_83 ;
V_23 = F_7 ( V_8 , F_18 ( V_8 ) +
sizeof( struct V_71 ) ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
V_52 = F_55 ( V_8 ) ;
V_81 = ( T_3 * ) & V_52 -> V_81 ;
V_83 = ( T_3 * ) & V_52 -> V_83 ;
if ( memcmp ( V_88 -> V_89 , V_81 , sizeof( V_88 -> V_89 ) ) )
F_46 ( V_8 , V_88 -> V_90 , V_81 ,
V_88 -> V_89 , true ) ;
if ( memcmp ( V_88 -> V_91 , V_83 , sizeof( V_88 -> V_91 ) ) ) {
unsigned int V_92 = 0 ;
int V_93 = V_94 ;
bool V_95 = true ;
if ( F_56 ( V_52 -> V_96 ) )
V_95 = F_57 ( V_8 , & V_92 ,
V_97 , NULL ,
& V_93 ) != V_97 ;
F_46 ( V_8 , V_88 -> V_90 , V_83 ,
V_88 -> V_91 , V_95 ) ;
}
F_47 ( V_52 , V_88 -> V_98 ) ;
F_48 ( V_52 , F_58 ( V_88 -> V_99 ) ) ;
V_52 -> V_100 = V_88 -> V_101 ;
return 0 ;
}
static void F_59 ( struct V_7 * V_8 , T_1 * V_102 ,
T_1 V_103 , T_6 * V_58 )
{
F_60 ( V_58 , V_8 , * V_102 , V_103 , 0 ) ;
* V_102 = V_103 ;
F_42 ( V_8 ) ;
}
static void F_61 ( struct V_7 * V_8 , T_1 * V_102 , T_1 V_103 )
{
struct V_60 * V_61 = F_40 ( V_8 ) ;
if ( V_61 -> V_58 && V_8 -> V_25 != V_62 ) {
F_59 ( V_8 , V_102 , V_103 , & V_61 -> V_58 ) ;
if ( ! V_61 -> V_58 )
V_61 -> V_58 = V_63 ;
} else {
* V_102 = V_103 ;
F_42 ( V_8 ) ;
}
}
static int F_62 ( struct V_7 * V_8 , const struct V_104 * V_105 )
{
struct V_60 * V_61 ;
int V_23 ;
V_23 = F_7 ( V_8 , F_37 ( V_8 ) +
sizeof( struct V_60 ) ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
V_61 = F_40 ( V_8 ) ;
if ( V_105 -> V_106 != V_61 -> V_107 )
F_61 ( V_8 , & V_61 -> V_107 , V_105 -> V_106 ) ;
if ( V_105 -> V_108 != V_61 -> V_109 )
F_61 ( V_8 , & V_61 -> V_109 , V_105 -> V_108 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_8 , const struct V_110 * V_111 )
{
struct V_57 * V_112 ;
int V_23 ;
V_23 = F_7 ( V_8 , F_37 ( V_8 ) +
sizeof( struct V_57 ) ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
V_112 = F_39 ( V_8 ) ;
if ( V_111 -> V_113 != V_112 -> V_107 )
F_59 ( V_8 , & V_112 -> V_107 , V_111 -> V_113 , & V_112 -> V_58 ) ;
if ( V_111 -> V_114 != V_112 -> V_109 )
F_59 ( V_8 , & V_112 -> V_109 , V_111 -> V_114 , & V_112 -> V_58 ) ;
return 0 ;
}
static int F_64 ( struct V_7 * V_8 ,
const struct V_115 * V_116 )
{
struct V_117 * V_118 ;
int V_23 ;
unsigned int V_119 = F_37 ( V_8 ) ;
V_23 = F_7 ( V_8 , V_119 + sizeof( struct V_117 ) ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
V_118 = F_65 ( V_8 ) ;
if ( V_116 -> V_120 != V_118 -> V_107 ||
V_116 -> V_121 != V_118 -> V_109 ) {
T_7 V_122 , V_123 , V_124 ;
V_124 = V_118 -> V_125 ;
V_122 = F_66 ( V_8 , V_119 ) ;
V_118 -> V_107 = V_116 -> V_120 ;
V_118 -> V_109 = V_116 -> V_121 ;
V_123 = F_66 ( V_8 , V_119 ) ;
V_118 -> V_125 = V_124 ^ V_122 ^ V_123 ;
F_42 ( V_8 ) ;
}
return 0 ;
}
static int F_67 ( struct V_126 * V_127 , struct V_7 * V_8 , int V_128 )
{
struct V_129 * V_129 ;
if ( F_13 ( ! V_8 ) )
return - V_18 ;
V_129 = F_68 ( V_127 , V_128 ) ;
if ( F_13 ( ! V_129 ) ) {
F_69 ( V_8 ) ;
return - V_130 ;
}
F_70 ( V_129 , V_8 ) ;
return 0 ;
}
static int F_71 ( struct V_126 * V_127 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
struct V_131 V_132 ;
const struct V_11 * V_133 ;
int V_134 ;
V_132 . V_135 = V_136 ;
V_132 . V_10 = V_10 ;
V_132 . V_137 = NULL ;
V_132 . V_138 = 0 ;
for ( V_133 = F_72 ( V_12 ) , V_134 = F_73 ( V_12 ) ; V_134 > 0 ;
V_133 = F_74 ( V_133 , & V_134 ) ) {
switch ( F_75 ( V_133 ) ) {
case V_139 :
V_132 . V_137 = V_133 ;
break;
case V_140 :
V_132 . V_138 = F_76 ( V_133 ) ;
break;
}
}
return F_77 ( V_127 , V_8 , & V_132 ) ;
}
static bool F_78 ( const struct V_11 * V_133 , int V_134 )
{
return V_133 -> F_73 == V_134 ;
}
static int F_79 ( struct V_126 * V_127 , struct V_7 * V_8 ,
struct V_9 * V_10 , const struct V_11 * V_12 )
{
const struct V_11 * V_141 = NULL ;
const struct V_11 * V_133 ;
int V_134 ;
for ( V_133 = F_72 ( V_12 ) , V_134 = F_73 ( V_12 ) ; V_134 > 0 ;
V_133 = F_74 ( V_133 , & V_134 ) ) {
switch ( F_75 ( V_133 ) ) {
case V_142 :
if ( F_80 () >= F_76 ( V_133 ) )
return 0 ;
break;
case V_143 :
V_141 = V_133 ;
break;
}
}
V_134 = F_73 ( V_141 ) ;
V_133 = F_72 ( V_141 ) ;
if ( F_13 ( ! V_134 ) )
return 0 ;
if ( F_22 ( F_75 ( V_133 ) == V_144 &&
F_78 ( V_133 , V_134 ) ) )
return F_71 ( V_127 , V_8 , V_10 , V_133 ) ;
V_8 = F_81 ( V_8 , V_19 ) ;
if ( ! V_8 )
return 0 ;
if ( ! F_5 ( V_8 , V_10 , V_133 ) ) {
if ( F_82 () )
F_83 ( L_1 ,
F_84 ( V_127 ) ) ;
F_69 ( V_8 ) ;
}
return 0 ;
}
static void F_85 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_145 * V_146 = F_72 ( V_12 ) ;
T_5 V_147 = 0 ;
V_147 = F_86 ( V_8 ) ;
V_147 = F_87 ( V_147 , V_146 -> V_148 ) ;
if ( ! V_147 )
V_147 = 0x1 ;
V_10 -> V_149 = V_147 ;
}
static int F_88 ( struct V_7 * V_8 ,
const struct V_11 * V_150 )
{
int V_23 = 0 ;
switch ( F_75 ( V_150 ) ) {
case V_151 :
V_8 -> V_73 = F_76 ( V_150 ) ;
break;
case V_152 :
V_8 -> V_153 = F_76 ( V_150 ) ;
break;
case V_154 :
F_89 ( V_8 ) -> V_155 = F_72 ( V_150 ) ;
break;
case V_156 :
V_23 = F_31 ( V_8 , F_72 ( V_150 ) ) ;
break;
case V_157 :
V_23 = F_51 ( V_8 , F_72 ( V_150 ) ) ;
break;
case V_158 :
V_23 = F_54 ( V_8 , F_72 ( V_150 ) ) ;
break;
case V_159 :
V_23 = F_63 ( V_8 , F_72 ( V_150 ) ) ;
break;
case V_160 :
V_23 = F_62 ( V_8 , F_72 ( V_150 ) ) ;
break;
case V_161 :
V_23 = F_64 ( V_8 , F_72 ( V_150 ) ) ;
break;
}
return V_23 ;
}
static int F_90 ( struct V_126 * V_127 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_133 , int V_134 )
{
struct V_5 * V_13 ;
int V_23 ;
V_23 = F_91 ( V_8 , V_10 ) ;
if ( V_23 )
return V_23 ;
if ( ! F_78 ( V_133 , V_134 ) ) {
V_8 = F_81 ( V_8 , V_19 ) ;
if ( ! V_8 )
return 0 ;
}
V_13 = F_5 ( V_8 , V_10 , NULL ) ;
if ( V_13 ) {
V_13 -> V_16 . V_162 = F_76 ( V_133 ) ;
} else {
F_69 ( V_8 ) ;
if ( F_82 () )
F_83 ( L_2 ,
F_84 ( V_127 ) ) ;
}
return 0 ;
}
static int F_92 ( struct V_126 * V_127 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 , int V_38 )
{
int V_163 = - 1 ;
const struct V_11 * V_133 ;
int V_134 ;
for ( V_133 = V_12 , V_134 = V_38 ; V_134 > 0 ;
V_133 = F_74 ( V_133 , & V_134 ) ) {
int V_23 = 0 ;
if ( V_163 != - 1 ) {
F_67 ( V_127 , F_81 ( V_8 , V_19 ) , V_163 ) ;
V_163 = - 1 ;
}
switch ( F_75 ( V_133 ) ) {
case V_164 :
V_163 = F_76 ( V_133 ) ;
break;
case V_144 :
F_71 ( V_127 , V_8 , V_10 , V_133 ) ;
break;
case V_165 :
F_85 ( V_8 , V_10 , V_133 ) ;
break;
case V_166 :
V_23 = F_27 ( V_8 , F_72 ( V_133 ) ) ;
if ( F_13 ( V_23 ) )
return V_23 ;
break;
case V_167 :
V_23 = F_21 ( V_8 ) ;
break;
case V_168 :
V_23 = F_90 ( V_127 , V_8 , V_10 , V_133 , V_134 ) ;
if ( F_78 ( V_133 , V_134 ) ) {
return V_23 ;
}
break;
case V_169 :
V_23 = F_88 ( V_8 , F_72 ( V_133 ) ) ;
break;
case V_170 :
V_23 = F_79 ( V_127 , V_8 , V_10 , V_133 ) ;
break;
}
if ( F_13 ( V_23 ) ) {
F_69 ( V_8 ) ;
return V_23 ;
}
}
if ( V_163 != - 1 )
F_67 ( V_127 , V_8 , V_163 ) ;
else
F_93 ( V_8 ) ;
return 0 ;
}
static void F_94 ( struct V_126 * V_127 )
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
F_92 ( V_127 , V_8 , V_10 , V_15 ,
F_73 ( V_15 ) ) ;
else
F_95 ( V_8 , V_10 ) ;
} while ( ! F_2 ( V_2 ) );
F_1 ( V_2 ) ;
}
int F_96 ( struct V_126 * V_127 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_171 = F_97 ( V_172 ) ;
struct V_173 * V_174 ;
int V_23 ;
V_174 = F_98 ( F_89 ( V_8 ) -> V_175 -> V_176 ) ;
F_99 ( V_172 ) ;
F_89 ( V_8 ) -> V_155 = NULL ;
V_23 = F_92 ( V_127 , V_8 , V_10 ,
V_174 -> V_15 , V_174 -> V_177 ) ;
if ( ! V_171 )
F_94 ( V_127 ) ;
F_100 ( V_172 ) ;
return V_23 ;
}
int F_101 ( void )
{
V_14 = F_102 ( struct V_1 ) ;
if ( ! V_14 )
return - V_18 ;
return 0 ;
}
void F_103 ( void )
{
F_104 ( V_14 ) ;
}
