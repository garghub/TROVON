static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned V_4 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_4 = V_2 -> V_5 ;
switch ( F_3 ( V_2 -> V_6 , V_4 ) ) {
case 0 :
if ( ( V_3 & V_7 ) &&
F_4 ( V_8 , V_4 ) )
return 1 ;
if ( ( V_3 & V_9 ) &&
F_4 ( V_10 , V_4 ) )
return 1 ;
if ( ( V_3 & V_11 ) &&
F_4 ( V_12 , V_4 ) )
return 1 ;
return 0 ;
case 1 :
if ( ( V_3 & V_7 ) &&
F_4 ( V_13 , V_4 ) )
return 1 ;
if ( ( V_3 & V_9 ) &&
F_4 ( V_14 , V_4 ) )
return 1 ;
if ( ( V_3 & V_11 ) &&
F_4 ( V_15 , V_4 ) )
return 1 ;
return 0 ;
case 2 :
return V_3 & F_5 ( V_2 -> V_16 [ 1 ] ) ;
case 3 :
return V_3 & F_5 ( V_2 -> V_16 [ 2 ] ) ;
case 4 :
return ( ( V_3 & V_7 ) && V_2 -> V_16 [ 0 ] == V_17 ) ;
case 5 :
return V_3 & V_18 ;
default:
return 0 ;
}
}
static int F_6 ( struct V_1 * V_2 , int V_19 )
{
struct V_20 * V_4 ;
T_1 V_21 = ( T_1 ) V_19 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
F_7 (n, &ctx->names_list, list) {
if ( ( V_4 -> V_22 != V_23 ) &&
( ( V_4 -> V_21 & V_24 ) == V_21 ) )
return 1 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_25 ) {
V_2 -> V_25 = 1 ;
V_2 -> V_26 = V_27 ;
}
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
int V_33 = V_2 -> V_34 ;
if ( F_10 ( V_33 ) ) {
V_31 -> V_35 [ -- V_33 ] = V_29 ;
V_2 -> V_34 = V_33 ;
return 1 ;
}
if ( ! V_31 )
return 0 ;
V_31 = V_31 -> V_36 ;
if ( V_31 ) {
V_31 -> V_35 [ 30 ] = V_29 ;
V_2 -> V_32 = V_31 ;
V_2 -> V_34 = 30 ;
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
V_2 -> V_32 = F_12 ( sizeof( struct V_30 ) , V_37 ) ;
if ( ! V_2 -> V_32 ) {
V_2 -> V_32 = V_31 ;
return 0 ;
}
if ( V_31 )
V_31 -> V_36 = V_2 -> V_32 ;
else
V_2 -> V_38 = V_2 -> V_32 ;
V_2 -> V_34 = 31 ;
return 1 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_30 * V_31 , int V_39 )
{
#ifdef F_14
struct V_30 * V_40 ;
int V_4 ;
if ( ! V_31 ) {
V_31 = V_2 -> V_38 ;
V_39 = 31 ;
if ( ! V_31 )
return;
}
V_4 = V_39 ;
for ( V_40 = V_31 ; V_40 != V_2 -> V_32 ; V_40 = V_40 -> V_36 , V_4 = 31 ) {
while ( V_4 -- ) {
F_15 ( V_40 -> V_35 [ V_4 ] ) ;
V_40 -> V_35 [ V_4 ] = NULL ;
}
}
while ( V_4 -- > V_2 -> V_34 ) {
F_15 ( V_40 -> V_35 [ V_4 ] ) ;
V_40 -> V_35 [ V_4 ] = NULL ;
}
V_2 -> V_32 = V_31 ;
V_2 -> V_34 = V_39 ;
#endif
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_30 * V_31 , * V_40 ;
for ( V_31 = V_2 -> V_38 ; V_31 ; V_31 = V_40 ) {
V_40 = V_31 -> V_36 ;
F_17 ( V_31 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
#ifdef F_14
struct V_30 * V_31 ;
int V_4 ;
if ( ! V_42 )
return 0 ;
for ( V_31 = V_2 -> V_38 ; V_31 != V_2 -> V_32 ; V_31 = V_31 -> V_36 ) {
for ( V_4 = 0 ; V_4 < 31 ; V_4 ++ )
if ( F_19 ( V_31 -> V_35 [ V_4 ] , V_42 ) )
return 1 ;
}
if ( V_31 ) {
for ( V_4 = V_2 -> V_34 ; V_4 < 31 ; V_4 ++ )
if ( F_19 ( V_31 -> V_35 [ V_4 ] , V_42 ) )
return 1 ;
}
#endif
return 0 ;
}
static int F_20 ( T_2 V_43 ,
struct V_20 * V_44 ,
struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_20 * V_4 ;
int V_47 ;
if ( V_44 ) {
V_47 = F_21 ( V_43 , V_46 -> V_48 , V_44 -> V_43 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
V_47 = F_21 ( V_43 , V_46 -> V_48 , V_4 -> V_43 ) ;
if ( V_47 )
return V_47 ;
}
}
return 0 ;
}
static int F_22 ( T_3 V_49 ,
struct V_20 * V_44 ,
struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_20 * V_4 ;
int V_47 ;
if ( V_44 ) {
V_47 = F_23 ( V_49 , V_46 -> V_48 , V_44 -> V_49 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
V_47 = F_23 ( V_49 , V_46 -> V_48 , V_4 -> V_49 ) ;
if ( V_47 )
return V_47 ;
}
}
return 0 ;
}
static int F_24 ( struct V_50 * V_51 ,
const struct V_52 * V_52 ,
struct V_45 * V_46 ,
struct V_1 * V_2 ,
struct V_20 * V_44 )
{
switch ( V_46 -> V_19 ) {
case V_53 :
return F_20 ( V_52 -> V_43 , V_44 , V_46 , V_2 ) ;
case V_54 :
return F_22 ( V_52 -> V_49 , V_44 , V_46 , V_2 ) ;
case V_55 :
return F_20 ( V_52 -> V_56 , V_44 , V_46 , V_2 ) ;
case V_57 :
return F_22 ( V_52 -> V_58 , V_44 , V_46 , V_2 ) ;
case V_59 :
return F_20 ( V_51 -> V_60 , V_44 , V_46 , V_2 ) ;
case V_61 :
return F_20 ( V_52 -> V_62 , V_44 , V_46 , V_2 ) ;
case V_63 :
return F_22 ( V_52 -> V_64 , V_44 , V_46 , V_2 ) ;
case V_65 :
return F_20 ( V_52 -> V_66 , V_44 , V_46 , V_2 ) ;
case V_67 :
return F_22 ( V_52 -> V_68 , V_44 , V_46 , V_2 ) ;
case V_69 :
return F_21 ( V_52 -> V_43 , V_46 -> V_48 , V_51 -> V_60 ) ;
case V_70 :
return F_21 ( V_52 -> V_43 , V_46 -> V_48 , V_52 -> V_56 ) ;
case V_71 :
return F_21 ( V_52 -> V_43 , V_46 -> V_48 , V_52 -> V_62 ) ;
case V_72 :
return F_21 ( V_52 -> V_43 , V_46 -> V_48 , V_52 -> V_66 ) ;
case V_73 :
return F_21 ( V_51 -> V_60 , V_46 -> V_48 , V_52 -> V_56 ) ;
case V_74 :
return F_21 ( V_51 -> V_60 , V_46 -> V_48 , V_52 -> V_62 ) ;
case V_75 :
return F_21 ( V_51 -> V_60 , V_46 -> V_48 , V_52 -> V_66 ) ;
case V_76 :
return F_21 ( V_52 -> V_56 , V_46 -> V_48 , V_52 -> V_62 ) ;
case V_77 :
return F_21 ( V_52 -> V_56 , V_46 -> V_48 , V_52 -> V_66 ) ;
case V_78 :
return F_21 ( V_52 -> V_62 , V_46 -> V_48 , V_52 -> V_66 ) ;
case V_79 :
return F_23 ( V_52 -> V_49 , V_46 -> V_48 , V_52 -> V_58 ) ;
case V_80 :
return F_23 ( V_52 -> V_49 , V_46 -> V_48 , V_52 -> V_64 ) ;
case V_81 :
return F_23 ( V_52 -> V_49 , V_46 -> V_48 , V_52 -> V_68 ) ;
case V_82 :
return F_23 ( V_52 -> V_58 , V_46 -> V_48 , V_52 -> V_64 ) ;
case V_83 :
return F_23 ( V_52 -> V_58 , V_46 -> V_48 , V_52 -> V_68 ) ;
case V_84 :
return F_23 ( V_52 -> V_64 , V_46 -> V_48 , V_52 -> V_68 ) ;
default:
F_25 ( 1 , L_1 ) ;
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_50 * V_51 ,
struct V_85 * V_86 ,
struct V_1 * V_2 ,
struct V_20 * V_44 ,
enum V_87 * V_88 ,
bool V_89 )
{
const struct V_52 * V_52 ;
int V_90 , V_91 = 1 ;
T_4 V_92 ;
V_52 = F_27 ( V_51 -> V_52 , V_51 == V_93 || V_89 ) ;
for ( V_90 = 0 ; V_90 < V_86 -> V_94 ; V_90 ++ ) {
struct V_45 * V_46 = & V_86 -> V_95 [ V_90 ] ;
struct V_20 * V_4 ;
int V_96 = 0 ;
T_5 V_97 ;
switch ( V_46 -> type ) {
case V_98 :
V_97 = F_28 ( V_51 ) ;
V_96 = F_29 ( V_97 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_99 :
if ( V_2 ) {
if ( ! V_2 -> V_100 )
V_2 -> V_100 = F_30 ( V_51 ) ;
V_96 = F_29 ( V_2 -> V_100 , V_46 -> V_48 , V_46 -> V_19 ) ;
}
break;
case V_101 :
V_96 = F_31 ( V_51 , V_86 -> V_102 ) ;
break;
case V_103 :
V_96 = F_21 ( V_52 -> V_43 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_104 :
V_96 = F_21 ( V_52 -> V_56 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_105 :
V_96 = F_21 ( V_52 -> V_62 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_106 :
V_96 = F_21 ( V_52 -> V_66 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_107 :
V_96 = F_23 ( V_52 -> V_49 , V_46 -> V_48 , V_46 -> V_49 ) ;
if ( V_46 -> V_48 == V_108 ) {
if ( ! V_96 )
V_96 = F_32 ( V_46 -> V_49 ) ;
} else if ( V_46 -> V_48 == V_109 ) {
if ( V_96 )
V_96 = ! F_32 ( V_46 -> V_49 ) ;
}
break;
case V_110 :
V_96 = F_23 ( V_52 -> V_58 , V_46 -> V_48 , V_46 -> V_49 ) ;
if ( V_46 -> V_48 == V_108 ) {
if ( ! V_96 )
V_96 = F_33 ( V_46 -> V_49 ) ;
} else if ( V_46 -> V_48 == V_109 ) {
if ( V_96 )
V_96 = ! F_33 ( V_46 -> V_49 ) ;
}
break;
case V_111 :
V_96 = F_23 ( V_52 -> V_64 , V_46 -> V_48 , V_46 -> V_49 ) ;
break;
case V_112 :
V_96 = F_23 ( V_52 -> V_68 , V_46 -> V_48 , V_46 -> V_49 ) ;
break;
case V_113 :
V_96 = F_29 ( V_51 -> V_114 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_115 :
if ( V_2 )
V_96 = F_29 ( V_2 -> V_6 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_116 :
if ( V_2 && V_2 -> V_117 )
V_96 = F_29 ( V_2 -> V_118 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_119 :
if ( V_2 && V_2 -> V_117 ) {
if ( V_46 -> V_19 )
V_96 = F_29 ( V_2 -> V_117 , V_46 -> V_48 , V_120 ) ;
else
V_96 = F_29 ( V_2 -> V_117 , V_46 -> V_48 , V_121 ) ;
}
break;
case V_122 :
if ( V_44 ) {
if ( F_29 ( F_34 ( V_44 -> V_123 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_34 ( V_44 -> V_124 ) , V_46 -> V_48 , V_46 -> V_19 ) )
++ V_96 ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( F_34 ( V_4 -> V_123 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_34 ( V_4 -> V_124 ) , V_46 -> V_48 , V_46 -> V_19 ) ) {
++ V_96 ;
break;
}
}
}
break;
case V_125 :
if ( V_44 ) {
if ( F_29 ( F_35 ( V_44 -> V_123 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_35 ( V_44 -> V_124 ) , V_46 -> V_48 , V_46 -> V_19 ) )
++ V_96 ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( F_35 ( V_4 -> V_123 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_35 ( V_4 -> V_124 ) , V_46 -> V_48 , V_46 -> V_19 ) ) {
++ V_96 ;
break;
}
}
}
break;
case V_126 :
if ( V_44 )
V_96 = F_29 ( V_44 -> V_22 , V_46 -> V_48 , V_46 -> V_19 ) ;
else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( V_4 -> V_22 , V_46 -> V_48 , V_46 -> V_19 ) ) {
++ V_96 ;
break;
}
}
}
break;
case V_127 :
if ( V_44 ) {
V_96 = F_21 ( V_44 -> V_43 , V_46 -> V_48 , V_46 -> V_43 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_21 ( V_4 -> V_43 , V_46 -> V_48 , V_46 -> V_43 ) ) {
++ V_96 ;
break;
}
}
}
break;
case V_128 :
if ( V_44 ) {
V_96 = F_23 ( V_44 -> V_49 , V_46 -> V_48 , V_46 -> V_49 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_23 ( V_4 -> V_49 , V_46 -> V_48 , V_46 -> V_49 ) ) {
++ V_96 ;
break;
}
}
}
break;
case V_129 :
if ( V_44 )
V_96 = F_36 ( V_86 -> V_130 , V_44 -> V_22 , V_44 -> V_123 ) ;
break;
case V_131 :
if ( V_2 )
V_96 = F_18 ( V_2 , V_86 -> V_42 ) ;
break;
case V_132 :
V_96 = F_21 ( V_51 -> V_60 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_133 :
V_96 = F_29 ( F_37 ( V_51 ) , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
if ( V_46 -> V_139 ) {
if ( V_91 ) {
F_38 ( V_51 , & V_92 ) ;
V_91 = 0 ;
}
V_96 = F_39 ( V_92 , V_46 -> type ,
V_46 -> V_48 ,
V_46 -> V_139 ,
V_2 ) ;
}
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
if ( V_46 -> V_139 ) {
if ( V_44 ) {
V_96 = F_39 (
V_44 -> V_145 , V_46 -> type , V_46 -> V_48 ,
V_46 -> V_139 , V_2 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_39 ( V_4 -> V_145 , V_46 -> type ,
V_46 -> V_48 , V_46 -> V_139 ,
V_2 ) ) {
++ V_96 ;
break;
}
}
}
if ( ! V_2 || V_2 -> type != V_146 )
break;
if ( F_39 ( V_2 -> V_147 . V_145 ,
V_46 -> type , V_46 -> V_48 ,
V_46 -> V_139 , V_2 ) )
++ V_96 ;
}
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
if ( V_2 )
V_96 = F_29 ( V_2 -> V_16 [ V_46 -> type - V_148 ] , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_152 :
V_96 = 1 ;
break;
case V_153 :
V_96 = F_1 ( V_2 , V_46 -> V_19 ) ;
break;
case V_154 :
V_96 = F_6 ( V_2 , V_46 -> V_19 ) ;
break;
case V_155 :
V_96 = F_24 ( V_51 , V_52 , V_46 , V_2 , V_44 ) ;
break;
}
if ( ! V_96 )
return 0 ;
}
if ( V_2 ) {
if ( V_86 -> V_25 <= V_2 -> V_25 )
return 0 ;
if ( V_86 -> V_156 ) {
F_17 ( V_2 -> V_156 ) ;
V_2 -> V_156 = F_40 ( V_86 -> V_156 , V_157 ) ;
}
V_2 -> V_25 = V_86 -> V_25 ;
}
switch ( V_86 -> V_158 ) {
case V_159 : * V_88 = V_160 ; break;
case V_161 : * V_88 = V_27 ; break;
}
return 1 ;
}
static enum V_87 F_41 ( struct V_50 * V_51 , char * * V_162 )
{
struct V_163 * V_164 ;
enum V_87 V_88 ;
F_42 () ;
F_43 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_26 ( V_51 , & V_164 -> V_86 , NULL , NULL ,
& V_88 , true ) ) {
if ( V_88 == V_27 )
* V_162 = F_40 ( V_164 -> V_86 . V_156 , V_157 ) ;
F_44 () ;
return V_88 ;
}
}
F_44 () ;
return V_165 ;
}
static int F_45 ( const struct V_85 * V_86 , unsigned long V_19 )
{
int V_166 , V_167 ;
if ( V_19 > 0xffffffff )
return false ;
V_166 = F_46 ( V_19 ) ;
if ( V_166 >= V_168 )
return false ;
V_167 = F_47 ( V_19 ) ;
return V_86 -> V_3 [ V_166 ] & V_167 ;
}
static enum V_87 F_48 ( struct V_50 * V_51 ,
struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_163 * V_164 ;
enum V_87 V_88 ;
if ( V_171 && V_51 -> V_172 == V_171 )
return V_160 ;
F_42 () ;
if ( ! F_49 ( V_170 ) ) {
F_43 (e, list, list) {
if ( F_45 ( & V_164 -> V_86 , V_2 -> V_5 ) &&
F_26 ( V_51 , & V_164 -> V_86 , V_2 , NULL ,
& V_88 , false ) ) {
F_44 () ;
V_2 -> V_26 = V_88 ;
return V_88 ;
}
}
}
F_44 () ;
return V_165 ;
}
static int F_50 ( struct V_50 * V_51 ,
struct V_20 * V_4 ,
struct V_1 * V_2 ) {
int V_173 = F_51 ( ( T_4 ) V_4 -> V_22 ) ;
struct V_169 * V_170 = & V_174 [ V_173 ] ;
struct V_163 * V_164 ;
enum V_87 V_88 ;
if ( F_49 ( V_170 ) )
return 0 ;
F_43 (e, list, list) {
if ( F_45 ( & V_164 -> V_86 , V_2 -> V_5 ) &&
F_26 ( V_51 , & V_164 -> V_86 , V_2 , V_4 , & V_88 , false ) ) {
V_2 -> V_26 = V_88 ;
return 1 ;
}
}
return 0 ;
}
void F_52 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_20 * V_4 ;
if ( V_171 && V_51 -> V_172 == V_171 )
return;
F_42 () ;
F_7 (n, &ctx->names_list, list) {
if ( F_50 ( V_51 , V_4 , V_2 ) )
break;
}
F_44 () ;
}
static inline struct V_1 * F_53 ( struct V_50 * V_51 ,
int V_117 ,
long V_118 )
{
struct V_1 * V_175 = V_51 -> V_1 ;
if ( ! V_175 )
return NULL ;
V_175 -> V_117 = V_117 ;
if ( F_2 ( V_118 <= - V_176 ) &&
( V_118 >= - V_177 ) &&
( V_118 != - V_178 ) )
V_175 -> V_118 = - V_179 ;
else
V_175 -> V_118 = V_118 ;
if ( V_175 -> V_180 && ! V_175 -> V_181 ) {
F_48 ( V_51 , V_175 , & V_182 [ V_183 ] ) ;
F_52 ( V_51 , V_175 ) ;
}
V_51 -> V_1 = NULL ;
return V_175 ;
}
static inline void F_54 ( struct V_1 * V_175 )
{
F_17 ( V_175 -> V_184 . V_185 ) ;
V_175 -> V_184 . V_185 = NULL ;
V_175 -> V_184 . V_186 = 0 ;
}
static inline void F_55 ( struct V_1 * V_175 )
{
struct V_20 * V_4 , * V_36 ;
F_56 (n, next, &context->names_list, list) {
F_57 ( & V_4 -> V_170 ) ;
if ( V_4 -> V_44 )
F_58 ( V_4 -> V_44 ) ;
if ( V_4 -> V_187 )
F_17 ( V_4 ) ;
}
V_175 -> V_188 = 0 ;
F_59 ( & V_175 -> V_189 ) ;
V_175 -> V_189 . V_190 = NULL ;
V_175 -> V_189 . V_191 = NULL ;
}
static inline void F_60 ( struct V_1 * V_175 )
{
struct V_192 * V_193 ;
while ( ( V_193 = V_175 -> V_193 ) ) {
V_175 -> V_193 = V_193 -> V_36 ;
F_17 ( V_193 ) ;
}
while ( ( V_193 = V_175 -> V_194 ) ) {
V_175 -> V_194 = V_193 -> V_36 ;
F_17 ( V_193 ) ;
}
}
static inline struct V_1 * F_61 ( enum V_87 V_88 )
{
struct V_1 * V_175 ;
V_175 = F_12 ( sizeof( * V_175 ) , V_37 ) ;
if ( ! V_175 )
return NULL ;
V_175 -> V_88 = V_88 ;
V_175 -> V_25 = V_88 == V_27 ? ~ 0ULL : 0 ;
F_62 ( & V_175 -> V_195 ) ;
F_62 ( & V_175 -> V_196 ) ;
return V_175 ;
}
int F_63 ( struct V_50 * V_51 )
{
struct V_1 * V_175 ;
enum V_87 V_88 ;
char * V_162 = NULL ;
if ( F_10 ( ! V_197 ) )
return 0 ;
V_88 = F_41 ( V_51 , & V_162 ) ;
if ( V_88 == V_160 ) {
F_64 ( V_51 , V_198 ) ;
return 0 ;
}
if ( ! ( V_175 = F_61 ( V_88 ) ) ) {
F_17 ( V_162 ) ;
F_65 ( L_2 ) ;
return - V_199 ;
}
V_175 -> V_156 = V_162 ;
V_51 -> V_1 = V_175 ;
F_66 ( V_51 , V_198 ) ;
return 0 ;
}
static inline void F_67 ( struct V_1 * V_175 )
{
F_55 ( V_175 ) ;
F_13 ( V_175 , NULL , 0 ) ;
F_16 ( V_175 ) ;
F_60 ( V_175 ) ;
F_17 ( V_175 -> V_156 ) ;
F_17 ( V_175 -> V_200 ) ;
F_54 ( V_175 ) ;
F_17 ( V_175 ) ;
}
static int F_68 ( struct V_1 * V_175 , T_5 V_97 ,
T_2 V_201 , T_2 V_43 , unsigned int V_202 ,
T_4 V_92 , char * V_203 )
{
struct V_204 * V_205 ;
char * V_2 = NULL ;
T_4 V_186 ;
int V_47 = 0 ;
V_205 = F_69 ( V_175 , V_37 , V_206 ) ;
if ( ! V_205 )
return V_47 ;
F_70 ( V_205 , L_3 , V_97 ,
F_71 ( & V_207 , V_201 ) ,
F_71 ( & V_207 , V_43 ) , V_202 ) ;
if ( V_92 ) {
if ( F_72 ( V_92 , & V_2 , & V_186 ) ) {
F_70 ( V_205 , L_4 ) ;
V_47 = 1 ;
} else {
F_70 ( V_205 , L_5 , V_2 ) ;
F_73 ( V_2 , V_186 ) ;
}
}
F_70 ( V_205 , L_6 ) ;
F_74 ( V_205 , V_203 ) ;
F_75 ( V_205 ) ;
return V_47 ;
}
static int F_76 ( struct V_1 * V_175 ,
struct V_204 * * V_205 ,
int V_208 ,
T_6 * V_209 ,
const char T_7 * V_31 ,
char * V_210 )
{
char V_211 [ 12 ] ;
const char T_7 * V_212 = V_31 ;
T_6 V_213 = snprintf ( V_211 , 12 , L_7 , V_208 ) + 5 ;
T_6 V_186 , V_214 , V_215 ;
T_6 V_216 = V_217 ;
unsigned int V_90 , V_218 = 0 , V_219 = 0 ;
int V_220 ;
V_214 = V_186 = F_77 ( V_31 , V_221 ) - 1 ;
if ( F_78 ( V_186 < 0 || V_186 > V_221 - 1 ) ) {
F_79 ( V_222 , V_93 , 0 ) ;
return - 1 ;
}
do {
if ( V_214 > V_217 )
V_215 = V_217 ;
else
V_215 = V_214 ;
V_220 = F_80 ( V_210 , V_212 , V_215 ) ;
if ( V_220 ) {
F_81 ( 1 ) ;
F_79 ( V_222 , V_93 , 0 ) ;
return - 1 ;
}
V_210 [ V_215 ] = '\0' ;
V_218 = F_82 ( V_210 , V_215 ) ;
if ( V_218 ) {
V_216 = V_217 / 2 ;
break;
}
V_214 -= V_215 ;
V_212 += V_215 ;
} while ( V_214 > 0 );
V_214 = V_186 ;
if ( V_186 > V_216 )
V_219 = 1 ;
for ( V_90 = 0 ; V_214 > 0 ; V_90 ++ ) {
int V_223 ;
if ( V_214 > V_216 )
V_215 = V_216 ;
else
V_215 = V_214 ;
V_223 = V_217 - V_213 - * V_209 ;
if ( V_218 )
V_223 -= ( V_215 * 2 ) ;
else
V_223 -= V_215 ;
if ( V_223 < 0 ) {
* V_209 = 0 ;
F_75 ( * V_205 ) ;
* V_205 = F_69 ( V_175 , V_37 , V_224 ) ;
if ( ! * V_205 )
return 0 ;
}
if ( ( V_90 == 0 ) && ( V_219 ) )
F_70 ( * V_205 , L_8 , V_208 ,
V_218 ? 2 * V_186 : V_186 ) ;
if ( V_186 >= V_216 )
V_220 = F_80 ( V_210 , V_31 , V_215 ) ;
else
V_220 = 0 ;
if ( V_220 ) {
F_81 ( 1 ) ;
F_79 ( V_222 , V_93 , 0 ) ;
return - 1 ;
}
V_210 [ V_215 ] = '\0' ;
F_70 ( * V_205 , L_9 , V_208 ) ;
if ( V_219 )
F_70 ( * V_205 , L_10 , V_90 ) ;
F_70 ( * V_205 , L_11 ) ;
if ( V_218 )
F_83 ( * V_205 , V_210 , V_215 ) ;
else
F_84 ( * V_205 , V_210 ) ;
V_31 += V_215 ;
V_214 -= V_215 ;
* V_209 += V_213 ;
if ( V_218 )
* V_209 += V_215 * 2 ;
else
* V_209 += V_215 ;
}
return V_186 + 1 ;
}
static void F_85 ( struct V_1 * V_175 ,
struct V_204 * * V_205 )
{
int V_90 , V_186 ;
T_6 V_209 = 0 ;
const char T_7 * V_31 ;
char * V_210 ;
V_31 = ( const char T_7 * ) V_93 -> V_225 -> V_226 ;
F_70 ( * V_205 , L_12 , V_175 -> V_227 . V_228 ) ;
V_210 = F_86 ( V_217 + 1 , V_37 ) ;
if ( ! V_210 ) {
F_87 ( L_13 ) ;
return;
}
for ( V_90 = 0 ; V_90 < V_175 -> V_227 . V_228 ; V_90 ++ ) {
V_186 = F_76 ( V_175 , V_205 , V_90 ,
& V_209 , V_31 , V_210 ) ;
if ( V_186 <= 0 )
break;
V_31 += V_186 ;
}
F_17 ( V_210 ) ;
}
static void F_88 ( struct V_1 * V_175 , int * V_229 )
{
struct V_204 * V_205 ;
int V_90 ;
V_205 = F_69 ( V_175 , V_37 , V_175 -> type ) ;
if ( ! V_205 )
return;
switch ( V_175 -> type ) {
case V_230 : {
int V_231 = V_175 -> V_232 . V_231 ;
F_70 ( V_205 , L_14 , V_231 ) ;
for ( V_90 = 0 ; V_90 < V_231 ; V_90 ++ )
F_70 ( V_205 , L_15 , V_90 ,
V_175 -> V_232 . args [ V_90 ] ) ;
break; }
case V_146 : {
T_4 V_145 = V_175 -> V_147 . V_145 ;
F_70 ( V_205 , L_16 ,
F_71 ( & V_207 , V_175 -> V_147 . V_43 ) ,
F_89 ( & V_207 , V_175 -> V_147 . V_49 ) ,
V_175 -> V_147 . V_21 ) ;
if ( V_145 ) {
char * V_2 = NULL ;
T_4 V_186 ;
if ( F_72 ( V_145 , & V_2 , & V_186 ) ) {
F_70 ( V_205 , L_17 , V_145 ) ;
* V_229 = 1 ;
} else {
F_70 ( V_205 , L_5 , V_2 ) ;
F_73 ( V_2 , V_186 ) ;
}
}
if ( V_175 -> V_147 . V_233 ) {
F_75 ( V_205 ) ;
V_205 = F_69 ( V_175 , V_37 ,
V_234 ) ;
if ( F_2 ( ! V_205 ) )
return;
F_70 ( V_205 ,
L_18 ,
V_175 -> V_147 . V_235 ,
V_175 -> V_147 . V_236 ,
V_175 -> V_147 . V_237 ,
V_175 -> V_147 . V_238 ) ;
}
break; }
case V_239 : {
F_70 ( V_205 ,
L_19
L_20 ,
V_175 -> V_240 . V_241 , V_175 -> V_240 . V_21 ,
V_175 -> V_240 . V_242 . V_243 ,
V_175 -> V_240 . V_242 . V_244 ,
V_175 -> V_240 . V_242 . V_245 ,
V_175 -> V_240 . V_242 . V_246 ) ;
break; }
case V_247 : {
F_70 ( V_205 ,
L_21
L_22 ,
V_175 -> V_248 . V_249 ,
V_175 -> V_248 . V_250 ,
V_175 -> V_248 . V_251 ,
V_175 -> V_248 . V_252 . V_253 ,
V_175 -> V_248 . V_252 . V_254 ) ;
break; }
case V_255 : {
F_70 ( V_205 , L_23 ,
V_175 -> V_256 . V_249 ,
V_175 -> V_256 . V_257 ) ;
break; }
case V_258 : {
struct V_259 * V_242 = & V_175 -> V_260 . V_261 ;
F_70 ( V_205 ,
L_24
L_25 ,
V_175 -> V_260 . V_249 ,
V_242 -> V_243 , V_242 -> V_244 ,
V_242 -> V_245 , V_242 -> V_246 ) ;
break; }
case V_262 : {
F_70 ( V_205 , L_26 , V_175 -> V_263 . V_97 ) ;
F_90 ( V_205 , L_27 , & V_175 -> V_263 . V_264 . V_265 ) ;
F_90 ( V_205 , L_28 , & V_175 -> V_263 . V_264 . V_266 ) ;
F_90 ( V_205 , L_29 , & V_175 -> V_263 . V_264 . V_267 ) ;
break; }
case V_268 : {
F_70 ( V_205 , L_30 , V_175 -> V_269 . V_270 ,
V_175 -> V_269 . V_271 ) ;
break; }
case V_224 : {
F_85 ( V_175 , & V_205 ) ;
break; }
}
F_75 ( V_205 ) ;
}
static inline int F_91 ( char * V_184 , int V_186 )
{
char * V_272 = V_184 + V_186 - 1 ;
while ( V_272 > V_184 && ! isprint ( * V_272 ) )
V_272 -- ;
V_186 = V_272 - V_184 + 1 ;
V_186 -= isprint ( V_184 [ V_186 - 1 ] ) == 0 ;
return V_186 ;
}
static void F_92 ( struct V_50 * V_51 ,
struct V_1 * V_175 )
{
int V_273 ;
char * V_210 ;
char * V_274 = L_31 ;
int V_186 = strlen ( V_274 ) ;
struct V_204 * V_205 ;
V_205 = F_69 ( V_175 , V_37 , V_275 ) ;
if ( ! V_205 )
return;
F_70 ( V_205 , L_32 ) ;
if ( ! V_175 -> V_184 . V_185 ) {
V_210 = F_86 ( V_276 , V_37 ) ;
if ( ! V_210 )
goto V_277;
V_273 = F_93 ( V_51 , V_210 , V_276 ) ;
if ( V_273 == 0 ) {
F_17 ( V_210 ) ;
goto V_277;
}
V_273 = F_91 ( V_210 , V_273 ) ;
if ( V_273 == 0 ) {
F_17 ( V_210 ) ;
goto V_277;
}
V_175 -> V_184 . V_185 = V_210 ;
V_175 -> V_184 . V_186 = V_273 ;
}
V_274 = V_175 -> V_184 . V_185 ;
V_186 = V_175 -> V_184 . V_186 ;
V_277:
F_94 ( V_205 , V_274 , V_186 ) ;
F_75 ( V_205 ) ;
}
static void F_95 ( struct V_1 * V_175 , struct V_50 * V_51 )
{
int V_90 , V_229 = 0 ;
struct V_204 * V_205 ;
struct V_192 * V_193 ;
struct V_20 * V_4 ;
V_175 -> V_114 = V_51 -> V_114 ;
V_205 = F_69 ( V_175 , V_37 , V_278 ) ;
if ( ! V_205 )
return;
F_70 ( V_205 , L_33 ,
V_175 -> V_6 , V_175 -> V_5 ) ;
if ( V_175 -> V_114 != V_279 )
F_70 ( V_205 , L_34 , V_175 -> V_114 ) ;
if ( V_175 -> V_117 )
F_70 ( V_205 , L_35 ,
( V_175 -> V_117 == V_120 ) ? L_36 : L_37 ,
V_175 -> V_118 ) ;
F_70 ( V_205 ,
L_38 ,
V_175 -> V_16 [ 0 ] ,
V_175 -> V_16 [ 1 ] ,
V_175 -> V_16 [ 2 ] ,
V_175 -> V_16 [ 3 ] ,
V_175 -> V_188 ) ;
F_96 ( V_205 , V_51 ) ;
F_97 ( V_205 , V_175 -> V_156 ) ;
F_75 ( V_205 ) ;
for ( V_193 = V_175 -> V_193 ; V_193 ; V_193 = V_193 -> V_36 ) {
V_205 = F_69 ( V_175 , V_37 , V_193 -> type ) ;
if ( ! V_205 )
continue;
switch ( V_193 -> type ) {
case V_280 : {
struct V_281 * V_282 = ( void * ) V_193 ;
F_70 ( V_205 , L_39 , V_282 -> V_283 ) ;
F_90 ( V_205 , L_40 , & V_282 -> V_284 . V_266 ) ;
F_90 ( V_205 , L_41 , & V_282 -> V_284 . V_265 ) ;
F_70 ( V_205 , L_42 , V_282 -> V_284 . V_285 ) ;
F_90 ( V_205 , L_43 , & V_282 -> V_286 . V_266 ) ;
F_90 ( V_205 , L_44 , & V_282 -> V_286 . V_265 ) ;
F_90 ( V_205 , L_45 , & V_282 -> V_286 . V_267 ) ;
F_90 ( V_205 , L_46 , & V_282 -> V_287 . V_266 ) ;
F_90 ( V_205 , L_47 , & V_282 -> V_287 . V_265 ) ;
F_90 ( V_205 , L_48 , & V_282 -> V_287 . V_267 ) ;
break; }
}
F_75 ( V_205 ) ;
}
if ( V_175 -> type )
F_88 ( V_175 , & V_229 ) ;
if ( V_175 -> V_288 [ 0 ] >= 0 ) {
V_205 = F_69 ( V_175 , V_37 , V_289 ) ;
if ( V_205 ) {
F_70 ( V_205 , L_49 ,
V_175 -> V_288 [ 0 ] , V_175 -> V_288 [ 1 ] ) ;
F_75 ( V_205 ) ;
}
}
if ( V_175 -> V_290 ) {
V_205 = F_69 ( V_175 , V_37 , V_291 ) ;
if ( V_205 ) {
F_70 ( V_205 , L_50 ) ;
F_83 ( V_205 , ( void * ) V_175 -> V_200 ,
V_175 -> V_290 ) ;
F_75 ( V_205 ) ;
}
}
for ( V_193 = V_175 -> V_194 ; V_193 ; V_193 = V_193 -> V_36 ) {
struct V_292 * V_282 = ( void * ) V_193 ;
for ( V_90 = 0 ; V_90 < V_282 -> V_293 ; V_90 ++ )
if ( F_68 ( V_175 , V_282 -> V_294 [ V_90 ] ,
V_282 -> V_295 [ V_90 ] ,
V_282 -> V_296 [ V_90 ] ,
V_282 -> V_297 [ V_90 ] ,
V_282 -> V_298 [ V_90 ] ,
V_282 -> V_299 [ V_90 ] ) )
V_229 = 1 ;
}
if ( V_175 -> V_294 &&
F_68 ( V_175 , V_175 -> V_294 ,
V_175 -> V_295 , V_175 -> V_296 ,
V_175 -> V_297 ,
V_175 -> V_298 , V_175 -> V_299 ) )
V_229 = 1 ;
if ( V_175 -> V_189 . V_190 && V_175 -> V_189 . V_191 ) {
V_205 = F_69 ( V_175 , V_37 , V_300 ) ;
if ( V_205 ) {
F_98 ( V_205 , L_51 , & V_175 -> V_189 ) ;
F_75 ( V_205 ) ;
}
}
V_90 = 0 ;
F_7 (n, &context->names_list, list) {
if ( V_4 -> V_301 )
continue;
F_99 ( V_175 , V_4 , NULL , V_90 ++ , & V_229 ) ;
}
F_92 ( V_51 , V_175 ) ;
V_205 = F_69 ( V_175 , V_37 , V_302 ) ;
if ( V_205 )
F_75 ( V_205 ) ;
if ( V_229 )
F_87 ( L_52 ) ;
}
void F_100 ( struct V_50 * V_51 )
{
struct V_1 * V_175 ;
V_175 = F_53 ( V_51 , 0 , 0 ) ;
if ( ! V_175 )
return;
if ( V_175 -> V_180 && V_175 -> V_26 == V_27 )
F_95 ( V_175 , V_51 ) ;
if ( ! F_49 ( & V_175 -> V_195 ) )
F_101 ( & V_175 -> V_195 ) ;
F_67 ( V_175 ) ;
}
void F_102 ( int V_5 , unsigned long V_303 , unsigned long V_304 ,
unsigned long V_305 , unsigned long V_306 )
{
struct V_50 * V_51 = V_93 ;
struct V_1 * V_175 = V_51 -> V_1 ;
enum V_87 V_88 ;
if ( ! V_175 )
return;
F_103 ( V_175 -> V_180 || V_175 -> V_188 ) ;
if ( ! V_307 )
return;
V_175 -> V_6 = F_104 () ;
V_175 -> V_5 = V_5 ;
V_175 -> V_16 [ 0 ] = V_303 ;
V_175 -> V_16 [ 1 ] = V_304 ;
V_175 -> V_16 [ 2 ] = V_305 ;
V_175 -> V_16 [ 3 ] = V_306 ;
V_88 = V_175 -> V_88 ;
V_175 -> V_181 = ! V_308 ;
if ( ! V_175 -> V_181 && V_88 == V_165 ) {
V_175 -> V_25 = 0 ;
V_88 = F_48 ( V_51 , V_175 , & V_182 [ V_309 ] ) ;
}
if ( V_88 == V_160 )
return;
V_175 -> V_310 = 0 ;
V_175 -> ctime = V_311 ;
V_175 -> V_180 = 1 ;
V_175 -> V_26 = V_88 ;
V_175 -> V_100 = 0 ;
}
void F_105 ( int V_312 , long V_118 )
{
struct V_50 * V_51 = V_93 ;
struct V_1 * V_175 ;
if ( V_312 )
V_312 = V_120 ;
else
V_312 = V_121 ;
V_175 = F_53 ( V_51 , V_312 , V_118 ) ;
if ( ! V_175 )
return;
if ( V_175 -> V_180 && V_175 -> V_26 == V_27 )
F_95 ( V_175 , V_51 ) ;
V_175 -> V_180 = 0 ;
V_175 -> V_25 = V_175 -> V_88 == V_27 ? ~ 0ULL : 0 ;
if ( ! F_49 ( & V_175 -> V_195 ) )
F_101 ( & V_175 -> V_195 ) ;
F_55 ( V_175 ) ;
F_13 ( V_175 , NULL , 0 ) ;
F_60 ( V_175 ) ;
V_175 -> V_193 = NULL ;
V_175 -> V_194 = NULL ;
V_175 -> V_294 = 0 ;
V_175 -> V_298 = 0 ;
V_175 -> V_290 = 0 ;
V_175 -> type = 0 ;
V_175 -> V_288 [ 0 ] = - 1 ;
if ( V_175 -> V_88 != V_27 ) {
F_17 ( V_175 -> V_156 ) ;
V_175 -> V_156 = NULL ;
}
V_51 -> V_1 = V_175 ;
}
static inline void F_106 ( const struct V_313 * V_313 )
{
#ifdef F_14
struct V_1 * V_175 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
int V_39 ;
if ( F_10 ( F_107 ( & V_313 -> V_314 ) ) )
return;
V_175 = V_93 -> V_1 ;
V_31 = V_175 -> V_32 ;
V_39 = V_175 -> V_34 ;
F_42 () ;
V_29 = F_108 ( V_313 ) ;
F_44 () ;
if ( ! V_29 )
return;
if ( F_10 ( F_9 ( V_175 , V_29 ) ) )
return;
if ( F_2 ( ! F_11 ( V_175 ) ) ) {
F_109 ( L_53 ) ;
F_8 ( V_175 ) ;
F_15 ( V_29 ) ;
F_13 ( V_175 , V_31 , V_39 ) ;
return;
}
F_9 ( V_175 , V_29 ) ;
#endif
}
static void F_110 ( const struct V_190 * V_190 )
{
#ifdef F_14
struct V_1 * V_175 ;
struct V_30 * V_31 ;
const struct V_190 * V_315 , * V_316 ;
struct V_28 * V_317 ;
unsigned long V_318 ;
int V_39 ;
V_175 = V_93 -> V_1 ;
V_31 = V_175 -> V_32 ;
V_39 = V_175 -> V_34 ;
V_319:
V_317 = NULL ;
V_315 = V_190 ;
F_42 () ;
V_318 = F_111 ( & V_320 ) ;
for(; ; ) {
struct V_313 * V_313 = F_112 ( V_315 ) ;
if ( V_313 && F_2 ( ! F_107 ( & V_313 -> V_314 ) ) ) {
struct V_28 * V_29 ;
V_29 = F_108 ( V_313 ) ;
if ( V_29 ) {
if ( F_2 ( ! F_9 ( V_175 , V_29 ) ) ) {
V_317 = V_29 ;
break;
}
}
}
V_316 = V_315 -> V_321 ;
if ( V_316 == V_315 )
break;
V_315 = V_316 ;
}
if ( F_2 ( F_113 ( & V_320 , V_318 ) || V_317 ) ) {
F_44 () ;
if ( ! V_317 ) {
F_13 ( V_175 , V_31 , V_39 ) ;
goto V_319;
}
F_15 ( V_317 ) ;
if ( F_11 ( V_175 ) ) {
F_13 ( V_175 , V_31 , V_39 ) ;
goto V_319;
}
F_109 ( L_53 ) ;
F_13 ( V_175 , V_31 , V_39 ) ;
F_8 ( V_175 ) ;
return;
}
F_44 () ;
#endif
}
static struct V_20 * F_114 ( struct V_1 * V_175 ,
unsigned char type )
{
struct V_20 * V_322 ;
if ( V_175 -> V_188 < V_323 ) {
V_322 = & V_175 -> V_324 [ V_175 -> V_188 ] ;
memset ( V_322 , 0 , sizeof( * V_322 ) ) ;
} else {
V_322 = F_12 ( sizeof( * V_322 ) , V_325 ) ;
if ( ! V_322 )
return NULL ;
V_322 -> V_187 = true ;
}
V_322 -> V_22 = V_23 ;
V_322 -> type = type ;
F_115 ( & V_322 -> V_170 , & V_175 -> V_196 ) ;
V_175 -> V_188 ++ ;
return V_322 ;
}
struct V_326 *
F_116 ( const T_7 char * V_327 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
struct V_20 * V_4 ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 )
continue;
if ( V_4 -> V_44 -> V_327 == V_327 ) {
V_4 -> V_44 -> V_328 ++ ;
return V_4 -> V_44 ;
}
}
return NULL ;
}
void F_117 ( struct V_326 * V_44 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
struct V_20 * V_4 ;
if ( ! V_175 -> V_180 )
return;
V_4 = F_114 ( V_175 , V_329 ) ;
if ( ! V_4 )
return;
V_4 -> V_44 = V_44 ;
V_4 -> V_330 = V_331 ;
V_44 -> V_322 = V_4 ;
V_44 -> V_328 ++ ;
if ( ! V_175 -> V_189 . V_190 )
F_118 ( V_93 -> V_332 , & V_175 -> V_189 ) ;
}
void F_119 ( struct V_326 * V_44 , const struct V_190 * V_190 ,
unsigned int V_271 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
const struct V_313 * V_313 = F_112 ( V_190 ) ;
struct V_20 * V_4 ;
bool V_316 = V_271 & V_333 ;
if ( ! V_175 -> V_180 )
return;
if ( ! V_44 )
goto V_334;
V_4 = V_44 -> V_322 ;
if ( V_4 ) {
if ( V_316 ) {
if ( V_4 -> type == V_335 ||
V_4 -> type == V_329 )
goto V_277;
} else {
if ( V_4 -> type != V_335 )
goto V_277;
}
}
F_120 (n, &context->names_list, list) {
if ( V_4 -> V_22 ) {
if ( V_4 -> V_22 != V_313 -> V_336 ||
V_4 -> V_123 != V_313 -> V_337 -> V_338 )
continue;
} else if ( V_4 -> V_44 ) {
if ( strcmp ( V_4 -> V_44 -> V_44 , V_44 -> V_44 ) )
continue;
} else
continue;
if ( V_316 ) {
if ( V_4 -> type == V_335 ||
V_4 -> type == V_329 )
goto V_277;
} else {
if ( V_4 -> type != V_335 )
goto V_277;
}
}
V_334:
V_4 = F_114 ( V_175 , V_329 ) ;
if ( ! V_4 )
return;
if ( V_44 ) {
V_4 -> V_44 = V_44 ;
V_44 -> V_328 ++ ;
}
V_277:
if ( V_316 ) {
V_4 -> V_330 = V_4 -> V_44 ? F_121 ( V_4 -> V_44 -> V_44 ) : V_331 ;
V_4 -> type = V_335 ;
if ( V_271 & V_339 )
V_4 -> V_301 = true ;
} else {
V_4 -> V_330 = V_331 ;
V_4 -> type = V_340 ;
}
F_110 ( V_190 ) ;
F_122 ( V_4 , V_190 , V_313 ) ;
}
void F_123 ( const struct V_341 * V_341 )
{
F_119 ( NULL , V_341 -> V_342 . V_190 , 0 ) ;
}
void F_124 ( const struct V_313 * V_316 ,
const struct V_190 * V_190 ,
const unsigned char type )
{
struct V_1 * V_175 = V_93 -> V_1 ;
const struct V_313 * V_313 = F_112 ( V_190 ) ;
const char * V_343 = V_190 -> V_344 . V_44 ;
struct V_20 * V_4 , * V_345 = NULL , * V_346 = NULL ;
if ( ! V_175 -> V_180 )
return;
if ( V_313 )
F_106 ( V_313 ) ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 ||
( V_4 -> type != V_335 &&
V_4 -> type != V_329 ) )
continue;
if ( V_4 -> V_22 == V_316 -> V_336 && V_4 -> V_123 == V_316 -> V_337 -> V_338 &&
! F_125 ( V_343 ,
V_4 -> V_44 -> V_44 , V_4 -> V_330 ) ) {
if ( V_4 -> type == V_329 )
V_4 -> type = V_335 ;
V_345 = V_4 ;
break;
}
}
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 ||
( V_4 -> type != type && V_4 -> type != V_329 ) )
continue;
if ( ! strcmp ( V_343 , V_4 -> V_44 -> V_44 ) ||
! F_125 ( V_343 , V_4 -> V_44 -> V_44 ,
V_345 ?
V_345 -> V_330 :
V_331 ) ) {
if ( V_4 -> type == V_329 )
V_4 -> type = type ;
V_346 = V_4 ;
break;
}
}
if ( ! V_345 ) {
V_4 = F_114 ( V_175 , V_335 ) ;
if ( ! V_4 )
return;
F_122 ( V_4 , NULL , V_316 ) ;
}
if ( ! V_346 ) {
V_346 = F_114 ( V_175 , type ) ;
if ( ! V_346 )
return;
if ( V_345 ) {
V_346 -> V_44 = V_345 -> V_44 ;
V_346 -> V_330 = V_331 ;
V_346 -> V_44 -> V_328 ++ ;
}
}
if ( V_313 )
F_122 ( V_346 , V_190 , V_313 ) ;
else
V_346 -> V_22 = V_23 ;
}
int F_126 ( struct V_1 * V_2 ,
struct V_347 * V_348 , unsigned int * V_310 )
{
if ( ! V_2 -> V_180 )
return 0 ;
if ( ! V_2 -> V_310 )
V_2 -> V_310 = F_127 () ;
V_348 -> V_253 = V_2 -> ctime . V_253 ;
V_348 -> V_254 = V_2 -> ctime . V_254 ;
* V_310 = V_2 -> V_310 ;
if ( ! V_2 -> V_25 ) {
V_2 -> V_25 = 1 ;
V_2 -> V_26 = V_27 ;
}
return 1 ;
}
static int F_128 ( T_2 V_60 )
{
if ( ! F_37 ( V_93 ) )
return 0 ;
if ( F_129 ( V_349 ) )
return - V_350 ;
if ( ! F_130 ( V_351 ) )
return - V_350 ;
if ( F_129 ( V_352 ) && F_131 ( V_60 ) )
return - V_350 ;
return 0 ;
}
static void F_132 ( T_2 V_353 , T_2 V_354 ,
unsigned int V_355 , unsigned int V_202 ,
int V_47 )
{
struct V_204 * V_205 ;
T_8 V_43 , V_356 , V_60 ;
if ( ! V_307 )
return;
V_43 = F_71 ( & V_207 , F_133 ( V_93 ) ) ;
V_356 = F_71 ( & V_207 , V_353 ) ;
V_60 = F_71 ( & V_207 , V_354 ) ,
V_205 = F_69 ( NULL , V_37 , V_357 ) ;
if ( ! V_205 )
return;
F_70 ( V_205 , L_54 , F_28 ( V_93 ) , V_43 ) ;
F_134 ( V_205 ) ;
F_70 ( V_205 , L_55 ,
V_356 , V_60 , V_355 , V_202 , ! V_47 ) ;
F_75 ( V_205 ) ;
}
int F_135 ( T_2 V_60 )
{
struct V_50 * V_358 = V_93 ;
unsigned int V_355 , V_202 = ( unsigned int ) - 1 ;
T_2 V_356 ;
int V_47 ;
V_356 = F_136 ( V_93 ) ;
V_355 = F_137 ( V_93 ) ;
V_47 = F_128 ( V_60 ) ;
if ( V_47 )
goto V_277;
if ( F_131 ( V_60 ) )
V_202 = ( unsigned int ) F_138 ( & V_359 ) ;
V_358 -> V_202 = V_202 ;
V_358 -> V_60 = V_60 ;
V_277:
F_132 ( V_356 , V_60 , V_355 , V_202 , V_47 ) ;
return V_47 ;
}
void F_139 ( int V_241 , T_1 V_21 , struct V_259 * V_242 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
if ( V_242 )
memcpy ( & V_175 -> V_240 . V_242 , V_242 , sizeof( struct V_259 ) ) ;
else
memset ( & V_175 -> V_240 . V_242 , 0 , sizeof( struct V_259 ) ) ;
V_175 -> V_240 . V_241 = V_241 ;
V_175 -> V_240 . V_21 = V_21 ;
V_175 -> type = V_239 ;
}
void F_140 ( T_9 V_249 , T_6 V_250 , unsigned int V_251 ,
const struct V_347 * V_252 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
struct V_347 * V_31 = & V_175 -> V_248 . V_252 ;
if ( V_252 )
memcpy ( V_31 , V_252 , sizeof( struct V_347 ) ) ;
else
memset ( V_31 , 0 , sizeof( struct V_347 ) ) ;
V_175 -> V_248 . V_249 = V_249 ;
V_175 -> V_248 . V_250 = V_250 ;
V_175 -> V_248 . V_251 = V_251 ;
V_175 -> type = V_247 ;
}
void F_141 ( T_9 V_249 , const struct V_360 * V_361 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
if ( V_361 )
V_175 -> V_256 . V_257 = V_361 -> V_257 ;
else
V_175 -> V_256 . V_257 = 0 ;
V_175 -> V_256 . V_249 = V_249 ;
V_175 -> type = V_255 ;
}
void F_142 ( T_9 V_249 , struct V_259 * V_261 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_260 . V_249 = V_249 ;
V_175 -> V_260 . V_261 = * V_261 ;
V_175 -> type = V_258 ;
}
void F_143 ( struct V_362 * V_363 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_147 . V_43 = V_363 -> V_43 ;
V_175 -> V_147 . V_49 = V_363 -> V_49 ;
V_175 -> V_147 . V_21 = V_363 -> V_21 ;
V_175 -> V_147 . V_233 = 0 ;
F_144 ( V_363 , & V_175 -> V_147 . V_145 ) ;
V_175 -> type = V_146 ;
}
void F_145 ( unsigned long V_235 , T_8 V_43 , T_10 V_49 , T_1 V_21 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_147 . V_235 = V_235 ;
V_175 -> V_147 . V_236 = V_43 ;
V_175 -> V_147 . V_237 = V_49 ;
V_175 -> V_147 . V_238 = V_21 ;
V_175 -> V_147 . V_233 = 1 ;
}
void F_146 ( struct V_364 * V_365 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> type = V_224 ;
V_175 -> V_227 . V_228 = V_365 -> V_228 ;
}
int F_147 ( int V_231 , unsigned long * args )
{
struct V_1 * V_175 = V_93 -> V_1 ;
if ( V_231 <= 0 || V_231 > V_366 || ! args )
return - V_367 ;
V_175 -> type = V_230 ;
V_175 -> V_232 . V_231 = V_231 ;
memcpy ( V_175 -> V_232 . args , args , V_231 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_148 ( int V_368 , int V_369 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_288 [ 0 ] = V_368 ;
V_175 -> V_288 [ 1 ] = V_369 ;
}
int F_149 ( int V_186 , void * V_370 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
if ( ! V_175 -> V_200 ) {
void * V_31 = F_86 ( sizeof( struct V_371 ) , V_37 ) ;
if ( ! V_31 )
return - V_199 ;
V_175 -> V_200 = V_31 ;
}
V_175 -> V_290 = V_186 ;
memcpy ( V_175 -> V_200 , V_370 , V_186 ) ;
return 0 ;
}
void F_150 ( struct V_50 * V_348 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_294 = F_28 ( V_348 ) ;
V_175 -> V_295 = F_136 ( V_348 ) ;
V_175 -> V_296 = F_133 ( V_348 ) ;
V_175 -> V_297 = F_137 ( V_348 ) ;
F_38 ( V_348 , & V_175 -> V_298 ) ;
memcpy ( V_175 -> V_299 , V_348 -> V_203 , V_372 ) ;
}
int F_151 ( int V_373 , struct V_50 * V_348 )
{
struct V_292 * V_374 ;
struct V_50 * V_51 = V_93 ;
struct V_1 * V_2 = V_51 -> V_1 ;
T_2 V_43 = F_152 () , V_375 = F_133 ( V_348 ) ;
if ( V_171 && V_348 -> V_172 == V_171 ) {
if ( V_373 == V_376 || V_373 == V_377 || V_373 == V_378 || V_373 == V_379 ) {
V_380 = F_28 ( V_51 ) ;
if ( F_131 ( V_51 -> V_60 ) )
V_381 = V_51 -> V_60 ;
else
V_381 = V_43 ;
F_38 ( V_51 , & V_382 ) ;
}
if ( ! V_383 || F_153 () )
return 0 ;
}
if ( ! V_2 -> V_294 ) {
V_2 -> V_294 = F_154 ( V_348 ) ;
V_2 -> V_295 = F_136 ( V_348 ) ;
V_2 -> V_296 = V_375 ;
V_2 -> V_297 = F_137 ( V_348 ) ;
F_38 ( V_348 , & V_2 -> V_298 ) ;
memcpy ( V_2 -> V_299 , V_348 -> V_203 , V_372 ) ;
return 0 ;
}
V_374 = ( void * ) V_2 -> V_194 ;
if ( ! V_374 || V_374 -> V_293 == V_384 ) {
V_374 = F_12 ( sizeof( * V_374 ) , V_157 ) ;
if ( ! V_374 )
return - V_199 ;
V_374 -> V_315 . type = V_206 ;
V_374 -> V_315 . V_36 = V_2 -> V_194 ;
V_2 -> V_194 = ( void * ) V_374 ;
}
F_103 ( V_374 -> V_293 >= V_384 ) ;
V_374 -> V_294 [ V_374 -> V_293 ] = F_154 ( V_348 ) ;
V_374 -> V_295 [ V_374 -> V_293 ] = F_136 ( V_348 ) ;
V_374 -> V_296 [ V_374 -> V_293 ] = V_375 ;
V_374 -> V_297 [ V_374 -> V_293 ] = F_137 ( V_348 ) ;
F_38 ( V_348 , & V_374 -> V_298 [ V_374 -> V_293 ] ) ;
memcpy ( V_374 -> V_299 [ V_374 -> V_293 ] , V_348 -> V_203 , V_372 ) ;
V_374 -> V_293 ++ ;
return 0 ;
}
int F_155 ( struct V_364 * V_365 ,
const struct V_52 * V_385 , const struct V_52 * V_386 )
{
struct V_281 * V_387 ;
struct V_1 * V_175 = V_93 -> V_1 ;
struct V_388 V_389 ;
V_387 = F_86 ( sizeof( * V_387 ) , V_37 ) ;
if ( ! V_387 )
return - V_199 ;
V_387 -> V_315 . type = V_280 ;
V_387 -> V_315 . V_36 = V_175 -> V_193 ;
V_175 -> V_193 = ( void * ) V_387 ;
F_156 ( V_365 -> V_341 -> V_342 . V_190 , & V_389 ) ;
V_387 -> V_284 . V_266 = V_389 . V_266 ;
V_387 -> V_284 . V_265 = V_389 . V_265 ;
V_387 -> V_284 . V_285 = ! ! ( V_389 . V_390 & V_391 ) ;
V_387 -> V_283 = ( V_389 . V_390 & V_392 ) >> V_393 ;
V_387 -> V_286 . V_266 = V_386 -> V_394 ;
V_387 -> V_286 . V_265 = V_386 -> V_395 ;
V_387 -> V_286 . V_267 = V_386 -> V_396 ;
V_387 -> V_287 . V_266 = V_385 -> V_394 ;
V_387 -> V_287 . V_265 = V_385 -> V_395 ;
V_387 -> V_287 . V_267 = V_385 -> V_396 ;
return 0 ;
}
void F_157 ( const struct V_52 * V_385 , const struct V_52 * V_386 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_263 . V_97 = F_28 ( V_93 ) ;
V_175 -> V_263 . V_264 . V_267 = V_385 -> V_396 ;
V_175 -> V_263 . V_264 . V_265 = V_385 -> V_396 ;
V_175 -> V_263 . V_264 . V_266 = V_385 -> V_394 ;
V_175 -> type = V_262 ;
}
void F_158 ( int V_270 , int V_271 )
{
struct V_1 * V_175 = V_93 -> V_1 ;
V_175 -> V_269 . V_270 = V_270 ;
V_175 -> V_269 . V_271 = V_271 ;
V_175 -> type = V_268 ;
}
static void F_159 ( struct V_204 * V_205 )
{
T_2 V_201 , V_43 ;
T_3 V_49 ;
unsigned int V_202 ;
char V_203 [ sizeof( V_93 -> V_203 ) ] ;
V_201 = F_136 ( V_93 ) ;
V_202 = F_137 ( V_93 ) ;
F_160 ( & V_43 , & V_49 ) ;
F_70 ( V_205 , L_56 ,
F_71 ( & V_207 , V_201 ) ,
F_71 ( & V_207 , V_43 ) ,
F_89 ( & V_207 , V_49 ) ,
V_202 ) ;
F_134 ( V_205 ) ;
F_70 ( V_205 , L_57 , F_28 ( V_93 ) ) ;
F_74 ( V_205 , F_161 ( V_203 , V_93 ) ) ;
F_162 ( V_205 , V_93 -> V_225 ) ;
}
void F_163 ( long V_397 )
{
struct V_204 * V_205 ;
if ( ! V_307 )
return;
if ( V_397 == V_398 )
return;
V_205 = F_69 ( NULL , V_37 , V_399 ) ;
if ( F_2 ( ! V_205 ) )
return;
F_159 ( V_205 ) ;
F_70 ( V_205 , L_58 , V_397 ) ;
F_75 ( V_205 ) ;
}
void F_164 ( unsigned long V_400 , long V_397 , int V_401 )
{
struct V_204 * V_205 ;
V_205 = F_69 ( NULL , V_37 , V_402 ) ;
if ( F_2 ( ! V_205 ) )
return;
F_159 ( V_205 ) ;
F_70 ( V_205 , L_59 ,
V_397 , F_104 () , V_400 , F_165 () ,
F_166 ( V_93 ) , V_401 ) ;
F_75 ( V_205 ) ;
}
struct V_169 * F_167 ( void )
{
struct V_1 * V_2 = V_93 -> V_1 ;
if ( F_10 ( ! V_2 || ! V_2 -> V_180 ) )
return NULL ;
return & V_2 -> V_195 ;
}
