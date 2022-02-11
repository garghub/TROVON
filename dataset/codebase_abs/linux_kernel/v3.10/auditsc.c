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
if ( V_48 -> V_50 == V_108 ) {
if ( ! V_98 )
V_98 = F_31 ( V_48 -> V_51 ) ;
} else if ( V_48 -> V_50 == V_109 ) {
if ( V_98 )
V_98 = ! F_31 ( V_48 -> V_51 ) ;
}
break;
case V_110 :
V_98 = F_24 ( V_54 -> V_60 , V_48 -> V_50 , V_48 -> V_51 ) ;
if ( V_48 -> V_50 == V_108 ) {
if ( ! V_98 )
V_98 = F_32 ( V_48 -> V_51 ) ;
} else if ( V_48 -> V_50 == V_109 ) {
if ( V_98 )
V_98 = ! F_32 ( V_48 -> V_51 ) ;
}
break;
case V_111 :
V_98 = F_24 ( V_54 -> V_66 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_112 :
V_98 = F_24 ( V_54 -> V_70 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_113 :
V_98 = F_29 ( V_53 -> V_114 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_115 :
if ( V_8 )
V_98 = F_29 ( V_8 -> V_10 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_116 :
if ( V_8 && V_8 -> V_117 )
V_98 = F_29 ( V_8 -> V_118 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_119 :
if ( V_8 && V_8 -> V_117 ) {
if ( V_48 -> V_22 )
V_98 = F_29 ( V_8 -> V_117 , V_48 -> V_50 , V_120 ) ;
else
V_98 = F_29 ( V_8 -> V_117 , V_48 -> V_50 , V_121 ) ;
}
break;
case V_122 :
if ( V_46 ) {
if ( F_29 ( F_33 ( V_46 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_33 ( V_46 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) )
++ V_98 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_29 ( F_33 ( V_3 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_33 ( V_3 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_125 :
if ( V_46 ) {
if ( F_29 ( F_34 ( V_46 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_34 ( V_46 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) )
++ V_98 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_29 ( F_34 ( V_3 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_29 ( F_34 ( V_3 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_126 :
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
case V_127 :
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
case V_128 :
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
case V_129 :
if ( V_46 )
V_98 = F_35 ( V_88 -> V_130 , V_46 -> V_25 , V_46 -> V_123 ) ;
break;
case V_131 :
if ( V_8 )
V_98 = F_19 ( V_8 , V_88 -> V_44 ) ;
break;
case V_132 :
V_98 = 0 ;
if ( V_8 )
V_98 = F_22 ( V_53 -> V_62 , V_48 -> V_50 , V_48 -> V_45 ) ;
break;
case V_133 :
V_98 = F_29 ( F_36 ( V_53 ) , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
if ( V_48 -> V_139 ) {
if ( V_93 ) {
F_37 ( V_53 , & V_94 ) ;
V_93 = 0 ;
}
V_98 = F_38 ( V_94 , V_48 -> type ,
V_48 -> V_50 ,
V_48 -> V_139 ,
V_8 ) ;
}
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
if ( V_48 -> V_139 ) {
if ( V_46 ) {
V_98 = F_38 (
V_46 -> V_145 , V_48 -> type , V_48 -> V_50 ,
V_48 -> V_139 , V_8 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_38 ( V_3 -> V_145 , V_48 -> type ,
V_48 -> V_50 , V_48 -> V_139 ,
V_8 ) ) {
++ V_98 ;
break;
}
}
}
if ( ! V_8 || V_8 -> type != V_146 )
break;
if ( F_38 ( V_8 -> V_147 . V_145 ,
V_48 -> type , V_48 -> V_50 ,
V_48 -> V_139 , V_8 ) )
++ V_98 ;
}
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
if ( V_8 )
V_98 = F_29 ( V_8 -> V_19 [ V_48 -> type - V_148 ] , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_152 :
V_98 = 1 ;
break;
case V_153 :
V_98 = F_3 ( V_8 , V_48 -> V_22 ) ;
break;
case V_154 :
V_98 = F_7 ( V_8 , V_48 -> V_22 ) ;
break;
case V_155 :
V_98 = F_25 ( V_53 , V_54 , V_48 , V_8 , V_46 ) ;
break;
}
if ( ! V_98 )
return 0 ;
}
if ( V_8 ) {
if ( V_88 -> V_27 <= V_8 -> V_27 )
return 0 ;
if ( V_88 -> V_156 ) {
F_18 ( V_8 -> V_156 ) ;
V_8 -> V_156 = F_39 ( V_88 -> V_156 , V_157 ) ;
}
V_8 -> V_27 = V_88 -> V_27 ;
}
switch ( V_88 -> V_158 ) {
case V_159 : * V_90 = V_160 ; break;
case V_161 : * V_90 = V_29 ; break;
}
return 1 ;
}
static enum V_89 F_40 ( struct V_52 * V_53 , char * * V_162 )
{
struct V_163 * V_164 ;
enum V_89 V_90 ;
F_41 () ;
F_42 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_27 ( V_53 , & V_164 -> V_88 , NULL , NULL ,
& V_90 , true ) ) {
if ( V_90 == V_29 )
* V_162 = F_39 ( V_164 -> V_88 . V_156 , V_157 ) ;
F_43 () ;
return V_90 ;
}
}
F_43 () ;
return V_165 ;
}
static enum V_89 F_44 ( struct V_52 * V_53 ,
struct V_7 * V_8 ,
struct V_166 * V_167 )
{
struct V_163 * V_164 ;
enum V_89 V_90 ;
if ( V_168 && V_53 -> V_169 == V_168 )
return V_160 ;
F_41 () ;
if ( ! F_45 ( V_167 ) ) {
int V_170 = F_46 ( V_8 -> V_9 ) ;
int V_171 = F_47 ( V_8 -> V_9 ) ;
F_42 (e, list, list) {
if ( ( V_164 -> V_88 . V_2 [ V_170 ] & V_171 ) == V_171 &&
F_27 ( V_53 , & V_164 -> V_88 , V_8 , NULL ,
& V_90 , false ) ) {
F_43 () ;
V_8 -> V_28 = V_90 ;
return V_90 ;
}
}
}
F_43 () ;
return V_165 ;
}
static int F_48 ( struct V_52 * V_53 ,
struct V_23 * V_3 ,
struct V_7 * V_8 ) {
int V_170 , V_171 ;
int V_172 = F_49 ( ( T_4 ) V_3 -> V_25 ) ;
struct V_166 * V_167 = & V_173 [ V_172 ] ;
struct V_163 * V_164 ;
enum V_89 V_90 ;
V_170 = F_46 ( V_8 -> V_9 ) ;
V_171 = F_47 ( V_8 -> V_9 ) ;
if ( F_45 ( V_167 ) )
return 0 ;
F_42 (e, list, list) {
if ( ( V_164 -> V_88 . V_2 [ V_170 ] & V_171 ) == V_171 &&
F_27 ( V_53 , & V_164 -> V_88 , V_8 , V_3 , & V_90 , false ) ) {
V_8 -> V_28 = V_90 ;
return 1 ;
}
}
return 0 ;
}
void F_50 ( struct V_52 * V_53 , struct V_7 * V_8 )
{
struct V_23 * V_3 ;
if ( V_168 && V_53 -> V_169 == V_168 )
return;
F_41 () ;
F_8 (n, &ctx->names_list, list) {
if ( F_48 ( V_53 , V_3 , V_8 ) )
break;
}
F_43 () ;
}
static inline struct V_7 * F_51 ( struct V_52 * V_53 ,
int V_117 ,
long V_118 )
{
struct V_7 * V_174 = V_53 -> V_7 ;
if ( ! V_174 )
return NULL ;
V_174 -> V_117 = V_117 ;
if ( F_4 ( V_118 <= - V_175 ) &&
( V_118 >= - V_176 ) &&
( V_118 != - V_177 ) )
V_174 -> V_118 = - V_178 ;
else
V_174 -> V_118 = V_118 ;
if ( V_174 -> V_179 && ! V_174 -> V_180 ) {
F_44 ( V_53 , V_174 , & V_181 [ V_182 ] ) ;
F_50 ( V_53 , V_174 ) ;
}
V_53 -> V_7 = NULL ;
return V_174 ;
}
static inline void F_52 ( struct V_7 * V_174 )
{
struct V_23 * V_3 , * V_38 ;
#if V_183 == 2
if ( V_174 -> V_184 + V_174 -> V_185 != V_174 -> V_186 ) {
int V_92 = 0 ;
F_53 ( V_187 L_2
L_3
L_4 ,
__FILE__ , __LINE__ ,
V_174 -> V_188 , V_174 -> V_9 , V_174 -> V_179 ,
V_174 -> V_186 , V_174 -> V_184 ,
V_174 -> V_185 ) ;
F_8 (n, &context->names_list, list) {
F_53 ( V_187 L_5 , V_92 ++ ,
V_3 -> V_46 , V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
F_54 () ;
return;
}
#endif
#if V_183
V_174 -> V_184 = 0 ;
V_174 -> V_185 = 0 ;
#endif
F_55 (n, next, &context->names_list, list) {
F_56 ( & V_3 -> V_167 ) ;
if ( V_3 -> V_46 && V_3 -> V_189 )
F_57 ( V_3 -> V_46 ) ;
if ( V_3 -> V_190 )
F_18 ( V_3 ) ;
}
V_174 -> V_186 = 0 ;
F_58 ( & V_174 -> V_191 ) ;
V_174 -> V_191 . V_192 = NULL ;
V_174 -> V_191 . V_193 = NULL ;
}
static inline void F_59 ( struct V_7 * V_174 )
{
struct V_194 * V_195 ;
while ( ( V_195 = V_174 -> V_195 ) ) {
V_174 -> V_195 = V_195 -> V_38 ;
F_18 ( V_195 ) ;
}
while ( ( V_195 = V_174 -> V_196 ) ) {
V_174 -> V_196 = V_195 -> V_38 ;
F_18 ( V_195 ) ;
}
}
static inline struct V_7 * F_60 ( enum V_89 V_90 )
{
struct V_7 * V_174 ;
V_174 = F_13 ( sizeof( * V_174 ) , V_39 ) ;
if ( ! V_174 )
return NULL ;
V_174 -> V_90 = V_90 ;
V_174 -> V_27 = V_90 == V_29 ? ~ 0ULL : 0 ;
F_61 ( & V_174 -> V_197 ) ;
F_61 ( & V_174 -> V_198 ) ;
return V_174 ;
}
int F_62 ( struct V_52 * V_53 )
{
struct V_7 * V_174 ;
enum V_89 V_90 ;
char * V_162 = NULL ;
if ( F_11 ( ! V_199 ) )
return 0 ;
V_90 = F_40 ( V_53 , & V_162 ) ;
if ( V_90 == V_160 )
return 0 ;
if ( ! ( V_174 = F_60 ( V_90 ) ) ) {
F_18 ( V_162 ) ;
F_63 ( L_7 ) ;
return - V_200 ;
}
V_174 -> V_156 = V_162 ;
V_53 -> V_7 = V_174 ;
F_64 ( V_53 , V_201 ) ;
return 0 ;
}
static inline void F_65 ( struct V_7 * V_174 )
{
F_52 ( V_174 ) ;
F_14 ( V_174 , NULL , 0 ) ;
F_17 ( V_174 ) ;
F_59 ( V_174 ) ;
F_18 ( V_174 -> V_156 ) ;
F_18 ( V_174 -> V_202 ) ;
F_18 ( V_174 ) ;
}
static int F_66 ( struct V_7 * V_174 , T_5 V_100 ,
T_2 V_203 , T_2 V_45 , unsigned int V_204 ,
T_4 V_94 , char * V_205 )
{
struct V_206 * V_207 ;
char * V_8 = NULL ;
T_4 V_208 ;
int V_49 = 0 ;
V_207 = F_67 ( V_174 , V_39 , V_209 ) ;
if ( ! V_207 )
return V_49 ;
F_68 ( V_207 , L_8 , V_100 ,
F_69 ( & V_210 , V_203 ) ,
F_69 ( & V_210 , V_45 ) , V_204 ) ;
if ( V_94 ) {
if ( F_70 ( V_94 , & V_8 , & V_208 ) ) {
F_68 ( V_207 , L_9 ) ;
V_49 = 1 ;
} else {
F_68 ( V_207 , L_10 , V_8 ) ;
F_71 ( V_8 , V_208 ) ;
}
}
F_68 ( V_207 , L_11 ) ;
F_72 ( V_207 , V_205 ) ;
F_73 ( V_207 ) ;
return V_49 ;
}
static int F_74 ( struct V_7 * V_174 ,
struct V_206 * * V_207 ,
int V_211 ,
T_6 * V_212 ,
const char T_7 * V_33 ,
char * V_213 )
{
char V_214 [ 12 ] ;
const char T_7 * V_215 = V_33 ;
T_6 V_216 = snprintf ( V_214 , 12 , L_12 , V_211 ) + 5 ;
T_6 V_208 , V_217 , V_218 ;
T_6 V_219 = V_220 ;
unsigned int V_92 , V_221 = 0 , V_222 = 0 ;
int V_223 ;
V_217 = V_208 = F_75 ( V_33 , V_224 ) - 1 ;
if ( F_4 ( ( V_208 == - 1 ) || V_208 > V_224 - 1 ) ) {
F_76 ( 1 ) ;
F_77 ( V_225 , V_95 , 0 ) ;
return - 1 ;
}
do {
if ( V_217 > V_220 )
V_218 = V_220 ;
else
V_218 = V_217 ;
V_223 = F_78 ( V_213 , V_215 , V_218 ) ;
if ( V_223 ) {
F_76 ( 1 ) ;
F_77 ( V_225 , V_95 , 0 ) ;
return - 1 ;
}
V_213 [ V_218 ] = '\0' ;
V_221 = F_79 ( V_213 , V_218 ) ;
if ( V_221 ) {
V_219 = V_220 / 2 ;
break;
}
V_217 -= V_218 ;
V_215 += V_218 ;
} while ( V_217 > 0 );
V_217 = V_208 ;
if ( V_208 > V_219 )
V_222 = 1 ;
for ( V_92 = 0 ; V_217 > 0 ; V_92 ++ ) {
int V_226 ;
if ( V_217 > V_219 )
V_218 = V_219 ;
else
V_218 = V_217 ;
V_226 = V_220 - V_216 - * V_212 ;
if ( V_221 )
V_226 -= ( V_218 * 2 ) ;
else
V_226 -= V_218 ;
if ( V_226 < 0 ) {
* V_212 = 0 ;
F_73 ( * V_207 ) ;
* V_207 = F_67 ( V_174 , V_39 , V_227 ) ;
if ( ! * V_207 )
return 0 ;
}
if ( ( V_92 == 0 ) && ( V_222 ) )
F_68 ( * V_207 , L_13 , V_211 ,
V_221 ? 2 * V_208 : V_208 ) ;
if ( V_208 >= V_219 )
V_223 = F_78 ( V_213 , V_33 , V_218 ) ;
else
V_223 = 0 ;
if ( V_223 ) {
F_76 ( 1 ) ;
F_77 ( V_225 , V_95 , 0 ) ;
return - 1 ;
}
V_213 [ V_218 ] = '\0' ;
F_68 ( * V_207 , L_14 , V_211 ) ;
if ( V_222 )
F_68 ( * V_207 , L_15 , V_92 ) ;
F_68 ( * V_207 , L_16 ) ;
if ( V_221 )
F_80 ( * V_207 , V_213 , V_218 ) ;
else
F_81 ( * V_207 , V_213 ) ;
V_33 += V_218 ;
V_217 -= V_218 ;
* V_212 += V_216 ;
if ( V_221 )
* V_212 += V_218 * 2 ;
else
* V_212 += V_218 ;
}
return V_208 + 1 ;
}
static void F_82 ( struct V_7 * V_174 ,
struct V_206 * * V_207 ,
struct V_228 * V_229 )
{
int V_92 , V_208 ;
T_6 V_212 = 0 ;
const char T_7 * V_33 ;
char * V_213 ;
if ( V_229 -> V_230 != V_95 -> V_230 )
return;
V_33 = ( const char T_7 * ) V_229 -> V_230 -> V_231 ;
F_68 ( * V_207 , L_17 , V_229 -> V_232 ) ;
V_213 = F_83 ( V_220 + 1 , V_39 ) ;
if ( ! V_213 ) {
F_84 ( L_18 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_229 -> V_232 ; V_92 ++ ) {
V_208 = F_74 ( V_174 , V_207 , V_92 ,
& V_212 , V_33 , V_213 ) ;
if ( V_208 <= 0 )
break;
V_33 += V_208 ;
}
F_18 ( V_213 ) ;
}
static void F_85 ( struct V_7 * V_174 , int * V_233 )
{
struct V_206 * V_207 ;
int V_92 ;
V_207 = F_67 ( V_174 , V_39 , V_174 -> type ) ;
if ( ! V_207 )
return;
switch ( V_174 -> type ) {
case V_234 : {
int V_235 = V_174 -> V_236 . V_235 ;
F_68 ( V_207 , L_19 , V_235 ) ;
for ( V_92 = 0 ; V_92 < V_235 ; V_92 ++ )
F_68 ( V_207 , L_20 , V_92 ,
V_174 -> V_236 . args [ V_92 ] ) ;
break; }
case V_146 : {
T_4 V_145 = V_174 -> V_147 . V_145 ;
F_68 ( V_207 , L_21 ,
F_69 ( & V_210 , V_174 -> V_147 . V_45 ) ,
F_86 ( & V_210 , V_174 -> V_147 . V_51 ) ,
V_174 -> V_147 . V_24 ) ;
if ( V_145 ) {
char * V_8 = NULL ;
T_4 V_208 ;
if ( F_70 ( V_145 , & V_8 , & V_208 ) ) {
F_68 ( V_207 , L_22 , V_145 ) ;
* V_233 = 1 ;
} else {
F_68 ( V_207 , L_10 , V_8 ) ;
F_71 ( V_8 , V_208 ) ;
}
}
if ( V_174 -> V_147 . V_237 ) {
F_73 ( V_207 ) ;
V_207 = F_67 ( V_174 , V_39 ,
V_238 ) ;
if ( F_4 ( ! V_207 ) )
return;
F_68 ( V_207 ,
L_23 ,
V_174 -> V_147 . V_239 ,
V_174 -> V_147 . V_240 ,
V_174 -> V_147 . V_241 ,
V_174 -> V_147 . V_242 ) ;
}
break; }
case V_243 : {
F_68 ( V_207 ,
L_24
L_25 ,
V_174 -> V_244 . V_245 , V_174 -> V_244 . V_24 ,
V_174 -> V_244 . V_246 . V_247 ,
V_174 -> V_244 . V_246 . V_248 ,
V_174 -> V_244 . V_246 . V_249 ,
V_174 -> V_244 . V_246 . V_250 ) ;
break; }
case V_251 : {
F_68 ( V_207 ,
L_26
L_27 ,
V_174 -> V_252 . V_253 ,
V_174 -> V_252 . V_254 ,
V_174 -> V_252 . V_255 ,
V_174 -> V_252 . V_256 . V_257 ,
V_174 -> V_252 . V_256 . V_258 ) ;
break; }
case V_259 : {
F_68 ( V_207 , L_28 ,
V_174 -> V_260 . V_253 ,
V_174 -> V_260 . V_261 ) ;
break; }
case V_262 : {
struct V_263 * V_246 = & V_174 -> V_264 . V_265 ;
F_68 ( V_207 ,
L_29
L_30 ,
V_174 -> V_264 . V_253 ,
V_246 -> V_247 , V_246 -> V_248 ,
V_246 -> V_249 , V_246 -> V_250 ) ;
break; }
case V_266 : {
F_68 ( V_207 , L_31 , V_174 -> V_267 . V_100 ) ;
F_87 ( V_207 , L_32 , & V_174 -> V_267 . V_268 . V_269 ) ;
F_87 ( V_207 , L_33 , & V_174 -> V_267 . V_268 . V_270 ) ;
F_87 ( V_207 , L_34 , & V_174 -> V_267 . V_268 . V_271 ) ;
break; }
case V_272 : {
F_68 ( V_207 , L_35 , V_174 -> V_273 . V_274 ,
V_174 -> V_273 . V_1 ) ;
break; }
}
F_73 ( V_207 ) ;
}
static void F_88 ( struct V_7 * V_174 , struct V_52 * V_53 )
{
int V_92 , V_233 = 0 ;
struct V_206 * V_207 ;
struct V_194 * V_195 ;
struct V_23 * V_3 ;
V_174 -> V_114 = V_53 -> V_114 ;
V_207 = F_67 ( V_174 , V_39 , V_275 ) ;
if ( ! V_207 )
return;
F_68 ( V_207 , L_36 ,
V_174 -> V_10 , V_174 -> V_9 ) ;
if ( V_174 -> V_114 != V_276 )
F_68 ( V_207 , L_37 , V_174 -> V_114 ) ;
if ( V_174 -> V_117 )
F_68 ( V_207 , L_38 ,
( V_174 -> V_117 == V_120 ) ? L_39 : L_40 ,
V_174 -> V_118 ) ;
F_68 ( V_207 ,
L_41 ,
V_174 -> V_19 [ 0 ] ,
V_174 -> V_19 [ 1 ] ,
V_174 -> V_19 [ 2 ] ,
V_174 -> V_19 [ 3 ] ,
V_174 -> V_186 ) ;
F_89 ( V_207 , V_53 ) ;
F_90 ( V_207 , V_174 -> V_156 ) ;
F_73 ( V_207 ) ;
for ( V_195 = V_174 -> V_195 ; V_195 ; V_195 = V_195 -> V_38 ) {
V_207 = F_67 ( V_174 , V_39 , V_195 -> type ) ;
if ( ! V_207 )
continue;
switch ( V_195 -> type ) {
case V_227 : {
struct V_228 * V_229 = ( void * ) V_195 ;
F_82 ( V_174 , & V_207 , V_229 ) ;
break; }
case V_277 : {
struct V_278 * V_279 = ( void * ) V_195 ;
F_68 ( V_207 , L_42 , V_279 -> V_280 ) ;
F_87 ( V_207 , L_43 , & V_279 -> V_281 . V_270 ) ;
F_87 ( V_207 , L_44 , & V_279 -> V_281 . V_269 ) ;
F_68 ( V_207 , L_45 , V_279 -> V_281 . V_282 ) ;
F_87 ( V_207 , L_46 , & V_279 -> V_283 . V_270 ) ;
F_87 ( V_207 , L_47 , & V_279 -> V_283 . V_269 ) ;
F_87 ( V_207 , L_48 , & V_279 -> V_283 . V_271 ) ;
F_87 ( V_207 , L_49 , & V_279 -> V_284 . V_270 ) ;
F_87 ( V_207 , L_50 , & V_279 -> V_284 . V_269 ) ;
F_87 ( V_207 , L_51 , & V_279 -> V_284 . V_271 ) ;
break; }
}
F_73 ( V_207 ) ;
}
if ( V_174 -> type )
F_85 ( V_174 , & V_233 ) ;
if ( V_174 -> V_285 [ 0 ] >= 0 ) {
V_207 = F_67 ( V_174 , V_39 , V_286 ) ;
if ( V_207 ) {
F_68 ( V_207 , L_52 ,
V_174 -> V_285 [ 0 ] , V_174 -> V_285 [ 1 ] ) ;
F_73 ( V_207 ) ;
}
}
if ( V_174 -> V_287 ) {
V_207 = F_67 ( V_174 , V_39 , V_288 ) ;
if ( V_207 ) {
F_68 ( V_207 , L_53 ) ;
F_80 ( V_207 , ( void * ) V_174 -> V_202 ,
V_174 -> V_287 ) ;
F_73 ( V_207 ) ;
}
}
for ( V_195 = V_174 -> V_196 ; V_195 ; V_195 = V_195 -> V_38 ) {
struct V_289 * V_279 = ( void * ) V_195 ;
for ( V_92 = 0 ; V_92 < V_279 -> V_290 ; V_92 ++ )
if ( F_66 ( V_174 , V_279 -> V_291 [ V_92 ] ,
V_279 -> V_292 [ V_92 ] ,
V_279 -> V_293 [ V_92 ] ,
V_279 -> V_294 [ V_92 ] ,
V_279 -> V_295 [ V_92 ] ,
V_279 -> V_296 [ V_92 ] ) )
V_233 = 1 ;
}
if ( V_174 -> V_291 &&
F_66 ( V_174 , V_174 -> V_291 ,
V_174 -> V_292 , V_174 -> V_293 ,
V_174 -> V_294 ,
V_174 -> V_295 , V_174 -> V_296 ) )
V_233 = 1 ;
if ( V_174 -> V_191 . V_192 && V_174 -> V_191 . V_193 ) {
V_207 = F_67 ( V_174 , V_39 , V_297 ) ;
if ( V_207 ) {
F_91 ( V_207 , L_54 , & V_174 -> V_191 ) ;
F_73 ( V_207 ) ;
}
}
V_92 = 0 ;
F_8 (n, &context->names_list, list)
F_92 ( V_174 , V_3 , NULL , V_92 ++ , & V_233 ) ;
V_207 = F_67 ( V_174 , V_39 , V_298 ) ;
if ( V_207 )
F_73 ( V_207 ) ;
if ( V_233 )
F_84 ( L_55 ) ;
}
void F_93 ( struct V_52 * V_53 )
{
struct V_7 * V_174 ;
V_174 = F_51 ( V_53 , 0 , 0 ) ;
if ( ! V_174 )
return;
if ( V_174 -> V_179 && V_174 -> V_28 == V_29 )
F_88 ( V_174 , V_53 ) ;
if ( ! F_45 ( & V_174 -> V_197 ) )
F_94 ( & V_174 -> V_197 ) ;
F_65 ( V_174 ) ;
}
void F_95 ( int V_10 , int V_9 ,
unsigned long V_299 , unsigned long V_300 ,
unsigned long V_301 , unsigned long V_302 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_174 = V_53 -> V_7 ;
enum V_89 V_90 ;
if ( ! V_174 )
return;
F_96 ( V_174 -> V_179 || V_174 -> V_186 ) ;
if ( ! V_303 )
return;
V_174 -> V_10 = V_10 ;
V_174 -> V_9 = V_9 ;
V_174 -> V_19 [ 0 ] = V_299 ;
V_174 -> V_19 [ 1 ] = V_300 ;
V_174 -> V_19 [ 2 ] = V_301 ;
V_174 -> V_19 [ 3 ] = V_302 ;
V_90 = V_174 -> V_90 ;
V_174 -> V_180 = ! V_304 ;
if ( ! V_174 -> V_180 && V_90 == V_165 ) {
V_174 -> V_27 = 0 ;
V_90 = F_44 ( V_53 , V_174 , & V_181 [ V_305 ] ) ;
}
if ( V_90 == V_160 )
return;
V_174 -> V_188 = 0 ;
V_174 -> ctime = V_306 ;
V_174 -> V_179 = 1 ;
V_174 -> V_28 = V_90 ;
V_174 -> V_102 = 0 ;
}
void F_97 ( int V_307 , long V_118 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_174 ;
if ( V_307 )
V_307 = V_120 ;
else
V_307 = V_121 ;
V_174 = F_51 ( V_53 , V_307 , V_118 ) ;
if ( ! V_174 )
return;
if ( V_174 -> V_179 && V_174 -> V_28 == V_29 )
F_88 ( V_174 , V_53 ) ;
V_174 -> V_179 = 0 ;
V_174 -> V_27 = V_174 -> V_90 == V_29 ? ~ 0ULL : 0 ;
if ( ! F_45 ( & V_174 -> V_197 ) )
F_94 ( & V_174 -> V_197 ) ;
F_52 ( V_174 ) ;
F_14 ( V_174 , NULL , 0 ) ;
F_59 ( V_174 ) ;
V_174 -> V_195 = NULL ;
V_174 -> V_196 = NULL ;
V_174 -> V_291 = 0 ;
V_174 -> V_295 = 0 ;
V_174 -> V_287 = 0 ;
V_174 -> type = 0 ;
V_174 -> V_285 [ 0 ] = - 1 ;
if ( V_174 -> V_90 != V_29 ) {
F_18 ( V_174 -> V_156 ) ;
V_174 -> V_156 = NULL ;
}
V_53 -> V_7 = V_174 ;
}
static inline void F_98 ( const struct V_308 * V_308 )
{
#ifdef F_15
struct V_7 * V_174 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
int V_41 ;
if ( F_11 ( F_99 ( & V_308 -> V_309 ) ) )
return;
V_174 = V_95 -> V_7 ;
V_33 = V_174 -> V_34 ;
V_41 = V_174 -> V_36 ;
F_41 () ;
V_31 = F_100 ( V_308 ) ;
F_43 () ;
if ( ! V_31 )
return;
if ( F_11 ( F_10 ( V_174 , V_31 ) ) )
return;
if ( F_4 ( ! F_12 ( V_174 ) ) ) {
F_53 ( V_310 L_56 ) ;
F_9 ( V_174 ) ;
F_16 ( V_31 ) ;
F_14 ( V_174 , V_33 , V_41 ) ;
return;
}
F_10 ( V_174 , V_31 ) ;
#endif
}
static void F_101 ( const struct V_192 * V_192 )
{
#ifdef F_15
struct V_7 * V_174 ;
struct V_32 * V_33 ;
const struct V_192 * V_311 , * V_312 ;
struct V_30 * V_313 ;
unsigned long V_314 ;
int V_41 ;
V_174 = V_95 -> V_7 ;
V_33 = V_174 -> V_34 ;
V_41 = V_174 -> V_36 ;
V_315:
V_313 = NULL ;
V_311 = V_192 ;
F_41 () ;
V_314 = F_102 ( & V_316 ) ;
for(; ; ) {
struct V_308 * V_308 = V_311 -> V_317 ;
if ( V_308 && F_4 ( ! F_99 ( & V_308 -> V_309 ) ) ) {
struct V_30 * V_31 ;
V_31 = F_100 ( V_308 ) ;
if ( V_31 ) {
if ( F_4 ( ! F_10 ( V_174 , V_31 ) ) ) {
V_313 = V_31 ;
break;
}
}
}
V_312 = V_311 -> V_318 ;
if ( V_312 == V_311 )
break;
V_311 = V_312 ;
}
if ( F_4 ( F_103 ( & V_316 , V_314 ) || V_313 ) ) {
F_43 () ;
if ( ! V_313 ) {
F_14 ( V_174 , V_33 , V_41 ) ;
goto V_315;
}
F_16 ( V_313 ) ;
if ( F_12 ( V_174 ) ) {
F_14 ( V_174 , V_33 , V_41 ) ;
goto V_315;
}
F_53 ( V_310
L_56 ) ;
F_14 ( V_174 , V_33 , V_41 ) ;
F_9 ( V_174 ) ;
return;
}
F_43 () ;
#endif
}
static struct V_23 * F_104 ( struct V_7 * V_174 ,
unsigned char type )
{
struct V_23 * V_319 ;
if ( V_174 -> V_186 < V_320 ) {
V_319 = & V_174 -> V_321 [ V_174 -> V_186 ] ;
memset ( V_319 , 0 , sizeof( * V_319 ) ) ;
} else {
V_319 = F_13 ( sizeof( * V_319 ) , V_322 ) ;
if ( ! V_319 )
return NULL ;
V_319 -> V_190 = true ;
}
V_319 -> V_25 = ( unsigned long ) - 1 ;
V_319 -> type = type ;
F_105 ( & V_319 -> V_167 , & V_174 -> V_198 ) ;
V_174 -> V_186 ++ ;
#if V_183
V_174 -> V_185 ++ ;
#endif
return V_319 ;
}
struct V_323 *
F_106 ( const T_7 char * V_324 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_23 * V_3 ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( V_3 -> V_46 -> V_324 == V_324 )
return V_3 -> V_46 ;
}
return NULL ;
}
void F_107 ( struct V_323 * V_46 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_23 * V_3 ;
if ( ! V_174 -> V_179 ) {
#if V_183 == 2
F_53 ( V_187 L_57 ,
__FILE__ , __LINE__ , V_174 -> V_188 , V_46 ) ;
F_54 () ;
#endif
return;
}
#if V_183
F_96 ( ! V_46 -> V_46 ) ;
#endif
V_3 = F_104 ( V_174 , V_325 ) ;
if ( ! V_3 )
return;
V_3 -> V_46 = V_46 ;
V_3 -> V_326 = V_327 ;
V_3 -> V_189 = true ;
V_46 -> V_319 = V_3 ;
if ( ! V_174 -> V_191 . V_192 )
F_108 ( V_95 -> V_328 , & V_174 -> V_191 ) ;
}
void F_109 ( struct V_323 * V_46 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
F_96 ( ! V_174 ) ;
if ( ! V_174 -> V_179 ) {
#if V_183 == 2
F_53 ( V_187 L_58 ,
__FILE__ , __LINE__ , V_174 -> V_188 , V_46 ) ;
if ( V_174 -> V_186 ) {
struct V_23 * V_3 ;
int V_92 = 0 ;
F_8 (n, &context->names_list, list)
F_53 ( V_187 L_59 , V_92 ++ ,
V_3 -> V_46 , V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
#endif
F_57 ( V_46 ) ;
}
#if V_183
else {
++ V_174 -> V_184 ;
if ( V_174 -> V_184 > V_174 -> V_186 ) {
F_53 ( V_187 L_60
L_61
L_62 ,
__FILE__ , __LINE__ ,
V_174 -> V_188 , V_174 -> V_9 ,
V_174 -> V_179 , V_46 -> V_46 ,
V_174 -> V_186 , V_174 -> V_184 ) ;
F_54 () ;
}
}
#endif
}
void F_110 ( struct V_323 * V_46 , const struct V_192 * V_192 ,
unsigned int V_312 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
const struct V_308 * V_308 = V_192 -> V_317 ;
struct V_23 * V_3 ;
if ( ! V_174 -> V_179 )
return;
if ( ! V_46 )
goto V_329;
#if V_183
F_96 ( ! V_46 -> V_46 ) ;
#endif
V_3 = V_46 -> V_319 ;
if ( V_3 ) {
if ( V_312 ) {
if ( V_3 -> type == V_330 ||
V_3 -> type == V_325 )
goto V_331;
} else {
if ( V_3 -> type != V_330 )
goto V_331;
}
}
F_111 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> V_46 -> V_46 != V_46 -> V_46 )
continue;
if ( V_312 ) {
if ( V_3 -> type == V_330 ||
V_3 -> type == V_325 )
goto V_331;
} else {
if ( V_3 -> type != V_330 )
goto V_331;
}
}
V_329:
V_3 = F_104 ( V_174 , V_332 ) ;
if ( ! V_3 )
return;
V_331:
if ( V_312 ) {
V_3 -> V_326 = V_3 -> V_46 ? F_112 ( V_3 -> V_46 -> V_46 ) : V_327 ;
V_3 -> type = V_330 ;
} else {
V_3 -> V_326 = V_327 ;
V_3 -> type = V_332 ;
}
F_101 ( V_192 ) ;
F_113 ( V_3 , V_192 , V_308 ) ;
}
void F_114 ( const struct V_308 * V_312 ,
const struct V_192 * V_192 ,
const unsigned char type )
{
struct V_7 * V_174 = V_95 -> V_7 ;
const struct V_308 * V_308 = V_192 -> V_317 ;
const char * V_333 = V_192 -> V_334 . V_46 ;
struct V_23 * V_3 , * V_335 = NULL , * V_336 = NULL ;
if ( ! V_174 -> V_179 )
return;
if ( V_308 )
F_98 ( V_308 ) ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != V_330 )
continue;
if ( V_3 -> V_25 == V_312 -> V_337 &&
! F_115 ( V_333 , V_3 -> V_46 -> V_46 , V_3 -> V_326 ) ) {
V_335 = V_3 ;
break;
}
}
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != type )
continue;
if ( V_335 && ( V_3 -> V_46 != V_335 -> V_46 ) )
continue;
if ( ! strcmp ( V_333 , V_3 -> V_46 -> V_46 ) ||
! F_115 ( V_333 , V_3 -> V_46 -> V_46 ,
V_335 ?
V_335 -> V_326 :
V_327 ) ) {
V_336 = V_3 ;
break;
}
}
if ( ! V_335 ) {
V_3 = F_104 ( V_174 , V_330 ) ;
if ( ! V_3 )
return;
F_113 ( V_3 , NULL , V_312 ) ;
}
if ( ! V_336 ) {
V_336 = F_104 ( V_174 , type ) ;
if ( ! V_336 )
return;
if ( V_335 ) {
V_336 -> V_46 = V_335 -> V_46 ;
V_336 -> V_326 = V_327 ;
V_336 -> V_189 = false ;
}
}
if ( V_308 )
F_113 ( V_336 , V_192 , V_308 ) ;
else
V_336 -> V_25 = ( unsigned long ) - 1 ;
}
int F_116 ( struct V_7 * V_8 ,
struct V_338 * V_339 , unsigned int * V_188 )
{
if ( ! V_8 -> V_179 )
return 0 ;
if ( ! V_8 -> V_188 )
V_8 -> V_188 = F_117 () ;
V_339 -> V_257 = V_8 -> ctime . V_257 ;
V_339 -> V_258 = V_8 -> ctime . V_258 ;
* V_188 = V_8 -> V_188 ;
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
return 1 ;
}
int F_118 ( T_2 V_62 )
{
struct V_52 * V_340 = V_95 ;
struct V_7 * V_174 = V_340 -> V_7 ;
unsigned int V_204 ;
#ifdef F_119
if ( F_36 ( V_340 ) )
return - V_341 ;
#else
if ( ! F_120 ( V_342 ) )
return - V_341 ;
#endif
V_204 = F_121 ( & V_343 ) ;
if ( V_174 && V_174 -> V_179 ) {
struct V_206 * V_207 ;
V_207 = F_67 ( NULL , V_39 , V_344 ) ;
if ( V_207 ) {
F_68 ( V_207 , L_63
L_64
L_65 ,
V_340 -> V_100 ,
F_69 ( & V_210 , F_122 ( V_340 ) ) ,
F_69 ( & V_210 , V_340 -> V_62 ) ,
F_69 ( & V_210 , V_62 ) ,
V_340 -> V_204 , V_204 ) ;
F_73 ( V_207 ) ;
}
}
V_340 -> V_204 = V_204 ;
V_340 -> V_62 = V_62 ;
return 0 ;
}
void F_123 ( int V_245 , T_1 V_24 , struct V_263 * V_246 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( V_246 )
memcpy ( & V_174 -> V_244 . V_246 , V_246 , sizeof( struct V_263 ) ) ;
else
memset ( & V_174 -> V_244 . V_246 , 0 , sizeof( struct V_263 ) ) ;
V_174 -> V_244 . V_245 = V_245 ;
V_174 -> V_244 . V_24 = V_24 ;
V_174 -> type = V_243 ;
}
void F_124 ( T_8 V_253 , T_6 V_254 , unsigned int V_255 ,
const struct V_338 * V_256 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_338 * V_33 = & V_174 -> V_252 . V_256 ;
if ( V_256 )
memcpy ( V_33 , V_256 , sizeof( struct V_338 ) ) ;
else
memset ( V_33 , 0 , sizeof( struct V_338 ) ) ;
V_174 -> V_252 . V_253 = V_253 ;
V_174 -> V_252 . V_254 = V_254 ;
V_174 -> V_252 . V_255 = V_255 ;
V_174 -> type = V_251 ;
}
void F_125 ( T_8 V_253 , const struct V_345 * V_346 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( V_346 )
V_174 -> V_260 . V_261 = V_346 -> V_261 ;
else
V_174 -> V_260 . V_261 = 0 ;
V_174 -> V_260 . V_253 = V_253 ;
V_174 -> type = V_259 ;
}
void F_126 ( T_8 V_253 , struct V_263 * V_265 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_264 . V_253 = V_253 ;
V_174 -> V_264 . V_265 = * V_265 ;
V_174 -> type = V_262 ;
}
void F_127 ( struct V_347 * V_348 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_147 . V_45 = V_348 -> V_45 ;
V_174 -> V_147 . V_51 = V_348 -> V_51 ;
V_174 -> V_147 . V_24 = V_348 -> V_24 ;
V_174 -> V_147 . V_237 = 0 ;
F_128 ( V_348 , & V_174 -> V_147 . V_145 ) ;
V_174 -> type = V_146 ;
}
void F_129 ( unsigned long V_239 , T_9 V_45 , T_10 V_51 , T_1 V_24 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_147 . V_239 = V_239 ;
V_174 -> V_147 . V_240 = V_45 ;
V_174 -> V_147 . V_241 = V_51 ;
V_174 -> V_147 . V_242 = V_24 ;
V_174 -> V_147 . V_237 = 1 ;
}
int F_130 ( struct V_349 * V_350 )
{
struct V_228 * V_351 ;
struct V_7 * V_174 = V_95 -> V_7 ;
V_351 = F_83 ( sizeof( * V_351 ) , V_39 ) ;
if ( ! V_351 )
return - V_200 ;
V_351 -> V_232 = V_350 -> V_232 ;
V_351 -> V_352 = V_350 -> V_352 ;
V_351 -> V_230 = V_350 -> V_230 ;
V_351 -> V_311 . type = V_227 ;
V_351 -> V_311 . V_38 = V_174 -> V_195 ;
V_174 -> V_195 = ( void * ) V_351 ;
return 0 ;
}
int F_131 ( int V_235 , unsigned long * args )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( V_235 <= 0 || V_235 > V_353 || ! args )
return - V_354 ;
V_174 -> type = V_234 ;
V_174 -> V_236 . V_235 = V_235 ;
memcpy ( V_174 -> V_236 . args , args , V_235 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_132 ( int V_355 , int V_356 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_285 [ 0 ] = V_355 ;
V_174 -> V_285 [ 1 ] = V_356 ;
}
int F_133 ( int V_208 , void * V_357 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( ! V_174 -> V_202 ) {
void * V_33 = F_83 ( sizeof( struct V_358 ) , V_39 ) ;
if ( ! V_33 )
return - V_200 ;
V_174 -> V_202 = V_33 ;
}
V_174 -> V_287 = V_208 ;
memcpy ( V_174 -> V_202 , V_357 , V_208 ) ;
return 0 ;
}
void F_134 ( struct V_52 * V_339 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_291 = V_339 -> V_100 ;
V_174 -> V_292 = F_135 ( V_339 ) ;
V_174 -> V_293 = F_122 ( V_339 ) ;
V_174 -> V_294 = F_136 ( V_339 ) ;
F_37 ( V_339 , & V_174 -> V_295 ) ;
memcpy ( V_174 -> V_296 , V_339 -> V_205 , V_359 ) ;
}
int F_137 ( int V_360 , struct V_52 * V_339 )
{
struct V_289 * V_361 ;
struct V_52 * V_53 = V_95 ;
struct V_7 * V_8 = V_53 -> V_7 ;
T_2 V_45 = F_138 () , V_362 = F_122 ( V_339 ) ;
if ( V_168 && V_339 -> V_169 == V_168 ) {
if ( V_360 == V_363 || V_360 == V_364 || V_360 == V_365 || V_360 == V_366 ) {
V_367 = V_53 -> V_100 ;
if ( F_139 ( V_53 -> V_62 ) )
V_368 = V_53 -> V_62 ;
else
V_368 = V_45 ;
F_37 ( V_53 , & V_369 ) ;
}
if ( ! V_370 || F_140 () )
return 0 ;
}
if ( ! V_8 -> V_291 ) {
V_8 -> V_291 = V_339 -> V_169 ;
V_8 -> V_292 = F_135 ( V_339 ) ;
V_8 -> V_293 = V_362 ;
V_8 -> V_294 = F_136 ( V_339 ) ;
F_37 ( V_339 , & V_8 -> V_295 ) ;
memcpy ( V_8 -> V_296 , V_339 -> V_205 , V_359 ) ;
return 0 ;
}
V_361 = ( void * ) V_8 -> V_196 ;
if ( ! V_361 || V_361 -> V_290 == V_371 ) {
V_361 = F_13 ( sizeof( * V_361 ) , V_157 ) ;
if ( ! V_361 )
return - V_200 ;
V_361 -> V_311 . type = V_209 ;
V_361 -> V_311 . V_38 = V_8 -> V_196 ;
V_8 -> V_196 = ( void * ) V_361 ;
}
F_96 ( V_361 -> V_290 >= V_371 ) ;
V_361 -> V_291 [ V_361 -> V_290 ] = V_339 -> V_169 ;
V_361 -> V_292 [ V_361 -> V_290 ] = F_135 ( V_339 ) ;
V_361 -> V_293 [ V_361 -> V_290 ] = V_362 ;
V_361 -> V_294 [ V_361 -> V_290 ] = F_136 ( V_339 ) ;
F_37 ( V_339 , & V_361 -> V_295 [ V_361 -> V_290 ] ) ;
memcpy ( V_361 -> V_296 [ V_361 -> V_290 ] , V_339 -> V_205 , V_359 ) ;
V_361 -> V_290 ++ ;
return 0 ;
}
int F_141 ( struct V_349 * V_350 ,
const struct V_54 * V_372 , const struct V_54 * V_373 )
{
struct V_278 * V_351 ;
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_374 V_375 ;
struct V_192 * V_192 ;
V_351 = F_83 ( sizeof( * V_351 ) , V_39 ) ;
if ( ! V_351 )
return - V_200 ;
V_351 -> V_311 . type = V_277 ;
V_351 -> V_311 . V_38 = V_174 -> V_195 ;
V_174 -> V_195 = ( void * ) V_351 ;
V_192 = F_142 ( V_350 -> V_376 -> V_377 ) ;
F_143 ( V_192 , & V_375 ) ;
F_144 ( V_192 ) ;
V_351 -> V_281 . V_270 = V_375 . V_270 ;
V_351 -> V_281 . V_269 = V_375 . V_269 ;
V_351 -> V_281 . V_282 = ! ! ( V_375 . V_378 & V_379 ) ;
V_351 -> V_280 = ( V_375 . V_378 & V_380 ) >> V_381 ;
V_351 -> V_283 . V_270 = V_373 -> V_382 ;
V_351 -> V_283 . V_269 = V_373 -> V_383 ;
V_351 -> V_283 . V_271 = V_373 -> V_384 ;
V_351 -> V_284 . V_270 = V_372 -> V_382 ;
V_351 -> V_284 . V_269 = V_372 -> V_383 ;
V_351 -> V_284 . V_271 = V_372 -> V_384 ;
return 0 ;
}
void F_145 ( T_5 V_100 ,
const struct V_54 * V_372 , const struct V_54 * V_373 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_267 . V_100 = V_100 ;
V_174 -> V_267 . V_268 . V_271 = V_372 -> V_384 ;
V_174 -> V_267 . V_268 . V_269 = V_372 -> V_384 ;
V_174 -> V_267 . V_268 . V_270 = V_372 -> V_382 ;
V_174 -> type = V_266 ;
}
void F_146 ( int V_274 , int V_1 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_273 . V_274 = V_274 ;
V_174 -> V_273 . V_1 = V_1 ;
V_174 -> type = V_272 ;
}
static void F_147 ( struct V_206 * V_207 )
{
T_2 V_203 , V_45 ;
T_3 V_51 ;
unsigned int V_204 ;
V_203 = F_135 ( V_95 ) ;
V_204 = F_136 ( V_95 ) ;
F_148 ( & V_45 , & V_51 ) ;
F_68 ( V_207 , L_66 ,
F_69 ( & V_210 , V_203 ) ,
F_69 ( & V_210 , V_45 ) ,
F_86 ( & V_210 , V_51 ) ,
V_204 ) ;
F_149 ( V_207 ) ;
F_68 ( V_207 , L_67 , V_95 -> V_100 ) ;
F_72 ( V_207 , V_95 -> V_205 ) ;
}
static void F_150 ( struct V_206 * V_207 , char * V_385 , long V_386 )
{
F_147 ( V_207 ) ;
F_68 ( V_207 , L_68 ) ;
F_81 ( V_207 , V_385 ) ;
F_68 ( V_207 , L_69 , V_386 ) ;
}
void F_151 ( long V_386 )
{
struct V_206 * V_207 ;
if ( ! V_303 )
return;
if ( V_386 == V_387 )
return;
V_207 = F_67 ( NULL , V_39 , V_388 ) ;
if ( F_4 ( ! V_207 ) )
return;
F_150 ( V_207 , L_70 , V_386 ) ;
F_73 ( V_207 ) ;
}
void F_152 ( unsigned long V_389 , long V_386 , int V_390 )
{
struct V_206 * V_207 ;
V_207 = F_67 ( NULL , V_39 , V_391 ) ;
if ( F_4 ( ! V_207 ) )
return;
F_147 ( V_207 ) ;
F_68 ( V_207 , L_69 , V_386 ) ;
F_68 ( V_207 , L_71 , V_389 ) ;
F_68 ( V_207 , L_72 , F_153 () ) ;
F_68 ( V_207 , L_73 , F_154 ( V_95 ) ) ;
F_68 ( V_207 , L_74 , V_390 ) ;
F_73 ( V_207 ) ;
}
struct V_166 * F_155 ( void )
{
struct V_7 * V_8 = V_95 -> V_7 ;
if ( F_11 ( ! V_8 || ! V_8 -> V_179 ) )
return NULL ;
return & V_8 -> V_197 ;
}
