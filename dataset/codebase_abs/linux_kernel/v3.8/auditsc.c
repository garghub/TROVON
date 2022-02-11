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
F_49 ( V_171 ) ;
F_14 ( V_171 , NULL , 0 ) ;
F_17 ( V_171 ) ;
F_56 ( V_171 ) ;
F_18 ( V_171 -> V_153 ) ;
F_18 ( V_171 -> V_199 ) ;
F_18 ( V_171 ) ;
}
void F_65 ( struct V_200 * V_201 )
{
char * V_8 = NULL ;
unsigned V_202 ;
int error ;
T_4 V_94 ;
F_34 ( V_95 , & V_94 ) ;
if ( ! V_94 )
return;
error = F_66 ( V_94 , & V_8 , & V_202 ) ;
if ( error ) {
if ( error != - V_203 )
goto V_204;
return;
}
F_67 ( V_201 , L_8 , V_8 ) ;
F_68 ( V_8 , V_202 ) ;
return;
V_204:
F_69 ( L_9 ) ;
return;
}
void F_70 ( struct V_200 * V_201 , struct V_52 * V_53 )
{
const struct V_54 * V_54 ;
char V_46 [ sizeof( V_53 -> V_205 ) ] ;
struct V_206 * V_207 = V_53 -> V_207 ;
char * V_208 ;
if ( ! V_201 )
return;
V_54 = F_71 () ;
F_72 ( & V_53 -> V_209 -> V_210 ) ;
if ( V_53 -> signal && V_53 -> signal -> V_208 )
V_208 = V_53 -> signal -> V_208 -> V_46 ;
else
V_208 = L_10 ;
F_73 ( & V_53 -> V_209 -> V_210 ) ;
F_67 ( V_201 ,
L_11
L_12
L_13 ,
F_30 () ,
V_53 -> V_100 ,
F_74 ( & V_211 , V_53 -> V_62 ) ,
F_74 ( & V_211 , V_54 -> V_45 ) ,
F_75 ( & V_211 , V_54 -> V_51 ) ,
F_74 ( & V_211 , V_54 -> V_58 ) ,
F_74 ( & V_211 , V_54 -> V_64 ) ,
F_74 ( & V_211 , V_54 -> V_68 ) ,
F_75 ( & V_211 , V_54 -> V_60 ) ,
F_75 ( & V_211 , V_54 -> V_66 ) ,
F_75 ( & V_211 , V_54 -> V_70 ) ,
V_53 -> V_212 , V_208 ) ;
F_76 ( V_46 , V_53 ) ;
F_67 ( V_201 , L_14 ) ;
F_77 ( V_201 , V_46 ) ;
if ( V_207 ) {
F_78 ( & V_207 -> V_213 ) ;
if ( V_207 -> V_214 )
F_79 ( V_201 , L_15 , & V_207 -> V_214 -> V_215 ) ;
F_80 ( & V_207 -> V_213 ) ;
}
F_65 ( V_201 ) ;
}
static int F_81 ( struct V_7 * V_171 , T_5 V_100 ,
T_2 V_216 , T_2 V_45 , unsigned int V_212 ,
T_4 V_94 , char * V_205 )
{
struct V_200 * V_201 ;
char * V_8 = NULL ;
T_4 V_202 ;
int V_49 = 0 ;
V_201 = F_82 ( V_171 , V_39 , V_217 ) ;
if ( ! V_201 )
return V_49 ;
F_67 ( V_201 , L_16 , V_100 ,
F_74 ( & V_211 , V_216 ) ,
F_74 ( & V_211 , V_45 ) , V_212 ) ;
if ( F_66 ( V_94 , & V_8 , & V_202 ) ) {
F_67 ( V_201 , L_17 ) ;
V_49 = 1 ;
} else {
F_67 ( V_201 , L_18 , V_8 ) ;
F_68 ( V_8 , V_202 ) ;
}
F_67 ( V_201 , L_19 ) ;
F_77 ( V_201 , V_205 ) ;
F_83 ( V_201 ) ;
return V_49 ;
}
static int F_84 ( struct V_7 * V_171 ,
struct V_200 * * V_201 ,
int V_218 ,
T_6 * V_219 ,
const char T_7 * V_33 ,
char * V_220 )
{
char V_221 [ 12 ] ;
const char T_7 * V_222 = V_33 ;
T_6 V_223 = snprintf ( V_221 , 12 , L_20 , V_218 ) + 5 ;
T_6 V_202 , V_224 , V_225 ;
T_6 V_226 = V_227 ;
unsigned int V_92 , V_228 = 0 , V_229 = 0 ;
int V_230 ;
V_224 = V_202 = F_85 ( V_33 , V_231 ) - 1 ;
if ( F_4 ( ( V_202 == - 1 ) || V_202 > V_231 - 1 ) ) {
F_86 ( 1 ) ;
F_87 ( V_232 , V_95 , 0 ) ;
return - 1 ;
}
do {
if ( V_224 > V_227 )
V_225 = V_227 ;
else
V_225 = V_224 ;
V_230 = F_88 ( V_220 , V_222 , V_225 ) ;
if ( V_230 ) {
F_86 ( 1 ) ;
F_87 ( V_232 , V_95 , 0 ) ;
return - 1 ;
}
V_220 [ V_225 ] = '\0' ;
V_228 = F_89 ( V_220 , V_225 ) ;
if ( V_228 ) {
V_226 = V_227 / 2 ;
break;
}
V_224 -= V_225 ;
V_222 += V_225 ;
} while ( V_224 > 0 );
V_224 = V_202 ;
if ( V_202 > V_226 )
V_229 = 1 ;
for ( V_92 = 0 ; V_224 > 0 ; V_92 ++ ) {
int V_233 ;
if ( V_224 > V_226 )
V_225 = V_226 ;
else
V_225 = V_224 ;
V_233 = V_227 - V_223 - * V_219 ;
if ( V_228 )
V_233 -= ( V_225 * 2 ) ;
else
V_233 -= V_225 ;
if ( V_233 < 0 ) {
* V_219 = 0 ;
F_83 ( * V_201 ) ;
* V_201 = F_82 ( V_171 , V_39 , V_234 ) ;
if ( ! * V_201 )
return 0 ;
}
if ( ( V_92 == 0 ) && ( V_229 ) )
F_67 ( * V_201 , L_21 , V_218 ,
V_228 ? 2 * V_202 : V_202 ) ;
if ( V_202 >= V_226 )
V_230 = F_88 ( V_220 , V_33 , V_225 ) ;
else
V_230 = 0 ;
if ( V_230 ) {
F_86 ( 1 ) ;
F_87 ( V_232 , V_95 , 0 ) ;
return - 1 ;
}
V_220 [ V_225 ] = '\0' ;
F_67 ( * V_201 , L_22 , V_218 ) ;
if ( V_229 )
F_67 ( * V_201 , L_23 , V_92 ) ;
F_67 ( * V_201 , L_24 ) ;
if ( V_228 )
F_90 ( * V_201 , V_220 , V_225 ) ;
else
F_91 ( * V_201 , V_220 ) ;
V_33 += V_225 ;
V_224 -= V_225 ;
* V_219 += V_223 ;
if ( V_228 )
* V_219 += V_225 * 2 ;
else
* V_219 += V_225 ;
}
return V_202 + 1 ;
}
static void F_92 ( struct V_7 * V_171 ,
struct V_200 * * V_201 ,
struct V_235 * V_236 )
{
int V_92 , V_202 ;
T_6 V_219 = 0 ;
const char T_7 * V_33 ;
char * V_220 ;
if ( V_236 -> V_207 != V_95 -> V_207 )
return;
V_33 = ( const char T_7 * ) V_236 -> V_207 -> V_237 ;
F_67 ( * V_201 , L_25 , V_236 -> V_238 ) ;
V_220 = F_59 ( V_227 + 1 , V_39 ) ;
if ( ! V_220 ) {
F_69 ( L_26 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_236 -> V_238 ; V_92 ++ ) {
V_202 = F_84 ( V_171 , V_201 , V_92 ,
& V_219 , V_33 , V_220 ) ;
if ( V_202 <= 0 )
break;
V_33 += V_202 ;
}
F_18 ( V_220 ) ;
}
static void F_93 ( struct V_200 * V_201 , char * V_239 , T_8 * V_240 )
{
int V_92 ;
F_67 ( V_201 , L_27 , V_239 ) ;
F_94 (i) {
F_67 ( V_201 , L_28 , V_240 -> V_240 [ ( V_241 - 1 ) - V_92 ] ) ;
}
}
static void F_95 ( struct V_200 * V_201 , struct V_23 * V_46 )
{
T_8 * V_242 = & V_46 -> V_243 . V_244 ;
T_8 * V_245 = & V_46 -> V_243 . V_246 ;
int log = 0 ;
if ( ! F_96 ( * V_242 ) ) {
F_93 ( V_201 , L_29 , V_242 ) ;
log = 1 ;
}
if ( ! F_96 ( * V_245 ) ) {
F_93 ( V_201 , L_30 , V_245 ) ;
log = 1 ;
}
if ( log )
F_67 ( V_201 , L_31 , V_46 -> V_243 . V_247 , V_46 -> V_248 ) ;
}
static void F_97 ( struct V_7 * V_171 , int * V_249 )
{
struct V_200 * V_201 ;
int V_92 ;
V_201 = F_82 ( V_171 , V_39 , V_171 -> type ) ;
if ( ! V_201 )
return;
switch ( V_171 -> type ) {
case V_250 : {
int V_251 = V_171 -> V_252 . V_251 ;
F_67 ( V_201 , L_32 , V_251 ) ;
for ( V_92 = 0 ; V_92 < V_251 ; V_92 ++ )
F_67 ( V_201 , L_33 , V_92 ,
V_171 -> V_252 . args [ V_92 ] ) ;
break; }
case V_143 : {
T_4 V_142 = V_171 -> V_144 . V_142 ;
F_67 ( V_201 , L_34 ,
F_74 ( & V_211 , V_171 -> V_144 . V_45 ) ,
F_75 ( & V_211 , V_171 -> V_144 . V_51 ) ,
V_171 -> V_144 . V_24 ) ;
if ( V_142 ) {
char * V_8 = NULL ;
T_4 V_202 ;
if ( F_66 ( V_142 , & V_8 , & V_202 ) ) {
F_67 ( V_201 , L_35 , V_142 ) ;
* V_249 = 1 ;
} else {
F_67 ( V_201 , L_18 , V_8 ) ;
F_68 ( V_8 , V_202 ) ;
}
}
if ( V_171 -> V_144 . V_253 ) {
F_83 ( V_201 ) ;
V_201 = F_82 ( V_171 , V_39 ,
V_254 ) ;
if ( F_4 ( ! V_201 ) )
return;
F_67 ( V_201 ,
L_36 ,
V_171 -> V_144 . V_255 ,
V_171 -> V_144 . V_256 ,
V_171 -> V_144 . V_257 ,
V_171 -> V_144 . V_258 ) ;
}
break; }
case V_259 : {
F_67 ( V_201 ,
L_37
L_38 ,
V_171 -> V_260 . V_261 , V_171 -> V_260 . V_24 ,
V_171 -> V_260 . V_262 . V_263 ,
V_171 -> V_260 . V_262 . V_264 ,
V_171 -> V_260 . V_262 . V_265 ,
V_171 -> V_260 . V_262 . V_266 ) ;
break; }
case V_267 : {
F_67 ( V_201 ,
L_39
L_40 ,
V_171 -> V_268 . V_269 ,
V_171 -> V_268 . V_270 ,
V_171 -> V_268 . V_271 ,
V_171 -> V_268 . V_272 . V_273 ,
V_171 -> V_268 . V_272 . V_274 ) ;
break; }
case V_275 : {
F_67 ( V_201 , L_41 ,
V_171 -> V_276 . V_269 ,
V_171 -> V_276 . V_277 ) ;
break; }
case V_278 : {
struct V_279 * V_262 = & V_171 -> V_280 . V_281 ;
F_67 ( V_201 ,
L_42
L_43 ,
V_171 -> V_280 . V_269 ,
V_262 -> V_263 , V_262 -> V_264 ,
V_262 -> V_265 , V_262 -> V_266 ) ;
break; }
case V_282 : {
F_67 ( V_201 , L_44 , V_171 -> V_283 . V_100 ) ;
F_93 ( V_201 , L_45 , & V_171 -> V_283 . V_240 . V_246 ) ;
F_93 ( V_201 , L_46 , & V_171 -> V_283 . V_240 . V_244 ) ;
F_93 ( V_201 , L_47 , & V_171 -> V_283 . V_240 . V_284 ) ;
break; }
case V_285 : {
F_67 ( V_201 , L_48 , V_171 -> V_286 . V_287 ,
V_171 -> V_286 . V_1 ) ;
break; }
}
F_83 ( V_201 ) ;
}
static void F_98 ( struct V_7 * V_171 , struct V_23 * V_3 ,
int V_288 , int * V_249 )
{
struct V_200 * V_201 ;
V_201 = F_82 ( V_171 , V_39 , V_289 ) ;
if ( ! V_201 )
return;
F_67 ( V_201 , L_49 , V_288 ) ;
if ( V_3 -> V_46 ) {
switch ( V_3 -> V_290 ) {
case V_291 :
F_67 ( V_201 , L_50 ) ;
F_77 ( V_201 , V_3 -> V_46 -> V_46 ) ;
break;
case 0 :
F_79 ( V_201 , L_50 , & V_171 -> V_188 ) ;
break;
default:
F_67 ( V_201 , L_50 ) ;
F_99 ( V_201 , V_3 -> V_46 -> V_46 ,
V_3 -> V_290 ) ;
}
} else
F_67 ( V_201 , L_51 ) ;
if ( V_3 -> V_25 != ( unsigned long ) - 1 ) {
F_67 ( V_201 , L_52
L_53
L_54 ,
V_3 -> V_25 ,
F_31 ( V_3 -> V_121 ) ,
F_32 ( V_3 -> V_121 ) ,
V_3 -> V_24 ,
F_74 ( & V_211 , V_3 -> V_45 ) ,
F_75 ( & V_211 , V_3 -> V_51 ) ,
F_31 ( V_3 -> V_122 ) ,
F_32 ( V_3 -> V_122 ) ) ;
}
if ( V_3 -> V_142 != 0 ) {
char * V_8 = NULL ;
T_4 V_202 ;
if ( F_66 (
V_3 -> V_142 , & V_8 , & V_202 ) ) {
F_67 ( V_201 , L_35 , V_3 -> V_142 ) ;
* V_249 = 2 ;
} else {
F_67 ( V_201 , L_18 , V_8 ) ;
F_68 ( V_8 , V_202 ) ;
}
}
F_95 ( V_201 , V_3 ) ;
F_83 ( V_201 ) ;
}
static void F_100 ( struct V_7 * V_171 , struct V_52 * V_53 )
{
int V_92 , V_249 = 0 ;
struct V_200 * V_201 ;
struct V_191 * V_192 ;
struct V_23 * V_3 ;
V_171 -> V_112 = V_53 -> V_112 ;
V_201 = F_82 ( V_171 , V_39 , V_292 ) ;
if ( ! V_201 )
return;
F_67 ( V_201 , L_55 ,
V_171 -> V_10 , V_171 -> V_9 ) ;
if ( V_171 -> V_112 != V_293 )
F_67 ( V_201 , L_56 , V_171 -> V_112 ) ;
if ( V_171 -> V_115 )
F_67 ( V_201 , L_57 ,
( V_171 -> V_115 == V_118 ) ? L_58 : L_59 ,
V_171 -> V_116 ) ;
F_67 ( V_201 ,
L_60 ,
V_171 -> V_19 [ 0 ] ,
V_171 -> V_19 [ 1 ] ,
V_171 -> V_19 [ 2 ] ,
V_171 -> V_19 [ 3 ] ,
V_171 -> V_183 ) ;
F_70 ( V_201 , V_53 ) ;
F_101 ( V_201 , V_171 -> V_153 ) ;
F_83 ( V_201 ) ;
for ( V_192 = V_171 -> V_192 ; V_192 ; V_192 = V_192 -> V_38 ) {
V_201 = F_82 ( V_171 , V_39 , V_192 -> type ) ;
if ( ! V_201 )
continue;
switch ( V_192 -> type ) {
case V_234 : {
struct V_235 * V_236 = ( void * ) V_192 ;
F_92 ( V_171 , & V_201 , V_236 ) ;
break; }
case V_294 : {
struct V_295 * V_296 = ( void * ) V_192 ;
F_67 ( V_201 , L_61 , V_296 -> V_248 ) ;
F_93 ( V_201 , L_62 , & V_296 -> V_243 . V_244 ) ;
F_93 ( V_201 , L_63 , & V_296 -> V_243 . V_246 ) ;
F_67 ( V_201 , L_64 , V_296 -> V_243 . V_247 ) ;
F_93 ( V_201 , L_65 , & V_296 -> V_297 . V_244 ) ;
F_93 ( V_201 , L_66 , & V_296 -> V_297 . V_246 ) ;
F_93 ( V_201 , L_67 , & V_296 -> V_297 . V_284 ) ;
F_93 ( V_201 , L_68 , & V_296 -> V_298 . V_244 ) ;
F_93 ( V_201 , L_69 , & V_296 -> V_298 . V_246 ) ;
F_93 ( V_201 , L_70 , & V_296 -> V_298 . V_284 ) ;
break; }
}
F_83 ( V_201 ) ;
}
if ( V_171 -> type )
F_97 ( V_171 , & V_249 ) ;
if ( V_171 -> V_299 [ 0 ] >= 0 ) {
V_201 = F_82 ( V_171 , V_39 , V_300 ) ;
if ( V_201 ) {
F_67 ( V_201 , L_71 ,
V_171 -> V_299 [ 0 ] , V_171 -> V_299 [ 1 ] ) ;
F_83 ( V_201 ) ;
}
}
if ( V_171 -> V_301 ) {
V_201 = F_82 ( V_171 , V_39 , V_302 ) ;
if ( V_201 ) {
F_67 ( V_201 , L_72 ) ;
F_90 ( V_201 , ( void * ) V_171 -> V_199 ,
V_171 -> V_301 ) ;
F_83 ( V_201 ) ;
}
}
for ( V_192 = V_171 -> V_193 ; V_192 ; V_192 = V_192 -> V_38 ) {
struct V_303 * V_296 = ( void * ) V_192 ;
for ( V_92 = 0 ; V_92 < V_296 -> V_304 ; V_92 ++ )
if ( F_81 ( V_171 , V_296 -> V_305 [ V_92 ] ,
V_296 -> V_306 [ V_92 ] ,
V_296 -> V_307 [ V_92 ] ,
V_296 -> V_308 [ V_92 ] ,
V_296 -> V_309 [ V_92 ] ,
V_296 -> V_310 [ V_92 ] ) )
V_249 = 1 ;
}
if ( V_171 -> V_305 &&
F_81 ( V_171 , V_171 -> V_305 ,
V_171 -> V_306 , V_171 -> V_307 ,
V_171 -> V_308 ,
V_171 -> V_309 , V_171 -> V_310 ) )
V_249 = 1 ;
if ( V_171 -> V_188 . V_189 && V_171 -> V_188 . V_190 ) {
V_201 = F_82 ( V_171 , V_39 , V_311 ) ;
if ( V_201 ) {
F_79 ( V_201 , L_73 , & V_171 -> V_188 ) ;
F_83 ( V_201 ) ;
}
}
V_92 = 0 ;
F_8 (n, &context->names_list, list)
F_98 ( V_171 , V_3 , V_92 ++ , & V_249 ) ;
V_201 = F_82 ( V_171 , V_39 , V_312 ) ;
if ( V_201 )
F_83 ( V_201 ) ;
if ( V_249 )
F_69 ( L_74 ) ;
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
unsigned long V_313 , unsigned long V_314 ,
unsigned long V_315 , unsigned long V_316 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_171 = V_53 -> V_7 ;
enum V_89 V_90 ;
if ( ! V_171 )
return;
F_105 ( V_171 -> V_176 || V_171 -> V_183 ) ;
if ( ! V_317 )
return;
V_171 -> V_10 = V_10 ;
V_171 -> V_9 = V_9 ;
V_171 -> V_19 [ 0 ] = V_313 ;
V_171 -> V_19 [ 1 ] = V_314 ;
V_171 -> V_19 [ 2 ] = V_315 ;
V_171 -> V_19 [ 3 ] = V_316 ;
V_90 = V_171 -> V_90 ;
V_171 -> V_177 = ! V_318 ;
if ( ! V_171 -> V_177 && V_90 == V_162 ) {
V_171 -> V_27 = 0 ;
V_90 = F_41 ( V_53 , V_171 , & V_178 [ V_319 ] ) ;
}
if ( V_90 == V_157 )
return;
V_171 -> V_185 = 0 ;
V_171 -> ctime = V_320 ;
V_171 -> V_176 = 1 ;
V_171 -> V_28 = V_90 ;
V_171 -> V_102 = 0 ;
}
void F_106 ( int V_321 , long V_116 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_171 ;
if ( V_321 )
V_321 = V_118 ;
else
V_321 = V_119 ;
V_171 = F_48 ( V_53 , V_321 , V_116 ) ;
if ( ! V_171 )
return;
if ( V_171 -> V_176 && V_171 -> V_28 == V_29 )
F_100 ( V_171 , V_53 ) ;
V_171 -> V_176 = 0 ;
V_171 -> V_27 = V_171 -> V_90 == V_29 ? ~ 0ULL : 0 ;
if ( ! F_42 ( & V_171 -> V_194 ) )
F_103 ( & V_171 -> V_194 ) ;
F_49 ( V_171 ) ;
F_14 ( V_171 , NULL , 0 ) ;
F_56 ( V_171 ) ;
V_171 -> V_192 = NULL ;
V_171 -> V_193 = NULL ;
V_171 -> V_305 = 0 ;
V_171 -> V_309 = 0 ;
V_171 -> V_301 = 0 ;
V_171 -> type = 0 ;
V_171 -> V_299 [ 0 ] = - 1 ;
if ( V_171 -> V_90 != V_29 ) {
F_18 ( V_171 -> V_153 ) ;
V_171 -> V_153 = NULL ;
}
V_53 -> V_7 = V_171 ;
}
static inline void F_107 ( const struct V_322 * V_322 )
{
#ifdef F_15
struct V_7 * V_171 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
int V_41 ;
if ( F_11 ( F_108 ( & V_322 -> V_323 ) ) )
return;
V_171 = V_95 -> V_7 ;
V_33 = V_171 -> V_34 ;
V_41 = V_171 -> V_36 ;
F_38 () ;
V_31 = F_109 ( V_322 ) ;
F_40 () ;
if ( ! V_31 )
return;
if ( F_11 ( F_10 ( V_171 , V_31 ) ) )
return;
if ( F_4 ( ! F_12 ( V_171 ) ) ) {
F_50 ( V_324 L_75 ) ;
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
const struct V_189 * V_325 , * V_326 ;
struct V_30 * V_327 ;
unsigned long V_328 ;
int V_41 ;
V_171 = V_95 -> V_7 ;
V_33 = V_171 -> V_34 ;
V_41 = V_171 -> V_36 ;
V_329:
V_327 = NULL ;
V_325 = V_189 ;
F_38 () ;
V_328 = F_111 ( & V_330 ) ;
for(; ; ) {
struct V_322 * V_322 = V_325 -> V_331 ;
if ( V_322 && F_4 ( ! F_108 ( & V_322 -> V_323 ) ) ) {
struct V_30 * V_31 ;
V_31 = F_109 ( V_322 ) ;
if ( V_31 ) {
if ( F_4 ( ! F_10 ( V_171 , V_31 ) ) ) {
V_327 = V_31 ;
break;
}
}
}
V_326 = V_325 -> V_332 ;
if ( V_326 == V_325 )
break;
V_325 = V_326 ;
}
if ( F_4 ( F_112 ( & V_330 , V_328 ) || V_327 ) ) {
F_40 () ;
if ( ! V_327 ) {
F_14 ( V_171 , V_33 , V_41 ) ;
goto V_329;
}
F_16 ( V_327 ) ;
if ( F_12 ( V_171 ) ) {
F_14 ( V_171 , V_33 , V_41 ) ;
goto V_329;
}
F_50 ( V_324
L_75 ) ;
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
struct V_23 * V_333 ;
if ( V_171 -> V_183 < V_334 ) {
V_333 = & V_171 -> V_335 [ V_171 -> V_183 ] ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
} else {
V_333 = F_13 ( sizeof( * V_333 ) , V_336 ) ;
if ( ! V_333 )
return NULL ;
V_333 -> V_187 = true ;
}
V_333 -> V_25 = ( unsigned long ) - 1 ;
V_333 -> type = type ;
F_114 ( & V_333 -> V_164 , & V_171 -> V_195 ) ;
V_171 -> V_183 ++ ;
#if V_180
V_171 -> V_182 ++ ;
#endif
return V_333 ;
}
struct V_337 *
F_115 ( const T_7 char * V_338 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_23 * V_3 ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( V_3 -> V_46 -> V_338 == V_338 )
return V_3 -> V_46 ;
}
return NULL ;
}
void F_116 ( struct V_337 * V_46 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_23 * V_3 ;
if ( ! V_171 -> V_176 ) {
#if V_180 == 2
F_50 ( V_184 L_76 ,
__FILE__ , __LINE__ , V_171 -> V_185 , V_46 ) ;
F_51 () ;
#endif
return;
}
#if V_180
F_105 ( ! V_46 -> V_46 ) ;
#endif
V_3 = F_113 ( V_171 , V_339 ) ;
if ( ! V_3 )
return;
V_3 -> V_46 = V_46 ;
V_3 -> V_290 = V_291 ;
V_3 -> V_186 = true ;
V_46 -> V_333 = V_3 ;
if ( ! V_171 -> V_188 . V_189 )
F_117 ( V_95 -> V_340 , & V_171 -> V_188 ) ;
}
void F_118 ( struct V_337 * V_46 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
F_105 ( ! V_171 ) ;
if ( ! V_171 -> V_176 ) {
#if V_180 == 2
F_50 ( V_184 L_77 ,
__FILE__ , __LINE__ , V_171 -> V_185 , V_46 ) ;
if ( V_171 -> V_183 ) {
struct V_23 * V_3 ;
int V_92 ;
F_8 (n, &context->names_list, list)
F_50 ( V_184 L_78 , V_92 ,
V_3 -> V_46 , V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
#endif
F_54 ( V_46 ) ;
}
#if V_180
else {
++ V_171 -> V_181 ;
if ( V_171 -> V_181 > V_171 -> V_183 ) {
F_50 ( V_184 L_79
L_80
L_81 ,
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
struct V_341 V_342 ;
int V_49 ;
if ( ! V_189 )
return 0 ;
V_49 = F_120 ( V_189 , & V_342 ) ;
if ( V_49 )
return V_49 ;
V_46 -> V_243 . V_244 = V_342 . V_244 ;
V_46 -> V_243 . V_246 = V_342 . V_246 ;
V_46 -> V_243 . V_247 = ! ! ( V_342 . V_343 & V_344 ) ;
V_46 -> V_248 = ( V_342 . V_343 & V_345 ) >> V_346 ;
return 0 ;
}
static void F_121 ( struct V_23 * V_46 , const struct V_189 * V_189 ,
const struct V_322 * V_322 )
{
V_46 -> V_25 = V_322 -> V_347 ;
V_46 -> V_121 = V_322 -> V_348 -> V_349 ;
V_46 -> V_24 = V_322 -> V_350 ;
V_46 -> V_45 = V_322 -> V_351 ;
V_46 -> V_51 = V_322 -> V_352 ;
V_46 -> V_122 = V_322 -> V_353 ;
F_122 ( V_322 , & V_46 -> V_142 ) ;
F_119 ( V_46 , V_189 ) ;
}
void F_123 ( struct V_337 * V_46 , const struct V_189 * V_189 ,
unsigned int V_326 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
const struct V_322 * V_322 = V_189 -> V_331 ;
struct V_23 * V_3 ;
if ( ! V_171 -> V_176 )
return;
if ( ! V_46 )
goto V_354;
#if V_180
F_105 ( ! V_46 -> V_46 ) ;
#endif
V_3 = V_46 -> V_333 ;
if ( V_3 ) {
if ( V_326 ) {
if ( V_3 -> type == V_355 ||
V_3 -> type == V_339 )
goto V_356;
} else {
if ( V_3 -> type != V_355 )
goto V_356;
}
}
F_124 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> V_46 -> V_46 != V_46 -> V_46 )
continue;
if ( V_326 ) {
if ( V_3 -> type == V_355 ||
V_3 -> type == V_339 )
goto V_356;
} else {
if ( V_3 -> type != V_355 )
goto V_356;
}
}
V_354:
V_3 = F_113 ( V_171 , V_357 ) ;
if ( ! V_3 )
return;
V_356:
if ( V_326 ) {
V_3 -> V_290 = V_3 -> V_46 ? F_125 ( V_3 -> V_46 -> V_46 ) : V_291 ;
V_3 -> type = V_355 ;
} else {
V_3 -> V_290 = V_291 ;
V_3 -> type = V_357 ;
}
F_110 ( V_189 ) ;
F_121 ( V_3 , V_189 , V_322 ) ;
}
void F_126 ( const struct V_322 * V_326 ,
const struct V_189 * V_189 ,
const unsigned char type )
{
struct V_7 * V_171 = V_95 -> V_7 ;
const struct V_322 * V_322 = V_189 -> V_331 ;
const char * V_358 = V_189 -> V_359 . V_46 ;
struct V_23 * V_3 , * V_360 = NULL , * V_361 = NULL ;
if ( ! V_171 -> V_176 )
return;
if ( V_322 )
F_107 ( V_322 ) ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != V_355 )
continue;
if ( V_3 -> V_25 == V_326 -> V_347 &&
! F_127 ( V_358 , V_3 -> V_46 -> V_46 , V_3 -> V_290 ) ) {
V_360 = V_3 ;
break;
}
}
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != type )
continue;
if ( V_360 && ( V_3 -> V_46 != V_360 -> V_46 ) )
continue;
if ( ! strcmp ( V_358 , V_3 -> V_46 -> V_46 ) ||
! F_127 ( V_358 , V_3 -> V_46 -> V_46 ,
V_360 ?
V_360 -> V_290 :
V_291 ) ) {
V_361 = V_3 ;
break;
}
}
if ( ! V_360 ) {
V_3 = F_113 ( V_171 , V_355 ) ;
if ( ! V_3 )
return;
F_121 ( V_3 , NULL , V_326 ) ;
}
if ( ! V_361 ) {
V_361 = F_113 ( V_171 , type ) ;
if ( ! V_361 )
return;
if ( V_360 ) {
V_361 -> V_46 = V_360 -> V_46 ;
V_361 -> V_290 = V_291 ;
V_361 -> V_186 = false ;
}
}
if ( V_322 )
F_121 ( V_361 , V_189 , V_322 ) ;
else
V_361 -> V_25 = ( unsigned long ) - 1 ;
}
int F_128 ( struct V_7 * V_8 ,
struct V_362 * V_363 , unsigned int * V_185 )
{
if ( ! V_8 -> V_176 )
return 0 ;
if ( ! V_8 -> V_185 )
V_8 -> V_185 = F_129 () ;
V_363 -> V_273 = V_8 -> ctime . V_273 ;
V_363 -> V_274 = V_8 -> ctime . V_274 ;
* V_185 = V_8 -> V_185 ;
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
return 1 ;
}
int F_130 ( T_2 V_62 )
{
struct V_52 * V_364 = V_95 ;
struct V_7 * V_171 = V_364 -> V_7 ;
unsigned int V_212 ;
#ifdef F_131
if ( F_132 ( V_364 -> V_62 ) )
return - V_365 ;
#else
if ( ! F_133 ( V_366 ) )
return - V_365 ;
#endif
V_212 = F_134 ( & V_367 ) ;
if ( V_171 && V_171 -> V_176 ) {
struct V_200 * V_201 ;
V_201 = F_82 ( NULL , V_39 , V_368 ) ;
if ( V_201 ) {
F_67 ( V_201 , L_82
L_83
L_84 ,
V_364 -> V_100 ,
F_74 ( & V_211 , F_135 ( V_364 ) ) ,
F_74 ( & V_211 , V_364 -> V_62 ) ,
F_74 ( & V_211 , V_62 ) ,
V_364 -> V_212 , V_212 ) ;
F_83 ( V_201 ) ;
}
}
V_364 -> V_212 = V_212 ;
V_364 -> V_62 = V_62 ;
return 0 ;
}
void F_136 ( int V_261 , T_1 V_24 , struct V_279 * V_262 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
if ( V_262 )
memcpy ( & V_171 -> V_260 . V_262 , V_262 , sizeof( struct V_279 ) ) ;
else
memset ( & V_171 -> V_260 . V_262 , 0 , sizeof( struct V_279 ) ) ;
V_171 -> V_260 . V_261 = V_261 ;
V_171 -> V_260 . V_24 = V_24 ;
V_171 -> type = V_259 ;
}
void F_137 ( T_9 V_269 , T_6 V_270 , unsigned int V_271 ,
const struct V_362 * V_272 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_362 * V_33 = & V_171 -> V_268 . V_272 ;
if ( V_272 )
memcpy ( V_33 , V_272 , sizeof( struct V_362 ) ) ;
else
memset ( V_33 , 0 , sizeof( struct V_362 ) ) ;
V_171 -> V_268 . V_269 = V_269 ;
V_171 -> V_268 . V_270 = V_270 ;
V_171 -> V_268 . V_271 = V_271 ;
V_171 -> type = V_267 ;
}
void F_138 ( T_9 V_269 , const struct V_369 * V_370 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
if ( V_370 )
V_171 -> V_276 . V_277 = V_370 -> V_277 ;
else
V_171 -> V_276 . V_277 = 0 ;
V_171 -> V_276 . V_269 = V_269 ;
V_171 -> type = V_275 ;
}
void F_139 ( T_9 V_269 , struct V_279 * V_281 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_280 . V_269 = V_269 ;
V_171 -> V_280 . V_281 = * V_281 ;
V_171 -> type = V_278 ;
}
void F_140 ( struct V_371 * V_372 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_144 . V_45 = V_372 -> V_45 ;
V_171 -> V_144 . V_51 = V_372 -> V_51 ;
V_171 -> V_144 . V_24 = V_372 -> V_24 ;
V_171 -> V_144 . V_253 = 0 ;
F_141 ( V_372 , & V_171 -> V_144 . V_142 ) ;
V_171 -> type = V_143 ;
}
void F_142 ( unsigned long V_255 , T_10 V_45 , T_11 V_51 , T_1 V_24 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_144 . V_255 = V_255 ;
V_171 -> V_144 . V_256 = V_45 ;
V_171 -> V_144 . V_257 = V_51 ;
V_171 -> V_144 . V_258 = V_24 ;
V_171 -> V_144 . V_253 = 1 ;
}
int F_143 ( struct V_373 * V_374 )
{
struct V_235 * V_375 ;
struct V_7 * V_171 = V_95 -> V_7 ;
V_375 = F_59 ( sizeof( * V_375 ) , V_39 ) ;
if ( ! V_375 )
return - V_197 ;
V_375 -> V_238 = V_374 -> V_238 ;
V_375 -> V_376 = V_374 -> V_376 ;
V_375 -> V_207 = V_374 -> V_207 ;
V_375 -> V_325 . type = V_234 ;
V_375 -> V_325 . V_38 = V_171 -> V_192 ;
V_171 -> V_192 = ( void * ) V_375 ;
return 0 ;
}
void F_144 ( int V_251 , unsigned long * args )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> type = V_250 ;
V_171 -> V_252 . V_251 = V_251 ;
memcpy ( V_171 -> V_252 . args , args , V_251 * sizeof( unsigned long ) ) ;
}
void F_145 ( int V_377 , int V_378 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_299 [ 0 ] = V_377 ;
V_171 -> V_299 [ 1 ] = V_378 ;
}
int F_146 ( int V_202 , void * V_379 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
if ( ! V_171 -> V_199 ) {
void * V_33 = F_59 ( sizeof( struct V_380 ) , V_39 ) ;
if ( ! V_33 )
return - V_197 ;
V_171 -> V_199 = V_33 ;
}
V_171 -> V_301 = V_202 ;
memcpy ( V_171 -> V_199 , V_379 , V_202 ) ;
return 0 ;
}
void F_147 ( struct V_52 * V_363 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_305 = V_363 -> V_100 ;
V_171 -> V_306 = F_148 ( V_363 ) ;
V_171 -> V_307 = F_135 ( V_363 ) ;
V_171 -> V_308 = F_149 ( V_363 ) ;
F_34 ( V_363 , & V_171 -> V_309 ) ;
memcpy ( V_171 -> V_310 , V_363 -> V_205 , V_381 ) ;
}
int F_150 ( int V_382 , struct V_52 * V_363 )
{
struct V_303 * V_383 ;
struct V_52 * V_53 = V_95 ;
struct V_7 * V_8 = V_53 -> V_7 ;
T_2 V_45 = F_151 () , V_384 = F_135 ( V_363 ) ;
if ( V_165 && V_363 -> V_166 == V_165 ) {
if ( V_382 == V_385 || V_382 == V_386 || V_382 == V_387 || V_382 == V_388 ) {
V_389 = V_53 -> V_100 ;
if ( F_132 ( V_53 -> V_62 ) )
V_390 = V_53 -> V_62 ;
else
V_390 = V_45 ;
F_34 ( V_53 , & V_391 ) ;
}
if ( ! V_392 || F_152 () )
return 0 ;
}
if ( ! V_8 -> V_305 ) {
V_8 -> V_305 = V_363 -> V_166 ;
V_8 -> V_306 = F_148 ( V_363 ) ;
V_8 -> V_307 = V_384 ;
V_8 -> V_308 = F_149 ( V_363 ) ;
F_34 ( V_363 , & V_8 -> V_309 ) ;
memcpy ( V_8 -> V_310 , V_363 -> V_205 , V_381 ) ;
return 0 ;
}
V_383 = ( void * ) V_8 -> V_193 ;
if ( ! V_383 || V_383 -> V_304 == V_393 ) {
V_383 = F_13 ( sizeof( * V_383 ) , V_154 ) ;
if ( ! V_383 )
return - V_197 ;
V_383 -> V_325 . type = V_217 ;
V_383 -> V_325 . V_38 = V_8 -> V_193 ;
V_8 -> V_193 = ( void * ) V_383 ;
}
F_105 ( V_383 -> V_304 >= V_393 ) ;
V_383 -> V_305 [ V_383 -> V_304 ] = V_363 -> V_166 ;
V_383 -> V_306 [ V_383 -> V_304 ] = F_148 ( V_363 ) ;
V_383 -> V_307 [ V_383 -> V_304 ] = V_384 ;
V_383 -> V_308 [ V_383 -> V_304 ] = F_149 ( V_363 ) ;
F_34 ( V_363 , & V_383 -> V_309 [ V_383 -> V_304 ] ) ;
memcpy ( V_383 -> V_310 [ V_383 -> V_304 ] , V_363 -> V_205 , V_381 ) ;
V_383 -> V_304 ++ ;
return 0 ;
}
int F_153 ( struct V_373 * V_374 ,
const struct V_54 * V_394 , const struct V_54 * V_395 )
{
struct V_295 * V_375 ;
struct V_7 * V_171 = V_95 -> V_7 ;
struct V_341 V_396 ;
struct V_189 * V_189 ;
V_375 = F_59 ( sizeof( * V_375 ) , V_39 ) ;
if ( ! V_375 )
return - V_197 ;
V_375 -> V_325 . type = V_294 ;
V_375 -> V_325 . V_38 = V_171 -> V_192 ;
V_171 -> V_192 = ( void * ) V_375 ;
V_189 = F_154 ( V_374 -> V_397 -> V_398 ) ;
F_120 ( V_189 , & V_396 ) ;
F_155 ( V_189 ) ;
V_375 -> V_243 . V_244 = V_396 . V_244 ;
V_375 -> V_243 . V_246 = V_396 . V_246 ;
V_375 -> V_243 . V_247 = ! ! ( V_396 . V_343 & V_344 ) ;
V_375 -> V_248 = ( V_396 . V_343 & V_345 ) >> V_346 ;
V_375 -> V_297 . V_244 = V_395 -> V_399 ;
V_375 -> V_297 . V_246 = V_395 -> V_400 ;
V_375 -> V_297 . V_284 = V_395 -> V_401 ;
V_375 -> V_298 . V_244 = V_394 -> V_399 ;
V_375 -> V_298 . V_246 = V_394 -> V_400 ;
V_375 -> V_298 . V_284 = V_394 -> V_401 ;
return 0 ;
}
void F_156 ( T_5 V_100 ,
const struct V_54 * V_394 , const struct V_54 * V_395 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_283 . V_100 = V_100 ;
V_171 -> V_283 . V_240 . V_284 = V_394 -> V_401 ;
V_171 -> V_283 . V_240 . V_246 = V_394 -> V_401 ;
V_171 -> V_283 . V_240 . V_244 = V_394 -> V_399 ;
V_171 -> type = V_282 ;
}
void F_157 ( int V_287 , int V_1 )
{
struct V_7 * V_171 = V_95 -> V_7 ;
V_171 -> V_286 . V_287 = V_287 ;
V_171 -> V_286 . V_1 = V_1 ;
V_171 -> type = V_285 ;
}
static void F_158 ( struct V_200 * V_201 )
{
T_2 V_216 , V_45 ;
T_3 V_51 ;
unsigned int V_212 ;
V_216 = F_148 ( V_95 ) ;
V_212 = F_149 ( V_95 ) ;
F_159 ( & V_45 , & V_51 ) ;
F_67 ( V_201 , L_85 ,
F_74 ( & V_211 , V_216 ) ,
F_74 ( & V_211 , V_45 ) ,
F_75 ( & V_211 , V_51 ) ,
V_212 ) ;
F_65 ( V_201 ) ;
F_67 ( V_201 , L_86 , V_95 -> V_100 ) ;
F_77 ( V_201 , V_95 -> V_205 ) ;
}
static void F_160 ( struct V_200 * V_201 , char * V_402 , long V_403 )
{
F_158 ( V_201 ) ;
F_67 ( V_201 , L_87 ) ;
F_91 ( V_201 , V_402 ) ;
F_67 ( V_201 , L_88 , V_403 ) ;
}
void F_161 ( long V_403 )
{
struct V_200 * V_201 ;
if ( ! V_317 )
return;
if ( V_403 == V_404 )
return;
V_201 = F_82 ( NULL , V_39 , V_405 ) ;
if ( F_4 ( ! V_201 ) )
return;
F_160 ( V_201 , L_89 , V_403 ) ;
F_83 ( V_201 ) ;
}
void F_162 ( unsigned long V_406 , long V_403 , int V_407 )
{
struct V_200 * V_201 ;
V_201 = F_82 ( NULL , V_39 , V_408 ) ;
if ( F_4 ( ! V_201 ) )
return;
F_158 ( V_201 ) ;
F_67 ( V_201 , L_88 , V_403 ) ;
F_67 ( V_201 , L_90 , V_406 ) ;
F_67 ( V_201 , L_91 , F_163 () ) ;
F_67 ( V_201 , L_92 , F_164 ( V_95 ) ) ;
F_67 ( V_201 , L_93 , V_407 ) ;
F_83 ( V_201 ) ;
}
struct V_163 * F_165 ( void )
{
struct V_7 * V_8 = V_95 -> V_7 ;
if ( F_11 ( ! V_8 || ! V_8 -> V_176 ) )
return NULL ;
return & V_8 -> V_194 ;
}
