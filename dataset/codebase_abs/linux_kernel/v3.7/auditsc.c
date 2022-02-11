static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 = F_2 ( V_1 ) ;
if ( V_1 & ( V_4 | V_5 ) )
V_3 |= V_6 ;
return V_3 & V_2 ;
}
static int F_3 ( struct V_7 * V_8 , int V_2 )
{
unsigned V_3 ;
if ( F_4 ( ! V_8 ) )
return 0 ;
V_3 = V_8 -> V_9 ;
switch ( F_5 ( V_8 -> V_10 , V_3 ) ) {
case 0 :
if ( ( V_2 & V_6 ) &&
F_6 ( V_11 , V_3 ) )
return 1 ;
if ( ( V_2 & V_12 ) &&
F_6 ( V_13 , V_3 ) )
return 1 ;
if ( ( V_2 & V_14 ) &&
F_6 ( V_15 , V_3 ) )
return 1 ;
return 0 ;
case 1 :
if ( ( V_2 & V_6 ) &&
F_6 ( V_16 , V_3 ) )
return 1 ;
if ( ( V_2 & V_12 ) &&
F_6 ( V_17 , V_3 ) )
return 1 ;
if ( ( V_2 & V_14 ) &&
F_6 ( V_18 , V_3 ) )
return 1 ;
return 0 ;
case 2 :
return V_2 & F_2 ( V_8 -> V_19 [ 1 ] ) ;
case 3 :
return V_2 & F_2 ( V_8 -> V_19 [ 2 ] ) ;
case 4 :
return ( ( V_2 & V_6 ) && V_8 -> V_19 [ 0 ] == V_20 ) ;
case 5 :
return V_2 & V_21 ;
default:
return 0 ;
}
}
static int F_7 ( struct V_7 * V_8 , int V_22 )
{
struct V_23 * V_3 ;
T_1 V_24 = ( T_1 ) V_22 ;
if ( F_4 ( ! V_8 ) )
return 0 ;
F_8 (n, &ctx->names_list, list) {
if ( ( V_3 -> V_25 != - 1 ) &&
( ( V_3 -> V_24 & V_26 ) == V_24 ) )
return 1 ;
}
return 0 ;
}
static void F_9 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
}
static int F_10 ( struct V_7 * V_8 , struct V_30 * V_31 )
{
struct V_32 * V_33 = V_8 -> V_34 ;
int V_35 = V_8 -> V_36 ;
if ( F_11 ( V_35 ) ) {
V_33 -> V_37 [ -- V_35 ] = V_31 ;
V_8 -> V_36 = V_35 ;
return 1 ;
}
if ( ! V_33 )
return 0 ;
V_33 = V_33 -> V_38 ;
if ( V_33 ) {
V_33 -> V_37 [ 30 ] = V_31 ;
V_8 -> V_34 = V_33 ;
V_8 -> V_36 = 30 ;
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_32 * V_33 = V_8 -> V_34 ;
V_8 -> V_34 = F_13 ( sizeof( struct V_32 ) , V_39 ) ;
if ( ! V_8 -> V_34 ) {
V_8 -> V_34 = V_33 ;
return 0 ;
}
if ( V_33 )
V_33 -> V_38 = V_8 -> V_34 ;
else
V_8 -> V_40 = V_8 -> V_34 ;
V_8 -> V_36 = 31 ;
return 1 ;
}
static void F_14 ( struct V_7 * V_8 ,
struct V_32 * V_33 , int V_41 )
{
#ifdef F_15
struct V_32 * V_42 ;
int V_3 ;
if ( ! V_33 ) {
V_33 = V_8 -> V_40 ;
V_41 = 31 ;
if ( ! V_33 )
return;
}
V_3 = V_41 ;
for ( V_42 = V_33 ; V_42 != V_8 -> V_34 ; V_42 = V_42 -> V_38 , V_3 = 31 ) {
while ( V_3 -- ) {
F_16 ( V_42 -> V_37 [ V_3 ] ) ;
V_42 -> V_37 [ V_3 ] = NULL ;
}
}
while ( V_3 -- > V_8 -> V_36 ) {
F_16 ( V_42 -> V_37 [ V_3 ] ) ;
V_42 -> V_37 [ V_3 ] = NULL ;
}
V_8 -> V_34 = V_33 ;
V_8 -> V_36 = V_41 ;
#endif
}
static void F_17 ( struct V_7 * V_8 )
{
struct V_32 * V_33 , * V_42 ;
for ( V_33 = V_8 -> V_40 ; V_33 ; V_33 = V_42 ) {
V_42 = V_33 -> V_38 ;
F_18 ( V_33 ) ;
}
}
static int F_19 ( struct V_7 * V_8 , struct V_43 * V_44 )
{
#ifdef F_15
struct V_32 * V_33 ;
int V_3 ;
if ( ! V_44 )
return 0 ;
for ( V_33 = V_8 -> V_40 ; V_33 != V_8 -> V_34 ; V_33 = V_33 -> V_38 ) {
for ( V_3 = 0 ; V_3 < 31 ; V_3 ++ )
if ( F_20 ( V_33 -> V_37 [ V_3 ] , V_44 ) )
return 1 ;
}
if ( V_33 ) {
for ( V_3 = V_8 -> V_36 ; V_3 < 31 ; V_3 ++ )
if ( F_20 ( V_33 -> V_37 [ V_3 ] , V_44 ) )
return 1 ;
}
#endif
return 0 ;
}
static int F_21 ( T_2 V_45 ,
struct V_23 * V_46 ,
struct V_47 * V_48 ,
struct V_7 * V_8 )
{
struct V_23 * V_3 ;
int V_49 ;
if ( V_46 ) {
V_49 = F_22 ( V_45 , V_48 -> V_50 , V_46 -> V_45 ) ;
if ( V_49 )
return V_49 ;
}
if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
V_49 = F_22 ( V_45 , V_48 -> V_50 , V_3 -> V_45 ) ;
if ( V_49 )
return V_49 ;
}
}
return 0 ;
}
static int F_23 ( T_3 V_51 ,
struct V_23 * V_46 ,
struct V_47 * V_48 ,
struct V_7 * V_8 )
{
struct V_23 * V_3 ;
int V_49 ;
if ( V_46 ) {
V_49 = F_24 ( V_51 , V_48 -> V_50 , V_46 -> V_51 ) ;
if ( V_49 )
return V_49 ;
}
if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
V_49 = F_24 ( V_51 , V_48 -> V_50 , V_3 -> V_51 ) ;
if ( V_49 )
return V_49 ;
}
}
return 0 ;
}
static int F_25 ( struct V_52 * V_53 ,
const struct V_54 * V_54 ,
struct V_47 * V_48 ,
struct V_7 * V_8 ,
struct V_23 * V_46 )
{
switch ( V_48 -> V_22 ) {
case V_55 :
return F_21 ( V_54 -> V_45 , V_46 , V_48 , V_8 ) ;
case V_56 :
return F_23 ( V_54 -> V_51 , V_46 , V_48 , V_8 ) ;
case V_57 :
return F_21 ( V_54 -> V_58 , V_46 , V_48 , V_8 ) ;
case V_59 :
return F_23 ( V_54 -> V_60 , V_46 , V_48 , V_8 ) ;
case V_61 :
return F_21 ( V_53 -> V_62 , V_46 , V_48 , V_8 ) ;
case V_63 :
return F_21 ( V_54 -> V_64 , V_46 , V_48 , V_8 ) ;
case V_65 :
return F_23 ( V_54 -> V_66 , V_46 , V_48 , V_8 ) ;
case V_67 :
return F_21 ( V_54 -> V_68 , V_46 , V_48 , V_8 ) ;
case V_69 :
return F_23 ( V_54 -> V_70 , V_46 , V_48 , V_8 ) ;
case V_71 :
return F_22 ( V_54 -> V_45 , V_48 -> V_50 , V_53 -> V_62 ) ;
case V_72 :
return F_22 ( V_54 -> V_45 , V_48 -> V_50 , V_54 -> V_58 ) ;
case V_73 :
return F_22 ( V_54 -> V_45 , V_48 -> V_50 , V_54 -> V_64 ) ;
case V_74 :
return F_22 ( V_54 -> V_45 , V_48 -> V_50 , V_54 -> V_68 ) ;
case V_75 :
return F_22 ( V_53 -> V_62 , V_48 -> V_50 , V_54 -> V_58 ) ;
case V_76 :
return F_22 ( V_53 -> V_62 , V_48 -> V_50 , V_54 -> V_64 ) ;
case V_77 :
return F_22 ( V_53 -> V_62 , V_48 -> V_50 , V_54 -> V_68 ) ;
case V_78 :
return F_22 ( V_54 -> V_58 , V_48 -> V_50 , V_54 -> V_64 ) ;
case V_79 :
return F_22 ( V_54 -> V_58 , V_48 -> V_50 , V_54 -> V_68 ) ;
case V_80 :
return F_22 ( V_54 -> V_64 , V_48 -> V_50 , V_54 -> V_68 ) ;
case V_81 :
return F_24 ( V_54 -> V_51 , V_48 -> V_50 , V_54 -> V_60 ) ;
case V_82 :
return F_24 ( V_54 -> V_51 , V_48 -> V_50 , V_54 -> V_66 ) ;
case V_83 :
return F_24 ( V_54 -> V_51 , V_48 -> V_50 , V_54 -> V_70 ) ;
case V_84 :
return F_24 ( V_54 -> V_60 , V_48 -> V_50 , V_54 -> V_66 ) ;
case V_85 :
return F_24 ( V_54 -> V_60 , V_48 -> V_50 , V_54 -> V_70 ) ;
case V_86 :
return F_24 ( V_54 -> V_66 , V_48 -> V_50 , V_54 -> V_70 ) ;
default:
F_26 ( 1 , L_1 ) ;
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_52 * V_53 ,
struct V_87 * V_88 ,
struct V_7 * V_8 ,
struct V_23 * V_46 ,
enum V_89 * V_90 ,
bool V_91 )
{
const struct V_54 * V_54 ;
int V_92 , V_93 = 1 ;
T_4 V_94 ;
V_54 = F_28 ( V_53 -> V_54 , V_53 == V_95 || V_91 ) ;
for ( V_92 = 0 ; V_92 < V_88 -> V_96 ; V_92 ++ ) {
struct V_47 * V_48 = & V_88 -> V_97 [ V_92 ] ;
struct V_23 * V_3 ;
int V_98 = 0 ;
switch ( V_48 -> type ) {
case V_99 :
V_98 = F_29 ( V_53 -> V_100 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_101 :
if ( V_8 ) {
if ( ! V_8 -> V_102 )
V_8 -> V_102 = F_30 () ;
V_98 = F_29 ( V_8 -> V_102 , V_48 -> V_50 , V_48 -> V_22 ) ;
}
break;
case V_103 :
V_98 = F_22 ( V_54 -> V_45 , V_48 -> V_50 , V_48 -> V_45 ) ;
break;
case V_104 :
V_98 = F_22 ( V_54 -> V_58 , V_48 -> V_50 , V_48 -> V_45 ) ;
break;
case V_105 :
V_98 = F_22 ( V_54 -> V_64 , V_48 -> V_50 , V_48 -> V_45 ) ;
break;
case V_106 :
V_98 = F_22 ( V_54 -> V_68 , V_48 -> V_50 , V_48 -> V_45 ) ;
break;
case V_107 :
V_98 = F_24 ( V_54 -> V_51 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_108 :
V_98 = F_24 ( V_54 -> V_60 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_109 :
V_98 = F_24 ( V_54 -> V_66 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_110 :
V_98 = F_24 ( V_54 -> V_70 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_111 :
V_98 = F_29 ( V_53 -> V_112 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_113 :
if ( V_8 )
V_98 = F_29 ( V_8 -> V_10 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_114 :
if ( V_8 && V_8 -> V_115 )
V_98 = F_29 ( V_8 -> V_116 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_117 :
if ( V_8 && V_8 -> V_115 ) {
if ( V_48 -> V_22 )
V_98 = F_29 ( V_8 -> V_115 , V_48 -> V_50 , V_118 ) ;
else
V_98 = F_29 ( V_8 -> V_115 , V_48 -> V_50 , V_119 ) ;
}
break;
case V_120 :
if ( V_46 ) {
if ( F_29 ( F_31 ( V_46 -> V_121 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_31 ( V_46 -> V_122 ) , V_48 -> V_50 , V_48 -> V_22 ) )
++ V_98 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_29 ( F_31 ( V_3 -> V_121 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_31 ( V_3 -> V_122 ) , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_123 :
if ( V_46 ) {
if ( F_29 ( F_32 ( V_46 -> V_121 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_32 ( V_46 -> V_122 ) , V_48 -> V_50 , V_48 -> V_22 ) )
++ V_98 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_29 ( F_32 ( V_3 -> V_121 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_32 ( V_3 -> V_122 ) , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_124 :
if ( V_46 )
V_98 = ( V_46 -> V_25 == V_48 -> V_22 ) ;
else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_29 ( V_3 -> V_25 , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_125 :
if ( V_46 ) {
V_98 = F_22 ( V_46 -> V_45 , V_48 -> V_50 , V_48 -> V_45 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_22 ( V_3 -> V_45 , V_48 -> V_50 , V_48 -> V_45 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_126 :
if ( V_46 ) {
V_98 = F_24 ( V_46 -> V_51 , V_48 -> V_50 , V_48 -> V_51 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_24 ( V_3 -> V_51 , V_48 -> V_50 , V_48 -> V_51 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_127 :
if ( V_46 )
V_98 = F_33 ( V_88 -> V_128 , V_46 -> V_25 , V_46 -> V_121 ) ;
break;
case V_129 :
if ( V_8 )
V_98 = F_19 ( V_8 , V_88 -> V_44 ) ;
break;
case V_130 :
V_98 = 0 ;
if ( V_8 )
V_98 = F_22 ( V_53 -> V_62 , V_48 -> V_50 , V_48 -> V_45 ) ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
if ( V_48 -> V_136 ) {
if ( V_93 ) {
F_34 ( V_53 , & V_94 ) ;
V_93 = 0 ;
}
V_98 = F_35 ( V_94 , V_48 -> type ,
V_48 -> V_50 ,
V_48 -> V_136 ,
V_8 ) ;
}
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
if ( V_48 -> V_136 ) {
if ( V_46 ) {
V_98 = F_35 (
V_46 -> V_142 , V_48 -> type , V_48 -> V_50 ,
V_48 -> V_136 , V_8 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_35 ( V_3 -> V_142 , V_48 -> type ,
V_48 -> V_50 , V_48 -> V_136 ,
V_8 ) ) {
++ V_98 ;
break;
}
}
}
if ( ! V_8 || V_8 -> type != V_143 )
break;
if ( F_35 ( V_8 -> V_144 . V_142 ,
V_48 -> type , V_48 -> V_50 ,
V_48 -> V_136 , V_8 ) )
++ V_98 ;
}
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
if ( V_8 )
V_98 = F_29 ( V_8 -> V_19 [ V_48 -> type - V_145 ] , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_149 :
V_98 = 1 ;
break;
case V_150 :
V_98 = F_3 ( V_8 , V_48 -> V_22 ) ;
break;
case V_151 :
V_98 = F_7 ( V_8 , V_48 -> V_22 ) ;
break;
case V_152 :
V_98 = F_25 ( V_53 , V_54 , V_48 , V_8 , V_46 ) ;
break;
}
if ( ! V_98 )
return 0 ;
}
if ( V_8 ) {
if ( V_88 -> V_27 <= V_8 -> V_27 )
return 0 ;
if ( V_88 -> V_153 ) {
F_18 ( V_8 -> V_153 ) ;
V_8 -> V_153 = F_36 ( V_88 -> V_153 , V_154 ) ;
}
V_8 -> V_27 = V_88 -> V_27 ;
}
switch ( V_88 -> V_155 ) {
case V_156 : * V_90 = V_157 ; break;
case V_158 : * V_90 = V_29 ; break;
}
return 1 ;
}
static enum V_89 F_37 ( struct V_52 * V_53 , char * * V_159 )
{
struct V_160 * V_161 ;
enum V_89 V_90 ;
F_38 () ;
F_39 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_27 ( V_53 , & V_161 -> V_88 , NULL , NULL ,
& V_90 , true ) ) {
if ( V_90 == V_29 )
* V_159 = F_36 ( V_161 -> V_88 . V_153 , V_154 ) ;
F_40 () ;
return V_90 ;
}
}
F_40 () ;
return V_162 ;
}
static enum V_89 F_41 ( struct V_52 * V_53 ,
struct V_7 * V_8 ,
struct V_163 * V_164 )
{
struct V_160 * V_161 ;
enum V_89 V_90 ;
if ( V_165 && V_53 -> V_166 == V_165 )
return V_157 ;
F_38 () ;
if ( ! F_42 ( V_164 ) ) {
int V_167 = F_43 ( V_8 -> V_9 ) ;
int V_168 = F_44 ( V_8 -> V_9 ) ;
F_39 (e, list, list) {
if ( ( V_161 -> V_88 . V_2 [ V_167 ] & V_168 ) == V_168 &&
F_27 ( V_53 , & V_161 -> V_88 , V_8 , NULL ,
& V_90 , false ) ) {
F_40 () ;
V_8 -> V_28 = V_90 ;
return V_90 ;
}
}
}
F_40 () ;
return V_162 ;
}
static int F_45 ( struct V_52 * V_53 ,
struct V_23 * V_3 ,
struct V_7 * V_8 ) {
int V_167 , V_168 ;
int V_169 = F_46 ( ( T_4 ) V_3 -> V_25 ) ;
struct V_163 * V_164 = & V_170 [ V_169 ] ;
struct V_160 * V_161 ;
enum V_89 V_90 ;
V_167 = F_43 ( V_8 -> V_9 ) ;
V_168 = F_44 ( V_8 -> V_9 ) ;
if ( F_42 ( V_164 ) )
return 0 ;
F_39 (e, list, list) {
if ( ( V_161 -> V_88 . V_2 [ V_167 ] & V_168 ) == V_168 &&
F_27 ( V_53 , & V_161 -> V_88 , V_8 , V_3 , & V_90 , false ) ) {
V_8 -> V_28 = V_90 ;
return 1 ;
}
}
return 0 ;
}
void F_47 ( struct V_52 * V_53 , struct V_7 * V_8 )
{
struct V_23 * V_3 ;
if ( V_165 && V_53 -> V_166 == V_165 )
return;
F_38 () ;
F_8 (n, &ctx->names_list, list) {
if ( F_45 ( V_53 , V_3 , V_8 ) )
break;
}
F_40 () ;
}
static inline struct V_7 * F_48 ( struct V_52 * V_53 ,
int V_115 ,
long V_116 )
{
struct V_7 * V_171 = V_53 -> V_7 ;
if ( ! V_171 )
return NULL ;
V_171 -> V_115 = V_115 ;
if ( F_4 ( V_116 <= - V_172 ) &&
( V_116 >= - V_173 ) &&
( V_116 != - V_174 ) )
V_171 -> V_116 = - V_175 ;
else
V_171 -> V_116 = V_116 ;
if ( V_171 -> V_176 && ! V_171 -> V_177 ) {
F_41 ( V_53 , V_171 , & V_178 [ V_179 ] ) ;
F_47 ( V_53 , V_171 ) ;
}
V_53 -> V_7 = NULL ;
return V_171 ;
}
static inline void F_49 ( struct V_7 * V_171 )
{
struct V_23 * V_3 , * V_38 ;
#if V_180 == 2
if ( V_171 -> V_181 + V_171 -> V_182 != V_171 -> V_183 ) {
F_50 ( V_184 L_2
L_3
L_4 ,
__FILE__ , __LINE__ ,
V_171 -> V_185 , V_171 -> V_9 , V_171 -> V_176 ,
V_171 -> V_183 , V_171 -> V_181 ,
V_171 -> V_182 ) ;
F_8 (n, &context->names_list, list) {
F_50 ( V_184 L_5 , V_92 ,
V_3 -> V_46 , V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
F_51 () ;
return;
}
#endif
#if V_180
V_171 -> V_181 = 0 ;
V_171 -> V_182 = 0 ;
#endif
F_52 (n, next, &context->names_list, list) {
F_53 ( & V_3 -> V_164 ) ;
if ( V_3 -> V_46 && V_3 -> V_186 )
F_54 ( V_3 -> V_46 ) ;
if ( V_3 -> V_187 )
F_18 ( V_3 ) ;
}
V_171 -> V_183 = 0 ;
F_55 ( & V_171 -> V_188 ) ;
V_171 -> V_188 . V_189 = NULL ;
V_171 -> V_188 . V_190 = NULL ;
}
static inline void F_56 ( struct V_7 * V_171 )
{
struct V_191 * V_192 ;
while ( ( V_192 = V_171 -> V_192 ) ) {
V_171 -> V_192 = V_192 -> V_38 ;
F_18 ( V_192 ) ;
}
while ( ( V_192 = V_171 -> V_193 ) ) {
V_171 -> V_193 = V_192 -> V_38 ;
F_18 ( V_192 ) ;
}
}
static inline void F_57 ( struct V_7 * V_171 ,
enum V_89 V_90 )
{
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
V_171 -> V_90 = V_90 ;
V_171 -> V_27 = V_90 == V_29 ? ~ 0ULL : 0 ;
}
static inline struct V_7 * F_58 ( enum V_89 V_90 )
{
struct V_7 * V_171 ;
if ( ! ( V_171 = F_59 ( sizeof( * V_171 ) , V_39 ) ) )
return NULL ;
F_57 ( V_171 , V_90 ) ;
F_60 ( & V_171 -> V_194 ) ;
F_60 ( & V_171 -> V_195 ) ;
return V_171 ;
}
int F_61 ( struct V_52 * V_53 )
{
struct V_7 * V_171 ;
enum V_89 V_90 ;
char * V_159 = NULL ;
if ( F_11 ( ! V_196 ) )
return 0 ;
V_90 = F_37 ( V_53 , & V_159 ) ;
if ( V_90 == V_157 )
return 0 ;
if ( ! ( V_171 = F_58 ( V_90 ) ) ) {
F_18 ( V_159 ) ;
F_62 ( L_7 ) ;
return - V_197 ;
}
V_171 -> V_153 = V_159 ;
V_53 -> V_7 = V_171 ;
F_63 ( V_53 , V_198 ) ;
return 0 ;
}
static inline void F_64 ( struct V_7 * V_171 )
{
struct V_7 * V_199 ;
int V_41 = 0 ;
do {
V_199 = V_171 -> V_199 ;
if ( V_199 || ( V_41 && V_41 < 10 ) ) {
++ V_41 ;
F_50 ( V_184 L_8
L_9 ,
V_171 -> V_185 , V_171 -> V_9 ,
V_171 -> V_183 , V_41 ) ;
}
F_49 ( V_171 ) ;
F_14 ( V_171 , NULL , 0 ) ;
F_17 ( V_171 ) ;
F_56 ( V_171 ) ;
F_18 ( V_171 -> V_153 ) ;
F_18 ( V_171 -> V_200 ) ;
F_18 ( V_171 ) ;
V_171 = V_199 ;
} while ( V_171 );
if ( V_41 >= 10 )
F_50 ( V_184 L_10 , V_41 ) ;
}
void F_65 ( struct V_201 * V_202 )
{
char * V_8 = NULL ;
unsigned V_203 ;
int error ;
T_4 V_94 ;
F_34 ( V_95 , & V_94 ) ;
if ( ! V_94 )
return;
error = F_66 ( V_94 , & V_8 , & V_203 ) ;
if ( error ) {
if ( error != - V_204 )
goto V_205;
return;
}
F_67 ( V_202 , L_11 , V_8 ) ;
F_68 ( V_8 , V_203 ) ;
return;
V_205:
F_69 ( L_12 ) ;
return;
}
void F_70 ( struct V_201 * V_202 , struct V_52 * V_53 )
{
const struct V_54 * V_54 ;
char V_46 [ sizeof( V_53 -> V_206 ) ] ;
struct V_207 * V_208 = V_53 -> V_208 ;
char * V_209 ;
if ( ! V_202 )
return;
V_54 = F_71 () ;
F_72 ( & V_53 -> V_210 -> V_211 ) ;
if ( V_53 -> signal && V_53 -> signal -> V_209 && V_53 -> signal -> V_209 -> V_46 )
V_209 = V_53 -> signal -> V_209 -> V_46 ;
else
V_209 = L_13 ;
F_73 ( & V_53 -> V_210 -> V_211 ) ;
F_67 ( V_202 ,
L_14
L_15
L_16 ,
F_30 () ,
V_53 -> V_100 ,
F_74 ( & V_212 , V_53 -> V_62 ) ,
F_74 ( & V_212 , V_54 -> V_45 ) ,
F_75 ( & V_212 , V_54 -> V_51 ) ,
F_74 ( & V_212 , V_54 -> V_58 ) ,
F_74 ( & V_212 , V_54 -> V_64 ) ,
F_74 ( & V_212 , V_54 -> V_68 ) ,
F_75 ( & V_212 , V_54 -> V_60 ) ,
F_75 ( & V_212 , V_54 -> V_66 ) ,
F_75 ( & V_212 , V_54 -> V_70 ) ,
V_53 -> V_213 , V_209 ) ;
F_76 ( V_46 , V_53 ) ;
F_67 ( V_202 , L_17 ) ;
F_77 ( V_202 , V_46 ) ;
if ( V_208 ) {
F_78 ( & V_208 -> V_214 ) ;
if ( V_208 -> V_215 )
F_79 ( V_202 , L_18 , & V_208 -> V_215 -> V_216 ) ;
F_80 ( & V_208 -> V_214 ) ;
}
F_65 ( V_202 ) ;
}
static int F_81 ( struct V_7 * V_171 , T_5 V_100 ,
T_2 V_217 , T_2 V_45 , unsigned int V_213 ,
T_4 V_94 , char * V_206 )
{
struct V_201 * V_202 ;
char * V_8 = NULL ;
T_4 V_203 ;
int V_49 = 0 ;
V_202 = F_82 ( V_171 , V_39 , V_218 ) ;
if ( ! V_202 )
return V_49 ;
F_67 ( V_202 , L_19 , V_100 ,
F_74 ( & V_212 , V_217 ) ,
F_74 ( & V_212 , V_45 ) , V_213 ) ;
if ( F_66 ( V_94 , & V_8 , & V_203 ) ) {
F_67 ( V_202 , L_20 ) ;
V_49 = 1 ;
} else {
F_67 ( V_202 , L_21 , V_8 ) ;
F_68 ( V_8 , V_203 ) ;
}
F_67 ( V_202 , L_22 ) ;
F_77 ( V_202 , V_206 ) ;
F_83 ( V_202 ) ;
return V_49 ;
}
static int F_84 ( struct V_7 * V_171 ,
struct V_201 * * V_202 ,
int V_219 ,
T_6 * V_220 ,
const char T_7 * V_33 ,
char * V_221 )
{
char V_222 [ 12 ] ;
const char T_7 * V_223 = V_33 ;
T_6 V_224 = snprintf ( V_222 , 12 , L_23 , V_219 ) + 5 ;
T_6 V_203 , V_225 , V_226 ;
T_6 V_227 = V_228 ;
unsigned int V_92 , V_229 = 0 , V_230 = 0 ;
int V_231 ;
V_225 = V_203 = F_85 ( V_33 , V_232 ) - 1 ;
if ( F_4 ( ( V_203 == - 1 ) || V_203 > V_232 - 1 ) ) {
F_86 ( 1 ) ;
F_87 ( V_233 , V_95 , 0 ) ;
return - 1 ;
}
do {
if ( V_225 > V_228 )
V_226 = V_228 ;
else
V_226 = V_225 ;
V_231 = F_88 ( V_221 , V_223 , V_226 ) ;
if ( V_231 ) {
F_86 ( 1 ) ;
F_87 ( V_233 , V_95 , 0 ) ;
return - 1 ;
}
V_221 [ V_226 ] = '\0' ;
V_229 = F_89 ( V_221 , V_226 ) ;
if ( V_229 ) {
V_227 = V_228 / 2 ;
break;
}
V_225 -= V_226 ;
V_223 += V_226 ;
} while ( V_225 > 0 );
V_225 = V_203 ;
if ( V_203 > V_227 )
V_230 = 1 ;
for ( V_92 = 0 ; V_225 > 0 ; V_92 ++ ) {
int V_234 ;
if ( V_225 > V_227 )
V_226 = V_227 ;
else
V_226 = V_225 ;
V_234 = V_228 - V_224 - * V_220 ;
if ( V_229 )
V_234 -= ( V_226 * 2 ) ;
else
V_234 -= V_226 ;
if ( V_234 < 0 ) {
* V_220 = 0 ;
F_83 ( * V_202 ) ;
* V_202 = F_82 ( V_171 , V_39 , V_235 ) ;
if ( ! * V_202 )
return 0 ;
}
if ( ( V_92 == 0 ) && ( V_230 ) )
F_67 ( * V_202 , L_24 , V_219 ,
V_229 ? 2 * V_203 : V_203 ) ;
if ( V_203 >= V_227 )
V_231 = F_88 ( V_221 , V_33 , V_226 ) ;
else
V_231 = 0 ;
if ( V_231 ) {
F_86 ( 1 ) ;
F_87 ( V_233 , V_95 , 0 ) ;
return - 1 ;
}
V_221 [ V_226 ] = '\0' ;
F_67 ( * V_202 , L_25 , V_219 ) ;
if ( V_230 )
F_67 ( * V_202 , L_26 , V_92 ) ;
F_67 ( * V_202 , L_27 ) ;
if ( V_229 )
F_90 ( * V_202 , V_221 , V_226 ) ;
else
F_91 ( * V_202 , V_221 ) ;
V_33 += V_226 ;
V_225 -= V_226 ;
* V_220 += V_224 ;
if ( V_229 )
* V_220 += V_226 * 2 ;
else
* V_220 += V_226 ;
}
return V_203 + 1 ;
}
static void F_92 ( struct V_7 * V_171 ,
struct V_201 * * V_202 ,
struct V_236 * V_237 )
{
int V_92 , V_203 ;
T_6 V_220 = 0 ;
const char T_7 * V_33 ;
char * V_221 ;
if ( V_237 -> V_208 != V_95 -> V_208 )
return;
V_33 = ( const char T_7 * ) V_237 -> V_208 -> V_238 ;
F_67 ( * V_202 , L_28 , V_237 -> V_239 ) ;
V_221 = F_59 ( V_228 + 1 , V_39 ) ;
if ( ! V_221 ) {
F_69 ( L_29 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_237 -> V_239 ; V_92 ++ ) {
V_203 = F_84 ( V_171 , V_202 , V_92 ,
& V_220 , V_33 , V_221 ) ;
if ( V_203 <= 0 )
break;
V_33 += V_203 ;
}
F_18 ( V_221 ) ;
}
static void F_93 ( struct V_201 * V_202 , char * V_240 , T_8 * V_241 )
{
int V_92 ;
F_67 ( V_202 , L_30 , V_240 ) ;
F_94 (i) {
F_67 ( V_202 , L_31 , V_241 -> V_241 [ ( V_242 - 1 ) - V_92 ] ) ;
}
}
static void F_95 ( struct V_201 * V_202 , struct V_23 * V_46 )
{
T_8 * V_243 = & V_46 -> V_244 . V_245 ;
T_8 * V_246 = & V_46 -> V_244 . V_247 ;
int log = 0 ;
if ( ! F_96 ( * V_243 ) ) {
F_93 ( V_202 , L_32 , V_243 ) ;
log = 1 ;
}
if ( ! F_96 ( * V_246 ) ) {
F_93 ( V_202 , L_33 , V_246 ) ;
log = 1 ;
}
if ( log )
F_67 ( V_202 , L_34 , V_46 -> V_244 . V_248 , V_46 -> V_249 ) ;
}
static void F_97 ( struct V_7 * V_171 , int * V_250 )
{
struct V_201 * V_202 ;
int V_92 ;
V_202 = F_82 ( V_171 , V_39 , V_171 -> type ) ;
if ( ! V_202 )
return;
switch ( V_171 -> type ) {
case V_251 : {
int V_252 = V_171 -> V_253 . V_252 ;
F_67 ( V_202 , L_35 , V_252 ) ;
for ( V_92 = 0 ; V_92 < V_252 ; V_92 ++ )
F_67 ( V_202 , L_36 , V_92 ,
V_171 -> V_253 . args [ V_92 ] ) ;
break; }
case V_143 : {
T_4 V_142 = V_171 -> V_144 . V_142 ;
F_67 ( V_202 , L_37 ,
F_74 ( & V_212 , V_171 -> V_144 . V_45 ) ,
F_75 ( & V_212 , V_171 -> V_144 . V_51 ) ,
V_171 -> V_144 . V_24 ) ;
if ( V_142 ) {
char * V_8 = NULL ;
T_4 V_203 ;
if ( F_66 ( V_142 , & V_8 , & V_203 ) ) {
F_67 ( V_202 , L_38 , V_142 ) ;
* V_250 = 1 ;
} else {
F_67 ( V_202 , L_21 , V_8 ) ;
F_68 ( V_8 , V_203 ) ;
}
}
if ( V_171 -> V_144 . V_254 ) {
F_83 ( V_202 ) ;
V_202 = F_82 ( V_171 , V_39 ,
V_255 ) ;
F_67 ( V_202 ,
L_39 ,
V_171 -> V_144 . V_256 ,
V_171 -> V_144 . V_257 ,
V_171 -> V_144 . V_258 ,
V_171 -> V_144 . V_259 ) ;
if ( ! V_202 )
return;
}
break; }
case V_260 : {
F_67 ( V_202 ,
L_40
L_41 ,
V_171 -> V_261 . V_262 , V_171 -> V_261 . V_24 ,
V_171 -> V_261 . V_263 . V_264 ,
V_171 -> V_261 . V_263 . V_265 ,
V_171 -> V_261 . V_263 . V_266 ,
V_171 -> V_261 . V_263 . V_267 ) ;
break; }
case V_268 : {
F_67 ( V_202 ,
L_42
L_43 ,
V_171 -> V_269 . V_270 ,
V_171 -> V_269 . V_271 ,
V_171 -> V_269 . V_272 ,
V_171 -> V_269 . V_273 . V_274 ,
V_171 -> V_269 . V_273 . V_275 ) ;
break; }
case V_276 : {
F_67 ( V_202 , L_44 ,
V_171 -> V_277 . V_270 ,
V_171 -> V_277 . V_278 ) ;
break; }
case V_279 : {
struct V_280 * V_263 = & V_171 -> V_281 . V_282 ;
F_67 ( V_202 ,
L_45
L_46 ,
V_171 -> V_281 . V_270 ,
V_263 -> V_264 , V_263 -> V_265 ,
V_263 -> V_266 , V_263 -> V_267 ) ;
break; }
case V_283 : {
F_67 ( V_202 , L_47 , V_171 -> V_284 . V_100 ) ;
F_93 ( V_202 , L_48 , & V_171 -> V_284 . V_241 . V_247 ) ;
F_93 ( V_202 , L_49 , & V_171 -> V_284 . V_241 . V_245 ) ;
F_93 ( V_202 , L_50 , & V_171 -> V_284 . V_241 . V_285 ) ;
break; }
case V_286 : {
F_67 ( V_202 , L_51 , V_171 -> V_287 . V_288 ,
V_171 -> V_287 . V_1 ) ;
break; }
}
F_83 ( V_202 ) ;
}
static void F_98 ( struct V_7 * V_171 , struct V_23 * V_3 ,
int V_289 , int * V_250 )
{
struct V_201 * V_202 ;
V_202 = F_82 ( V_171 , V_39 , V_290 ) ;
if ( ! V_202 )
return;
F_67 ( V_202 , L_52 , V_289 ) ;
if ( V_3 -> V_46 ) {
switch ( V_3 -> V_291 ) {
case V_292 :
F_67 ( V_202 , L_53 ) ;
F_77 ( V_202 , V_3 -> V_46 -> V_46 ) ;
break;
case 0 :
F_79 ( V_202 , L_53 , & V_171 -> V_188 ) ;
break;
default:
F_67 ( V_202 , L_53 ) ;
F_99 ( V_202 , V_3 -> V_46 -> V_46 ,
V_3 -> V_291 ) ;
}
} else
F_67 ( V_202 , L_54 ) ;
if ( V_3 -> V_25 != ( unsigned long ) - 1 ) {
F_67 ( V_202 , L_55
L_56
L_57 ,
V_3 -> V_25 ,
F_31 ( V_3 -> V_121 ) ,
F_32 ( V_3 -> V_121 ) ,
V_3 -> V_24 ,
F_74 ( & V_212 , V_3 -> V_45 ) ,
F_75 ( & V_212 , V_3 -> V_51 ) ,
F_31 ( V_3 -> V_122 ) ,
F_32 ( V_3 -> V_122 ) ) ;
}
if ( V_3 -> V_142 != 0 ) {
char * V_8 = NULL ;
T_4 V_203 ;
if ( F_66 (
V_3 -> V_142 , & V_8 , & V_203 ) ) {
F_67 ( V_202 , L_38 , V_3 -> V_142 ) ;
* V_250 = 2 ;
} else {
F_67 ( V_202 , L_21 , V_8 ) ;
F_68 ( V_8 , V_203 ) ;
}
}
F_95 ( V_202 , V_3 ) ;
F_83 ( V_202 ) ;
}
static void F_100 ( struct V_7 * V_171 , struct V_52 * V_53 )
{
int V_92 , V_250 = 0 ;
struct V_201 * V_202 ;
struct V_191 * V_192 ;
struct V_23 * V_3 ;
V_171 -> V_112 = V_53 -> V_112 ;
V_202 = F_82 ( V_171 , V_39 , V_293 ) ;
if ( ! V_202 )
return;
F_67 ( V_202 , L_58 ,
V_171 -> V_10 , V_171 -> V_9 ) ;
if ( V_171 -> V_112 != V_294 )
F_67 ( V_202 , L_59 , V_171 -> V_112 ) ;
if ( V_171 -> V_115 )
F_67 ( V_202 , L_60 ,
( V_171 -> V_115 == V_118 ) ? L_61 : L_62 ,
V_171 -> V_116 ) ;
F_67 ( V_202 ,
L_63 ,
V_171 -> V_19 [ 0 ] ,
V_171 -> V_19 [ 1 ] ,
V_171 -> V_19 [ 2 ] ,
V_171 -> V_19 [ 3 ] ,
V_171 -> V_183 ) ;
F_70 ( V_202 , V_53 ) ;
F_101 ( V_202 , V_171 -> V_153 ) ;
F_83 ( V_202 ) ;
for ( V_192 = V_171 -> V_192 ; V_192 ; V_192 = V_192 -> V_38 ) {
V_202 = F_82 ( V_171 , V_39 , V_192 -> type ) ;
if ( ! V_202 )
continue;
switch ( V_192 -> type ) {
case V_235 : {
struct V_236 * V_237 = ( void * ) V_192 ;
F_92 ( V_171 , & V_202 , V_237 ) ;
break; }
case V_295 : {
struct V_296 * V_297 = ( void * ) V_192 ;
F_67 ( V_202 , L_64 , V_297 -> V_249 ) ;
F_93 ( V_202 , L_65 , & V_297 -> V_244 . V_245 ) ;
F_93 ( V_202 , L_66 , & V_297 -> V_244 . V_247 ) ;
F_67 ( V_202 , L_67 , V_297 -> V_244 . V_248 ) ;
F_93 ( V_202 , L_68 , & V_297 -> V_298 . V_245 ) ;
F_93 ( V_202 , L_69 , & V_297 -> V_298 . V_247 ) ;
F_93 ( V_202 , L_70 , & V_297 -> V_298 . V_285 ) ;
F_93 ( V_202 , L_71 , & V_297 -> V_299 . V_245 ) ;
F_93 ( V_202 , L_72 , & V_297 -> V_299 . V_247 ) ;
F_93 ( V_202 , L_73 , & V_297 -> V_299 . V_285 ) ;
break; }
}
F_83 ( V_202 ) ;
}
if ( V_171 -> type )
F_97 ( V_171 , & V_250 ) ;
if ( V_171 -> V_300 [ 0 ] >= 0 ) {
V_202 = F_82 ( V_171 , V_39 , V_301 ) ;
if ( V_202 ) {
F_67 ( V_202 , L_74 ,
V_171 -> V_300 [ 0 ] , V_171 -> V_300 [ 1 ] ) ;
F_83 ( V_202 ) ;
}
}
if ( V_171 -> V_302 ) {
V_202 = F_82 ( V_171 , V_39 , V_303 ) ;
if ( V_202 ) {
F_67 ( V_202 , L_75 ) ;
F_90 ( V_202 , ( void * ) V_171 -> V_200 ,
V_171 -> V_302 ) ;
F_83 ( V_202 ) ;
}
}
for ( V_192 = V_171 -> V_193 ; V_192 ; V_192 = V_192 -> V_38 ) {
struct V_304 * V_297 = ( void * ) V_192 ;
for ( V_92 = 0 ; V_92 < V_297 -> V_305 ; V_92 ++ )
if ( F_81 ( V_171 , V_297 -> V_306 [ V_92 ] ,
V_297 -> V_307 [ V_92 ] ,
V_297 -> V_308 [ V_92 ] ,
V_297 -> V_309 [ V_92 ] ,
V_297 -> V_310 [ V_92 ] ,
V_297 -> V_311 [ V_92 ] ) )
V_250 = 1 ;
}
if ( V_171 -> V_306 &&
F_81 ( V_171 , V_171 -> V_306 ,
V_171 -> V_307 , V_171 -> V_308 ,
V_171 -> V_309 ,
V_171 -> V_310 , V_171 -> V_311 ) )
V_250 = 1 ;
if ( V_171 -> V_188 . V_189 && V_171 -> V_188 . V_190 ) {
V_202 = F_82 ( V_171 , V_39 , V_312 ) ;
if ( V_202 ) {
F_79 ( V_202 , L_76 , & V_171 -> V_188 ) ;
F_83 ( V_202 ) ;
}
}
V_92 = 0 ;
F_8 (n, &context->names_list, list)
F_98 ( V_171 , V_3 , V_92 ++ , & V_250 ) ;
V_202 = F_82 ( V_171 , V_39 , V_313 ) ;
if ( V_202 )
F_83 ( V_202 ) ;
if ( V_250 )
F_69 ( L_77 ) ;
}
void F_102 ( struct V_52 * V_53 )
{
struct V_7 * V_171 ;
V_171 = F_48 ( V_53 , 0 , 0 ) ;
if ( ! V_171 )
return;
if ( V_171 -> V_176 && V_171 -> V_28 == V_29 )
F_100 ( V_171 , V_53 ) ;
if ( ! F_42 ( & V_171 -> V_194 ) )
F_103 ( & V_171 -> V_194 ) ;
F_64 ( V_171 ) ;
}
void F_104 ( int V_10 , int V_9 ,
unsigned long V_314 , unsigned long V_315 ,
unsigned long V_316 , unsigned long V_317 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_171 = V_53 -> V_7 ;
enum V_89 V_90 ;
if ( ! V_171 )
return;
if ( V_171 -> V_176 ) {
struct V_7 * V_318 ;
#if V_180
F_50 ( V_184
L_78
L_79 ,
V_171 -> V_185 , V_53 -> V_100 , V_171 -> V_9 , V_9 ) ;
#endif
V_318 = F_58 ( V_171 -> V_90 ) ;
if ( V_318 ) {
V_318 -> V_199 = V_171 ;
V_171 = V_318 ;
V_53 -> V_7 = V_318 ;
} else {
F_57 ( V_171 , V_171 -> V_90 ) ;
}
}
F_105 ( V_171 -> V_176 || V_171 -> V_183 ) ;
if ( ! V_319 )
return;
V_171 -> V_10 = V_10 ;
V_171 -> V_9 = V_9 ;
V_171 -> V_19 [ 0 ] = V_314 ;
V_171 -> V_19 [ 1 ] = V_315 ;
V_171 -> V_19 [ 2 ] = V_316 ;
V_171 -> V_19 [ 3 ] = V_317 ;
V_90 = V_171 -> V_90 ;
V_171 -> V_177 = ! V_320 ;
if ( ! V_171 -> V_177 && V_90 == V_162 ) {
V_171 -> V_27 = 0 ;
V_90 = F_41 ( V_53 , V_171 , & V_178 [ V_321 ] ) ;
}
if ( V_90 == V_157 )
return;
V_171 -> V_185 = 0 ;
V_171 -> ctime = V_322 ;
V_171 -> V_176 = 1 ;
V_171 -> V_28 = V_90 ;
V_171 -> V_102 = 0 ;
}
void F_106 ( int V_323 , long V_116 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_171 ;
if ( V_323 )
V_323 = V_118 ;
else
V_323 = V_119 ;
V_171 = F_48 ( V_53 , V_323 , V_116 ) ;
if ( ! V_171 )
return;
if ( V_171 -> V_176 && V_171 -> V_28 == V_29 )
F_100 ( V_171 , V_53 ) ;
V_171 -> V_176 = 0 ;
V_171 -> V_27 = V_171 -> V_90 == V_29 ? ~ 0ULL : 0 ;
if ( ! F_42 ( & V_171 -> V_194 ) )
F_103 ( & V_171 -> V_194 ) ;
if ( V_171 -> V_199 ) {
struct V_7 * V_324 = V_171 -> V_199 ;
V_171 -> V_199 = NULL ;
F_64 ( V_171 ) ;
V_53 -> V_7 = V_324 ;
} else {
F_49 ( V_171 ) ;
F_14 ( V_171 , NULL , 0 ) ;
F_56 ( V_171 ) ;
V_171 -> V_192 = NULL ;
V_171 -> V_193 = NULL ;
V_171 -> V_306 = 0 ;
V_171 -> V_310 = 0 ;
V_171 -> V_302 = 0 ;
V_171 -> type = 0 ;
V_171 -> V_300 [ 0 ] = - 1 ;
if ( V_171 -> V_90 != V_29 ) {
F_18 ( V_171 -> V_153 ) ;
V_171 -> V_153 = NULL ;
}
V_53 -> V_7 = V_171 ;
}
}
static inline void F_107 ( const struct V_325 * V_325 )
{
#ifdef F_15
struct V_7 * V_171 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
int V_41 ;
if ( F_11 ( F_108 ( & V_325 -> V_326 ) ) )
return;
V_171 = V_95 -> V_7 ;
V_33 = V_171 -> V_34 ;
V_41 = V_171 -> V_36 ;
F_38 () ;
V_31 = F_109 ( V_325 ) ;
F_40 () ;
if ( ! V_31 )
return;
if ( F_11 ( F_10 ( V_171 , V_31 ) ) )
return;
if ( F_4 ( ! F_12 ( V_171 ) ) ) {
F_50 ( V_327 L_80 ) ;
F_9 ( V_171 ) ;
F_16 ( V_31 ) ;
F_14 ( V_171 , V_33 , V_41 ) ;
return;
}
F_10 ( V_171 , V_31 ) ;
#endif
}
static void F_110 ( const struct V_189 * V_189 )
{
#ifdef F_15
struct V_7 * V_171 ;
struct V_32 * V_33 ;
const struct V_189 * V_328 , * V_329 ;
struct V_30 * V_330 ;
unsigned long V_331 ;
int V_41 ;
V_171 = V_95 -> V_7 ;
V_33 = V_171 -> V_34 ;
V_41 = V_171 -> V_36 ;
V_332:
V_330 = NULL ;
V_328 = V_189 ;
F_38 () ;
V_331 = F_111 ( & V_333 ) ;
for(; ; ) {
struct V_325 * V_325 = V_328 -> V_334 ;
if ( V_325 && F_4 ( ! F_108 ( & V_325 -> V_326 ) ) ) {
struct V_30 * V_31 ;
V_31 = F_109 ( V_325 ) ;
if ( V_31 ) {
if ( F_4 ( ! F_10 ( V_171 , V_31 ) ) ) {
V_330 = V_31 ;
break;
}
}
}
V_329 = V_328 -> V_335 ;
if ( V_329 == V_328 )
break;
V_328 = V_329 ;
}
if ( F_4 ( F_112 ( & V_333 , V_331 ) || V_330 ) ) {
F_40 () ;
if ( ! V_330 ) {
F_14 ( V_171 , V_33 , V_41 ) ;
goto V_332;
}
F_16 ( V_330 ) ;
if ( F_12 ( V_171 ) ) {
F_14 ( V_171 , V_33 , V_41 ) ;
goto V_332;
}
F_50 ( V_327
L_80 ) ;
F_14 ( V_171 , V_33 , V_41 ) ;
F_9 ( V_171 ) ;
return;
}
F_40 () ;
#endif
}
static struct V_23 * F_113 ( struct V_7 * V_171 ,
unsigned char type )
{
struct V_23 * V_336 ;
if ( V_171 -> V_183 < V_337 ) {
V_336 = & V_171 -> V_338 [ V_171 -> V_183 ] ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
} else {
V_336 = F_13 ( sizeof( * V_336 ) , V_339 ) ;
if ( ! V_336 )
return NULL ;
V_336 -> V_187 = true ;
}
V_336 -> V_25 = ( unsigned long ) - 1 ;
V_336 -> type = type ;
F_114 ( & V_336 -> V_164 , & V_171 -> V_195 ) ;
V_171 -> V_183 ++ ;
#if V_180
V_171 -> V_182 ++ ;
#endif
return V_336 ;
}
struct V_340 *
F_115 ( const T_7 char * V_341 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_23 * V_3 ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( V_3 -> V_46 -> V_341 == V_341 )
return V_3 -> V_46 ;
}
return NULL ;
}
void F_116 ( struct V_340 * V_46 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_23 * V_3 ;
if ( ! V_171 -> V_176 ) {
#if V_180 == 2
F_50 ( V_184 L_81 ,
__FILE__ , __LINE__ , V_171 -> V_185 , V_46 ) ;
F_51 () ;
#endif
return;
}
#if V_180
F_105 ( ! V_46 -> V_46 ) ;
#endif
V_3 = F_113 ( V_171 , V_342 ) ;
if ( ! V_3 )
return;
V_3 -> V_46 = V_46 ;
V_3 -> V_291 = V_292 ;
V_3 -> V_186 = true ;
V_46 -> V_336 = V_3 ;
if ( ! V_171 -> V_188 . V_189 )
F_117 ( V_95 -> V_343 , & V_171 -> V_188 ) ;
}
void F_118 ( struct V_340 * V_46 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
F_105 ( ! V_171 ) ;
if ( ! V_171 -> V_176 ) {
#if V_180 == 2
F_50 ( V_184 L_82 ,
__FILE__ , __LINE__ , V_171 -> V_185 , V_46 ) ;
if ( V_171 -> V_183 ) {
struct V_23 * V_3 ;
int V_92 ;
F_8 (n, &context->names_list, list)
F_50 ( V_184 L_83 , V_92 ,
V_3 -> V_46 , V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
#endif
F_54 ( V_46 ) ;
}
#if V_180
else {
++ V_171 -> V_181 ;
if ( V_171 -> V_181 > V_171 -> V_183 ) {
F_50 ( V_184 L_84
L_85
L_86 ,
__FILE__ , __LINE__ ,
V_171 -> V_185 , V_171 -> V_9 ,
V_171 -> V_176 , V_46 -> V_46 ,
V_171 -> V_183 , V_171 -> V_181 ) ;
F_51 () ;
}
}
#endif
}
static inline int F_119 ( struct V_23 * V_46 , const struct V_189 * V_189 )
{
struct V_344 V_345 ;
int V_49 ;
if ( ! V_189 )
return 0 ;
V_49 = F_120 ( V_189 , & V_345 ) ;
if ( V_49 )
return V_49 ;
V_46 -> V_244 . V_245 = V_345 . V_245 ;
V_46 -> V_244 . V_247 = V_345 . V_247 ;
V_46 -> V_244 . V_248 = ! ! ( V_345 . V_346 & V_347 ) ;
V_46 -> V_249 = ( V_345 . V_346 & V_348 ) >> V_349 ;
return 0 ;
}
static void F_121 ( struct V_23 * V_46 , const struct V_189 * V_189 ,
const struct V_325 * V_325 )
{
V_46 -> V_25 = V_325 -> V_350 ;
V_46 -> V_121 = V_325 -> V_351 -> V_352 ;
V_46 -> V_24 = V_325 -> V_353 ;
V_46 -> V_45 = V_325 -> V_354 ;
V_46 -> V_51 = V_325 -> V_355 ;
V_46 -> V_122 = V_325 -> V_356 ;
F_122 ( V_325 , & V_46 -> V_142 ) ;
F_119 ( V_46 , V_189 ) ;
}
void F_123 ( struct V_340 * V_46 , const struct V_189 * V_189 ,
unsigned int V_329 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
const struct V_325 * V_325 = V_189 -> V_334 ;
struct V_23 * V_3 ;
if ( ! V_171 -> V_176 )
return;
if ( ! V_46 )
goto V_357;
#if V_180
F_105 ( ! V_46 -> V_46 ) ;
#endif
V_3 = V_46 -> V_336 ;
if ( V_3 ) {
if ( V_329 ) {
if ( V_3 -> type == V_358 ||
V_3 -> type == V_342 )
goto V_359;
} else {
if ( V_3 -> type != V_358 )
goto V_359;
}
}
F_124 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> V_46 -> V_46 != V_46 -> V_46 )
continue;
if ( V_329 ) {
if ( V_3 -> type == V_358 ||
V_3 -> type == V_342 )
goto V_359;
} else {
if ( V_3 -> type != V_358 )
goto V_359;
}
}
V_357:
V_3 = F_113 ( V_171 , V_360 ) ;
if ( ! V_3 )
return;
V_359:
if ( V_329 ) {
V_3 -> V_291 = V_3 -> V_46 ? F_125 ( V_3 -> V_46 -> V_46 ) : V_292 ;
V_3 -> type = V_358 ;
} else {
V_3 -> V_291 = V_292 ;
V_3 -> type = V_360 ;
}
F_110 ( V_189 ) ;
F_121 ( V_3 , V_189 , V_325 ) ;
}
void F_126 ( const struct V_325 * V_329 ,
const struct V_189 * V_189 ,
const unsigned char type )
{
struct V_7 * V_171 = V_95 -> V_7 ;
const struct V_325 * V_325 = V_189 -> V_334 ;
const char * V_361 = V_189 -> V_362 . V_46 ;
struct V_23 * V_3 , * V_363 = NULL , * V_364 = NULL ;
if ( ! V_171 -> V_176 )
return;
if ( V_325 )
F_107 ( V_325 ) ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != V_358 )
continue;
if ( V_3 -> V_25 == V_329 -> V_350 &&
! F_127 ( V_361 , V_3 -> V_46 -> V_46 , V_3 -> V_291 ) ) {
V_363 = V_3 ;
break;
}
}
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != type )
continue;
if ( V_363 && ( V_3 -> V_46 != V_363 -> V_46 ) )
continue;
if ( ! strcmp ( V_361 , V_3 -> V_46 -> V_46 ) ||
! F_127 ( V_361 , V_3 -> V_46 -> V_46 ,
V_363 ?
V_363 -> V_291 :
V_292 ) ) {
V_364 = V_3 ;
break;
}
}
if ( ! V_363 ) {
V_3 = F_113 ( V_171 , V_358 ) ;
if ( ! V_3 )
return;
F_121 ( V_3 , NULL , V_329 ) ;
}
if ( ! V_364 ) {
V_364 = F_113 ( V_171 , type ) ;
if ( ! V_364 )
return;
if ( V_363 ) {
V_364 -> V_46 = V_363 -> V_46 ;
V_364 -> V_291 = V_292 ;
V_364 -> V_186 = false ;
}
}
if ( V_325 )
F_121 ( V_364 , V_189 , V_325 ) ;
else
V_364 -> V_25 = ( unsigned long ) - 1 ;
}
int F_128 ( struct V_7 * V_8 ,
struct V_365 * V_366 , unsigned int * V_185 )
{
if ( ! V_8 -> V_176 )
return 0 ;
if ( ! V_8 -> V_185 )
V_8 -> V_185 = F_129 () ;
V_366 -> V_274 = V_8 -> ctime . V_274 ;
V_366 -> V_275 = V_8 -> ctime . V_275 ;
* V_185 = V_8 -> V_185 ;
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
return 1 ;
}
int F_130 ( T_2 V_62 )
{
struct V_52 * V_367 = V_95 ;
struct V_7 * V_171 = V_367 -> V_7 ;
unsigned int V_213 ;
#ifdef F_131
if ( F_132 ( V_367 -> V_62 ) )
return - V_368 ;
#else
if ( ! F_133 ( V_369 ) )
return - V_368 ;
#endif
V_213 = F_134 ( & V_370 ) ;
if ( V_171 && V_171 -> V_176 ) {
struct V_201 * V_202 ;
V_202 = F_82 ( NULL , V_39 , V_371 ) ;
if ( V_202 ) {
F_67 ( V_202 , L_87
L_88
L_89 ,
V_367 -> V_100 ,
F_74 ( & V_212 , F_135 ( V_367 ) ) ,
F_74 ( & V_212 , V_367 -> V_62 ) ,
F_74 ( & V_212 , V_62 ) ,
V_367 -> V_213 , V_213 ) ;
F_83 ( V_202 ) ;
}
}
V_367 -> V_213 = V_213 ;
V_367 -> V_62 = V_62 ;
return 0 ;
}
void F_136 ( int V_262 , T_1 V_24 , struct V_280 * V_263 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
if ( V_263 )
memcpy ( & V_171 -> V_261 . V_263 , V_263 , sizeof( struct V_280 ) ) ;
else
memset ( & V_171 -> V_261 . V_263 , 0 , sizeof( struct V_280 ) ) ;
V_171 -> V_261 . V_262 = V_262 ;
V_171 -> V_261 . V_24 = V_24 ;
V_171 -> type = V_260 ;
}
void F_137 ( T_9 V_270 , T_6 V_271 , unsigned int V_272 ,
const struct V_365 * V_273 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_365 * V_33 = & V_171 -> V_269 . V_273 ;
if ( V_273 )
memcpy ( V_33 , V_273 , sizeof( struct V_365 ) ) ;
else
memset ( V_33 , 0 , sizeof( struct V_365 ) ) ;
V_171 -> V_269 . V_270 = V_270 ;
V_171 -> V_269 . V_271 = V_271 ;
V_171 -> V_269 . V_272 = V_272 ;
V_171 -> type = V_268 ;
}
void F_138 ( T_9 V_270 , const struct V_372 * V_373 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
if ( V_373 )
V_171 -> V_277 . V_278 = V_373 -> V_278 ;
else
V_171 -> V_277 . V_278 = 0 ;
V_171 -> V_277 . V_270 = V_270 ;
V_171 -> type = V_276 ;
}
void F_139 ( T_9 V_270 , struct V_280 * V_282 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_281 . V_270 = V_270 ;
V_171 -> V_281 . V_282 = * V_282 ;
V_171 -> type = V_279 ;
}
void F_140 ( struct V_374 * V_375 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_144 . V_45 = V_375 -> V_45 ;
V_171 -> V_144 . V_51 = V_375 -> V_51 ;
V_171 -> V_144 . V_24 = V_375 -> V_24 ;
V_171 -> V_144 . V_254 = 0 ;
F_141 ( V_375 , & V_171 -> V_144 . V_142 ) ;
V_171 -> type = V_143 ;
}
void F_142 ( unsigned long V_256 , T_10 V_45 , T_11 V_51 , T_1 V_24 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_144 . V_256 = V_256 ;
V_171 -> V_144 . V_257 = V_45 ;
V_171 -> V_144 . V_258 = V_51 ;
V_171 -> V_144 . V_259 = V_24 ;
V_171 -> V_144 . V_254 = 1 ;
}
int F_143 ( struct V_376 * V_377 )
{
struct V_236 * V_378 ;
struct V_7 * V_171 = V_95 -> V_7 ;
V_378 = F_59 ( sizeof( * V_378 ) , V_39 ) ;
if ( ! V_378 )
return - V_197 ;
V_378 -> V_239 = V_377 -> V_239 ;
V_378 -> V_379 = V_377 -> V_379 ;
V_378 -> V_208 = V_377 -> V_208 ;
V_378 -> V_328 . type = V_235 ;
V_378 -> V_328 . V_38 = V_171 -> V_192 ;
V_171 -> V_192 = ( void * ) V_378 ;
return 0 ;
}
void F_144 ( int V_252 , unsigned long * args )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> type = V_251 ;
V_171 -> V_253 . V_252 = V_252 ;
memcpy ( V_171 -> V_253 . args , args , V_252 * sizeof( unsigned long ) ) ;
}
void F_145 ( int V_380 , int V_381 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_300 [ 0 ] = V_380 ;
V_171 -> V_300 [ 1 ] = V_381 ;
}
int F_146 ( int V_203 , void * V_382 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
if ( ! V_171 -> V_200 ) {
void * V_33 = F_59 ( sizeof( struct V_383 ) , V_39 ) ;
if ( ! V_33 )
return - V_197 ;
V_171 -> V_200 = V_33 ;
}
V_171 -> V_302 = V_203 ;
memcpy ( V_171 -> V_200 , V_382 , V_203 ) ;
return 0 ;
}
void F_147 ( struct V_52 * V_366 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_306 = V_366 -> V_100 ;
V_171 -> V_307 = F_148 ( V_366 ) ;
V_171 -> V_308 = F_135 ( V_366 ) ;
V_171 -> V_309 = F_149 ( V_366 ) ;
F_34 ( V_366 , & V_171 -> V_310 ) ;
memcpy ( V_171 -> V_311 , V_366 -> V_206 , V_384 ) ;
}
int F_150 ( int V_385 , struct V_52 * V_366 )
{
struct V_304 * V_386 ;
struct V_52 * V_53 = V_95 ;
struct V_7 * V_8 = V_53 -> V_7 ;
T_2 V_45 = F_151 () , V_387 = F_135 ( V_366 ) ;
if ( V_165 && V_366 -> V_166 == V_165 ) {
if ( V_385 == V_388 || V_385 == V_389 || V_385 == V_390 || V_385 == V_391 ) {
V_392 = V_53 -> V_100 ;
if ( F_132 ( V_53 -> V_62 ) )
V_393 = V_53 -> V_62 ;
else
V_393 = V_45 ;
F_34 ( V_53 , & V_394 ) ;
}
if ( ! V_395 || F_152 () )
return 0 ;
}
if ( ! V_8 -> V_306 ) {
V_8 -> V_306 = V_366 -> V_166 ;
V_8 -> V_307 = F_148 ( V_366 ) ;
V_8 -> V_308 = V_387 ;
V_8 -> V_309 = F_149 ( V_366 ) ;
F_34 ( V_366 , & V_8 -> V_310 ) ;
memcpy ( V_8 -> V_311 , V_366 -> V_206 , V_384 ) ;
return 0 ;
}
V_386 = ( void * ) V_8 -> V_193 ;
if ( ! V_386 || V_386 -> V_305 == V_396 ) {
V_386 = F_13 ( sizeof( * V_386 ) , V_154 ) ;
if ( ! V_386 )
return - V_197 ;
V_386 -> V_328 . type = V_218 ;
V_386 -> V_328 . V_38 = V_8 -> V_193 ;
V_8 -> V_193 = ( void * ) V_386 ;
}
F_105 ( V_386 -> V_305 >= V_396 ) ;
V_386 -> V_306 [ V_386 -> V_305 ] = V_366 -> V_166 ;
V_386 -> V_307 [ V_386 -> V_305 ] = F_148 ( V_366 ) ;
V_386 -> V_308 [ V_386 -> V_305 ] = V_387 ;
V_386 -> V_309 [ V_386 -> V_305 ] = F_149 ( V_366 ) ;
F_34 ( V_366 , & V_386 -> V_310 [ V_386 -> V_305 ] ) ;
memcpy ( V_386 -> V_311 [ V_386 -> V_305 ] , V_366 -> V_206 , V_384 ) ;
V_386 -> V_305 ++ ;
return 0 ;
}
int F_153 ( struct V_376 * V_377 ,
const struct V_54 * V_397 , const struct V_54 * V_398 )
{
struct V_296 * V_378 ;
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_344 V_399 ;
struct V_189 * V_189 ;
V_378 = F_59 ( sizeof( * V_378 ) , V_39 ) ;
if ( ! V_378 )
return - V_197 ;
V_378 -> V_328 . type = V_295 ;
V_378 -> V_328 . V_38 = V_171 -> V_192 ;
V_171 -> V_192 = ( void * ) V_378 ;
V_189 = F_154 ( V_377 -> V_400 -> V_401 ) ;
F_120 ( V_189 , & V_399 ) ;
F_155 ( V_189 ) ;
V_378 -> V_244 . V_245 = V_399 . V_245 ;
V_378 -> V_244 . V_247 = V_399 . V_247 ;
V_378 -> V_244 . V_248 = ! ! ( V_399 . V_346 & V_347 ) ;
V_378 -> V_249 = ( V_399 . V_346 & V_348 ) >> V_349 ;
V_378 -> V_298 . V_245 = V_398 -> V_402 ;
V_378 -> V_298 . V_247 = V_398 -> V_403 ;
V_378 -> V_298 . V_285 = V_398 -> V_404 ;
V_378 -> V_299 . V_245 = V_397 -> V_402 ;
V_378 -> V_299 . V_247 = V_397 -> V_403 ;
V_378 -> V_299 . V_285 = V_397 -> V_404 ;
return 0 ;
}
void F_156 ( T_5 V_100 ,
const struct V_54 * V_397 , const struct V_54 * V_398 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_284 . V_100 = V_100 ;
V_171 -> V_284 . V_241 . V_285 = V_397 -> V_404 ;
V_171 -> V_284 . V_241 . V_247 = V_397 -> V_404 ;
V_171 -> V_284 . V_241 . V_245 = V_397 -> V_402 ;
V_171 -> type = V_283 ;
}
void F_157 ( int V_288 , int V_1 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_287 . V_288 = V_288 ;
V_171 -> V_287 . V_1 = V_1 ;
V_171 -> type = V_286 ;
}
static void F_158 ( struct V_201 * V_202 , char * V_405 , long V_406 )
{
T_2 V_217 , V_45 ;
T_3 V_51 ;
unsigned int V_213 ;
V_217 = F_148 ( V_95 ) ;
V_213 = F_149 ( V_95 ) ;
F_159 ( & V_45 , & V_51 ) ;
F_67 ( V_202 , L_90 ,
F_74 ( & V_212 , V_217 ) ,
F_74 ( & V_212 , V_45 ) ,
F_75 ( & V_212 , V_51 ) ,
V_213 ) ;
F_65 ( V_202 ) ;
F_67 ( V_202 , L_91 , V_95 -> V_100 ) ;
F_77 ( V_202 , V_95 -> V_206 ) ;
F_67 ( V_202 , L_92 ) ;
F_91 ( V_202 , V_405 ) ;
F_67 ( V_202 , L_93 , V_406 ) ;
}
void F_160 ( long V_406 )
{
struct V_201 * V_202 ;
if ( ! V_319 )
return;
if ( V_406 == V_407 )
return;
V_202 = F_82 ( NULL , V_39 , V_408 ) ;
F_158 ( V_202 , L_94 , V_406 ) ;
F_83 ( V_202 ) ;
}
void F_161 ( unsigned long V_409 , long V_406 , int V_410 )
{
struct V_201 * V_202 ;
V_202 = F_82 ( NULL , V_39 , V_408 ) ;
F_158 ( V_202 , L_95 , V_406 ) ;
F_67 ( V_202 , L_96 , V_409 ) ;
F_67 ( V_202 , L_97 , F_162 () ) ;
F_67 ( V_202 , L_98 , F_163 ( V_95 ) ) ;
F_67 ( V_202 , L_99 , V_410 ) ;
F_83 ( V_202 ) ;
}
struct V_163 * F_164 ( void )
{
struct V_7 * V_8 = V_95 -> V_7 ;
if ( F_11 ( ! V_8 || ! V_8 -> V_176 ) )
return NULL ;
return & V_8 -> V_194 ;
}
