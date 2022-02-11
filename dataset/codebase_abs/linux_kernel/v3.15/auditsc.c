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
static enum V_89 F_45 ( struct V_52 * V_53 ,
struct V_7 * V_8 ,
struct V_166 * V_167 )
{
struct V_163 * V_164 ;
enum V_89 V_90 ;
if ( V_168 && V_53 -> V_169 == V_168 )
return V_160 ;
F_42 () ;
if ( ! F_46 ( V_167 ) ) {
int V_170 = F_47 ( V_8 -> V_9 ) ;
int V_171 = F_48 ( V_8 -> V_9 ) ;
F_43 (e, list, list) {
if ( ( V_164 -> V_88 . V_2 [ V_170 ] & V_171 ) == V_171 &&
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
static int F_49 ( struct V_52 * V_53 ,
struct V_23 * V_3 ,
struct V_7 * V_8 ) {
int V_170 , V_171 ;
int V_172 = F_50 ( ( T_4 ) V_3 -> V_25 ) ;
struct V_166 * V_167 = & V_173 [ V_172 ] ;
struct V_163 * V_164 ;
enum V_89 V_90 ;
V_170 = F_47 ( V_8 -> V_9 ) ;
V_171 = F_48 ( V_8 -> V_9 ) ;
if ( F_46 ( V_167 ) )
return 0 ;
F_43 (e, list, list) {
if ( ( V_164 -> V_88 . V_2 [ V_170 ] & V_171 ) == V_171 &&
F_27 ( V_53 , & V_164 -> V_88 , V_8 , V_3 , & V_90 , false ) ) {
V_8 -> V_28 = V_90 ;
return 1 ;
}
}
return 0 ;
}
void F_51 ( struct V_52 * V_53 , struct V_7 * V_8 )
{
struct V_23 * V_3 ;
if ( V_168 && V_53 -> V_169 == V_168 )
return;
F_42 () ;
F_8 (n, &ctx->names_list, list) {
if ( F_49 ( V_53 , V_3 , V_8 ) )
break;
}
F_44 () ;
}
static inline struct V_7 * F_52 ( struct V_52 * V_53 ,
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
F_45 ( V_53 , V_174 , & V_181 [ V_182 ] ) ;
F_51 ( V_53 , V_174 ) ;
}
V_53 -> V_7 = NULL ;
return V_174 ;
}
static inline void F_53 ( struct V_7 * V_174 )
{
F_18 ( V_174 -> V_183 . V_184 ) ;
V_174 -> V_183 . V_184 = NULL ;
V_174 -> V_183 . V_185 = 0 ;
}
static inline void F_54 ( struct V_7 * V_174 )
{
struct V_23 * V_3 , * V_38 ;
#if V_186 == 2
if ( V_174 -> V_187 + V_174 -> V_188 != V_174 -> V_189 ) {
int V_92 = 0 ;
F_55 ( L_2
L_3
L_4 , __FILE__ , __LINE__ ,
V_174 -> V_190 , V_174 -> V_9 , V_174 -> V_179 ,
V_174 -> V_189 , V_174 -> V_187 ,
V_174 -> V_188 ) ;
F_8 (n, &context->names_list, list) {
F_55 ( L_5 , V_92 ++ , V_3 -> V_46 ,
V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
F_56 () ;
return;
}
#endif
#if V_186
V_174 -> V_187 = 0 ;
V_174 -> V_188 = 0 ;
#endif
F_57 (n, next, &context->names_list, list) {
F_58 ( & V_3 -> V_167 ) ;
if ( V_3 -> V_46 && V_3 -> V_191 )
F_59 ( V_3 -> V_46 ) ;
if ( V_3 -> V_192 )
F_18 ( V_3 ) ;
}
V_174 -> V_189 = 0 ;
F_60 ( & V_174 -> V_193 ) ;
V_174 -> V_193 . V_194 = NULL ;
V_174 -> V_193 . V_195 = NULL ;
}
static inline void F_61 ( struct V_7 * V_174 )
{
struct V_196 * V_197 ;
while ( ( V_197 = V_174 -> V_197 ) ) {
V_174 -> V_197 = V_197 -> V_38 ;
F_18 ( V_197 ) ;
}
while ( ( V_197 = V_174 -> V_198 ) ) {
V_174 -> V_198 = V_197 -> V_38 ;
F_18 ( V_197 ) ;
}
}
static inline struct V_7 * F_62 ( enum V_89 V_90 )
{
struct V_7 * V_174 ;
V_174 = F_13 ( sizeof( * V_174 ) , V_39 ) ;
if ( ! V_174 )
return NULL ;
V_174 -> V_90 = V_90 ;
V_174 -> V_27 = V_90 == V_29 ? ~ 0ULL : 0 ;
F_63 ( & V_174 -> V_199 ) ;
F_63 ( & V_174 -> V_200 ) ;
return V_174 ;
}
int F_64 ( struct V_52 * V_53 )
{
struct V_7 * V_174 ;
enum V_89 V_90 ;
char * V_162 = NULL ;
if ( F_11 ( ! V_201 ) )
return 0 ;
V_90 = F_41 ( V_53 , & V_162 ) ;
if ( V_90 == V_160 ) {
F_65 ( V_53 , V_202 ) ;
return 0 ;
}
if ( ! ( V_174 = F_62 ( V_90 ) ) ) {
F_18 ( V_162 ) ;
F_66 ( L_7 ) ;
return - V_203 ;
}
V_174 -> V_156 = V_162 ;
V_53 -> V_7 = V_174 ;
F_67 ( V_53 , V_202 ) ;
return 0 ;
}
static inline void F_68 ( struct V_7 * V_174 )
{
F_54 ( V_174 ) ;
F_14 ( V_174 , NULL , 0 ) ;
F_17 ( V_174 ) ;
F_61 ( V_174 ) ;
F_18 ( V_174 -> V_156 ) ;
F_18 ( V_174 -> V_204 ) ;
F_53 ( V_174 ) ;
F_18 ( V_174 ) ;
}
static int F_69 ( struct V_7 * V_174 , T_5 V_99 ,
T_2 V_205 , T_2 V_45 , unsigned int V_206 ,
T_4 V_94 , char * V_207 )
{
struct V_208 * V_209 ;
char * V_8 = NULL ;
T_4 V_185 ;
int V_49 = 0 ;
V_209 = F_70 ( V_174 , V_39 , V_210 ) ;
if ( ! V_209 )
return V_49 ;
F_71 ( V_209 , L_8 , V_99 ,
F_72 ( & V_211 , V_205 ) ,
F_72 ( & V_211 , V_45 ) , V_206 ) ;
if ( V_94 ) {
if ( F_73 ( V_94 , & V_8 , & V_185 ) ) {
F_71 ( V_209 , L_9 ) ;
V_49 = 1 ;
} else {
F_71 ( V_209 , L_10 , V_8 ) ;
F_74 ( V_8 , V_185 ) ;
}
}
F_71 ( V_209 , L_11 ) ;
F_75 ( V_209 , V_207 ) ;
F_76 ( V_209 ) ;
return V_49 ;
}
static int F_77 ( struct V_7 * V_174 ,
struct V_208 * * V_209 ,
int V_212 ,
T_6 * V_213 ,
const char T_7 * V_33 ,
char * V_214 )
{
char V_215 [ 12 ] ;
const char T_7 * V_216 = V_33 ;
T_6 V_217 = snprintf ( V_215 , 12 , L_12 , V_212 ) + 5 ;
T_6 V_185 , V_218 , V_219 ;
T_6 V_220 = V_221 ;
unsigned int V_92 , V_222 = 0 , V_223 = 0 ;
int V_224 ;
V_218 = V_185 = F_78 ( V_33 , V_225 ) - 1 ;
if ( F_4 ( ( V_185 == - 1 ) || V_185 > V_225 - 1 ) ) {
F_79 ( 1 ) ;
F_80 ( V_226 , V_95 , 0 ) ;
return - 1 ;
}
do {
if ( V_218 > V_221 )
V_219 = V_221 ;
else
V_219 = V_218 ;
V_224 = F_81 ( V_214 , V_216 , V_219 ) ;
if ( V_224 ) {
F_79 ( 1 ) ;
F_80 ( V_226 , V_95 , 0 ) ;
return - 1 ;
}
V_214 [ V_219 ] = '\0' ;
V_222 = F_82 ( V_214 , V_219 ) ;
if ( V_222 ) {
V_220 = V_221 / 2 ;
break;
}
V_218 -= V_219 ;
V_216 += V_219 ;
} while ( V_218 > 0 );
V_218 = V_185 ;
if ( V_185 > V_220 )
V_223 = 1 ;
for ( V_92 = 0 ; V_218 > 0 ; V_92 ++ ) {
int V_227 ;
if ( V_218 > V_220 )
V_219 = V_220 ;
else
V_219 = V_218 ;
V_227 = V_221 - V_217 - * V_213 ;
if ( V_222 )
V_227 -= ( V_219 * 2 ) ;
else
V_227 -= V_219 ;
if ( V_227 < 0 ) {
* V_213 = 0 ;
F_76 ( * V_209 ) ;
* V_209 = F_70 ( V_174 , V_39 , V_228 ) ;
if ( ! * V_209 )
return 0 ;
}
if ( ( V_92 == 0 ) && ( V_223 ) )
F_71 ( * V_209 , L_13 , V_212 ,
V_222 ? 2 * V_185 : V_185 ) ;
if ( V_185 >= V_220 )
V_224 = F_81 ( V_214 , V_33 , V_219 ) ;
else
V_224 = 0 ;
if ( V_224 ) {
F_79 ( 1 ) ;
F_80 ( V_226 , V_95 , 0 ) ;
return - 1 ;
}
V_214 [ V_219 ] = '\0' ;
F_71 ( * V_209 , L_14 , V_212 ) ;
if ( V_223 )
F_71 ( * V_209 , L_15 , V_92 ) ;
F_71 ( * V_209 , L_16 ) ;
if ( V_222 )
F_83 ( * V_209 , V_214 , V_219 ) ;
else
F_84 ( * V_209 , V_214 ) ;
V_33 += V_219 ;
V_218 -= V_219 ;
* V_213 += V_217 ;
if ( V_222 )
* V_213 += V_219 * 2 ;
else
* V_213 += V_219 ;
}
return V_185 + 1 ;
}
static void F_85 ( struct V_7 * V_174 ,
struct V_208 * * V_209 )
{
int V_92 , V_185 ;
T_6 V_213 = 0 ;
const char T_7 * V_33 ;
char * V_214 ;
V_33 = ( const char T_7 * ) V_95 -> V_229 -> V_230 ;
F_71 ( * V_209 , L_17 , V_174 -> V_231 . V_232 ) ;
V_214 = F_86 ( V_221 + 1 , V_39 ) ;
if ( ! V_214 ) {
F_87 ( L_18 ) ;
return;
}
for ( V_92 = 0 ; V_92 < V_174 -> V_231 . V_232 ; V_92 ++ ) {
V_185 = F_77 ( V_174 , V_209 , V_92 ,
& V_213 , V_33 , V_214 ) ;
if ( V_185 <= 0 )
break;
V_33 += V_185 ;
}
F_18 ( V_214 ) ;
}
static void F_88 ( struct V_7 * V_174 , int * V_233 )
{
struct V_208 * V_209 ;
int V_92 ;
V_209 = F_70 ( V_174 , V_39 , V_174 -> type ) ;
if ( ! V_209 )
return;
switch ( V_174 -> type ) {
case V_234 : {
int V_235 = V_174 -> V_236 . V_235 ;
F_71 ( V_209 , L_19 , V_235 ) ;
for ( V_92 = 0 ; V_92 < V_235 ; V_92 ++ )
F_71 ( V_209 , L_20 , V_92 ,
V_174 -> V_236 . args [ V_92 ] ) ;
break; }
case V_146 : {
T_4 V_145 = V_174 -> V_147 . V_145 ;
F_71 ( V_209 , L_21 ,
F_72 ( & V_211 , V_174 -> V_147 . V_45 ) ,
F_89 ( & V_211 , V_174 -> V_147 . V_51 ) ,
V_174 -> V_147 . V_24 ) ;
if ( V_145 ) {
char * V_8 = NULL ;
T_4 V_185 ;
if ( F_73 ( V_145 , & V_8 , & V_185 ) ) {
F_71 ( V_209 , L_22 , V_145 ) ;
* V_233 = 1 ;
} else {
F_71 ( V_209 , L_10 , V_8 ) ;
F_74 ( V_8 , V_185 ) ;
}
}
if ( V_174 -> V_147 . V_237 ) {
F_76 ( V_209 ) ;
V_209 = F_70 ( V_174 , V_39 ,
V_238 ) ;
if ( F_4 ( ! V_209 ) )
return;
F_71 ( V_209 ,
L_23 ,
V_174 -> V_147 . V_239 ,
V_174 -> V_147 . V_240 ,
V_174 -> V_147 . V_241 ,
V_174 -> V_147 . V_242 ) ;
}
break; }
case V_243 : {
F_71 ( V_209 ,
L_24
L_25 ,
V_174 -> V_244 . V_245 , V_174 -> V_244 . V_24 ,
V_174 -> V_244 . V_246 . V_247 ,
V_174 -> V_244 . V_246 . V_248 ,
V_174 -> V_244 . V_246 . V_249 ,
V_174 -> V_244 . V_246 . V_250 ) ;
break; }
case V_251 : {
F_71 ( V_209 ,
L_26
L_27 ,
V_174 -> V_252 . V_253 ,
V_174 -> V_252 . V_254 ,
V_174 -> V_252 . V_255 ,
V_174 -> V_252 . V_256 . V_257 ,
V_174 -> V_252 . V_256 . V_258 ) ;
break; }
case V_259 : {
F_71 ( V_209 , L_28 ,
V_174 -> V_260 . V_253 ,
V_174 -> V_260 . V_261 ) ;
break; }
case V_262 : {
struct V_263 * V_246 = & V_174 -> V_264 . V_265 ;
F_71 ( V_209 ,
L_29
L_30 ,
V_174 -> V_264 . V_253 ,
V_246 -> V_247 , V_246 -> V_248 ,
V_246 -> V_249 , V_246 -> V_250 ) ;
break; }
case V_266 : {
F_71 ( V_209 , L_31 , V_174 -> V_267 . V_99 ) ;
F_90 ( V_209 , L_32 , & V_174 -> V_267 . V_268 . V_269 ) ;
F_90 ( V_209 , L_33 , & V_174 -> V_267 . V_268 . V_270 ) ;
F_90 ( V_209 , L_34 , & V_174 -> V_267 . V_268 . V_271 ) ;
break; }
case V_272 : {
F_71 ( V_209 , L_35 , V_174 -> V_273 . V_274 ,
V_174 -> V_273 . V_1 ) ;
break; }
case V_228 : {
F_85 ( V_174 , & V_209 ) ;
break; }
}
F_76 ( V_209 ) ;
}
static inline int F_91 ( char * V_183 , int V_185 )
{
char * V_275 = V_183 + V_185 - 1 ;
while ( V_275 > V_183 && ! isprint ( * V_275 ) )
V_275 -- ;
V_185 = V_275 - V_183 + 1 ;
V_185 -= isprint ( V_183 [ V_185 - 1 ] ) == 0 ;
return V_185 ;
}
static void F_92 ( struct V_52 * V_53 ,
struct V_7 * V_174 )
{
int V_276 ;
char * V_214 ;
char * V_277 = L_6 ;
int V_185 = strlen ( V_277 ) ;
struct V_208 * V_209 ;
V_209 = F_70 ( V_174 , V_39 , V_278 ) ;
if ( ! V_209 )
return;
F_71 ( V_209 , L_36 ) ;
if ( ! V_174 -> V_183 . V_184 ) {
V_214 = F_86 ( V_279 , V_39 ) ;
if ( ! V_214 )
goto V_280;
V_276 = F_93 ( V_53 , V_214 , V_279 ) ;
if ( V_276 == 0 ) {
F_18 ( V_214 ) ;
goto V_280;
}
V_276 = F_91 ( V_214 , V_276 ) ;
if ( V_276 == 0 ) {
F_18 ( V_214 ) ;
goto V_280;
}
V_174 -> V_183 . V_184 = V_214 ;
V_174 -> V_183 . V_185 = V_276 ;
}
V_277 = V_174 -> V_183 . V_184 ;
V_185 = V_174 -> V_183 . V_185 ;
V_280:
F_94 ( V_209 , V_277 , V_185 ) ;
F_76 ( V_209 ) ;
}
static void F_95 ( struct V_7 * V_174 , struct V_52 * V_53 )
{
int V_92 , V_233 = 0 ;
struct V_208 * V_209 ;
struct V_196 * V_197 ;
struct V_23 * V_3 ;
V_174 -> V_114 = V_53 -> V_114 ;
V_209 = F_70 ( V_174 , V_39 , V_281 ) ;
if ( ! V_209 )
return;
F_71 ( V_209 , L_37 ,
V_174 -> V_10 , V_174 -> V_9 ) ;
if ( V_174 -> V_114 != V_282 )
F_71 ( V_209 , L_38 , V_174 -> V_114 ) ;
if ( V_174 -> V_117 )
F_71 ( V_209 , L_39 ,
( V_174 -> V_117 == V_120 ) ? L_40 : L_41 ,
V_174 -> V_118 ) ;
F_71 ( V_209 ,
L_42 ,
V_174 -> V_19 [ 0 ] ,
V_174 -> V_19 [ 1 ] ,
V_174 -> V_19 [ 2 ] ,
V_174 -> V_19 [ 3 ] ,
V_174 -> V_189 ) ;
F_96 ( V_209 , V_53 ) ;
F_97 ( V_209 , V_174 -> V_156 ) ;
F_76 ( V_209 ) ;
for ( V_197 = V_174 -> V_197 ; V_197 ; V_197 = V_197 -> V_38 ) {
V_209 = F_70 ( V_174 , V_39 , V_197 -> type ) ;
if ( ! V_209 )
continue;
switch ( V_197 -> type ) {
case V_283 : {
struct V_284 * V_285 = ( void * ) V_197 ;
F_71 ( V_209 , L_43 , V_285 -> V_286 ) ;
F_90 ( V_209 , L_44 , & V_285 -> V_287 . V_270 ) ;
F_90 ( V_209 , L_45 , & V_285 -> V_287 . V_269 ) ;
F_71 ( V_209 , L_46 , V_285 -> V_287 . V_288 ) ;
F_90 ( V_209 , L_47 , & V_285 -> V_289 . V_270 ) ;
F_90 ( V_209 , L_48 , & V_285 -> V_289 . V_269 ) ;
F_90 ( V_209 , L_49 , & V_285 -> V_289 . V_271 ) ;
F_90 ( V_209 , L_50 , & V_285 -> V_290 . V_270 ) ;
F_90 ( V_209 , L_51 , & V_285 -> V_290 . V_269 ) ;
F_90 ( V_209 , L_52 , & V_285 -> V_290 . V_271 ) ;
break; }
}
F_76 ( V_209 ) ;
}
if ( V_174 -> type )
F_88 ( V_174 , & V_233 ) ;
if ( V_174 -> V_291 [ 0 ] >= 0 ) {
V_209 = F_70 ( V_174 , V_39 , V_292 ) ;
if ( V_209 ) {
F_71 ( V_209 , L_53 ,
V_174 -> V_291 [ 0 ] , V_174 -> V_291 [ 1 ] ) ;
F_76 ( V_209 ) ;
}
}
if ( V_174 -> V_293 ) {
V_209 = F_70 ( V_174 , V_39 , V_294 ) ;
if ( V_209 ) {
F_71 ( V_209 , L_54 ) ;
F_83 ( V_209 , ( void * ) V_174 -> V_204 ,
V_174 -> V_293 ) ;
F_76 ( V_209 ) ;
}
}
for ( V_197 = V_174 -> V_198 ; V_197 ; V_197 = V_197 -> V_38 ) {
struct V_295 * V_285 = ( void * ) V_197 ;
for ( V_92 = 0 ; V_92 < V_285 -> V_296 ; V_92 ++ )
if ( F_69 ( V_174 , V_285 -> V_297 [ V_92 ] ,
V_285 -> V_298 [ V_92 ] ,
V_285 -> V_299 [ V_92 ] ,
V_285 -> V_300 [ V_92 ] ,
V_285 -> V_301 [ V_92 ] ,
V_285 -> V_302 [ V_92 ] ) )
V_233 = 1 ;
}
if ( V_174 -> V_297 &&
F_69 ( V_174 , V_174 -> V_297 ,
V_174 -> V_298 , V_174 -> V_299 ,
V_174 -> V_300 ,
V_174 -> V_301 , V_174 -> V_302 ) )
V_233 = 1 ;
if ( V_174 -> V_193 . V_194 && V_174 -> V_193 . V_195 ) {
V_209 = F_70 ( V_174 , V_39 , V_303 ) ;
if ( V_209 ) {
F_98 ( V_209 , L_55 , & V_174 -> V_193 ) ;
F_76 ( V_209 ) ;
}
}
V_92 = 0 ;
F_8 (n, &context->names_list, list) {
if ( V_3 -> V_304 )
continue;
F_99 ( V_174 , V_3 , NULL , V_92 ++ , & V_233 ) ;
}
F_92 ( V_53 , V_174 ) ;
V_209 = F_70 ( V_174 , V_39 , V_305 ) ;
if ( V_209 )
F_76 ( V_209 ) ;
if ( V_233 )
F_87 ( L_56 ) ;
}
void F_100 ( struct V_52 * V_53 )
{
struct V_7 * V_174 ;
V_174 = F_52 ( V_53 , 0 , 0 ) ;
if ( ! V_174 )
return;
if ( V_174 -> V_179 && V_174 -> V_28 == V_29 )
F_95 ( V_174 , V_53 ) ;
if ( ! F_46 ( & V_174 -> V_199 ) )
F_101 ( & V_174 -> V_199 ) ;
F_68 ( V_174 ) ;
}
void F_102 ( int V_10 , int V_9 ,
unsigned long V_306 , unsigned long V_307 ,
unsigned long V_308 , unsigned long V_309 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_174 = V_53 -> V_7 ;
enum V_89 V_90 ;
if ( ! V_174 )
return;
F_103 ( V_174 -> V_179 || V_174 -> V_189 ) ;
if ( ! V_310 )
return;
V_174 -> V_10 = V_10 ;
V_174 -> V_9 = V_9 ;
V_174 -> V_19 [ 0 ] = V_306 ;
V_174 -> V_19 [ 1 ] = V_307 ;
V_174 -> V_19 [ 2 ] = V_308 ;
V_174 -> V_19 [ 3 ] = V_309 ;
V_90 = V_174 -> V_90 ;
V_174 -> V_180 = ! V_311 ;
if ( ! V_174 -> V_180 && V_90 == V_165 ) {
V_174 -> V_27 = 0 ;
V_90 = F_45 ( V_53 , V_174 , & V_181 [ V_312 ] ) ;
}
if ( V_90 == V_160 )
return;
V_174 -> V_190 = 0 ;
V_174 -> ctime = V_313 ;
V_174 -> V_179 = 1 ;
V_174 -> V_28 = V_90 ;
V_174 -> V_102 = 0 ;
}
void F_104 ( int V_314 , long V_118 )
{
struct V_52 * V_53 = V_95 ;
struct V_7 * V_174 ;
if ( V_314 )
V_314 = V_120 ;
else
V_314 = V_121 ;
V_174 = F_52 ( V_53 , V_314 , V_118 ) ;
if ( ! V_174 )
return;
if ( V_174 -> V_179 && V_174 -> V_28 == V_29 )
F_95 ( V_174 , V_53 ) ;
V_174 -> V_179 = 0 ;
V_174 -> V_27 = V_174 -> V_90 == V_29 ? ~ 0ULL : 0 ;
if ( ! F_46 ( & V_174 -> V_199 ) )
F_101 ( & V_174 -> V_199 ) ;
F_54 ( V_174 ) ;
F_14 ( V_174 , NULL , 0 ) ;
F_61 ( V_174 ) ;
V_174 -> V_197 = NULL ;
V_174 -> V_198 = NULL ;
V_174 -> V_297 = 0 ;
V_174 -> V_301 = 0 ;
V_174 -> V_293 = 0 ;
V_174 -> type = 0 ;
V_174 -> V_291 [ 0 ] = - 1 ;
if ( V_174 -> V_90 != V_29 ) {
F_18 ( V_174 -> V_156 ) ;
V_174 -> V_156 = NULL ;
}
V_53 -> V_7 = V_174 ;
}
static inline void F_105 ( const struct V_315 * V_315 )
{
#ifdef F_15
struct V_7 * V_174 ;
struct V_32 * V_33 ;
struct V_30 * V_31 ;
int V_41 ;
if ( F_11 ( F_106 ( & V_315 -> V_316 ) ) )
return;
V_174 = V_95 -> V_7 ;
V_33 = V_174 -> V_34 ;
V_41 = V_174 -> V_36 ;
F_42 () ;
V_31 = F_107 ( V_315 ) ;
F_44 () ;
if ( ! V_31 )
return;
if ( F_11 ( F_10 ( V_174 , V_31 ) ) )
return;
if ( F_4 ( ! F_12 ( V_174 ) ) ) {
F_108 ( L_57 ) ;
F_9 ( V_174 ) ;
F_16 ( V_31 ) ;
F_14 ( V_174 , V_33 , V_41 ) ;
return;
}
F_10 ( V_174 , V_31 ) ;
#endif
}
static void F_109 ( const struct V_194 * V_194 )
{
#ifdef F_15
struct V_7 * V_174 ;
struct V_32 * V_33 ;
const struct V_194 * V_317 , * V_318 ;
struct V_30 * V_319 ;
unsigned long V_320 ;
int V_41 ;
V_174 = V_95 -> V_7 ;
V_33 = V_174 -> V_34 ;
V_41 = V_174 -> V_36 ;
V_321:
V_319 = NULL ;
V_317 = V_194 ;
F_42 () ;
V_320 = F_110 ( & V_322 ) ;
for(; ; ) {
struct V_315 * V_315 = V_317 -> V_323 ;
if ( V_315 && F_4 ( ! F_106 ( & V_315 -> V_316 ) ) ) {
struct V_30 * V_31 ;
V_31 = F_107 ( V_315 ) ;
if ( V_31 ) {
if ( F_4 ( ! F_10 ( V_174 , V_31 ) ) ) {
V_319 = V_31 ;
break;
}
}
}
V_318 = V_317 -> V_324 ;
if ( V_318 == V_317 )
break;
V_317 = V_318 ;
}
if ( F_4 ( F_111 ( & V_322 , V_320 ) || V_319 ) ) {
F_44 () ;
if ( ! V_319 ) {
F_14 ( V_174 , V_33 , V_41 ) ;
goto V_321;
}
F_16 ( V_319 ) ;
if ( F_12 ( V_174 ) ) {
F_14 ( V_174 , V_33 , V_41 ) ;
goto V_321;
}
F_108 ( L_57 ) ;
F_14 ( V_174 , V_33 , V_41 ) ;
F_9 ( V_174 ) ;
return;
}
F_44 () ;
#endif
}
static struct V_23 * F_112 ( struct V_7 * V_174 ,
unsigned char type )
{
struct V_23 * V_325 ;
if ( V_174 -> V_189 < V_326 ) {
V_325 = & V_174 -> V_327 [ V_174 -> V_189 ] ;
memset ( V_325 , 0 , sizeof( * V_325 ) ) ;
} else {
V_325 = F_13 ( sizeof( * V_325 ) , V_328 ) ;
if ( ! V_325 )
return NULL ;
V_325 -> V_192 = true ;
}
V_325 -> V_25 = ( unsigned long ) - 1 ;
V_325 -> type = type ;
F_113 ( & V_325 -> V_167 , & V_174 -> V_200 ) ;
V_174 -> V_189 ++ ;
#if V_186
V_174 -> V_188 ++ ;
#endif
return V_325 ;
}
struct V_329 *
F_114 ( const T_7 char * V_330 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_23 * V_3 ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 )
continue;
if ( V_3 -> V_46 -> V_330 == V_330 )
return V_3 -> V_46 ;
}
return NULL ;
}
void F_115 ( struct V_329 * V_46 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_23 * V_3 ;
if ( ! V_174 -> V_179 ) {
#if V_186 == 2
F_55 ( L_58 ,
__FILE__ , __LINE__ , V_174 -> V_190 , V_46 ) ;
F_56 () ;
#endif
return;
}
#if V_186
F_103 ( ! V_46 -> V_46 ) ;
#endif
V_3 = F_112 ( V_174 , V_331 ) ;
if ( ! V_3 )
return;
V_3 -> V_46 = V_46 ;
V_3 -> V_332 = V_333 ;
V_3 -> V_191 = true ;
V_46 -> V_325 = V_3 ;
if ( ! V_174 -> V_193 . V_194 )
F_116 ( V_95 -> V_334 , & V_174 -> V_193 ) ;
}
void F_117 ( struct V_329 * V_46 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
F_103 ( ! V_174 ) ;
if ( ! V_46 -> V_325 || ! V_174 -> V_179 ) {
#if V_186 == 2
F_55 ( L_59 ,
__FILE__ , __LINE__ , V_174 -> V_190 , V_46 ) ;
if ( V_174 -> V_189 ) {
struct V_23 * V_3 ;
int V_92 = 0 ;
F_8 (n, &context->names_list, list)
F_55 ( L_60 , V_92 ++ , V_3 -> V_46 ,
V_3 -> V_46 -> V_46 ? : L_6 ) ;
}
#endif
F_59 ( V_46 ) ;
}
#if V_186
else {
++ V_174 -> V_187 ;
if ( V_174 -> V_187 > V_174 -> V_189 ) {
F_55 ( L_61
L_62 ,
__FILE__ , __LINE__ ,
V_174 -> V_190 , V_174 -> V_9 ,
V_174 -> V_179 , V_46 -> V_46 ,
V_174 -> V_189 , V_174 -> V_187 ) ;
F_56 () ;
}
}
#endif
}
void F_118 ( struct V_329 * V_46 , const struct V_194 * V_194 ,
unsigned int V_1 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
const struct V_315 * V_315 = V_194 -> V_323 ;
struct V_23 * V_3 ;
bool V_318 = V_1 & V_335 ;
if ( ! V_174 -> V_179 )
return;
if ( ! V_46 )
goto V_336;
#if V_186
F_103 ( ! V_46 -> V_46 ) ;
#endif
V_3 = V_46 -> V_325 ;
if ( V_3 ) {
if ( V_318 ) {
if ( V_3 -> type == V_337 ||
V_3 -> type == V_331 )
goto V_280;
} else {
if ( V_3 -> type != V_337 )
goto V_280;
}
}
F_119 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> V_46 -> V_46 != V_46 -> V_46 )
continue;
if ( V_318 ) {
if ( V_3 -> type == V_337 ||
V_3 -> type == V_331 )
goto V_280;
} else {
if ( V_3 -> type != V_337 )
goto V_280;
}
}
V_336:
V_3 = F_112 ( V_174 , V_338 ) ;
if ( ! V_3 )
return;
V_280:
if ( V_318 ) {
V_3 -> V_332 = V_3 -> V_46 ? F_120 ( V_3 -> V_46 -> V_46 ) : V_333 ;
V_3 -> type = V_337 ;
if ( V_1 & V_339 )
V_3 -> V_304 = true ;
} else {
V_3 -> V_332 = V_333 ;
V_3 -> type = V_338 ;
}
F_109 ( V_194 ) ;
F_121 ( V_3 , V_194 , V_315 ) ;
}
void F_122 ( const struct V_315 * V_318 ,
const struct V_194 * V_194 ,
const unsigned char type )
{
struct V_7 * V_174 = V_95 -> V_7 ;
const struct V_315 * V_315 = V_194 -> V_323 ;
const char * V_340 = V_194 -> V_341 . V_46 ;
struct V_23 * V_3 , * V_342 = NULL , * V_343 = NULL ;
if ( ! V_174 -> V_179 )
return;
if ( V_315 )
F_105 ( V_315 ) ;
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != V_337 )
continue;
if ( V_3 -> V_25 == V_318 -> V_344 &&
! F_123 ( V_340 , V_3 -> V_46 -> V_46 , V_3 -> V_332 ) ) {
V_342 = V_3 ;
break;
}
}
F_8 (n, &context->names_list, list) {
if ( ! V_3 -> V_46 || V_3 -> type != type )
continue;
if ( V_342 && ( V_3 -> V_46 != V_342 -> V_46 ) )
continue;
if ( ! strcmp ( V_340 , V_3 -> V_46 -> V_46 ) ||
! F_123 ( V_340 , V_3 -> V_46 -> V_46 ,
V_342 ?
V_342 -> V_332 :
V_333 ) ) {
V_343 = V_3 ;
break;
}
}
if ( ! V_342 ) {
V_3 = F_112 ( V_174 , V_337 ) ;
if ( ! V_3 )
return;
F_121 ( V_3 , NULL , V_318 ) ;
}
if ( ! V_343 ) {
V_343 = F_112 ( V_174 , type ) ;
if ( ! V_343 )
return;
if ( V_342 ) {
V_343 -> V_46 = V_342 -> V_46 ;
V_343 -> V_332 = V_333 ;
V_343 -> V_191 = false ;
}
}
if ( V_315 )
F_121 ( V_343 , V_194 , V_315 ) ;
else
V_343 -> V_25 = ( unsigned long ) - 1 ;
}
int F_124 ( struct V_7 * V_8 ,
struct V_345 * V_346 , unsigned int * V_190 )
{
if ( ! V_8 -> V_179 )
return 0 ;
if ( ! V_8 -> V_190 )
V_8 -> V_190 = F_125 () ;
V_346 -> V_257 = V_8 -> ctime . V_257 ;
V_346 -> V_258 = V_8 -> ctime . V_258 ;
* V_190 = V_8 -> V_190 ;
if ( ! V_8 -> V_27 ) {
V_8 -> V_27 = 1 ;
V_8 -> V_28 = V_29 ;
}
return 1 ;
}
static int F_126 ( T_2 V_62 )
{
if ( ! F_37 ( V_95 ) )
return 0 ;
if ( F_127 ( V_347 ) )
return - V_348 ;
if ( ! F_128 ( V_349 ) )
return - V_348 ;
if ( F_127 ( V_350 ) && F_129 ( V_62 ) )
return - V_348 ;
return 0 ;
}
static void F_130 ( T_2 V_351 , T_2 V_352 ,
unsigned int V_353 , unsigned int V_206 ,
int V_49 )
{
struct V_208 * V_209 ;
T_8 V_45 , V_354 , V_62 ;
if ( ! V_310 )
return;
V_45 = F_72 ( & V_211 , F_131 ( V_95 ) ) ;
V_354 = F_72 ( & V_211 , V_351 ) ;
V_62 = F_72 ( & V_211 , V_352 ) ,
V_209 = F_70 ( NULL , V_39 , V_355 ) ;
if ( ! V_209 )
return;
F_71 ( V_209 , L_63 , F_29 ( V_95 ) , V_45 ) ;
F_132 ( V_209 ) ;
F_71 ( V_209 , L_64 ,
V_354 , V_62 , V_353 , V_206 , ! V_49 ) ;
F_76 ( V_209 ) ;
}
int F_133 ( T_2 V_62 )
{
struct V_52 * V_356 = V_95 ;
unsigned int V_353 , V_206 = ( unsigned int ) - 1 ;
T_2 V_354 ;
int V_49 ;
V_354 = F_134 ( V_95 ) ;
V_353 = F_135 ( V_95 ) ;
V_49 = F_126 ( V_62 ) ;
if ( V_49 )
goto V_280;
if ( F_129 ( V_62 ) )
V_206 = ( unsigned int ) F_136 ( & V_357 ) ;
V_356 -> V_206 = V_206 ;
V_356 -> V_62 = V_62 ;
V_280:
F_130 ( V_354 , V_62 , V_353 , V_206 , V_49 ) ;
return V_49 ;
}
void F_137 ( int V_245 , T_1 V_24 , struct V_263 * V_246 )
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
void F_138 ( T_9 V_253 , T_6 V_254 , unsigned int V_255 ,
const struct V_345 * V_256 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_345 * V_33 = & V_174 -> V_252 . V_256 ;
if ( V_256 )
memcpy ( V_33 , V_256 , sizeof( struct V_345 ) ) ;
else
memset ( V_33 , 0 , sizeof( struct V_345 ) ) ;
V_174 -> V_252 . V_253 = V_253 ;
V_174 -> V_252 . V_254 = V_254 ;
V_174 -> V_252 . V_255 = V_255 ;
V_174 -> type = V_251 ;
}
void F_139 ( T_9 V_253 , const struct V_358 * V_359 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( V_359 )
V_174 -> V_260 . V_261 = V_359 -> V_261 ;
else
V_174 -> V_260 . V_261 = 0 ;
V_174 -> V_260 . V_253 = V_253 ;
V_174 -> type = V_259 ;
}
void F_140 ( T_9 V_253 , struct V_263 * V_265 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_264 . V_253 = V_253 ;
V_174 -> V_264 . V_265 = * V_265 ;
V_174 -> type = V_262 ;
}
void F_141 ( struct V_360 * V_361 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_147 . V_45 = V_361 -> V_45 ;
V_174 -> V_147 . V_51 = V_361 -> V_51 ;
V_174 -> V_147 . V_24 = V_361 -> V_24 ;
V_174 -> V_147 . V_237 = 0 ;
F_142 ( V_361 , & V_174 -> V_147 . V_145 ) ;
V_174 -> type = V_146 ;
}
void F_143 ( unsigned long V_239 , T_8 V_45 , T_10 V_51 , T_1 V_24 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_147 . V_239 = V_239 ;
V_174 -> V_147 . V_240 = V_45 ;
V_174 -> V_147 . V_241 = V_51 ;
V_174 -> V_147 . V_242 = V_24 ;
V_174 -> V_147 . V_237 = 1 ;
}
void F_144 ( struct V_362 * V_363 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> type = V_228 ;
V_174 -> V_231 . V_232 = V_363 -> V_232 ;
}
int F_145 ( int V_235 , unsigned long * args )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( V_235 <= 0 || V_235 > V_364 || ! args )
return - V_365 ;
V_174 -> type = V_234 ;
V_174 -> V_236 . V_235 = V_235 ;
memcpy ( V_174 -> V_236 . args , args , V_235 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_146 ( int V_366 , int V_367 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_291 [ 0 ] = V_366 ;
V_174 -> V_291 [ 1 ] = V_367 ;
}
int F_147 ( int V_185 , void * V_368 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
if ( ! V_174 -> V_204 ) {
void * V_33 = F_86 ( sizeof( struct V_369 ) , V_39 ) ;
if ( ! V_33 )
return - V_203 ;
V_174 -> V_204 = V_33 ;
}
V_174 -> V_293 = V_185 ;
memcpy ( V_174 -> V_204 , V_368 , V_185 ) ;
return 0 ;
}
void F_148 ( struct V_52 * V_346 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_297 = F_29 ( V_346 ) ;
V_174 -> V_298 = F_134 ( V_346 ) ;
V_174 -> V_299 = F_131 ( V_346 ) ;
V_174 -> V_300 = F_135 ( V_346 ) ;
F_38 ( V_346 , & V_174 -> V_301 ) ;
memcpy ( V_174 -> V_302 , V_346 -> V_207 , V_370 ) ;
}
int F_149 ( int V_371 , struct V_52 * V_346 )
{
struct V_295 * V_372 ;
struct V_52 * V_53 = V_95 ;
struct V_7 * V_8 = V_53 -> V_7 ;
T_2 V_45 = F_150 () , V_373 = F_131 ( V_346 ) ;
if ( V_168 && V_346 -> V_169 == V_168 ) {
if ( V_371 == V_374 || V_371 == V_375 || V_371 == V_376 || V_371 == V_377 ) {
V_378 = F_29 ( V_53 ) ;
if ( F_129 ( V_53 -> V_62 ) )
V_379 = V_53 -> V_62 ;
else
V_379 = V_45 ;
F_38 ( V_53 , & V_380 ) ;
}
if ( ! V_381 || F_151 () )
return 0 ;
}
if ( ! V_8 -> V_297 ) {
V_8 -> V_297 = F_152 ( V_346 ) ;
V_8 -> V_298 = F_134 ( V_346 ) ;
V_8 -> V_299 = V_373 ;
V_8 -> V_300 = F_135 ( V_346 ) ;
F_38 ( V_346 , & V_8 -> V_301 ) ;
memcpy ( V_8 -> V_302 , V_346 -> V_207 , V_370 ) ;
return 0 ;
}
V_372 = ( void * ) V_8 -> V_198 ;
if ( ! V_372 || V_372 -> V_296 == V_382 ) {
V_372 = F_13 ( sizeof( * V_372 ) , V_157 ) ;
if ( ! V_372 )
return - V_203 ;
V_372 -> V_317 . type = V_210 ;
V_372 -> V_317 . V_38 = V_8 -> V_198 ;
V_8 -> V_198 = ( void * ) V_372 ;
}
F_103 ( V_372 -> V_296 >= V_382 ) ;
V_372 -> V_297 [ V_372 -> V_296 ] = F_152 ( V_346 ) ;
V_372 -> V_298 [ V_372 -> V_296 ] = F_134 ( V_346 ) ;
V_372 -> V_299 [ V_372 -> V_296 ] = V_373 ;
V_372 -> V_300 [ V_372 -> V_296 ] = F_135 ( V_346 ) ;
F_38 ( V_346 , & V_372 -> V_301 [ V_372 -> V_296 ] ) ;
memcpy ( V_372 -> V_302 [ V_372 -> V_296 ] , V_346 -> V_207 , V_370 ) ;
V_372 -> V_296 ++ ;
return 0 ;
}
int F_153 ( struct V_362 * V_363 ,
const struct V_54 * V_383 , const struct V_54 * V_384 )
{
struct V_284 * V_385 ;
struct V_7 * V_174 = V_95 -> V_7 ;
struct V_386 V_387 ;
struct V_194 * V_194 ;
V_385 = F_86 ( sizeof( * V_385 ) , V_39 ) ;
if ( ! V_385 )
return - V_203 ;
V_385 -> V_317 . type = V_283 ;
V_385 -> V_317 . V_38 = V_174 -> V_197 ;
V_174 -> V_197 = ( void * ) V_385 ;
V_194 = F_154 ( V_363 -> V_388 -> V_389 ) ;
F_155 ( V_194 , & V_387 ) ;
F_156 ( V_194 ) ;
V_385 -> V_287 . V_270 = V_387 . V_270 ;
V_385 -> V_287 . V_269 = V_387 . V_269 ;
V_385 -> V_287 . V_288 = ! ! ( V_387 . V_390 & V_391 ) ;
V_385 -> V_286 = ( V_387 . V_390 & V_392 ) >> V_393 ;
V_385 -> V_289 . V_270 = V_384 -> V_394 ;
V_385 -> V_289 . V_269 = V_384 -> V_395 ;
V_385 -> V_289 . V_271 = V_384 -> V_396 ;
V_385 -> V_290 . V_270 = V_383 -> V_394 ;
V_385 -> V_290 . V_269 = V_383 -> V_395 ;
V_385 -> V_290 . V_271 = V_383 -> V_396 ;
return 0 ;
}
void F_157 ( const struct V_54 * V_383 , const struct V_54 * V_384 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_267 . V_99 = F_29 ( V_95 ) ;
V_174 -> V_267 . V_268 . V_271 = V_383 -> V_396 ;
V_174 -> V_267 . V_268 . V_269 = V_383 -> V_396 ;
V_174 -> V_267 . V_268 . V_270 = V_383 -> V_394 ;
V_174 -> type = V_266 ;
}
void F_158 ( int V_274 , int V_1 )
{
struct V_7 * V_174 = V_95 -> V_7 ;
V_174 -> V_273 . V_274 = V_274 ;
V_174 -> V_273 . V_1 = V_1 ;
V_174 -> type = V_272 ;
}
static void F_159 ( struct V_208 * V_209 )
{
T_2 V_205 , V_45 ;
T_3 V_51 ;
unsigned int V_206 ;
struct V_397 * V_229 = V_95 -> V_229 ;
V_205 = F_134 ( V_95 ) ;
V_206 = F_135 ( V_95 ) ;
F_160 ( & V_45 , & V_51 ) ;
F_71 ( V_209 , L_65 ,
F_72 ( & V_211 , V_205 ) ,
F_72 ( & V_211 , V_45 ) ,
F_89 ( & V_211 , V_51 ) ,
V_206 ) ;
F_132 ( V_209 ) ;
F_71 ( V_209 , L_66 , F_29 ( V_95 ) ) ;
F_75 ( V_209 , V_95 -> V_207 ) ;
if ( V_229 ) {
F_161 ( & V_229 -> V_398 ) ;
if ( V_229 -> V_399 )
F_98 ( V_209 , L_67 , & V_229 -> V_399 -> V_400 ) ;
F_162 ( & V_229 -> V_398 ) ;
} else
F_71 ( V_209 , L_68 ) ;
}
void F_163 ( long V_401 )
{
struct V_208 * V_209 ;
if ( ! V_310 )
return;
if ( V_401 == V_402 )
return;
V_209 = F_70 ( NULL , V_39 , V_403 ) ;
if ( F_4 ( ! V_209 ) )
return;
F_159 ( V_209 ) ;
F_71 ( V_209 , L_69 , V_401 ) ;
F_76 ( V_209 ) ;
}
void F_164 ( unsigned long V_404 , long V_401 , int V_405 )
{
struct V_208 * V_209 ;
V_209 = F_70 ( NULL , V_39 , V_406 ) ;
if ( F_4 ( ! V_209 ) )
return;
F_159 ( V_209 ) ;
F_71 ( V_209 , L_69 , V_401 ) ;
F_71 ( V_209 , L_70 , V_404 ) ;
F_71 ( V_209 , L_71 , F_165 () ) ;
F_71 ( V_209 , L_72 , F_166 ( V_95 ) ) ;
F_71 ( V_209 , L_73 , V_405 ) ;
F_76 ( V_209 ) ;
}
struct V_166 * F_167 ( void )
{
struct V_7 * V_8 = V_95 -> V_7 ;
if ( F_11 ( ! V_8 || ! V_8 -> V_179 ) )
return NULL ;
return & V_8 -> V_199 ;
}
