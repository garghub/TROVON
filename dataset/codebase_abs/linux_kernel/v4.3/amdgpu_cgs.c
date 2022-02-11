static int F_1 ( void * V_1 , enum V_2 type ,
T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 )
{
V_6 ;
switch( type ) {
case V_7 :
case V_8 :
* V_3 = 0 ;
* V_4 = V_9 -> V_10 . V_11 ;
* V_5 = V_9 -> V_10 . V_11 - V_9 -> V_12 ;
break;
case V_13 :
case V_14 :
* V_3 = V_9 -> V_10 . V_11 ;
* V_4 = V_9 -> V_10 . V_15 - V_9 -> V_10 . V_11 ;
* V_5 = * V_4 ;
break;
case V_16 :
case V_17 :
* V_3 = V_9 -> V_10 . V_18 ;
* V_4 = V_9 -> V_10 . V_19 ;
* V_5 = V_9 -> V_10 . V_19 - V_9 -> V_20 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_2 ( void * V_1 , void * V_22 ,
T_1 V_23 ,
T_1 V_24 , T_1 V_25 ,
T_2 * V_26 , T_1 * V_27 )
{
V_6 ;
int V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = F_3 ( V_22 ) ;
int V_33 = F_4 ( V_23 , V_34 ) >> V_35 ;
struct V_36 * V_37 = F_5 ( & V_32 , V_33 ) ;
V_28 = F_6 ( V_9 , V_23 , V_34 , false ,
V_38 , 0 , V_37 , NULL , & V_30 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_30 , false ) ;
if ( F_8 ( V_28 != 0 ) )
return V_28 ;
V_28 = F_9 ( V_30 , V_38 ,
V_24 , V_25 , V_27 ) ;
F_10 ( V_30 ) ;
* V_26 = ( T_2 ) V_30 ;
return V_28 ;
}
static int F_11 ( void * V_1 , T_2 V_26 )
{
struct V_29 * V_39 = (struct V_29 * ) V_26 ;
if ( V_39 ) {
int V_40 = F_7 ( V_39 , false ) ;
if ( F_12 ( V_40 == 0 ) ) {
F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
}
F_14 ( & V_39 ) ;
}
return 0 ;
}
static int F_15 ( void * V_1 ,
enum V_2 type ,
T_1 V_23 , T_1 V_41 ,
T_1 V_24 , T_1 V_25 ,
T_2 * V_42 )
{
V_6 ;
T_3 V_43 = 0 ;
int V_28 = 0 ;
T_4 V_44 = 0 ;
struct V_29 * V_39 ;
struct V_45 V_46 ;
struct V_47 V_48 ;
if ( V_24 > V_25 ) {
F_16 ( 1 ) ;
return - V_21 ;
}
if ( ( ( V_41 != 1 ) && ( V_41 & ( V_41 - 1 ) ) )
|| V_23 == 0 || V_41 == 0 )
return - V_21 ;
switch( type ) {
case V_7 :
case V_8 :
V_43 = V_49 ;
V_44 = V_50 ;
if ( V_25 > V_9 -> V_10 . V_15 )
return - V_21 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_53 | V_54 |
V_55 ;
break;
case V_13 :
case V_14 :
V_43 = V_56 ;
V_44 = V_50 ;
if ( V_9 -> V_10 . V_11 < V_9 -> V_10 . V_15 ) {
V_48 . V_51 =
F_17 ( V_24 , V_9 -> V_10 . V_11 ) >> V_35 ;
V_48 . V_52 =
F_18 ( V_25 , V_9 -> V_10 . V_15 ) >> V_35 ;
V_48 . V_43 = V_53 | V_54 |
V_55 ;
}
break;
case V_16 :
V_44 = V_38 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_57 | V_58 ;
break;
case V_17 :
V_43 = V_59 ;
V_44 = V_38 ;
V_48 . V_51 = V_24 >> V_35 ;
V_48 . V_52 = V_25 >> V_35 ;
V_48 . V_43 = V_53 | V_58 |
V_54 ;
break;
default:
return - V_21 ;
}
* V_42 = 0 ;
V_46 . V_46 = & V_48 ;
V_46 . V_60 = 1 ;
V_46 . V_61 = & V_48 ;
V_46 . V_62 = 1 ;
V_28 = F_19 ( V_9 , V_23 , V_34 ,
true , V_44 , V_43 ,
NULL , & V_46 , NULL ,
& V_39 ) ;
if ( V_28 ) {
F_20 ( L_1 , V_28 ) ;
return V_28 ;
}
* V_42 = ( T_2 ) V_39 ;
return V_28 ;
}
static int F_21 ( void * V_1 , T_2 V_42 )
{
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
if ( V_39 ) {
int V_40 = F_7 ( V_39 , false ) ;
if ( F_12 ( V_40 == 0 ) ) {
F_22 ( V_39 ) ;
F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
}
F_14 ( & V_39 ) ;
}
return 0 ;
}
static int F_23 ( void * V_1 , T_2 V_42 ,
T_1 * V_27 )
{
int V_40 ;
T_5 V_24 , V_25 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
F_24 ( V_39 -> V_46 . V_60 > 1 ) ;
V_24 = V_39 -> V_63 [ 0 ] . V_51 << V_35 ;
V_25 = V_39 -> V_63 [ 0 ] . V_52 << V_35 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_9 ( V_39 , V_38 ,
V_24 , V_25 , V_27 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_25 ( void * V_1 , T_2 V_42 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_13 ( V_39 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_26 ( void * V_1 , T_2 V_42 ,
void * * V_64 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
V_40 = F_27 ( V_39 , V_64 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static int F_28 ( void * V_1 , T_2 V_42 )
{
int V_40 ;
struct V_29 * V_39 = (struct V_29 * ) V_42 ;
V_40 = F_7 ( V_39 , false ) ;
if ( F_8 ( V_40 != 0 ) )
return V_40 ;
F_22 ( V_39 ) ;
F_10 ( V_39 ) ;
return V_40 ;
}
static T_4 F_29 ( void * V_1 , unsigned V_65 )
{
V_6 ;
return F_30 ( V_65 ) ;
}
static void F_31 ( void * V_1 , unsigned V_65 ,
T_4 V_66 )
{
V_6 ;
F_32 ( V_65 , V_66 ) ;
}
static T_4 F_33 ( void * V_1 ,
enum V_67 V_68 ,
unsigned V_69 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_34 ( V_69 ) ;
case V_71 :
return F_35 ( V_69 ) ;
case V_72 :
return F_36 ( V_69 ) ;
case V_73 :
return F_37 ( V_69 ) ;
case V_74 :
return F_38 ( V_69 ) ;
case V_75 :
F_20 ( L_2 ) ;
return 0 ;
}
F_39 ( 1 , L_3 ) ;
return 0 ;
}
static void F_40 ( void * V_1 ,
enum V_67 V_68 ,
unsigned V_69 , T_4 V_66 )
{
V_6 ;
switch ( V_68 ) {
case V_70 :
return F_41 ( V_69 , V_66 ) ;
case V_71 :
return F_42 ( V_69 , V_66 ) ;
case V_72 :
return F_43 ( V_69 , V_66 ) ;
case V_73 :
return F_44 ( V_69 , V_66 ) ;
case V_74 :
return F_45 ( V_69 , V_66 ) ;
case V_75 :
F_20 ( L_2 ) ;
return;
}
F_39 ( 1 , L_3 ) ;
}
static T_6 F_46 ( void * V_1 , unsigned V_76 )
{
V_6 ;
T_6 V_77 ;
int V_28 = F_47 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_4 ) )
return 0 ;
return V_77 ;
}
static T_3 F_48 ( void * V_1 , unsigned V_76 )
{
V_6 ;
T_3 V_77 ;
int V_28 = F_49 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_5 ) )
return 0 ;
return V_77 ;
}
static T_4 F_50 ( void * V_1 ,
unsigned V_76 )
{
V_6 ;
T_4 V_77 ;
int V_28 = F_51 ( V_9 -> V_78 , V_76 , & V_77 ) ;
if ( F_39 ( V_28 , L_6 ) )
return 0 ;
return V_77 ;
}
static void F_52 ( void * V_1 , unsigned V_76 ,
T_6 V_66 )
{
V_6 ;
int V_28 = F_53 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_7 ) ;
}
static void F_54 ( void * V_1 , unsigned V_76 ,
T_3 V_66 )
{
V_6 ;
int V_28 = F_55 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_8 ) ;
}
static void F_56 ( void * V_1 , unsigned V_76 ,
T_4 V_66 )
{
V_6 ;
int V_28 = F_57 ( V_9 -> V_78 , V_76 , V_66 ) ;
F_39 ( V_28 , L_9 ) ;
}
static const void * F_58 ( void * V_1 ,
unsigned V_79 , T_3 * V_23 ,
T_6 * V_80 , T_6 * V_81 )
{
V_6 ;
T_3 V_82 ;
if ( F_59 (
V_9 -> V_83 . V_84 , V_79 , V_23 ,
V_80 , V_81 , & V_82 ) )
return ( T_6 * ) V_9 -> V_83 . V_84 -> V_85 +
V_82 ;
return NULL ;
}
static int F_60 ( void * V_1 , unsigned V_79 ,
T_6 * V_80 , T_6 * V_81 )
{
V_6 ;
if ( F_61 (
V_9 -> V_83 . V_84 , V_79 ,
V_80 , V_81 ) )
return 0 ;
return - V_21 ;
}
static int F_62 ( void * V_1 , unsigned V_79 ,
void * args )
{
V_6 ;
return F_63 (
V_9 -> V_83 . V_84 , V_79 , args ) ;
}
static int F_64 ( void * V_1 , T_2 * V_86 )
{
return 0 ;
}
static int F_65 ( void * V_1 , T_2 V_86 )
{
return 0 ;
}
static int F_66 ( void * V_1 , T_2 V_86 ,
int V_87 )
{
return 0 ;
}
static int F_67 ( void * V_1 , T_2 V_86 ,
enum V_88 clock , unsigned V_89 )
{
return 0 ;
}
static int F_68 ( void * V_1 , T_2 V_86 ,
enum V_90 V_91 , int V_92 )
{
return 0 ;
}
static int F_69 ( void * V_1 ,
enum V_88 clock ,
struct V_93 * V_94 )
{
return 0 ;
}
static int F_70 ( void * V_1 , T_4 V_95 ,
const T_4 * V_96 )
{
F_20 ( L_10 ) ;
return - V_97 ;
}
static int F_71 ( struct V_98 * V_9 ,
struct V_99 * V_100 ,
unsigned type ,
enum V_101 V_102 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_100 -> V_105 ;
if ( ! V_104 )
return - V_21 ;
if ( ! V_104 -> V_106 )
return - V_21 ;
return V_104 -> V_106 ( V_104 -> V_107 ,
V_104 -> V_108 ,
type ,
( int ) V_102 ) ;
}
static int F_72 ( struct V_98 * V_9 ,
struct V_99 * V_109 ,
struct V_110 * V_111 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_109 -> V_105 ;
if ( ! V_104 )
return - V_21 ;
if ( ! V_104 -> V_112 )
return - V_21 ;
return V_104 -> V_112 ( V_104 -> V_107 ,
V_104 -> V_108 ,
V_111 -> V_113 ) ;
}
static int F_73 ( void * V_1 , unsigned V_108 ,
unsigned V_114 ,
T_7 V_106 ,
T_8 V_112 ,
void * V_107 )
{
V_6 ;
int V_28 = 0 ;
struct V_103 * V_104 ;
struct V_99 * V_109 =
F_74 ( sizeof( struct V_99 ) , V_115 ) ;
if ( ! V_109 )
return - V_116 ;
V_104 =
F_74 ( sizeof( struct V_103 ) , V_115 ) ;
if ( ! V_104 ) {
F_75 ( V_109 ) ;
return - V_116 ;
}
V_109 -> V_114 = V_114 ;
V_109 -> V_117 = & V_118 ;
V_104 -> V_108 = V_108 ;
V_104 -> V_106 = V_106 ;
V_104 -> V_112 = V_112 ;
V_104 -> V_107 = V_107 ;
V_109 -> V_105 = ( void * ) V_104 ;
V_28 = F_76 ( V_9 , V_108 , V_109 ) ;
if ( V_28 ) {
F_75 ( V_104 ) ;
F_75 ( V_109 ) ;
}
return V_28 ;
}
static int F_77 ( void * V_1 , unsigned V_108 , unsigned type )
{
V_6 ;
return F_78 ( V_9 , V_9 -> V_119 . V_120 [ V_108 ] , type ) ;
}
static int F_79 ( void * V_1 , unsigned V_108 , unsigned type )
{
V_6 ;
return F_80 ( V_9 , V_9 -> V_119 . V_120 [ V_108 ] , type ) ;
}
int F_81 ( void * V_1 ,
enum V_121 V_122 ,
enum V_123 V_102 )
{
V_6 ;
int V_124 , V_40 = - 1 ;
for ( V_124 = 0 ; V_124 < V_9 -> V_125 ; V_124 ++ ) {
if ( ! V_9 -> V_126 [ V_124 ] . V_127 )
continue;
if ( V_9 -> V_128 [ V_124 ] . type == V_122 ) {
V_40 = V_9 -> V_128 [ V_124 ] . V_117 -> V_129 (
( void * ) V_9 ,
V_102 ) ;
break;
}
}
return V_40 ;
}
int F_82 ( void * V_1 ,
enum V_121 V_122 ,
enum V_130 V_102 )
{
V_6 ;
int V_124 , V_40 = - 1 ;
for ( V_124 = 0 ; V_124 < V_9 -> V_125 ; V_124 ++ ) {
if ( ! V_9 -> V_126 [ V_124 ] . V_127 )
continue;
if ( V_9 -> V_128 [ V_124 ] . type == V_122 ) {
V_40 = V_9 -> V_128 [ V_124 ] . V_117 -> V_131 (
( void * ) V_9 ,
V_102 ) ;
break;
}
}
return V_40 ;
}
static T_4 F_83 ( void * V_1 , T_4 V_132 )
{
V_6 ;
enum V_133 V_134 = V_135 ;
switch ( V_132 ) {
case V_136 :
V_134 = V_137 ;
break;
case V_138 :
V_134 = V_139 ;
break;
case V_140 :
V_134 = V_141 ;
break;
case V_142 :
V_134 = V_143 ;
break;
case V_144 :
V_134 = V_145 ;
break;
case V_146 :
case V_147 :
V_134 = V_148 ;
break;
case V_149 :
if ( V_9 -> V_150 == V_151 )
V_134 = V_152 ;
else if ( V_9 -> V_150 == V_153 )
V_134 = V_148 ;
break;
case V_154 :
V_134 = V_155 ;
break;
default:
F_20 ( L_11 ) ;
}
return V_134 ;
}
static int F_84 ( void * V_1 ,
enum V_156 type ,
struct V_157 * V_158 )
{
V_6 ;
if ( V_159 != type ) {
T_1 V_160 ;
T_4 V_161 ;
const struct V_162 * V_163 ;
enum V_133 V_164 ;
struct V_165 * V_166 ;
V_164 = F_83 ( V_1 , type ) ;
V_166 = & V_9 -> V_167 . V_166 [ V_164 ] ;
if ( V_166 -> V_168 == NULL )
return - V_21 ;
V_160 = V_166 -> V_169 ;
V_163 = ( const struct V_162 * ) V_166 -> V_168 -> V_105 ;
V_161 = F_85 ( V_163 -> V_163 . V_170 ) ;
if ( ( type == V_147 ) ||
( type == V_149 ) ) {
V_160 += F_85 ( V_163 -> V_171 ) << 2 ;
V_161 = F_85 ( V_163 -> V_172 ) << 2 ;
}
V_158 -> V_169 = V_160 ;
V_158 -> V_173 = V_161 ;
V_158 -> V_174 = ( T_3 ) F_85 ( V_163 -> V_163 . V_175 ) ;
V_158 -> V_176 = ( T_3 ) F_85 ( V_163 -> V_177 ) ;
} else {
char V_178 [ 30 ] = { 0 } ;
int V_179 = 0 ;
T_4 V_180 ;
T_4 V_181 ;
const T_6 * V_100 ;
const struct V_182 * V_183 ;
switch ( V_9 -> V_150 ) {
case V_151 :
strcpy ( V_178 , L_12 ) ;
break;
default:
F_20 ( L_13 ) ;
return - V_21 ;
}
V_179 = F_86 ( & V_9 -> V_184 . V_168 , V_178 , V_9 -> V_185 ) ;
if ( V_179 ) {
F_20 ( L_14 ) ;
return V_179 ;
}
V_179 = F_87 ( V_9 -> V_184 . V_168 ) ;
if ( V_179 ) {
F_20 ( L_15 , V_178 ) ;
F_88 ( V_9 -> V_184 . V_168 ) ;
V_9 -> V_184 . V_168 = NULL ;
return V_179 ;
}
V_183 = ( const struct V_182 * ) V_9 -> V_184 . V_168 -> V_105 ;
V_9 -> V_184 . V_186 = F_85 ( V_183 -> V_163 . V_175 ) ;
V_180 = F_85 ( V_183 -> V_163 . V_170 ) ;
V_181 = F_85 ( V_183 -> V_187 ) ;
V_100 = ( const T_6 * ) ( V_9 -> V_184 . V_168 -> V_105 +
F_85 ( V_183 -> V_163 . V_188 ) ) ;
V_158 -> V_174 = V_9 -> V_184 . V_186 ;
V_158 -> V_173 = V_180 ;
V_158 -> V_189 = ( void * ) V_100 ;
}
return 0 ;
}
void * F_89 ( struct V_98 * V_9 )
{
struct V_190 * V_1 =
F_90 ( sizeof( * V_1 ) , V_115 ) ;
if ( ! V_1 ) {
F_20 ( L_16 ) ;
return NULL ;
}
V_1 -> V_191 . V_192 = & V_193 ;
V_1 -> V_191 . V_194 = & V_195 ;
V_1 -> V_9 = V_9 ;
return V_1 ;
}
void F_91 ( void * V_1 )
{
F_75 ( V_1 ) ;
}
