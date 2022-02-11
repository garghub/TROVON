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
unsigned long V_47 ,
struct V_48 * V_49 ,
struct V_7 * V_8 )
{
struct V_23 * V_3 ;
unsigned long V_50 ;
T_2 V_51 ;
int V_52 ;
F_22 ( sizeof( T_2 ) != sizeof( V_53 ) ) ;
if ( V_46 ) {
V_50 = ( unsigned long ) V_46 ;
V_50 += V_47 ;
V_51 = * ( T_2 * ) V_50 ;
V_52 = F_23 ( V_45 , V_49 -> V_54 , V_51 ) ;
if ( V_52 )
return V_52 ;
}
if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
V_50 = ( unsigned long ) V_3 ;
V_50 += V_47 ;
V_51 = * ( T_2 * ) V_50 ;
V_52 = F_23 ( V_45 , V_49 -> V_54 , V_51 ) ;
if ( V_52 )
return V_52 ;
}
}
return 0 ;
}
static int F_24 ( struct V_55 * V_56 ,
const struct V_57 * V_57 ,
struct V_48 * V_49 ,
struct V_7 * V_8 ,
struct V_23 * V_46 )
{
switch ( V_49 -> V_22 ) {
case V_58 :
return F_21 ( V_57 -> V_59 ,
V_46 , F_25 ( struct V_23 , V_59 ) ,
V_49 , V_8 ) ;
case V_60 :
return F_21 ( V_57 -> V_61 ,
V_46 , F_25 ( struct V_23 , V_61 ) ,
V_49 , V_8 ) ;
case V_62 :
return F_21 ( V_57 -> V_63 ,
V_46 , F_25 ( struct V_23 , V_59 ) ,
V_49 , V_8 ) ;
case V_64 :
return F_21 ( V_57 -> V_65 ,
V_46 , F_25 ( struct V_23 , V_61 ) ,
V_49 , V_8 ) ;
case V_66 :
return F_21 ( V_56 -> V_67 ,
V_46 , F_25 ( struct V_23 , V_59 ) ,
V_49 , V_8 ) ;
case V_68 :
return F_21 ( V_57 -> V_69 ,
V_46 , F_25 ( struct V_23 , V_59 ) ,
V_49 , V_8 ) ;
case V_70 :
return F_21 ( V_57 -> V_71 ,
V_46 , F_25 ( struct V_23 , V_61 ) ,
V_49 , V_8 ) ;
case V_72 :
return F_21 ( V_57 -> V_73 ,
V_46 , F_25 ( struct V_23 , V_59 ) ,
V_49 , V_8 ) ;
case V_74 :
return F_21 ( V_57 -> V_75 ,
V_46 , F_25 ( struct V_23 , V_61 ) ,
V_49 , V_8 ) ;
case V_76 :
return F_23 ( V_57 -> V_59 , V_49 -> V_54 , V_56 -> V_67 ) ;
case V_77 :
return F_23 ( V_57 -> V_59 , V_49 -> V_54 , V_57 -> V_63 ) ;
case V_78 :
return F_23 ( V_57 -> V_59 , V_49 -> V_54 , V_57 -> V_69 ) ;
case V_79 :
return F_23 ( V_57 -> V_59 , V_49 -> V_54 , V_57 -> V_73 ) ;
case V_80 :
return F_23 ( V_56 -> V_67 , V_49 -> V_54 , V_57 -> V_63 ) ;
case V_81 :
return F_23 ( V_56 -> V_67 , V_49 -> V_54 , V_57 -> V_69 ) ;
case V_82 :
return F_23 ( V_56 -> V_67 , V_49 -> V_54 , V_57 -> V_73 ) ;
case V_83 :
return F_23 ( V_57 -> V_63 , V_49 -> V_54 , V_57 -> V_69 ) ;
case V_84 :
return F_23 ( V_57 -> V_63 , V_49 -> V_54 , V_57 -> V_73 ) ;
case V_85 :
return F_23 ( V_57 -> V_69 , V_49 -> V_54 , V_57 -> V_73 ) ;
case V_86 :
return F_23 ( V_57 -> V_61 , V_49 -> V_54 , V_57 -> V_65 ) ;
case V_87 :
return F_23 ( V_57 -> V_61 , V_49 -> V_54 , V_57 -> V_71 ) ;
case V_88 :
return F_23 ( V_57 -> V_61 , V_49 -> V_54 , V_57 -> V_75 ) ;
case V_89 :
return F_23 ( V_57 -> V_65 , V_49 -> V_54 , V_57 -> V_71 ) ;
case V_90 :
return F_23 ( V_57 -> V_65 , V_49 -> V_54 , V_57 -> V_75 ) ;
case V_91 :
return F_23 ( V_57 -> V_71 , V_49 -> V_54 , V_57 -> V_75 ) ;
default:
F_26 ( 1 , L_1 ) ;
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_55 * V_56 ,
struct V_92 * V_93 ,
struct V_7 * V_8 ,
struct V_23 * V_46 ,
enum V_94 * V_95 ,
bool V_96 )
{
const struct V_57 * V_57 ;
int V_97 , V_98 = 1 ;
T_3 V_99 ;
V_57 = F_28 ( V_56 -> V_57 , V_56 == V_100 || V_96 ) ;
for ( V_97 = 0 ; V_97 < V_93 -> V_101 ; V_97 ++ ) {
struct V_48 * V_49 = & V_93 -> V_102 [ V_97 ] ;
struct V_23 * V_3 ;
int V_103 = 0 ;
switch ( V_49 -> type ) {
case V_104 :
V_103 = F_23 ( V_56 -> V_105 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_106 :
if ( V_8 ) {
if ( ! V_8 -> V_107 )
V_8 -> V_107 = F_29 () ;
V_103 = F_23 ( V_8 -> V_107 , V_49 -> V_54 , V_49 -> V_22 ) ;
}
break;
case V_108 :
V_103 = F_23 ( V_57 -> V_59 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_109 :
V_103 = F_23 ( V_57 -> V_63 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_110 :
V_103 = F_23 ( V_57 -> V_69 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_111 :
V_103 = F_23 ( V_57 -> V_73 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_112 :
V_103 = F_23 ( V_57 -> V_61 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_113 :
V_103 = F_23 ( V_57 -> V_65 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_114 :
V_103 = F_23 ( V_57 -> V_71 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_115 :
V_103 = F_23 ( V_57 -> V_75 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_116 :
V_103 = F_23 ( V_56 -> V_117 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_118 :
if ( V_8 )
V_103 = F_23 ( V_8 -> V_10 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_119 :
if ( V_8 && V_8 -> V_120 )
V_103 = F_23 ( V_8 -> V_121 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_122 :
if ( V_8 && V_8 -> V_120 ) {
if ( V_49 -> V_22 )
V_103 = F_23 ( V_8 -> V_120 , V_49 -> V_54 , V_123 ) ;
else
V_103 = F_23 ( V_8 -> V_120 , V_49 -> V_54 , V_124 ) ;
}
break;
case V_125 :
if ( V_46 ) {
if ( F_23 ( F_30 ( V_46 -> V_126 ) , V_49 -> V_54 , V_49 -> V_22 ) ||
F_23 ( F_30 ( V_46 -> V_127 ) , V_49 -> V_54 , V_49 -> V_22 ) )
++ V_103 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_23 ( F_30 ( V_3 -> V_126 ) , V_49 -> V_54 , V_49 -> V_22 ) ||
F_23 ( F_30 ( V_3 -> V_127 ) , V_49 -> V_54 , V_49 -> V_22 ) ) {
++ V_103 ;
break;
}
}
}
break;
case V_128 :
if ( V_46 ) {
if ( F_23 ( F_31 ( V_46 -> V_126 ) , V_49 -> V_54 , V_49 -> V_22 ) ||
F_23 ( F_31 ( V_46 -> V_127 ) , V_49 -> V_54 , V_49 -> V_22 ) )
++ V_103 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_23 ( F_31 ( V_3 -> V_126 ) , V_49 -> V_54 , V_49 -> V_22 ) ||
F_23 ( F_31 ( V_3 -> V_127 ) , V_49 -> V_54 , V_49 -> V_22 ) ) {
++ V_103 ;
break;
}
}
}
break;
case V_129 :
if ( V_46 )
V_103 = ( V_46 -> V_25 == V_49 -> V_22 ) ;
else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_23 ( V_3 -> V_25 , V_49 -> V_54 , V_49 -> V_22 ) ) {
++ V_103 ;
break;
}
}
}
break;
case V_130 :
if ( V_46 ) {
V_103 = F_23 ( V_46 -> V_59 , V_49 -> V_54 , V_49 -> V_22 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_23 ( V_3 -> V_59 , V_49 -> V_54 , V_49 -> V_22 ) ) {
++ V_103 ;
break;
}
}
}
break;
case V_131 :
if ( V_46 ) {
V_103 = F_23 ( V_46 -> V_61 , V_49 -> V_54 , V_49 -> V_22 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_23 ( V_3 -> V_61 , V_49 -> V_54 , V_49 -> V_22 ) ) {
++ V_103 ;
break;
}
}
}
break;
case V_132 :
if ( V_46 )
V_103 = F_32 ( V_93 -> V_133 , V_46 -> V_25 , V_46 -> V_126 ) ;
break;
case V_134 :
if ( V_8 )
V_103 = F_19 ( V_8 , V_93 -> V_44 ) ;
break;
case V_135 :
V_103 = 0 ;
if ( V_8 )
V_103 = F_23 ( V_56 -> V_67 , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
if ( V_49 -> V_141 ) {
if ( V_98 ) {
F_33 ( V_56 , & V_99 ) ;
V_98 = 0 ;
}
V_103 = F_34 ( V_99 , V_49 -> type ,
V_49 -> V_54 ,
V_49 -> V_141 ,
V_8 ) ;
}
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
if ( V_49 -> V_141 ) {
if ( V_46 ) {
V_103 = F_34 (
V_46 -> V_147 , V_49 -> type , V_49 -> V_54 ,
V_49 -> V_141 , V_8 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_34 ( V_3 -> V_147 , V_49 -> type ,
V_49 -> V_54 , V_49 -> V_141 ,
V_8 ) ) {
++ V_103 ;
break;
}
}
}
if ( ! V_8 || V_8 -> type != V_148 )
break;
if ( F_34 ( V_8 -> V_149 . V_147 ,
V_49 -> type , V_49 -> V_54 ,
V_49 -> V_141 , V_8 ) )
++ V_103 ;
}
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
if ( V_8 )
V_103 = F_23 ( V_8 -> V_19 [ V_49 -> type - V_150 ] , V_49 -> V_54 , V_49 -> V_22 ) ;
break;
case V_154 :
V_103 = 1 ;
break;
case V_155 :
V_103 = F_3 ( V_8 , V_49 -> V_22 ) ;
break;
case V_156 :
V_103 = F_7 ( V_8 , V_49 -> V_22 ) ;
break;
case V_157 :
V_103 = F_24 ( V_56 , V_57 , V_49 , V_8 , V_46 ) ;
break;
}
if ( ! V_103 )
return 0 ;
}
if ( V_8 ) {
if ( V_93 -> V_27 <= V_8 -> V_27 )
return 0 ;
if ( V_93 -> V_158 ) {
F_18 ( V_8 -> V_158 ) ;
V_8 -> V_158 = F_35 ( V_93 -> V_158 , V_159 ) ;
}
V_8 -> V_27 = V_93 -> V_27 ;
}
switch ( V_93 -> V_160 ) {
case V_161 : * V_95 = V_162 ; break;
case V_163 : * V_95 = V_29 ; break;
}
return 1 ;
}
static enum V_94 F_36 ( struct V_55 * V_56 , char * * V_164 )
{
struct V_165 * V_166 ;
enum V_94 V_95 ;
F_37 () ;
F_38 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_27 ( V_56 , & V_166 -> V_93 , NULL , NULL ,
& V_95 , true ) ) {
if ( V_95 == V_29 )
* V_164 = F_35 ( V_166 -> V_93 . V_158 , V_159 ) ;
F_39 () ;
return V_95 ;
}
}
F_39 () ;
return V_167 ;
}
static enum V_94 F_40 ( struct V_55 * V_56 ,
struct V_7 * V_8 ,
struct V_168 * V_169 )
{
struct V_165 * V_166 ;
enum V_94 V_95 ;
if ( V_170 && V_56 -> V_171 == V_170 )
return V_162 ;
F_37 () ;
if ( ! F_41 ( V_169 ) ) {
int V_172 = F_42 ( V_8 -> V_9 ) ;
int V_173 = F_43 ( V_8 -> V_9 ) ;
F_38 (e, list, list) {
if ( ( V_166 -> V_93 . V_2 [ V_172 ] & V_173 ) == V_173 &&
F_27 ( V_56 , & V_166 -> V_93 , V_8 , NULL ,
& V_95 , false ) ) {
F_39 () ;
V_8 -> V_28 = V_95 ;
return V_95 ;
}
}
}
F_39 () ;
return V_167 ;
}
static int F_44 ( struct V_55 * V_56 ,
struct V_23 * V_3 ,
struct V_7 * V_8 ) {
int V_172 , V_173 ;
int V_174 = F_45 ( ( T_3 ) V_3 -> V_25 ) ;
struct V_168 * V_169 = & V_175 [ V_174 ] ;
struct V_165 * V_166 ;
enum V_94 V_95 ;
V_172 = F_42 ( V_8 -> V_9 ) ;
V_173 = F_43 ( V_8 -> V_9 ) ;
if ( F_41 ( V_169 ) )
return 0 ;
F_38 (e, list, list) {
if ( ( V_166 -> V_93 . V_2 [ V_172 ] & V_173 ) == V_173 &&
F_27 ( V_56 , & V_166 -> V_93 , V_8 , V_3 , & V_95 , false ) ) {
V_8 -> V_28 = V_95 ;
return 1 ;
}
}
return 0 ;
}
void F_46 ( struct V_55 * V_56 , struct V_7 * V_8 )
{
struct V_23 * V_3 ;
if ( V_170 && V_56 -> V_171 == V_170 )
return;
F_37 () ;
F_8 (n, &ctx->names_list, list) {
if ( F_44 ( V_56 , V_3 , V_8 ) )
break;
}
F_39 () ;
}
static inline struct V_7 * F_47 ( struct V_55 * V_56 ,
int V_120 ,
long V_121 )
{
struct V_7 * V_176 = V_56 -> V_7 ;
if ( ! V_176 )
return NULL ;
V_176 -> V_120 = V_120 ;
if ( F_4 ( V_121 <= - V_177 ) &&
( V_121 >= - V_178 ) &&
( V_121 != - V_179 ) )
V_176 -> V_121 = - V_180 ;
else
V_176 -> V_121 = V_121 ;
if ( V_176 -> V_181 && ! V_176 -> V_182 ) {
F_40 ( V_56 , V_176 , & V_183 [ V_184 ] ) ;
F_46 ( V_56 , V_176 ) ;
}
V_56 -> V_7 = NULL ;
return V_176 ;
}
static inline void F_48 ( struct V_7 * V_176 )
{
struct V_23 * V_3 , * V_38 ;
#if V_185 == 2
if ( V_176 -> V_186 + V_176 -> V_187 != V_176 -> V_188 ) {
F_49 ( V_189 L_2
L_3
L_4 ,
__FILE__ , __LINE__ ,
V_176 -> V_190 , V_176 -> V_9 , V_176 -> V_181 ,
V_176 -> V_188 , V_176 -> V_186 ,
V_176 -> V_187 ) ;
F_8 (n, &context->names_list, list) {
F_49 ( V_189 L_5 , V_97 ,
V_3 -> V_46 , V_3 -> V_46 ? : L_6 ) ;
}
F_50 () ;
return;
}
#endif
#if V_185
V_176 -> V_186 = 0 ;
V_176 -> V_187 = 0 ;
#endif
F_51 (n, next, &context->names_list, list) {
F_52 ( & V_3 -> V_169 ) ;
if ( V_3 -> V_46 && V_3 -> V_191 )
F_53 ( V_3 -> V_46 ) ;
if ( V_3 -> V_192 )
F_18 ( V_3 ) ;
}
V_176 -> V_188 = 0 ;
F_54 ( & V_176 -> V_193 ) ;
V_176 -> V_193 . V_194 = NULL ;
V_176 -> V_193 . V_195 = NULL ;
}
static inline void F_55 ( struct V_7 * V_176 )
{
struct V_196 * V_197 ;
while ( ( V_197 = V_176 -> V_197 ) ) {
V_176 -> V_197 = V_197 -> V_38 ;
F_18 ( V_197 ) ;
}
while ( ( V_197 = V_176 -> V_198 ) ) {
V_176 -> V_198 = V_197 -> V_38 ;
F_18 ( V_197 ) ;
}
}
static inline void F_56 ( struct V_7 * V_176 ,
enum V_94 V_95 )
{
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_176 -> V_95 = V_95 ;
V_176 -> V_27 = V_95 == V_29 ? ~ 0ULL : 0 ;
}
static inline struct V_7 * F_57 ( enum V_94 V_95 )
{
struct V_7 * V_176 ;
if ( ! ( V_176 = F_58 ( sizeof( * V_176 ) , V_39 ) ) )
return NULL ;
F_56 ( V_176 , V_95 ) ;
F_59 ( & V_176 -> V_199 ) ;
F_59 ( & V_176 -> V_200 ) ;
return V_176 ;
}
int F_60 ( struct V_55 * V_56 )
{
struct V_7 * V_176 ;
enum V_94 V_95 ;
char * V_164 = NULL ;
if ( F_11 ( ! V_201 ) )
return 0 ;
V_95 = F_36 ( V_56 , & V_164 ) ;
if ( V_95 == V_162 )
return 0 ;
if ( ! ( V_176 = F_57 ( V_95 ) ) ) {
F_18 ( V_164 ) ;
F_61 ( L_7 ) ;
return - V_202 ;
}
V_176 -> V_158 = V_164 ;
V_56 -> V_7 = V_176 ;
F_62 ( V_56 , V_203 ) ;
return 0 ;
}
static inline void F_63 ( struct V_7 * V_176 )
{
struct V_7 * V_204 ;
int V_41 = 0 ;
do {
V_204 = V_176 -> V_204 ;
if ( V_204 || ( V_41 && V_41 < 10 ) ) {
++ V_41 ;
F_49 ( V_189 L_8
L_9 ,
V_176 -> V_190 , V_176 -> V_9 ,
V_176 -> V_188 , V_41 ) ;
}
F_48 ( V_176 ) ;
F_14 ( V_176 , NULL , 0 ) ;
F_17 ( V_176 ) ;
F_55 ( V_176 ) ;
F_18 ( V_176 -> V_158 ) ;
F_18 ( V_176 -> V_205 ) ;
F_18 ( V_176 ) ;
V_176 = V_204 ;
} while ( V_176 );
if ( V_41 >= 10 )
F_49 ( V_189 L_10 , V_41 ) ;
}
void F_64 ( struct V_206 * V_207 )
{
char * V_8 = NULL ;
unsigned V_208 ;
int error ;
T_3 V_99 ;
F_33 ( V_100 , & V_99 ) ;
if ( ! V_99 )
return;
error = F_65 ( V_99 , & V_8 , & V_208 ) ;
if ( error ) {
if ( error != - V_209 )
goto V_210;
return;
}
F_66 ( V_207 , L_11 , V_8 ) ;
F_67 ( V_8 , V_208 ) ;
return;
V_210:
F_68 ( L_12 ) ;
return;
}
static void F_69 ( struct V_206 * V_207 , struct V_55 * V_56 )
{
char V_46 [ sizeof( V_56 -> V_211 ) ] ;
struct V_212 * V_213 = V_56 -> V_213 ;
struct V_214 * V_215 ;
F_70 ( V_46 , V_56 ) ;
F_66 ( V_207 , L_13 ) ;
F_71 ( V_207 , V_46 ) ;
if ( V_213 ) {
F_72 ( & V_213 -> V_216 ) ;
V_215 = V_213 -> V_217 ;
while ( V_215 ) {
if ( ( V_215 -> V_218 & V_219 ) &&
V_215 -> V_220 ) {
F_73 ( V_207 , L_14 ,
& V_215 -> V_220 -> V_221 ) ;
break;
}
V_215 = V_215 -> V_222 ;
}
F_74 ( & V_213 -> V_216 ) ;
}
F_64 ( V_207 ) ;
}
static int F_75 ( struct V_7 * V_176 , T_4 V_105 ,
T_2 V_223 , T_2 V_59 , unsigned int V_224 ,
T_3 V_99 , char * V_211 )
{
struct V_206 * V_207 ;
char * V_8 = NULL ;
T_3 V_208 ;
int V_52 = 0 ;
V_207 = F_76 ( V_176 , V_39 , V_225 ) ;
if ( ! V_207 )
return V_52 ;
F_66 ( V_207 , L_15 , V_105 , V_223 ,
V_59 , V_224 ) ;
if ( F_65 ( V_99 , & V_8 , & V_208 ) ) {
F_66 ( V_207 , L_16 ) ;
V_52 = 1 ;
} else {
F_66 ( V_207 , L_17 , V_8 ) ;
F_67 ( V_8 , V_208 ) ;
}
F_66 ( V_207 , L_18 ) ;
F_71 ( V_207 , V_211 ) ;
F_77 ( V_207 ) ;
return V_52 ;
}
static int F_78 ( struct V_7 * V_176 ,
struct V_206 * * V_207 ,
int V_226 ,
T_5 * V_227 ,
const char T_6 * V_33 ,
char * V_228 )
{
char V_229 [ 12 ] ;
const char T_6 * V_230 = V_33 ;
T_5 V_231 = snprintf ( V_229 , 12 , L_19 , V_226 ) + 5 ;
T_5 V_208 , V_232 , V_233 ;
T_5 V_234 = V_235 ;
unsigned int V_97 , V_236 = 0 , V_237 = 0 ;
int V_238 ;
V_232 = V_208 = F_79 ( V_33 , V_239 ) - 1 ;
if ( F_4 ( ( V_208 == - 1 ) || V_208 > V_239 - 1 ) ) {
F_80 ( 1 ) ;
F_81 ( V_240 , V_100 , 0 ) ;
return - 1 ;
}
do {
if ( V_232 > V_235 )
V_233 = V_235 ;
else
V_233 = V_232 ;
V_238 = F_82 ( V_228 , V_230 , V_233 ) ;
if ( V_238 ) {
F_80 ( 1 ) ;
F_81 ( V_240 , V_100 , 0 ) ;
return - 1 ;
}
V_228 [ V_233 ] = '\0' ;
V_236 = F_83 ( V_228 , V_233 ) ;
if ( V_236 ) {
V_234 = V_235 / 2 ;
break;
}
V_232 -= V_233 ;
V_230 += V_233 ;
} while ( V_232 > 0 );
V_232 = V_208 ;
if ( V_208 > V_234 )
V_237 = 1 ;
for ( V_97 = 0 ; V_232 > 0 ; V_97 ++ ) {
int V_241 ;
if ( V_232 > V_234 )
V_233 = V_234 ;
else
V_233 = V_232 ;
V_241 = V_235 - V_231 - * V_227 ;
if ( V_236 )
V_241 -= ( V_233 * 2 ) ;
else
V_241 -= V_233 ;
if ( V_241 < 0 ) {
* V_227 = 0 ;
F_77 ( * V_207 ) ;
* V_207 = F_76 ( V_176 , V_39 , V_242 ) ;
if ( ! * V_207 )
return 0 ;
}
if ( ( V_97 == 0 ) && ( V_237 ) )
F_66 ( * V_207 , L_20 , V_226 ,
V_236 ? 2 * V_208 : V_208 ) ;
if ( V_208 >= V_234 )
V_238 = F_82 ( V_228 , V_33 , V_233 ) ;
else
V_238 = 0 ;
if ( V_238 ) {
F_80 ( 1 ) ;
F_81 ( V_240 , V_100 , 0 ) ;
return - 1 ;
}
V_228 [ V_233 ] = '\0' ;
F_66 ( * V_207 , L_21 , V_226 ) ;
if ( V_237 )
F_66 ( * V_207 , L_22 , V_97 ) ;
F_66 ( * V_207 , L_23 ) ;
if ( V_236 )
F_84 ( * V_207 , V_228 , V_233 ) ;
else
F_85 ( * V_207 , V_228 ) ;
V_33 += V_233 ;
V_232 -= V_233 ;
* V_227 += V_231 ;
if ( V_236 )
* V_227 += V_233 * 2 ;
else
* V_227 += V_233 ;
}
return V_208 + 1 ;
}
static void F_86 ( struct V_7 * V_176 ,
struct V_206 * * V_207 ,
struct V_243 * V_244 )
{
int V_97 , V_208 ;
T_5 V_227 = 0 ;
const char T_6 * V_33 ;
char * V_228 ;
if ( V_244 -> V_213 != V_100 -> V_213 )
return;
V_33 = ( const char T_6 * ) V_244 -> V_213 -> V_245 ;
F_66 ( * V_207 , L_24 , V_244 -> V_246 ) ;
V_228 = F_58 ( V_235 + 1 , V_39 ) ;
if ( ! V_228 ) {
F_68 ( L_25 ) ;
return;
}
for ( V_97 = 0 ; V_97 < V_244 -> V_246 ; V_97 ++ ) {
V_208 = F_78 ( V_176 , V_207 , V_97 ,
& V_227 , V_33 , V_228 ) ;
if ( V_208 <= 0 )
break;
V_33 += V_208 ;
}
F_18 ( V_228 ) ;
}
static void F_87 ( struct V_206 * V_207 , char * V_247 , T_7 * V_248 )
{
int V_97 ;
F_66 ( V_207 , L_26 , V_247 ) ;
F_88 (i) {
F_66 ( V_207 , L_27 , V_248 -> V_248 [ ( V_249 - 1 ) - V_97 ] ) ;
}
}
static void F_89 ( struct V_206 * V_207 , struct V_23 * V_46 )
{
T_7 * V_250 = & V_46 -> V_251 . V_252 ;
T_7 * V_253 = & V_46 -> V_251 . V_254 ;
int log = 0 ;
if ( ! F_90 ( * V_250 ) ) {
F_87 ( V_207 , L_28 , V_250 ) ;
log = 1 ;
}
if ( ! F_90 ( * V_253 ) ) {
F_87 ( V_207 , L_29 , V_253 ) ;
log = 1 ;
}
if ( log )
F_66 ( V_207 , L_30 , V_46 -> V_251 . V_255 , V_46 -> V_256 ) ;
}
static void F_91 ( struct V_7 * V_176 , int * V_257 )
{
struct V_206 * V_207 ;
int V_97 ;
V_207 = F_76 ( V_176 , V_39 , V_176 -> type ) ;
if ( ! V_207 )
return;
switch ( V_176 -> type ) {
case V_258 : {
int V_259 = V_176 -> V_260 . V_259 ;
F_66 ( V_207 , L_31 , V_259 ) ;
for ( V_97 = 0 ; V_97 < V_259 ; V_97 ++ )
F_66 ( V_207 , L_32 , V_97 ,
V_176 -> V_260 . args [ V_97 ] ) ;
break; }
case V_148 : {
T_3 V_147 = V_176 -> V_149 . V_147 ;
F_66 ( V_207 , L_33 ,
V_176 -> V_149 . V_59 , V_176 -> V_149 . V_61 , V_176 -> V_149 . V_24 ) ;
if ( V_147 ) {
char * V_8 = NULL ;
T_3 V_208 ;
if ( F_65 ( V_147 , & V_8 , & V_208 ) ) {
F_66 ( V_207 , L_34 , V_147 ) ;
* V_257 = 1 ;
} else {
F_66 ( V_207 , L_17 , V_8 ) ;
F_67 ( V_8 , V_208 ) ;
}
}
if ( V_176 -> V_149 . V_261 ) {
F_77 ( V_207 ) ;
V_207 = F_76 ( V_176 , V_39 ,
V_262 ) ;
F_66 ( V_207 ,
L_35 ,
V_176 -> V_149 . V_263 ,
V_176 -> V_149 . V_264 ,
V_176 -> V_149 . V_265 ,
V_176 -> V_149 . V_266 ) ;
if ( ! V_207 )
return;
}
break; }
case V_267 : {
F_66 ( V_207 ,
L_36
L_37 ,
V_176 -> V_268 . V_269 , V_176 -> V_268 . V_24 ,
V_176 -> V_268 . V_270 . V_271 ,
V_176 -> V_268 . V_270 . V_272 ,
V_176 -> V_268 . V_270 . V_273 ,
V_176 -> V_268 . V_270 . V_274 ) ;
break; }
case V_275 : {
F_66 ( V_207 ,
L_38
L_39 ,
V_176 -> V_276 . V_277 ,
V_176 -> V_276 . V_278 ,
V_176 -> V_276 . V_279 ,
V_176 -> V_276 . V_280 . V_281 ,
V_176 -> V_276 . V_280 . V_282 ) ;
break; }
case V_283 : {
F_66 ( V_207 , L_40 ,
V_176 -> V_284 . V_277 ,
V_176 -> V_284 . V_285 ) ;
break; }
case V_286 : {
struct V_287 * V_270 = & V_176 -> V_288 . V_289 ;
F_66 ( V_207 ,
L_41
L_42 ,
V_176 -> V_288 . V_277 ,
V_270 -> V_271 , V_270 -> V_272 ,
V_270 -> V_273 , V_270 -> V_274 ) ;
break; }
case V_290 : {
F_66 ( V_207 , L_43 , V_176 -> V_291 . V_105 ) ;
F_87 ( V_207 , L_44 , & V_176 -> V_291 . V_248 . V_254 ) ;
F_87 ( V_207 , L_45 , & V_176 -> V_291 . V_248 . V_252 ) ;
F_87 ( V_207 , L_46 , & V_176 -> V_291 . V_248 . V_292 ) ;
break; }
case V_293 : {
F_66 ( V_207 , L_47 , V_176 -> V_217 . V_294 ,
V_176 -> V_217 . V_1 ) ;
break; }
}
F_77 ( V_207 ) ;
}
static void F_92 ( struct V_7 * V_176 , struct V_23 * V_3 ,
int V_295 , int * V_257 )
{
struct V_206 * V_207 ;
V_207 = F_76 ( V_176 , V_39 , V_296 ) ;
if ( ! V_207 )
return;
F_66 ( V_207 , L_48 , V_295 ) ;
if ( V_3 -> V_46 ) {
switch ( V_3 -> V_297 ) {
case V_298 :
F_66 ( V_207 , L_49 ) ;
F_71 ( V_207 , V_3 -> V_46 ) ;
break;
case 0 :
F_73 ( V_207 , L_49 , & V_176 -> V_193 ) ;
break;
default:
F_66 ( V_207 , L_49 ) ;
F_93 ( V_207 , V_3 -> V_46 ,
V_3 -> V_297 ) ;
}
} else
F_66 ( V_207 , L_50 ) ;
if ( V_3 -> V_25 != ( unsigned long ) - 1 ) {
F_66 ( V_207 , L_51
L_52
L_53 ,
V_3 -> V_25 ,
F_30 ( V_3 -> V_126 ) ,
F_31 ( V_3 -> V_126 ) ,
V_3 -> V_24 ,
V_3 -> V_59 ,
V_3 -> V_61 ,
F_30 ( V_3 -> V_127 ) ,
F_31 ( V_3 -> V_127 ) ) ;
}
if ( V_3 -> V_147 != 0 ) {
char * V_8 = NULL ;
T_3 V_208 ;
if ( F_65 (
V_3 -> V_147 , & V_8 , & V_208 ) ) {
F_66 ( V_207 , L_34 , V_3 -> V_147 ) ;
* V_257 = 2 ;
} else {
F_66 ( V_207 , L_17 , V_8 ) ;
F_67 ( V_8 , V_208 ) ;
}
}
F_89 ( V_207 , V_3 ) ;
F_77 ( V_207 ) ;
}
static void F_94 ( struct V_7 * V_176 , struct V_55 * V_56 )
{
const struct V_57 * V_57 ;
int V_97 , V_257 = 0 ;
struct V_206 * V_207 ;
struct V_196 * V_197 ;
const char * V_299 ;
struct V_23 * V_3 ;
V_176 -> V_105 = V_56 -> V_105 ;
if ( ! V_176 -> V_107 )
V_176 -> V_107 = F_29 () ;
V_57 = F_95 () ;
V_176 -> V_59 = V_57 -> V_59 ;
V_176 -> V_61 = V_57 -> V_61 ;
V_176 -> V_63 = V_57 -> V_63 ;
V_176 -> V_69 = V_57 -> V_69 ;
V_176 -> V_73 = V_57 -> V_73 ;
V_176 -> V_65 = V_57 -> V_65 ;
V_176 -> V_71 = V_57 -> V_71 ;
V_176 -> V_75 = V_57 -> V_75 ;
V_176 -> V_117 = V_56 -> V_117 ;
V_207 = F_76 ( V_176 , V_39 , V_300 ) ;
if ( ! V_207 )
return;
F_66 ( V_207 , L_54 ,
V_176 -> V_10 , V_176 -> V_9 ) ;
if ( V_176 -> V_117 != V_301 )
F_66 ( V_207 , L_55 , V_176 -> V_117 ) ;
if ( V_176 -> V_120 )
F_66 ( V_207 , L_56 ,
( V_176 -> V_120 == V_123 ) ? L_57 : L_58 ,
V_176 -> V_121 ) ;
F_96 ( & V_56 -> V_302 -> V_303 ) ;
if ( V_56 -> signal && V_56 -> signal -> V_299 && V_56 -> signal -> V_299 -> V_46 )
V_299 = V_56 -> signal -> V_299 -> V_46 ;
else
V_299 = L_59 ;
F_97 ( & V_56 -> V_302 -> V_303 ) ;
F_66 ( V_207 ,
L_60
L_61
L_62
L_63 ,
V_176 -> V_19 [ 0 ] ,
V_176 -> V_19 [ 1 ] ,
V_176 -> V_19 [ 2 ] ,
V_176 -> V_19 [ 3 ] ,
V_176 -> V_188 ,
V_176 -> V_107 ,
V_176 -> V_105 ,
V_56 -> V_67 ,
V_176 -> V_59 ,
V_176 -> V_61 ,
V_176 -> V_63 , V_176 -> V_69 , V_176 -> V_73 ,
V_176 -> V_65 , V_176 -> V_71 , V_176 -> V_75 , V_299 ,
V_56 -> V_224 ) ;
F_69 ( V_207 , V_56 ) ;
F_98 ( V_207 , V_176 -> V_158 ) ;
F_77 ( V_207 ) ;
for ( V_197 = V_176 -> V_197 ; V_197 ; V_197 = V_197 -> V_38 ) {
V_207 = F_76 ( V_176 , V_39 , V_197 -> type ) ;
if ( ! V_207 )
continue;
switch ( V_197 -> type ) {
case V_242 : {
struct V_243 * V_244 = ( void * ) V_197 ;
F_86 ( V_176 , & V_207 , V_244 ) ;
break; }
case V_304 : {
struct V_305 * V_306 = ( void * ) V_197 ;
F_66 ( V_207 , L_64 , V_306 -> V_256 ) ;
F_87 ( V_207 , L_65 , & V_306 -> V_251 . V_252 ) ;
F_87 ( V_207 , L_66 , & V_306 -> V_251 . V_254 ) ;
F_66 ( V_207 , L_67 , V_306 -> V_251 . V_255 ) ;
F_87 ( V_207 , L_68 , & V_306 -> V_307 . V_252 ) ;
F_87 ( V_207 , L_69 , & V_306 -> V_307 . V_254 ) ;
F_87 ( V_207 , L_70 , & V_306 -> V_307 . V_292 ) ;
F_87 ( V_207 , L_71 , & V_306 -> V_308 . V_252 ) ;
F_87 ( V_207 , L_72 , & V_306 -> V_308 . V_254 ) ;
F_87 ( V_207 , L_73 , & V_306 -> V_308 . V_292 ) ;
break; }
}
F_77 ( V_207 ) ;
}
if ( V_176 -> type )
F_91 ( V_176 , & V_257 ) ;
if ( V_176 -> V_309 [ 0 ] >= 0 ) {
V_207 = F_76 ( V_176 , V_39 , V_310 ) ;
if ( V_207 ) {
F_66 ( V_207 , L_74 ,
V_176 -> V_309 [ 0 ] , V_176 -> V_309 [ 1 ] ) ;
F_77 ( V_207 ) ;
}
}
if ( V_176 -> V_311 ) {
V_207 = F_76 ( V_176 , V_39 , V_312 ) ;
if ( V_207 ) {
F_66 ( V_207 , L_75 ) ;
F_84 ( V_207 , ( void * ) V_176 -> V_205 ,
V_176 -> V_311 ) ;
F_77 ( V_207 ) ;
}
}
for ( V_197 = V_176 -> V_198 ; V_197 ; V_197 = V_197 -> V_38 ) {
struct V_313 * V_306 = ( void * ) V_197 ;
for ( V_97 = 0 ; V_97 < V_306 -> V_314 ; V_97 ++ )
if ( F_75 ( V_176 , V_306 -> V_315 [ V_97 ] ,
V_306 -> V_316 [ V_97 ] ,
V_306 -> V_317 [ V_97 ] ,
V_306 -> V_318 [ V_97 ] ,
V_306 -> V_319 [ V_97 ] ,
V_306 -> V_320 [ V_97 ] ) )
V_257 = 1 ;
}
if ( V_176 -> V_315 &&
F_75 ( V_176 , V_176 -> V_315 ,
V_176 -> V_316 , V_176 -> V_317 ,
V_176 -> V_318 ,
V_176 -> V_319 , V_176 -> V_320 ) )
V_257 = 1 ;
if ( V_176 -> V_193 . V_194 && V_176 -> V_193 . V_195 ) {
V_207 = F_76 ( V_176 , V_39 , V_321 ) ;
if ( V_207 ) {
F_73 ( V_207 , L_76 , & V_176 -> V_193 ) ;
F_77 ( V_207 ) ;
}
}
V_97 = 0 ;
F_8 (n, &context->names_list, list)
F_92 ( V_176 , V_3 , V_97 ++ , & V_257 ) ;
V_207 = F_76 ( V_176 , V_39 , V_322 ) ;
if ( V_207 )
F_77 ( V_207 ) ;
if ( V_257 )
F_68 ( L_77 ) ;
}
void F_99 ( struct V_55 * V_56 )
{
struct V_7 * V_176 ;
V_176 = F_47 ( V_56 , 0 , 0 ) ;
if ( ! V_176 )
return;
if ( V_176 -> V_181 && V_176 -> V_28 == V_29 )
F_94 ( V_176 , V_56 ) ;
if ( ! F_41 ( & V_176 -> V_199 ) )
F_100 ( & V_176 -> V_199 ) ;
F_63 ( V_176 ) ;
}
void F_101 ( int V_10 , int V_9 ,
unsigned long V_323 , unsigned long V_324 ,
unsigned long V_325 , unsigned long V_326 )
{
struct V_55 * V_56 = V_100 ;
struct V_7 * V_176 = V_56 -> V_7 ;
enum V_94 V_95 ;
if ( ! V_176 )
return;
if ( V_176 -> V_181 ) {
struct V_7 * V_327 ;
#if V_185
F_49 ( V_189
L_78
L_79 ,
V_176 -> V_190 , V_56 -> V_105 , V_176 -> V_9 , V_9 ) ;
#endif
V_327 = F_57 ( V_176 -> V_95 ) ;
if ( V_327 ) {
V_327 -> V_204 = V_176 ;
V_176 = V_327 ;
V_56 -> V_7 = V_327 ;
} else {
F_56 ( V_176 , V_176 -> V_95 ) ;
}
}
F_102 ( V_176 -> V_181 || V_176 -> V_188 ) ;
if ( ! V_328 )
return;
V_176 -> V_10 = V_10 ;
V_176 -> V_9 = V_9 ;
V_176 -> V_19 [ 0 ] = V_323 ;
V_176 -> V_19 [ 1 ] = V_324 ;
V_176 -> V_19 [ 2 ] = V_325 ;
V_176 -> V_19 [ 3 ] = V_326 ;
V_95 = V_176 -> V_95 ;
V_176 -> V_182 = ! V_329 ;
if ( ! V_176 -> V_182 && V_95 == V_167 ) {
V_176 -> V_27 = 0 ;
V_95 = F_40 ( V_56 , V_176 , & V_183 [ V_330 ] ) ;
}
if ( V_95 == V_162 )
return;
V_176 -> V_190 = 0 ;
V_176 -> ctime = V_331 ;
V_176 -> V_181 = 1 ;
V_176 -> V_28 = V_95 ;
V_176 -> V_107 = 0 ;
}
void F_103 ( int V_332 , long V_121 )
{
struct V_55 * V_56 = V_100 ;
struct V_7 * V_176 ;
if ( V_332 )
V_332 = V_123 ;
else
V_332 = V_124 ;
V_176 = F_47 ( V_56 , V_332 , V_121 ) ;
if ( ! V_176 )
return;
if ( V_176 -> V_181 && V_176 -> V_28 == V_29 )
F_94 ( V_176 , V_56 ) ;
V_176 -> V_181 = 0 ;
V_176 -> V_27 = V_176 -> V_95 == V_29 ? ~ 0ULL : 0 ;
if ( ! F_41 ( & V_176 -> V_199 ) )
F_100 ( & V_176 -> V_199 ) ;
if ( V_176 -> V_204 ) {
struct V_7 * V_333 = V_176 -> V_204 ;
V_176 -> V_204 = NULL ;
F_63 ( V_176 ) ;
V_56 -> V_7 = V_333 ;
} else {
F_48 ( V_176 ) ;
F_14 ( V_176 , NULL , 0 ) ;
F_55 ( V_176 ) ;
V_176 -> V_197 = NULL ;
V_176 -> V_198 = NULL ;
V_176 -> V_315 = 0 ;
V_176 -> V_319 = 0 ;
V_176 -> V_311 = 0 ;
V_176 -> type = 0 ;
V_176 -> V_309 [ 0 ] = - 1 ;
if ( V_176 -> V_95 != V_29 ) {
F_18 ( V_176 -> V_158 ) ;
V_176 -> V_158 = NULL ;
}
V_56 -> V_7 = V_176 ;
}
}
static inline void F_104 ( const struct V_334 * V_334 )
{
#ifdef F_15
struct V_7 * V_176 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
int V_41 ;
if ( F_11 ( F_105 ( & V_334 -> V_335 ) ) )
return;
V_176 = V_100 -> V_7 ;
V_33 = V_176 -> V_34 ;
V_41 = V_176 -> V_36 ;
F_37 () ;
V_31 = F_106 ( V_334 ) ;
F_39 () ;
if ( ! V_31 )
return;
if ( F_11 ( F_10 ( V_176 , V_31 ) ) )
return;
if ( F_4 ( ! F_12 ( V_176 ) ) ) {
F_49 ( V_336 L_80 ) ;
F_9 ( V_176 ) ;
F_16 ( V_31 ) ;
F_14 ( V_176 , V_33 , V_41 ) ;
return;
}
F_10 ( V_176 , V_31 ) ;
#endif
}
static void F_107 ( const struct V_194 * V_194 )
{
#ifdef F_15
struct V_7 * V_176 ;
struct V_32 * V_33 ;
const struct V_194 * V_337 , * V_338 ;
struct V_30 * V_339 ;
unsigned long V_340 ;
int V_41 ;
V_176 = V_100 -> V_7 ;
V_33 = V_176 -> V_34 ;
V_41 = V_176 -> V_36 ;
V_341:
V_339 = NULL ;
V_337 = V_194 ;
F_37 () ;
V_340 = F_108 ( & V_342 ) ;
for(; ; ) {
struct V_334 * V_334 = V_337 -> V_343 ;
if ( V_334 && F_4 ( ! F_105 ( & V_334 -> V_335 ) ) ) {
struct V_30 * V_31 ;
V_31 = F_106 ( V_334 ) ;
if ( V_31 ) {
if ( F_4 ( ! F_10 ( V_176 , V_31 ) ) ) {
V_339 = V_31 ;
break;
}
}
}
V_338 = V_337 -> V_344 ;
if ( V_338 == V_337 )
break;
V_337 = V_338 ;
}
if ( F_4 ( F_109 ( & V_342 , V_340 ) || V_339 ) ) {
F_39 () ;
if ( ! V_339 ) {
F_14 ( V_176 , V_33 , V_41 ) ;
goto V_341;
}
F_16 ( V_339 ) ;
if ( F_12 ( V_176 ) ) {
F_14 ( V_176 , V_33 , V_41 ) ;
goto V_341;
}
F_49 ( V_336
L_80 ) ;
F_14 ( V_176 , V_33 , V_41 ) ;
F_9 ( V_176 ) ;
return;
}
F_39 () ;
#endif
}
static struct V_23 * F_110 ( struct V_7 * V_176 )
{
struct V_23 * V_345 ;
if ( V_176 -> V_188 < V_346 ) {
V_345 = & V_176 -> V_347 [ V_176 -> V_188 ] ;
memset ( V_345 , 0 , sizeof( * V_345 ) ) ;
} else {
V_345 = F_13 ( sizeof( * V_345 ) , V_348 ) ;
if ( ! V_345 )
return NULL ;
V_345 -> V_192 = true ;
}
V_345 -> V_25 = ( unsigned long ) - 1 ;
F_111 ( & V_345 -> V_169 , & V_176 -> V_200 ) ;
V_176 -> V_188 ++ ;
#if V_185
V_176 -> V_187 ++ ;
#endif
return V_345 ;
}
void F_112 ( const char * V_46 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
struct V_23 * V_3 ;
if ( ! V_176 -> V_181 ) {
#if V_185 == 2
F_49 ( V_189 L_81 ,
__FILE__ , __LINE__ , V_176 -> V_190 , V_46 ) ;
F_50 () ;
#endif
return;
}
V_3 = F_110 ( V_176 ) ;
if ( ! V_3 )
return;
V_3 -> V_46 = V_46 ;
V_3 -> V_297 = V_298 ;
V_3 -> V_191 = true ;
if ( ! V_176 -> V_193 . V_194 )
F_113 ( V_100 -> V_349 , & V_176 -> V_193 ) ;
}
void F_114 ( const char * V_46 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
F_102 ( ! V_176 ) ;
if ( ! V_176 -> V_181 ) {
#if V_185 == 2
F_49 ( V_189 L_82 ,
__FILE__ , __LINE__ , V_176 -> V_190 , V_46 ) ;
if ( V_176 -> V_188 ) {
struct V_23 * V_3 ;
int V_97 ;
F_8 (n, &context->names_list, list)
F_49 ( V_189 L_83 , V_97 ,
V_3 -> V_46 , V_3 -> V_46 ? : L_6 ) ;
}
#endif
F_53 ( V_46 ) ;
}
#if V_185
else {
++ V_176 -> V_186 ;
if ( V_176 -> V_186 > V_176 -> V_188 ) {
F_49 ( V_189 L_84
L_85
L_86 ,
__FILE__ , __LINE__ ,
V_176 -> V_190 , V_176 -> V_9 ,
V_176 -> V_181 , V_46 , V_176 -> V_188 ,
V_176 -> V_186 ) ;
F_50 () ;
}
}
#endif
}
static inline int F_115 ( struct V_23 * V_46 , const struct V_194 * V_194 )
{
struct V_350 V_351 ;
int V_52 ;
if ( ! V_194 )
return 0 ;
V_52 = F_116 ( V_194 , & V_351 ) ;
if ( V_52 )
return V_52 ;
V_46 -> V_251 . V_252 = V_351 . V_252 ;
V_46 -> V_251 . V_254 = V_351 . V_254 ;
V_46 -> V_251 . V_255 = ! ! ( V_351 . V_352 & V_353 ) ;
V_46 -> V_256 = ( V_351 . V_352 & V_354 ) >> V_355 ;
return 0 ;
}
static void F_117 ( struct V_23 * V_46 , const struct V_194 * V_194 ,
const struct V_334 * V_334 )
{
V_46 -> V_25 = V_334 -> V_356 ;
V_46 -> V_126 = V_334 -> V_357 -> V_358 ;
V_46 -> V_24 = V_334 -> V_359 ;
V_46 -> V_59 = V_334 -> V_360 ;
V_46 -> V_61 = V_334 -> V_361 ;
V_46 -> V_127 = V_334 -> V_362 ;
F_118 ( V_334 , & V_46 -> V_147 ) ;
F_115 ( V_46 , V_194 ) ;
}
void F_119 ( const char * V_46 , const struct V_194 * V_194 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
const struct V_334 * V_334 = V_194 -> V_343 ;
struct V_23 * V_3 ;
if ( ! V_176 -> V_181 )
return;
F_120 (n, &context->names_list, list) {
if ( V_3 -> V_46 && ( V_3 -> V_46 == V_46 ) )
goto V_363;
}
V_3 = F_110 ( V_176 ) ;
if ( ! V_3 )
return;
V_363:
F_107 ( V_194 ) ;
F_117 ( V_3 , V_194 , V_334 ) ;
}
void F_121 ( const struct V_194 * V_194 ,
const struct V_334 * V_338 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
const char * V_364 = NULL , * V_365 = NULL ;
const struct V_334 * V_334 = V_194 -> V_343 ;
const char * V_366 = V_194 -> V_367 . V_46 ;
struct V_23 * V_3 ;
int V_368 = 0 ;
if ( ! V_176 -> V_181 )
return;
if ( V_334 )
F_104 ( V_334 ) ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( V_3 -> V_25 == V_338 -> V_356 &&
! F_122 ( V_366 , V_3 -> V_46 , & V_368 ) ) {
V_3 -> V_297 = V_368 ;
V_364 = V_3 -> V_46 ;
goto V_369;
}
}
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( ! strcmp ( V_366 , V_3 -> V_46 ) ||
! F_122 ( V_366 , V_3 -> V_46 , & V_368 ) ) {
if ( V_334 )
F_117 ( V_3 , NULL , V_334 ) ;
else
V_3 -> V_25 = ( unsigned long ) - 1 ;
V_365 = V_3 -> V_46 ;
goto V_369;
}
}
V_369:
if ( ! V_364 ) {
V_3 = F_110 ( V_176 ) ;
if ( ! V_3 )
return;
F_117 ( V_3 , NULL , V_338 ) ;
}
if ( ! V_365 ) {
V_3 = F_110 ( V_176 ) ;
if ( ! V_3 )
return;
if ( V_364 ) {
V_3 -> V_46 = V_364 ;
V_3 -> V_297 = V_298 ;
V_3 -> V_191 = false ;
}
if ( V_334 )
F_117 ( V_3 , NULL , V_334 ) ;
}
}
int F_123 ( struct V_7 * V_8 ,
struct V_370 * V_371 , unsigned int * V_190 )
{
if ( ! V_8 -> V_181 )
return 0 ;
if ( ! V_8 -> V_190 )
V_8 -> V_190 = F_124 () ;
V_371 -> V_281 = V_8 -> ctime . V_281 ;
V_371 -> V_282 = V_8 -> ctime . V_282 ;
* V_190 = V_8 -> V_190 ;
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
return 1 ;
}
int F_125 ( T_2 V_67 )
{
struct V_55 * V_372 = V_100 ;
struct V_7 * V_176 = V_372 -> V_7 ;
unsigned int V_224 ;
#ifdef F_126
if ( V_372 -> V_67 != - 1 )
return - V_373 ;
#else
if ( ! F_127 ( V_374 ) )
return - V_373 ;
#endif
V_224 = F_128 ( & V_375 ) ;
if ( V_176 && V_176 -> V_181 ) {
struct V_206 * V_207 ;
V_207 = F_76 ( NULL , V_39 , V_376 ) ;
if ( V_207 ) {
F_66 ( V_207 , L_87
L_88
L_89 ,
V_372 -> V_105 , F_129 ( V_372 ) ,
V_372 -> V_67 , V_67 ,
V_372 -> V_224 , V_224 ) ;
F_77 ( V_207 ) ;
}
}
V_372 -> V_224 = V_224 ;
V_372 -> V_67 = V_67 ;
return 0 ;
}
void F_130 ( int V_269 , T_1 V_24 , struct V_287 * V_270 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
if ( V_270 )
memcpy ( & V_176 -> V_268 . V_270 , V_270 , sizeof( struct V_287 ) ) ;
else
memset ( & V_176 -> V_268 . V_270 , 0 , sizeof( struct V_287 ) ) ;
V_176 -> V_268 . V_269 = V_269 ;
V_176 -> V_268 . V_24 = V_24 ;
V_176 -> type = V_267 ;
}
void F_131 ( T_8 V_277 , T_5 V_278 , unsigned int V_279 ,
const struct V_370 * V_280 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
struct V_370 * V_33 = & V_176 -> V_276 . V_280 ;
if ( V_280 )
memcpy ( V_33 , V_280 , sizeof( struct V_370 ) ) ;
else
memset ( V_33 , 0 , sizeof( struct V_370 ) ) ;
V_176 -> V_276 . V_277 = V_277 ;
V_176 -> V_276 . V_278 = V_278 ;
V_176 -> V_276 . V_279 = V_279 ;
V_176 -> type = V_275 ;
}
void F_132 ( T_8 V_277 , const struct V_377 * V_378 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
if ( V_378 )
V_176 -> V_284 . V_285 = V_378 -> V_285 ;
else
V_176 -> V_284 . V_285 = 0 ;
V_176 -> V_284 . V_277 = V_277 ;
V_176 -> type = V_283 ;
}
void F_133 ( T_8 V_277 , struct V_287 * V_289 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_288 . V_277 = V_277 ;
V_176 -> V_288 . V_289 = * V_289 ;
V_176 -> type = V_286 ;
}
void F_134 ( struct V_379 * V_380 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_149 . V_59 = V_380 -> V_59 ;
V_176 -> V_149 . V_61 = V_380 -> V_61 ;
V_176 -> V_149 . V_24 = V_380 -> V_24 ;
V_176 -> V_149 . V_261 = 0 ;
F_135 ( V_380 , & V_176 -> V_149 . V_147 ) ;
V_176 -> type = V_148 ;
}
void F_136 ( unsigned long V_263 , T_2 V_59 , V_53 V_61 , T_1 V_24 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_149 . V_263 = V_263 ;
V_176 -> V_149 . V_264 = V_59 ;
V_176 -> V_149 . V_265 = V_61 ;
V_176 -> V_149 . V_266 = V_24 ;
V_176 -> V_149 . V_261 = 1 ;
}
int F_137 ( struct V_381 * V_382 )
{
struct V_243 * V_383 ;
struct V_7 * V_176 = V_100 -> V_7 ;
V_383 = F_58 ( sizeof( * V_383 ) , V_39 ) ;
if ( ! V_383 )
return - V_202 ;
V_383 -> V_246 = V_382 -> V_246 ;
V_383 -> V_384 = V_382 -> V_384 ;
V_383 -> V_213 = V_382 -> V_213 ;
V_383 -> V_337 . type = V_242 ;
V_383 -> V_337 . V_38 = V_176 -> V_197 ;
V_176 -> V_197 = ( void * ) V_383 ;
return 0 ;
}
void F_138 ( int V_259 , unsigned long * args )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> type = V_258 ;
V_176 -> V_260 . V_259 = V_259 ;
memcpy ( V_176 -> V_260 . args , args , V_259 * sizeof( unsigned long ) ) ;
}
void F_139 ( int V_385 , int V_386 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_309 [ 0 ] = V_385 ;
V_176 -> V_309 [ 1 ] = V_386 ;
}
int F_140 ( int V_208 , void * V_387 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
if ( ! V_176 -> V_205 ) {
void * V_33 = F_58 ( sizeof( struct V_388 ) , V_39 ) ;
if ( ! V_33 )
return - V_202 ;
V_176 -> V_205 = V_33 ;
}
V_176 -> V_311 = V_208 ;
memcpy ( V_176 -> V_205 , V_387 , V_208 ) ;
return 0 ;
}
void F_141 ( struct V_55 * V_371 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_315 = V_371 -> V_105 ;
V_176 -> V_316 = F_142 ( V_371 ) ;
V_176 -> V_317 = F_129 ( V_371 ) ;
V_176 -> V_318 = F_143 ( V_371 ) ;
F_33 ( V_371 , & V_176 -> V_319 ) ;
memcpy ( V_176 -> V_320 , V_371 -> V_211 , V_389 ) ;
}
int F_144 ( int V_390 , struct V_55 * V_371 )
{
struct V_313 * V_391 ;
struct V_55 * V_56 = V_100 ;
struct V_7 * V_8 = V_56 -> V_7 ;
T_2 V_59 = F_145 () , V_392 = F_129 ( V_371 ) ;
if ( V_170 && V_371 -> V_171 == V_170 ) {
if ( V_390 == V_393 || V_390 == V_394 || V_390 == V_395 || V_390 == V_396 ) {
V_397 = V_56 -> V_105 ;
if ( V_56 -> V_67 != - 1 )
V_398 = V_56 -> V_67 ;
else
V_398 = V_59 ;
F_33 ( V_56 , & V_399 ) ;
}
if ( ! V_400 || F_146 () )
return 0 ;
}
if ( ! V_8 -> V_315 ) {
V_8 -> V_315 = V_371 -> V_171 ;
V_8 -> V_316 = F_142 ( V_371 ) ;
V_8 -> V_317 = V_392 ;
V_8 -> V_318 = F_143 ( V_371 ) ;
F_33 ( V_371 , & V_8 -> V_319 ) ;
memcpy ( V_8 -> V_320 , V_371 -> V_211 , V_389 ) ;
return 0 ;
}
V_391 = ( void * ) V_8 -> V_198 ;
if ( ! V_391 || V_391 -> V_314 == V_401 ) {
V_391 = F_13 ( sizeof( * V_391 ) , V_159 ) ;
if ( ! V_391 )
return - V_202 ;
V_391 -> V_337 . type = V_225 ;
V_391 -> V_337 . V_38 = V_8 -> V_198 ;
V_8 -> V_198 = ( void * ) V_391 ;
}
F_102 ( V_391 -> V_314 >= V_401 ) ;
V_391 -> V_315 [ V_391 -> V_314 ] = V_371 -> V_171 ;
V_391 -> V_316 [ V_391 -> V_314 ] = F_142 ( V_371 ) ;
V_391 -> V_317 [ V_391 -> V_314 ] = V_392 ;
V_391 -> V_318 [ V_391 -> V_314 ] = F_143 ( V_371 ) ;
F_33 ( V_371 , & V_391 -> V_319 [ V_391 -> V_314 ] ) ;
memcpy ( V_391 -> V_320 [ V_391 -> V_314 ] , V_371 -> V_211 , V_389 ) ;
V_391 -> V_314 ++ ;
return 0 ;
}
int F_147 ( struct V_381 * V_382 ,
const struct V_57 * V_402 , const struct V_57 * V_403 )
{
struct V_305 * V_383 ;
struct V_7 * V_176 = V_100 -> V_7 ;
struct V_350 V_404 ;
struct V_194 * V_194 ;
V_383 = F_58 ( sizeof( * V_383 ) , V_39 ) ;
if ( ! V_383 )
return - V_202 ;
V_383 -> V_337 . type = V_304 ;
V_383 -> V_337 . V_38 = V_176 -> V_197 ;
V_176 -> V_197 = ( void * ) V_383 ;
V_194 = F_148 ( V_382 -> V_405 -> V_406 ) ;
F_116 ( V_194 , & V_404 ) ;
F_149 ( V_194 ) ;
V_383 -> V_251 . V_252 = V_404 . V_252 ;
V_383 -> V_251 . V_254 = V_404 . V_254 ;
V_383 -> V_251 . V_255 = ! ! ( V_404 . V_352 & V_353 ) ;
V_383 -> V_256 = ( V_404 . V_352 & V_354 ) >> V_355 ;
V_383 -> V_307 . V_252 = V_403 -> V_407 ;
V_383 -> V_307 . V_254 = V_403 -> V_408 ;
V_383 -> V_307 . V_292 = V_403 -> V_409 ;
V_383 -> V_308 . V_252 = V_402 -> V_407 ;
V_383 -> V_308 . V_254 = V_402 -> V_408 ;
V_383 -> V_308 . V_292 = V_402 -> V_409 ;
return 0 ;
}
void F_150 ( T_4 V_105 ,
const struct V_57 * V_402 , const struct V_57 * V_403 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_291 . V_105 = V_105 ;
V_176 -> V_291 . V_248 . V_292 = V_402 -> V_409 ;
V_176 -> V_291 . V_248 . V_254 = V_402 -> V_409 ;
V_176 -> V_291 . V_248 . V_252 = V_402 -> V_407 ;
V_176 -> type = V_290 ;
}
void F_151 ( int V_294 , int V_1 )
{
struct V_7 * V_176 = V_100 -> V_7 ;
V_176 -> V_217 . V_294 = V_294 ;
V_176 -> V_217 . V_1 = V_1 ;
V_176 -> type = V_293 ;
}
static void F_152 ( struct V_206 * V_207 , char * V_410 , long V_411 )
{
T_2 V_223 , V_59 ;
V_53 V_61 ;
unsigned int V_224 ;
V_223 = F_142 ( V_100 ) ;
V_224 = F_143 ( V_100 ) ;
F_153 ( & V_59 , & V_61 ) ;
F_66 ( V_207 , L_90 ,
V_223 , V_59 , V_61 , V_224 ) ;
F_64 ( V_207 ) ;
F_66 ( V_207 , L_91 , V_100 -> V_105 ) ;
F_71 ( V_207 , V_100 -> V_211 ) ;
F_66 ( V_207 , L_92 ) ;
F_85 ( V_207 , V_410 ) ;
F_66 ( V_207 , L_93 , V_411 ) ;
}
void F_154 ( long V_411 )
{
struct V_206 * V_207 ;
if ( ! V_328 )
return;
if ( V_411 == V_412 )
return;
V_207 = F_76 ( NULL , V_39 , V_413 ) ;
F_152 ( V_207 , L_94 , V_411 ) ;
F_77 ( V_207 ) ;
}
void F_155 ( unsigned long V_414 )
{
struct V_206 * V_207 ;
V_207 = F_76 ( NULL , V_39 , V_413 ) ;
F_152 ( V_207 , L_95 , V_240 ) ;
F_66 ( V_207 , L_96 , V_414 ) ;
F_77 ( V_207 ) ;
}
struct V_168 * F_156 ( void )
{
struct V_7 * V_8 = V_100 -> V_7 ;
if ( F_11 ( ! V_8 || ! V_8 -> V_181 ) )
return NULL ;
return & V_8 -> V_199 ;
}
