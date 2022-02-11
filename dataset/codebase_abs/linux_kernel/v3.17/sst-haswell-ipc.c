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
F_46 ( V_40 , V_46 ,
V_62 , 0 ) ;
F_46 ( V_40 , V_49 ,
V_164 , 0 ) ;
}
}
if ( V_43 & V_110 ) {
V_138 = F_57 ( V_33 ) ;
if ( V_138 > 0 ) {
F_46 ( V_40 , V_48 ,
V_110 | V_111 , V_111 ) ;
F_46 ( V_40 , V_49 ,
V_112 , 0 ) ;
}
}
F_21 ( & V_40 -> V_58 , V_57 ) ;
F_34 ( & V_33 -> V_79 , & V_33 -> V_56 ) ;
return V_165 ;
}
int F_62 ( struct V_32 * V_33 ,
struct V_166 * V_167 )
{
int V_71 ;
V_71 = F_35 ( V_33 , F_63 ( V_149 ) ,
NULL , 0 , V_167 , sizeof( * V_167 ) ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_37 ) ;
return V_71 ;
}
int F_64 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_71 = F_65 ( V_33 , V_35 , V_168 , V_169 ,
& V_35 -> V_170 [ V_169 ] ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_66 ( V_33 , V_35 , V_168 , V_169 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_38 ,
V_35 -> V_36 . V_37 , V_169 ) ;
return V_71 ;
}
V_35 -> V_171 [ V_169 ] = 1 ;
return 0 ;
}
int F_67 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_35 -> V_171 [ V_169 ] = 0 ;
V_71 = F_66 ( V_33 , V_35 , V_168 , V_169 ,
V_35 -> V_170 [ V_169 ] ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_38 ,
V_35 -> V_36 . V_37 , V_169 ) ;
return V_71 ;
}
return 0 ;
}
int F_65 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_168 , T_1 V_169 , T_1 * V_172 )
{
if ( V_169 > 1 )
return - V_130 ;
F_39 ( V_33 -> V_41 , V_172 ,
V_35 -> V_36 . V_173 [ V_169 ] ,
sizeof( * V_172 ) ) ;
return 0 ;
}
int F_68 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_5 V_174 ,
enum V_175 V_176 )
{
V_35 -> V_177 . V_174 = V_174 ;
V_35 -> V_177 . V_178 = V_176 ;
return 0 ;
}
int F_66 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_168 , T_1 V_169 , T_1 V_172 )
{
struct V_179 * V_180 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_39 , V_35 -> V_36 . V_37 ) ;
if ( V_169 > 1 )
return - V_130 ;
if ( V_35 -> V_171 [ V_169 ] ) {
V_35 -> V_170 [ V_169 ] = V_172 ;
return 0 ;
}
V_66 = F_63 ( V_136 ) |
F_69 ( V_115 ) ;
V_66 |= ( V_35 -> V_36 . V_37 << V_11 ) ;
V_66 |= ( V_181 << V_9 ) ;
V_66 |= ( V_168 << V_182 ) ;
V_180 = & V_35 -> V_177 ;
V_180 -> V_169 = V_169 ;
V_180 -> V_183 = V_172 ;
V_71 = F_35 ( V_33 , V_66 , V_180 , sizeof( * V_180 ) , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_40 ) ;
return V_71 ;
}
return 0 ;
}
int F_70 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_71 = F_71 ( V_33 , V_168 , V_169 ,
& V_33 -> V_170 [ V_169 ] ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_72 ( V_33 , V_168 , V_169 , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_41 ,
V_169 ) ;
return V_71 ;
}
V_33 -> V_171 [ V_169 ] = 1 ;
return 0 ;
}
int F_73 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 )
{
int V_71 ;
V_71 = F_72 ( V_33 , V_168 , V_169 ,
V_33 -> V_184 . V_173 [ V_169 ] ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_41 ,
V_169 ) ;
return V_71 ;
}
V_33 -> V_171 [ V_169 ] = 0 ;
return 0 ;
}
int F_71 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 ,
T_1 * V_172 )
{
if ( V_169 > 1 )
return - V_130 ;
F_39 ( V_33 -> V_41 , V_172 ,
V_33 -> V_184 . V_173 [ V_169 ] ,
sizeof( * V_172 ) ) ;
return 0 ;
}
int F_74 ( struct V_32 * V_33 ,
T_5 V_174 , enum V_175 V_176 )
{
V_33 -> V_174 = V_174 ;
V_33 -> V_178 = V_176 ;
return 0 ;
}
int F_72 ( struct V_32 * V_33 , T_1 V_168 , T_1 V_169 ,
T_1 V_172 )
{
struct V_179 V_180 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_42 , V_172 ) ;
if ( V_169 == 2 ) {
if ( V_33 -> V_171 [ 0 ] && V_33 -> V_171 [ 1 ] ) {
V_33 -> V_170 [ 0 ] = V_33 -> V_170 [ 1 ] = V_172 ;
return 0 ;
} else if ( V_33 -> V_171 [ 0 ] )
V_180 . V_169 = 1 ;
else if ( V_33 -> V_171 [ 1 ] )
V_180 . V_169 = 0 ;
else
V_180 . V_169 = 0xffffffff ;
} else {
if ( V_33 -> V_171 [ V_169 ] ) {
V_33 -> V_170 [ V_169 ] = V_172 ;
return 0 ;
}
V_180 . V_169 = V_169 ;
}
V_66 = F_63 ( V_136 ) |
F_69 ( V_115 ) ;
V_66 |= ( V_33 -> V_184 . V_185 << V_11 ) ;
V_66 |= ( V_181 << V_9 ) ;
V_66 |= ( V_168 << V_182 ) ;
V_180 . V_174 = V_33 -> V_174 ;
V_180 . V_178 = V_33 -> V_178 ;
V_180 . V_183 = V_172 ;
V_71 = F_35 ( V_33 , V_66 , & V_180 , sizeof( V_180 ) , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_43 ) ;
return V_71 ;
}
return 0 ;
}
struct V_31 * F_75 ( struct V_32 * V_33 , int V_186 ,
T_1 (* V_108)( struct V_31 * V_35 , void * V_187 ) ,
void * V_187 )
{
struct V_31 * V_35 ;
struct V_39 * V_40 = V_33 -> V_41 ;
unsigned long V_57 ;
V_35 = F_76 ( sizeof( * V_35 ) , V_188 ) ;
if ( V_35 == NULL )
return NULL ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
F_77 ( & V_35 -> V_189 , & V_33 -> V_190 ) ;
V_35 -> V_108 = V_108 ;
V_35 -> V_109 = V_187 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_191 = V_186 ;
F_78 ( & V_35 -> V_96 , F_43 ) ;
F_21 ( & V_40 -> V_58 , V_57 ) ;
return V_35 ;
}
int F_79 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
T_1 V_66 ;
int V_71 = 0 ;
struct V_39 * V_40 = V_33 -> V_41 ;
unsigned long V_57 ;
if ( ! V_35 -> V_192 )
goto V_193;
F_58 ( L_44 , V_35 -> V_191 ) ;
V_35 -> V_194 . V_34 = V_35 -> V_36 . V_37 ;
V_66 = F_63 ( V_151 ) ;
V_71 = F_35 ( V_33 , V_66 , & V_35 -> V_194 ,
sizeof( V_35 -> V_194 ) , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_45 ,
V_35 -> V_194 . V_34 ) ;
return - V_195 ;
}
F_80 ( V_35 , & V_35 -> V_194 ) ;
V_193:
F_81 ( & V_35 -> V_96 ) ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
F_17 ( & V_35 -> V_189 ) ;
F_82 ( V_35 ) ;
F_21 ( & V_40 -> V_58 , V_57 ) ;
return V_71 ;
}
int F_83 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_196 V_197 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_46 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_199 . V_200 = V_197 ;
return 0 ;
}
int F_84 ( struct V_32 * V_33 ,
struct V_31 * V_35 , int V_201 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_47 ) ;
return - V_130 ;
}
if ( V_201 != 2 )
return - V_130 ;
V_35 -> V_198 . V_199 . V_202 = V_201 ;
return 0 ;
}
int F_85 ( struct V_32 * V_33 ,
struct V_31 * V_35 , int V_203 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_48 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_199 . V_204 = V_203 ;
return 0 ;
}
int F_86 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_205 ,
enum V_12 V_13 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_49 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_199 . V_205 = V_205 ;
V_35 -> V_198 . V_199 . V_13 = V_13 ;
return 0 ;
}
int F_87 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_206 V_207 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_50 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_199 . V_207 = V_207 ;
return 0 ;
}
int F_88 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_197 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_51 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_199 . V_208 = V_197 ;
return 0 ;
}
int F_89 ( struct V_32 * V_33 , struct V_31 * V_35 ,
enum V_209 V_210 ,
enum V_211 V_212 ,
enum F_89 V_213 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_52 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_210 = V_210 ;
V_35 -> V_198 . V_212 = V_212 ;
V_35 -> V_198 . V_213 = V_213 ;
F_90 ( V_35 , & V_35 -> V_198 ) ;
return 0 ;
}
int F_91 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_214 , T_1 V_215 ,
T_1 V_216 , T_1 V_217 , T_1 V_218 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_53 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_219 . V_214 = V_214 ;
V_35 -> V_198 . V_219 . V_215 = V_215 ;
V_35 -> V_198 . V_219 . V_216 = V_216 ;
V_35 -> V_198 . V_219 . V_217 = V_217 ;
V_35 -> V_198 . V_219 . V_218 = V_218 ;
F_92 ( V_35 ) ;
return 0 ;
}
int F_93 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_220 V_221 ,
T_1 V_222 )
{
struct V_223 * V_205 = & V_35 -> V_198 . V_205 ;
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_54 ) ;
return - V_130 ;
}
V_205 -> V_224 = 1 ;
V_205 -> V_225 [ 0 ] . V_221 = V_221 ;
V_205 -> V_225 [ 0 ] . V_222 = V_222 ;
return 0 ;
}
int F_94 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_82 , T_1 V_226 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_55 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_227 . V_82 = V_82 ;
V_35 -> V_198 . V_227 . V_226 = V_226 ;
return 0 ;
}
int F_95 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_82 , T_1 V_226 )
{
if ( V_35 -> V_192 ) {
F_13 ( V_33 -> V_50 , L_56 ) ;
return - V_130 ;
}
V_35 -> V_198 . V_228 . V_82 = V_82 ;
V_35 -> V_198 . V_228 . V_226 = V_226 ;
return 0 ;
}
int F_96 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
struct V_229 * V_230 = & V_35 -> V_198 ;
struct V_231 * V_36 = & V_35 -> V_36 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_57 , V_35 -> V_191 ) ;
V_66 = F_63 ( V_150 ) ;
V_71 = F_35 ( V_33 , V_66 , V_230 , sizeof( * V_230 ) ,
V_36 , sizeof( * V_36 ) ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_58 ) ;
return V_71 ;
}
V_35 -> V_192 = 1 ;
F_97 ( V_35 ) ;
return 0 ;
}
int F_98 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_37 ;
}
int F_99 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_185 ;
}
T_1 F_100 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_232 ;
}
T_1 F_101 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_233 ;
}
T_1 F_102 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_169 )
{
if ( V_169 >= 2 )
return 0 ;
return V_35 -> V_36 . V_234 [ V_169 ] ;
}
T_1 F_103 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_169 )
{
if ( V_169 >= 2 )
return 0 ;
return V_35 -> V_36 . V_173 [ V_169 ] ;
}
int F_104 ( struct V_32 * V_33 )
{
struct V_235 * V_36 ;
T_1 V_66 ;
int V_71 ;
V_36 = & V_33 -> V_184 ;
V_66 = F_63 ( V_157 ) ;
F_58 ( L_59 , 0 ) ;
V_71 = F_35 ( V_33 , V_66 , NULL , 0 , V_36 , sizeof( * V_36 ) ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_60 ) ;
return V_71 ;
}
F_105 ( V_36 ) ;
return 0 ;
}
static int F_106 ( struct V_32 * V_33 , int type ,
int V_34 , int V_68 )
{
T_1 V_66 ;
V_66 = F_63 ( V_136 ) | F_69 ( type ) ;
V_66 |= ( V_34 << V_11 ) ;
if ( V_68 )
return F_35 ( V_33 , V_66 , NULL , 0 , NULL , 0 ) ;
else
return F_36 ( V_33 , V_66 , NULL , 0 ) ;
}
int F_107 ( struct V_32 * V_33 , struct V_31 * V_35 ,
int V_68 )
{
int V_71 ;
F_58 ( L_61 , V_35 -> V_36 . V_37 ) ;
V_71 = F_106 ( V_33 , V_118 ,
V_35 -> V_36 . V_37 , V_68 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_62 ,
V_35 -> V_36 . V_37 ) ;
return V_71 ;
}
int F_108 ( struct V_32 * V_33 , struct V_31 * V_35 ,
int V_68 )
{
int V_71 ;
F_58 ( L_63 , V_35 -> V_36 . V_37 ) ;
V_71 = F_106 ( V_33 , V_120 ,
V_35 -> V_36 . V_37 , V_68 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_64 ,
V_35 -> V_36 . V_37 ) ;
return V_71 ;
}
int F_109 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
int V_71 , V_236 = 10 ;
if ( ! V_35 -> V_192 )
return 0 ;
while ( V_35 -> V_119 && V_236 -- )
F_110 ( 1 ) ;
if ( ! V_236 ) {
F_13 ( V_33 -> V_50 , L_65 ,
V_35 -> V_36 . V_37 ) ;
return - V_130 ;
}
F_58 ( L_17 , V_35 -> V_36 . V_37 ) ;
V_71 = F_106 ( V_33 , V_117 ,
V_35 -> V_36 . V_37 , 1 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_66 ,
V_35 -> V_36 . V_37 ) ;
return V_71 ;
}
T_1 F_111 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
T_1 V_101 ;
F_39 ( V_33 -> V_41 , & V_101 ,
V_35 -> V_36 . V_232 , sizeof( V_101 ) ) ;
return V_101 ;
}
T_5 F_112 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
T_5 V_237 ;
F_39 ( V_33 -> V_41 , & V_237 ,
V_35 -> V_36 . V_233 ,
sizeof( V_237 ) ) ;
return V_237 ;
}
int F_113 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_168 , T_1 V_238 )
{
T_1 V_66 ;
int V_71 ;
F_114 ( V_35 -> V_36 . V_37 , V_238 ) ;
V_66 = F_63 ( V_136 ) |
F_69 ( V_115 ) ;
V_66 |= ( V_35 -> V_36 . V_37 << V_11 ) ;
V_66 |= ( V_239 << V_9 ) ;
V_66 |= ( V_168 << V_182 ) ;
V_35 -> V_240 . V_238 = V_238 ;
V_71 = F_36 ( V_33 , V_66 , & V_35 -> V_240 ,
sizeof( V_35 -> V_240 ) ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_67 ,
V_35 -> V_36 . V_37 , V_238 ) ;
return V_71 ;
}
int F_115 ( struct V_32 * V_33 ,
enum V_241 V_50 , enum V_242 V_243 ,
enum V_244 V_245 , T_1 V_246 )
{
struct V_247 V_13 ;
T_1 V_66 ;
int V_71 ;
F_58 ( L_68 , V_50 ) ;
V_13 . V_248 = V_50 ;
V_13 . V_249 = V_243 ;
V_13 . V_245 = V_245 ;
V_13 . V_246 = V_246 ;
F_116 ( & V_13 ) ;
V_66 = F_63 ( V_155 ) ;
V_71 = F_35 ( V_33 , V_66 , & V_13 , sizeof( V_13 ) ,
NULL , 0 ) ;
if ( V_71 < 0 )
F_13 ( V_33 -> V_50 , L_69 ) ;
return V_71 ;
}
int F_117 ( struct V_32 * V_33 ,
enum V_250 V_251 , struct V_252 * V_253 )
{
T_1 V_66 , V_254 ;
int V_71 , V_255 ;
V_66 = F_63 ( V_156 ) ;
V_254 = V_251 ;
F_58 ( L_70 , V_251 ) ;
V_71 = F_35 ( V_33 , V_66 , & V_254 , sizeof( V_254 ) ,
V_253 , sizeof( * V_253 ) ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_71 , V_251 ) ;
return V_71 ;
}
for ( V_255 = 0 ; V_255 < V_253 -> V_256 ; V_255 ++ ) {
F_38 ( V_33 -> V_50 ,
L_72 ,
V_255 , V_253 -> V_257 [ V_255 ] . V_82 ,
V_253 -> V_257 [ V_255 ] . V_226 ,
V_253 -> V_257 [ V_255 ] . V_258 ) ;
}
F_38 ( V_33 -> V_50 , L_73 ,
V_253 -> V_256 , V_251 ) ;
memcpy ( & V_33 -> V_253 , V_253 , sizeof( * V_253 ) ) ;
return 0 ;
}
int F_118 ( struct V_32 * V_33 , T_1 V_255 ,
T_1 * V_82 , T_1 * V_226 , T_1 * V_258 )
{
struct V_259 * V_260 ;
struct V_252 * V_261 ;
int V_262 ;
V_261 = & V_33 -> V_253 ;
V_262 = V_261 -> V_256 ;
F_58 ( L_74 , V_262 ) ;
if ( V_255 >= V_262 )
return - V_130 ;
V_260 = & V_261 -> V_257 [ V_255 ] ;
* V_82 = V_260 -> V_82 ;
* V_226 = V_260 -> V_226 ;
* V_258 = V_260 -> V_258 ;
return 0 ;
}
static int F_119 ( struct V_32 * V_33 )
{
int V_87 ;
V_33 -> V_1 = F_76 ( sizeof( struct V_51 ) *
V_263 , V_188 ) ;
if ( V_33 -> V_1 == NULL )
return - V_127 ;
for ( V_87 = 0 ; V_87 < V_263 ; V_87 ++ ) {
F_120 ( & V_33 -> V_1 [ V_87 ] . V_69 ) ;
F_77 ( & V_33 -> V_1 [ V_87 ] . V_53 , & V_33 -> V_52 ) ;
}
return 0 ;
}
void F_121 ( struct V_32 * V_33 ,
struct V_264 * V_265 )
{
V_33 -> V_265 = V_265 ;
}
struct V_39 * F_122 ( struct V_32 * V_33 )
{
return V_33 -> V_41 ;
}
int F_123 ( struct V_266 * V_50 , struct V_267 * V_109 )
{
struct V_166 V_167 ;
struct V_32 * V_33 ;
struct V_268 * V_269 ;
int V_71 ;
F_38 ( V_50 , L_75 ) ;
V_33 = F_124 ( V_50 , sizeof( * V_33 ) , V_188 ) ;
if ( V_33 == NULL )
return - V_127 ;
V_33 -> V_50 = V_50 ;
F_125 ( & V_33 -> V_190 ) ;
F_125 ( & V_33 -> V_59 ) ;
F_125 ( & V_33 -> V_63 ) ;
F_125 ( & V_33 -> V_52 ) ;
F_120 ( & V_33 -> V_93 ) ;
F_120 ( & V_33 -> V_270 ) ;
V_71 = F_119 ( V_33 ) ;
if ( V_71 < 0 )
return - V_127 ;
F_126 ( & V_33 -> V_79 ) ;
V_33 -> V_271 = F_127 ( V_272 ,
& V_33 -> V_79 , L_76 ,
F_128 ( V_33 -> V_50 ) ) ;
if ( F_129 ( V_33 -> V_271 ) ) {
V_71 = F_130 ( V_33 -> V_271 ) ;
F_13 ( V_33 -> V_50 , L_77 ) ;
goto V_273;
}
F_131 ( & V_33 -> V_56 , F_18 ) ;
V_274 . V_275 = V_33 ;
V_33 -> V_41 = F_132 ( V_50 , & V_274 , V_109 ) ;
if ( V_33 -> V_41 == NULL ) {
V_71 = - V_276 ;
goto V_277;
}
F_133 ( V_33 -> V_41 ) ;
V_269 = F_134 ( V_33 -> V_41 , V_109 -> V_278 , V_33 ) ;
if ( V_269 == NULL ) {
V_71 = - V_276 ;
F_13 ( V_50 , L_78 ) ;
goto V_279;
}
F_135 ( V_33 -> V_41 ) ;
V_71 = F_30 ( V_33 -> V_93 , V_33 -> V_92 ,
F_31 ( V_280 ) ) ;
if ( V_71 == 0 ) {
V_71 = - V_121 ;
F_13 ( V_33 -> V_50 , L_79 ) ;
goto V_281;
}
F_62 ( V_33 , & V_167 ) ;
V_71 = F_104 ( V_33 ) ;
if ( V_71 < 0 ) {
F_13 ( V_33 -> V_50 , L_80 ) ;
goto V_281;
}
V_109 -> V_41 = V_33 ;
return 0 ;
V_281:
F_133 ( V_33 -> V_41 ) ;
F_136 ( V_269 ) ;
V_279:
F_137 ( V_33 -> V_41 ) ;
V_277:
F_138 ( V_33 -> V_271 ) ;
V_273:
F_82 ( V_33 -> V_1 ) ;
return V_71 ;
}
void F_139 ( struct V_266 * V_50 , struct V_267 * V_109 )
{
struct V_32 * V_33 = V_109 -> V_41 ;
F_133 ( V_33 -> V_41 ) ;
F_140 ( V_33 -> V_41 ) ;
F_137 ( V_33 -> V_41 ) ;
F_82 ( V_33 -> V_265 ) ;
F_138 ( V_33 -> V_271 ) ;
F_82 ( V_33 -> V_1 ) ;
}
