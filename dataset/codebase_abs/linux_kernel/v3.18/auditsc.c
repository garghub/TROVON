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
if ( ( V_4 -> V_22 != - 1 ) &&
( ( V_4 -> V_21 & V_23 ) == V_21 ) )
return 1 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 ) {
V_2 -> V_24 = 1 ;
V_2 -> V_25 = V_26 ;
}
}
static int F_9 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
int V_32 = V_2 -> V_33 ;
if ( F_10 ( V_32 ) ) {
V_30 -> V_34 [ -- V_32 ] = V_28 ;
V_2 -> V_33 = V_32 ;
return 1 ;
}
if ( ! V_30 )
return 0 ;
V_30 = V_30 -> V_35 ;
if ( V_30 ) {
V_30 -> V_34 [ 30 ] = V_28 ;
V_2 -> V_31 = V_30 ;
V_2 -> V_33 = 30 ;
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
V_2 -> V_31 = F_12 ( sizeof( struct V_29 ) , V_36 ) ;
if ( ! V_2 -> V_31 ) {
V_2 -> V_31 = V_30 ;
return 0 ;
}
if ( V_30 )
V_30 -> V_35 = V_2 -> V_31 ;
else
V_2 -> V_37 = V_2 -> V_31 ;
V_2 -> V_33 = 31 ;
return 1 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_29 * V_30 , int V_38 )
{
#ifdef F_14
struct V_29 * V_39 ;
int V_4 ;
if ( ! V_30 ) {
V_30 = V_2 -> V_37 ;
V_38 = 31 ;
if ( ! V_30 )
return;
}
V_4 = V_38 ;
for ( V_39 = V_30 ; V_39 != V_2 -> V_31 ; V_39 = V_39 -> V_35 , V_4 = 31 ) {
while ( V_4 -- ) {
F_15 ( V_39 -> V_34 [ V_4 ] ) ;
V_39 -> V_34 [ V_4 ] = NULL ;
}
}
while ( V_4 -- > V_2 -> V_33 ) {
F_15 ( V_39 -> V_34 [ V_4 ] ) ;
V_39 -> V_34 [ V_4 ] = NULL ;
}
V_2 -> V_31 = V_30 ;
V_2 -> V_33 = V_38 ;
#endif
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_30 , * V_39 ;
for ( V_30 = V_2 -> V_37 ; V_30 ; V_30 = V_39 ) {
V_39 = V_30 -> V_35 ;
F_17 ( V_30 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
#ifdef F_14
struct V_29 * V_30 ;
int V_4 ;
if ( ! V_41 )
return 0 ;
for ( V_30 = V_2 -> V_37 ; V_30 != V_2 -> V_31 ; V_30 = V_30 -> V_35 ) {
for ( V_4 = 0 ; V_4 < 31 ; V_4 ++ )
if ( F_19 ( V_30 -> V_34 [ V_4 ] , V_41 ) )
return 1 ;
}
if ( V_30 ) {
for ( V_4 = V_2 -> V_33 ; V_4 < 31 ; V_4 ++ )
if ( F_19 ( V_30 -> V_34 [ V_4 ] , V_41 ) )
return 1 ;
}
#endif
return 0 ;
}
static int F_20 ( T_2 V_42 ,
struct V_20 * V_43 ,
struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_20 * V_4 ;
int V_46 ;
if ( V_43 ) {
V_46 = F_21 ( V_42 , V_45 -> V_47 , V_43 -> V_42 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
V_46 = F_21 ( V_42 , V_45 -> V_47 , V_4 -> V_42 ) ;
if ( V_46 )
return V_46 ;
}
}
return 0 ;
}
static int F_22 ( T_3 V_48 ,
struct V_20 * V_43 ,
struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_20 * V_4 ;
int V_46 ;
if ( V_43 ) {
V_46 = F_23 ( V_48 , V_45 -> V_47 , V_43 -> V_48 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
V_46 = F_23 ( V_48 , V_45 -> V_47 , V_4 -> V_48 ) ;
if ( V_46 )
return V_46 ;
}
}
return 0 ;
}
static int F_24 ( struct V_49 * V_50 ,
const struct V_51 * V_51 ,
struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_20 * V_43 )
{
switch ( V_45 -> V_19 ) {
case V_52 :
return F_20 ( V_51 -> V_42 , V_43 , V_45 , V_2 ) ;
case V_53 :
return F_22 ( V_51 -> V_48 , V_43 , V_45 , V_2 ) ;
case V_54 :
return F_20 ( V_51 -> V_55 , V_43 , V_45 , V_2 ) ;
case V_56 :
return F_22 ( V_51 -> V_57 , V_43 , V_45 , V_2 ) ;
case V_58 :
return F_20 ( V_50 -> V_59 , V_43 , V_45 , V_2 ) ;
case V_60 :
return F_20 ( V_51 -> V_61 , V_43 , V_45 , V_2 ) ;
case V_62 :
return F_22 ( V_51 -> V_63 , V_43 , V_45 , V_2 ) ;
case V_64 :
return F_20 ( V_51 -> V_65 , V_43 , V_45 , V_2 ) ;
case V_66 :
return F_22 ( V_51 -> V_67 , V_43 , V_45 , V_2 ) ;
case V_68 :
return F_21 ( V_51 -> V_42 , V_45 -> V_47 , V_50 -> V_59 ) ;
case V_69 :
return F_21 ( V_51 -> V_42 , V_45 -> V_47 , V_51 -> V_55 ) ;
case V_70 :
return F_21 ( V_51 -> V_42 , V_45 -> V_47 , V_51 -> V_61 ) ;
case V_71 :
return F_21 ( V_51 -> V_42 , V_45 -> V_47 , V_51 -> V_65 ) ;
case V_72 :
return F_21 ( V_50 -> V_59 , V_45 -> V_47 , V_51 -> V_55 ) ;
case V_73 :
return F_21 ( V_50 -> V_59 , V_45 -> V_47 , V_51 -> V_61 ) ;
case V_74 :
return F_21 ( V_50 -> V_59 , V_45 -> V_47 , V_51 -> V_65 ) ;
case V_75 :
return F_21 ( V_51 -> V_55 , V_45 -> V_47 , V_51 -> V_61 ) ;
case V_76 :
return F_21 ( V_51 -> V_55 , V_45 -> V_47 , V_51 -> V_65 ) ;
case V_77 :
return F_21 ( V_51 -> V_61 , V_45 -> V_47 , V_51 -> V_65 ) ;
case V_78 :
return F_23 ( V_51 -> V_48 , V_45 -> V_47 , V_51 -> V_57 ) ;
case V_79 :
return F_23 ( V_51 -> V_48 , V_45 -> V_47 , V_51 -> V_63 ) ;
case V_80 :
return F_23 ( V_51 -> V_48 , V_45 -> V_47 , V_51 -> V_67 ) ;
case V_81 :
return F_23 ( V_51 -> V_57 , V_45 -> V_47 , V_51 -> V_63 ) ;
case V_82 :
return F_23 ( V_51 -> V_57 , V_45 -> V_47 , V_51 -> V_67 ) ;
case V_83 :
return F_23 ( V_51 -> V_63 , V_45 -> V_47 , V_51 -> V_67 ) ;
default:
F_25 ( 1 , L_1 ) ;
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_49 * V_50 ,
struct V_84 * V_85 ,
struct V_1 * V_2 ,
struct V_20 * V_43 ,
enum V_86 * V_87 ,
bool V_88 )
{
const struct V_51 * V_51 ;
int V_89 , V_90 = 1 ;
T_4 V_91 ;
V_51 = F_27 ( V_50 -> V_51 , V_50 == V_92 || V_88 ) ;
for ( V_89 = 0 ; V_89 < V_85 -> V_93 ; V_89 ++ ) {
struct V_44 * V_45 = & V_85 -> V_94 [ V_89 ] ;
struct V_20 * V_4 ;
int V_95 = 0 ;
T_5 V_96 ;
switch ( V_45 -> type ) {
case V_97 :
V_96 = F_28 ( V_50 ) ;
V_95 = F_29 ( V_96 , V_45 -> V_47 , V_45 -> V_19 ) ;
break;
case V_98 :
if ( V_2 ) {
if ( ! V_2 -> V_99 )
V_2 -> V_99 = F_30 ( V_50 ) ;
V_95 = F_29 ( V_2 -> V_99 , V_45 -> V_47 , V_45 -> V_19 ) ;
}
break;
case V_100 :
V_95 = F_21 ( V_51 -> V_42 , V_45 -> V_47 , V_45 -> V_42 ) ;
break;
case V_101 :
V_95 = F_21 ( V_51 -> V_55 , V_45 -> V_47 , V_45 -> V_42 ) ;
break;
case V_102 :
V_95 = F_21 ( V_51 -> V_61 , V_45 -> V_47 , V_45 -> V_42 ) ;
break;
case V_103 :
V_95 = F_21 ( V_51 -> V_65 , V_45 -> V_47 , V_45 -> V_42 ) ;
break;
case V_104 :
V_95 = F_23 ( V_51 -> V_48 , V_45 -> V_47 , V_45 -> V_48 ) ;
if ( V_45 -> V_47 == V_105 ) {
if ( ! V_95 )
V_95 = F_31 ( V_45 -> V_48 ) ;
} else if ( V_45 -> V_47 == V_106 ) {
if ( V_95 )
V_95 = ! F_31 ( V_45 -> V_48 ) ;
}
break;
case V_107 :
V_95 = F_23 ( V_51 -> V_57 , V_45 -> V_47 , V_45 -> V_48 ) ;
if ( V_45 -> V_47 == V_105 ) {
if ( ! V_95 )
V_95 = F_32 ( V_45 -> V_48 ) ;
} else if ( V_45 -> V_47 == V_106 ) {
if ( V_95 )
V_95 = ! F_32 ( V_45 -> V_48 ) ;
}
break;
case V_108 :
V_95 = F_23 ( V_51 -> V_63 , V_45 -> V_47 , V_45 -> V_48 ) ;
break;
case V_109 :
V_95 = F_23 ( V_51 -> V_67 , V_45 -> V_47 , V_45 -> V_48 ) ;
break;
case V_110 :
V_95 = F_29 ( V_50 -> V_111 , V_45 -> V_47 , V_45 -> V_19 ) ;
break;
case V_112 :
if ( V_2 )
V_95 = F_29 ( V_2 -> V_6 , V_45 -> V_47 , V_45 -> V_19 ) ;
break;
case V_113 :
if ( V_2 && V_2 -> V_114 )
V_95 = F_29 ( V_2 -> V_115 , V_45 -> V_47 , V_45 -> V_19 ) ;
break;
case V_116 :
if ( V_2 && V_2 -> V_114 ) {
if ( V_45 -> V_19 )
V_95 = F_29 ( V_2 -> V_114 , V_45 -> V_47 , V_117 ) ;
else
V_95 = F_29 ( V_2 -> V_114 , V_45 -> V_47 , V_118 ) ;
}
break;
case V_119 :
if ( V_43 ) {
if ( F_29 ( F_33 ( V_43 -> V_120 ) , V_45 -> V_47 , V_45 -> V_19 ) ||
F_29 ( F_33 ( V_43 -> V_121 ) , V_45 -> V_47 , V_45 -> V_19 ) )
++ V_95 ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( F_33 ( V_4 -> V_120 ) , V_45 -> V_47 , V_45 -> V_19 ) ||
F_29 ( F_33 ( V_4 -> V_121 ) , V_45 -> V_47 , V_45 -> V_19 ) ) {
++ V_95 ;
break;
}
}
}
break;
case V_122 :
if ( V_43 ) {
if ( F_29 ( F_34 ( V_43 -> V_120 ) , V_45 -> V_47 , V_45 -> V_19 ) ||
F_29 ( F_34 ( V_43 -> V_121 ) , V_45 -> V_47 , V_45 -> V_19 ) )
++ V_95 ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( F_34 ( V_4 -> V_120 ) , V_45 -> V_47 , V_45 -> V_19 ) ||
F_29 ( F_34 ( V_4 -> V_121 ) , V_45 -> V_47 , V_45 -> V_19 ) ) {
++ V_95 ;
break;
}
}
}
break;
case V_123 :
if ( V_43 )
V_95 = F_29 ( V_43 -> V_22 , V_45 -> V_47 , V_45 -> V_19 ) ;
else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_29 ( V_4 -> V_22 , V_45 -> V_47 , V_45 -> V_19 ) ) {
++ V_95 ;
break;
}
}
}
break;
case V_124 :
if ( V_43 ) {
V_95 = F_21 ( V_43 -> V_42 , V_45 -> V_47 , V_45 -> V_42 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_21 ( V_4 -> V_42 , V_45 -> V_47 , V_45 -> V_42 ) ) {
++ V_95 ;
break;
}
}
}
break;
case V_125 :
if ( V_43 ) {
V_95 = F_23 ( V_43 -> V_48 , V_45 -> V_47 , V_45 -> V_48 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_23 ( V_4 -> V_48 , V_45 -> V_47 , V_45 -> V_48 ) ) {
++ V_95 ;
break;
}
}
}
break;
case V_126 :
if ( V_43 )
V_95 = F_35 ( V_85 -> V_127 , V_43 -> V_22 , V_43 -> V_120 ) ;
break;
case V_128 :
if ( V_2 )
V_95 = F_18 ( V_2 , V_85 -> V_41 ) ;
break;
case V_129 :
V_95 = 0 ;
if ( V_2 )
V_95 = F_21 ( V_50 -> V_59 , V_45 -> V_47 , V_45 -> V_42 ) ;
break;
case V_130 :
V_95 = F_29 ( F_36 ( V_50 ) , V_45 -> V_47 , V_45 -> V_19 ) ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
if ( V_45 -> V_136 ) {
if ( V_90 ) {
F_37 ( V_50 , & V_91 ) ;
V_90 = 0 ;
}
V_95 = F_38 ( V_91 , V_45 -> type ,
V_45 -> V_47 ,
V_45 -> V_136 ,
V_2 ) ;
}
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
if ( V_45 -> V_136 ) {
if ( V_43 ) {
V_95 = F_38 (
V_43 -> V_142 , V_45 -> type , V_45 -> V_47 ,
V_45 -> V_136 , V_2 ) ;
} else if ( V_2 ) {
F_7 (n, &ctx->names_list, list) {
if ( F_38 ( V_4 -> V_142 , V_45 -> type ,
V_45 -> V_47 , V_45 -> V_136 ,
V_2 ) ) {
++ V_95 ;
break;
}
}
}
if ( ! V_2 || V_2 -> type != V_143 )
break;
if ( F_38 ( V_2 -> V_144 . V_142 ,
V_45 -> type , V_45 -> V_47 ,
V_45 -> V_136 , V_2 ) )
++ V_95 ;
}
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
if ( V_2 )
V_95 = F_29 ( V_2 -> V_16 [ V_45 -> type - V_145 ] , V_45 -> V_47 , V_45 -> V_19 ) ;
break;
case V_149 :
V_95 = 1 ;
break;
case V_150 :
V_95 = F_1 ( V_2 , V_45 -> V_19 ) ;
break;
case V_151 :
V_95 = F_6 ( V_2 , V_45 -> V_19 ) ;
break;
case V_152 :
V_95 = F_24 ( V_50 , V_51 , V_45 , V_2 , V_43 ) ;
break;
}
if ( ! V_95 )
return 0 ;
}
if ( V_2 ) {
if ( V_85 -> V_24 <= V_2 -> V_24 )
return 0 ;
if ( V_85 -> V_153 ) {
F_17 ( V_2 -> V_153 ) ;
V_2 -> V_153 = F_39 ( V_85 -> V_153 , V_154 ) ;
}
V_2 -> V_24 = V_85 -> V_24 ;
}
switch ( V_85 -> V_155 ) {
case V_156 : * V_87 = V_157 ; break;
case V_158 : * V_87 = V_26 ; break;
}
return 1 ;
}
static enum V_86 F_40 ( struct V_49 * V_50 , char * * V_159 )
{
struct V_160 * V_161 ;
enum V_86 V_87 ;
F_41 () ;
F_42 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_26 ( V_50 , & V_161 -> V_85 , NULL , NULL ,
& V_87 , true ) ) {
if ( V_87 == V_26 )
* V_159 = F_39 ( V_161 -> V_85 . V_153 , V_154 ) ;
F_43 () ;
return V_87 ;
}
}
F_43 () ;
return V_162 ;
}
static int F_44 ( const struct V_84 * V_85 , unsigned long V_19 )
{
int V_163 , V_164 ;
if ( V_19 > 0xffffffff )
return false ;
V_163 = F_45 ( V_19 ) ;
if ( V_163 >= V_165 )
return false ;
V_164 = F_46 ( V_19 ) ;
return V_85 -> V_3 [ V_163 ] & V_164 ;
}
static enum V_86 F_47 ( struct V_49 * V_50 ,
struct V_1 * V_2 ,
struct V_166 * V_167 )
{
struct V_160 * V_161 ;
enum V_86 V_87 ;
if ( V_168 && V_50 -> V_169 == V_168 )
return V_157 ;
F_41 () ;
if ( ! F_48 ( V_167 ) ) {
F_42 (e, list, list) {
if ( F_44 ( & V_161 -> V_85 , V_2 -> V_5 ) &&
F_26 ( V_50 , & V_161 -> V_85 , V_2 , NULL ,
& V_87 , false ) ) {
F_43 () ;
V_2 -> V_25 = V_87 ;
return V_87 ;
}
}
}
F_43 () ;
return V_162 ;
}
static int F_49 ( struct V_49 * V_50 ,
struct V_20 * V_4 ,
struct V_1 * V_2 ) {
int V_170 = F_50 ( ( T_4 ) V_4 -> V_22 ) ;
struct V_166 * V_167 = & V_171 [ V_170 ] ;
struct V_160 * V_161 ;
enum V_86 V_87 ;
if ( F_48 ( V_167 ) )
return 0 ;
F_42 (e, list, list) {
if ( F_44 ( & V_161 -> V_85 , V_2 -> V_5 ) &&
F_26 ( V_50 , & V_161 -> V_85 , V_2 , V_4 , & V_87 , false ) ) {
V_2 -> V_25 = V_87 ;
return 1 ;
}
}
return 0 ;
}
void F_51 ( struct V_49 * V_50 , struct V_1 * V_2 )
{
struct V_20 * V_4 ;
if ( V_168 && V_50 -> V_169 == V_168 )
return;
F_41 () ;
F_7 (n, &ctx->names_list, list) {
if ( F_49 ( V_50 , V_4 , V_2 ) )
break;
}
F_43 () ;
}
static inline struct V_1 * F_52 ( struct V_49 * V_50 ,
int V_114 ,
long V_115 )
{
struct V_1 * V_172 = V_50 -> V_1 ;
if ( ! V_172 )
return NULL ;
V_172 -> V_114 = V_114 ;
if ( F_2 ( V_115 <= - V_173 ) &&
( V_115 >= - V_174 ) &&
( V_115 != - V_175 ) )
V_172 -> V_115 = - V_176 ;
else
V_172 -> V_115 = V_115 ;
if ( V_172 -> V_177 && ! V_172 -> V_178 ) {
F_47 ( V_50 , V_172 , & V_179 [ V_180 ] ) ;
F_51 ( V_50 , V_172 ) ;
}
V_50 -> V_1 = NULL ;
return V_172 ;
}
static inline void F_53 ( struct V_1 * V_172 )
{
F_17 ( V_172 -> V_181 . V_182 ) ;
V_172 -> V_181 . V_182 = NULL ;
V_172 -> V_181 . V_183 = 0 ;
}
static inline void F_54 ( struct V_1 * V_172 )
{
struct V_20 * V_4 , * V_35 ;
#if V_184 == 2
if ( V_172 -> V_185 + V_172 -> V_186 != V_172 -> V_187 ) {
int V_89 = 0 ;
F_55 ( L_2
L_3
L_4 , __FILE__ , __LINE__ ,
V_172 -> V_188 , V_172 -> V_5 , V_172 -> V_177 ,
V_172 -> V_187 , V_172 -> V_185 ,
V_172 -> V_186 ) ;
F_7 (n, &context->names_list, list) {
F_55 ( L_5 , V_89 ++ , V_4 -> V_43 ,
V_4 -> V_43 -> V_43 ? : L_6 ) ;
}
F_56 () ;
return;
}
#endif
#if V_184
V_172 -> V_185 = 0 ;
V_172 -> V_186 = 0 ;
#endif
F_57 (n, next, &context->names_list, list) {
F_58 ( & V_4 -> V_167 ) ;
if ( V_4 -> V_43 && V_4 -> V_189 )
F_59 ( V_4 -> V_43 ) ;
if ( V_4 -> V_190 )
F_17 ( V_4 ) ;
}
V_172 -> V_187 = 0 ;
F_60 ( & V_172 -> V_191 ) ;
V_172 -> V_191 . V_192 = NULL ;
V_172 -> V_191 . V_193 = NULL ;
}
static inline void F_61 ( struct V_1 * V_172 )
{
struct V_194 * V_195 ;
while ( ( V_195 = V_172 -> V_195 ) ) {
V_172 -> V_195 = V_195 -> V_35 ;
F_17 ( V_195 ) ;
}
while ( ( V_195 = V_172 -> V_196 ) ) {
V_172 -> V_196 = V_195 -> V_35 ;
F_17 ( V_195 ) ;
}
}
static inline struct V_1 * F_62 ( enum V_86 V_87 )
{
struct V_1 * V_172 ;
V_172 = F_12 ( sizeof( * V_172 ) , V_36 ) ;
if ( ! V_172 )
return NULL ;
V_172 -> V_87 = V_87 ;
V_172 -> V_24 = V_87 == V_26 ? ~ 0ULL : 0 ;
F_63 ( & V_172 -> V_197 ) ;
F_63 ( & V_172 -> V_198 ) ;
return V_172 ;
}
int F_64 ( struct V_49 * V_50 )
{
struct V_1 * V_172 ;
enum V_86 V_87 ;
char * V_159 = NULL ;
if ( F_10 ( ! V_199 ) )
return 0 ;
V_87 = F_40 ( V_50 , & V_159 ) ;
if ( V_87 == V_157 ) {
F_65 ( V_50 , V_200 ) ;
return 0 ;
}
if ( ! ( V_172 = F_62 ( V_87 ) ) ) {
F_17 ( V_159 ) ;
F_66 ( L_7 ) ;
return - V_201 ;
}
V_172 -> V_153 = V_159 ;
V_50 -> V_1 = V_172 ;
F_67 ( V_50 , V_200 ) ;
return 0 ;
}
static inline void F_68 ( struct V_1 * V_172 )
{
F_54 ( V_172 ) ;
F_13 ( V_172 , NULL , 0 ) ;
F_16 ( V_172 ) ;
F_61 ( V_172 ) ;
F_17 ( V_172 -> V_153 ) ;
F_17 ( V_172 -> V_202 ) ;
F_53 ( V_172 ) ;
F_17 ( V_172 ) ;
}
static int F_69 ( struct V_1 * V_172 , T_5 V_96 ,
T_2 V_203 , T_2 V_42 , unsigned int V_204 ,
T_4 V_91 , char * V_205 )
{
struct V_206 * V_207 ;
char * V_2 = NULL ;
T_4 V_183 ;
int V_46 = 0 ;
V_207 = F_70 ( V_172 , V_36 , V_208 ) ;
if ( ! V_207 )
return V_46 ;
F_71 ( V_207 , L_8 , V_96 ,
F_72 ( & V_209 , V_203 ) ,
F_72 ( & V_209 , V_42 ) , V_204 ) ;
if ( V_91 ) {
if ( F_73 ( V_91 , & V_2 , & V_183 ) ) {
F_71 ( V_207 , L_9 ) ;
V_46 = 1 ;
} else {
F_71 ( V_207 , L_10 , V_2 ) ;
F_74 ( V_2 , V_183 ) ;
}
}
F_71 ( V_207 , L_11 ) ;
F_75 ( V_207 , V_205 ) ;
F_76 ( V_207 ) ;
return V_46 ;
}
static int F_77 ( struct V_1 * V_172 ,
struct V_206 * * V_207 ,
int V_210 ,
T_6 * V_211 ,
const char T_7 * V_30 ,
char * V_212 )
{
char V_213 [ 12 ] ;
const char T_7 * V_214 = V_30 ;
T_6 V_215 = snprintf ( V_213 , 12 , L_12 , V_210 ) + 5 ;
T_6 V_183 , V_216 , V_217 ;
T_6 V_218 = V_219 ;
unsigned int V_89 , V_220 = 0 , V_221 = 0 ;
int V_222 ;
V_216 = V_183 = F_78 ( V_30 , V_223 ) - 1 ;
if ( F_2 ( ( V_183 == - 1 ) || V_183 > V_223 - 1 ) ) {
F_79 ( 1 ) ;
F_80 ( V_224 , V_92 , 0 ) ;
return - 1 ;
}
do {
if ( V_216 > V_219 )
V_217 = V_219 ;
else
V_217 = V_216 ;
V_222 = F_81 ( V_212 , V_214 , V_217 ) ;
if ( V_222 ) {
F_79 ( 1 ) ;
F_80 ( V_224 , V_92 , 0 ) ;
return - 1 ;
}
V_212 [ V_217 ] = '\0' ;
V_220 = F_82 ( V_212 , V_217 ) ;
if ( V_220 ) {
V_218 = V_219 / 2 ;
break;
}
V_216 -= V_217 ;
V_214 += V_217 ;
} while ( V_216 > 0 );
V_216 = V_183 ;
if ( V_183 > V_218 )
V_221 = 1 ;
for ( V_89 = 0 ; V_216 > 0 ; V_89 ++ ) {
int V_225 ;
if ( V_216 > V_218 )
V_217 = V_218 ;
else
V_217 = V_216 ;
V_225 = V_219 - V_215 - * V_211 ;
if ( V_220 )
V_225 -= ( V_217 * 2 ) ;
else
V_225 -= V_217 ;
if ( V_225 < 0 ) {
* V_211 = 0 ;
F_76 ( * V_207 ) ;
* V_207 = F_70 ( V_172 , V_36 , V_226 ) ;
if ( ! * V_207 )
return 0 ;
}
if ( ( V_89 == 0 ) && ( V_221 ) )
F_71 ( * V_207 , L_13 , V_210 ,
V_220 ? 2 * V_183 : V_183 ) ;
if ( V_183 >= V_218 )
V_222 = F_81 ( V_212 , V_30 , V_217 ) ;
else
V_222 = 0 ;
if ( V_222 ) {
F_79 ( 1 ) ;
F_80 ( V_224 , V_92 , 0 ) ;
return - 1 ;
}
V_212 [ V_217 ] = '\0' ;
F_71 ( * V_207 , L_14 , V_210 ) ;
if ( V_221 )
F_71 ( * V_207 , L_15 , V_89 ) ;
F_71 ( * V_207 , L_16 ) ;
if ( V_220 )
F_83 ( * V_207 , V_212 , V_217 ) ;
else
F_84 ( * V_207 , V_212 ) ;
V_30 += V_217 ;
V_216 -= V_217 ;
* V_211 += V_215 ;
if ( V_220 )
* V_211 += V_217 * 2 ;
else
* V_211 += V_217 ;
}
return V_183 + 1 ;
}
static void F_85 ( struct V_1 * V_172 ,
struct V_206 * * V_207 )
{
int V_89 , V_183 ;
T_6 V_211 = 0 ;
const char T_7 * V_30 ;
char * V_212 ;
V_30 = ( const char T_7 * ) V_92 -> V_227 -> V_228 ;
F_71 ( * V_207 , L_17 , V_172 -> V_229 . V_230 ) ;
V_212 = F_86 ( V_219 + 1 , V_36 ) ;
if ( ! V_212 ) {
F_87 ( L_18 ) ;
return;
}
for ( V_89 = 0 ; V_89 < V_172 -> V_229 . V_230 ; V_89 ++ ) {
V_183 = F_77 ( V_172 , V_207 , V_89 ,
& V_211 , V_30 , V_212 ) ;
if ( V_183 <= 0 )
break;
V_30 += V_183 ;
}
F_17 ( V_212 ) ;
}
static void F_88 ( struct V_1 * V_172 , int * V_231 )
{
struct V_206 * V_207 ;
int V_89 ;
V_207 = F_70 ( V_172 , V_36 , V_172 -> type ) ;
if ( ! V_207 )
return;
switch ( V_172 -> type ) {
case V_232 : {
int V_233 = V_172 -> V_234 . V_233 ;
F_71 ( V_207 , L_19 , V_233 ) ;
for ( V_89 = 0 ; V_89 < V_233 ; V_89 ++ )
F_71 ( V_207 , L_20 , V_89 ,
V_172 -> V_234 . args [ V_89 ] ) ;
break; }
case V_143 : {
T_4 V_142 = V_172 -> V_144 . V_142 ;
F_71 ( V_207 , L_21 ,
F_72 ( & V_209 , V_172 -> V_144 . V_42 ) ,
F_89 ( & V_209 , V_172 -> V_144 . V_48 ) ,
V_172 -> V_144 . V_21 ) ;
if ( V_142 ) {
char * V_2 = NULL ;
T_4 V_183 ;
if ( F_73 ( V_142 , & V_2 , & V_183 ) ) {
F_71 ( V_207 , L_22 , V_142 ) ;
* V_231 = 1 ;
} else {
F_71 ( V_207 , L_10 , V_2 ) ;
F_74 ( V_2 , V_183 ) ;
}
}
if ( V_172 -> V_144 . V_235 ) {
F_76 ( V_207 ) ;
V_207 = F_70 ( V_172 , V_36 ,
V_236 ) ;
if ( F_2 ( ! V_207 ) )
return;
F_71 ( V_207 ,
L_23 ,
V_172 -> V_144 . V_237 ,
V_172 -> V_144 . V_238 ,
V_172 -> V_144 . V_239 ,
V_172 -> V_144 . V_240 ) ;
}
break; }
case V_241 : {
F_71 ( V_207 ,
L_24
L_25 ,
V_172 -> V_242 . V_243 , V_172 -> V_242 . V_21 ,
V_172 -> V_242 . V_244 . V_245 ,
V_172 -> V_242 . V_244 . V_246 ,
V_172 -> V_242 . V_244 . V_247 ,
V_172 -> V_242 . V_244 . V_248 ) ;
break; }
case V_249 : {
F_71 ( V_207 ,
L_26
L_27 ,
V_172 -> V_250 . V_251 ,
V_172 -> V_250 . V_252 ,
V_172 -> V_250 . V_253 ,
V_172 -> V_250 . V_254 . V_255 ,
V_172 -> V_250 . V_254 . V_256 ) ;
break; }
case V_257 : {
F_71 ( V_207 , L_28 ,
V_172 -> V_258 . V_251 ,
V_172 -> V_258 . V_259 ) ;
break; }
case V_260 : {
struct V_261 * V_244 = & V_172 -> V_262 . V_263 ;
F_71 ( V_207 ,
L_29
L_30 ,
V_172 -> V_262 . V_251 ,
V_244 -> V_245 , V_244 -> V_246 ,
V_244 -> V_247 , V_244 -> V_248 ) ;
break; }
case V_264 : {
F_71 ( V_207 , L_31 , V_172 -> V_265 . V_96 ) ;
F_90 ( V_207 , L_32 , & V_172 -> V_265 . V_266 . V_267 ) ;
F_90 ( V_207 , L_33 , & V_172 -> V_265 . V_266 . V_268 ) ;
F_90 ( V_207 , L_34 , & V_172 -> V_265 . V_266 . V_269 ) ;
break; }
case V_270 : {
F_71 ( V_207 , L_35 , V_172 -> V_271 . V_272 ,
V_172 -> V_271 . V_273 ) ;
break; }
case V_226 : {
F_85 ( V_172 , & V_207 ) ;
break; }
}
F_76 ( V_207 ) ;
}
static inline int F_91 ( char * V_181 , int V_183 )
{
char * V_274 = V_181 + V_183 - 1 ;
while ( V_274 > V_181 && ! isprint ( * V_274 ) )
V_274 -- ;
V_183 = V_274 - V_181 + 1 ;
V_183 -= isprint ( V_181 [ V_183 - 1 ] ) == 0 ;
return V_183 ;
}
static void F_92 ( struct V_49 * V_50 ,
struct V_1 * V_172 )
{
int V_275 ;
char * V_212 ;
char * V_276 = L_6 ;
int V_183 = strlen ( V_276 ) ;
struct V_206 * V_207 ;
V_207 = F_70 ( V_172 , V_36 , V_277 ) ;
if ( ! V_207 )
return;
F_71 ( V_207 , L_36 ) ;
if ( ! V_172 -> V_181 . V_182 ) {
V_212 = F_86 ( V_278 , V_36 ) ;
if ( ! V_212 )
goto V_279;
V_275 = F_93 ( V_50 , V_212 , V_278 ) ;
if ( V_275 == 0 ) {
F_17 ( V_212 ) ;
goto V_279;
}
V_275 = F_91 ( V_212 , V_275 ) ;
if ( V_275 == 0 ) {
F_17 ( V_212 ) ;
goto V_279;
}
V_172 -> V_181 . V_182 = V_212 ;
V_172 -> V_181 . V_183 = V_275 ;
}
V_276 = V_172 -> V_181 . V_182 ;
V_183 = V_172 -> V_181 . V_183 ;
V_279:
F_94 ( V_207 , V_276 , V_183 ) ;
F_76 ( V_207 ) ;
}
static void F_95 ( struct V_1 * V_172 , struct V_49 * V_50 )
{
int V_89 , V_231 = 0 ;
struct V_206 * V_207 ;
struct V_194 * V_195 ;
struct V_20 * V_4 ;
V_172 -> V_111 = V_50 -> V_111 ;
V_207 = F_70 ( V_172 , V_36 , V_280 ) ;
if ( ! V_207 )
return;
F_71 ( V_207 , L_37 ,
V_172 -> V_6 , V_172 -> V_5 ) ;
if ( V_172 -> V_111 != V_281 )
F_71 ( V_207 , L_38 , V_172 -> V_111 ) ;
if ( V_172 -> V_114 )
F_71 ( V_207 , L_39 ,
( V_172 -> V_114 == V_117 ) ? L_40 : L_41 ,
V_172 -> V_115 ) ;
F_71 ( V_207 ,
L_42 ,
V_172 -> V_16 [ 0 ] ,
V_172 -> V_16 [ 1 ] ,
V_172 -> V_16 [ 2 ] ,
V_172 -> V_16 [ 3 ] ,
V_172 -> V_187 ) ;
F_96 ( V_207 , V_50 ) ;
F_97 ( V_207 , V_172 -> V_153 ) ;
F_76 ( V_207 ) ;
for ( V_195 = V_172 -> V_195 ; V_195 ; V_195 = V_195 -> V_35 ) {
V_207 = F_70 ( V_172 , V_36 , V_195 -> type ) ;
if ( ! V_207 )
continue;
switch ( V_195 -> type ) {
case V_282 : {
struct V_283 * V_284 = ( void * ) V_195 ;
F_71 ( V_207 , L_43 , V_284 -> V_285 ) ;
F_90 ( V_207 , L_44 , & V_284 -> V_286 . V_268 ) ;
F_90 ( V_207 , L_45 , & V_284 -> V_286 . V_267 ) ;
F_71 ( V_207 , L_46 , V_284 -> V_286 . V_287 ) ;
F_90 ( V_207 , L_47 , & V_284 -> V_288 . V_268 ) ;
F_90 ( V_207 , L_48 , & V_284 -> V_288 . V_267 ) ;
F_90 ( V_207 , L_49 , & V_284 -> V_288 . V_269 ) ;
F_90 ( V_207 , L_50 , & V_284 -> V_289 . V_268 ) ;
F_90 ( V_207 , L_51 , & V_284 -> V_289 . V_267 ) ;
F_90 ( V_207 , L_52 , & V_284 -> V_289 . V_269 ) ;
break; }
}
F_76 ( V_207 ) ;
}
if ( V_172 -> type )
F_88 ( V_172 , & V_231 ) ;
if ( V_172 -> V_290 [ 0 ] >= 0 ) {
V_207 = F_70 ( V_172 , V_36 , V_291 ) ;
if ( V_207 ) {
F_71 ( V_207 , L_53 ,
V_172 -> V_290 [ 0 ] , V_172 -> V_290 [ 1 ] ) ;
F_76 ( V_207 ) ;
}
}
if ( V_172 -> V_292 ) {
V_207 = F_70 ( V_172 , V_36 , V_293 ) ;
if ( V_207 ) {
F_71 ( V_207 , L_54 ) ;
F_83 ( V_207 , ( void * ) V_172 -> V_202 ,
V_172 -> V_292 ) ;
F_76 ( V_207 ) ;
}
}
for ( V_195 = V_172 -> V_196 ; V_195 ; V_195 = V_195 -> V_35 ) {
struct V_294 * V_284 = ( void * ) V_195 ;
for ( V_89 = 0 ; V_89 < V_284 -> V_295 ; V_89 ++ )
if ( F_69 ( V_172 , V_284 -> V_296 [ V_89 ] ,
V_284 -> V_297 [ V_89 ] ,
V_284 -> V_298 [ V_89 ] ,
V_284 -> V_299 [ V_89 ] ,
V_284 -> V_300 [ V_89 ] ,
V_284 -> V_301 [ V_89 ] ) )
V_231 = 1 ;
}
if ( V_172 -> V_296 &&
F_69 ( V_172 , V_172 -> V_296 ,
V_172 -> V_297 , V_172 -> V_298 ,
V_172 -> V_299 ,
V_172 -> V_300 , V_172 -> V_301 ) )
V_231 = 1 ;
if ( V_172 -> V_191 . V_192 && V_172 -> V_191 . V_193 ) {
V_207 = F_70 ( V_172 , V_36 , V_302 ) ;
if ( V_207 ) {
F_98 ( V_207 , L_55 , & V_172 -> V_191 ) ;
F_76 ( V_207 ) ;
}
}
V_89 = 0 ;
F_7 (n, &context->names_list, list) {
if ( V_4 -> V_303 )
continue;
F_99 ( V_172 , V_4 , NULL , V_89 ++ , & V_231 ) ;
}
F_92 ( V_50 , V_172 ) ;
V_207 = F_70 ( V_172 , V_36 , V_304 ) ;
if ( V_207 )
F_76 ( V_207 ) ;
if ( V_231 )
F_87 ( L_56 ) ;
}
void F_100 ( struct V_49 * V_50 )
{
struct V_1 * V_172 ;
V_172 = F_52 ( V_50 , 0 , 0 ) ;
if ( ! V_172 )
return;
if ( V_172 -> V_177 && V_172 -> V_25 == V_26 )
F_95 ( V_172 , V_50 ) ;
if ( ! F_48 ( & V_172 -> V_197 ) )
F_101 ( & V_172 -> V_197 ) ;
F_68 ( V_172 ) ;
}
void F_102 ( int V_5 , unsigned long V_305 , unsigned long V_306 ,
unsigned long V_307 , unsigned long V_308 )
{
struct V_49 * V_50 = V_92 ;
struct V_1 * V_172 = V_50 -> V_1 ;
enum V_86 V_87 ;
if ( ! V_172 )
return;
F_103 ( V_172 -> V_177 || V_172 -> V_187 ) ;
if ( ! V_309 )
return;
V_172 -> V_6 = F_104 () ;
V_172 -> V_5 = V_5 ;
V_172 -> V_16 [ 0 ] = V_305 ;
V_172 -> V_16 [ 1 ] = V_306 ;
V_172 -> V_16 [ 2 ] = V_307 ;
V_172 -> V_16 [ 3 ] = V_308 ;
V_87 = V_172 -> V_87 ;
V_172 -> V_178 = ! V_310 ;
if ( ! V_172 -> V_178 && V_87 == V_162 ) {
V_172 -> V_24 = 0 ;
V_87 = F_47 ( V_50 , V_172 , & V_179 [ V_311 ] ) ;
}
if ( V_87 == V_157 )
return;
V_172 -> V_188 = 0 ;
V_172 -> ctime = V_312 ;
V_172 -> V_177 = 1 ;
V_172 -> V_25 = V_87 ;
V_172 -> V_99 = 0 ;
}
void F_105 ( int V_313 , long V_115 )
{
struct V_49 * V_50 = V_92 ;
struct V_1 * V_172 ;
if ( V_313 )
V_313 = V_117 ;
else
V_313 = V_118 ;
V_172 = F_52 ( V_50 , V_313 , V_115 ) ;
if ( ! V_172 )
return;
if ( V_172 -> V_177 && V_172 -> V_25 == V_26 )
F_95 ( V_172 , V_50 ) ;
V_172 -> V_177 = 0 ;
V_172 -> V_24 = V_172 -> V_87 == V_26 ? ~ 0ULL : 0 ;
if ( ! F_48 ( & V_172 -> V_197 ) )
F_101 ( & V_172 -> V_197 ) ;
F_54 ( V_172 ) ;
F_13 ( V_172 , NULL , 0 ) ;
F_61 ( V_172 ) ;
V_172 -> V_195 = NULL ;
V_172 -> V_196 = NULL ;
V_172 -> V_296 = 0 ;
V_172 -> V_300 = 0 ;
V_172 -> V_292 = 0 ;
V_172 -> type = 0 ;
V_172 -> V_290 [ 0 ] = - 1 ;
if ( V_172 -> V_87 != V_26 ) {
F_17 ( V_172 -> V_153 ) ;
V_172 -> V_153 = NULL ;
}
V_50 -> V_1 = V_172 ;
}
static inline void F_106 ( const struct V_314 * V_314 )
{
#ifdef F_14
struct V_1 * V_172 ;
struct V_29 * V_30 ;
struct V_27 * V_28 ;
int V_38 ;
if ( F_10 ( F_107 ( & V_314 -> V_315 ) ) )
return;
V_172 = V_92 -> V_1 ;
V_30 = V_172 -> V_31 ;
V_38 = V_172 -> V_33 ;
F_41 () ;
V_28 = F_108 ( V_314 ) ;
F_43 () ;
if ( ! V_28 )
return;
if ( F_10 ( F_9 ( V_172 , V_28 ) ) )
return;
if ( F_2 ( ! F_11 ( V_172 ) ) ) {
F_109 ( L_57 ) ;
F_8 ( V_172 ) ;
F_15 ( V_28 ) ;
F_13 ( V_172 , V_30 , V_38 ) ;
return;
}
F_9 ( V_172 , V_28 ) ;
#endif
}
static void F_110 ( const struct V_192 * V_192 )
{
#ifdef F_14
struct V_1 * V_172 ;
struct V_29 * V_30 ;
const struct V_192 * V_316 , * V_317 ;
struct V_27 * V_318 ;
unsigned long V_319 ;
int V_38 ;
V_172 = V_92 -> V_1 ;
V_30 = V_172 -> V_31 ;
V_38 = V_172 -> V_33 ;
V_320:
V_318 = NULL ;
V_316 = V_192 ;
F_41 () ;
V_319 = F_111 ( & V_321 ) ;
for(; ; ) {
struct V_314 * V_314 = V_316 -> V_322 ;
if ( V_314 && F_2 ( ! F_107 ( & V_314 -> V_315 ) ) ) {
struct V_27 * V_28 ;
V_28 = F_108 ( V_314 ) ;
if ( V_28 ) {
if ( F_2 ( ! F_9 ( V_172 , V_28 ) ) ) {
V_318 = V_28 ;
break;
}
}
}
V_317 = V_316 -> V_323 ;
if ( V_317 == V_316 )
break;
V_316 = V_317 ;
}
if ( F_2 ( F_112 ( & V_321 , V_319 ) || V_318 ) ) {
F_43 () ;
if ( ! V_318 ) {
F_13 ( V_172 , V_30 , V_38 ) ;
goto V_320;
}
F_15 ( V_318 ) ;
if ( F_11 ( V_172 ) ) {
F_13 ( V_172 , V_30 , V_38 ) ;
goto V_320;
}
F_109 ( L_57 ) ;
F_13 ( V_172 , V_30 , V_38 ) ;
F_8 ( V_172 ) ;
return;
}
F_43 () ;
#endif
}
static struct V_20 * F_113 ( struct V_1 * V_172 ,
unsigned char type )
{
struct V_20 * V_324 ;
if ( V_172 -> V_187 < V_325 ) {
V_324 = & V_172 -> V_326 [ V_172 -> V_187 ] ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
} else {
V_324 = F_12 ( sizeof( * V_324 ) , V_327 ) ;
if ( ! V_324 )
return NULL ;
V_324 -> V_190 = true ;
}
V_324 -> V_22 = ( unsigned long ) - 1 ;
V_324 -> type = type ;
F_114 ( & V_324 -> V_167 , & V_172 -> V_198 ) ;
V_172 -> V_187 ++ ;
#if V_184
V_172 -> V_186 ++ ;
#endif
return V_324 ;
}
struct V_328 *
F_115 ( const T_7 char * V_329 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_20 * V_4 ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 )
continue;
if ( V_4 -> V_43 -> V_329 == V_329 )
return V_4 -> V_43 ;
}
return NULL ;
}
void F_116 ( struct V_328 * V_43 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_20 * V_4 ;
if ( ! V_172 -> V_177 ) {
#if V_184 == 2
F_55 ( L_58 ,
__FILE__ , __LINE__ , V_172 -> V_188 , V_43 ) ;
F_56 () ;
#endif
return;
}
#if V_184
F_103 ( ! V_43 -> V_43 ) ;
#endif
V_4 = F_113 ( V_172 , V_330 ) ;
if ( ! V_4 )
return;
V_4 -> V_43 = V_43 ;
V_4 -> V_331 = V_332 ;
V_4 -> V_189 = true ;
V_43 -> V_324 = V_4 ;
if ( ! V_172 -> V_191 . V_192 )
F_117 ( V_92 -> V_333 , & V_172 -> V_191 ) ;
}
void F_118 ( struct V_328 * V_43 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
F_103 ( ! V_172 ) ;
if ( ! V_43 -> V_324 || ! V_172 -> V_177 ) {
#if V_184 == 2
F_55 ( L_59 ,
__FILE__ , __LINE__ , V_172 -> V_188 , V_43 ) ;
if ( V_172 -> V_187 ) {
struct V_20 * V_4 ;
int V_89 = 0 ;
F_7 (n, &context->names_list, list)
F_55 ( L_60 , V_89 ++ , V_4 -> V_43 ,
V_4 -> V_43 -> V_43 ? : L_6 ) ;
}
#endif
F_59 ( V_43 ) ;
}
#if V_184
else {
++ V_172 -> V_185 ;
if ( V_172 -> V_185 > V_172 -> V_187 ) {
F_55 ( L_61
L_62 ,
__FILE__ , __LINE__ ,
V_172 -> V_188 , V_172 -> V_5 ,
V_172 -> V_177 , V_43 -> V_43 ,
V_172 -> V_187 , V_172 -> V_185 ) ;
F_56 () ;
}
}
#endif
}
void F_119 ( struct V_328 * V_43 , const struct V_192 * V_192 ,
unsigned int V_273 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
const struct V_314 * V_314 = V_192 -> V_322 ;
struct V_20 * V_4 ;
bool V_317 = V_273 & V_334 ;
if ( ! V_172 -> V_177 )
return;
if ( ! V_43 )
goto V_335;
#if V_184
F_103 ( ! V_43 -> V_43 ) ;
#endif
V_4 = V_43 -> V_324 ;
if ( V_4 ) {
if ( V_317 ) {
if ( V_4 -> type == V_336 ||
V_4 -> type == V_330 )
goto V_279;
} else {
if ( V_4 -> type != V_336 )
goto V_279;
}
}
F_120 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 || V_4 -> V_43 -> V_43 != V_43 -> V_43 )
continue;
if ( V_317 ) {
if ( V_4 -> type == V_336 ||
V_4 -> type == V_330 )
goto V_279;
} else {
if ( V_4 -> type != V_336 )
goto V_279;
}
}
V_335:
V_4 = F_113 ( V_172 , V_337 ) ;
if ( ! V_4 )
return;
V_279:
if ( V_317 ) {
V_4 -> V_331 = V_4 -> V_43 ? F_121 ( V_4 -> V_43 -> V_43 ) : V_332 ;
V_4 -> type = V_336 ;
if ( V_273 & V_338 )
V_4 -> V_303 = true ;
} else {
V_4 -> V_331 = V_332 ;
V_4 -> type = V_337 ;
}
F_110 ( V_192 ) ;
F_122 ( V_4 , V_192 , V_314 ) ;
}
void F_123 ( const struct V_314 * V_317 ,
const struct V_192 * V_192 ,
const unsigned char type )
{
struct V_1 * V_172 = V_92 -> V_1 ;
const struct V_314 * V_314 = V_192 -> V_322 ;
const char * V_339 = V_192 -> V_340 . V_43 ;
struct V_20 * V_4 , * V_341 = NULL , * V_342 = NULL ;
if ( ! V_172 -> V_177 )
return;
if ( V_314 )
F_106 ( V_314 ) ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 || V_4 -> type != V_336 )
continue;
if ( V_4 -> V_22 == V_317 -> V_343 &&
! F_124 ( V_339 , V_4 -> V_43 -> V_43 , V_4 -> V_331 ) ) {
V_341 = V_4 ;
break;
}
}
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 || V_4 -> type != type )
continue;
if ( V_341 && ( V_4 -> V_43 != V_341 -> V_43 ) )
continue;
if ( ! strcmp ( V_339 , V_4 -> V_43 -> V_43 ) ||
! F_124 ( V_339 , V_4 -> V_43 -> V_43 ,
V_341 ?
V_341 -> V_331 :
V_332 ) ) {
V_342 = V_4 ;
break;
}
}
if ( ! V_341 ) {
V_4 = F_113 ( V_172 , V_336 ) ;
if ( ! V_4 )
return;
F_122 ( V_4 , NULL , V_317 ) ;
}
if ( ! V_342 ) {
V_342 = F_113 ( V_172 , type ) ;
if ( ! V_342 )
return;
if ( V_341 ) {
V_342 -> V_43 = V_341 -> V_43 ;
V_342 -> V_331 = V_332 ;
V_342 -> V_189 = false ;
}
}
if ( V_314 )
F_122 ( V_342 , V_192 , V_314 ) ;
else
V_342 -> V_22 = ( unsigned long ) - 1 ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_344 * V_345 , unsigned int * V_188 )
{
if ( ! V_2 -> V_177 )
return 0 ;
if ( ! V_2 -> V_188 )
V_2 -> V_188 = F_126 () ;
V_345 -> V_255 = V_2 -> ctime . V_255 ;
V_345 -> V_256 = V_2 -> ctime . V_256 ;
* V_188 = V_2 -> V_188 ;
if ( ! V_2 -> V_24 ) {
V_2 -> V_24 = 1 ;
V_2 -> V_25 = V_26 ;
}
return 1 ;
}
static int F_127 ( T_2 V_59 )
{
if ( ! F_36 ( V_92 ) )
return 0 ;
if ( F_128 ( V_346 ) )
return - V_347 ;
if ( ! F_129 ( V_348 ) )
return - V_347 ;
if ( F_128 ( V_349 ) && F_130 ( V_59 ) )
return - V_347 ;
return 0 ;
}
static void F_131 ( T_2 V_350 , T_2 V_351 ,
unsigned int V_352 , unsigned int V_204 ,
int V_46 )
{
struct V_206 * V_207 ;
T_8 V_42 , V_353 , V_59 ;
if ( ! V_309 )
return;
V_42 = F_72 ( & V_209 , F_132 ( V_92 ) ) ;
V_353 = F_72 ( & V_209 , V_350 ) ;
V_59 = F_72 ( & V_209 , V_351 ) ,
V_207 = F_70 ( NULL , V_36 , V_354 ) ;
if ( ! V_207 )
return;
F_71 ( V_207 , L_63 , F_28 ( V_92 ) , V_42 ) ;
F_133 ( V_207 ) ;
F_71 ( V_207 , L_64 ,
V_353 , V_59 , V_352 , V_204 , ! V_46 ) ;
F_76 ( V_207 ) ;
}
int F_134 ( T_2 V_59 )
{
struct V_49 * V_355 = V_92 ;
unsigned int V_352 , V_204 = ( unsigned int ) - 1 ;
T_2 V_353 ;
int V_46 ;
V_353 = F_135 ( V_92 ) ;
V_352 = F_136 ( V_92 ) ;
V_46 = F_127 ( V_59 ) ;
if ( V_46 )
goto V_279;
if ( F_130 ( V_59 ) )
V_204 = ( unsigned int ) F_137 ( & V_356 ) ;
V_355 -> V_204 = V_204 ;
V_355 -> V_59 = V_59 ;
V_279:
F_131 ( V_353 , V_59 , V_352 , V_204 , V_46 ) ;
return V_46 ;
}
void F_138 ( int V_243 , T_1 V_21 , struct V_261 * V_244 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( V_244 )
memcpy ( & V_172 -> V_242 . V_244 , V_244 , sizeof( struct V_261 ) ) ;
else
memset ( & V_172 -> V_242 . V_244 , 0 , sizeof( struct V_261 ) ) ;
V_172 -> V_242 . V_243 = V_243 ;
V_172 -> V_242 . V_21 = V_21 ;
V_172 -> type = V_241 ;
}
void F_139 ( T_9 V_251 , T_6 V_252 , unsigned int V_253 ,
const struct V_344 * V_254 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_344 * V_30 = & V_172 -> V_250 . V_254 ;
if ( V_254 )
memcpy ( V_30 , V_254 , sizeof( struct V_344 ) ) ;
else
memset ( V_30 , 0 , sizeof( struct V_344 ) ) ;
V_172 -> V_250 . V_251 = V_251 ;
V_172 -> V_250 . V_252 = V_252 ;
V_172 -> V_250 . V_253 = V_253 ;
V_172 -> type = V_249 ;
}
void F_140 ( T_9 V_251 , const struct V_357 * V_358 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( V_358 )
V_172 -> V_258 . V_259 = V_358 -> V_259 ;
else
V_172 -> V_258 . V_259 = 0 ;
V_172 -> V_258 . V_251 = V_251 ;
V_172 -> type = V_257 ;
}
void F_141 ( T_9 V_251 , struct V_261 * V_263 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_262 . V_251 = V_251 ;
V_172 -> V_262 . V_263 = * V_263 ;
V_172 -> type = V_260 ;
}
void F_142 ( struct V_359 * V_360 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_144 . V_42 = V_360 -> V_42 ;
V_172 -> V_144 . V_48 = V_360 -> V_48 ;
V_172 -> V_144 . V_21 = V_360 -> V_21 ;
V_172 -> V_144 . V_235 = 0 ;
F_143 ( V_360 , & V_172 -> V_144 . V_142 ) ;
V_172 -> type = V_143 ;
}
void F_144 ( unsigned long V_237 , T_8 V_42 , T_10 V_48 , T_1 V_21 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_144 . V_237 = V_237 ;
V_172 -> V_144 . V_238 = V_42 ;
V_172 -> V_144 . V_239 = V_48 ;
V_172 -> V_144 . V_240 = V_21 ;
V_172 -> V_144 . V_235 = 1 ;
}
void F_145 ( struct V_361 * V_362 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> type = V_226 ;
V_172 -> V_229 . V_230 = V_362 -> V_230 ;
}
int F_146 ( int V_233 , unsigned long * args )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( V_233 <= 0 || V_233 > V_363 || ! args )
return - V_364 ;
V_172 -> type = V_232 ;
V_172 -> V_234 . V_233 = V_233 ;
memcpy ( V_172 -> V_234 . args , args , V_233 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_147 ( int V_365 , int V_366 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_290 [ 0 ] = V_365 ;
V_172 -> V_290 [ 1 ] = V_366 ;
}
int F_148 ( int V_183 , void * V_367 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( ! V_172 -> V_202 ) {
void * V_30 = F_86 ( sizeof( struct V_368 ) , V_36 ) ;
if ( ! V_30 )
return - V_201 ;
V_172 -> V_202 = V_30 ;
}
V_172 -> V_292 = V_183 ;
memcpy ( V_172 -> V_202 , V_367 , V_183 ) ;
return 0 ;
}
void F_149 ( struct V_49 * V_345 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_296 = F_28 ( V_345 ) ;
V_172 -> V_297 = F_135 ( V_345 ) ;
V_172 -> V_298 = F_132 ( V_345 ) ;
V_172 -> V_299 = F_136 ( V_345 ) ;
F_37 ( V_345 , & V_172 -> V_300 ) ;
memcpy ( V_172 -> V_301 , V_345 -> V_205 , V_369 ) ;
}
int F_150 ( int V_370 , struct V_49 * V_345 )
{
struct V_294 * V_371 ;
struct V_49 * V_50 = V_92 ;
struct V_1 * V_2 = V_50 -> V_1 ;
T_2 V_42 = F_151 () , V_372 = F_132 ( V_345 ) ;
if ( V_168 && V_345 -> V_169 == V_168 ) {
if ( V_370 == V_373 || V_370 == V_374 || V_370 == V_375 || V_370 == V_376 ) {
V_377 = F_28 ( V_50 ) ;
if ( F_130 ( V_50 -> V_59 ) )
V_378 = V_50 -> V_59 ;
else
V_378 = V_42 ;
F_37 ( V_50 , & V_379 ) ;
}
if ( ! V_380 || F_152 () )
return 0 ;
}
if ( ! V_2 -> V_296 ) {
V_2 -> V_296 = F_153 ( V_345 ) ;
V_2 -> V_297 = F_135 ( V_345 ) ;
V_2 -> V_298 = V_372 ;
V_2 -> V_299 = F_136 ( V_345 ) ;
F_37 ( V_345 , & V_2 -> V_300 ) ;
memcpy ( V_2 -> V_301 , V_345 -> V_205 , V_369 ) ;
return 0 ;
}
V_371 = ( void * ) V_2 -> V_196 ;
if ( ! V_371 || V_371 -> V_295 == V_381 ) {
V_371 = F_12 ( sizeof( * V_371 ) , V_154 ) ;
if ( ! V_371 )
return - V_201 ;
V_371 -> V_316 . type = V_208 ;
V_371 -> V_316 . V_35 = V_2 -> V_196 ;
V_2 -> V_196 = ( void * ) V_371 ;
}
F_103 ( V_371 -> V_295 >= V_381 ) ;
V_371 -> V_296 [ V_371 -> V_295 ] = F_153 ( V_345 ) ;
V_371 -> V_297 [ V_371 -> V_295 ] = F_135 ( V_345 ) ;
V_371 -> V_298 [ V_371 -> V_295 ] = V_372 ;
V_371 -> V_299 [ V_371 -> V_295 ] = F_136 ( V_345 ) ;
F_37 ( V_345 , & V_371 -> V_300 [ V_371 -> V_295 ] ) ;
memcpy ( V_371 -> V_301 [ V_371 -> V_295 ] , V_345 -> V_205 , V_369 ) ;
V_371 -> V_295 ++ ;
return 0 ;
}
int F_154 ( struct V_361 * V_362 ,
const struct V_51 * V_382 , const struct V_51 * V_383 )
{
struct V_283 * V_384 ;
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_385 V_386 ;
struct V_192 * V_192 ;
V_384 = F_86 ( sizeof( * V_384 ) , V_36 ) ;
if ( ! V_384 )
return - V_201 ;
V_384 -> V_316 . type = V_282 ;
V_384 -> V_316 . V_35 = V_172 -> V_195 ;
V_172 -> V_195 = ( void * ) V_384 ;
V_192 = F_155 ( V_362 -> V_387 -> V_388 ) ;
F_156 ( V_192 , & V_386 ) ;
F_157 ( V_192 ) ;
V_384 -> V_286 . V_268 = V_386 . V_268 ;
V_384 -> V_286 . V_267 = V_386 . V_267 ;
V_384 -> V_286 . V_287 = ! ! ( V_386 . V_389 & V_390 ) ;
V_384 -> V_285 = ( V_386 . V_389 & V_391 ) >> V_392 ;
V_384 -> V_288 . V_268 = V_383 -> V_393 ;
V_384 -> V_288 . V_267 = V_383 -> V_394 ;
V_384 -> V_288 . V_269 = V_383 -> V_395 ;
V_384 -> V_289 . V_268 = V_382 -> V_393 ;
V_384 -> V_289 . V_267 = V_382 -> V_394 ;
V_384 -> V_289 . V_269 = V_382 -> V_395 ;
return 0 ;
}
void F_158 ( const struct V_51 * V_382 , const struct V_51 * V_383 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_265 . V_96 = F_28 ( V_92 ) ;
V_172 -> V_265 . V_266 . V_269 = V_382 -> V_395 ;
V_172 -> V_265 . V_266 . V_267 = V_382 -> V_395 ;
V_172 -> V_265 . V_266 . V_268 = V_382 -> V_393 ;
V_172 -> type = V_264 ;
}
void F_159 ( int V_272 , int V_273 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_271 . V_272 = V_272 ;
V_172 -> V_271 . V_273 = V_273 ;
V_172 -> type = V_270 ;
}
static void F_160 ( struct V_206 * V_207 )
{
T_2 V_203 , V_42 ;
T_3 V_48 ;
unsigned int V_204 ;
struct V_396 * V_227 = V_92 -> V_227 ;
char V_205 [ sizeof( V_92 -> V_205 ) ] ;
V_203 = F_135 ( V_92 ) ;
V_204 = F_136 ( V_92 ) ;
F_161 ( & V_42 , & V_48 ) ;
F_71 ( V_207 , L_65 ,
F_72 ( & V_209 , V_203 ) ,
F_72 ( & V_209 , V_42 ) ,
F_89 ( & V_209 , V_48 ) ,
V_204 ) ;
F_133 ( V_207 ) ;
F_71 ( V_207 , L_66 , F_28 ( V_92 ) ) ;
F_75 ( V_207 , F_162 ( V_205 , V_92 ) ) ;
if ( V_227 ) {
F_163 ( & V_227 -> V_397 ) ;
if ( V_227 -> V_398 )
F_98 ( V_207 , L_67 , & V_227 -> V_398 -> V_399 ) ;
F_164 ( & V_227 -> V_397 ) ;
} else
F_71 ( V_207 , L_68 ) ;
}
void F_165 ( long V_400 )
{
struct V_206 * V_207 ;
if ( ! V_309 )
return;
if ( V_400 == V_401 )
return;
V_207 = F_70 ( NULL , V_36 , V_402 ) ;
if ( F_2 ( ! V_207 ) )
return;
F_160 ( V_207 ) ;
F_71 ( V_207 , L_69 , V_400 ) ;
F_76 ( V_207 ) ;
}
void F_166 ( unsigned long V_403 , long V_400 , int V_404 )
{
struct V_206 * V_207 ;
V_207 = F_70 ( NULL , V_36 , V_405 ) ;
if ( F_2 ( ! V_207 ) )
return;
F_160 ( V_207 ) ;
F_71 ( V_207 , L_70 ,
V_400 , F_104 () , V_403 , F_167 () ,
F_168 ( V_92 ) , V_404 ) ;
F_76 ( V_207 ) ;
}
struct V_166 * F_169 ( void )
{
struct V_1 * V_2 = V_92 -> V_1 ;
if ( F_10 ( ! V_2 || ! V_2 -> V_177 ) )
return NULL ;
return & V_2 -> V_197 ;
}
