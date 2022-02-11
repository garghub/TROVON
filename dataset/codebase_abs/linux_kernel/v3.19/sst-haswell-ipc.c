static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 & V_2 ) >> V_3 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return ( V_1 & V_4 ) >> V_5 ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return ( V_1 & V_6 ) >> V_7 ;
}
static inline T_1 F_4 ( T_1 V_1 )
{
return ( V_1 & V_8 ) >> V_9 ;
}
static inline T_1 F_5 ( T_1 V_1 , T_1 type )
{
return ( V_1 & ~ V_8 ) +
( type << V_9 ) ;
}
static inline T_1 F_6 ( T_1 V_1 )
{
return ( V_1 & V_10 ) >> V_11 ;
}
static inline T_1 F_7 ( T_1 V_1 )
{
return ( V_1 & V_8 ) >> V_9 ;
}
T_1 F_8 ( enum V_12 V_13 )
{
switch ( V_13 ) {
case V_14 :
return ( 0xFFFFFFF0 | V_15 ) ;
case V_16 :
return ( 0xFFFFFF00 | V_17
| ( V_18 << 4 ) ) ;
case V_19 :
return ( 0xFFFFF000 | V_17
| ( V_18 << 4 )
| ( V_20 << 8 ) ) ;
case V_21 :
return ( 0xFFFFF000 | V_17
| ( V_15 << 4 )
| ( V_18 << 8 ) ) ;
case V_22 :
return ( 0xFFFF0000 | V_17
| ( V_15 << 4 )
| ( V_18 << 8 )
| ( V_20 << 12 ) ) ;
case V_23 :
return ( 0xFFFF0000 | V_17
| ( V_18 << 4 )
| ( V_24 << 8 )
| ( V_25 << 12 ) ) ;
case V_26 :
return ( 0xFFFF0000 | V_17
| ( V_15 << 4 )
| ( V_18 << 8 )
| ( V_27 << 12 ) ) ;
case V_28 :
return ( 0xFFF00000 | V_17
| ( V_15 << 4 )
| ( V_18 << 8 )
| ( V_24 << 12 )
| ( V_25 << 16 ) ) ;
case V_29 :
return ( 0xFF000000 | V_15
| ( V_17 << 4 )
| ( V_18 << 8 )
| ( V_24 << 12 )
| ( V_25 << 16 )
| ( V_20 << 20 ) ) ;
case V_30 :
return ( 0xFFFFFF00 | V_17
| ( V_17 << 4 ) ) ;
default:
return 0xFFFFFFFF ;
}
}
static struct V_31 * F_9 ( struct V_32 * V_33 ,
int V_34 )
{
struct V_31 * V_35 ;
F_10 (stream, &hsw->stream_list, node) {
if ( V_35 -> V_36 . V_37 == V_34 )
return V_35 ;
}
return NULL ;
}
static void F_11 ( struct V_32 * V_33 , const char * V_38 )
{
struct V_39 * V_40 = V_33 -> V_41 ;
T_1 V_42 , V_43 , V_44 , V_45 ;
V_45 = F_12 ( V_40 , V_46 ) ;
V_42 = F_12 ( V_40 , V_47 ) ;
V_43 = F_12 ( V_40 , V_48 ) ;
V_44 = F_12 ( V_40 , V_49 ) ;
F_13 ( V_33 -> V_50 , L_1 ,
V_38 , V_45 , V_42 , V_43 , V_44 ) ;
}
static struct V_51 * F_14 ( struct V_32 * V_33 )
{
struct V_51 * V_1 = NULL ;
if ( ! F_15 ( & V_33 -> V_52 ) ) {
V_1 = F_16 ( & V_33 -> V_52 , struct V_51 ,
V_53 ) ;
F_17 ( & V_1 -> V_53 ) ;
}
return V_1 ;
}
static void F_18 ( struct V_54 * V_55 )
{
struct V_32 * V_33 =
F_19 ( V_55 , struct V_32 , V_56 ) ;
struct V_51 * V_1 ;
unsigned long V_57 ;
T_1 V_45 ;
F_20 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
if ( F_15 ( & V_33 -> V_59 ) || V_33 -> V_60 ) {
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return;
}
V_45 = F_12 ( V_33 -> V_41 , V_46 ) ;
if ( V_45 & ( V_61 | V_62 ) ) {
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return;
}
V_1 = F_16 ( & V_33 -> V_59 , struct V_51 , V_53 ) ;
F_22 ( & V_1 -> V_53 , & V_33 -> V_63 ) ;
F_23 ( V_33 -> V_41 , V_1 -> V_64 , V_1 -> V_65 ) ;
F_24 ( V_33 -> V_41 , V_1 -> V_66 | V_61 ) ;
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
}
static void F_25 ( struct V_32 * V_33 , struct V_51 * V_1 )
{
V_1 -> V_67 = true ;
F_26 ( L_2 , V_1 -> V_66 ) ;
if ( ! V_1 -> V_68 )
F_27 ( & V_1 -> V_53 , & V_33 -> V_52 ) ;
else
F_28 ( & V_1 -> V_69 ) ;
}
static int F_29 ( struct V_32 * V_33 , struct V_51 * V_1 ,
void * V_70 )
{
unsigned long V_57 ;
int V_71 ;
V_71 = F_30 ( V_1 -> V_69 , V_1 -> V_67 ,
F_31 ( V_72 ) ) ;
F_20 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
if ( V_71 == 0 ) {
F_11 ( V_33 , L_3 ) ;
F_32 ( L_4 , V_1 -> V_66 ) ;
F_17 ( & V_1 -> V_53 ) ;
V_71 = - V_73 ;
} else {
if ( V_1 -> V_74 )
memcpy ( V_70 , V_1 -> V_70 , V_1 -> V_74 ) ;
V_71 = V_1 -> V_75 ;
}
F_27 ( & V_1 -> V_53 , & V_33 -> V_52 ) ;
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return V_71 ;
}
static int F_33 ( struct V_32 * V_33 , T_1 V_66 , void * V_64 ,
T_2 V_76 , void * V_70 , T_2 V_77 , int V_68 )
{
struct V_51 * V_1 ;
unsigned long V_57 ;
F_20 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
V_1 = F_14 ( V_33 ) ;
if ( V_1 == NULL ) {
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return - V_78 ;
}
if ( V_76 )
memcpy ( V_1 -> V_64 , V_64 , V_76 ) ;
V_1 -> V_66 = V_66 ;
V_1 -> V_65 = V_76 ;
V_1 -> V_74 = V_77 ;
V_1 -> V_68 = V_68 ;
V_1 -> V_75 = 0 ;
V_1 -> V_60 = false ;
V_1 -> V_67 = false ;
F_27 ( & V_1 -> V_53 , & V_33 -> V_59 ) ;
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
F_34 ( & V_33 -> V_79 , & V_33 -> V_56 ) ;
if ( V_68 )
return F_29 ( V_33 , V_1 , V_70 ) ;
else
return 0 ;
}
static inline int F_35 ( struct V_32 * V_33 , T_1 V_66 ,
void * V_64 , T_2 V_76 , void * V_70 , T_2 V_77 )
{
return F_33 ( V_33 , V_66 , V_64 , V_76 , V_70 ,
V_77 , 1 ) ;
}
static inline int F_36 ( struct V_32 * V_33 , T_1 V_66 ,
void * V_64 , T_2 V_76 )
{
return F_33 ( V_33 , V_66 , V_64 , V_76 , NULL , 0 , 0 ) ;
}
static void F_37 ( struct V_32 * V_33 , T_1 V_66 )
{
struct V_80 V_81 ;
T_1 V_82 ;
T_3 V_83 [ V_84 - 5 * sizeof( T_1 ) ] ;
char * V_85 [ 5 ] , * V_86 ;
int V_87 = 0 ;
V_82 = ( V_66 & 0x1FFFFFFF ) << 3 ;
F_38 ( V_33 -> V_50 , L_5 ,
V_66 , V_82 ) ;
F_39 ( V_33 -> V_41 , & V_81 , V_82 , sizeof( V_81 ) ) ;
F_40 ( V_33 -> V_41 , V_81 . V_88 ,
V_81 . V_89 , V_81 . V_90 ,
V_81 . V_91 ) ;
V_33 -> V_92 = true ;
F_28 ( & V_33 -> V_93 ) ;
F_38 ( V_33 -> V_50 , L_6 ,
V_81 . V_88 , V_81 . V_89 ) ;
F_38 ( V_33 -> V_50 , L_7 ,
V_81 . V_90 , V_81 . V_91 ) ;
if ( V_81 . V_94 < sizeof( V_81 . V_83 ) ) {
V_81 . V_83 [ V_81 . V_94 ] = 0 ;
F_38 ( V_33 -> V_50 , L_8 , V_81 . V_83 ) ;
memcpy ( V_83 , V_81 . V_83 , V_81 . V_94 ) ;
V_86 = & V_83 [ 0 ] ;
for ( V_87 = 0 ; V_87 < sizeof( V_85 ) / sizeof( char * ) ; V_87 ++ )
V_85 [ V_87 ] = F_41 ( & V_86 , L_9 ) ;
F_42 ( V_33 -> V_50 , L_10
L_11 ,
V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] , V_85 [ 4 ] ) ;
}
}
static void F_43 ( struct V_95 * V_55 )
{
struct V_31 * V_35 = F_19 ( V_55 ,
struct V_31 , V_96 ) ;
struct V_97 * V_98 = & V_35 -> V_98 ;
struct V_99 * V_100 = & V_35 -> V_101 ;
struct V_32 * V_33 = V_35 -> V_33 ;
T_1 V_102 ;
V_102 = F_7 ( V_35 -> V_66 ) ;
switch ( V_102 ) {
case V_103 :
F_44 ( L_12 ,
V_35 -> V_36 . V_37 ) ;
F_45 ( V_33 -> V_41 , V_98 , sizeof( * V_98 ) ) ;
F_13 ( V_33 -> V_50 , L_13 ,
V_98 -> V_104 , V_98 -> V_105 ,
V_98 -> V_106 ) ;
break;
case V_107 :
F_44 ( L_14 ,
V_35 -> V_36 . V_37 ) ;
F_45 ( V_33 -> V_41 , V_100 , sizeof( * V_100 ) ) ;
if ( V_35 -> V_108 )
V_35 -> V_108 ( V_35 , V_35 -> V_109 ) ;
break;
default:
F_13 ( V_33 -> V_50 , L_15 ,
V_35 -> V_66 ) ;
break;
}
F_46 ( V_33 -> V_41 , V_48 ,
V_110 | V_111 , V_111 ) ;
F_46 ( V_33 -> V_41 , V_49 , V_112 , 0 ) ;
}
static struct V_51 * F_47 ( struct V_32 * V_33 , T_1 V_66 )
{
struct V_51 * V_1 ;
V_66 &= ~ ( V_113 | V_4 ) ;
if ( F_15 ( & V_33 -> V_63 ) ) {
F_13 ( V_33 -> V_50 , L_16 ,
V_66 ) ;
return NULL ;
}
F_10 (msg, &hsw->rx_list, list) {
if ( V_1 -> V_66 == V_66 )
return V_1 ;
}
return NULL ;
}
static void F_48 ( struct V_32 * V_33 , struct V_51 * V_1 )
{
struct V_31 * V_35 ;
T_1 V_66 = V_1 -> V_66 & ~ ( V_113 | V_4 ) ;
T_1 V_34 = F_6 ( V_66 ) ;
T_1 V_114 = F_3 ( V_66 ) ;
V_35 = F_9 ( V_33 , V_34 ) ;
if ( V_35 == NULL )
return;
switch ( V_114 ) {
case V_115 :
case V_116 :
break;
case V_117 :
F_44 ( L_17 , V_35 -> V_36 . V_37 ) ;
break;
case V_118 :
V_35 -> V_119 = false ;
F_44 ( L_18 ,
V_35 -> V_36 . V_37 ) ;
break;
case V_120 :
V_35 -> V_119 = true ;
F_44 ( L_19 ,
V_35 -> V_36 . V_37 ) ;
break;
}
}
static int F_49 ( struct V_32 * V_33 , T_1 V_66 )
{
struct V_51 * V_1 ;
T_1 V_36 = F_2 ( V_66 ) ;
F_26 ( L_20 , V_66 ) ;
V_1 = F_47 ( V_33 , V_66 ) ;
if ( V_1 == NULL ) {
F_32 ( L_21 , V_66 ) ;
return - V_121 ;
}
switch ( V_36 ) {
case V_122 :
F_50 ( L_22 , V_66 ) ;
V_1 -> V_60 = true ;
V_33 -> V_60 = true ;
return 1 ;
case V_123 :
if ( V_1 -> V_60 ) {
F_50 ( L_2 , V_66 ) ;
F_45 ( V_33 -> V_41 , V_1 -> V_70 ,
V_1 -> V_74 ) ;
V_33 -> V_60 = false ;
} else {
F_51 ( V_33 -> V_41 , V_1 -> V_70 ,
V_1 -> V_74 ) ;
}
break;
case V_124 :
F_32 ( L_23 , V_66 ) ;
V_1 -> V_75 = - V_125 ;
break;
case V_126 :
F_32 ( L_24 , V_66 ) ;
V_1 -> V_75 = - V_127 ;
break;
case V_128 :
F_32 ( L_25 , V_66 ) ;
V_1 -> V_75 = - V_78 ;
break;
case V_129 :
F_32 ( L_26 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
case V_131 :
F_32 ( L_27 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
case V_132 :
F_32 ( L_28 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
case V_133 :
F_32 ( L_29 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
case V_134 :
F_32 ( L_30 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
case V_135 :
F_32 ( L_31 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
default:
F_32 ( L_32 , V_66 ) ;
V_1 -> V_75 = - V_130 ;
break;
}
if ( F_1 ( V_66 ) == V_136 )
F_48 ( V_33 , V_1 ) ;
F_17 ( & V_1 -> V_53 ) ;
F_25 ( V_33 , V_1 ) ;
return 1 ;
}
static int F_52 ( struct V_32 * V_33 , T_1 V_66 )
{
T_1 V_114 , V_34 , V_137 ;
struct V_31 * V_35 ;
int V_138 = 0 ;
V_114 = F_3 ( V_66 ) ;
V_34 = F_6 ( V_66 ) ;
V_137 = F_4 ( V_66 ) ;
V_35 = F_9 ( V_33 , V_34 ) ;
if ( V_35 == NULL )
return V_138 ;
V_35 -> V_66 = V_66 ;
switch ( V_114 ) {
case V_115 :
F_13 ( V_33 -> V_50 , L_33 ,
V_66 ) ;
break;
case V_116 :
F_53 ( & V_35 -> V_96 ) ;
break;
default:
V_138 = F_49 ( V_33 , V_66 ) ;
break;
}
return V_138 ;
}
static int F_54 ( struct V_32 * V_33 , T_1 V_66 )
{
T_1 V_139 = ( V_66 & V_140 ) >> V_141 ;
struct V_142 * V_35 = & V_33 -> V_143 ;
int V_71 = 1 ;
if ( V_139 != V_144 ) {
F_13 ( V_33 -> V_50 ,
L_34 , V_66 ) ;
return 0 ;
}
F_55 ( & V_35 -> V_145 ) ;
V_35 -> V_146 = V_35 -> V_147 ;
F_45 (
V_33 -> V_41 , & V_35 -> V_147 , sizeof( V_35 -> V_147 ) ) ;
F_56 ( & V_35 -> V_145 ) ;
F_53 ( & V_35 -> V_96 ) ;
return V_71 ;
}
static int F_57 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 ;
T_1 type , V_66 ;
int V_138 = 1 ;
V_66 = F_12 ( V_40 , V_48 ) ;
type = F_1 ( V_66 ) ;
F_58 ( L_20 , V_66 ) ;
if ( ! V_33 -> V_92 && V_66 & V_148 ) {
F_37 ( V_33 , V_66 ) ;
return V_138 ;
}
switch ( type ) {
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
F_13 ( V_33 -> V_50 , L_35 ,
type , V_66 ) ;
break;
case V_136 :
V_138 = F_52 ( V_33 , V_66 ) ;
break;
case V_161 :
V_138 = F_54 ( V_33 , V_66 ) ;
break;
default:
F_13 ( V_33 -> V_50 , L_36 ,
type , V_66 ) ;
break;
}
return V_138 ;
}
static T_4 F_59 ( int V_162 , void * V_163 )
{
struct V_39 * V_40 = (struct V_39 * ) V_163 ;
struct V_32 * V_33 = F_60 ( V_40 ) ;
T_1 V_45 , V_43 ;
int V_138 ;
unsigned long V_57 ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
V_45 = F_61 ( V_33 -> V_41 ) ;
V_43 = F_12 ( V_40 , V_48 ) ;
if ( V_45 & V_62 ) {
V_138 = F_49 ( V_33 , V_45 ) ;
if ( V_138 > 0 ) {
F_62 ( V_40 , V_46 ,
V_62 , 0 ) ;
F_62 ( V_40 , V_49 ,
V_164 , 0 ) ;
}
}
if ( V_43 & V_110 ) {
V_138 = F_57 ( V_33 ) ;
if ( V_138 > 0 ) {
F_62 ( V_40 , V_48 ,
V_110 | V_111 , V_111 ) ;
F_62 ( V_40 , V_49 ,
V_112 , 0 ) ;
}
}
F_21 ( & V_40 -> V_58 , V_57 ) ;
F_34 ( & V_33 -> V_79 , & V_33 -> V_56 ) ;
return V_165 ;
}
int F_63 ( struct V_32 * V_33 ,
struct V_166 * V_167 )
{
int V_71 ;
V_71 = F_35 ( V_33 , F_64 ( V_149 ) ,
NULL , 0 , V_167 , sizeof( * V_167 ) ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_37 ) ;
return V_71 ;
}
int F_65 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_71 = F_66 ( V_33 , V_35 , V_168 , V_169 ,
& V_35 -> V_170 [ V_169 ] ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_67 ( V_33 , V_35 , V_168 , V_169 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_38 ,
V_35 -> V_36 . V_37 , V_169 ) ;
return V_71 ;
}
V_35 -> V_171 [ V_169 ] = 1 ;
return 0 ;
}
int F_68 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_35 -> V_171 [ V_169 ] = 0 ;
V_71 = F_67 ( V_33 , V_35 , V_168 , V_169 ,
V_35 -> V_170 [ V_169 ] ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_38 ,
V_35 -> V_36 . V_37 , V_169 ) ;
return V_71 ;
}
return 0 ;
}
int F_66 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_168 , T_1 V_169 , T_1 * V_172 )
{
if ( V_169 > 1 )
return - V_130 ;
F_39 ( V_33 -> V_41 , V_172 ,
V_35 -> V_36 . V_173 [ V_169 ] ,
sizeof( * V_172 ) ) ;
return 0 ;
}
int F_69 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_5 V_174 ,
enum V_175 V_176 )
{
V_35 -> V_177 . V_174 = V_174 ;
V_35 -> V_177 . V_178 = V_176 ;
return 0 ;
}
int F_67 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_168 , T_1 V_169 , T_1 V_172 )
{
struct V_179 * V_180 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_39 , V_35 -> V_36 . V_37 ) ;
if ( V_169 >= 2 && V_169 != V_181 )
return - V_130 ;
V_66 = F_64 ( V_136 ) |
F_70 ( V_115 ) ;
V_66 |= ( V_35 -> V_36 . V_37 << V_11 ) ;
V_66 |= ( V_182 << V_9 ) ;
V_66 |= ( V_168 << V_183 ) ;
V_180 = & V_35 -> V_177 ;
V_180 -> V_184 = V_172 ;
if ( V_169 == V_181 ) {
if ( V_33 -> V_171 [ 0 ] && V_33 -> V_171 [ 1 ] ) {
V_33 -> V_170 [ 0 ] = V_33 -> V_170 [ 1 ] = V_172 ;
return 0 ;
} else if ( V_33 -> V_171 [ 0 ] )
V_180 -> V_169 = 1 ;
else if ( V_33 -> V_171 [ 1 ] )
V_180 -> V_169 = 0 ;
else
V_180 -> V_169 = V_181 ;
} else {
if ( V_33 -> V_171 [ V_169 ] ) {
V_33 -> V_170 [ V_169 ] = V_172 ;
return 0 ;
}
V_180 -> V_169 = V_169 ;
}
V_71 = F_35 ( V_33 , V_66 , V_180 , sizeof( * V_180 ) , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_40 ) ;
return V_71 ;
}
return 0 ;
}
int F_71 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_71 = F_72 ( V_33 , V_168 , V_169 ,
& V_33 -> V_170 [ V_169 ] ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_73 ( V_33 , V_168 , V_169 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_41 ,
V_169 ) ;
return V_71 ;
}
V_33 -> V_171 [ V_169 ] = 1 ;
return 0 ;
}
int F_74 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_71 = F_73 ( V_33 , V_168 , V_169 ,
V_33 -> V_185 . V_173 [ V_169 ] ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_41 ,
V_169 ) ;
return V_71 ;
}
V_33 -> V_171 [ V_169 ] = 0 ;
return 0 ;
}
int F_72 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 ,
T_1 * V_172 )
{
if ( V_169 > 1 )
return - V_130 ;
F_39 ( V_33 -> V_41 , V_172 ,
V_33 -> V_185 . V_173 [ V_169 ] ,
sizeof( * V_172 ) ) ;
return 0 ;
}
int F_75 ( struct V_32 * V_33 ,
T_5 V_174 , enum V_175 V_176 )
{
V_33 -> V_174 = V_174 ;
V_33 -> V_178 = V_176 ;
return 0 ;
}
int F_73 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 ,
T_1 V_172 )
{
struct V_179 V_180 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_42 , V_172 ) ;
if ( V_169 >= 2 && V_169 != V_181 )
return - V_130 ;
if ( V_169 == V_181 ) {
if ( V_33 -> V_171 [ 0 ] && V_33 -> V_171 [ 1 ] ) {
V_33 -> V_170 [ 0 ] = V_33 -> V_170 [ 1 ] = V_172 ;
return 0 ;
} else if ( V_33 -> V_171 [ 0 ] )
V_180 . V_169 = 1 ;
else if ( V_33 -> V_171 [ 1 ] )
V_180 . V_169 = 0 ;
else
V_180 . V_169 = V_181 ;
} else {
if ( V_33 -> V_171 [ V_169 ] ) {
V_33 -> V_170 [ V_169 ] = V_172 ;
return 0 ;
}
V_180 . V_169 = V_169 ;
}
V_66 = F_64 ( V_136 ) |
F_70 ( V_115 ) ;
V_66 |= ( V_33 -> V_185 . V_186 << V_11 ) ;
V_66 |= ( V_182 << V_9 ) ;
V_66 |= ( V_168 << V_183 ) ;
V_180 . V_174 = V_33 -> V_174 ;
V_180 . V_178 = V_33 -> V_178 ;
V_180 . V_184 = V_172 ;
V_71 = F_35 ( V_33 , V_66 , & V_180 , sizeof( V_180 ) , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_43 ) ;
return V_71 ;
}
return 0 ;
}
struct V_31 * F_76 ( struct V_32 * V_33 , int V_187 ,
T_1 (* V_108)( struct V_31 * V_35 , void * V_188 ) ,
void * V_188 )
{
struct V_31 * V_35 ;
struct V_39 * V_40 = V_33 -> V_41 ;
unsigned long V_57 ;
V_35 = F_77 ( sizeof( * V_35 ) , V_189 ) ;
if ( V_35 == NULL )
return NULL ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
F_78 ( & V_35 -> V_190 , & V_33 -> V_191 ) ;
V_35 -> V_108 = V_108 ;
V_35 -> V_109 = V_188 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_192 = V_187 ;
F_79 ( & V_35 -> V_96 , F_43 ) ;
F_21 ( & V_40 -> V_58 , V_57 ) ;
return V_35 ;
}
int F_80 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
T_1 V_66 ;
int V_71 = 0 ;
struct V_39 * V_40 = V_33 -> V_41 ;
unsigned long V_57 ;
if ( ! V_35 ) {
F_81 ( V_33 -> V_50 , L_44 ) ;
return 0 ;
}
if ( ! V_35 -> V_193 )
goto V_194;
F_58 ( L_45 , V_35 -> V_192 ) ;
V_35 -> V_195 . V_34 = V_35 -> V_36 . V_37 ;
V_66 = F_64 ( V_151 ) ;
V_71 = F_35 ( V_33 , V_66 , & V_35 -> V_195 ,
sizeof( V_35 -> V_195 ) , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_46 ,
V_35 -> V_195 . V_34 ) ;
return - V_196 ;
}
F_82 ( V_35 , & V_35 -> V_195 ) ;
V_194:
F_83 ( & V_35 -> V_96 ) ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
F_17 ( & V_35 -> V_190 ) ;
F_84 ( V_35 ) ;
F_21 ( & V_40 -> V_58 , V_57 ) ;
return V_71 ;
}
int F_85 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_197 V_198 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_47 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_200 . V_201 = V_198 ;
return 0 ;
}
int F_86 ( struct V_32 * V_33 ,
struct V_31 * V_35 , int V_202 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_48 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_200 . V_203 = V_202 ;
return 0 ;
}
int F_87 ( struct V_32 * V_33 ,
struct V_31 * V_35 , int V_204 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_49 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_200 . V_205 = V_204 ;
return 0 ;
}
int F_88 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_206 ,
enum V_12 V_13 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_50 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_200 . V_206 = V_206 ;
V_35 -> V_199 . V_200 . V_13 = V_13 ;
return 0 ;
}
int F_89 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_207 V_208 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_51 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_200 . V_208 = V_208 ;
return 0 ;
}
int F_90 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_198 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_52 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_200 . V_209 = V_198 ;
return 0 ;
}
int F_91 ( struct V_32 * V_33 , struct V_31 * V_35 ,
enum V_210 V_211 ,
enum V_212 V_213 ,
enum F_91 V_214 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_53 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_211 = V_211 ;
V_35 -> V_199 . V_213 = V_213 ;
V_35 -> V_199 . V_214 = V_214 ;
F_92 ( V_35 , & V_35 -> V_199 ) ;
return 0 ;
}
int F_93 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_215 , T_1 V_216 ,
T_1 V_217 , T_1 V_218 , T_1 V_219 )
{
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_54 ) ;
return - V_130 ;
}
V_35 -> V_199 . V_220 . V_215 = V_215 ;
V_35 -> V_199 . V_220 . V_216 = V_216 ;
V_35 -> V_199 . V_220 . V_217 = V_217 ;
V_35 -> V_199 . V_220 . V_218 = V_218 ;
V_35 -> V_199 . V_220 . V_219 = V_219 ;
F_94 ( V_35 ) ;
return 0 ;
}
int F_95 ( struct V_32 * V_33 ,
struct V_31 * V_35 , struct V_221 * V_222 )
{
struct V_223 * V_206 = & V_35 -> V_199 . V_206 ;
struct V_39 * V_41 = F_96 ( V_33 ) ;
struct V_224 * V_225 = V_222 -> V_225 ;
if ( V_35 -> V_193 ) {
F_13 ( V_33 -> V_50 , L_55 ) ;
return - V_130 ;
}
V_206 -> V_226 = 1 ;
V_206 -> V_227 [ 0 ] . V_228 = V_225 -> V_187 ;
V_206 -> V_227 [ 0 ] . V_229 = V_225 -> V_230 ;
V_35 -> V_199 . V_231 . V_82 =
F_97 ( V_41 , V_222 -> V_232 , V_233 ) ;
V_35 -> V_199 . V_231 . V_234 = V_225 -> V_235 ;
V_35 -> V_199 . V_236 . V_82 =
F_97 ( V_41 , V_41 -> V_237 , V_233 ) ;
V_35 -> V_199 . V_236 . V_234 = V_41 -> V_238 ;
F_38 ( V_33 -> V_50 , L_56 , V_225 -> V_187 ,
V_222 -> V_187 ) ;
F_38 ( V_33 -> V_50 , L_57 ,
V_35 -> V_199 . V_231 . V_82 ,
V_35 -> V_199 . V_231 . V_234 ) ;
F_38 ( V_33 -> V_50 , L_58 ,
V_35 -> V_199 . V_236 . V_82 ,
V_35 -> V_199 . V_236 . V_234 ) ;
return 0 ;
}
int F_98 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
struct V_239 * V_240 = & V_35 -> V_199 ;
struct V_241 * V_36 = & V_35 -> V_36 ;
T_1 V_66 ;
int V_71 ;
if ( ! V_35 ) {
F_81 ( V_33 -> V_50 , L_59 ) ;
return 0 ;
}
if ( V_35 -> V_193 ) {
F_81 ( V_33 -> V_50 , L_60 ) ;
return 0 ;
}
F_58 ( L_61 , V_35 -> V_192 ) ;
V_66 = F_64 ( V_150 ) ;
V_71 = F_35 ( V_33 , V_66 , V_240 , sizeof( * V_240 ) ,
V_36 , sizeof( * V_36 ) ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_62 ) ;
return V_71 ;
}
V_35 -> V_193 = 1 ;
F_99 ( V_35 ) ;
return 0 ;
}
int F_100 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_37 ;
}
int F_101 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_186 ;
}
T_1 F_102 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_242 ;
}
T_1 F_103 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_243 ;
}
T_1 F_104 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_169 )
{
if ( V_169 >= 2 )
return 0 ;
return V_35 -> V_36 . V_244 [ V_169 ] ;
}
T_1 F_105 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_169 )
{
if ( V_169 >= 2 )
return 0 ;
return V_35 -> V_36 . V_173 [ V_169 ] ;
}
int F_106 ( struct V_32 * V_33 )
{
struct V_245 * V_36 ;
T_1 V_66 ;
int V_71 ;
V_36 = & V_33 -> V_185 ;
V_66 = F_64 ( V_157 ) ;
F_58 ( L_63 , 0 ) ;
V_71 = F_35 ( V_33 , V_66 , NULL , 0 , V_36 , sizeof( * V_36 ) ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_64 ) ;
return V_71 ;
}
F_107 ( V_36 ) ;
return 0 ;
}
static int F_108 ( struct V_32 * V_33 , int type ,
int V_34 , int V_68 )
{
T_1 V_66 ;
V_66 = F_64 ( V_136 ) | F_70 ( type ) ;
V_66 |= ( V_34 << V_11 ) ;
if ( V_68 )
return F_35 ( V_33 , V_66 , NULL , 0 , NULL , 0 ) ;
else
return F_36 ( V_33 , V_66 , NULL , 0 ) ;
}
int F_109 ( struct V_32 * V_33 , struct V_31 * V_35 ,
int V_68 )
{
int V_71 ;
if ( ! V_35 ) {
F_81 ( V_33 -> V_50 , L_65 ) ;
return 0 ;
}
F_58 ( L_66 , V_35 -> V_36 . V_37 ) ;
V_71 = F_108 ( V_33 , V_118 ,
V_35 -> V_36 . V_37 , V_68 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_67 ,
V_35 -> V_36 . V_37 ) ;
return V_71 ;
}
int F_110 ( struct V_32 * V_33 , struct V_31 * V_35 ,
int V_68 )
{
int V_71 ;
if ( ! V_35 ) {
F_81 ( V_33 -> V_50 , L_68 ) ;
return 0 ;
}
F_58 ( L_69 , V_35 -> V_36 . V_37 ) ;
V_71 = F_108 ( V_33 , V_120 ,
V_35 -> V_36 . V_37 , V_68 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_70 ,
V_35 -> V_36 . V_37 ) ;
return V_71 ;
}
int F_111 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
int V_71 , V_246 = 10 ;
if ( ! V_35 ) {
F_81 ( V_33 -> V_50 , L_71 ) ;
return 0 ;
}
if ( ! V_35 -> V_193 )
return 0 ;
while ( V_35 -> V_119 && V_246 -- )
F_112 ( 1 ) ;
if ( ! V_246 ) {
F_13 ( V_33 -> V_50 , L_72 ,
V_35 -> V_36 . V_37 ) ;
return - V_130 ;
}
F_58 ( L_17 , V_35 -> V_36 . V_37 ) ;
V_71 = F_108 ( V_33 , V_117 ,
V_35 -> V_36 . V_37 , 1 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_73 ,
V_35 -> V_36 . V_37 ) ;
return V_71 ;
}
T_1 F_113 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
T_1 V_101 ;
F_39 ( V_33 -> V_41 , & V_101 ,
V_35 -> V_36 . V_242 , sizeof( V_101 ) ) ;
return V_101 ;
}
T_5 F_114 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
T_5 V_247 ;
F_39 ( V_33 -> V_41 , & V_247 ,
V_35 -> V_36 . V_243 ,
sizeof( V_247 ) ) ;
return V_247 ;
}
int F_115 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_168 , T_1 V_248 )
{
T_1 V_66 ;
int V_71 ;
F_116 ( V_35 -> V_36 . V_37 , V_248 ) ;
V_66 = F_64 ( V_136 ) |
F_70 ( V_115 ) ;
V_66 |= ( V_35 -> V_36 . V_37 << V_11 ) ;
V_66 |= ( V_249 << V_9 ) ;
V_66 |= ( V_168 << V_183 ) ;
V_35 -> V_250 . V_248 = V_248 ;
V_71 = F_36 ( V_33 , V_66 , & V_35 -> V_250 ,
sizeof( V_35 -> V_250 ) ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_74 ,
V_35 -> V_36 . V_37 , V_248 ) ;
return V_71 ;
}
int F_117 ( struct V_32 * V_33 ,
enum V_251 V_50 , enum V_252 V_253 ,
enum V_254 V_255 , T_1 V_256 )
{
struct V_257 V_13 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_75 , V_50 ) ;
V_13 . V_258 = V_50 ;
V_13 . V_259 = V_253 ;
V_13 . V_255 = V_255 ;
V_13 . V_256 = V_256 ;
if ( V_255 == V_260 )
V_13 . V_202 = 4 ;
else
V_13 . V_202 = 2 ;
F_118 ( & V_13 ) ;
V_66 = F_64 ( V_155 ) ;
V_71 = F_35 ( V_33 , V_66 , & V_13 , sizeof( V_13 ) ,
NULL , 0 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_76 ) ;
return V_71 ;
}
int F_119 ( struct V_32 * V_33 ,
enum V_261 V_262 , struct V_263 * V_264 )
{
T_1 V_66 , V_265 ;
int V_71 , V_266 ;
V_66 = F_64 ( V_156 ) ;
V_265 = V_262 ;
F_58 ( L_77 , V_262 ) ;
V_71 = F_35 ( V_33 , V_66 , & V_265 , sizeof( V_265 ) ,
V_264 , sizeof( * V_264 ) ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_78 , V_262 ) ;
return V_71 ;
}
for ( V_266 = 0 ; V_266 < V_264 -> V_267 ; V_266 ++ ) {
F_38 ( V_33 -> V_50 ,
L_79 ,
V_266 , V_264 -> V_268 [ V_266 ] . V_82 ,
V_264 -> V_268 [ V_266 ] . V_234 ,
V_264 -> V_268 [ V_266 ] . V_269 ) ;
}
F_38 ( V_33 -> V_50 , L_80 ,
V_264 -> V_267 , V_262 ) ;
return V_71 ;
}
struct V_221 * F_120 ( struct V_32 * V_33 ,
int V_270 , int V_82 )
{
struct V_39 * V_41 = V_33 -> V_41 ;
struct V_224 * V_225 ;
struct V_221 * V_222 ;
int V_271 ;
V_225 = F_121 ( V_41 , V_270 ) ;
if ( V_225 == NULL ) {
F_13 ( V_41 -> V_50 , L_81 ,
V_270 ) ;
return NULL ;
}
V_222 = F_122 ( V_225 , V_270 , NULL ) ;
if ( V_222 == NULL ) {
F_13 ( V_41 -> V_50 , L_82 ,
V_270 ) ;
return NULL ;
}
V_271 = F_123 ( V_222 , V_82 ) ;
if ( V_271 < 0 ) {
F_13 ( V_41 -> V_50 , L_83 ,
V_270 ) ;
F_124 ( V_222 ) ;
return NULL ;
}
F_38 ( V_41 -> V_50 , L_84 , V_222 -> V_187 ,
V_270 ) ;
return V_222 ;
}
void F_125 ( struct V_221 * V_222 )
{
F_126 ( V_222 ) ;
F_124 ( V_222 ) ;
}
static int F_127 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 ;
T_1 V_266 , V_82 , V_234 ;
int V_71 = 0 ;
F_58 ( L_85 , V_272 ) ;
if ( V_33 -> V_264 . V_267 > V_272 ) {
F_13 ( V_33 -> V_50 ,
L_86 ,
V_272 ) ;
memset ( & V_33 -> V_264 , 0 , sizeof( V_33 -> V_264 ) ) ;
return - V_130 ;
}
V_71 = F_128 ( V_40 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_87 , V_71 ) ;
return V_71 ;
}
F_46 ( V_40 , V_273 ,
V_274 | V_275 ,
V_274 | V_275 ) ;
for ( V_266 = 0 ; V_266 < V_33 -> V_264 . V_267 ; V_266 ++ ) {
if ( V_33 -> V_264 . V_268 [ V_266 ] . V_269 == V_276
&& V_33 -> V_264 . V_268 [ V_266 ] . V_82 > V_277
&& V_33 -> V_264 . V_268 [ V_266 ] . V_82 <
V_277 + V_278 ) {
V_82 = V_33 -> V_264 . V_268 [ V_266 ] . V_82
- V_277 ;
V_234 = ( V_33 -> V_264 . V_268 [ V_266 ] . V_234 + 3 ) & ( ~ 3 ) ;
V_71 = F_129 ( V_40 , V_33 -> V_279 + V_82 ,
V_40 -> V_280 . V_281 + V_82 , V_234 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 ,
L_88 ) ;
memset ( & V_33 -> V_264 , 0 , sizeof( V_33 -> V_264 ) ) ;
goto V_194;
}
}
}
V_194:
F_130 ( V_40 ) ;
return V_71 ;
}
static int F_131 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 ;
T_1 V_266 , V_82 , V_234 ;
int V_71 ;
for ( V_266 = 0 ; V_266 < V_33 -> V_264 . V_267 ; V_266 ++ ) {
if ( V_33 -> V_264 . V_268 [ V_266 ] . V_269 == V_276
&& V_33 -> V_264 . V_268 [ V_266 ] . V_82 > V_277
&& V_33 -> V_264 . V_268 [ V_266 ] . V_82 <
V_277 + V_278 ) {
V_82 = V_33 -> V_264 . V_268 [ V_266 ] . V_82
- V_277 ;
V_234 = ( V_33 -> V_264 . V_268 [ V_266 ] . V_234 + 3 ) & ( ~ 3 ) ;
V_71 = F_132 ( V_40 , V_40 -> V_280 . V_281 + V_82 ,
V_33 -> V_279 + V_82 , V_234 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 ,
L_89 ) ;
return V_71 ;
}
}
}
return 0 ;
}
static void F_133 ( struct V_32 * V_33 )
{
struct V_51 * V_1 , * V_85 ;
unsigned long V_57 ;
int V_282 = 0 , V_283 = 0 ;
F_20 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
F_134 (msg, tmp, &hsw->tx_list, list) {
F_22 ( & V_1 -> V_53 , & V_33 -> V_52 ) ;
V_282 ++ ;
}
F_134 (msg, tmp, &hsw->rx_list, list) {
F_22 ( & V_1 -> V_53 , & V_33 -> V_52 ) ;
V_283 ++ ;
}
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
if ( V_282 || V_283 )
F_13 ( V_33 -> V_50 , L_90 ,
V_282 , V_283 ) ;
}
int F_135 ( struct V_32 * V_33 )
{
struct V_39 * V_41 = V_33 -> V_41 ;
int V_71 ;
F_38 ( V_33 -> V_50 , L_91 ) ;
V_71 = F_136 ( V_41 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_92 ) ;
return - V_284 ;
}
V_71 = F_128 ( V_41 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_87 , V_71 ) ;
return V_71 ;
}
V_71 = F_137 ( V_33 -> V_285 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_93 ) ;
F_130 ( V_41 ) ;
return - V_127 ;
}
F_130 ( V_41 ) ;
return 0 ;
}
static int F_138 ( struct V_32 * V_33 )
{
struct V_39 * V_41 = V_33 -> V_41 ;
int V_71 ;
F_38 ( V_33 -> V_50 , L_94 ) ;
V_71 = F_128 ( V_41 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_87 , V_71 ) ;
return V_71 ;
}
V_71 = F_131 ( V_33 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_95 ) ;
F_130 ( V_41 ) ;
return - V_127 ;
}
F_130 ( V_41 ) ;
F_139 ( V_41 ) ;
return V_71 ;
}
int F_140 ( struct V_32 * V_33 )
{
int V_71 ;
F_38 ( V_33 -> V_50 , L_96 ) ;
V_71 = F_119 ( V_33 , V_286 , & V_33 -> V_264 ) ;
if ( V_71 < 0 )
return V_71 ;
F_141 ( V_33 -> V_41 ) ;
V_71 = F_127 ( V_33 ) ;
if ( V_71 < 0 )
return V_71 ;
F_133 ( V_33 ) ;
return 0 ;
}
int F_142 ( struct V_32 * V_33 )
{
F_143 ( V_33 -> V_285 ) ;
F_144 ( V_33 -> V_41 ) ;
V_33 -> V_92 = false ;
F_145 ( V_33 -> V_41 ) ;
return 0 ;
}
int F_146 ( struct V_32 * V_33 )
{
struct V_287 * V_50 = V_33 -> V_50 ;
int V_71 ;
F_38 ( V_50 , L_97 ) ;
if ( V_33 -> V_92 )
return 1 ;
V_71 = F_138 ( V_33 ) ;
if ( V_71 < 0 )
F_13 ( V_50 , L_98 ) ;
V_71 = F_30 ( V_33 -> V_93 , V_33 -> V_92 ,
F_31 ( V_288 ) ) ;
if ( V_71 == 0 ) {
F_13 ( V_33 -> V_50 , L_99 ,
F_12 ( V_33 -> V_41 , V_48 ) ,
F_12 ( V_33 -> V_41 , V_46 ) ) ;
return - V_121 ;
}
V_71 = F_117 ( V_33 , V_289 ,
V_290 ,
V_291 , 9 ) ;
if ( V_71 < 0 )
F_13 ( V_50 , L_100 ) ;
return V_71 ;
}
static int F_147 ( struct V_32 * V_33 )
{
int V_87 ;
V_33 -> V_1 = F_77 ( sizeof( struct V_51 ) *
V_292 , V_189 ) ;
if ( V_33 -> V_1 == NULL )
return - V_127 ;
for ( V_87 = 0 ; V_87 < V_292 ; V_87 ++ ) {
F_148 ( & V_33 -> V_1 [ V_87 ] . V_69 ) ;
F_78 ( & V_33 -> V_1 [ V_87 ] . V_53 , & V_33 -> V_52 ) ;
}
return 0 ;
}
struct V_39 * F_96 ( struct V_32 * V_33 )
{
return V_33 -> V_41 ;
}
int F_149 ( struct V_287 * V_50 , struct V_293 * V_109 )
{
struct V_166 V_167 ;
struct V_32 * V_33 ;
int V_71 ;
F_38 ( V_50 , L_101 ) ;
V_33 = F_150 ( V_50 , sizeof( * V_33 ) , V_189 ) ;
if ( V_33 == NULL )
return - V_127 ;
V_33 -> V_50 = V_50 ;
F_151 ( & V_33 -> V_191 ) ;
F_151 ( & V_33 -> V_59 ) ;
F_151 ( & V_33 -> V_63 ) ;
F_151 ( & V_33 -> V_52 ) ;
F_148 ( & V_33 -> V_93 ) ;
F_148 ( & V_33 -> V_294 ) ;
V_71 = F_147 ( V_33 ) ;
if ( V_71 < 0 )
return - V_127 ;
F_152 ( & V_33 -> V_79 ) ;
V_33 -> V_295 = F_153 ( V_296 ,
& V_33 -> V_79 , L_102 ,
F_154 ( V_33 -> V_50 ) ) ;
if ( F_155 ( V_33 -> V_295 ) ) {
V_71 = F_156 ( V_33 -> V_295 ) ;
F_13 ( V_33 -> V_50 , L_103 ) ;
goto V_297;
}
F_157 ( & V_33 -> V_56 , F_18 ) ;
V_298 . V_299 = V_33 ;
V_33 -> V_41 = F_158 ( V_50 , & V_298 , V_109 ) ;
if ( V_33 -> V_41 == NULL ) {
V_71 = - V_284 ;
goto V_300;
}
V_33 -> V_301 = F_159 ( V_33 -> V_41 -> V_302 ,
V_278 , & V_33 -> V_279 , V_189 ) ;
if ( V_33 -> V_301 == NULL ) {
V_71 = - V_127 ;
goto V_303;
}
F_160 ( V_33 -> V_41 ) ;
V_33 -> V_285 = F_161 ( V_33 -> V_41 , V_109 -> V_304 , V_33 ) ;
if ( V_33 -> V_285 == NULL ) {
V_71 = - V_284 ;
F_13 ( V_50 , L_104 ) ;
goto V_305;
}
F_139 ( V_33 -> V_41 ) ;
V_71 = F_30 ( V_33 -> V_93 , V_33 -> V_92 ,
F_31 ( V_288 ) ) ;
if ( V_71 == 0 ) {
V_71 = - V_121 ;
F_13 ( V_33 -> V_50 , L_99 ,
F_12 ( V_33 -> V_41 , V_48 ) ,
F_12 ( V_33 -> V_41 , V_46 ) ) ;
goto V_306;
}
F_63 ( V_33 , & V_167 ) ;
V_71 = F_106 ( V_33 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_105 ) ;
goto V_306;
}
V_109 -> V_41 = V_33 ;
return 0 ;
V_306:
F_160 ( V_33 -> V_41 ) ;
F_162 ( V_33 -> V_285 ) ;
V_305:
F_163 ( V_33 -> V_41 -> V_302 , V_278 ,
V_33 -> V_301 , V_33 -> V_279 ) ;
V_303:
F_164 ( V_33 -> V_41 ) ;
V_300:
F_165 ( V_33 -> V_295 ) ;
V_297:
F_84 ( V_33 -> V_1 ) ;
return V_71 ;
}
void F_166 ( struct V_287 * V_50 , struct V_293 * V_109 )
{
struct V_32 * V_33 = V_109 -> V_41 ;
F_160 ( V_33 -> V_41 ) ;
F_167 ( V_33 -> V_41 ) ;
F_163 ( V_33 -> V_41 -> V_302 , V_278 ,
V_33 -> V_301 , V_33 -> V_279 ) ;
F_164 ( V_33 -> V_41 ) ;
F_84 ( V_33 -> V_307 ) ;
F_165 ( V_33 -> V_295 ) ;
F_84 ( V_33 -> V_1 ) ;
}
