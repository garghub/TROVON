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
if ( F_50 ( V_51 ) )
return V_162 ;
F_43 () ;
if ( ! F_51 ( V_172 ) ) {
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
static int F_52 ( struct V_50 * V_51 ,
struct V_20 * V_4 ,
struct V_1 * V_2 ) {
int V_173 = F_53 ( ( T_4 ) V_4 -> V_22 ) ;
struct V_171 * V_172 = & V_174 [ V_173 ] ;
struct V_165 * V_166 ;
enum V_87 V_88 ;
if ( F_51 ( V_172 ) )
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
void F_54 ( struct V_50 * V_51 , struct V_1 * V_2 )
{
struct V_20 * V_4 ;
if ( F_50 ( V_51 ) )
return;
F_43 () ;
F_7 (n, &ctx->names_list, list) {
if ( F_52 ( V_51 , V_4 , V_2 ) )
break;
}
F_45 () ;
}
static inline struct V_1 * F_55 ( struct V_50 * V_51 ,
int V_119 ,
long V_120 )
{
struct V_1 * V_175 = V_51 -> V_1 ;
if ( ! V_175 )
return NULL ;
V_175 -> V_119 = V_119 ;
if ( F_2 ( V_120 <= - V_176 ) &&
( V_120 >= - V_177 ) &&
( V_120 != - V_178 ) )
V_175 -> V_120 = - V_179 ;
else
V_175 -> V_120 = V_120 ;
if ( V_175 -> V_180 && ! V_175 -> V_181 ) {
F_49 ( V_51 , V_175 , & V_182 [ V_183 ] ) ;
F_54 ( V_51 , V_175 ) ;
}
V_51 -> V_1 = NULL ;
return V_175 ;
}
static inline void F_56 ( struct V_1 * V_175 )
{
F_17 ( V_175 -> V_184 . V_185 ) ;
V_175 -> V_184 . V_185 = NULL ;
V_175 -> V_184 . V_186 = 0 ;
}
static inline void F_57 ( struct V_1 * V_175 )
{
struct V_20 * V_4 , * V_36 ;
F_58 (n, next, &context->names_list, list) {
F_59 ( & V_4 -> V_172 ) ;
if ( V_4 -> V_44 )
F_60 ( V_4 -> V_44 ) ;
if ( V_4 -> V_187 )
F_17 ( V_4 ) ;
}
V_175 -> V_188 = 0 ;
F_61 ( & V_175 -> V_189 ) ;
V_175 -> V_189 . V_190 = NULL ;
V_175 -> V_189 . V_191 = NULL ;
}
static inline void F_62 ( struct V_1 * V_175 )
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
static inline struct V_1 * F_63 ( enum V_87 V_88 )
{
struct V_1 * V_175 ;
V_175 = F_12 ( sizeof( * V_175 ) , V_37 ) ;
if ( ! V_175 )
return NULL ;
V_175 -> V_88 = V_88 ;
V_175 -> V_25 = V_88 == V_27 ? ~ 0ULL : 0 ;
F_64 ( & V_175 -> V_195 ) ;
F_64 ( & V_175 -> V_196 ) ;
return V_175 ;
}
int F_65 ( struct V_50 * V_51 )
{
struct V_1 * V_175 ;
enum V_87 V_88 ;
char * V_164 = NULL ;
if ( F_10 ( ! V_197 ) )
return 0 ;
V_88 = F_42 ( V_51 , & V_164 ) ;
if ( V_88 == V_162 ) {
F_66 ( V_51 , V_198 ) ;
return 0 ;
}
if ( ! ( V_175 = F_63 ( V_88 ) ) ) {
F_17 ( V_164 ) ;
F_67 ( L_2 ) ;
return - V_199 ;
}
V_175 -> V_158 = V_164 ;
V_51 -> V_1 = V_175 ;
F_68 ( V_51 , V_198 ) ;
return 0 ;
}
static inline void F_69 ( struct V_1 * V_175 )
{
F_57 ( V_175 ) ;
F_13 ( V_175 , NULL , 0 ) ;
F_16 ( V_175 ) ;
F_62 ( V_175 ) ;
F_17 ( V_175 -> V_158 ) ;
F_17 ( V_175 -> V_200 ) ;
F_56 ( V_175 ) ;
F_17 ( V_175 ) ;
}
static int F_70 ( struct V_1 * V_175 , T_5 V_98 ,
T_2 V_201 , T_2 V_43 , unsigned int V_93 ,
T_4 V_92 , char * V_202 )
{
struct V_203 * V_204 ;
char * V_2 = NULL ;
T_4 V_186 ;
int V_47 = 0 ;
V_204 = F_71 ( V_175 , V_37 , V_205 ) ;
if ( ! V_204 )
return V_47 ;
F_72 ( V_204 , L_3 , V_98 ,
F_73 ( & V_206 , V_201 ) ,
F_73 ( & V_206 , V_43 ) , V_93 ) ;
if ( V_92 ) {
if ( F_74 ( V_92 , & V_2 , & V_186 ) ) {
F_72 ( V_204 , L_4 ) ;
V_47 = 1 ;
} else {
F_72 ( V_204 , L_5 , V_2 ) ;
F_75 ( V_2 , V_186 ) ;
}
}
F_72 ( V_204 , L_6 ) ;
F_76 ( V_204 , V_202 ) ;
F_77 ( V_204 ) ;
return V_47 ;
}
static void F_78 ( struct V_1 * V_175 ,
struct V_203 * * V_204 )
{
long V_207 ;
long V_208 ;
long V_209 ;
long V_210 ;
long V_211 = 0 ;
long V_212 ;
bool V_213 ;
bool V_214 ;
unsigned int V_215 ;
unsigned int V_216 ;
char * V_217 ;
char * V_218 ;
const char T_6 * V_31 = ( const char T_6 * ) V_94 -> V_219 -> V_220 ;
char V_221 [ 96 ] ;
F_79 ( V_222 > 7500 ) ;
V_207 = V_222 ;
V_217 = F_80 ( V_222 + 1 , V_37 ) ;
if ( ! V_217 ) {
F_81 ( L_7 ) ;
return;
}
V_218 = V_217 ;
F_72 ( * V_204 , L_8 , V_175 -> V_223 . V_224 ) ;
V_208 = V_207 ;
V_210 = 0 ;
V_209 = 0 ;
V_213 = true ;
V_214 = false ;
V_215 = 0 ;
V_216 = 0 ;
do {
if ( V_209 == 0 )
V_209 = F_82 ( V_31 , V_225 ) - 1 ;
if ( V_213 ) {
if ( V_218 != V_217 ) {
memmove ( V_217 , V_218 , V_210 ) ;
V_218 = V_217 ;
}
V_212 = F_83 ( & V_217 [ V_210 ] , V_31 ,
V_207 - V_210 ) ;
if ( V_212 == - V_226 ) {
F_84 ( V_227 , V_94 , 0 ) ;
goto V_228;
} else if ( V_212 == ( V_207 - V_210 ) ) {
V_213 = true ;
V_214 = true ;
V_209 = V_209 * 2 ;
V_31 += V_212 ;
} else {
V_213 = false ;
if ( ! V_214 )
V_214 = F_85 (
V_218 , V_212 ) ;
if ( V_209 < V_207 )
V_209 = ( V_214 ?
V_212 * 2 : V_212 ) ;
V_31 += V_212 + 1 ;
}
V_210 += V_212 ;
V_217 [ V_210 ] = '\0' ;
V_211 = ( V_214 ? V_210 * 2 : V_210 + 2 ) ;
}
if ( V_210 > 0 ) {
if ( ( sizeof( V_221 ) + 8 ) > V_208 ) {
V_208 = V_207 ;
F_77 ( * V_204 ) ;
* V_204 = F_71 ( V_175 ,
V_37 , V_229 ) ;
if ( ! * V_204 )
goto V_228;
}
V_212 = 0 ;
if ( V_213 || ( V_215 > 0 ) ||
( ( V_211 + sizeof( V_221 ) ) > V_208 ) ) {
if ( V_215 == 0 ) {
V_212 += snprintf ( & V_221 [ V_212 ] ,
sizeof( V_221 ) - V_212 ,
L_9 ,
V_216 , V_209 ) ;
}
V_212 += snprintf ( & V_221 [ V_212 ] ,
sizeof( V_221 ) - V_212 ,
L_10 , V_216 , V_215 ++ ) ;
} else
V_212 += snprintf ( & V_221 [ V_212 ] ,
sizeof( V_221 ) - V_212 ,
L_11 , V_216 ) ;
F_86 ( V_212 >= sizeof( V_221 ) ) ;
V_221 [ sizeof( V_221 ) - 1 ] = '\0' ;
F_72 ( * V_204 , L_12 , V_221 ) ;
V_208 -= V_212 ;
V_212 = V_210 ;
if ( V_214 ) {
if ( V_211 > V_208 )
V_212 = V_208 / 2 ;
F_87 ( * V_204 , V_218 , V_212 ) ;
V_208 -= V_212 * 2 ;
V_211 -= V_212 * 2 ;
} else {
if ( V_211 > V_208 )
V_212 = V_208 - 2 ;
F_88 ( * V_204 , V_218 , V_212 ) ;
V_208 -= V_212 + 2 ;
V_211 -= V_212 ;
}
V_210 -= V_212 ;
V_218 += V_212 ;
}
if ( ( V_210 == 0 ) && ! V_213 ) {
V_216 ++ ;
V_215 = 0 ;
V_209 = 0 ;
V_213 = true ;
V_214 = false ;
}
} while ( V_216 < V_175 -> V_223 . V_224 );
V_228:
F_17 ( V_217 ) ;
}
static void F_89 ( struct V_1 * V_175 , int * V_230 )
{
struct V_203 * V_204 ;
int V_90 ;
V_204 = F_71 ( V_175 , V_37 , V_175 -> type ) ;
if ( ! V_204 )
return;
switch ( V_175 -> type ) {
case V_231 : {
int V_232 = V_175 -> V_233 . V_232 ;
F_72 ( V_204 , L_13 , V_232 ) ;
for ( V_90 = 0 ; V_90 < V_232 ; V_90 ++ )
F_72 ( V_204 , L_14 , V_90 ,
V_175 -> V_233 . args [ V_90 ] ) ;
break; }
case V_148 : {
T_4 V_147 = V_175 -> V_149 . V_147 ;
F_72 ( V_204 , L_15 ,
F_73 ( & V_206 , V_175 -> V_149 . V_43 ) ,
F_90 ( & V_206 , V_175 -> V_149 . V_49 ) ,
V_175 -> V_149 . V_21 ) ;
if ( V_147 ) {
char * V_2 = NULL ;
T_4 V_186 ;
if ( F_74 ( V_147 , & V_2 , & V_186 ) ) {
F_72 ( V_204 , L_16 , V_147 ) ;
* V_230 = 1 ;
} else {
F_72 ( V_204 , L_5 , V_2 ) ;
F_75 ( V_2 , V_186 ) ;
}
}
if ( V_175 -> V_149 . V_234 ) {
F_77 ( V_204 ) ;
V_204 = F_71 ( V_175 , V_37 ,
V_235 ) ;
if ( F_2 ( ! V_204 ) )
return;
F_72 ( V_204 ,
L_17 ,
V_175 -> V_149 . V_236 ,
V_175 -> V_149 . V_237 ,
V_175 -> V_149 . V_238 ,
V_175 -> V_149 . V_239 ) ;
}
break; }
case V_240 :
F_72 ( V_204 ,
L_18
L_19 ,
V_175 -> V_241 . V_242 , V_175 -> V_241 . V_21 ,
V_175 -> V_241 . V_243 . V_244 ,
V_175 -> V_241 . V_243 . V_245 ,
V_175 -> V_241 . V_243 . V_246 ,
V_175 -> V_241 . V_243 . V_247 ) ;
break;
case V_248 :
F_72 ( V_204 ,
L_20
L_21 ,
V_175 -> V_249 . V_250 ,
V_175 -> V_249 . V_251 ,
V_175 -> V_249 . V_252 ,
V_175 -> V_249 . V_253 . V_254 ,
V_175 -> V_249 . V_253 . V_255 ) ;
break;
case V_256 :
F_72 ( V_204 , L_22 ,
V_175 -> V_257 . V_250 ,
V_175 -> V_257 . V_258 ) ;
break;
case V_259 : {
struct V_260 * V_243 = & V_175 -> V_261 . V_262 ;
F_72 ( V_204 ,
L_23
L_24 ,
V_175 -> V_261 . V_250 ,
V_243 -> V_244 , V_243 -> V_245 ,
V_243 -> V_246 , V_243 -> V_247 ) ;
break; }
case V_263 :
F_72 ( V_204 , L_25 , V_175 -> V_264 . V_98 ) ;
F_91 ( V_204 , L_26 , & V_175 -> V_264 . V_265 . V_266 ) ;
F_91 ( V_204 , L_27 , & V_175 -> V_264 . V_265 . V_267 ) ;
F_91 ( V_204 , L_28 , & V_175 -> V_264 . V_265 . V_268 ) ;
F_91 ( V_204 , L_29 , & V_175 -> V_264 . V_265 . V_269 ) ;
break;
case V_270 :
F_72 ( V_204 , L_30 , V_175 -> V_271 . V_272 ,
V_175 -> V_271 . V_273 ) ;
break;
case V_229 :
F_78 ( V_175 , & V_204 ) ;
break;
case V_274 :
F_72 ( V_204 , L_31 ) ;
F_76 ( V_204 , V_175 -> V_275 . V_44 ) ;
F_17 ( V_175 -> V_275 . V_44 ) ;
break;
}
F_77 ( V_204 ) ;
}
static inline int F_92 ( char * V_184 , int V_186 )
{
char * V_276 = V_184 + V_186 - 1 ;
while ( V_276 > V_184 && ! isprint ( * V_276 ) )
V_276 -- ;
V_186 = V_276 - V_184 + 1 ;
V_186 -= isprint ( V_184 [ V_186 - 1 ] ) == 0 ;
return V_186 ;
}
static void F_93 ( struct V_50 * V_51 ,
struct V_1 * V_175 )
{
int V_277 ;
char * V_218 ;
char * V_278 = L_32 ;
int V_186 = strlen ( V_278 ) ;
struct V_203 * V_204 ;
V_204 = F_71 ( V_175 , V_37 , V_279 ) ;
if ( ! V_204 )
return;
F_72 ( V_204 , L_33 ) ;
if ( ! V_175 -> V_184 . V_185 ) {
V_218 = F_80 ( V_280 , V_37 ) ;
if ( ! V_218 )
goto V_228;
V_277 = F_94 ( V_51 , V_218 , V_280 ) ;
if ( V_277 == 0 ) {
F_17 ( V_218 ) ;
goto V_228;
}
V_277 = F_92 ( V_218 , V_277 ) ;
if ( V_277 == 0 ) {
F_17 ( V_218 ) ;
goto V_228;
}
V_175 -> V_184 . V_185 = V_218 ;
V_175 -> V_184 . V_186 = V_277 ;
}
V_278 = V_175 -> V_184 . V_185 ;
V_186 = V_175 -> V_184 . V_186 ;
V_228:
F_95 ( V_204 , V_278 , V_186 ) ;
F_77 ( V_204 ) ;
}
static void F_96 ( struct V_1 * V_175 , struct V_50 * V_51 )
{
int V_90 , V_230 = 0 ;
struct V_203 * V_204 ;
struct V_192 * V_193 ;
struct V_20 * V_4 ;
V_175 -> V_116 = V_51 -> V_116 ;
V_204 = F_71 ( V_175 , V_37 , V_281 ) ;
if ( ! V_204 )
return;
F_72 ( V_204 , L_34 ,
V_175 -> V_6 , V_175 -> V_5 ) ;
if ( V_175 -> V_116 != V_282 )
F_72 ( V_204 , L_35 , V_175 -> V_116 ) ;
if ( V_175 -> V_119 )
F_72 ( V_204 , L_36 ,
( V_175 -> V_119 == V_122 ) ? L_37 : L_38 ,
V_175 -> V_120 ) ;
F_72 ( V_204 ,
L_39 ,
V_175 -> V_16 [ 0 ] ,
V_175 -> V_16 [ 1 ] ,
V_175 -> V_16 [ 2 ] ,
V_175 -> V_16 [ 3 ] ,
V_175 -> V_188 ) ;
F_97 ( V_204 , V_51 ) ;
F_98 ( V_204 , V_175 -> V_158 ) ;
F_77 ( V_204 ) ;
for ( V_193 = V_175 -> V_193 ; V_193 ; V_193 = V_193 -> V_36 ) {
V_204 = F_71 ( V_175 , V_37 , V_193 -> type ) ;
if ( ! V_204 )
continue;
switch ( V_193 -> type ) {
case V_283 : {
struct V_284 * V_285 = ( void * ) V_193 ;
F_72 ( V_204 , L_40 , V_285 -> V_286 ) ;
F_91 ( V_204 , L_41 , & V_285 -> V_287 . V_267 ) ;
F_91 ( V_204 , L_42 , & V_285 -> V_287 . V_266 ) ;
F_72 ( V_204 , L_43 , V_285 -> V_287 . V_288 ) ;
F_91 ( V_204 , L_44 , & V_285 -> V_289 . V_267 ) ;
F_91 ( V_204 , L_45 , & V_285 -> V_289 . V_266 ) ;
F_91 ( V_204 , L_46 , & V_285 -> V_289 . V_268 ) ;
F_91 ( V_204 , L_47 , & V_285 -> V_289 . V_269 ) ;
F_91 ( V_204 , L_48 , & V_285 -> V_290 . V_267 ) ;
F_91 ( V_204 , L_49 , & V_285 -> V_290 . V_266 ) ;
F_91 ( V_204 , L_50 , & V_285 -> V_290 . V_268 ) ;
F_91 ( V_204 , L_51 , & V_285 -> V_290 . V_269 ) ;
break; }
}
F_77 ( V_204 ) ;
}
if ( V_175 -> type )
F_89 ( V_175 , & V_230 ) ;
if ( V_175 -> V_291 [ 0 ] >= 0 ) {
V_204 = F_71 ( V_175 , V_37 , V_292 ) ;
if ( V_204 ) {
F_72 ( V_204 , L_52 ,
V_175 -> V_291 [ 0 ] , V_175 -> V_291 [ 1 ] ) ;
F_77 ( V_204 ) ;
}
}
if ( V_175 -> V_293 ) {
V_204 = F_71 ( V_175 , V_37 , V_294 ) ;
if ( V_204 ) {
F_72 ( V_204 , L_53 ) ;
F_87 ( V_204 , ( void * ) V_175 -> V_200 ,
V_175 -> V_293 ) ;
F_77 ( V_204 ) ;
}
}
for ( V_193 = V_175 -> V_194 ; V_193 ; V_193 = V_193 -> V_36 ) {
struct V_295 * V_285 = ( void * ) V_193 ;
for ( V_90 = 0 ; V_90 < V_285 -> V_296 ; V_90 ++ )
if ( F_70 ( V_175 , V_285 -> V_297 [ V_90 ] ,
V_285 -> V_298 [ V_90 ] ,
V_285 -> V_299 [ V_90 ] ,
V_285 -> V_300 [ V_90 ] ,
V_285 -> V_301 [ V_90 ] ,
V_285 -> V_302 [ V_90 ] ) )
V_230 = 1 ;
}
if ( V_175 -> V_297 &&
F_70 ( V_175 , V_175 -> V_297 ,
V_175 -> V_298 , V_175 -> V_299 ,
V_175 -> V_300 ,
V_175 -> V_301 , V_175 -> V_302 ) )
V_230 = 1 ;
if ( V_175 -> V_189 . V_190 && V_175 -> V_189 . V_191 ) {
V_204 = F_71 ( V_175 , V_37 , V_303 ) ;
if ( V_204 ) {
F_99 ( V_204 , L_54 , & V_175 -> V_189 ) ;
F_77 ( V_204 ) ;
}
}
V_90 = 0 ;
F_7 (n, &context->names_list, list) {
if ( V_4 -> V_304 )
continue;
F_100 ( V_175 , V_4 , NULL , V_90 ++ , & V_230 ) ;
}
F_93 ( V_51 , V_175 ) ;
V_204 = F_71 ( V_175 , V_37 , V_305 ) ;
if ( V_204 )
F_77 ( V_204 ) ;
if ( V_230 )
F_81 ( L_55 ) ;
}
void F_101 ( struct V_50 * V_51 )
{
struct V_1 * V_175 ;
V_175 = F_55 ( V_51 , 0 , 0 ) ;
if ( ! V_175 )
return;
if ( V_175 -> V_180 && V_175 -> V_26 == V_27 )
F_96 ( V_175 , V_51 ) ;
if ( ! F_51 ( & V_175 -> V_195 ) )
F_102 ( & V_175 -> V_195 ) ;
F_69 ( V_175 ) ;
}
void F_103 ( int V_5 , unsigned long V_306 , unsigned long V_307 ,
unsigned long V_308 , unsigned long V_309 )
{
struct V_50 * V_51 = V_94 ;
struct V_1 * V_175 = V_51 -> V_1 ;
enum V_87 V_88 ;
if ( ! V_175 )
return;
F_104 ( V_175 -> V_180 || V_175 -> V_188 ) ;
if ( ! V_310 )
return;
V_175 -> V_6 = F_105 () ;
V_175 -> V_5 = V_5 ;
V_175 -> V_16 [ 0 ] = V_306 ;
V_175 -> V_16 [ 1 ] = V_307 ;
V_175 -> V_16 [ 2 ] = V_308 ;
V_175 -> V_16 [ 3 ] = V_309 ;
V_88 = V_175 -> V_88 ;
V_175 -> V_181 = ! V_311 ;
if ( ! V_175 -> V_181 && V_88 == V_167 ) {
V_175 -> V_25 = 0 ;
V_88 = F_49 ( V_51 , V_175 , & V_182 [ V_312 ] ) ;
}
if ( V_88 == V_162 )
return;
V_175 -> V_313 = 0 ;
F_106 ( & V_175 -> ctime ) ;
V_175 -> V_180 = 1 ;
V_175 -> V_26 = V_88 ;
V_175 -> V_101 = 0 ;
}
void F_107 ( int V_314 , long V_120 )
{
struct V_50 * V_51 = V_94 ;
struct V_1 * V_175 ;
if ( V_314 )
V_314 = V_122 ;
else
V_314 = V_123 ;
V_175 = F_55 ( V_51 , V_314 , V_120 ) ;
if ( ! V_175 )
return;
if ( V_175 -> V_180 && V_175 -> V_26 == V_27 )
F_96 ( V_175 , V_51 ) ;
V_175 -> V_180 = 0 ;
V_175 -> V_25 = V_175 -> V_88 == V_27 ? ~ 0ULL : 0 ;
if ( ! F_51 ( & V_175 -> V_195 ) )
F_102 ( & V_175 -> V_195 ) ;
F_57 ( V_175 ) ;
F_13 ( V_175 , NULL , 0 ) ;
F_62 ( V_175 ) ;
V_175 -> V_193 = NULL ;
V_175 -> V_194 = NULL ;
V_175 -> V_297 = 0 ;
V_175 -> V_301 = 0 ;
V_175 -> V_293 = 0 ;
V_175 -> type = 0 ;
V_175 -> V_291 [ 0 ] = - 1 ;
if ( V_175 -> V_88 != V_27 ) {
F_17 ( V_175 -> V_158 ) ;
V_175 -> V_158 = NULL ;
}
V_51 -> V_1 = V_175 ;
}
static inline void F_108 ( const struct V_315 * V_315 )
{
#ifdef F_14
struct V_1 * V_175 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
int V_39 ;
if ( F_10 ( ! V_315 -> V_316 ) )
return;
V_175 = V_94 -> V_1 ;
V_31 = V_175 -> V_32 ;
V_39 = V_175 -> V_34 ;
F_43 () ;
V_29 = F_109 ( V_315 ) ;
F_45 () ;
if ( ! V_29 )
return;
if ( F_10 ( F_9 ( V_175 , V_29 ) ) )
return;
if ( F_2 ( ! F_11 ( V_175 ) ) ) {
F_110 ( L_56 ) ;
F_8 ( V_175 ) ;
F_15 ( V_29 ) ;
F_13 ( V_175 , V_31 , V_39 ) ;
return;
}
F_9 ( V_175 , V_29 ) ;
#endif
}
static void F_111 ( const struct V_190 * V_190 )
{
#ifdef F_14
struct V_1 * V_175 ;
struct V_30 * V_31 ;
const struct V_190 * V_317 , * V_318 ;
struct V_28 * V_319 ;
unsigned long V_320 ;
int V_39 ;
V_175 = V_94 -> V_1 ;
V_31 = V_175 -> V_32 ;
V_39 = V_175 -> V_34 ;
V_321:
V_319 = NULL ;
V_317 = V_190 ;
F_43 () ;
V_320 = F_112 ( & V_322 ) ;
for(; ; ) {
struct V_315 * V_315 = F_113 ( V_317 ) ;
if ( V_315 && F_2 ( V_315 -> V_316 ) ) {
struct V_28 * V_29 ;
V_29 = F_109 ( V_315 ) ;
if ( V_29 ) {
if ( F_2 ( ! F_9 ( V_175 , V_29 ) ) ) {
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
if ( F_2 ( F_114 ( & V_322 , V_320 ) || V_319 ) ) {
F_45 () ;
if ( ! V_319 ) {
F_13 ( V_175 , V_31 , V_39 ) ;
goto V_321;
}
F_15 ( V_319 ) ;
if ( F_11 ( V_175 ) ) {
F_13 ( V_175 , V_31 , V_39 ) ;
goto V_321;
}
F_110 ( L_56 ) ;
F_13 ( V_175 , V_31 , V_39 ) ;
F_8 ( V_175 ) ;
return;
}
F_45 () ;
#endif
}
static struct V_20 * F_115 ( struct V_1 * V_175 ,
unsigned char type )
{
struct V_20 * V_324 ;
if ( V_175 -> V_188 < V_325 ) {
V_324 = & V_175 -> V_326 [ V_175 -> V_188 ] ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
} else {
V_324 = F_12 ( sizeof( * V_324 ) , V_327 ) ;
if ( ! V_324 )
return NULL ;
V_324 -> V_187 = true ;
}
V_324 -> V_22 = V_23 ;
V_324 -> type = type ;
F_116 ( & V_324 -> V_172 , & V_175 -> V_196 ) ;
V_175 -> V_188 ++ ;
return V_324 ;
}
struct V_328 *
F_117 ( const T_6 char * V_329 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
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
void F_118 ( struct V_328 * V_44 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
struct V_20 * V_4 ;
if ( ! V_175 -> V_180 )
return;
V_4 = F_115 ( V_175 , V_331 ) ;
if ( ! V_4 )
return;
V_4 -> V_44 = V_44 ;
V_4 -> V_332 = V_333 ;
V_44 -> V_324 = V_4 ;
V_44 -> V_330 ++ ;
if ( ! V_175 -> V_189 . V_190 )
F_119 ( V_94 -> V_334 , & V_175 -> V_189 ) ;
}
void F_120 ( struct V_328 * V_44 , const struct V_190 * V_190 ,
unsigned int V_273 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
struct V_315 * V_315 = F_113 ( V_190 ) ;
struct V_20 * V_4 ;
bool V_318 = V_273 & V_335 ;
if ( ! V_175 -> V_180 )
return;
if ( ! V_44 )
goto V_336;
V_4 = V_44 -> V_324 ;
if ( V_4 ) {
if ( V_318 ) {
if ( V_4 -> type == V_337 ||
V_4 -> type == V_331 )
goto V_228;
} else {
if ( V_4 -> type != V_337 )
goto V_228;
}
}
F_121 (n, &context->names_list, list) {
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
goto V_228;
} else {
if ( V_4 -> type != V_337 )
goto V_228;
}
}
V_336:
V_4 = F_115 ( V_175 , V_331 ) ;
if ( ! V_4 )
return;
if ( V_44 ) {
V_4 -> V_44 = V_44 ;
V_44 -> V_330 ++ ;
}
V_228:
if ( V_318 ) {
V_4 -> V_332 = V_4 -> V_44 ? F_122 ( V_4 -> V_44 -> V_44 ) : V_333 ;
V_4 -> type = V_337 ;
if ( V_273 & V_341 )
V_4 -> V_304 = true ;
} else {
V_4 -> V_332 = V_333 ;
V_4 -> type = V_342 ;
}
F_111 ( V_190 ) ;
F_123 ( V_4 , V_190 , V_315 ) ;
}
void F_124 ( const struct V_343 * V_343 )
{
F_120 ( NULL , V_343 -> V_344 . V_190 , 0 ) ;
}
void F_125 ( struct V_315 * V_318 ,
const struct V_190 * V_190 ,
const unsigned char type )
{
struct V_1 * V_175 = V_94 -> V_1 ;
struct V_315 * V_315 = F_113 ( V_190 ) ;
const char * V_345 = V_190 -> V_346 . V_44 ;
struct V_20 * V_4 , * V_347 = NULL , * V_348 = NULL ;
if ( ! V_175 -> V_180 )
return;
if ( V_315 )
F_108 ( V_315 ) ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_44 ||
( V_4 -> type != V_337 &&
V_4 -> type != V_331 ) )
continue;
if ( V_4 -> V_22 == V_318 -> V_338 && V_4 -> V_125 == V_318 -> V_339 -> V_340 &&
! F_126 ( V_345 ,
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
! F_126 ( V_345 , V_4 -> V_44 -> V_44 ,
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
V_4 = F_115 ( V_175 , V_337 ) ;
if ( ! V_4 )
return;
F_123 ( V_4 , NULL , V_318 ) ;
}
if ( ! V_348 ) {
V_348 = F_115 ( V_175 , type ) ;
if ( ! V_348 )
return;
if ( V_347 ) {
V_348 -> V_44 = V_347 -> V_44 ;
V_348 -> V_332 = V_333 ;
V_348 -> V_44 -> V_330 ++ ;
}
}
if ( V_315 )
F_123 ( V_348 , V_190 , V_315 ) ;
else
V_348 -> V_22 = V_23 ;
}
int F_127 ( struct V_1 * V_2 ,
struct V_349 * V_350 , unsigned int * V_313 )
{
if ( ! V_2 -> V_180 )
return 0 ;
if ( ! V_2 -> V_313 )
V_2 -> V_313 = F_128 () ;
V_350 -> V_254 = V_2 -> ctime . V_254 ;
V_350 -> V_255 = V_2 -> ctime . V_255 ;
* V_313 = V_2 -> V_313 ;
if ( ! V_2 -> V_25 ) {
V_2 -> V_25 = 1 ;
V_2 -> V_26 = V_27 ;
}
return 1 ;
}
static int F_129 ( T_2 V_60 )
{
if ( ! F_38 ( V_94 ) )
return 0 ;
if ( F_130 ( V_351 ) )
return - V_352 ;
if ( ! F_131 ( V_353 ) )
return - V_352 ;
if ( F_130 ( V_354 ) && F_132 ( V_60 ) )
return - V_352 ;
return 0 ;
}
static void F_133 ( T_2 V_355 , T_2 V_356 ,
unsigned int V_357 , unsigned int V_93 ,
int V_47 )
{
struct V_203 * V_204 ;
T_7 V_43 , V_358 , V_60 ;
struct V_359 * V_360 ;
if ( ! V_310 )
return;
V_204 = F_71 ( NULL , V_37 , V_361 ) ;
if ( ! V_204 )
return;
V_43 = F_73 ( & V_206 , F_134 ( V_94 ) ) ;
V_358 = F_73 ( & V_206 , V_355 ) ;
V_60 = F_73 ( & V_206 , V_356 ) ,
V_360 = F_135 ( V_94 ) ;
F_72 ( V_204 , L_57 , F_28 ( V_94 ) , V_43 ) ;
F_136 ( V_204 ) ;
F_72 ( V_204 , L_58 ,
V_358 , V_60 , V_360 ? F_137 ( V_360 ) : L_59 ,
V_357 , V_93 , ! V_47 ) ;
F_138 ( V_360 ) ;
F_77 ( V_204 ) ;
}
int F_139 ( T_2 V_60 )
{
struct V_50 * V_362 = V_94 ;
unsigned int V_357 , V_93 = ( unsigned int ) - 1 ;
T_2 V_358 ;
int V_47 ;
V_358 = F_140 ( V_94 ) ;
V_357 = F_34 ( V_94 ) ;
V_47 = F_129 ( V_60 ) ;
if ( V_47 )
goto V_228;
if ( F_132 ( V_60 ) ) {
V_93 = ( unsigned int ) F_141 ( & V_363 ) ;
if ( F_2 ( V_93 == ( unsigned int ) - 1 ) )
V_93 = ( unsigned int ) F_141 ( & V_363 ) ;
}
V_362 -> V_93 = V_93 ;
V_362 -> V_60 = V_60 ;
V_228:
F_133 ( V_358 , V_60 , V_357 , V_93 , V_47 ) ;
return V_47 ;
}
void F_142 ( int V_242 , T_1 V_21 , struct V_260 * V_243 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
if ( V_243 )
memcpy ( & V_175 -> V_241 . V_243 , V_243 , sizeof( struct V_260 ) ) ;
else
memset ( & V_175 -> V_241 . V_243 , 0 , sizeof( struct V_260 ) ) ;
V_175 -> V_241 . V_242 = V_242 ;
V_175 -> V_241 . V_21 = V_21 ;
V_175 -> type = V_240 ;
}
void F_143 ( T_8 V_250 , T_9 V_251 , unsigned int V_252 ,
const struct V_364 * V_253 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
struct V_364 * V_31 = & V_175 -> V_249 . V_253 ;
if ( V_253 )
memcpy ( V_31 , V_253 , sizeof( struct V_364 ) ) ;
else
memset ( V_31 , 0 , sizeof( struct V_364 ) ) ;
V_175 -> V_249 . V_250 = V_250 ;
V_175 -> V_249 . V_251 = V_251 ;
V_175 -> V_249 . V_252 = V_252 ;
V_175 -> type = V_248 ;
}
void F_144 ( T_8 V_250 , const struct V_365 * V_366 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
if ( V_366 )
V_175 -> V_257 . V_258 = V_366 -> V_258 ;
else
V_175 -> V_257 . V_258 = 0 ;
V_175 -> V_257 . V_250 = V_250 ;
V_175 -> type = V_256 ;
}
void F_145 ( T_8 V_250 , struct V_260 * V_262 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_261 . V_250 = V_250 ;
V_175 -> V_261 . V_262 = * V_262 ;
V_175 -> type = V_259 ;
}
void F_146 ( struct V_367 * V_368 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_149 . V_43 = V_368 -> V_43 ;
V_175 -> V_149 . V_49 = V_368 -> V_49 ;
V_175 -> V_149 . V_21 = V_368 -> V_21 ;
V_175 -> V_149 . V_234 = 0 ;
F_147 ( V_368 , & V_175 -> V_149 . V_147 ) ;
V_175 -> type = V_148 ;
}
void F_148 ( unsigned long V_236 , T_7 V_43 , T_10 V_49 , T_1 V_21 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_149 . V_236 = V_236 ;
V_175 -> V_149 . V_237 = V_43 ;
V_175 -> V_149 . V_238 = V_49 ;
V_175 -> V_149 . V_239 = V_21 ;
V_175 -> V_149 . V_234 = 1 ;
}
void F_149 ( struct V_369 * V_370 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> type = V_229 ;
V_175 -> V_223 . V_224 = V_370 -> V_224 ;
}
int F_150 ( int V_232 , unsigned long * args )
{
struct V_1 * V_175 = V_94 -> V_1 ;
if ( V_232 <= 0 || V_232 > V_371 || ! args )
return - V_372 ;
V_175 -> type = V_231 ;
V_175 -> V_233 . V_232 = V_232 ;
memcpy ( V_175 -> V_233 . args , args , V_232 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_151 ( int V_373 , int V_374 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_291 [ 0 ] = V_373 ;
V_175 -> V_291 [ 1 ] = V_374 ;
}
int F_152 ( int V_186 , void * V_375 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
if ( ! V_175 -> V_200 ) {
void * V_31 = F_80 ( sizeof( struct V_376 ) , V_37 ) ;
if ( ! V_31 )
return - V_199 ;
V_175 -> V_200 = V_31 ;
}
V_175 -> V_293 = V_186 ;
memcpy ( V_175 -> V_200 , V_375 , V_186 ) ;
return 0 ;
}
void F_153 ( struct V_50 * V_350 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_297 = F_28 ( V_350 ) ;
V_175 -> V_298 = F_140 ( V_350 ) ;
V_175 -> V_299 = F_134 ( V_350 ) ;
V_175 -> V_300 = F_34 ( V_350 ) ;
F_39 ( V_350 , & V_175 -> V_301 ) ;
memcpy ( V_175 -> V_302 , V_350 -> V_202 , V_377 ) ;
}
int F_154 ( int V_378 , struct V_50 * V_350 )
{
struct V_295 * V_379 ;
struct V_50 * V_51 = V_94 ;
struct V_1 * V_2 = V_51 -> V_1 ;
T_2 V_43 = F_155 () , V_380 = F_134 ( V_350 ) ;
if ( F_50 ( V_350 ) &&
( V_378 == V_381 || V_378 == V_382 ||
V_378 == V_383 || V_378 == V_384 ) ) {
V_385 = F_28 ( V_51 ) ;
if ( F_132 ( V_51 -> V_60 ) )
V_386 = V_51 -> V_60 ;
else
V_386 = V_43 ;
F_39 ( V_51 , & V_387 ) ;
}
if ( ! V_388 || F_156 () )
return 0 ;
if ( ! V_2 -> V_297 ) {
V_2 -> V_297 = F_28 ( V_350 ) ;
V_2 -> V_298 = F_140 ( V_350 ) ;
V_2 -> V_299 = V_380 ;
V_2 -> V_300 = F_34 ( V_350 ) ;
F_39 ( V_350 , & V_2 -> V_301 ) ;
memcpy ( V_2 -> V_302 , V_350 -> V_202 , V_377 ) ;
return 0 ;
}
V_379 = ( void * ) V_2 -> V_194 ;
if ( ! V_379 || V_379 -> V_296 == V_389 ) {
V_379 = F_12 ( sizeof( * V_379 ) , V_159 ) ;
if ( ! V_379 )
return - V_199 ;
V_379 -> V_317 . type = V_205 ;
V_379 -> V_317 . V_36 = V_2 -> V_194 ;
V_2 -> V_194 = ( void * ) V_379 ;
}
F_104 ( V_379 -> V_296 >= V_389 ) ;
V_379 -> V_297 [ V_379 -> V_296 ] = F_28 ( V_350 ) ;
V_379 -> V_298 [ V_379 -> V_296 ] = F_140 ( V_350 ) ;
V_379 -> V_299 [ V_379 -> V_296 ] = V_380 ;
V_379 -> V_300 [ V_379 -> V_296 ] = F_34 ( V_350 ) ;
F_39 ( V_350 , & V_379 -> V_301 [ V_379 -> V_296 ] ) ;
memcpy ( V_379 -> V_302 [ V_379 -> V_296 ] , V_350 -> V_202 , V_377 ) ;
V_379 -> V_296 ++ ;
return 0 ;
}
int F_157 ( struct V_369 * V_370 ,
const struct V_52 * V_390 , const struct V_52 * V_391 )
{
struct V_284 * V_392 ;
struct V_1 * V_175 = V_94 -> V_1 ;
struct V_393 V_394 ;
V_392 = F_80 ( sizeof( * V_392 ) , V_37 ) ;
if ( ! V_392 )
return - V_199 ;
V_392 -> V_317 . type = V_283 ;
V_392 -> V_317 . V_36 = V_175 -> V_193 ;
V_175 -> V_193 = ( void * ) V_392 ;
F_158 ( V_370 -> V_343 -> V_344 . V_190 , & V_394 ) ;
V_392 -> V_287 . V_267 = V_394 . V_267 ;
V_392 -> V_287 . V_266 = V_394 . V_266 ;
V_392 -> V_287 . V_288 = ! ! ( V_394 . V_395 & V_396 ) ;
V_392 -> V_286 = ( V_394 . V_395 & V_397 ) >> V_398 ;
V_392 -> V_289 . V_267 = V_391 -> V_399 ;
V_392 -> V_289 . V_266 = V_391 -> V_400 ;
V_392 -> V_289 . V_268 = V_391 -> V_401 ;
V_392 -> V_289 . V_269 = V_391 -> V_402 ;
V_392 -> V_290 . V_267 = V_390 -> V_399 ;
V_392 -> V_290 . V_266 = V_390 -> V_400 ;
V_392 -> V_290 . V_268 = V_390 -> V_401 ;
V_392 -> V_290 . V_269 = V_390 -> V_402 ;
return 0 ;
}
void F_159 ( const struct V_52 * V_390 , const struct V_52 * V_391 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_264 . V_98 = F_28 ( V_94 ) ;
V_175 -> V_264 . V_265 . V_268 = V_390 -> V_401 ;
V_175 -> V_264 . V_265 . V_266 = V_390 -> V_401 ;
V_175 -> V_264 . V_265 . V_267 = V_390 -> V_399 ;
V_175 -> V_264 . V_265 . V_269 = V_390 -> V_402 ;
V_175 -> type = V_263 ;
}
void F_160 ( int V_272 , int V_273 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_271 . V_272 = V_272 ;
V_175 -> V_271 . V_273 = V_273 ;
V_175 -> type = V_270 ;
}
void F_161 ( char * V_44 )
{
struct V_1 * V_175 = V_94 -> V_1 ;
V_175 -> V_275 . V_44 = F_80 ( strlen ( V_44 ) + 1 , V_37 ) ;
strcpy ( V_175 -> V_275 . V_44 , V_44 ) ;
V_175 -> type = V_274 ;
}
static void F_162 ( struct V_203 * V_204 )
{
T_2 V_201 , V_43 ;
T_3 V_49 ;
unsigned int V_93 ;
char V_202 [ sizeof( V_94 -> V_202 ) ] ;
V_201 = F_140 ( V_94 ) ;
V_93 = F_34 ( V_94 ) ;
F_163 ( & V_43 , & V_49 ) ;
F_72 ( V_204 , L_60 ,
F_73 ( & V_206 , V_201 ) ,
F_73 ( & V_206 , V_43 ) ,
F_90 ( & V_206 , V_49 ) ,
V_93 ) ;
F_136 ( V_204 ) ;
F_72 ( V_204 , L_61 , F_28 ( V_94 ) ) ;
F_76 ( V_204 , F_164 ( V_202 , V_94 ) ) ;
F_165 ( V_204 , V_94 -> V_219 ) ;
}
void F_166 ( long V_403 )
{
struct V_203 * V_204 ;
if ( ! V_310 )
return;
if ( V_403 == V_404 )
return;
V_204 = F_71 ( NULL , V_37 , V_405 ) ;
if ( F_2 ( ! V_204 ) )
return;
F_162 ( V_204 ) ;
F_72 ( V_204 , L_62 , V_403 ) ;
F_77 ( V_204 ) ;
}
void F_167 ( unsigned long V_406 , long V_403 , int V_407 )
{
struct V_203 * V_204 ;
V_204 = F_71 ( NULL , V_37 , V_408 ) ;
if ( F_2 ( ! V_204 ) )
return;
F_162 ( V_204 ) ;
F_72 ( V_204 , L_63 ,
V_403 , F_105 () , V_406 ,
F_168 () , F_169 ( V_94 ) , V_407 ) ;
F_77 ( V_204 ) ;
}
struct V_171 * F_170 ( void )
{
struct V_1 * V_2 = V_94 -> V_1 ;
if ( F_10 ( ! V_2 || ! V_2 -> V_180 ) )
return NULL ;
return & V_2 -> V_195 ;
}
