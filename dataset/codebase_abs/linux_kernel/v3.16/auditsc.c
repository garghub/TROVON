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
T_5 V_99 ;
switch ( V_48 -> type ) {
case V_100 :
V_99 = F_29 ( V_53 ) ;
V_98 = F_30 ( V_99 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_101 :
if ( V_8 ) {
if ( ! V_8 -> V_102 )
V_8 -> V_102 = F_31 ( V_53 ) ;
V_98 = F_30 ( V_8 -> V_102 , V_48 -> V_50 , V_48 -> V_22 ) ;
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
V_98 = F_32 ( V_48 -> V_51 ) ;
} else if ( V_48 -> V_50 == V_109 ) {
if ( V_98 )
V_98 = ! F_32 ( V_48 -> V_51 ) ;
}
break;
case V_110 :
V_98 = F_24 ( V_54 -> V_60 , V_48 -> V_50 , V_48 -> V_51 ) ;
if ( V_48 -> V_50 == V_108 ) {
if ( ! V_98 )
V_98 = F_33 ( V_48 -> V_51 ) ;
} else if ( V_48 -> V_50 == V_109 ) {
if ( V_98 )
V_98 = ! F_33 ( V_48 -> V_51 ) ;
}
break;
case V_111 :
V_98 = F_24 ( V_54 -> V_66 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_112 :
V_98 = F_24 ( V_54 -> V_70 , V_48 -> V_50 , V_48 -> V_51 ) ;
break;
case V_113 :
V_98 = F_30 ( V_53 -> V_114 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_115 :
if ( V_8 )
V_98 = F_30 ( V_8 -> V_10 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_116 :
if ( V_8 && V_8 -> V_117 )
V_98 = F_30 ( V_8 -> V_118 , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_119 :
if ( V_8 && V_8 -> V_117 ) {
if ( V_48 -> V_22 )
V_98 = F_30 ( V_8 -> V_117 , V_48 -> V_50 , V_120 ) ;
else
V_98 = F_30 ( V_8 -> V_117 , V_48 -> V_50 , V_121 ) ;
}
break;
case V_122 :
if ( V_46 ) {
if ( F_30 ( F_34 ( V_46 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_30 ( F_34 ( V_46 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) )
++ V_98 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_30 ( F_34 ( V_3 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_30 ( F_34 ( V_3 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_125 :
if ( V_46 ) {
if ( F_30 ( F_35 ( V_46 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_30 ( F_35 ( V_46 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) )
++ V_98 ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_30 ( F_35 ( V_3 -> V_123 ) , V_48 -> V_50 , V_48 -> V_22 ) ||
F_30 ( F_35 ( V_3 -> V_124 ) , V_48 -> V_50 , V_48 -> V_22 ) ) {
++ V_98 ;
break;
}
}
}
break;
case V_126 :
if ( V_46 )
V_98 = F_30 ( V_46 -> V_25 , V_48 -> V_50 , V_48 -> V_22 ) ;
else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_30 ( V_3 -> V_25 , V_48 -> V_50 , V_48 -> V_22 ) ) {
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
V_98 = F_36 ( V_88 -> V_130 , V_46 -> V_25 , V_46 -> V_123 ) ;
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
V_98 = F_30 ( F_37 ( V_53 ) , V_48 -> V_50 , V_48 -> V_22 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
if ( V_48 -> V_139 ) {
if ( V_93 ) {
F_38 ( V_53 , & V_94 ) ;
V_93 = 0 ;
}
V_98 = F_39 ( V_94 , V_48 -> type ,
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
V_98 = F_39 (
V_46 -> V_145 , V_48 -> type , V_48 -> V_50 ,
V_48 -> V_139 , V_8 ) ;
} else if ( V_8 ) {
F_8 (n, &ctx->names_list, list) {
if ( F_39 ( V_3 -> V_145 , V_48 -> type ,
V_48 -> V_50 , V_48 -> V_139 ,
V_8 ) ) {
++ V_98 ;
break;
}
}
}
if ( ! V_8 || V_8 -> type != V_146 )
break;
if ( F_39 ( V_8 -> V_147 . V_145 ,
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
V_98 = F_30 ( V_8 -> V_19 [ V_48 -> type - V_148 ] , V_48 -> V_50 , V_48 -> V_22 ) ;
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
V_8 -> V_156 = F_40 ( V_88 -> V_156 , V_157 ) ;
}
V_8 -> V_27 = V_88 -> V_27 ;
}
switch ( V_88 -> V_158 ) {
case V_159 : * V_90 = V_160 ; break;
case V_161 : * V_90 = V_29 ; break;
}
return 1 ;
}
static enum V_89 F_41 ( struct V_52 * V_53 , char * * V_162 )
{
struct V_163 * V_164 ;
enum V_89 V_90 ;
F_42 () ;
F_43 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_27 ( V_53 , & V_164 -> V_88 , NULL , NULL ,
& V_90 , true ) ) {
if ( V_90 == V_29 )
* V_162 = F_40 ( V_164 -> V_88 . V_156 , V_157 ) ;
F_44 () ;
return V_90 ;
}
}
F_44 () ;
return V_165 ;
}
static int F_45 ( const struct V_87 * V_88 , unsigned long V_22 )
{
int V_166 , V_167 ;
if ( V_22 > 0xffffffff )
return false ;
V_166 = F_46 ( V_22 ) ;
if ( V_166 >= V_168 )
return false ;
V_167 = F_47 ( V_22 ) ;
return V_88 -> V_2 [ V_166 ] & V_167 ;
}
static enum V_89 F_48 ( struct V_52 * V_53 ,
struct V_7 * V_8 ,
struct V_169 * V_170 )
{
struct V_163 * V_164 ;
enum V_89 V_90 ;
if ( V_171 && V_53 -> V_172 == V_171 )
return V_160 ;
F_42 () ;
if ( ! F_49 ( V_170 ) ) {
F_43 (e, list, list) {
if ( F_45 ( & V_164 -> V_88 , V_8 -> V_9 ) &&
F_27 ( V_53 , & V_164 -> V_88 , V_8 , NULL ,
& V_90 , false ) ) {
F_44 () ;
V_8 -> V_28 = V_90 ;
return V_90 ;
}
}
}
F_44 () ;
return V_165 ;
}
static int F_50 ( struct V_52 * V_53 ,
struct V_23 * V_3 ,
struct V_7 * V_8 ) {
int V_173 = F_51 ( ( T_4 ) V_3 -> V_25 ) ;
struct V_169 * V_170 = & V_174 [ V_173 ] ;
struct V_163 * V_164 ;
enum V_89 V_90 ;
if ( F_49 ( V_170 ) )
return 0 ;
F_43 (e, list, list) {
if ( F_45 ( & V_164 -> V_88 , V_8 -> V_9 ) &&
F_27 ( V_53 , & V_164 -> V_88 , V_8 , V_3 , & V_90 , false ) ) {
V_8 -> V_28 = V_90 ;
return 1 ;
}
}
return 0 ;
}
void F_52 ( struct V_52 * V_53 , struct V_7 * V_8 )
{
struct V_23 * V_3 ;
if ( V_171 && V_53 -> V_172 == V_171 )
return;
F_42 () ;
F_8 (n, &ctx->names_list, list) {
if ( F_50 ( V_53 , V_3 , V_8 ) )
break;
}
F_44 () ;
}
static inline struct V_7 * F_53 ( struct V_52 * V_53 ,
int V_117 ,
long V_118 )
{
struct V_7 * V_175 = V_53 -> V_7 ;
if ( ! V_175 )
return NULL ;
V_175 -> V_117 = V_117 ;
if ( F_4 ( V_118 <= - V_176 ) &&
( V_118 >= - V_177 ) &&
( V_118 != - V_178 ) )
V_175 -> V_118 = - V_179 ;
else
V_175 -> V_118 = V_118 ;
if ( V_175 -> V_180 && ! V_175 -> V_181 ) {
F_48 ( V_53 , V_175 , & V_182 [ V_183 ] ) ;
F_52 ( V_53 , V_175 ) ;
}
V_53 -> V_7 = NULL ;
return V_175 ;
}
static inline void F_54 ( struct V_7 * V_175 )
{
F_18 ( V_175 -> V_184 . V_185 ) ;
V_175 -> V_184 . V_185 = NULL ;
V_175 -> V_184 . V_186 = 0 ;
}
static inline void F_55 ( struct V_7 * V_175 )
{
struct V_23 * V_3 , * V_38 ;
#if V_187 == 2
if ( V_175 -> V_188 + V_175 -> V_189 != V_175 -> V_190 ) {
int V_92 = 0 ;
F_56 ( L_2
L_3
L_4 , __FILE__ , __LINE__ ,
V_175 -> V_191 , V_175 -> V_9 , V_175 -> V_180 ,
V_175 -> V_190 , V_175 -> V_188 ,
V_175 -> V_189 ) ;
F_8 (n, &context->names_list, list) {
F_56 ( L_5 , V_92 ++ , V_3 -> V_46 ,
V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
F_57 () ;
return;
}
#endif
#if V_187
V_175 -> V_188 = 0 ;
V_175 -> V_189 = 0 ;
#endif
F_58 (n, next, &context->names_list, list) {
F_59 ( & V_3 -> V_170 ) ;
if ( V_3 -> V_46 && V_3 -> V_192 )
F_60 ( V_3 -> V_46 ) ;
if ( V_3 -> V_193 )
F_18 ( V_3 ) ;
}
V_175 -> V_190 = 0 ;
F_61 ( & V_175 -> V_194 ) ;
V_175 -> V_194 . V_195 = NULL ;
V_175 -> V_194 . V_196 = NULL ;
}
static inline void F_62 ( struct V_7 * V_175 )
{
struct V_197 * V_198 ;
while ( ( V_198 = V_175 -> V_198 ) ) {
V_175 -> V_198 = V_198 -> V_38 ;
F_18 ( V_198 ) ;
}
while ( ( V_198 = V_175 -> V_199 ) ) {
V_175 -> V_199 = V_198 -> V_38 ;
F_18 ( V_198 ) ;
}
}
static inline struct V_7 * F_63 ( enum V_89 V_90 )
{
struct V_7 * V_175 ;
V_175 = F_13 ( sizeof( * V_175 ) , V_39 ) ;
if ( ! V_175 )
return NULL ;
V_175 -> V_90 = V_90 ;
V_175 -> V_27 = V_90 == V_29 ? ~ 0ULL : 0 ;
F_64 ( & V_175 -> V_200 ) ;
F_64 ( & V_175 -> V_201 ) ;
return V_175 ;
}
int F_65 ( struct V_52 * V_53 )
{
struct V_7 * V_175 ;
enum V_89 V_90 ;
char * V_162 = NULL ;
if ( F_11 ( ! V_202 ) )
return 0 ;
V_90 = F_41 ( V_53 , & V_162 ) ;
if ( V_90 == V_160 ) {
F_66 ( V_53 , V_203 ) ;
return 0 ;
}
if ( ! ( V_175 = F_63 ( V_90 ) ) ) {
F_18 ( V_162 ) ;
F_67 ( L_7 ) ;
return - V_204 ;
}
V_175 -> V_156 = V_162 ;
V_53 -> V_7 = V_175 ;
F_68 ( V_53 , V_203 ) ;
return 0 ;
}
static inline void F_69 ( struct V_7 * V_175 )
{
F_55 ( V_175 ) ;
F_14 ( V_175 , NULL , 0 ) ;
F_17 ( V_175 ) ;
F_62 ( V_175 ) ;
F_18 ( V_175 -> V_156 ) ;
F_18 ( V_175 -> V_205 ) ;
F_54 ( V_175 ) ;
F_18 ( V_175 ) ;
}
static int F_70 ( struct V_7 * V_175 , T_5 V_99 ,
T_2 V_206 , T_2 V_45 , unsigned int V_207 ,
T_4 V_94 , char * V_208 )
{
struct V_209 * V_210 ;
char * V_8 = NULL ;
T_4 V_186 ;
int V_49 = 0 ;
V_210 = F_71 ( V_175 , V_39 , V_211 ) ;
if ( ! V_210 )
return V_49 ;
F_72 ( V_210 , L_8 , V_99 ,
F_73 ( & V_212 , V_206 ) ,
F_73 ( & V_212 , V_45 ) , V_207 ) ;
if ( V_94 ) {
if ( F_74 ( V_94 , & V_8 , & V_186 ) ) {
F_72 ( V_210 , L_9 ) ;
V_49 = 1 ;
} else {
F_72 ( V_210 , L_10 , V_8 ) ;
F_75 ( V_8 , V_186 ) ;
}
}
F_72 ( V_210 , L_11 ) ;
F_76 ( V_210 , V_208 ) ;
F_77 ( V_210 ) ;
return V_49 ;
}
static int F_78 ( struct V_7 * V_175 ,
struct V_209 * * V_210 ,
int V_213 ,
T_6 * V_214 ,
const char T_7 * V_33 ,
char * V_215 )
{
char V_216 [ 12 ] ;
const char T_7 * V_217 = V_33 ;
T_6 V_218 = snprintf ( V_216 , 12 , L_12 , V_213 ) + 5 ;
T_6 V_186 , V_219 , V_220 ;
T_6 V_221 = V_222 ;
unsigned int V_92 , V_223 = 0 , V_224 = 0 ;
int V_225 ;
V_219 = V_186 = F_79 ( V_33 , V_226 ) - 1 ;
if ( F_4 ( ( V_186 == - 1 ) || V_186 > V_226 - 1 ) ) {
F_80 ( 1 ) ;
F_81 ( V_227 , V_95 , 0 ) ;
return - 1 ;
}
do {
if ( V_219 > V_222 )
V_220 = V_222 ;
else
V_220 = V_219 ;
V_225 = F_82 ( V_215 , V_217 , V_220 ) ;
if ( V_225 ) {
F_80 ( 1 ) ;
F_81 ( V_227 , V_95 , 0 ) ;
return - 1 ;
}
V_215 [ V_220 ] = '\0' ;
V_223 = F_83 ( V_215 , V_220 ) ;
if ( V_223 ) {
V_221 = V_222 / 2 ;
break;
}
V_219 -= V_220 ;
V_217 += V_220 ;
} while ( V_219 > 0 );
V_219 = V_186 ;
if ( V_186 > V_221 )
V_224 = 1 ;
for ( V_92 = 0 ; V_219 > 0 ; V_92 ++ ) {
int V_228 ;
if ( V_219 > V_221 )
V_220 = V_221 ;
else
V_220 = V_219 ;
V_228 = V_222 - V_218 - * V_214 ;
if ( V_223 )
V_228 -= ( V_220 * 2 ) ;
else
V_228 -= V_220 ;
if ( V_228 < 0 ) {
* V_214 = 0 ;
F_77 ( * V_210 ) ;
* V_210 = F_71 ( V_175 , V_39 , V_229 ) ;
if ( ! * V_210 )
return 0 ;
}
if ( ( V_92 == 0 ) && ( V_224 ) )
F_72 ( * V_210 , L_13 , V_213 ,
V_223 ? 2 * V_186 : V_186 ) ;
if ( V_186 >= V_221 )
V_225 = F_82 ( V_215 , V_33 , V_220 ) ;
else
V_225 = 0 ;
if ( V_225 ) {
F_80 ( 1 ) ;
F_81 ( V_227 , V_95 , 0 ) ;
return - 1 ;
}
V_215 [ V_220 ] = '\0' ;
F_72 ( * V_210 , L_14 , V_213 ) ;
if ( V_224 )
F_72 ( * V_210 , L_15 , V_92 ) ;
F_72 ( * V_210 , L_16 ) ;
if ( V_223 )
F_84 ( * V_210 , V_215 , V_220 ) ;
else
F_85 ( * V_210 , V_215 ) ;
V_33 += V_220 ;
V_219 -= V_220 ;
* V_214 += V_218 ;
if ( V_223 )
* V_214 += V_220 * 2 ;
else
* V_214 += V_220 ;
}
return V_186 + 1 ;
}
static void F_86 ( struct V_7 * V_175 ,
struct V_209 * * V_210 )
{
int V_92 , V_186 ;
T_6 V_214 = 0 ;
const char T_7 * V_33 ;
char * V_215 ;
V_33 = ( const char T_7 * ) V_95 -> V_230 -> V_231 ;
F_72 ( * V_210 , L_17 , V_175 -> V_232 . V_233 ) ;
V_215 = F_87 ( V_222 + 1 , V_39 ) ;
if ( ! V_215 ) {
F_88 ( L_18 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_175 -> V_232 . V_233 ; V_92 ++ ) {
V_186 = F_78 ( V_175 , V_210 , V_92 ,
& V_214 , V_33 , V_215 ) ;
if ( V_186 <= 0 )
break;
V_33 += V_186 ;
}
F_18 ( V_215 ) ;
}
static void F_89 ( struct V_7 * V_175 , int * V_234 )
{
struct V_209 * V_210 ;
int V_92 ;
V_210 = F_71 ( V_175 , V_39 , V_175 -> type ) ;
if ( ! V_210 )
return;
switch ( V_175 -> type ) {
case V_235 : {
int V_236 = V_175 -> V_237 . V_236 ;
F_72 ( V_210 , L_19 , V_236 ) ;
for ( V_92 = 0 ; V_92 < V_236 ; V_92 ++ )
F_72 ( V_210 , L_20 , V_92 ,
V_175 -> V_237 . args [ V_92 ] ) ;
break; }
case V_146 : {
T_4 V_145 = V_175 -> V_147 . V_145 ;
F_72 ( V_210 , L_21 ,
F_73 ( & V_212 , V_175 -> V_147 . V_45 ) ,
F_90 ( & V_212 , V_175 -> V_147 . V_51 ) ,
V_175 -> V_147 . V_24 ) ;
if ( V_145 ) {
char * V_8 = NULL ;
T_4 V_186 ;
if ( F_74 ( V_145 , & V_8 , & V_186 ) ) {
F_72 ( V_210 , L_22 , V_145 ) ;
* V_234 = 1 ;
} else {
F_72 ( V_210 , L_10 , V_8 ) ;
F_75 ( V_8 , V_186 ) ;
}
}
if ( V_175 -> V_147 . V_238 ) {
F_77 ( V_210 ) ;
V_210 = F_71 ( V_175 , V_39 ,
V_239 ) ;
if ( F_4 ( ! V_210 ) )
return;
F_72 ( V_210 ,
L_23 ,
V_175 -> V_147 . V_240 ,
V_175 -> V_147 . V_241 ,
V_175 -> V_147 . V_242 ,
V_175 -> V_147 . V_243 ) ;
}
break; }
case V_244 : {
F_72 ( V_210 ,
L_24
L_25 ,
V_175 -> V_245 . V_246 , V_175 -> V_245 . V_24 ,
V_175 -> V_245 . V_247 . V_248 ,
V_175 -> V_245 . V_247 . V_249 ,
V_175 -> V_245 . V_247 . V_250 ,
V_175 -> V_245 . V_247 . V_251 ) ;
break; }
case V_252 : {
F_72 ( V_210 ,
L_26
L_27 ,
V_175 -> V_253 . V_254 ,
V_175 -> V_253 . V_255 ,
V_175 -> V_253 . V_256 ,
V_175 -> V_253 . V_257 . V_258 ,
V_175 -> V_253 . V_257 . V_259 ) ;
break; }
case V_260 : {
F_72 ( V_210 , L_28 ,
V_175 -> V_261 . V_254 ,
V_175 -> V_261 . V_262 ) ;
break; }
case V_263 : {
struct V_264 * V_247 = & V_175 -> V_265 . V_266 ;
F_72 ( V_210 ,
L_29
L_30 ,
V_175 -> V_265 . V_254 ,
V_247 -> V_248 , V_247 -> V_249 ,
V_247 -> V_250 , V_247 -> V_251 ) ;
break; }
case V_267 : {
F_72 ( V_210 , L_31 , V_175 -> V_268 . V_99 ) ;
F_91 ( V_210 , L_32 , & V_175 -> V_268 . V_269 . V_270 ) ;
F_91 ( V_210 , L_33 , & V_175 -> V_268 . V_269 . V_271 ) ;
F_91 ( V_210 , L_34 , & V_175 -> V_268 . V_269 . V_272 ) ;
break; }
case V_273 : {
F_72 ( V_210 , L_35 , V_175 -> V_274 . V_275 ,
V_175 -> V_274 . V_1 ) ;
break; }
case V_229 : {
F_86 ( V_175 , & V_210 ) ;
break; }
}
F_77 ( V_210 ) ;
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
static void F_93 ( struct V_52 * V_53 ,
struct V_7 * V_175 )
{
int V_277 ;
char * V_215 ;
char * V_278 = L_6 ;
int V_186 = strlen ( V_278 ) ;
struct V_209 * V_210 ;
V_210 = F_71 ( V_175 , V_39 , V_279 ) ;
if ( ! V_210 )
return;
F_72 ( V_210 , L_36 ) ;
if ( ! V_175 -> V_184 . V_185 ) {
V_215 = F_87 ( V_280 , V_39 ) ;
if ( ! V_215 )
goto V_281;
V_277 = F_94 ( V_53 , V_215 , V_280 ) ;
if ( V_277 == 0 ) {
F_18 ( V_215 ) ;
goto V_281;
}
V_277 = F_92 ( V_215 , V_277 ) ;
if ( V_277 == 0 ) {
F_18 ( V_215 ) ;
goto V_281;
}
V_175 -> V_184 . V_185 = V_215 ;
V_175 -> V_184 . V_186 = V_277 ;
}
V_278 = V_175 -> V_184 . V_185 ;
V_186 = V_175 -> V_184 . V_186 ;
V_281:
F_95 ( V_210 , V_278 , V_186 ) ;
F_77 ( V_210 ) ;
}
static void F_96 ( struct V_7 * V_175 , struct V_52 * V_53 )
{
int V_92 , V_234 = 0 ;
struct V_209 * V_210 ;
struct V_197 * V_198 ;
struct V_23 * V_3 ;
V_175 -> V_114 = V_53 -> V_114 ;
V_210 = F_71 ( V_175 , V_39 , V_282 ) ;
if ( ! V_210 )
return;
F_72 ( V_210 , L_37 ,
V_175 -> V_10 , V_175 -> V_9 ) ;
if ( V_175 -> V_114 != V_283 )
F_72 ( V_210 , L_38 , V_175 -> V_114 ) ;
if ( V_175 -> V_117 )
F_72 ( V_210 , L_39 ,
( V_175 -> V_117 == V_120 ) ? L_40 : L_41 ,
V_175 -> V_118 ) ;
F_72 ( V_210 ,
L_42 ,
V_175 -> V_19 [ 0 ] ,
V_175 -> V_19 [ 1 ] ,
V_175 -> V_19 [ 2 ] ,
V_175 -> V_19 [ 3 ] ,
V_175 -> V_190 ) ;
F_97 ( V_210 , V_53 ) ;
F_98 ( V_210 , V_175 -> V_156 ) ;
F_77 ( V_210 ) ;
for ( V_198 = V_175 -> V_198 ; V_198 ; V_198 = V_198 -> V_38 ) {
V_210 = F_71 ( V_175 , V_39 , V_198 -> type ) ;
if ( ! V_210 )
continue;
switch ( V_198 -> type ) {
case V_284 : {
struct V_285 * V_286 = ( void * ) V_198 ;
F_72 ( V_210 , L_43 , V_286 -> V_287 ) ;
F_91 ( V_210 , L_44 , & V_286 -> V_288 . V_271 ) ;
F_91 ( V_210 , L_45 , & V_286 -> V_288 . V_270 ) ;
F_72 ( V_210 , L_46 , V_286 -> V_288 . V_289 ) ;
F_91 ( V_210 , L_47 , & V_286 -> V_290 . V_271 ) ;
F_91 ( V_210 , L_48 , & V_286 -> V_290 . V_270 ) ;
F_91 ( V_210 , L_49 , & V_286 -> V_290 . V_272 ) ;
F_91 ( V_210 , L_50 , & V_286 -> V_291 . V_271 ) ;
F_91 ( V_210 , L_51 , & V_286 -> V_291 . V_270 ) ;
F_91 ( V_210 , L_52 , & V_286 -> V_291 . V_272 ) ;
break; }
}
F_77 ( V_210 ) ;
}
if ( V_175 -> type )
F_89 ( V_175 , & V_234 ) ;
if ( V_175 -> V_292 [ 0 ] >= 0 ) {
V_210 = F_71 ( V_175 , V_39 , V_293 ) ;
if ( V_210 ) {
F_72 ( V_210 , L_53 ,
V_175 -> V_292 [ 0 ] , V_175 -> V_292 [ 1 ] ) ;
F_77 ( V_210 ) ;
}
}
if ( V_175 -> V_294 ) {
V_210 = F_71 ( V_175 , V_39 , V_295 ) ;
if ( V_210 ) {
F_72 ( V_210 , L_54 ) ;
F_84 ( V_210 , ( void * ) V_175 -> V_205 ,
V_175 -> V_294 ) ;
F_77 ( V_210 ) ;
}
}
for ( V_198 = V_175 -> V_199 ; V_198 ; V_198 = V_198 -> V_38 ) {
struct V_296 * V_286 = ( void * ) V_198 ;
for ( V_92 = 0 ; V_92 < V_286 -> V_297 ; V_92 ++ )
if ( F_70 ( V_175 , V_286 -> V_298 [ V_92 ] ,
V_286 -> V_299 [ V_92 ] ,
V_286 -> V_300 [ V_92 ] ,
V_286 -> V_301 [ V_92 ] ,
V_286 -> V_302 [ V_92 ] ,
V_286 -> V_303 [ V_92 ] ) )
V_234 = 1 ;
}
if ( V_175 -> V_298 &&
F_70 ( V_175 , V_175 -> V_298 ,
V_175 -> V_299 , V_175 -> V_300 ,
V_175 -> V_301 ,
V_175 -> V_302 , V_175 -> V_303 ) )
V_234 = 1 ;
if ( V_175 -> V_194 . V_195 && V_175 -> V_194 . V_196 ) {
V_210 = F_71 ( V_175 , V_39 , V_304 ) ;
if ( V_210 ) {
F_99 ( V_210 , L_55 , & V_175 -> V_194 ) ;
F_77 ( V_210 ) ;
}
}
V_92 = 0 ;
F_8 (n, &context->names_list, list) {
if ( V_3 -> V_305 )
continue;
F_100 ( V_175 , V_3 , NULL , V_92 ++ , & V_234 ) ;
}
F_93 ( V_53 , V_175 ) ;
V_210 = F_71 ( V_175 , V_39 , V_306 ) ;
if ( V_210 )
F_77 ( V_210 ) ;
if ( V_234 )
F_88 ( L_56 ) ;
}
void F_101 ( struct V_52 * V_53 )
{
struct V_7 * V_175 ;
V_175 = F_53 ( V_53 , 0 , 0 ) ;
if ( ! V_175 )
return;
if ( V_175 -> V_180 && V_175 -> V_28 == V_29 )
F_96 ( V_175 , V_53 ) ;
if ( ! F_49 ( & V_175 -> V_200 ) )
F_102 ( & V_175 -> V_200 ) ;
F_69 ( V_175 ) ;
}
void F_103 ( int V_10 , int V_9 ,
unsigned long V_307 , unsigned long V_308 ,
unsigned long V_309 , unsigned long V_310 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_175 = V_53 -> V_7 ;
enum V_89 V_90 ;
if ( ! V_175 )
return;
F_104 ( V_175 -> V_180 || V_175 -> V_190 ) ;
if ( ! V_311 )
return;
V_175 -> V_10 = V_10 ;
V_175 -> V_9 = V_9 ;
V_175 -> V_19 [ 0 ] = V_307 ;
V_175 -> V_19 [ 1 ] = V_308 ;
V_175 -> V_19 [ 2 ] = V_309 ;
V_175 -> V_19 [ 3 ] = V_310 ;
V_90 = V_175 -> V_90 ;
V_175 -> V_181 = ! V_312 ;
if ( ! V_175 -> V_181 && V_90 == V_165 ) {
V_175 -> V_27 = 0 ;
V_90 = F_48 ( V_53 , V_175 , & V_182 [ V_313 ] ) ;
}
if ( V_90 == V_160 )
return;
V_175 -> V_191 = 0 ;
V_175 -> ctime = V_314 ;
V_175 -> V_180 = 1 ;
V_175 -> V_28 = V_90 ;
V_175 -> V_102 = 0 ;
}
void F_105 ( int V_315 , long V_118 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_175 ;
if ( V_315 )
V_315 = V_120 ;
else
V_315 = V_121 ;
V_175 = F_53 ( V_53 , V_315 , V_118 ) ;
if ( ! V_175 )
return;
if ( V_175 -> V_180 && V_175 -> V_28 == V_29 )
F_96 ( V_175 , V_53 ) ;
V_175 -> V_180 = 0 ;
V_175 -> V_27 = V_175 -> V_90 == V_29 ? ~ 0ULL : 0 ;
if ( ! F_49 ( & V_175 -> V_200 ) )
F_102 ( & V_175 -> V_200 ) ;
F_55 ( V_175 ) ;
F_14 ( V_175 , NULL , 0 ) ;
F_62 ( V_175 ) ;
V_175 -> V_198 = NULL ;
V_175 -> V_199 = NULL ;
V_175 -> V_298 = 0 ;
V_175 -> V_302 = 0 ;
V_175 -> V_294 = 0 ;
V_175 -> type = 0 ;
V_175 -> V_292 [ 0 ] = - 1 ;
if ( V_175 -> V_90 != V_29 ) {
F_18 ( V_175 -> V_156 ) ;
V_175 -> V_156 = NULL ;
}
V_53 -> V_7 = V_175 ;
}
static inline void F_106 ( const struct V_316 * V_316 )
{
#ifdef F_15
struct V_7 * V_175 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
int V_41 ;
if ( F_11 ( F_107 ( & V_316 -> V_317 ) ) )
return;
V_175 = V_95 -> V_7 ;
V_33 = V_175 -> V_34 ;
V_41 = V_175 -> V_36 ;
F_42 () ;
V_31 = F_108 ( V_316 ) ;
F_44 () ;
if ( ! V_31 )
return;
if ( F_11 ( F_10 ( V_175 , V_31 ) ) )
return;
if ( F_4 ( ! F_12 ( V_175 ) ) ) {
F_109 ( L_57 ) ;
F_9 ( V_175 ) ;
F_16 ( V_31 ) ;
F_14 ( V_175 , V_33 , V_41 ) ;
return;
}
F_10 ( V_175 , V_31 ) ;
#endif
}
static void F_110 ( const struct V_195 * V_195 )
{
#ifdef F_15
struct V_7 * V_175 ;
struct V_32 * V_33 ;
const struct V_195 * V_318 , * V_319 ;
struct V_30 * V_320 ;
unsigned long V_321 ;
int V_41 ;
V_175 = V_95 -> V_7 ;
V_33 = V_175 -> V_34 ;
V_41 = V_175 -> V_36 ;
V_322:
V_320 = NULL ;
V_318 = V_195 ;
F_42 () ;
V_321 = F_111 ( & V_323 ) ;
for(; ; ) {
struct V_316 * V_316 = V_318 -> V_324 ;
if ( V_316 && F_4 ( ! F_107 ( & V_316 -> V_317 ) ) ) {
struct V_30 * V_31 ;
V_31 = F_108 ( V_316 ) ;
if ( V_31 ) {
if ( F_4 ( ! F_10 ( V_175 , V_31 ) ) ) {
V_320 = V_31 ;
break;
}
}
}
V_319 = V_318 -> V_325 ;
if ( V_319 == V_318 )
break;
V_318 = V_319 ;
}
if ( F_4 ( F_112 ( & V_323 , V_321 ) || V_320 ) ) {
F_44 () ;
if ( ! V_320 ) {
F_14 ( V_175 , V_33 , V_41 ) ;
goto V_322;
}
F_16 ( V_320 ) ;
if ( F_12 ( V_175 ) ) {
F_14 ( V_175 , V_33 , V_41 ) ;
goto V_322;
}
F_109 ( L_57 ) ;
F_14 ( V_175 , V_33 , V_41 ) ;
F_9 ( V_175 ) ;
return;
}
F_44 () ;
#endif
}
static struct V_23 * F_113 ( struct V_7 * V_175 ,
unsigned char type )
{
struct V_23 * V_326 ;
if ( V_175 -> V_190 < V_327 ) {
V_326 = & V_175 -> V_328 [ V_175 -> V_190 ] ;
memset ( V_326 , 0 , sizeof( * V_326 ) ) ;
} else {
V_326 = F_13 ( sizeof( * V_326 ) , V_329 ) ;
if ( ! V_326 )
return NULL ;
V_326 -> V_193 = true ;
}
V_326 -> V_25 = ( unsigned long ) - 1 ;
V_326 -> type = type ;
F_114 ( & V_326 -> V_170 , & V_175 -> V_201 ) ;
V_175 -> V_190 ++ ;
#if V_187
V_175 -> V_189 ++ ;
#endif
return V_326 ;
}
struct V_330 *
F_115 ( const T_7 char * V_331 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
struct V_23 * V_3 ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( V_3 -> V_46 -> V_331 == V_331 )
return V_3 -> V_46 ;
}
return NULL ;
}
void F_116 ( struct V_330 * V_46 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
struct V_23 * V_3 ;
if ( ! V_175 -> V_180 ) {
#if V_187 == 2
F_56 ( L_58 ,
__FILE__ , __LINE__ , V_175 -> V_191 , V_46 ) ;
F_57 () ;
#endif
return;
}
#if V_187
F_104 ( ! V_46 -> V_46 ) ;
#endif
V_3 = F_113 ( V_175 , V_332 ) ;
if ( ! V_3 )
return;
V_3 -> V_46 = V_46 ;
V_3 -> V_333 = V_334 ;
V_3 -> V_192 = true ;
V_46 -> V_326 = V_3 ;
if ( ! V_175 -> V_194 . V_195 )
F_117 ( V_95 -> V_335 , & V_175 -> V_194 ) ;
}
void F_118 ( struct V_330 * V_46 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
F_104 ( ! V_175 ) ;
if ( ! V_46 -> V_326 || ! V_175 -> V_180 ) {
#if V_187 == 2
F_56 ( L_59 ,
__FILE__ , __LINE__ , V_175 -> V_191 , V_46 ) ;
if ( V_175 -> V_190 ) {
struct V_23 * V_3 ;
int V_92 = 0 ;
F_8 (n, &context->names_list, list)
F_56 ( L_60 , V_92 ++ , V_3 -> V_46 ,
V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
#endif
F_60 ( V_46 ) ;
}
#if V_187
else {
++ V_175 -> V_188 ;
if ( V_175 -> V_188 > V_175 -> V_190 ) {
F_56 ( L_61
L_62 ,
__FILE__ , __LINE__ ,
V_175 -> V_191 , V_175 -> V_9 ,
V_175 -> V_180 , V_46 -> V_46 ,
V_175 -> V_190 , V_175 -> V_188 ) ;
F_57 () ;
}
}
#endif
}
void F_119 ( struct V_330 * V_46 , const struct V_195 * V_195 ,
unsigned int V_1 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
const struct V_316 * V_316 = V_195 -> V_324 ;
struct V_23 * V_3 ;
bool V_319 = V_1 & V_336 ;
if ( ! V_175 -> V_180 )
return;
if ( ! V_46 )
goto V_337;
#if V_187
F_104 ( ! V_46 -> V_46 ) ;
#endif
V_3 = V_46 -> V_326 ;
if ( V_3 ) {
if ( V_319 ) {
if ( V_3 -> type == V_338 ||
V_3 -> type == V_332 )
goto V_281;
} else {
if ( V_3 -> type != V_338 )
goto V_281;
}
}
F_120 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> V_46 -> V_46 != V_46 -> V_46 )
continue;
if ( V_319 ) {
if ( V_3 -> type == V_338 ||
V_3 -> type == V_332 )
goto V_281;
} else {
if ( V_3 -> type != V_338 )
goto V_281;
}
}
V_337:
V_3 = F_113 ( V_175 , V_339 ) ;
if ( ! V_3 )
return;
V_281:
if ( V_319 ) {
V_3 -> V_333 = V_3 -> V_46 ? F_121 ( V_3 -> V_46 -> V_46 ) : V_334 ;
V_3 -> type = V_338 ;
if ( V_1 & V_340 )
V_3 -> V_305 = true ;
} else {
V_3 -> V_333 = V_334 ;
V_3 -> type = V_339 ;
}
F_110 ( V_195 ) ;
F_122 ( V_3 , V_195 , V_316 ) ;
}
void F_123 ( const struct V_316 * V_319 ,
const struct V_195 * V_195 ,
const unsigned char type )
{
struct V_7 * V_175 = V_95 -> V_7 ;
const struct V_316 * V_316 = V_195 -> V_324 ;
const char * V_341 = V_195 -> V_342 . V_46 ;
struct V_23 * V_3 , * V_343 = NULL , * V_344 = NULL ;
if ( ! V_175 -> V_180 )
return;
if ( V_316 )
F_106 ( V_316 ) ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != V_338 )
continue;
if ( V_3 -> V_25 == V_319 -> V_345 &&
! F_124 ( V_341 , V_3 -> V_46 -> V_46 , V_3 -> V_333 ) ) {
V_343 = V_3 ;
break;
}
}
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != type )
continue;
if ( V_343 && ( V_3 -> V_46 != V_343 -> V_46 ) )
continue;
if ( ! strcmp ( V_341 , V_3 -> V_46 -> V_46 ) ||
! F_124 ( V_341 , V_3 -> V_46 -> V_46 ,
V_343 ?
V_343 -> V_333 :
V_334 ) ) {
V_344 = V_3 ;
break;
}
}
if ( ! V_343 ) {
V_3 = F_113 ( V_175 , V_338 ) ;
if ( ! V_3 )
return;
F_122 ( V_3 , NULL , V_319 ) ;
}
if ( ! V_344 ) {
V_344 = F_113 ( V_175 , type ) ;
if ( ! V_344 )
return;
if ( V_343 ) {
V_344 -> V_46 = V_343 -> V_46 ;
V_344 -> V_333 = V_334 ;
V_344 -> V_192 = false ;
}
}
if ( V_316 )
F_122 ( V_344 , V_195 , V_316 ) ;
else
V_344 -> V_25 = ( unsigned long ) - 1 ;
}
int F_125 ( struct V_7 * V_8 ,
struct V_346 * V_347 , unsigned int * V_191 )
{
if ( ! V_8 -> V_180 )
return 0 ;
if ( ! V_8 -> V_191 )
V_8 -> V_191 = F_126 () ;
V_347 -> V_258 = V_8 -> ctime . V_258 ;
V_347 -> V_259 = V_8 -> ctime . V_259 ;
* V_191 = V_8 -> V_191 ;
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
return 1 ;
}
static int F_127 ( T_2 V_62 )
{
if ( ! F_37 ( V_95 ) )
return 0 ;
if ( F_128 ( V_348 ) )
return - V_349 ;
if ( ! F_129 ( V_350 ) )
return - V_349 ;
if ( F_128 ( V_351 ) && F_130 ( V_62 ) )
return - V_349 ;
return 0 ;
}
static void F_131 ( T_2 V_352 , T_2 V_353 ,
unsigned int V_354 , unsigned int V_207 ,
int V_49 )
{
struct V_209 * V_210 ;
T_8 V_45 , V_355 , V_62 ;
if ( ! V_311 )
return;
V_45 = F_73 ( & V_212 , F_132 ( V_95 ) ) ;
V_355 = F_73 ( & V_212 , V_352 ) ;
V_62 = F_73 ( & V_212 , V_353 ) ,
V_210 = F_71 ( NULL , V_39 , V_356 ) ;
if ( ! V_210 )
return;
F_72 ( V_210 , L_63 , F_29 ( V_95 ) , V_45 ) ;
F_133 ( V_210 ) ;
F_72 ( V_210 , L_64 ,
V_355 , V_62 , V_354 , V_207 , ! V_49 ) ;
F_77 ( V_210 ) ;
}
int F_134 ( T_2 V_62 )
{
struct V_52 * V_357 = V_95 ;
unsigned int V_354 , V_207 = ( unsigned int ) - 1 ;
T_2 V_355 ;
int V_49 ;
V_355 = F_135 ( V_95 ) ;
V_354 = F_136 ( V_95 ) ;
V_49 = F_127 ( V_62 ) ;
if ( V_49 )
goto V_281;
if ( F_130 ( V_62 ) )
V_207 = ( unsigned int ) F_137 ( & V_358 ) ;
V_357 -> V_207 = V_207 ;
V_357 -> V_62 = V_62 ;
V_281:
F_131 ( V_355 , V_62 , V_354 , V_207 , V_49 ) ;
return V_49 ;
}
void F_138 ( int V_246 , T_1 V_24 , struct V_264 * V_247 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
if ( V_247 )
memcpy ( & V_175 -> V_245 . V_247 , V_247 , sizeof( struct V_264 ) ) ;
else
memset ( & V_175 -> V_245 . V_247 , 0 , sizeof( struct V_264 ) ) ;
V_175 -> V_245 . V_246 = V_246 ;
V_175 -> V_245 . V_24 = V_24 ;
V_175 -> type = V_244 ;
}
void F_139 ( T_9 V_254 , T_6 V_255 , unsigned int V_256 ,
const struct V_346 * V_257 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
struct V_346 * V_33 = & V_175 -> V_253 . V_257 ;
if ( V_257 )
memcpy ( V_33 , V_257 , sizeof( struct V_346 ) ) ;
else
memset ( V_33 , 0 , sizeof( struct V_346 ) ) ;
V_175 -> V_253 . V_254 = V_254 ;
V_175 -> V_253 . V_255 = V_255 ;
V_175 -> V_253 . V_256 = V_256 ;
V_175 -> type = V_252 ;
}
void F_140 ( T_9 V_254 , const struct V_359 * V_360 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
if ( V_360 )
V_175 -> V_261 . V_262 = V_360 -> V_262 ;
else
V_175 -> V_261 . V_262 = 0 ;
V_175 -> V_261 . V_254 = V_254 ;
V_175 -> type = V_260 ;
}
void F_141 ( T_9 V_254 , struct V_264 * V_266 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_265 . V_254 = V_254 ;
V_175 -> V_265 . V_266 = * V_266 ;
V_175 -> type = V_263 ;
}
void F_142 ( struct V_361 * V_362 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_147 . V_45 = V_362 -> V_45 ;
V_175 -> V_147 . V_51 = V_362 -> V_51 ;
V_175 -> V_147 . V_24 = V_362 -> V_24 ;
V_175 -> V_147 . V_238 = 0 ;
F_143 ( V_362 , & V_175 -> V_147 . V_145 ) ;
V_175 -> type = V_146 ;
}
void F_144 ( unsigned long V_240 , T_8 V_45 , T_10 V_51 , T_1 V_24 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_147 . V_240 = V_240 ;
V_175 -> V_147 . V_241 = V_45 ;
V_175 -> V_147 . V_242 = V_51 ;
V_175 -> V_147 . V_243 = V_24 ;
V_175 -> V_147 . V_238 = 1 ;
}
void F_145 ( struct V_363 * V_364 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> type = V_229 ;
V_175 -> V_232 . V_233 = V_364 -> V_233 ;
}
int F_146 ( int V_236 , unsigned long * args )
{
struct V_7 * V_175 = V_95 -> V_7 ;
if ( V_236 <= 0 || V_236 > V_365 || ! args )
return - V_366 ;
V_175 -> type = V_235 ;
V_175 -> V_237 . V_236 = V_236 ;
memcpy ( V_175 -> V_237 . args , args , V_236 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_147 ( int V_367 , int V_368 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_292 [ 0 ] = V_367 ;
V_175 -> V_292 [ 1 ] = V_368 ;
}
int F_148 ( int V_186 , void * V_369 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
if ( ! V_175 -> V_205 ) {
void * V_33 = F_87 ( sizeof( struct V_370 ) , V_39 ) ;
if ( ! V_33 )
return - V_204 ;
V_175 -> V_205 = V_33 ;
}
V_175 -> V_294 = V_186 ;
memcpy ( V_175 -> V_205 , V_369 , V_186 ) ;
return 0 ;
}
void F_149 ( struct V_52 * V_347 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_298 = F_29 ( V_347 ) ;
V_175 -> V_299 = F_135 ( V_347 ) ;
V_175 -> V_300 = F_132 ( V_347 ) ;
V_175 -> V_301 = F_136 ( V_347 ) ;
F_38 ( V_347 , & V_175 -> V_302 ) ;
memcpy ( V_175 -> V_303 , V_347 -> V_208 , V_371 ) ;
}
int F_150 ( int V_372 , struct V_52 * V_347 )
{
struct V_296 * V_373 ;
struct V_52 * V_53 = V_95 ;
struct V_7 * V_8 = V_53 -> V_7 ;
T_2 V_45 = F_151 () , V_374 = F_132 ( V_347 ) ;
if ( V_171 && V_347 -> V_172 == V_171 ) {
if ( V_372 == V_375 || V_372 == V_376 || V_372 == V_377 || V_372 == V_378 ) {
V_379 = F_29 ( V_53 ) ;
if ( F_130 ( V_53 -> V_62 ) )
V_380 = V_53 -> V_62 ;
else
V_380 = V_45 ;
F_38 ( V_53 , & V_381 ) ;
}
if ( ! V_382 || F_152 () )
return 0 ;
}
if ( ! V_8 -> V_298 ) {
V_8 -> V_298 = F_153 ( V_347 ) ;
V_8 -> V_299 = F_135 ( V_347 ) ;
V_8 -> V_300 = V_374 ;
V_8 -> V_301 = F_136 ( V_347 ) ;
F_38 ( V_347 , & V_8 -> V_302 ) ;
memcpy ( V_8 -> V_303 , V_347 -> V_208 , V_371 ) ;
return 0 ;
}
V_373 = ( void * ) V_8 -> V_199 ;
if ( ! V_373 || V_373 -> V_297 == V_383 ) {
V_373 = F_13 ( sizeof( * V_373 ) , V_157 ) ;
if ( ! V_373 )
return - V_204 ;
V_373 -> V_318 . type = V_211 ;
V_373 -> V_318 . V_38 = V_8 -> V_199 ;
V_8 -> V_199 = ( void * ) V_373 ;
}
F_104 ( V_373 -> V_297 >= V_383 ) ;
V_373 -> V_298 [ V_373 -> V_297 ] = F_153 ( V_347 ) ;
V_373 -> V_299 [ V_373 -> V_297 ] = F_135 ( V_347 ) ;
V_373 -> V_300 [ V_373 -> V_297 ] = V_374 ;
V_373 -> V_301 [ V_373 -> V_297 ] = F_136 ( V_347 ) ;
F_38 ( V_347 , & V_373 -> V_302 [ V_373 -> V_297 ] ) ;
memcpy ( V_373 -> V_303 [ V_373 -> V_297 ] , V_347 -> V_208 , V_371 ) ;
V_373 -> V_297 ++ ;
return 0 ;
}
int F_154 ( struct V_363 * V_364 ,
const struct V_54 * V_384 , const struct V_54 * V_385 )
{
struct V_285 * V_386 ;
struct V_7 * V_175 = V_95 -> V_7 ;
struct V_387 V_388 ;
struct V_195 * V_195 ;
V_386 = F_87 ( sizeof( * V_386 ) , V_39 ) ;
if ( ! V_386 )
return - V_204 ;
V_386 -> V_318 . type = V_284 ;
V_386 -> V_318 . V_38 = V_175 -> V_198 ;
V_175 -> V_198 = ( void * ) V_386 ;
V_195 = F_155 ( V_364 -> V_389 -> V_390 ) ;
F_156 ( V_195 , & V_388 ) ;
F_157 ( V_195 ) ;
V_386 -> V_288 . V_271 = V_388 . V_271 ;
V_386 -> V_288 . V_270 = V_388 . V_270 ;
V_386 -> V_288 . V_289 = ! ! ( V_388 . V_391 & V_392 ) ;
V_386 -> V_287 = ( V_388 . V_391 & V_393 ) >> V_394 ;
V_386 -> V_290 . V_271 = V_385 -> V_395 ;
V_386 -> V_290 . V_270 = V_385 -> V_396 ;
V_386 -> V_290 . V_272 = V_385 -> V_397 ;
V_386 -> V_291 . V_271 = V_384 -> V_395 ;
V_386 -> V_291 . V_270 = V_384 -> V_396 ;
V_386 -> V_291 . V_272 = V_384 -> V_397 ;
return 0 ;
}
void F_158 ( const struct V_54 * V_384 , const struct V_54 * V_385 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_268 . V_99 = F_29 ( V_95 ) ;
V_175 -> V_268 . V_269 . V_272 = V_384 -> V_397 ;
V_175 -> V_268 . V_269 . V_270 = V_384 -> V_397 ;
V_175 -> V_268 . V_269 . V_271 = V_384 -> V_395 ;
V_175 -> type = V_267 ;
}
void F_159 ( int V_275 , int V_1 )
{
struct V_7 * V_175 = V_95 -> V_7 ;
V_175 -> V_274 . V_275 = V_275 ;
V_175 -> V_274 . V_1 = V_1 ;
V_175 -> type = V_273 ;
}
static void F_160 ( struct V_209 * V_210 )
{
T_2 V_206 , V_45 ;
T_3 V_51 ;
unsigned int V_207 ;
struct V_398 * V_230 = V_95 -> V_230 ;
V_206 = F_135 ( V_95 ) ;
V_207 = F_136 ( V_95 ) ;
F_161 ( & V_45 , & V_51 ) ;
F_72 ( V_210 , L_65 ,
F_73 ( & V_212 , V_206 ) ,
F_73 ( & V_212 , V_45 ) ,
F_90 ( & V_212 , V_51 ) ,
V_207 ) ;
F_133 ( V_210 ) ;
F_72 ( V_210 , L_66 , F_29 ( V_95 ) ) ;
F_76 ( V_210 , V_95 -> V_208 ) ;
if ( V_230 ) {
F_162 ( & V_230 -> V_399 ) ;
if ( V_230 -> V_400 )
F_99 ( V_210 , L_67 , & V_230 -> V_400 -> V_401 ) ;
F_163 ( & V_230 -> V_399 ) ;
} else
F_72 ( V_210 , L_68 ) ;
}
void F_164 ( long V_402 )
{
struct V_209 * V_210 ;
if ( ! V_311 )
return;
if ( V_402 == V_403 )
return;
V_210 = F_71 ( NULL , V_39 , V_404 ) ;
if ( F_4 ( ! V_210 ) )
return;
F_160 ( V_210 ) ;
F_72 ( V_210 , L_69 , V_402 ) ;
F_77 ( V_210 ) ;
}
void F_165 ( unsigned long V_405 , long V_402 , int V_406 )
{
struct V_209 * V_210 ;
V_210 = F_71 ( NULL , V_39 , V_407 ) ;
if ( F_4 ( ! V_210 ) )
return;
F_160 ( V_210 ) ;
F_72 ( V_210 , L_69 , V_402 ) ;
F_72 ( V_210 , L_70 , V_405 ) ;
F_72 ( V_210 , L_71 , F_166 () ) ;
F_72 ( V_210 , L_72 , F_167 ( V_95 ) ) ;
F_72 ( V_210 , L_73 , V_406 ) ;
F_77 ( V_210 ) ;
}
struct V_169 * F_168 ( void )
{
struct V_7 * V_8 = V_95 -> V_7 ;
if ( F_11 ( ! V_8 || ! V_8 -> V_180 ) )
return NULL ;
return & V_8 -> V_200 ;
}
