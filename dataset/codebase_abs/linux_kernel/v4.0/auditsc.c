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
F_55 (n, next, &context->names_list, list) {
F_56 ( & V_4 -> V_167 ) ;
if ( V_4 -> V_43 )
F_57 ( V_4 -> V_43 ) ;
if ( V_4 -> V_184 )
F_17 ( V_4 ) ;
}
V_172 -> V_185 = 0 ;
F_58 ( & V_172 -> V_186 ) ;
V_172 -> V_186 . V_187 = NULL ;
V_172 -> V_186 . V_188 = NULL ;
}
static inline void F_59 ( struct V_1 * V_172 )
{
struct V_189 * V_190 ;
while ( ( V_190 = V_172 -> V_190 ) ) {
V_172 -> V_190 = V_190 -> V_35 ;
F_17 ( V_190 ) ;
}
while ( ( V_190 = V_172 -> V_191 ) ) {
V_172 -> V_191 = V_190 -> V_35 ;
F_17 ( V_190 ) ;
}
}
static inline struct V_1 * F_60 ( enum V_86 V_87 )
{
struct V_1 * V_172 ;
V_172 = F_12 ( sizeof( * V_172 ) , V_36 ) ;
if ( ! V_172 )
return NULL ;
V_172 -> V_87 = V_87 ;
V_172 -> V_24 = V_87 == V_26 ? ~ 0ULL : 0 ;
F_61 ( & V_172 -> V_192 ) ;
F_61 ( & V_172 -> V_193 ) ;
return V_172 ;
}
int F_62 ( struct V_49 * V_50 )
{
struct V_1 * V_172 ;
enum V_86 V_87 ;
char * V_159 = NULL ;
if ( F_10 ( ! V_194 ) )
return 0 ;
V_87 = F_40 ( V_50 , & V_159 ) ;
if ( V_87 == V_157 ) {
F_63 ( V_50 , V_195 ) ;
return 0 ;
}
if ( ! ( V_172 = F_60 ( V_87 ) ) ) {
F_17 ( V_159 ) ;
F_64 ( L_2 ) ;
return - V_196 ;
}
V_172 -> V_153 = V_159 ;
V_50 -> V_1 = V_172 ;
F_65 ( V_50 , V_195 ) ;
return 0 ;
}
static inline void F_66 ( struct V_1 * V_172 )
{
F_54 ( V_172 ) ;
F_13 ( V_172 , NULL , 0 ) ;
F_16 ( V_172 ) ;
F_59 ( V_172 ) ;
F_17 ( V_172 -> V_153 ) ;
F_17 ( V_172 -> V_197 ) ;
F_53 ( V_172 ) ;
F_17 ( V_172 ) ;
}
static int F_67 ( struct V_1 * V_172 , T_5 V_96 ,
T_2 V_198 , T_2 V_42 , unsigned int V_199 ,
T_4 V_91 , char * V_200 )
{
struct V_201 * V_202 ;
char * V_2 = NULL ;
T_4 V_183 ;
int V_46 = 0 ;
V_202 = F_68 ( V_172 , V_36 , V_203 ) ;
if ( ! V_202 )
return V_46 ;
F_69 ( V_202 , L_3 , V_96 ,
F_70 ( & V_204 , V_198 ) ,
F_70 ( & V_204 , V_42 ) , V_199 ) ;
if ( V_91 ) {
if ( F_71 ( V_91 , & V_2 , & V_183 ) ) {
F_69 ( V_202 , L_4 ) ;
V_46 = 1 ;
} else {
F_69 ( V_202 , L_5 , V_2 ) ;
F_72 ( V_2 , V_183 ) ;
}
}
F_69 ( V_202 , L_6 ) ;
F_73 ( V_202 , V_200 ) ;
F_74 ( V_202 ) ;
return V_46 ;
}
static int F_75 ( struct V_1 * V_172 ,
struct V_201 * * V_202 ,
int V_205 ,
T_6 * V_206 ,
const char T_7 * V_30 ,
char * V_207 )
{
char V_208 [ 12 ] ;
const char T_7 * V_209 = V_30 ;
T_6 V_210 = snprintf ( V_208 , 12 , L_7 , V_205 ) + 5 ;
T_6 V_183 , V_211 , V_212 ;
T_6 V_213 = V_214 ;
unsigned int V_89 , V_215 = 0 , V_216 = 0 ;
int V_217 ;
V_211 = V_183 = F_76 ( V_30 , V_218 ) - 1 ;
if ( F_2 ( ( V_183 == - 1 ) || V_183 > V_218 - 1 ) ) {
F_77 ( 1 ) ;
F_78 ( V_219 , V_92 , 0 ) ;
return - 1 ;
}
do {
if ( V_211 > V_214 )
V_212 = V_214 ;
else
V_212 = V_211 ;
V_217 = F_79 ( V_207 , V_209 , V_212 ) ;
if ( V_217 ) {
F_77 ( 1 ) ;
F_78 ( V_219 , V_92 , 0 ) ;
return - 1 ;
}
V_207 [ V_212 ] = '\0' ;
V_215 = F_80 ( V_207 , V_212 ) ;
if ( V_215 ) {
V_213 = V_214 / 2 ;
break;
}
V_211 -= V_212 ;
V_209 += V_212 ;
} while ( V_211 > 0 );
V_211 = V_183 ;
if ( V_183 > V_213 )
V_216 = 1 ;
for ( V_89 = 0 ; V_211 > 0 ; V_89 ++ ) {
int V_220 ;
if ( V_211 > V_213 )
V_212 = V_213 ;
else
V_212 = V_211 ;
V_220 = V_214 - V_210 - * V_206 ;
if ( V_215 )
V_220 -= ( V_212 * 2 ) ;
else
V_220 -= V_212 ;
if ( V_220 < 0 ) {
* V_206 = 0 ;
F_74 ( * V_202 ) ;
* V_202 = F_68 ( V_172 , V_36 , V_221 ) ;
if ( ! * V_202 )
return 0 ;
}
if ( ( V_89 == 0 ) && ( V_216 ) )
F_69 ( * V_202 , L_8 , V_205 ,
V_215 ? 2 * V_183 : V_183 ) ;
if ( V_183 >= V_213 )
V_217 = F_79 ( V_207 , V_30 , V_212 ) ;
else
V_217 = 0 ;
if ( V_217 ) {
F_77 ( 1 ) ;
F_78 ( V_219 , V_92 , 0 ) ;
return - 1 ;
}
V_207 [ V_212 ] = '\0' ;
F_69 ( * V_202 , L_9 , V_205 ) ;
if ( V_216 )
F_69 ( * V_202 , L_10 , V_89 ) ;
F_69 ( * V_202 , L_11 ) ;
if ( V_215 )
F_81 ( * V_202 , V_207 , V_212 ) ;
else
F_82 ( * V_202 , V_207 ) ;
V_30 += V_212 ;
V_211 -= V_212 ;
* V_206 += V_210 ;
if ( V_215 )
* V_206 += V_212 * 2 ;
else
* V_206 += V_212 ;
}
return V_183 + 1 ;
}
static void F_83 ( struct V_1 * V_172 ,
struct V_201 * * V_202 )
{
int V_89 , V_183 ;
T_6 V_206 = 0 ;
const char T_7 * V_30 ;
char * V_207 ;
V_30 = ( const char T_7 * ) V_92 -> V_222 -> V_223 ;
F_69 ( * V_202 , L_12 , V_172 -> V_224 . V_225 ) ;
V_207 = F_84 ( V_214 + 1 , V_36 ) ;
if ( ! V_207 ) {
F_85 ( L_13 ) ;
return;
}
for ( V_89 = 0 ; V_89 < V_172 -> V_224 . V_225 ; V_89 ++ ) {
V_183 = F_75 ( V_172 , V_202 , V_89 ,
& V_206 , V_30 , V_207 ) ;
if ( V_183 <= 0 )
break;
V_30 += V_183 ;
}
F_17 ( V_207 ) ;
}
static void F_86 ( struct V_1 * V_172 , int * V_226 )
{
struct V_201 * V_202 ;
int V_89 ;
V_202 = F_68 ( V_172 , V_36 , V_172 -> type ) ;
if ( ! V_202 )
return;
switch ( V_172 -> type ) {
case V_227 : {
int V_228 = V_172 -> V_229 . V_228 ;
F_69 ( V_202 , L_14 , V_228 ) ;
for ( V_89 = 0 ; V_89 < V_228 ; V_89 ++ )
F_69 ( V_202 , L_15 , V_89 ,
V_172 -> V_229 . args [ V_89 ] ) ;
break; }
case V_143 : {
T_4 V_142 = V_172 -> V_144 . V_142 ;
F_69 ( V_202 , L_16 ,
F_70 ( & V_204 , V_172 -> V_144 . V_42 ) ,
F_87 ( & V_204 , V_172 -> V_144 . V_48 ) ,
V_172 -> V_144 . V_21 ) ;
if ( V_142 ) {
char * V_2 = NULL ;
T_4 V_183 ;
if ( F_71 ( V_142 , & V_2 , & V_183 ) ) {
F_69 ( V_202 , L_17 , V_142 ) ;
* V_226 = 1 ;
} else {
F_69 ( V_202 , L_5 , V_2 ) ;
F_72 ( V_2 , V_183 ) ;
}
}
if ( V_172 -> V_144 . V_230 ) {
F_74 ( V_202 ) ;
V_202 = F_68 ( V_172 , V_36 ,
V_231 ) ;
if ( F_2 ( ! V_202 ) )
return;
F_69 ( V_202 ,
L_18 ,
V_172 -> V_144 . V_232 ,
V_172 -> V_144 . V_233 ,
V_172 -> V_144 . V_234 ,
V_172 -> V_144 . V_235 ) ;
}
break; }
case V_236 : {
F_69 ( V_202 ,
L_19
L_20 ,
V_172 -> V_237 . V_238 , V_172 -> V_237 . V_21 ,
V_172 -> V_237 . V_239 . V_240 ,
V_172 -> V_237 . V_239 . V_241 ,
V_172 -> V_237 . V_239 . V_242 ,
V_172 -> V_237 . V_239 . V_243 ) ;
break; }
case V_244 : {
F_69 ( V_202 ,
L_21
L_22 ,
V_172 -> V_245 . V_246 ,
V_172 -> V_245 . V_247 ,
V_172 -> V_245 . V_248 ,
V_172 -> V_245 . V_249 . V_250 ,
V_172 -> V_245 . V_249 . V_251 ) ;
break; }
case V_252 : {
F_69 ( V_202 , L_23 ,
V_172 -> V_253 . V_246 ,
V_172 -> V_253 . V_254 ) ;
break; }
case V_255 : {
struct V_256 * V_239 = & V_172 -> V_257 . V_258 ;
F_69 ( V_202 ,
L_24
L_25 ,
V_172 -> V_257 . V_246 ,
V_239 -> V_240 , V_239 -> V_241 ,
V_239 -> V_242 , V_239 -> V_243 ) ;
break; }
case V_259 : {
F_69 ( V_202 , L_26 , V_172 -> V_260 . V_96 ) ;
F_88 ( V_202 , L_27 , & V_172 -> V_260 . V_261 . V_262 ) ;
F_88 ( V_202 , L_28 , & V_172 -> V_260 . V_261 . V_263 ) ;
F_88 ( V_202 , L_29 , & V_172 -> V_260 . V_261 . V_264 ) ;
break; }
case V_265 : {
F_69 ( V_202 , L_30 , V_172 -> V_266 . V_267 ,
V_172 -> V_266 . V_268 ) ;
break; }
case V_221 : {
F_83 ( V_172 , & V_202 ) ;
break; }
}
F_74 ( V_202 ) ;
}
static inline int F_89 ( char * V_181 , int V_183 )
{
char * V_269 = V_181 + V_183 - 1 ;
while ( V_269 > V_181 && ! isprint ( * V_269 ) )
V_269 -- ;
V_183 = V_269 - V_181 + 1 ;
V_183 -= isprint ( V_181 [ V_183 - 1 ] ) == 0 ;
return V_183 ;
}
static void F_90 ( struct V_49 * V_50 ,
struct V_1 * V_172 )
{
int V_270 ;
char * V_207 ;
char * V_271 = L_31 ;
int V_183 = strlen ( V_271 ) ;
struct V_201 * V_202 ;
V_202 = F_68 ( V_172 , V_36 , V_272 ) ;
if ( ! V_202 )
return;
F_69 ( V_202 , L_32 ) ;
if ( ! V_172 -> V_181 . V_182 ) {
V_207 = F_84 ( V_273 , V_36 ) ;
if ( ! V_207 )
goto V_274;
V_270 = F_91 ( V_50 , V_207 , V_273 ) ;
if ( V_270 == 0 ) {
F_17 ( V_207 ) ;
goto V_274;
}
V_270 = F_89 ( V_207 , V_270 ) ;
if ( V_270 == 0 ) {
F_17 ( V_207 ) ;
goto V_274;
}
V_172 -> V_181 . V_182 = V_207 ;
V_172 -> V_181 . V_183 = V_270 ;
}
V_271 = V_172 -> V_181 . V_182 ;
V_183 = V_172 -> V_181 . V_183 ;
V_274:
F_92 ( V_202 , V_271 , V_183 ) ;
F_74 ( V_202 ) ;
}
static void F_93 ( struct V_1 * V_172 , struct V_49 * V_50 )
{
int V_89 , V_226 = 0 ;
struct V_201 * V_202 ;
struct V_189 * V_190 ;
struct V_20 * V_4 ;
V_172 -> V_111 = V_50 -> V_111 ;
V_202 = F_68 ( V_172 , V_36 , V_275 ) ;
if ( ! V_202 )
return;
F_69 ( V_202 , L_33 ,
V_172 -> V_6 , V_172 -> V_5 ) ;
if ( V_172 -> V_111 != V_276 )
F_69 ( V_202 , L_34 , V_172 -> V_111 ) ;
if ( V_172 -> V_114 )
F_69 ( V_202 , L_35 ,
( V_172 -> V_114 == V_117 ) ? L_36 : L_37 ,
V_172 -> V_115 ) ;
F_69 ( V_202 ,
L_38 ,
V_172 -> V_16 [ 0 ] ,
V_172 -> V_16 [ 1 ] ,
V_172 -> V_16 [ 2 ] ,
V_172 -> V_16 [ 3 ] ,
V_172 -> V_185 ) ;
F_94 ( V_202 , V_50 ) ;
F_95 ( V_202 , V_172 -> V_153 ) ;
F_74 ( V_202 ) ;
for ( V_190 = V_172 -> V_190 ; V_190 ; V_190 = V_190 -> V_35 ) {
V_202 = F_68 ( V_172 , V_36 , V_190 -> type ) ;
if ( ! V_202 )
continue;
switch ( V_190 -> type ) {
case V_277 : {
struct V_278 * V_279 = ( void * ) V_190 ;
F_69 ( V_202 , L_39 , V_279 -> V_280 ) ;
F_88 ( V_202 , L_40 , & V_279 -> V_281 . V_263 ) ;
F_88 ( V_202 , L_41 , & V_279 -> V_281 . V_262 ) ;
F_69 ( V_202 , L_42 , V_279 -> V_281 . V_282 ) ;
F_88 ( V_202 , L_43 , & V_279 -> V_283 . V_263 ) ;
F_88 ( V_202 , L_44 , & V_279 -> V_283 . V_262 ) ;
F_88 ( V_202 , L_45 , & V_279 -> V_283 . V_264 ) ;
F_88 ( V_202 , L_46 , & V_279 -> V_284 . V_263 ) ;
F_88 ( V_202 , L_47 , & V_279 -> V_284 . V_262 ) ;
F_88 ( V_202 , L_48 , & V_279 -> V_284 . V_264 ) ;
break; }
}
F_74 ( V_202 ) ;
}
if ( V_172 -> type )
F_86 ( V_172 , & V_226 ) ;
if ( V_172 -> V_285 [ 0 ] >= 0 ) {
V_202 = F_68 ( V_172 , V_36 , V_286 ) ;
if ( V_202 ) {
F_69 ( V_202 , L_49 ,
V_172 -> V_285 [ 0 ] , V_172 -> V_285 [ 1 ] ) ;
F_74 ( V_202 ) ;
}
}
if ( V_172 -> V_287 ) {
V_202 = F_68 ( V_172 , V_36 , V_288 ) ;
if ( V_202 ) {
F_69 ( V_202 , L_50 ) ;
F_81 ( V_202 , ( void * ) V_172 -> V_197 ,
V_172 -> V_287 ) ;
F_74 ( V_202 ) ;
}
}
for ( V_190 = V_172 -> V_191 ; V_190 ; V_190 = V_190 -> V_35 ) {
struct V_289 * V_279 = ( void * ) V_190 ;
for ( V_89 = 0 ; V_89 < V_279 -> V_290 ; V_89 ++ )
if ( F_67 ( V_172 , V_279 -> V_291 [ V_89 ] ,
V_279 -> V_292 [ V_89 ] ,
V_279 -> V_293 [ V_89 ] ,
V_279 -> V_294 [ V_89 ] ,
V_279 -> V_295 [ V_89 ] ,
V_279 -> V_296 [ V_89 ] ) )
V_226 = 1 ;
}
if ( V_172 -> V_291 &&
F_67 ( V_172 , V_172 -> V_291 ,
V_172 -> V_292 , V_172 -> V_293 ,
V_172 -> V_294 ,
V_172 -> V_295 , V_172 -> V_296 ) )
V_226 = 1 ;
if ( V_172 -> V_186 . V_187 && V_172 -> V_186 . V_188 ) {
V_202 = F_68 ( V_172 , V_36 , V_297 ) ;
if ( V_202 ) {
F_96 ( V_202 , L_51 , & V_172 -> V_186 ) ;
F_74 ( V_202 ) ;
}
}
V_89 = 0 ;
F_7 (n, &context->names_list, list) {
if ( V_4 -> V_298 )
continue;
F_97 ( V_172 , V_4 , NULL , V_89 ++ , & V_226 ) ;
}
F_90 ( V_50 , V_172 ) ;
V_202 = F_68 ( V_172 , V_36 , V_299 ) ;
if ( V_202 )
F_74 ( V_202 ) ;
if ( V_226 )
F_85 ( L_52 ) ;
}
void F_98 ( struct V_49 * V_50 )
{
struct V_1 * V_172 ;
V_172 = F_52 ( V_50 , 0 , 0 ) ;
if ( ! V_172 )
return;
if ( V_172 -> V_177 && V_172 -> V_25 == V_26 )
F_93 ( V_172 , V_50 ) ;
if ( ! F_48 ( & V_172 -> V_192 ) )
F_99 ( & V_172 -> V_192 ) ;
F_66 ( V_172 ) ;
}
void F_100 ( int V_5 , unsigned long V_300 , unsigned long V_301 ,
unsigned long V_302 , unsigned long V_303 )
{
struct V_49 * V_50 = V_92 ;
struct V_1 * V_172 = V_50 -> V_1 ;
enum V_86 V_87 ;
if ( ! V_172 )
return;
F_101 ( V_172 -> V_177 || V_172 -> V_185 ) ;
if ( ! V_304 )
return;
V_172 -> V_6 = F_102 () ;
V_172 -> V_5 = V_5 ;
V_172 -> V_16 [ 0 ] = V_300 ;
V_172 -> V_16 [ 1 ] = V_301 ;
V_172 -> V_16 [ 2 ] = V_302 ;
V_172 -> V_16 [ 3 ] = V_303 ;
V_87 = V_172 -> V_87 ;
V_172 -> V_178 = ! V_305 ;
if ( ! V_172 -> V_178 && V_87 == V_162 ) {
V_172 -> V_24 = 0 ;
V_87 = F_47 ( V_50 , V_172 , & V_179 [ V_306 ] ) ;
}
if ( V_87 == V_157 )
return;
V_172 -> V_307 = 0 ;
V_172 -> ctime = V_308 ;
V_172 -> V_177 = 1 ;
V_172 -> V_25 = V_87 ;
V_172 -> V_99 = 0 ;
}
void F_103 ( int V_309 , long V_115 )
{
struct V_49 * V_50 = V_92 ;
struct V_1 * V_172 ;
if ( V_309 )
V_309 = V_117 ;
else
V_309 = V_118 ;
V_172 = F_52 ( V_50 , V_309 , V_115 ) ;
if ( ! V_172 )
return;
if ( V_172 -> V_177 && V_172 -> V_25 == V_26 )
F_93 ( V_172 , V_50 ) ;
V_172 -> V_177 = 0 ;
V_172 -> V_24 = V_172 -> V_87 == V_26 ? ~ 0ULL : 0 ;
if ( ! F_48 ( & V_172 -> V_192 ) )
F_99 ( & V_172 -> V_192 ) ;
F_54 ( V_172 ) ;
F_13 ( V_172 , NULL , 0 ) ;
F_59 ( V_172 ) ;
V_172 -> V_190 = NULL ;
V_172 -> V_191 = NULL ;
V_172 -> V_291 = 0 ;
V_172 -> V_295 = 0 ;
V_172 -> V_287 = 0 ;
V_172 -> type = 0 ;
V_172 -> V_285 [ 0 ] = - 1 ;
if ( V_172 -> V_87 != V_26 ) {
F_17 ( V_172 -> V_153 ) ;
V_172 -> V_153 = NULL ;
}
V_50 -> V_1 = V_172 ;
}
static inline void F_104 ( const struct V_310 * V_310 )
{
#ifdef F_14
struct V_1 * V_172 ;
struct V_29 * V_30 ;
struct V_27 * V_28 ;
int V_38 ;
if ( F_10 ( F_105 ( & V_310 -> V_311 ) ) )
return;
V_172 = V_92 -> V_1 ;
V_30 = V_172 -> V_31 ;
V_38 = V_172 -> V_33 ;
F_41 () ;
V_28 = F_106 ( V_310 ) ;
F_43 () ;
if ( ! V_28 )
return;
if ( F_10 ( F_9 ( V_172 , V_28 ) ) )
return;
if ( F_2 ( ! F_11 ( V_172 ) ) ) {
F_107 ( L_53 ) ;
F_8 ( V_172 ) ;
F_15 ( V_28 ) ;
F_13 ( V_172 , V_30 , V_38 ) ;
return;
}
F_9 ( V_172 , V_28 ) ;
#endif
}
static void F_108 ( const struct V_187 * V_187 )
{
#ifdef F_14
struct V_1 * V_172 ;
struct V_29 * V_30 ;
const struct V_187 * V_312 , * V_313 ;
struct V_27 * V_314 ;
unsigned long V_315 ;
int V_38 ;
V_172 = V_92 -> V_1 ;
V_30 = V_172 -> V_31 ;
V_38 = V_172 -> V_33 ;
V_316:
V_314 = NULL ;
V_312 = V_187 ;
F_41 () ;
V_315 = F_109 ( & V_317 ) ;
for(; ; ) {
struct V_310 * V_310 = V_312 -> V_318 ;
if ( V_310 && F_2 ( ! F_105 ( & V_310 -> V_311 ) ) ) {
struct V_27 * V_28 ;
V_28 = F_106 ( V_310 ) ;
if ( V_28 ) {
if ( F_2 ( ! F_9 ( V_172 , V_28 ) ) ) {
V_314 = V_28 ;
break;
}
}
}
V_313 = V_312 -> V_319 ;
if ( V_313 == V_312 )
break;
V_312 = V_313 ;
}
if ( F_2 ( F_110 ( & V_317 , V_315 ) || V_314 ) ) {
F_43 () ;
if ( ! V_314 ) {
F_13 ( V_172 , V_30 , V_38 ) ;
goto V_316;
}
F_15 ( V_314 ) ;
if ( F_11 ( V_172 ) ) {
F_13 ( V_172 , V_30 , V_38 ) ;
goto V_316;
}
F_107 ( L_53 ) ;
F_13 ( V_172 , V_30 , V_38 ) ;
F_8 ( V_172 ) ;
return;
}
F_43 () ;
#endif
}
static struct V_20 * F_111 ( struct V_1 * V_172 ,
unsigned char type )
{
struct V_20 * V_320 ;
if ( V_172 -> V_185 < V_321 ) {
V_320 = & V_172 -> V_322 [ V_172 -> V_185 ] ;
memset ( V_320 , 0 , sizeof( * V_320 ) ) ;
} else {
V_320 = F_12 ( sizeof( * V_320 ) , V_323 ) ;
if ( ! V_320 )
return NULL ;
V_320 -> V_184 = true ;
}
V_320 -> V_22 = ( unsigned long ) - 1 ;
V_320 -> type = type ;
F_112 ( & V_320 -> V_167 , & V_172 -> V_193 ) ;
V_172 -> V_185 ++ ;
return V_320 ;
}
struct V_324 *
F_113 ( const T_7 char * V_325 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_20 * V_4 ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 )
continue;
if ( V_4 -> V_43 -> V_325 == V_325 ) {
V_4 -> V_43 -> V_326 ++ ;
return V_4 -> V_43 ;
}
}
return NULL ;
}
void F_114 ( struct V_324 * V_43 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_20 * V_4 ;
if ( ! V_172 -> V_177 )
return;
V_4 = F_111 ( V_172 , V_327 ) ;
if ( ! V_4 )
return;
V_4 -> V_43 = V_43 ;
V_4 -> V_328 = V_329 ;
V_43 -> V_320 = V_4 ;
V_43 -> V_326 ++ ;
if ( ! V_172 -> V_186 . V_187 )
F_115 ( V_92 -> V_330 , & V_172 -> V_186 ) ;
}
void F_116 ( struct V_324 * V_43 , const struct V_187 * V_187 ,
unsigned int V_268 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
const struct V_310 * V_310 = V_187 -> V_318 ;
struct V_20 * V_4 ;
bool V_313 = V_268 & V_331 ;
if ( ! V_172 -> V_177 )
return;
if ( ! V_43 )
goto V_332;
V_4 = V_43 -> V_320 ;
if ( V_4 ) {
if ( V_313 ) {
if ( V_4 -> type == V_333 ||
V_4 -> type == V_327 )
goto V_274;
} else {
if ( V_4 -> type != V_333 )
goto V_274;
}
}
F_117 (n, &context->names_list, list) {
if ( V_4 -> V_22 ) {
if ( V_4 -> V_22 != V_310 -> V_334 ||
V_4 -> V_120 != V_310 -> V_335 -> V_336 )
continue;
} else if ( V_4 -> V_43 ) {
if ( strcmp ( V_4 -> V_43 -> V_43 , V_43 -> V_43 ) )
continue;
} else
continue;
if ( V_313 ) {
if ( V_4 -> type == V_333 ||
V_4 -> type == V_327 )
goto V_274;
} else {
if ( V_4 -> type != V_333 )
goto V_274;
}
}
V_332:
V_4 = F_111 ( V_172 , V_327 ) ;
if ( ! V_4 )
return;
if ( V_43 ) {
V_4 -> V_43 = V_43 ;
V_43 -> V_326 ++ ;
}
V_274:
if ( V_313 ) {
V_4 -> V_328 = V_4 -> V_43 ? F_118 ( V_4 -> V_43 -> V_43 ) : V_329 ;
V_4 -> type = V_333 ;
if ( V_268 & V_337 )
V_4 -> V_298 = true ;
} else {
V_4 -> V_328 = V_329 ;
V_4 -> type = V_338 ;
}
F_108 ( V_187 ) ;
F_119 ( V_4 , V_187 , V_310 ) ;
}
void F_120 ( const struct V_339 * V_339 )
{
F_116 ( NULL , V_339 -> V_340 . V_187 , 0 ) ;
}
void F_121 ( const struct V_310 * V_313 ,
const struct V_187 * V_187 ,
const unsigned char type )
{
struct V_1 * V_172 = V_92 -> V_1 ;
const struct V_310 * V_310 = V_187 -> V_318 ;
const char * V_341 = V_187 -> V_342 . V_43 ;
struct V_20 * V_4 , * V_343 = NULL , * V_344 = NULL ;
if ( ! V_172 -> V_177 )
return;
if ( V_310 )
F_104 ( V_310 ) ;
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 ||
( V_4 -> type != V_333 &&
V_4 -> type != V_327 ) )
continue;
if ( V_4 -> V_22 == V_313 -> V_334 && V_4 -> V_120 == V_313 -> V_335 -> V_336 &&
! F_122 ( V_341 ,
V_4 -> V_43 -> V_43 , V_4 -> V_328 ) ) {
if ( V_4 -> type == V_327 )
V_4 -> type = V_333 ;
V_343 = V_4 ;
break;
}
}
F_7 (n, &context->names_list, list) {
if ( ! V_4 -> V_43 ||
( V_4 -> type != type && V_4 -> type != V_327 ) )
continue;
if ( ! strcmp ( V_341 , V_4 -> V_43 -> V_43 ) ||
! F_122 ( V_341 , V_4 -> V_43 -> V_43 ,
V_343 ?
V_343 -> V_328 :
V_329 ) ) {
if ( V_4 -> type == V_327 )
V_4 -> type = type ;
V_344 = V_4 ;
break;
}
}
if ( ! V_343 ) {
V_4 = F_111 ( V_172 , V_333 ) ;
if ( ! V_4 )
return;
F_119 ( V_4 , NULL , V_313 ) ;
}
if ( ! V_344 ) {
V_344 = F_111 ( V_172 , type ) ;
if ( ! V_344 )
return;
if ( V_343 ) {
V_344 -> V_43 = V_343 -> V_43 ;
V_344 -> V_328 = V_329 ;
V_344 -> V_43 -> V_326 ++ ;
}
}
if ( V_310 )
F_119 ( V_344 , V_187 , V_310 ) ;
else
V_344 -> V_22 = ( unsigned long ) - 1 ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_345 * V_346 , unsigned int * V_307 )
{
if ( ! V_2 -> V_177 )
return 0 ;
if ( ! V_2 -> V_307 )
V_2 -> V_307 = F_124 () ;
V_346 -> V_250 = V_2 -> ctime . V_250 ;
V_346 -> V_251 = V_2 -> ctime . V_251 ;
* V_307 = V_2 -> V_307 ;
if ( ! V_2 -> V_24 ) {
V_2 -> V_24 = 1 ;
V_2 -> V_25 = V_26 ;
}
return 1 ;
}
static int F_125 ( T_2 V_59 )
{
if ( ! F_36 ( V_92 ) )
return 0 ;
if ( F_126 ( V_347 ) )
return - V_348 ;
if ( ! F_127 ( V_349 ) )
return - V_348 ;
if ( F_126 ( V_350 ) && F_128 ( V_59 ) )
return - V_348 ;
return 0 ;
}
static void F_129 ( T_2 V_351 , T_2 V_352 ,
unsigned int V_353 , unsigned int V_199 ,
int V_46 )
{
struct V_201 * V_202 ;
T_8 V_42 , V_354 , V_59 ;
if ( ! V_304 )
return;
V_42 = F_70 ( & V_204 , F_130 ( V_92 ) ) ;
V_354 = F_70 ( & V_204 , V_351 ) ;
V_59 = F_70 ( & V_204 , V_352 ) ,
V_202 = F_68 ( NULL , V_36 , V_355 ) ;
if ( ! V_202 )
return;
F_69 ( V_202 , L_54 , F_28 ( V_92 ) , V_42 ) ;
F_131 ( V_202 ) ;
F_69 ( V_202 , L_55 ,
V_354 , V_59 , V_353 , V_199 , ! V_46 ) ;
F_74 ( V_202 ) ;
}
int F_132 ( T_2 V_59 )
{
struct V_49 * V_356 = V_92 ;
unsigned int V_353 , V_199 = ( unsigned int ) - 1 ;
T_2 V_354 ;
int V_46 ;
V_354 = F_133 ( V_92 ) ;
V_353 = F_134 ( V_92 ) ;
V_46 = F_125 ( V_59 ) ;
if ( V_46 )
goto V_274;
if ( F_128 ( V_59 ) )
V_199 = ( unsigned int ) F_135 ( & V_357 ) ;
V_356 -> V_199 = V_199 ;
V_356 -> V_59 = V_59 ;
V_274:
F_129 ( V_354 , V_59 , V_353 , V_199 , V_46 ) ;
return V_46 ;
}
void F_136 ( int V_238 , T_1 V_21 , struct V_256 * V_239 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( V_239 )
memcpy ( & V_172 -> V_237 . V_239 , V_239 , sizeof( struct V_256 ) ) ;
else
memset ( & V_172 -> V_237 . V_239 , 0 , sizeof( struct V_256 ) ) ;
V_172 -> V_237 . V_238 = V_238 ;
V_172 -> V_237 . V_21 = V_21 ;
V_172 -> type = V_236 ;
}
void F_137 ( T_9 V_246 , T_6 V_247 , unsigned int V_248 ,
const struct V_345 * V_249 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_345 * V_30 = & V_172 -> V_245 . V_249 ;
if ( V_249 )
memcpy ( V_30 , V_249 , sizeof( struct V_345 ) ) ;
else
memset ( V_30 , 0 , sizeof( struct V_345 ) ) ;
V_172 -> V_245 . V_246 = V_246 ;
V_172 -> V_245 . V_247 = V_247 ;
V_172 -> V_245 . V_248 = V_248 ;
V_172 -> type = V_244 ;
}
void F_138 ( T_9 V_246 , const struct V_358 * V_359 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( V_359 )
V_172 -> V_253 . V_254 = V_359 -> V_254 ;
else
V_172 -> V_253 . V_254 = 0 ;
V_172 -> V_253 . V_246 = V_246 ;
V_172 -> type = V_252 ;
}
void F_139 ( T_9 V_246 , struct V_256 * V_258 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_257 . V_246 = V_246 ;
V_172 -> V_257 . V_258 = * V_258 ;
V_172 -> type = V_255 ;
}
void F_140 ( struct V_360 * V_361 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_144 . V_42 = V_361 -> V_42 ;
V_172 -> V_144 . V_48 = V_361 -> V_48 ;
V_172 -> V_144 . V_21 = V_361 -> V_21 ;
V_172 -> V_144 . V_230 = 0 ;
F_141 ( V_361 , & V_172 -> V_144 . V_142 ) ;
V_172 -> type = V_143 ;
}
void F_142 ( unsigned long V_232 , T_8 V_42 , T_10 V_48 , T_1 V_21 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_144 . V_232 = V_232 ;
V_172 -> V_144 . V_233 = V_42 ;
V_172 -> V_144 . V_234 = V_48 ;
V_172 -> V_144 . V_235 = V_21 ;
V_172 -> V_144 . V_230 = 1 ;
}
void F_143 ( struct V_362 * V_363 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> type = V_221 ;
V_172 -> V_224 . V_225 = V_363 -> V_225 ;
}
int F_144 ( int V_228 , unsigned long * args )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( V_228 <= 0 || V_228 > V_364 || ! args )
return - V_365 ;
V_172 -> type = V_227 ;
V_172 -> V_229 . V_228 = V_228 ;
memcpy ( V_172 -> V_229 . args , args , V_228 * sizeof( unsigned long ) ) ;
return 0 ;
}
void F_145 ( int V_366 , int V_367 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_285 [ 0 ] = V_366 ;
V_172 -> V_285 [ 1 ] = V_367 ;
}
int F_146 ( int V_183 , void * V_368 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
if ( ! V_172 -> V_197 ) {
void * V_30 = F_84 ( sizeof( struct V_369 ) , V_36 ) ;
if ( ! V_30 )
return - V_196 ;
V_172 -> V_197 = V_30 ;
}
V_172 -> V_287 = V_183 ;
memcpy ( V_172 -> V_197 , V_368 , V_183 ) ;
return 0 ;
}
void F_147 ( struct V_49 * V_346 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_291 = F_28 ( V_346 ) ;
V_172 -> V_292 = F_133 ( V_346 ) ;
V_172 -> V_293 = F_130 ( V_346 ) ;
V_172 -> V_294 = F_134 ( V_346 ) ;
F_37 ( V_346 , & V_172 -> V_295 ) ;
memcpy ( V_172 -> V_296 , V_346 -> V_200 , V_370 ) ;
}
int F_148 ( int V_371 , struct V_49 * V_346 )
{
struct V_289 * V_372 ;
struct V_49 * V_50 = V_92 ;
struct V_1 * V_2 = V_50 -> V_1 ;
T_2 V_42 = F_149 () , V_373 = F_130 ( V_346 ) ;
if ( V_168 && V_346 -> V_169 == V_168 ) {
if ( V_371 == V_374 || V_371 == V_375 || V_371 == V_376 || V_371 == V_377 ) {
V_378 = F_28 ( V_50 ) ;
if ( F_128 ( V_50 -> V_59 ) )
V_379 = V_50 -> V_59 ;
else
V_379 = V_42 ;
F_37 ( V_50 , & V_380 ) ;
}
if ( ! V_381 || F_150 () )
return 0 ;
}
if ( ! V_2 -> V_291 ) {
V_2 -> V_291 = F_151 ( V_346 ) ;
V_2 -> V_292 = F_133 ( V_346 ) ;
V_2 -> V_293 = V_373 ;
V_2 -> V_294 = F_134 ( V_346 ) ;
F_37 ( V_346 , & V_2 -> V_295 ) ;
memcpy ( V_2 -> V_296 , V_346 -> V_200 , V_370 ) ;
return 0 ;
}
V_372 = ( void * ) V_2 -> V_191 ;
if ( ! V_372 || V_372 -> V_290 == V_382 ) {
V_372 = F_12 ( sizeof( * V_372 ) , V_154 ) ;
if ( ! V_372 )
return - V_196 ;
V_372 -> V_312 . type = V_203 ;
V_372 -> V_312 . V_35 = V_2 -> V_191 ;
V_2 -> V_191 = ( void * ) V_372 ;
}
F_101 ( V_372 -> V_290 >= V_382 ) ;
V_372 -> V_291 [ V_372 -> V_290 ] = F_151 ( V_346 ) ;
V_372 -> V_292 [ V_372 -> V_290 ] = F_133 ( V_346 ) ;
V_372 -> V_293 [ V_372 -> V_290 ] = V_373 ;
V_372 -> V_294 [ V_372 -> V_290 ] = F_134 ( V_346 ) ;
F_37 ( V_346 , & V_372 -> V_295 [ V_372 -> V_290 ] ) ;
memcpy ( V_372 -> V_296 [ V_372 -> V_290 ] , V_346 -> V_200 , V_370 ) ;
V_372 -> V_290 ++ ;
return 0 ;
}
int F_152 ( struct V_362 * V_363 ,
const struct V_51 * V_383 , const struct V_51 * V_384 )
{
struct V_278 * V_385 ;
struct V_1 * V_172 = V_92 -> V_1 ;
struct V_386 V_387 ;
V_385 = F_84 ( sizeof( * V_385 ) , V_36 ) ;
if ( ! V_385 )
return - V_196 ;
V_385 -> V_312 . type = V_277 ;
V_385 -> V_312 . V_35 = V_172 -> V_190 ;
V_172 -> V_190 = ( void * ) V_385 ;
F_153 ( V_363 -> V_339 -> V_340 . V_187 , & V_387 ) ;
V_385 -> V_281 . V_263 = V_387 . V_263 ;
V_385 -> V_281 . V_262 = V_387 . V_262 ;
V_385 -> V_281 . V_282 = ! ! ( V_387 . V_388 & V_389 ) ;
V_385 -> V_280 = ( V_387 . V_388 & V_390 ) >> V_391 ;
V_385 -> V_283 . V_263 = V_384 -> V_392 ;
V_385 -> V_283 . V_262 = V_384 -> V_393 ;
V_385 -> V_283 . V_264 = V_384 -> V_394 ;
V_385 -> V_284 . V_263 = V_383 -> V_392 ;
V_385 -> V_284 . V_262 = V_383 -> V_393 ;
V_385 -> V_284 . V_264 = V_383 -> V_394 ;
return 0 ;
}
void F_154 ( const struct V_51 * V_383 , const struct V_51 * V_384 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_260 . V_96 = F_28 ( V_92 ) ;
V_172 -> V_260 . V_261 . V_264 = V_383 -> V_394 ;
V_172 -> V_260 . V_261 . V_262 = V_383 -> V_394 ;
V_172 -> V_260 . V_261 . V_263 = V_383 -> V_392 ;
V_172 -> type = V_259 ;
}
void F_155 ( int V_267 , int V_268 )
{
struct V_1 * V_172 = V_92 -> V_1 ;
V_172 -> V_266 . V_267 = V_267 ;
V_172 -> V_266 . V_268 = V_268 ;
V_172 -> type = V_265 ;
}
static void F_156 ( struct V_201 * V_202 )
{
T_2 V_198 , V_42 ;
T_3 V_48 ;
unsigned int V_199 ;
struct V_395 * V_222 = V_92 -> V_222 ;
char V_200 [ sizeof( V_92 -> V_200 ) ] ;
V_198 = F_133 ( V_92 ) ;
V_199 = F_134 ( V_92 ) ;
F_157 ( & V_42 , & V_48 ) ;
F_69 ( V_202 , L_56 ,
F_70 ( & V_204 , V_198 ) ,
F_70 ( & V_204 , V_42 ) ,
F_87 ( & V_204 , V_48 ) ,
V_199 ) ;
F_131 ( V_202 ) ;
F_69 ( V_202 , L_57 , F_28 ( V_92 ) ) ;
F_73 ( V_202 , F_158 ( V_200 , V_92 ) ) ;
if ( V_222 ) {
F_159 ( & V_222 -> V_396 ) ;
if ( V_222 -> V_397 )
F_96 ( V_202 , L_58 , & V_222 -> V_397 -> V_340 ) ;
F_160 ( & V_222 -> V_396 ) ;
} else
F_69 ( V_202 , L_59 ) ;
}
void F_161 ( long V_398 )
{
struct V_201 * V_202 ;
if ( ! V_304 )
return;
if ( V_398 == V_399 )
return;
V_202 = F_68 ( NULL , V_36 , V_400 ) ;
if ( F_2 ( ! V_202 ) )
return;
F_156 ( V_202 ) ;
F_69 ( V_202 , L_60 , V_398 ) ;
F_74 ( V_202 ) ;
}
void F_162 ( unsigned long V_401 , long V_398 , int V_402 )
{
struct V_201 * V_202 ;
V_202 = F_68 ( NULL , V_36 , V_403 ) ;
if ( F_2 ( ! V_202 ) )
return;
F_156 ( V_202 ) ;
F_69 ( V_202 , L_61 ,
V_398 , F_102 () , V_401 , F_163 () ,
F_164 ( V_92 ) , V_402 ) ;
F_74 ( V_202 ) ;
}
struct V_166 * F_165 ( void )
{
struct V_1 * V_2 = V_92 -> V_1 ;
if ( F_10 ( ! V_2 || ! V_2 -> V_177 ) )
return NULL ;
return & V_2 -> V_192 ;
}
