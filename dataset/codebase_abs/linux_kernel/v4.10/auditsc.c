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
unsigned int V_93 ;
V_52 = F_27 ( V_51 -> V_52 , V_51 == V_94 || V_89 ) ;
for ( V_90 = 0 ; V_90 < V_86 -> V_95 ; V_90 ++ ) {
struct V_45 * V_46 = & V_86 -> V_96 [ V_90 ] ;
struct V_20 * V_4 ;
int V_97 = 0 ;
T_5 V_98 ;
switch ( V_46 -> type ) {
case V_99 :
V_98 = F_28 ( V_51 ) ;
V_97 = F_29 ( V_98 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_100 :
if ( V_2 ) {
if ( ! V_2 -> V_101 )
V_2 -> V_101 = F_30 ( V_51 ) ;
V_97 = F_29 ( V_2 -> V_101 , V_46 -> V_48 , V_46 -> V_19 ) ;
}
break;
case V_102 :
V_97 = F_31 ( V_51 , V_86 -> V_103 ) ;
break;
case V_104 :
V_97 = F_21 ( V_52 -> V_43 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_105 :
V_97 = F_21 ( V_52 -> V_56 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_106 :
V_97 = F_21 ( V_52 -> V_62 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_107 :
V_97 = F_21 ( V_52 -> V_66 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_108 :
V_97 = F_23 ( V_52 -> V_49 , V_46 -> V_48 , V_46 -> V_49 ) ;
if ( V_46 -> V_48 == V_109 ) {
if ( ! V_97 )
V_97 = F_32 ( V_46 -> V_49 ) ;
} else if ( V_46 -> V_48 == V_110 ) {
if ( V_97 )
V_97 = ! F_32 ( V_46 -> V_49 ) ;
}
break;
case V_111 :
V_97 = F_23 ( V_52 -> V_58 , V_46 -> V_48 , V_46 -> V_49 ) ;
if ( V_46 -> V_48 == V_109 ) {
if ( ! V_97 )
V_97 = F_33 ( V_46 -> V_49 ) ;
} else if ( V_46 -> V_48 == V_110 ) {
if ( V_97 )
V_97 = ! F_33 ( V_46 -> V_49 ) ;
}
break;
case V_112 :
V_97 = F_23 ( V_52 -> V_64 , V_46 -> V_48 , V_46 -> V_49 ) ;
break;
case V_113 :
V_97 = F_23 ( V_52 -> V_68 , V_46 -> V_48 , V_46 -> V_49 ) ;
break;
case V_114 :
V_93 = F_34 ( V_94 ) ;
V_97 = F_29 ( V_93 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_115 :
V_97 = F_29 ( V_51 -> V_116 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_117 :
if ( V_2 )
V_97 = F_29 ( V_2 -> V_6 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_118 :
if ( V_2 && V_2 -> V_119 )
V_97 = F_29 ( V_2 -> V_120 , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_121 :
if ( V_2 && V_2 -> V_119 ) {
if ( V_46 -> V_19 )
V_97 = F_29 ( V_2 -> V_119 , V_46 -> V_48 , V_122 ) ;
else
V_97 = F_29 ( V_2 -> V_119 , V_46 -> V_48 , V_123 ) ;
}
break;
case V_124 :
if ( V_44 ) {
if ( F_29 ( F_35 ( V_44 -> V_125 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_35 ( V_44 -> V_126 ) , V_46 -> V_48 , V_46 -> V_19 ) )
++ V_97 ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( F_35 ( V_4 -> V_125 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_35 ( V_4 -> V_126 ) , V_46 -> V_48 , V_46 -> V_19 ) ) {
++ V_97 ;
break;
}
}
}
break;
case V_127 :
if ( V_44 ) {
if ( F_29 ( F_36 ( V_44 -> V_125 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_36 ( V_44 -> V_126 ) , V_46 -> V_48 , V_46 -> V_19 ) )
++ V_97 ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( F_36 ( V_4 -> V_125 ) , V_46 -> V_48 , V_46 -> V_19 ) ||
F_29 ( F_36 ( V_4 -> V_126 ) , V_46 -> V_48 , V_46 -> V_19 ) ) {
++ V_97 ;
break;
}
}
}
break;
case V_128 :
if ( V_44 )
V_97 = F_29 ( V_44 -> V_22 , V_46 -> V_48 , V_46 -> V_19 ) ;
else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( V_4 -> V_22 , V_46 -> V_48 , V_46 -> V_19 ) ) {
++ V_97 ;
break;
}
}
}
break;
case V_129 :
if ( V_44 ) {
V_97 = F_21 ( V_44 -> V_43 , V_46 -> V_48 , V_46 -> V_43 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_21 ( V_4 -> V_43 , V_46 -> V_48 , V_46 -> V_43 ) ) {
++ V_97 ;
break;
}
}
}
break;
case V_130 :
if ( V_44 ) {
V_97 = F_23 ( V_44 -> V_49 , V_46 -> V_48 , V_46 -> V_49 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_23 ( V_4 -> V_49 , V_46 -> V_48 , V_46 -> V_49 ) ) {
++ V_97 ;
break;
}
}
}
break;
case V_131 :
if ( V_44 )
V_97 = F_37 ( V_86 -> V_132 , V_44 -> V_22 , V_44 -> V_125 ) ;
break;
case V_133 :
if ( V_2 )
V_97 = F_18 ( V_2 , V_86 -> V_42 ) ;
break;
case V_134 :
V_97 = F_21 ( V_51 -> V_60 , V_46 -> V_48 , V_46 -> V_43 ) ;
break;
case V_135 :
V_97 = F_29 ( F_38 ( V_51 ) , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
if ( V_46 -> V_141 ) {
if ( V_91 ) {
F_39 ( V_51 , & V_92 ) ;
V_91 = 0 ;
}
V_97 = F_40 ( V_92 , V_46 -> type ,
V_46 -> V_48 ,
V_46 -> V_141 ,
V_2 ) ;
}
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
if ( V_46 -> V_141 ) {
if ( V_44 ) {
V_97 = F_40 (
V_44 -> V_147 , V_46 -> type , V_46 -> V_48 ,
V_46 -> V_141 , V_2 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_40 ( V_4 -> V_147 , V_46 -> type ,
V_46 -> V_48 , V_46 -> V_141 ,
V_2 ) ) {
++ V_97 ;
break;
}
}
}
if ( ! V_2 || V_2 -> type != V_148 )
break;
if ( F_40 ( V_2 -> V_149 . V_147 ,
V_46 -> type , V_46 -> V_48 ,
V_46 -> V_141 , V_2 ) )
++ V_97 ;
}
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
if ( V_2 )
V_97 = F_29 ( V_2 -> V_16 [ V_46 -> type - V_150 ] , V_46 -> V_48 , V_46 -> V_19 ) ;
break;
case V_154 :
V_97 = 1 ;
break;
case V_155 :
V_97 = F_1 ( V_2 , V_46 -> V_19 ) ;
break;
case V_156 :
V_97 = F_6 ( V_2 , V_46 -> V_19 ) ;
break;
case V_157 :
V_97 = F_24 ( V_51 , V_52 , V_46 , V_2 , V_44 ) ;
break;
}
if ( ! V_97 )
return 0 ;
}
if ( V_2 ) {
if ( V_86 -> V_25 <= V_2 -> V_25 )
return 0 ;
if ( V_86 -> V_158 ) {
F_17 ( V_2 -> V_158 ) ;
V_2 -> V_158 = F_41 ( V_86 -> V_158 , V_159 ) ;
}
V_2 -> V_25 = V_86 -> V_25 ;
}
switch ( V_86 -> V_160 ) {
case V_161 :
* V_88 = V_162 ;
break;
case V_163 :
* V_88 = V_27 ;
break;
}
return 1 ;
}
static enum V_87 F_42 ( struct V_50 * V_51 , char * * V_164 )
{
struct V_165 * V_166 ;
enum V_87 V_88 ;
F_43 () ;
F_44 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_26 ( V_51 , & V_166 -> V_86 , NULL , NULL ,
& V_88 , true ) ) {
if ( V_88 == V_27 )
* V_164 = F_41 ( V_166 -> V_86 . V_158 , V_159 ) ;
F_45 () ;
return V_88 ;
}
}
F_45 () ;
return V_167 ;
}
static int F_46 ( const struct V_85 * V_86 , unsigned long V_19 )
{
int V_168 , V_169 ;
if ( V_19 > 0xffffffff )
return false ;
V_168 = F_47 ( V_19 ) ;
if ( V_168 >= V_170 )
return false ;
V_169 = F_48 ( V_19 ) ;
return V_86 -> V_3 [ V_168 ] & V_169 ;
}
static enum V_87 F_49 ( struct V_50 * V_51 ,
struct V_1 * V_2 ,
struct V_171 * V_172 )
{
struct V_165 * V_166 ;
enum V_87 V_88 ;
if ( V_173 && V_51 -> V_174 == V_173 )
return V_162 ;
F_43 () ;
if ( ! F_50 ( V_172 ) ) {
F_44 (e, list, list) {
if ( F_46 ( & V_166 -> V_86 , V_2 -> V_5 ) &&
F_26 ( V_51 , & V_166 -> V_86 , V_2 , NULL ,
& V_88 , false ) ) {
F_45 () ;
V_2 -> V_26 = V_88 ;
return V_88 ;
}
}
}
F_45 () ;
return V_167 ;
}
static int F_51 ( struct V_50 * V_51 ,
struct V_20 * V_4 ,
struct V_1 * V_2 ) {
int V_175 = F_52 ( ( T_4 ) V_4 -> V_22 ) ;
struct V_171 * V_172 = & V_176 [ V_175 ] ;
struct V_165 * V_166 ;
enum V_87 V_88 ;
if ( F_50 ( V_172 ) )
return 0 ;
F_44 (e, list, list) {
if ( F_46 ( & V_166 -> V_86 , V_2 -> V_5 ) &&
F_26 ( V_51 , & V_166 -> V_86 , V_2 , V_4 , & V_88 , false ) ) {
V_2 -> V_26 = V_88 ;
return 1 ;
}
}
return 0 ;
}
void F_53 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_20 * V_4 ;
if ( V_173 && V_51 -> V_174 == V_173 )
return;
F_43 () ;
F_7 (n, &ctx->names_list, list) {
if ( F_51 ( V_51 , V_4 , V_2 ) )
break;
}
F_45 () ;
}
static inline struct V_1 * F_54 ( struct V_50 * V_51 ,
int V_119 ,
long V_120 )
{
struct V_1 * V_177 = V_51 -> V_1 ;
if ( ! V_177 )
return NULL ;
V_177 -> V_119 = V_119 ;
if ( F_2 ( V_120 <= - V_178 ) &&
( V_120 >= - V_179 ) &&
( V_120 != - V_180 ) )
V_177 -> V_120 = - V_181 ;
else
V_177 -> V_120 = V_120 ;
if ( V_177 -> V_182 && ! V_177 -> V_183 ) {
F_49 ( V_51 , V_177 , & V_184 [ V_185 ] ) ;
F_53 ( V_51 , V_177 ) ;
}
V_51 -> V_1 = NULL ;
return V_177 ;
}
static inline void F_55 ( struct V_1 * V_177 )
{
F_17 ( V_177 -> V_186 . V_187 ) ;
V_177 -> V_186 . V_187 = NULL ;
V_177 -> V_186 . V_188 = 0 ;
}
static inline void F_56 ( struct V_1 * V_177 )
{
struct V_20 * V_4 , * V_36 ;
F_57 (n, next, &context->names_list, list) {
F_58 ( & V_4 -> V_172 ) ;
if ( V_4 -> V_44 )
F_59 ( V_4 -> V_44 ) ;
if ( V_4 -> V_189 )
F_17 ( V_4 ) ;
}
V_177 -> V_190 = 0 ;
F_60 ( & V_177 -> V_191 ) ;
V_177 -> V_191 . V_192 = NULL ;
V_177 -> V_191 . V_193 = NULL ;
}
static inline void F_61 ( struct V_1 * V_177 )
{
struct V_194 * V_195 ;
while ( ( V_195 = V_177 -> V_195 ) ) {
V_177 -> V_195 = V_195 -> V_36 ;
F_17 ( V_195 ) ;
}
while ( ( V_195 = V_177 -> V_196 ) ) {
V_177 -> V_196 = V_195 -> V_36 ;
F_17 ( V_195 ) ;
}
}
static inline struct V_1 * F_62 ( enum V_87 V_88 )
{
struct V_1 * V_177 ;
V_177 = F_12 ( sizeof( * V_177 ) , V_37 ) ;
if ( ! V_177 )
return NULL ;
V_177 -> V_88 = V_88 ;
V_177 -> V_25 = V_88 == V_27 ? ~ 0ULL : 0 ;
F_63 ( & V_177 -> V_197 ) ;
F_63 ( & V_177 -> V_198 ) ;
return V_177 ;
}
int F_64 ( struct V_50 * V_51 )
{
struct V_1 * V_177 ;
enum V_87 V_88 ;
char * V_164 = NULL ;
if ( F_10 ( ! V_199 ) )
return 0 ;
V_88 = F_42 ( V_51 , & V_164 ) ;
if ( V_88 == V_162 ) {
F_65 ( V_51 , V_200 ) ;
return 0 ;
}
if ( ! ( V_177 = F_62 ( V_88 ) ) ) {
F_17 ( V_164 ) ;
F_66 ( L_2 ) ;
return - V_201 ;
}
V_177 -> V_158 = V_164 ;
V_51 -> V_1 = V_177 ;
F_67 ( V_51 , V_200 ) ;
return 0 ;
}
static inline void F_68 ( struct V_1 * V_177 )
{
F_56 ( V_177 ) ;
F_13 ( V_177 , NULL , 0 ) ;
F_16 ( V_177 ) ;
F_61 ( V_177 ) ;
F_17 ( V_177 -> V_158 ) ;
F_17 ( V_177 -> V_202 ) ;
F_55 ( V_177 ) ;
F_17 ( V_177 ) ;
}
static int F_69 ( struct V_1 * V_177 , T_5 V_98 ,
T_2 V_203 , T_2 V_43 , unsigned int V_93 ,
T_4 V_92 , char * V_204 )
{
struct V_205 * V_206 ;
char * V_2 = NULL ;
T_4 V_188 ;
int V_47 = 0 ;
V_206 = F_70 ( V_177 , V_37 , V_207 ) ;
if ( ! V_206 )
return V_47 ;
F_71 ( V_206 , L_3 , V_98 ,
F_72 ( & V_208 , V_203 ) ,
F_72 ( & V_208 , V_43 ) , V_93 ) ;
if ( V_92 ) {
if ( F_73 ( V_92 , & V_2 , & V_188 ) ) {
F_71 ( V_206 , L_4 ) ;
V_47 = 1 ;
} else {
F_71 ( V_206 , L_5 , V_2 ) ;
F_74 ( V_2 , V_188 ) ;
}
}
F_71 ( V_206 , L_6 ) ;
F_75 ( V_206 , V_204 ) ;
F_76 ( V_206 ) ;
return V_47 ;
}
static void F_77 ( struct V_1 * V_177 ,
struct V_205 * * V_206 )
{
long V_209 ;
long V_210 ;
long V_211 ;
long V_212 ;
long V_213 = 0 ;
long V_214 ;
bool V_215 ;
bool V_216 ;
unsigned int V_217 ;
unsigned int V_218 ;
char * V_219 ;
char * V_220 ;
const char T_6 * V_31 = ( const char T_6 * ) V_94 -> V_221 -> V_222 ;
char V_223 [ 96 ] ;
F_78 ( V_224 > 7500 ) ;
V_209 = V_224 ;
V_219 = F_79 ( V_224 + 1 , V_37 ) ;
if ( ! V_219 ) {
F_80 ( L_7 ) ;
return;
}
V_220 = V_219 ;
F_71 ( * V_206 , L_8 , V_177 -> V_225 . V_226 ) ;
V_210 = V_209 ;
V_212 = 0 ;
V_211 = 0 ;
V_215 = true ;
V_216 = false ;
V_217 = 0 ;
V_218 = 0 ;
do {
if ( V_211 == 0 )
V_211 = F_81 ( V_31 , V_227 ) - 1 ;
if ( V_215 ) {
if ( V_220 != V_219 ) {
memmove ( V_219 , V_220 , V_212 ) ;
V_220 = V_219 ;
}
V_214 = F_82 ( & V_219 [ V_212 ] , V_31 ,
V_209 - V_212 ) ;
if ( V_214 == - V_228 ) {
F_83 ( V_229 , V_94 , 0 ) ;
goto V_230;
} else if ( V_214 == ( V_209 - V_212 ) ) {
V_215 = true ;
V_216 = true ;
V_211 = V_211 * 2 ;
V_31 += V_214 ;
} else {
V_215 = false ;
if ( ! V_216 )
V_216 = F_84 (
V_220 , V_214 ) ;
if ( V_211 < V_209 )
V_211 = ( V_216 ?
V_214 * 2 : V_214 ) ;
V_31 += V_214 + 1 ;
}
V_212 += V_214 ;
V_219 [ V_212 ] = '\0' ;
V_213 = ( V_216 ? V_212 * 2 : V_212 + 2 ) ;
}
if ( V_212 > 0 ) {
if ( ( sizeof( V_223 ) + 8 ) > V_210 ) {
V_210 = V_209 ;
F_76 ( * V_206 ) ;
* V_206 = F_70 ( V_177 ,
V_37 , V_231 ) ;
if ( ! * V_206 )
goto V_230;
}
V_214 = 0 ;
if ( V_215 || ( V_217 > 0 ) ||
( ( V_213 + sizeof( V_223 ) ) > V_210 ) ) {
if ( V_217 == 0 ) {
V_214 += snprintf ( & V_223 [ V_214 ] ,
sizeof( V_223 ) - V_214 ,
L_9 ,
V_218 , V_211 ) ;
}
V_214 += snprintf ( & V_223 [ V_214 ] ,
sizeof( V_223 ) - V_214 ,
L_10 , V_218 , V_217 ++ ) ;
} else
V_214 += snprintf ( & V_223 [ V_214 ] ,
sizeof( V_223 ) - V_214 ,
L_11 , V_218 ) ;
F_85 ( V_214 >= sizeof( V_223 ) ) ;
V_223 [ sizeof( V_223 ) - 1 ] = '\0' ;
F_71 ( * V_206 , L_12 , V_223 ) ;
V_210 -= V_214 ;
V_214 = V_212 ;
if ( V_216 ) {
if ( V_213 > V_210 )
V_214 = V_210 / 2 ;
F_86 ( * V_206 , V_220 , V_214 ) ;
V_210 -= V_214 * 2 ;
V_213 -= V_214 * 2 ;
} else {
if ( V_213 > V_210 )
V_214 = V_210 - 2 ;
F_87 ( * V_206 , V_220 , V_214 ) ;
V_210 -= V_214 + 2 ;
V_213 -= V_214 ;
}
V_212 -= V_214 ;
V_220 += V_214 ;
}
if ( ( V_212 == 0 ) && ! V_215 ) {
V_218 ++ ;
V_217 = 0 ;
V_211 = 0 ;
V_215 = true ;
V_216 = false ;
}
} while ( V_218 < V_177 -> V_225 . V_226 );
V_230:
F_17 ( V_219 ) ;
}
static void F_88 ( struct V_1 * V_177 , int * V_232 )
{
struct V_205 * V_206 ;
int V_90 ;
V_206 = F_70 ( V_177 , V_37 , V_177 -> type ) ;
if ( ! V_206 )
return;
switch ( V_177 -> type ) {
case V_233 : {
int V_234 = V_177 -> V_235 . V_234 ;
F_71 ( V_206 , L_13 , V_234 ) ;
for ( V_90 = 0 ; V_90 < V_234 ; V_90 ++ )
F_71 ( V_206 , L_14 , V_90 ,
V_177 -> V_235 . args [ V_90 ] ) ;
break; }
case V_148 : {
T_4 V_147 = V_177 -> V_149 . V_147 ;
F_71 ( V_206 , L_15 ,
F_72 ( & V_208 , V_177 -> V_149 . V_43 ) ,
F_89 ( & V_208 , V_177 -> V_149 . V_49 ) ,
V_177 -> V_149 . V_21 ) ;
if ( V_147 ) {
char * V_2 = NULL ;
T_4 V_188 ;
if ( F_73 ( V_147 , & V_2 , & V_188 ) ) {
F_71 ( V_206 , L_16 , V_147 ) ;
* V_232 = 1 ;
} else {
F_71 ( V_206 , L_5 , V_2 ) ;
F_74 ( V_2 , V_188 ) ;
}
}
if ( V_177 -> V_149 . V_236 ) {
F_76 ( V_206 ) ;
V_206 = F_70 ( V_177 , V_37 ,
V_237 ) ;
if ( F_2 ( ! V_206 ) )
return;
F_71 ( V_206 ,
L_17 ,
V_177 -> V_149 . V_238 ,
V_177 -> V_149 . V_239 ,
V_177 -> V_149 . V_240 ,
V_177 -> V_149 . V_241 ) ;
}
break; }
case V_242 : {
F_71 ( V_206 ,
L_18
L_19 ,
V_177 -> V_243 . V_244 , V_177 -> V_243 . V_21 ,
V_177 -> V_243 . V_245 . V_246 ,
V_177 -> V_243 . V_245 . V_247 ,
V_177 -> V_243 . V_245 . V_248 ,
V_177 -> V_243 . V_245 . V_249 ) ;
break; }
case V_250 : {
F_71 ( V_206 ,
L_20
L_21 ,
V_177 -> V_251 . V_252 ,
V_177 -> V_251 . V_253 ,
V_177 -> V_251 . V_254 ,
V_177 -> V_251 . V_255 . V_256 ,
V_177 -> V_251 . V_255 . V_257 ) ;
break; }
case V_258 : {
F_71 ( V_206 , L_22 ,
V_177 -> V_259 . V_252 ,
V_177 -> V_259 . V_260 ) ;
break; }
case V_261 : {
struct V_262 * V_245 = & V_177 -> V_263 . V_264 ;
F_71 ( V_206 ,
L_23
L_24 ,
V_177 -> V_263 . V_252 ,
V_245 -> V_246 , V_245 -> V_247 ,
V_245 -> V_248 , V_245 -> V_249 ) ;
break; }
case V_265 : {
F_71 ( V_206 , L_25 , V_177 -> V_266 . V_98 ) ;
F_90 ( V_206 , L_26 , & V_177 -> V_266 . V_267 . V_268 ) ;
F_90 ( V_206 , L_27 , & V_177 -> V_266 . V_267 . V_269 ) ;
F_90 ( V_206 , L_28 , & V_177 -> V_266 . V_267 . V_270 ) ;
break; }
case V_271 : {
F_71 ( V_206 , L_29 , V_177 -> V_272 . V_273 ,
V_177 -> V_272 . V_274 ) ;
break; }
case V_231 : {
F_77 ( V_177 , & V_206 ) ;
break; }
}
F_76 ( V_206 ) ;
}
static inline int F_91 ( char * V_186 , int V_188 )
{
char * V_275 = V_186 + V_188 - 1 ;
while ( V_275 > V_186 && ! isprint ( * V_275 ) )
V_275 -- ;
V_188 = V_275 - V_186 + 1 ;
V_188 -= isprint ( V_186 [ V_188 - 1 ] ) == 0 ;
return V_188 ;
}
static void F_92 ( struct V_50 * V_51 ,
struct V_1 * V_177 )
{
int V_276 ;
char * V_220 ;
char * V_277 = L_30 ;
int V_188 = strlen ( V_277 ) ;
struct V_205 * V_206 ;
V_206 = F_70 ( V_177 , V_37 , V_278 ) ;
if ( ! V_206 )
return;
F_71 ( V_206 , L_31 ) ;
if ( ! V_177 -> V_186 . V_187 ) {
V_220 = F_79 ( V_279 , V_37 ) ;
if ( ! V_220 )
goto V_230;
V_276 = F_93 ( V_51 , V_220 , V_279 ) ;
if ( V_276 == 0 ) {
F_17 ( V_220 ) ;
goto V_230;
}
V_276 = F_91 ( V_220 , V_276 ) ;
if ( V_276 == 0 ) {
F_17 ( V_220 ) ;
goto V_230;
}
V_177 -> V_186 . V_187 = V_220 ;
V_177 -> V_186 . V_188 = V_276 ;
}
V_277 = V_177 -> V_186 . V_187 ;
V_188 = V_177 -> V_186 . V_188 ;
V_230:
F_94 ( V_206 , V_277 , V_188 ) ;
F_76 ( V_206 ) ;
}
static void F_95 ( struct V_1 * V_177 , struct V_50 * V_51 )
{
int V_90 , V_232 = 0 ;
struct V_205 * V_206 ;
struct V_194 * V_195 ;
struct V_20 * V_4 ;
V_177 -> V_116 = V_51 -> V_116 ;
V_206 = F_70 ( V_177 , V_37 , V_280 ) ;
if ( ! V_206 )
return;
F_71 ( V_206 , L_32 ,
V_177 -> V_6 , V_177 -> V_5 ) ;
if ( V_177 -> V_116 != V_281 )
F_71 ( V_206 , L_33 , V_177 -> V_116 ) ;
if ( V_177 -> V_119 )
F_71 ( V_206 , L_34 ,
( V_177 -> V_119 == V_122 ) ? L_35 : L_36 ,
V_177 -> V_120 ) ;
F_71 ( V_206 ,
L_37 ,
V_177 -> V_16 [ 0 ] ,
V_177 -> V_16 [ 1 ] ,
V_177 -> V_16 [ 2 ] ,
V_177 -> V_16 [ 3 ] ,
V_177 -> V_190 ) ;
F_96 ( V_206 , V_51 ) ;
F_97 ( V_206 , V_177 -> V_158 ) ;
F_76 ( V_206 ) ;
for ( V_195 = V_177 -> V_195 ; V_195 ; V_195 = V_195 -> V_36 ) {
V_206 = F_70 ( V_177 , V_37 , V_195 -> type ) ;
if ( ! V_206 )
continue;
switch ( V_195 -> type ) {
case V_282 : {
struct V_283 * V_284 = ( void * ) V_195 ;
F_71 ( V_206 , L_38 , V_284 -> V_285 ) ;
F_90 ( V_206 , L_39 , & V_284 -> V_286 . V_269 ) ;
F_90 ( V_206 , L_40 , & V_284 -> V_286 . V_268 ) ;
F_71 ( V_206 , L_41 , V_284 -> V_286 . V_287 ) ;
F_90 ( V_206 , L_42 , & V_284 -> V_288 . V_269 ) ;
F_90 ( V_206 , L_43 , & V_284 -> V_288 . V_268 ) ;
F_90 ( V_206 , L_44 , & V_284 -> V_288 . V_270 ) ;
F_90 ( V_206 , L_45 , & V_284 -> V_289 . V_269 ) ;
F_90 ( V_206 , L_46 , & V_284 -> V_289 . V_268 ) ;
F_90 ( V_206 , L_47 , & V_284 -> V_289 . V_270 ) ;
break; }
}
F_76 ( V_206 ) ;
}
if ( V_177 -> type )
F_88 ( V_177 , & V_232 ) ;
if ( V_177 -> V_290 [ 0 ] >= 0 ) {
V_206 = F_70 ( V_177 , V_37 , V_291 ) ;
if ( V_206 ) {
F_71 ( V_206 , L_48 ,
V_177 -> V_290 [ 0 ] , V_177 -> V_290 [ 1 ] ) ;
F_76 ( V_206 ) ;
}
}
if ( V_177 -> V_292 ) {
V_206 = F_70 ( V_177 , V_37 , V_293 ) ;
if ( V_206 ) {
F_71 ( V_206 , L_49 ) ;
F_86 ( V_206 , ( void * ) V_177 -> V_202 ,
V_177 -> V_292 ) ;
F_76 ( V_206 ) ;
}
}
for ( V_195 = V_177 -> V_196 ; V_195 ; V_195 = V_195 -> V_36 ) {
struct V_294 * V_284 = ( void * ) V_195 ;
for ( V_90 = 0 ; V_90 < V_284 -> V_295 ; V_90 ++ )
if ( F_69 ( V_177 , V_284 -> V_296 [ V_90 ] ,
V_284 -> V_297 [ V_90 ] ,
V_284 -> V_298 [ V_90 ] ,
V_284 -> V_299 [ V_90 ] ,
V_284 -> V_300 [ V_90 ] ,
V_284 -> V_301 [ V_90 ] ) )
V_232 = 1 ;
}
if ( V_177 -> V_296 &&
F_69 ( V_177 , V_177 -> V_296 ,
V_177 -> V_297 , V_177 -> V_298 ,
V_177 -> V_299 ,
V_177 -> V_300 , V_177 -> V_301 ) )
V_232 = 1 ;
if ( V_177 -> V_191 . V_192 && V_177 -> V_191 . V_193 ) {
V_206 = F_70 ( V_177 , V_37 , V_302 ) ;
if ( V_206 ) {
F_98 ( V_206 , L_50 , & V_177 -> V_191 ) ;
F_76 ( V_206 ) ;
}
}
V_90 = 0 ;
F_7 (n, &context->names_list, list) {
if ( V_4 -> V_303 )
continue;
F_99 ( V_177 , V_4 , NULL , V_90 ++ , & V_232 ) ;
}
F_92 ( V_51 , V_177 ) ;
V_206 = F_70 ( V_177 , V_37 , V_304 ) ;
if ( V_206 )
F_76 ( V_206 ) ;
if ( V_232 )
F_80 ( L_51 ) ;
}
void F_100 ( struct V_50 * V_51 )
{
struct V_1 * V_177 ;
V_177 = F_54 ( V_51 , 0 , 0 ) ;
if ( ! V_177 )
return;
if ( V_177 -> V_182 && V_177 -> V_26 == V_27 )
F_95 ( V_177 , V_51 ) ;
if ( ! F_50 ( & V_177 -> V_197 ) )
F_101 ( & V_177 -> V_197 ) ;
F_68 ( V_177 ) ;
}
void F_102 ( int V_5 , unsigned long V_305 , unsigned long V_306 ,
unsigned long V_307 , unsigned long V_308 )
{
struct V_50 * V_51 = V_94 ;
struct V_1 * V_177 = V_51 -> V_1 ;
enum V_87 V_88 ;
if ( ! V_177 )
return;
F_103 ( V_177 -> V_182 || V_177 -> V_190 ) ;
if ( ! V_309 )
return;
V_177 -> V_6 = F_104 () ;
V_177 -> V_5 = V_5 ;
V_177 -> V_16 [ 0 ] = V_305 ;
V_177 -> V_16 [ 1 ] = V_306 ;
V_177 -> V_16 [ 2 ] = V_307 ;
V_177 -> V_16 [ 3 ] = V_308 ;
V_88 = V_177 -> V_88 ;
V_177 -> V_183 = ! V_310 ;
if ( ! V_177 -> V_183 && V_88 == V_167 ) {
V_177 -> V_25 = 0 ;
V_88 = F_49 ( V_51 , V_177 , & V_184 [ V_311 ] ) ;
}
if ( V_88 == V_162 )
return;
V_177 -> V_312 = 0 ;
V_177 -> ctime = V_313 ;
V_177 -> V_182 = 1 ;
V_177 -> V_26 = V_88 ;
V_177 -> V_101 = 0 ;
}
void F_105 ( int V_314 , long V_120 )
{
struct V_50 * V_51 = V_94 ;
struct V_1 * V_177 ;
if ( V_314 )
V_314 = V_122 ;
else
V_314 = V_123 ;
V_177 = F_54 ( V_51 , V_314 , V_120 ) ;
if ( ! V_177 )
return;
if ( V_177 -> V_182 && V_177 -> V_26 == V_27 )
F_95 ( V_177 , V_51 ) ;
V_177 -> V_182 = 0 ;
V_177 -> V_25 = V_177 -> V_88 == V_27 ? ~ 0ULL : 0 ;
if ( ! F_50 ( & V_177 -> V_197 ) )
F_101 ( & V_177 -> V_197 ) ;
F_56 ( V_177 ) ;
F_13 ( V_177 , NULL , 0 ) ;
F_61 ( V_177 ) ;
V_177 -> V_195 = NULL ;
V_177 -> V_196 = NULL ;
V_177 -> V_296 = 0 ;
V_177 -> V_300 = 0 ;
V_177 -> V_292 = 0 ;
V_177 -> type = 0 ;
V_177 -> V_290 [ 0 ] = - 1 ;
if ( V_177 -> V_88 != V_27 ) {
F_17 ( V_177 -> V_158 ) ;
V_177 -> V_158 = NULL ;
}
V_51 -> V_1 = V_177 ;
}
static inline void F_106 ( const struct V_315 * V_315 )
{
#ifdef F_14
struct V_1 * V_177 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
int V_39 ;
if ( F_10 ( F_107 ( & V_315 -> V_316 ) ) )
return;
V_177 = V_94 -> V_1 ;
V_31 = V_177 -> V_32 ;
V_39 = V_177 -> V_34 ;
F_43 () ;
V_29 = F_108 ( V_315 ) ;
F_45 () ;
if ( ! V_29 )
return;
if ( F_10 ( F_9 ( V_177 , V_29 ) ) )
return;
if ( F_2 ( ! F_11 ( V_177 ) ) ) {
F_109 ( L_52 ) ;
F_8 ( V_177 ) ;
F_15 ( V_29 ) ;
F_13 ( V_177 , V_31 , V_39 ) ;
return;
}
F_9 ( V_177 , V_29 ) ;
#endif
}
static void F_110 ( const struct V_192 * V_192 )
{
#ifdef F_14
struct V_1 * V_177 ;
struct V_30 * V_31 ;
const struct V_192 * V_317 , * V_318 ;
struct V_28 * V_319 ;
unsigned long V_320 ;
int V_39 ;
V_177 = V_94 -> V_1 ;
V_31 = V_177 -> V_32 ;
V_39 = V_177 -> V_34 ;
V_321:
V_319 = NULL ;
V_317 = V_192 ;
F_43 () ;
V_320 = F_111 ( & V_322 ) ;
for(; ; ) {
struct V_315 * V_315 = F_112 ( V_317 ) ;
if ( V_315 && F_2 ( ! F_107 ( & V_315 -> V_316 ) ) ) {
struct V_28 * V_29 ;
V_29 = F_108 ( V_315 ) ;
if ( V_29 ) {
if ( F_2 ( ! F_9 ( V_177 , V_29 ) ) ) {
V_319 = V_29 ;
break;
}
}
}
V_318 = V_317 -> V_323 ;
if ( V_318 == V_317 )
break;
V_317 = V_318 ;
}
if ( F_2 ( F_113 ( & V_322 , V_320 ) || V_319 ) ) {
F_45 () ;
if ( ! V_319 ) {
F_13 ( V_177 , V_31 , V_39 ) ;
goto V_321;
}
F_15 ( V_319 ) ;
if ( F_11 ( V_177 ) ) {
F_13 ( V_177 , V_31 , V_39 ) ;
goto V_321;
}
F_109 ( L_52 ) ;
F_13 ( V_177 , V_31 , V_39 ) ;
F_8 ( V_177 ) ;
return;
}
F_45 () ;
#endif
}
static struct V_20 * F_114 ( struct V_1 * V_177 ,
unsigned char type )
{
struct V_20 * V_324 ;
if ( V_177 -> V_190 < V_325 ) {
V_324 = & V_177 -> V_326 [ V_177 -> V_190 ] ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
} else {
V_324 = F_12 ( sizeof( * V_324 ) , V_327 ) ;
if ( ! V_324 )
return NULL ;
V_324 -> V_189 = true ;
}
V_324 -> V_22 = V_23 ;
V_324 -> type = type ;
F_115 ( & V_324 -> V_172 , & V_177 -> V_198 ) ;
V_177 -> V_190 ++ ;
return V_324 ;
}
struct V_328 *
F_116 ( const T_6 char * V_329 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
struct V_20 * V_4 ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 )
continue;
if ( V_4 -> V_44 -> V_329 == V_329 ) {
V_4 -> V_44 -> V_330 ++ ;
return V_4 -> V_44 ;
}
}
return NULL ;
}
void F_117 ( struct V_328 * V_44 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
struct V_20 * V_4 ;
if ( ! V_177 -> V_182 )
return;
V_4 = F_114 ( V_177 , V_331 ) ;
if ( ! V_4 )
return;
V_4 -> V_44 = V_44 ;
V_4 -> V_332 = V_333 ;
V_44 -> V_324 = V_4 ;
V_44 -> V_330 ++ ;
if ( ! V_177 -> V_191 . V_192 )
F_118 ( V_94 -> V_334 , & V_177 -> V_191 ) ;
}
void F_119 ( struct V_328 * V_44 , const struct V_192 * V_192 ,
unsigned int V_274 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
struct V_315 * V_315 = F_112 ( V_192 ) ;
struct V_20 * V_4 ;
bool V_318 = V_274 & V_335 ;
if ( ! V_177 -> V_182 )
return;
if ( ! V_44 )
goto V_336;
V_4 = V_44 -> V_324 ;
if ( V_4 ) {
if ( V_318 ) {
if ( V_4 -> type == V_337 ||
V_4 -> type == V_331 )
goto V_230;
} else {
if ( V_4 -> type != V_337 )
goto V_230;
}
}
F_120 (n, &context->names_list, list) {
if ( V_4 -> V_22 ) {
if ( V_4 -> V_22 != V_315 -> V_338 ||
V_4 -> V_125 != V_315 -> V_339 -> V_340 )
continue;
} else if ( V_4 -> V_44 ) {
if ( strcmp ( V_4 -> V_44 -> V_44 , V_44 -> V_44 ) )
continue;
} else
continue;
if ( V_318 ) {
if ( V_4 -> type == V_337 ||
V_4 -> type == V_331 )
goto V_230;
} else {
if ( V_4 -> type != V_337 )
goto V_230;
}
}
V_336:
V_4 = F_114 ( V_177 , V_331 ) ;
if ( ! V_4 )
return;
if ( V_44 ) {
V_4 -> V_44 = V_44 ;
V_44 -> V_330 ++ ;
}
V_230:
if ( V_318 ) {
V_4 -> V_332 = V_4 -> V_44 ? F_121 ( V_4 -> V_44 -> V_44 ) : V_333 ;
V_4 -> type = V_337 ;
if ( V_274 & V_341 )
V_4 -> V_303 = true ;
} else {
V_4 -> V_332 = V_333 ;
V_4 -> type = V_342 ;
}
F_110 ( V_192 ) ;
F_122 ( V_4 , V_192 , V_315 ) ;
}
void F_123 ( const struct V_343 * V_343 )
{
F_119 ( NULL , V_343 -> V_344 . V_192 , 0 ) ;
}
void F_124 ( struct V_315 * V_318 ,
const struct V_192 * V_192 ,
const unsigned char type )
{
struct V_1 * V_177 = V_94 -> V_1 ;
struct V_315 * V_315 = F_112 ( V_192 ) ;
const char * V_345 = V_192 -> V_346 . V_44 ;
struct V_20 * V_4 , * V_347 = NULL , * V_348 = NULL ;
if ( ! V_177 -> V_182 )
return;
if ( V_315 )
F_106 ( V_315 ) ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 ||
( V_4 -> type != V_337 &&
V_4 -> type != V_331 ) )
continue;
if ( V_4 -> V_22 == V_318 -> V_338 && V_4 -> V_125 == V_318 -> V_339 -> V_340 &&
! F_125 ( V_345 ,
V_4 -> V_44 -> V_44 , V_4 -> V_332 ) ) {
if ( V_4 -> type == V_331 )
V_4 -> type = V_337 ;
V_347 = V_4 ;
break;
}
}
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 ||
( V_4 -> type != type && V_4 -> type != V_331 ) )
continue;
if ( ! strcmp ( V_345 , V_4 -> V_44 -> V_44 ) ||
! F_125 ( V_345 , V_4 -> V_44 -> V_44 ,
V_347 ?
V_347 -> V_332 :
V_333 ) ) {
if ( V_4 -> type == V_331 )
V_4 -> type = type ;
V_348 = V_4 ;
break;
}
}
if ( ! V_347 ) {
V_4 = F_114 ( V_177 , V_337 ) ;
if ( ! V_4 )
return;
F_122 ( V_4 , NULL , V_318 ) ;
}
if ( ! V_348 ) {
V_348 = F_114 ( V_177 , type ) ;
if ( ! V_348 )
return;
if ( V_347 ) {
V_348 -> V_44 = V_347 -> V_44 ;
V_348 -> V_332 = V_333 ;
V_348 -> V_44 -> V_330 ++ ;
}
}
if ( V_315 )
F_122 ( V_348 , V_192 , V_315 ) ;
else
V_348 -> V_22 = V_23 ;
}
int F_126 ( struct V_1 * V_2 ,
struct V_349 * V_350 , unsigned int * V_312 )
{
if ( ! V_2 -> V_182 )
return 0 ;
if ( ! V_2 -> V_312 )
V_2 -> V_312 = F_127 () ;
V_350 -> V_256 = V_2 -> ctime . V_256 ;
V_350 -> V_257 = V_2 -> ctime . V_257 ;
* V_312 = V_2 -> V_312 ;
if ( ! V_2 -> V_25 ) {
V_2 -> V_25 = 1 ;
V_2 -> V_26 = V_27 ;
}
return 1 ;
}
static int F_128 ( T_2 V_60 )
{
if ( ! F_38 ( V_94 ) )
return 0 ;
if ( F_129 ( V_351 ) )
return - V_352 ;
if ( ! F_130 ( V_353 ) )
return - V_352 ;
if ( F_129 ( V_354 ) && F_131 ( V_60 ) )
return - V_352 ;
return 0 ;
}
static void F_132 ( T_2 V_355 , T_2 V_356 ,
unsigned int V_357 , unsigned int V_93 ,
int V_47 )
{
struct V_205 * V_206 ;
T_7 V_43 , V_358 , V_60 ;
struct V_359 * V_360 ;
if ( ! V_309 )
return;
V_206 = F_70 ( NULL , V_37 , V_361 ) ;
if ( ! V_206 )
return;
V_43 = F_72 ( & V_208 , F_133 ( V_94 ) ) ;
V_358 = F_72 ( & V_208 , V_355 ) ;
V_60 = F_72 ( & V_208 , V_356 ) ,
V_360 = F_134 ( V_94 ) ;
F_71 ( V_206 , L_53 , F_28 ( V_94 ) , V_43 ) ;
F_135 ( V_206 ) ;
F_71 ( V_206 , L_54 ,
V_358 , V_60 , V_360 ? F_136 ( V_360 ) : L_55 ,
V_357 , V_93 , ! V_47 ) ;
F_137 ( V_360 ) ;
F_76 ( V_206 ) ;
}
int F_138 ( T_2 V_60 )
{
struct V_50 * V_362 = V_94 ;
unsigned int V_357 , V_93 = ( unsigned int ) - 1 ;
T_2 V_358 ;
int V_47 ;
V_358 = F_139 ( V_94 ) ;
V_357 = F_34 ( V_94 ) ;
V_47 = F_128 ( V_60 ) ;
if ( V_47 )
goto V_230;
if ( F_131 ( V_60 ) ) {
V_93 = ( unsigned int ) F_140 ( & V_363 ) ;
if ( F_2 ( V_93 == ( unsigned int ) - 1 ) )
V_93 = ( unsigned int ) F_140 ( & V_363 ) ;
}
V_362 -> V_93 = V_93 ;
V_362 -> V_60 = V_60 ;
V_230:
F_132 ( V_358 , V_60 , V_357 , V_93 , V_47 ) ;
return V_47 ;
}
void F_141 ( int V_244 , T_1 V_21 , struct V_262 * V_245 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
if ( V_245 )
memcpy ( & V_177 -> V_243 . V_245 , V_245 , sizeof( struct V_262 ) ) ;
else
memset ( & V_177 -> V_243 . V_245 , 0 , sizeof( struct V_262 ) ) ;
V_177 -> V_243 . V_244 = V_244 ;
V_177 -> V_243 . V_21 = V_21 ;
V_177 -> type = V_242 ;
}
void F_142 ( T_8 V_252 , T_9 V_253 , unsigned int V_254 ,
const struct V_349 * V_255 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
struct V_349 * V_31 = & V_177 -> V_251 . V_255 ;
if ( V_255 )
memcpy ( V_31 , V_255 , sizeof( struct V_349 ) ) ;
else
memset ( V_31 , 0 , sizeof( struct V_349 ) ) ;
V_177 -> V_251 . V_252 = V_252 ;
V_177 -> V_251 . V_253 = V_253 ;
V_177 -> V_251 . V_254 = V_254 ;
V_177 -> type = V_250 ;
}
void F_143 ( T_8 V_252 , const struct V_364 * V_365 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
if ( V_365 )
V_177 -> V_259 . V_260 = V_365 -> V_260 ;
else
V_177 -> V_259 . V_260 = 0 ;
V_177 -> V_259 . V_252 = V_252 ;
V_177 -> type = V_258 ;
}
void F_144 ( T_8 V_252 , struct V_262 * V_264 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_263 . V_252 = V_252 ;
V_177 -> V_263 . V_264 = * V_264 ;
V_177 -> type = V_261 ;
}
void F_145 ( struct V_366 * V_367 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_149 . V_43 = V_367 -> V_43 ;
V_177 -> V_149 . V_49 = V_367 -> V_49 ;
V_177 -> V_149 . V_21 = V_367 -> V_21 ;
V_177 -> V_149 . V_236 = 0 ;
F_146 ( V_367 , & V_177 -> V_149 . V_147 ) ;
V_177 -> type = V_148 ;
}
void F_147 ( unsigned long V_238 , T_7 V_43 , T_10 V_49 , T_1 V_21 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_149 . V_238 = V_238 ;
V_177 -> V_149 . V_239 = V_43 ;
V_177 -> V_149 . V_240 = V_49 ;
V_177 -> V_149 . V_241 = V_21 ;
V_177 -> V_149 . V_236 = 1 ;
}
void F_148 ( struct V_368 * V_369 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> type = V_231 ;
V_177 -> V_225 . V_226 = V_369 -> V_226 ;
}
int F_149 ( int V_234 , unsigned long * args )
{
struct V_1 * V_177 = V_94 -> V_1 ;
if ( V_234 <= 0 || V_234 > V_370 || ! args )
return - V_371 ;
V_177 -> type = V_233 ;
V_177 -> V_235 . V_234 = V_234 ;
memcpy ( V_177 -> V_235 . args , args , V_234 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_150 ( int V_372 , int V_373 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_290 [ 0 ] = V_372 ;
V_177 -> V_290 [ 1 ] = V_373 ;
}
int F_151 ( int V_188 , void * V_374 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
if ( ! V_177 -> V_202 ) {
void * V_31 = F_79 ( sizeof( struct V_375 ) , V_37 ) ;
if ( ! V_31 )
return - V_201 ;
V_177 -> V_202 = V_31 ;
}
V_177 -> V_292 = V_188 ;
memcpy ( V_177 -> V_202 , V_374 , V_188 ) ;
return 0 ;
}
void F_152 ( struct V_50 * V_350 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_296 = F_28 ( V_350 ) ;
V_177 -> V_297 = F_139 ( V_350 ) ;
V_177 -> V_298 = F_133 ( V_350 ) ;
V_177 -> V_299 = F_34 ( V_350 ) ;
F_39 ( V_350 , & V_177 -> V_300 ) ;
memcpy ( V_177 -> V_301 , V_350 -> V_204 , V_376 ) ;
}
int F_153 ( int V_377 , struct V_50 * V_350 )
{
struct V_294 * V_378 ;
struct V_50 * V_51 = V_94 ;
struct V_1 * V_2 = V_51 -> V_1 ;
T_2 V_43 = F_154 () , V_379 = F_133 ( V_350 ) ;
if ( V_173 && V_350 -> V_174 == V_173 ) {
if ( V_377 == V_380 || V_377 == V_381 || V_377 == V_382 || V_377 == V_383 ) {
V_384 = F_28 ( V_51 ) ;
if ( F_131 ( V_51 -> V_60 ) )
V_385 = V_51 -> V_60 ;
else
V_385 = V_43 ;
F_39 ( V_51 , & V_386 ) ;
}
if ( ! V_387 || F_155 () )
return 0 ;
}
if ( ! V_2 -> V_296 ) {
V_2 -> V_296 = F_28 ( V_350 ) ;
V_2 -> V_297 = F_139 ( V_350 ) ;
V_2 -> V_298 = V_379 ;
V_2 -> V_299 = F_34 ( V_350 ) ;
F_39 ( V_350 , & V_2 -> V_300 ) ;
memcpy ( V_2 -> V_301 , V_350 -> V_204 , V_376 ) ;
return 0 ;
}
V_378 = ( void * ) V_2 -> V_196 ;
if ( ! V_378 || V_378 -> V_295 == V_388 ) {
V_378 = F_12 ( sizeof( * V_378 ) , V_159 ) ;
if ( ! V_378 )
return - V_201 ;
V_378 -> V_317 . type = V_207 ;
V_378 -> V_317 . V_36 = V_2 -> V_196 ;
V_2 -> V_196 = ( void * ) V_378 ;
}
F_103 ( V_378 -> V_295 >= V_388 ) ;
V_378 -> V_296 [ V_378 -> V_295 ] = F_28 ( V_350 ) ;
V_378 -> V_297 [ V_378 -> V_295 ] = F_139 ( V_350 ) ;
V_378 -> V_298 [ V_378 -> V_295 ] = V_379 ;
V_378 -> V_299 [ V_378 -> V_295 ] = F_34 ( V_350 ) ;
F_39 ( V_350 , & V_378 -> V_300 [ V_378 -> V_295 ] ) ;
memcpy ( V_378 -> V_301 [ V_378 -> V_295 ] , V_350 -> V_204 , V_376 ) ;
V_378 -> V_295 ++ ;
return 0 ;
}
int F_156 ( struct V_368 * V_369 ,
const struct V_52 * V_389 , const struct V_52 * V_390 )
{
struct V_283 * V_391 ;
struct V_1 * V_177 = V_94 -> V_1 ;
struct V_392 V_393 ;
V_391 = F_79 ( sizeof( * V_391 ) , V_37 ) ;
if ( ! V_391 )
return - V_201 ;
V_391 -> V_317 . type = V_282 ;
V_391 -> V_317 . V_36 = V_177 -> V_195 ;
V_177 -> V_195 = ( void * ) V_391 ;
F_157 ( V_369 -> V_343 -> V_344 . V_192 , & V_393 ) ;
V_391 -> V_286 . V_269 = V_393 . V_269 ;
V_391 -> V_286 . V_268 = V_393 . V_268 ;
V_391 -> V_286 . V_287 = ! ! ( V_393 . V_394 & V_395 ) ;
V_391 -> V_285 = ( V_393 . V_394 & V_396 ) >> V_397 ;
V_391 -> V_288 . V_269 = V_390 -> V_398 ;
V_391 -> V_288 . V_268 = V_390 -> V_399 ;
V_391 -> V_288 . V_270 = V_390 -> V_400 ;
V_391 -> V_289 . V_269 = V_389 -> V_398 ;
V_391 -> V_289 . V_268 = V_389 -> V_399 ;
V_391 -> V_289 . V_270 = V_389 -> V_400 ;
return 0 ;
}
void F_158 ( const struct V_52 * V_389 , const struct V_52 * V_390 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_266 . V_98 = F_28 ( V_94 ) ;
V_177 -> V_266 . V_267 . V_270 = V_389 -> V_400 ;
V_177 -> V_266 . V_267 . V_268 = V_389 -> V_400 ;
V_177 -> V_266 . V_267 . V_269 = V_389 -> V_398 ;
V_177 -> type = V_265 ;
}
void F_159 ( int V_273 , int V_274 )
{
struct V_1 * V_177 = V_94 -> V_1 ;
V_177 -> V_272 . V_273 = V_273 ;
V_177 -> V_272 . V_274 = V_274 ;
V_177 -> type = V_271 ;
}
static void F_160 ( struct V_205 * V_206 )
{
T_2 V_203 , V_43 ;
T_3 V_49 ;
unsigned int V_93 ;
char V_204 [ sizeof( V_94 -> V_204 ) ] ;
V_203 = F_139 ( V_94 ) ;
V_93 = F_34 ( V_94 ) ;
F_161 ( & V_43 , & V_49 ) ;
F_71 ( V_206 , L_56 ,
F_72 ( & V_208 , V_203 ) ,
F_72 ( & V_208 , V_43 ) ,
F_89 ( & V_208 , V_49 ) ,
V_93 ) ;
F_135 ( V_206 ) ;
F_71 ( V_206 , L_57 , F_28 ( V_94 ) ) ;
F_75 ( V_206 , F_162 ( V_204 , V_94 ) ) ;
F_163 ( V_206 , V_94 -> V_221 ) ;
}
void F_164 ( long V_401 )
{
struct V_205 * V_206 ;
if ( ! V_309 )
return;
if ( V_401 == V_402 )
return;
V_206 = F_70 ( NULL , V_37 , V_403 ) ;
if ( F_2 ( ! V_206 ) )
return;
F_160 ( V_206 ) ;
F_71 ( V_206 , L_58 , V_401 ) ;
F_76 ( V_206 ) ;
}
void F_165 ( unsigned long V_404 , long V_401 , int V_405 )
{
struct V_205 * V_206 ;
V_206 = F_70 ( NULL , V_37 , V_406 ) ;
if ( F_2 ( ! V_206 ) )
return;
F_160 ( V_206 ) ;
F_71 ( V_206 , L_59 ,
V_401 , F_104 () , V_404 ,
F_166 () , F_167 ( V_94 ) , V_405 ) ;
F_76 ( V_206 ) ;
}
struct V_171 * F_168 ( void )
{
struct V_1 * V_2 = V_94 -> V_1 ;
if ( F_10 ( ! V_2 || ! V_2 -> V_182 ) )
return NULL ;
return & V_2 -> V_197 ;
}
