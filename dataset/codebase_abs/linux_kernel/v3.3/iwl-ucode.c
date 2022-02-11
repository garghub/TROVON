static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 )
F_2 ( V_2 -> V_6 , V_4 -> V_7 ,
V_4 -> V_5 , V_4 -> V_8 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_7 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_1 ( V_2 , & V_10 -> V_11 ) ;
F_1 ( V_2 , & V_10 -> V_12 ) ;
}
void F_4 ( struct V_13 * V_14 )
{
F_3 ( V_2 ( V_14 ) , & V_14 -> V_15 ) ;
F_3 ( V_2 ( V_14 ) , & V_14 -> V_16 ) ;
F_3 ( V_2 ( V_14 ) , & V_14 -> V_17 ) ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const void * V_12 , T_1 V_7 )
{
if ( ! V_7 ) {
V_4 -> V_5 = NULL ;
return - V_18 ;
}
V_4 -> V_5 = F_6 ( V_2 -> V_6 , V_7 ,
& V_4 -> V_8 , V_19 ) ;
if ( ! V_4 -> V_5 )
return - V_20 ;
V_4 -> V_7 = V_7 ;
memcpy ( V_4 -> V_5 , V_12 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 , const char * V_21 ,
struct V_3 * V_22 , T_2 V_23 )
{
struct V_1 * V_2 = V_2 ( V_14 ) ;
T_3 V_24 = V_22 -> V_8 ;
T_2 V_25 = V_22 -> V_7 ;
int V_26 ;
V_14 -> V_27 = 0 ;
F_8 ( V_2 ,
F_9 ( V_28 ) ,
V_29 ) ;
F_8 ( V_2 ,
F_10 ( V_28 ) , V_23 ) ;
F_8 ( V_2 ,
F_11 ( V_28 ) ,
V_24 & V_30 ) ;
F_8 ( V_2 ,
F_12 ( V_28 ) ,
( F_13 ( V_24 )
<< V_31 ) | V_25 ) ;
F_8 ( V_2 ,
F_14 ( V_28 ) ,
1 << V_32 |
1 << V_33 |
V_34 ) ;
F_8 ( V_2 ,
F_9 ( V_28 ) ,
V_35 |
V_36 |
V_37 ) ;
F_15 ( V_2 , L_1 , V_21 ) ;
V_26 = F_16 ( V_14 -> V_38 -> V_39 ,
V_14 -> V_27 , 5 * V_40 ) ;
if ( ! V_26 ) {
F_17 ( V_14 , L_2 ,
V_21 ) ;
return - V_41 ;
}
return 0 ;
}
static inline struct V_9 * F_18 ( struct V_13 * V_14 ,
enum V_42 V_43 )
{
switch ( V_43 ) {
case V_44 :
return & V_14 -> V_16 ;
case V_45 :
return & V_14 -> V_17 ;
case V_46 :
return & V_14 -> V_15 ;
case V_47 :
break;
}
return NULL ;
}
static int F_19 ( struct V_13 * V_14 ,
enum V_42 V_43 )
{
int V_26 = 0 ;
struct V_9 * V_22 = F_18 ( V_14 , V_43 ) ;
if ( ! V_22 ) {
F_17 ( V_14 , L_3 ,
V_43 ) ;
return - V_18 ;
}
V_26 = F_7 ( V_14 , L_4 , & V_22 -> V_11 ,
V_48 ) ;
if ( V_26 )
return V_26 ;
return F_7 ( V_14 , L_5 , & V_22 -> V_12 ,
V_49 ) ;
}
static int F_20 ( struct V_13 * V_14 )
{
struct V_50 V_51 ;
T_4 * V_52 =
( T_4 * ) F_21 ( V_14 -> V_38 , V_53 ) ;
F_22 ( & V_51 . V_54 , V_55 ) ;
V_51 . V_56 = F_23 ( V_52 [ 0 ] ) ;
V_51 . V_57 = F_23 ( V_52 [ 1 ] ) ;
return F_24 ( V_14 , ( void * ) & V_51 , sizeof( V_51 ) ) ;
}
static int F_25 ( struct V_13 * V_14 )
{
struct V_58 V_51 ;
T_4 * V_59 =
( T_4 * ) F_21 ( V_14 -> V_38 ,
V_60 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
F_22 ( & V_51 . V_54 , V_61 ) ;
memcpy ( & V_51 . V_62 , V_59 , sizeof( * V_59 ) ) ;
if ( ! ( V_51 . V_62 ) )
V_51 . V_62 = V_63 ;
F_26 ( V_14 , L_6 ,
F_23 ( V_51 . V_62 ) ) ;
return F_24 ( V_14 , ( void * ) & V_51 , sizeof( V_51 ) ) ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_64 V_51 ;
T_4 * V_65 = ( T_4 * ) F_21 ( V_14 -> V_38 ,
V_66 ) ;
T_4 * V_67 =
( T_4 * ) F_21 ( V_14 -> V_38 ,
V_60 ) ;
struct V_68 * V_54 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
F_22 ( & V_51 . V_54 , V_61 ) ;
V_54 = (struct V_68 * ) F_21 ( V_14 -> V_38 ,
V_69 ) ;
memcpy ( & V_51 . V_70 , V_65 ,
sizeof( * V_65 ) ) ;
memcpy ( & V_51 . V_71 , V_67 ,
sizeof( * V_67 ) ) ;
if ( ! ( V_51 . V_71 ) ) {
F_26 ( V_14 , L_7 ) ;
V_51 . V_71 = V_63 ;
V_51 . V_70 = V_63 ;
}
memcpy ( & V_51 . V_72 , & V_54 -> V_73 ,
sizeof( V_54 -> V_73 ) ) ;
F_26 ( V_14 , L_8 ,
F_23 ( V_51 . V_70 ) ) ;
F_26 ( V_14 , L_9 ,
F_23 ( V_51 . V_71 ) ) ;
F_26 ( V_14 , L_10 ,
F_23 ( V_51 . V_72 ) ) ;
return F_24 ( V_14 , ( void * ) & V_51 , sizeof( V_51 ) ) ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_74 V_75 ;
struct V_76 V_51 = {
. V_77 = V_78 ,
. V_7 = { sizeof( struct V_74 ) , } ,
. V_12 = { & V_75 , } ,
} ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_79 . V_80 . V_81 = V_82 ;
V_75 . V_79 . V_80 . V_83 = V_82 ;
V_75 . V_79 . V_80 . V_84 = V_82 ;
V_75 . V_79 . V_85 =
V_86 ;
return F_29 ( V_14 , & V_51 ) ;
}
int F_30 ( struct V_87 * V_88 ,
struct V_89 * V_90 ,
struct V_91 * V_51 )
{
struct V_92 * V_93 = F_31 ( V_90 ) ;
struct V_94 * V_54 = (struct V_94 * ) V_93 -> V_95 . V_96 ;
int V_7 = F_32 ( V_93 -> V_97 ) & V_98 ;
V_7 -= 4 ;
if ( F_24 ( V_14 ( V_88 ) , V_54 , V_7 ) )
F_17 ( V_88 , L_11 ,
V_54 -> V_99 ) ;
return 0 ;
}
int F_33 ( struct V_13 * V_14 )
{
int V_26 ;
if ( F_34 ( V_14 ) -> V_100 &&
F_34 ( V_14 ) -> V_100 -> V_101 ) {
V_26 = F_35 ( V_14 , V_102 ,
V_103 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_28 ( V_14 ) ;
if ( V_26 )
return V_26 ;
if ( F_34 ( V_14 ) -> V_104 ) {
if ( F_34 ( V_14 ) -> V_105 )
return F_27 ( V_14 ) ;
else
return F_25 ( V_14 ) ;
}
return 0 ;
}
static int F_36 ( struct V_13 * V_14 )
{
struct V_106 V_107 ;
if ( F_34 ( V_14 ) -> V_108 -> V_109 ) {
V_107 . V_85 = V_110 ;
V_107 . V_85 |= V_111 ;
memcpy ( V_107 . V_112 , V_113 ,
sizeof( struct V_114 ) *
V_115 ) ;
V_107 . V_85 |= V_116 ;
V_107 . V_85 |= V_117 ;
} else {
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
}
return F_37 ( V_14 ,
V_118 , V_119 ,
sizeof( V_107 ) , & V_107 ) ;
}
void F_38 ( struct V_13 * V_14 )
{
struct V_120 V_121 ;
memcpy ( V_121 . V_122 , V_123 ,
sizeof( V_123 ) ) ;
if ( F_37 ( V_14 ,
V_124 , V_119 ,
sizeof( V_121 ) , & V_121 ) )
F_17 ( V_14 , L_12 ) ;
}
int F_35 ( struct V_13 * V_14 , T_5 V_125 , T_5 type )
{
struct V_126 V_127 ;
int V_26 ;
V_127 . V_125 = V_125 ;
V_127 . type = type ;
V_26 = F_37 ( V_14 ,
V_128 , V_119 ,
sizeof( V_127 ) , & V_127 ) ;
if ( V_26 )
F_17 ( V_14 , L_13 ) ;
return V_26 ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_87 * V_88 = V_88 ( V_14 ) ;
struct V_129 * V_130 ;
int V_26 ;
if ( ! V_88 -> V_131 )
V_88 -> V_131 =
F_40 ( L_14 ,
sizeof( struct V_91 ) ,
sizeof( void * ) , 0 , NULL ) ;
if ( ! V_88 -> V_131 )
return - V_20 ;
F_41 ( V_14 ) ;
F_42 (priv, ctx)
V_130 -> V_132 = false ;
V_26 = F_36 ( V_14 ) ;
if ( V_26 )
return V_26 ;
if ( ! F_34 ( V_88 ) -> V_133 ) {
V_26 = F_20 ( V_14 ) ;
if ( V_26 )
return V_26 ;
}
return F_43 ( V_14 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
T_6 * V_22 = ( T_6 * ) V_3 -> V_5 ;
T_2 V_7 = V_3 -> V_7 ;
T_2 V_134 ;
T_2 V_135 ;
F_15 ( V_2 , L_15 , V_7 ) ;
for ( V_135 = 0 ; V_135 < V_7 ; V_135 += 100 , V_22 += 100 / sizeof( T_2 ) ) {
F_8 ( V_2 , V_136 ,
V_135 + V_48 ) ;
V_134 = F_45 ( V_2 , V_137 ) ;
if ( V_134 != F_32 ( * V_22 ) )
return - V_138 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
T_6 * V_22 = ( T_6 * ) V_3 -> V_5 ;
T_2 V_7 = V_3 -> V_7 ;
T_2 V_134 ;
T_2 V_139 ;
int V_140 = 0 ;
F_15 ( V_2 , L_15 , V_7 ) ;
F_8 ( V_2 , V_136 ,
V_48 ) ;
for ( V_139 = 0 ;
V_139 < V_7 && V_140 < 20 ;
V_139 += sizeof( T_2 ) , V_22 ++ ) {
V_134 = F_45 ( V_2 , V_137 ) ;
if ( V_134 != F_32 ( * V_22 ) ) {
F_17 ( V_2 , L_16
L_17 ,
V_139 , V_134 , F_32 ( * V_22 ) ) ;
V_140 ++ ;
}
}
}
static int F_47 ( struct V_13 * V_14 ,
enum V_42 V_43 )
{
struct V_9 * V_10 = F_18 ( V_14 , V_43 ) ;
if ( ! V_10 ) {
F_17 ( V_14 , L_3 , V_43 ) ;
return - V_18 ;
}
if ( ! F_44 ( V_2 ( V_14 ) , & V_10 -> V_11 ) ) {
F_15 ( V_14 , L_18 ) ;
return 0 ;
}
F_17 ( V_14 , L_19 ) ;
F_46 ( V_2 ( V_14 ) , & V_10 -> V_11 ) ;
return - V_138 ;
}
static void F_48 ( struct V_13 * V_14 ,
struct V_92 * V_93 ,
void * V_12 )
{
struct V_141 * V_142 = V_12 ;
struct V_143 * V_144 ;
V_144 = & V_93 -> V_95 . V_145 ;
F_15 ( V_14 , L_20
L_21 ,
V_144 -> V_146 , V_144 -> V_147 ,
V_144 -> V_148 ) ;
V_14 -> V_38 -> V_149 . V_150 =
F_32 ( V_144 -> V_151 ) ;
V_14 -> V_38 -> V_149 . V_152 =
F_32 ( V_144 -> V_153 ) ;
V_142 -> V_154 = V_144 -> V_148 ;
V_142 -> V_155 = V_144 -> V_146 == V_156 ;
}
void F_49 ( struct V_157 * V_38 ,
struct V_158 * V_159 ,
T_5 V_51 ,
void (* F_50)( struct V_13 * V_14 ,
struct V_92 * V_93 ,
void * V_12 ) ,
void * V_160 )
{
V_159 -> F_50 = F_50 ;
V_159 -> V_160 = V_160 ;
V_159 -> V_51 = V_51 ;
V_159 -> V_161 = false ;
V_159 -> V_162 = false ;
F_51 ( & V_38 -> V_163 ) ;
F_52 ( & V_159 -> V_164 , & V_38 -> V_165 ) ;
F_53 ( & V_38 -> V_163 ) ;
}
int F_54 ( struct V_157 * V_38 ,
struct V_158 * V_159 ,
unsigned long V_166 )
{
int V_26 ;
V_26 = F_16 ( V_38 -> V_167 ,
V_159 -> V_161 || V_159 -> V_162 ,
V_166 ) ;
F_51 ( & V_38 -> V_163 ) ;
F_55 ( & V_159 -> V_164 ) ;
F_53 ( & V_38 -> V_163 ) ;
if ( V_159 -> V_162 )
return - V_138 ;
if ( V_26 <= 0 )
return - V_41 ;
return 0 ;
}
void F_56 ( struct V_157 * V_38 ,
struct V_158 * V_159 )
{
F_51 ( & V_38 -> V_163 ) ;
F_55 ( & V_159 -> V_164 ) ;
F_53 ( & V_38 -> V_163 ) ;
}
void F_57 ( struct V_157 * V_38 )
{
unsigned long V_85 ;
struct V_158 * V_159 ;
F_58 ( & V_38 -> V_163 , V_85 ) ;
F_59 (wait_entry, &shrd->notif_waits, list)
V_159 -> V_162 = true ;
F_60 ( & V_38 -> V_163 , V_85 ) ;
F_61 ( & V_38 -> V_167 ) ;
}
int F_62 ( struct V_13 * V_14 ,
enum V_42 V_43 )
{
struct V_158 V_168 ;
struct V_141 V_142 ;
int V_26 ;
enum V_42 V_169 ;
V_26 = F_63 ( V_14 ) ;
if ( V_26 )
return V_26 ;
F_49 ( V_14 -> V_38 , & V_168 , V_170 ,
F_48 , & V_142 ) ;
V_169 = V_14 -> V_38 -> V_43 ;
V_14 -> V_38 -> V_43 = V_43 ;
V_26 = F_19 ( V_14 , V_43 ) ;
if ( V_26 ) {
V_14 -> V_38 -> V_43 = V_169 ;
F_56 ( V_14 -> V_38 , & V_168 ) ;
return V_26 ;
}
F_64 ( V_14 ) ;
V_26 = F_54 ( V_14 -> V_38 , & V_168 ,
V_171 ) ;
if ( V_26 ) {
V_14 -> V_38 -> V_43 = V_169 ;
return V_26 ;
}
if ( ! V_142 . V_155 ) {
F_17 ( V_14 , L_22 ) ;
V_14 -> V_38 -> V_43 = V_169 ;
return - V_138 ;
}
if ( V_43 != V_45 ) {
V_26 = F_47 ( V_14 , V_43 ) ;
if ( V_26 ) {
V_14 -> V_38 -> V_43 = V_169 ;
return V_26 ;
}
F_65 ( 5 ) ;
}
V_26 = F_39 ( V_14 ) ;
if ( V_26 ) {
F_66 ( V_14 ,
L_23 , V_26 ) ;
V_14 -> V_38 -> V_43 = V_169 ;
return V_26 ;
}
return 0 ;
}
int F_67 ( struct V_13 * V_14 )
{
struct V_158 V_172 ;
int V_26 ;
F_68 ( & V_14 -> V_38 -> V_173 ) ;
if ( ! V_14 -> V_16 . V_11 . V_7 )
return 0 ;
if ( V_14 -> V_38 -> V_43 != V_47 )
return 0 ;
F_49 ( V_14 -> V_38 , & V_172 ,
V_174 ,
NULL , NULL ) ;
V_26 = F_62 ( V_14 , V_44 ) ;
if ( V_26 )
goto error;
V_26 = F_33 ( V_14 ) ;
if ( V_26 )
goto error;
V_26 = F_54 ( V_14 -> V_38 , & V_172 ,
V_175 ) ;
goto V_176;
error:
F_56 ( V_14 -> V_38 , & V_172 ) ;
V_176:
F_69 ( V_14 ) ;
return V_26 ;
}
