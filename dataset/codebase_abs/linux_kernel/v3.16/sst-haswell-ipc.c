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
if ( V_45 & V_61 ) {
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return;
}
V_1 = F_16 ( & V_33 -> V_59 , struct V_51 , V_53 ) ;
F_22 ( & V_1 -> V_53 , & V_33 -> V_62 ) ;
F_23 ( V_33 -> V_41 , V_1 -> V_63 , V_1 -> V_64 ) ;
F_24 ( V_33 -> V_41 , V_1 -> V_65 | V_61 ) ;
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
}
static void F_25 ( struct V_32 * V_33 , struct V_51 * V_1 )
{
V_1 -> V_66 = true ;
F_26 ( L_2 , V_1 -> V_65 ) ;
if ( ! V_1 -> V_67 )
F_27 ( & V_1 -> V_53 , & V_33 -> V_52 ) ;
else
F_28 ( & V_1 -> V_68 ) ;
}
static int F_29 ( struct V_32 * V_33 , struct V_51 * V_1 ,
void * V_69 )
{
unsigned long V_57 ;
int V_70 ;
V_70 = F_30 ( V_1 -> V_68 , V_1 -> V_66 ,
F_31 ( V_71 ) ) ;
F_20 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
if ( V_70 == 0 ) {
F_11 ( V_33 , L_3 ) ;
F_32 ( L_4 , V_1 -> V_65 ) ;
V_70 = - V_72 ;
} else {
if ( V_1 -> V_73 )
memcpy ( V_69 , V_1 -> V_69 , V_1 -> V_73 ) ;
V_70 = V_1 -> V_74 ;
}
F_27 ( & V_1 -> V_53 , & V_33 -> V_52 ) ;
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return V_70 ;
}
static int F_33 ( struct V_32 * V_33 , T_1 V_65 , void * V_63 ,
T_2 V_75 , void * V_69 , T_2 V_76 , int V_67 )
{
struct V_51 * V_1 ;
unsigned long V_57 ;
F_20 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
V_1 = F_14 ( V_33 ) ;
if ( V_1 == NULL ) {
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
return - V_77 ;
}
if ( V_75 )
memcpy ( V_1 -> V_63 , V_63 , V_75 ) ;
V_1 -> V_65 = V_65 ;
V_1 -> V_64 = V_75 ;
V_1 -> V_73 = V_76 ;
V_1 -> V_67 = V_67 ;
V_1 -> V_74 = 0 ;
V_1 -> V_60 = false ;
V_1 -> V_66 = false ;
F_27 ( & V_1 -> V_53 , & V_33 -> V_59 ) ;
F_21 ( & V_33 -> V_41 -> V_58 , V_57 ) ;
F_34 ( & V_33 -> V_78 , & V_33 -> V_56 ) ;
if ( V_67 )
return F_29 ( V_33 , V_1 , V_69 ) ;
else
return 0 ;
}
static inline int F_35 ( struct V_32 * V_33 , T_1 V_65 ,
void * V_63 , T_2 V_75 , void * V_69 , T_2 V_76 )
{
return F_33 ( V_33 , V_65 , V_63 , V_75 , V_69 ,
V_76 , 1 ) ;
}
static inline int F_36 ( struct V_32 * V_33 , T_1 V_65 ,
void * V_63 , T_2 V_75 )
{
return F_33 ( V_33 , V_65 , V_63 , V_75 , NULL , 0 , 0 ) ;
}
static void F_37 ( struct V_32 * V_33 , T_1 V_65 )
{
struct V_79 V_80 ;
T_1 V_81 ;
V_81 = ( V_65 & 0x1FFFFFFF ) << 3 ;
F_38 ( V_33 -> V_50 , L_5 ,
V_65 , V_81 ) ;
F_39 ( V_33 -> V_41 , & V_80 , V_81 , sizeof( V_80 ) ) ;
F_40 ( V_33 -> V_41 , V_80 . V_82 ,
V_80 . V_83 , V_80 . V_84 ,
V_80 . V_85 ) ;
V_33 -> V_86 = true ;
F_28 ( & V_33 -> V_87 ) ;
F_38 ( V_33 -> V_50 , L_6 ,
V_80 . V_82 , V_80 . V_83 ) ;
F_38 ( V_33 -> V_50 , L_7 ,
V_80 . V_84 , V_80 . V_85 ) ;
}
static void F_41 ( struct V_88 * V_55 )
{
struct V_31 * V_35 = F_19 ( V_55 ,
struct V_31 , V_89 ) ;
struct V_90 * V_91 = & V_35 -> V_91 ;
struct V_92 * V_93 = & V_35 -> V_94 ;
struct V_32 * V_33 = V_35 -> V_33 ;
T_1 V_95 ;
V_95 = F_7 ( V_35 -> V_65 ) ;
switch ( V_95 ) {
case V_96 :
F_42 ( L_8 ,
V_35 -> V_36 . V_37 ) ;
F_43 ( V_33 -> V_41 , V_91 , sizeof( * V_91 ) ) ;
F_13 ( V_33 -> V_50 , L_9 ,
V_91 -> V_97 , V_91 -> V_98 ,
V_91 -> V_99 ) ;
break;
case V_100 :
F_42 ( L_10 ,
V_35 -> V_36 . V_37 ) ;
F_43 ( V_33 -> V_41 , V_93 , sizeof( * V_93 ) ) ;
if ( V_35 -> V_101 )
V_35 -> V_101 ( V_35 , V_35 -> V_102 ) ;
break;
default:
F_13 ( V_33 -> V_50 , L_11 ,
V_35 -> V_65 ) ;
break;
}
F_44 ( V_33 -> V_41 , V_48 ,
V_103 | V_104 , V_104 ) ;
F_44 ( V_33 -> V_41 , V_49 , V_105 , 0 ) ;
}
static struct V_51 * F_45 ( struct V_32 * V_33 , T_1 V_65 )
{
struct V_51 * V_1 ;
V_65 &= ~ ( V_106 | V_4 ) ;
if ( F_15 ( & V_33 -> V_62 ) ) {
F_13 ( V_33 -> V_50 , L_12 ,
V_65 ) ;
return NULL ;
}
F_10 (msg, &hsw->rx_list, list) {
if ( V_1 -> V_65 == V_65 )
return V_1 ;
}
return NULL ;
}
static void F_46 ( struct V_32 * V_33 , struct V_51 * V_1 )
{
struct V_31 * V_35 ;
T_1 V_65 = V_1 -> V_65 & ~ ( V_106 | V_4 ) ;
T_1 V_34 = F_6 ( V_65 ) ;
T_1 V_107 = F_3 ( V_65 ) ;
V_35 = F_9 ( V_33 , V_34 ) ;
if ( V_35 == NULL )
return;
switch ( V_107 ) {
case V_108 :
case V_109 :
case V_110 :
break;
case V_111 :
V_35 -> V_112 = false ;
F_42 ( L_13 ,
V_35 -> V_36 . V_37 ) ;
break;
case V_113 :
V_35 -> V_112 = true ;
F_42 ( L_14 ,
V_35 -> V_36 . V_37 ) ;
break;
}
}
static int F_47 ( struct V_32 * V_33 , T_1 V_65 )
{
struct V_51 * V_1 ;
T_1 V_36 = F_2 ( V_65 ) ;
F_26 ( L_15 , V_65 ) ;
V_1 = F_45 ( V_33 , V_65 ) ;
if ( V_1 == NULL ) {
F_32 ( L_16 , V_65 ) ;
return - V_114 ;
}
switch ( V_36 ) {
case V_115 :
F_48 ( L_17 , V_65 ) ;
V_1 -> V_60 = true ;
V_33 -> V_60 = true ;
return 1 ;
case V_116 :
if ( V_1 -> V_60 ) {
F_48 ( L_2 , V_65 ) ;
F_43 ( V_33 -> V_41 , V_1 -> V_69 ,
V_1 -> V_73 ) ;
V_33 -> V_60 = false ;
} else {
F_49 ( V_33 -> V_41 , V_1 -> V_69 ,
V_1 -> V_73 ) ;
}
break;
case V_117 :
F_32 ( L_18 , V_65 ) ;
V_1 -> V_74 = - V_118 ;
break;
case V_119 :
F_32 ( L_19 , V_65 ) ;
V_1 -> V_74 = - V_120 ;
break;
case V_121 :
F_32 ( L_20 , V_65 ) ;
V_1 -> V_74 = - V_77 ;
break;
case V_122 :
F_32 ( L_21 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
case V_124 :
F_32 ( L_22 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
case V_125 :
F_32 ( L_23 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
case V_126 :
F_32 ( L_24 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
case V_127 :
F_32 ( L_25 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
case V_128 :
F_32 ( L_26 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
default:
F_32 ( L_27 , V_65 ) ;
V_1 -> V_74 = - V_123 ;
break;
}
F_46 ( V_33 , V_1 ) ;
F_17 ( & V_1 -> V_53 ) ;
F_25 ( V_33 , V_1 ) ;
return 1 ;
}
static int F_50 ( struct V_32 * V_33 , T_1 V_65 )
{
T_1 V_107 , V_34 , V_129 ;
struct V_31 * V_35 ;
int V_130 = 0 ;
V_107 = F_3 ( V_65 ) ;
V_34 = F_6 ( V_65 ) ;
V_129 = F_4 ( V_65 ) ;
V_35 = F_9 ( V_33 , V_34 ) ;
if ( V_35 == NULL )
return V_130 ;
V_35 -> V_65 = V_65 ;
switch ( V_107 ) {
case V_108 :
F_13 ( V_33 -> V_50 , L_28 ,
V_65 ) ;
break;
case V_109 :
F_51 ( & V_35 -> V_89 ) ;
break;
default:
V_130 = F_47 ( V_33 , V_65 ) ;
break;
}
return V_130 ;
}
static int F_52 ( struct V_32 * V_33 , T_1 V_65 )
{
T_1 V_131 = ( V_65 & V_132 ) >> V_133 ;
struct V_134 * V_35 = & V_33 -> V_135 ;
int V_70 = 1 ;
if ( V_131 != V_136 ) {
F_13 ( V_33 -> V_50 ,
L_29 , V_65 ) ;
return 0 ;
}
F_53 ( & V_35 -> V_137 ) ;
V_35 -> V_138 = V_35 -> V_139 ;
F_43 (
V_33 -> V_41 , & V_35 -> V_139 , sizeof( V_35 -> V_139 ) ) ;
F_54 ( & V_35 -> V_137 ) ;
F_51 ( & V_35 -> V_89 ) ;
return V_70 ;
}
static int F_55 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 ;
T_1 type , V_65 ;
int V_130 = 1 ;
V_65 = F_12 ( V_40 , V_48 ) ;
type = F_1 ( V_65 ) ;
F_56 ( L_15 , V_65 ) ;
if ( ! V_33 -> V_86 && V_65 & V_140 ) {
F_37 ( V_33 , V_65 ) ;
return V_130 ;
}
switch ( type ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
F_13 ( V_33 -> V_50 , L_30 ,
type , V_65 ) ;
break;
case V_153 :
V_130 = F_50 ( V_33 , V_65 ) ;
break;
case V_154 :
V_130 = F_52 ( V_33 , V_65 ) ;
break;
default:
F_13 ( V_33 -> V_50 , L_31 ,
type , V_65 ) ;
break;
}
return V_130 ;
}
static T_3 F_57 ( int V_155 , void * V_156 )
{
struct V_39 * V_40 = (struct V_39 * ) V_156 ;
struct V_32 * V_33 = F_58 ( V_40 ) ;
T_1 V_45 , V_43 ;
int V_130 ;
unsigned long V_57 ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
V_45 = F_59 ( V_33 -> V_41 ) ;
V_43 = F_12 ( V_40 , V_48 ) ;
if ( V_45 & V_157 ) {
V_130 = F_47 ( V_33 , V_45 ) ;
if ( V_130 > 0 ) {
F_44 ( V_40 , V_46 ,
V_157 , 0 ) ;
F_44 ( V_40 , V_49 ,
V_158 , 0 ) ;
}
}
if ( V_43 & V_103 ) {
V_130 = F_55 ( V_33 ) ;
if ( V_130 > 0 ) {
F_44 ( V_40 , V_48 ,
V_103 | V_104 , V_104 ) ;
F_44 ( V_40 , V_49 ,
V_105 , 0 ) ;
}
}
F_21 ( & V_40 -> V_58 , V_57 ) ;
F_34 ( & V_33 -> V_78 , & V_33 -> V_56 ) ;
return V_159 ;
}
int F_60 ( struct V_32 * V_33 ,
struct V_160 * V_161 )
{
int V_70 ;
V_70 = F_35 ( V_33 , F_61 ( V_141 ) ,
NULL , 0 , V_161 , sizeof( * V_161 ) ) ;
if ( V_70 < 0 )
F_13 ( V_33 -> V_50 , L_32 ) ;
return V_70 ;
}
int F_62 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_162 , T_1 V_163 )
{
int V_70 ;
V_70 = F_63 ( V_33 , V_35 , V_162 , V_163 ,
& V_35 -> V_164 [ V_163 ] ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_64 ( V_33 , V_35 , V_162 , V_163 , 0 ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_33 ,
V_35 -> V_36 . V_37 , V_163 ) ;
return V_70 ;
}
V_35 -> V_165 [ V_163 ] = 1 ;
return 0 ;
}
int F_65 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_162 , T_1 V_163 )
{
int V_70 ;
V_35 -> V_165 [ V_163 ] = 0 ;
V_70 = F_64 ( V_33 , V_35 , V_162 , V_163 ,
V_35 -> V_164 [ V_163 ] ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_33 ,
V_35 -> V_36 . V_37 , V_163 ) ;
return V_70 ;
}
return 0 ;
}
int F_63 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_162 , T_1 V_163 , T_1 * V_166 )
{
if ( V_163 > 1 )
return - V_123 ;
F_39 ( V_33 -> V_41 , V_166 ,
V_35 -> V_36 . V_167 [ V_163 ] ,
sizeof( * V_166 ) ) ;
return 0 ;
}
int F_66 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_4 V_168 ,
enum V_169 V_170 )
{
V_35 -> V_171 . V_168 = V_168 ;
V_35 -> V_171 . V_172 = V_170 ;
return 0 ;
}
int F_64 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_162 , T_1 V_163 , T_1 V_166 )
{
struct V_173 * V_174 ;
T_1 V_65 ;
int V_70 ;
F_56 ( L_34 , V_35 -> V_36 . V_37 ) ;
if ( V_163 > 1 )
return - V_123 ;
if ( V_35 -> V_165 [ V_163 ] ) {
V_35 -> V_164 [ V_163 ] = V_166 ;
return 0 ;
}
V_65 = F_61 ( V_153 ) |
F_67 ( V_108 ) ;
V_65 |= ( V_35 -> V_36 . V_37 << V_11 ) ;
V_65 |= ( V_175 << V_9 ) ;
V_65 |= ( V_162 << V_176 ) ;
V_174 = & V_35 -> V_171 ;
V_174 -> V_163 = V_163 ;
V_174 -> V_177 = V_166 ;
V_70 = F_35 ( V_33 , V_65 , V_174 , sizeof( * V_174 ) , NULL , 0 ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_35 ) ;
return V_70 ;
}
return 0 ;
}
int F_68 ( struct V_32 * V_33 , T_1 V_162 , T_1 V_163 )
{
int V_70 ;
V_70 = F_69 ( V_33 , V_162 , V_163 ,
& V_33 -> V_164 [ V_163 ] ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_70 ( V_33 , V_162 , V_163 , 0 ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_36 ,
V_163 ) ;
return V_70 ;
}
V_33 -> V_165 [ V_163 ] = 1 ;
return 0 ;
}
int F_71 ( struct V_32 * V_33 , T_1 V_162 , T_1 V_163 )
{
int V_70 ;
V_70 = F_70 ( V_33 , V_162 , V_163 ,
V_33 -> V_178 . V_167 [ V_163 ] ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_36 ,
V_163 ) ;
return V_70 ;
}
V_33 -> V_165 [ V_163 ] = 0 ;
return 0 ;
}
int F_69 ( struct V_32 * V_33 , T_1 V_162 , T_1 V_163 ,
T_1 * V_166 )
{
if ( V_163 > 1 )
return - V_123 ;
F_39 ( V_33 -> V_41 , V_166 ,
V_33 -> V_178 . V_167 [ V_163 ] ,
sizeof( * V_166 ) ) ;
return 0 ;
}
int F_72 ( struct V_32 * V_33 ,
T_4 V_168 , enum V_169 V_170 )
{
V_33 -> V_168 = V_168 ;
V_33 -> V_172 = V_170 ;
return 0 ;
}
int F_70 ( struct V_32 * V_33 , T_1 V_162 , T_1 V_163 ,
T_1 V_166 )
{
struct V_173 V_174 ;
T_1 V_65 ;
int V_70 ;
F_56 ( L_37 , V_166 ) ;
if ( V_163 == 2 ) {
if ( V_33 -> V_165 [ 0 ] && V_33 -> V_165 [ 1 ] ) {
V_33 -> V_164 [ 0 ] = V_33 -> V_164 [ 1 ] = V_166 ;
return 0 ;
} else if ( V_33 -> V_165 [ 0 ] )
V_174 . V_163 = 1 ;
else if ( V_33 -> V_165 [ 1 ] )
V_174 . V_163 = 0 ;
else
V_174 . V_163 = 0xffffffff ;
} else {
if ( V_33 -> V_165 [ V_163 ] ) {
V_33 -> V_164 [ V_163 ] = V_166 ;
return 0 ;
}
V_174 . V_163 = V_163 ;
}
V_65 = F_61 ( V_153 ) |
F_67 ( V_108 ) ;
V_65 |= ( V_33 -> V_178 . V_179 << V_11 ) ;
V_65 |= ( V_175 << V_9 ) ;
V_65 |= ( V_162 << V_176 ) ;
V_174 . V_168 = V_33 -> V_168 ;
V_174 . V_172 = V_33 -> V_172 ;
V_174 . V_177 = V_166 ;
V_70 = F_35 ( V_33 , V_65 , & V_174 , sizeof( V_174 ) , NULL , 0 ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_38 ) ;
return V_70 ;
}
return 0 ;
}
struct V_31 * F_73 ( struct V_32 * V_33 , int V_180 ,
T_1 (* V_101)( struct V_31 * V_35 , void * V_181 ) ,
void * V_181 )
{
struct V_31 * V_35 ;
struct V_39 * V_40 = V_33 -> V_41 ;
unsigned long V_57 ;
V_35 = F_74 ( sizeof( * V_35 ) , V_182 ) ;
if ( V_35 == NULL )
return NULL ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
F_75 ( & V_35 -> V_183 , & V_33 -> V_184 ) ;
V_35 -> V_101 = V_101 ;
V_35 -> V_102 = V_181 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_185 = V_180 ;
F_76 ( & V_35 -> V_89 , F_41 ) ;
F_21 ( & V_40 -> V_58 , V_57 ) ;
return V_35 ;
}
int F_77 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
T_1 V_65 ;
int V_70 = 0 ;
struct V_39 * V_40 = V_33 -> V_41 ;
unsigned long V_57 ;
if ( ! V_35 -> V_186 )
goto V_187;
F_56 ( L_39 , V_35 -> V_185 ) ;
V_35 -> V_188 . V_34 = V_35 -> V_36 . V_37 ;
V_65 = F_61 ( V_143 ) ;
V_70 = F_35 ( V_33 , V_65 , & V_35 -> V_188 ,
sizeof( V_35 -> V_188 ) , NULL , 0 ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_40 ,
V_35 -> V_188 . V_34 ) ;
return - V_189 ;
}
F_78 ( V_35 , & V_35 -> V_188 ) ;
V_187:
F_79 ( & V_35 -> V_89 ) ;
F_20 ( & V_40 -> V_58 , V_57 ) ;
F_17 ( & V_35 -> V_183 ) ;
F_80 ( V_35 ) ;
F_21 ( & V_40 -> V_58 , V_57 ) ;
return V_70 ;
}
int F_81 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_190 V_191 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_41 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_193 . V_194 = V_191 ;
return 0 ;
}
int F_82 ( struct V_32 * V_33 ,
struct V_31 * V_35 , int V_195 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_42 ) ;
return - V_123 ;
}
if ( V_195 != 2 )
return - V_123 ;
V_35 -> V_192 . V_193 . V_196 = V_195 ;
return 0 ;
}
int F_83 ( struct V_32 * V_33 ,
struct V_31 * V_35 , int V_197 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_43 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_193 . V_198 = V_197 ;
return 0 ;
}
int F_84 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_199 ,
enum V_12 V_13 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_44 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_193 . V_199 = V_199 ;
V_35 -> V_192 . V_193 . V_13 = V_13 ;
return 0 ;
}
int F_85 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_200 V_201 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_45 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_193 . V_201 = V_201 ;
return 0 ;
}
int F_86 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_191 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_46 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_193 . V_202 = V_191 ;
return 0 ;
}
int F_87 ( struct V_32 * V_33 , struct V_31 * V_35 ,
enum V_203 V_204 ,
enum V_205 V_206 ,
enum F_87 V_207 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_47 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_204 = V_204 ;
V_35 -> V_192 . V_206 = V_206 ;
V_35 -> V_192 . V_207 = V_207 ;
F_88 ( V_35 , & V_35 -> V_192 ) ;
return 0 ;
}
int F_89 ( struct V_32 * V_33 , struct V_31 * V_35 ,
T_1 V_208 , T_1 V_209 ,
T_1 V_210 , T_1 V_211 , T_1 V_212 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_48 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_213 . V_208 = V_208 ;
V_35 -> V_192 . V_213 . V_209 = V_209 ;
V_35 -> V_192 . V_213 . V_210 = V_210 ;
V_35 -> V_192 . V_213 . V_211 = V_211 ;
V_35 -> V_192 . V_213 . V_212 = V_212 ;
F_90 ( V_35 ) ;
return 0 ;
}
int F_91 ( struct V_32 * V_33 ,
struct V_31 * V_35 , enum V_214 V_215 ,
T_1 V_216 )
{
struct V_217 * V_199 = & V_35 -> V_192 . V_199 ;
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_49 ) ;
return - V_123 ;
}
V_199 -> V_218 = 1 ;
V_199 -> V_219 [ 0 ] . V_215 = V_215 ;
V_199 -> V_219 [ 0 ] . V_216 = V_216 ;
return 0 ;
}
int F_92 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_81 , T_1 V_220 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_50 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_221 . V_81 = V_81 ;
V_35 -> V_192 . V_221 . V_220 = V_220 ;
return 0 ;
}
int F_93 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_81 , T_1 V_220 )
{
if ( V_35 -> V_186 ) {
F_13 ( V_33 -> V_50 , L_51 ) ;
return - V_123 ;
}
V_35 -> V_192 . V_222 . V_81 = V_81 ;
V_35 -> V_192 . V_222 . V_220 = V_220 ;
return 0 ;
}
int F_94 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
struct V_223 * V_224 = & V_35 -> V_192 ;
struct V_225 * V_36 = & V_35 -> V_36 ;
T_1 V_65 ;
int V_70 ;
F_56 ( L_52 , V_35 -> V_185 ) ;
V_65 = F_61 ( V_142 ) ;
V_70 = F_35 ( V_33 , V_65 , V_224 , sizeof( * V_224 ) ,
V_36 , sizeof( * V_36 ) ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_53 ) ;
return V_70 ;
}
V_35 -> V_186 = 1 ;
F_95 ( V_35 ) ;
return 0 ;
}
int F_96 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_37 ;
}
int F_97 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_179 ;
}
T_1 F_98 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_226 ;
}
T_1 F_99 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
return V_35 -> V_36 . V_227 ;
}
T_1 F_100 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_163 )
{
if ( V_163 >= 2 )
return 0 ;
return V_35 -> V_36 . V_228 [ V_163 ] ;
}
T_1 F_101 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_163 )
{
if ( V_163 >= 2 )
return 0 ;
return V_35 -> V_36 . V_167 [ V_163 ] ;
}
int F_102 ( struct V_32 * V_33 )
{
struct V_229 * V_36 ;
T_1 V_65 ;
int V_70 ;
V_36 = & V_33 -> V_178 ;
V_65 = F_61 ( V_149 ) ;
F_56 ( L_54 , 0 ) ;
V_70 = F_35 ( V_33 , V_65 , NULL , 0 , V_36 , sizeof( * V_36 ) ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_55 ) ;
return V_70 ;
}
F_103 ( V_36 ) ;
return 0 ;
}
static int F_104 ( struct V_32 * V_33 , int type ,
int V_34 , int V_67 )
{
T_1 V_65 ;
V_65 = F_61 ( V_153 ) | F_67 ( type ) ;
V_65 |= ( V_34 << V_11 ) ;
if ( V_67 )
return F_35 ( V_33 , V_65 , NULL , 0 , NULL , 0 ) ;
else
return F_36 ( V_33 , V_65 , NULL , 0 ) ;
}
int F_105 ( struct V_32 * V_33 , struct V_31 * V_35 ,
int V_67 )
{
int V_70 ;
F_56 ( L_56 , V_35 -> V_36 . V_37 ) ;
V_70 = F_104 ( V_33 , V_111 ,
V_35 -> V_36 . V_37 , V_67 ) ;
if ( V_70 < 0 )
F_13 ( V_33 -> V_50 , L_57 ,
V_35 -> V_36 . V_37 ) ;
return V_70 ;
}
int F_106 ( struct V_32 * V_33 , struct V_31 * V_35 ,
int V_67 )
{
int V_70 ;
F_56 ( L_58 , V_35 -> V_36 . V_37 ) ;
V_70 = F_104 ( V_33 , V_113 ,
V_35 -> V_36 . V_37 , V_67 ) ;
if ( V_70 < 0 )
F_13 ( V_33 -> V_50 , L_59 ,
V_35 -> V_36 . V_37 ) ;
return V_70 ;
}
int F_107 ( struct V_32 * V_33 , struct V_31 * V_35 )
{
int V_70 , V_230 = 10 ;
if ( ! V_35 -> V_186 )
return 0 ;
while ( V_35 -> V_112 && V_230 -- )
F_108 ( 1 ) ;
if ( ! V_230 ) {
F_13 ( V_33 -> V_50 , L_60 ,
V_35 -> V_36 . V_37 ) ;
return - V_123 ;
}
F_56 ( L_61 , V_35 -> V_36 . V_37 ) ;
V_70 = F_104 ( V_33 , V_110 ,
V_35 -> V_36 . V_37 , 1 ) ;
if ( V_70 < 0 )
F_13 ( V_33 -> V_50 , L_62 ,
V_35 -> V_36 . V_37 ) ;
return V_70 ;
}
T_1 F_109 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
T_1 V_94 ;
F_39 ( V_33 -> V_41 , & V_94 ,
V_35 -> V_36 . V_226 , sizeof( V_94 ) ) ;
return V_94 ;
}
T_4 F_110 ( struct V_32 * V_33 ,
struct V_31 * V_35 )
{
T_4 V_231 ;
F_39 ( V_33 -> V_41 , & V_231 ,
V_35 -> V_36 . V_227 ,
sizeof( V_231 ) ) ;
return V_231 ;
}
int F_111 ( struct V_32 * V_33 ,
struct V_31 * V_35 , T_1 V_162 , T_1 V_232 )
{
T_1 V_65 ;
int V_70 ;
F_112 ( V_35 -> V_36 . V_37 , V_232 ) ;
V_65 = F_61 ( V_153 ) |
F_67 ( V_108 ) ;
V_65 |= ( V_35 -> V_36 . V_37 << V_11 ) ;
V_65 |= ( V_233 << V_9 ) ;
V_65 |= ( V_162 << V_176 ) ;
V_35 -> V_234 . V_232 = V_232 ;
V_70 = F_36 ( V_33 , V_65 , & V_35 -> V_234 ,
sizeof( V_35 -> V_234 ) ) ;
if ( V_70 < 0 )
F_13 ( V_33 -> V_50 , L_63 ,
V_35 -> V_36 . V_37 , V_232 ) ;
return V_70 ;
}
int F_113 ( struct V_32 * V_33 ,
enum V_235 V_50 , enum V_236 V_237 ,
enum V_238 V_239 , T_1 V_240 )
{
struct V_241 V_13 ;
T_1 V_65 ;
int V_70 ;
F_56 ( L_64 , V_50 ) ;
V_13 . V_242 = V_50 ;
V_13 . V_243 = V_237 ;
V_13 . V_239 = V_239 ;
V_13 . V_240 = V_240 ;
F_114 ( & V_13 ) ;
V_65 = F_61 ( V_147 ) ;
V_70 = F_35 ( V_33 , V_65 , & V_13 , sizeof( V_13 ) ,
NULL , 0 ) ;
if ( V_70 < 0 )
F_13 ( V_33 -> V_50 , L_65 ) ;
return V_70 ;
}
int F_115 ( struct V_32 * V_33 ,
enum V_244 V_245 , struct V_246 * V_247 )
{
T_1 V_65 , V_248 ;
int V_70 ;
V_65 = F_61 ( V_148 ) ;
V_248 = V_245 ;
F_56 ( L_66 , V_245 ) ;
V_70 = F_35 ( V_33 , V_65 , & V_248 , sizeof( V_248 ) ,
V_247 , sizeof( * V_247 ) ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_67 , V_245 ) ;
return V_70 ;
}
F_38 ( V_33 -> V_50 , L_68 ,
V_247 -> V_249 , V_245 ) ;
memcpy ( & V_33 -> V_247 , V_247 , sizeof( * V_247 ) ) ;
return 0 ;
}
int F_116 ( struct V_32 * V_33 , T_1 V_250 ,
T_1 * V_81 , T_1 * V_220 , T_1 * V_251 )
{
struct V_252 * V_253 ;
struct V_246 * V_254 ;
int V_255 ;
V_254 = & V_33 -> V_247 ;
V_255 = V_254 -> V_249 ;
F_56 ( L_69 , V_255 ) ;
if ( V_250 >= V_255 )
return - V_123 ;
V_253 = & V_254 -> V_256 [ V_250 ] ;
* V_81 = V_253 -> V_81 ;
* V_220 = V_253 -> V_220 ;
* V_251 = V_253 -> V_251 ;
return 0 ;
}
static int F_117 ( struct V_32 * V_33 )
{
int V_257 ;
V_33 -> V_1 = F_74 ( sizeof( struct V_51 ) *
V_258 , V_182 ) ;
if ( V_33 -> V_1 == NULL )
return - V_120 ;
for ( V_257 = 0 ; V_257 < V_258 ; V_257 ++ ) {
F_118 ( & V_33 -> V_1 [ V_257 ] . V_68 ) ;
F_75 ( & V_33 -> V_1 [ V_257 ] . V_53 , & V_33 -> V_52 ) ;
}
return 0 ;
}
void F_119 ( struct V_32 * V_33 ,
struct V_259 * V_260 )
{
V_33 -> V_260 = V_260 ;
}
struct V_39 * F_120 ( struct V_32 * V_33 )
{
return V_33 -> V_41 ;
}
int F_121 ( struct V_261 * V_50 , struct V_262 * V_102 )
{
struct V_160 V_161 ;
struct V_32 * V_33 ;
struct V_263 * V_264 ;
int V_70 ;
F_38 ( V_50 , L_70 ) ;
V_33 = F_122 ( V_50 , sizeof( * V_33 ) , V_182 ) ;
if ( V_33 == NULL )
return - V_120 ;
V_33 -> V_50 = V_50 ;
F_123 ( & V_33 -> V_184 ) ;
F_123 ( & V_33 -> V_59 ) ;
F_123 ( & V_33 -> V_62 ) ;
F_123 ( & V_33 -> V_52 ) ;
F_118 ( & V_33 -> V_87 ) ;
F_118 ( & V_33 -> V_265 ) ;
V_70 = F_117 ( V_33 ) ;
if ( V_70 < 0 )
return - V_120 ;
F_124 ( & V_33 -> V_78 ) ;
V_33 -> V_266 = F_125 ( V_267 ,
& V_33 -> V_78 , L_71 ,
F_126 ( V_33 -> V_50 ) ) ;
if ( F_127 ( V_33 -> V_266 ) ) {
V_70 = F_128 ( V_33 -> V_266 ) ;
F_13 ( V_33 -> V_50 , L_72 ) ;
goto V_268;
}
F_129 ( & V_33 -> V_56 , F_18 ) ;
V_269 . V_270 = V_33 ;
V_33 -> V_41 = F_130 ( V_50 , & V_269 , V_102 ) ;
if ( V_33 -> V_41 == NULL ) {
V_70 = - V_271 ;
goto V_272;
}
F_131 ( V_33 -> V_41 ) ;
V_264 = F_132 ( V_33 -> V_41 , V_102 -> V_273 , V_33 ) ;
if ( V_264 == NULL ) {
V_70 = - V_271 ;
F_13 ( V_50 , L_73 ) ;
goto V_274;
}
F_133 ( V_33 -> V_41 ) ;
V_70 = F_30 ( V_33 -> V_87 , V_33 -> V_86 ,
F_31 ( V_275 ) ) ;
if ( V_70 == 0 ) {
V_70 = - V_114 ;
F_13 ( V_33 -> V_50 , L_74 ) ;
goto V_276;
}
F_60 ( V_33 , & V_161 ) ;
F_134 ( V_33 -> V_50 , L_75 ,
V_161 . type , V_161 . V_277 , V_161 . V_278 , V_161 . V_279 ) ;
V_70 = F_102 ( V_33 ) ;
if ( V_70 < 0 ) {
F_13 ( V_33 -> V_50 , L_76 ) ;
goto V_276;
}
V_102 -> V_41 = V_33 ;
return 0 ;
V_276:
F_131 ( V_33 -> V_41 ) ;
F_135 ( V_264 ) ;
V_274:
F_136 ( V_33 -> V_41 ) ;
V_272:
F_137 ( V_33 -> V_266 ) ;
V_268:
F_80 ( V_33 -> V_1 ) ;
return V_70 ;
}
void F_138 ( struct V_261 * V_50 , struct V_262 * V_102 )
{
struct V_32 * V_33 = V_102 -> V_41 ;
F_131 ( V_33 -> V_41 ) ;
F_139 ( V_33 -> V_41 ) ;
F_136 ( V_33 -> V_41 ) ;
F_80 ( V_33 -> V_260 ) ;
F_137 ( V_33 -> V_266 ) ;
F_80 ( V_33 -> V_1 ) ;
}
