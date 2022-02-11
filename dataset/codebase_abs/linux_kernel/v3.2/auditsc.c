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
unsigned V_23 = V_22 & ~ V_24 ;
T_1 V_25 = V_22 & V_24 ;
if ( F_4 ( ! V_8 ) )
return 0 ;
if ( V_23 >= V_8 -> V_26 )
return 0 ;
if ( V_8 -> V_27 [ V_23 ] . V_28 == - 1 )
return 0 ;
if ( ( V_8 -> V_27 [ V_23 ] . V_25 ^ V_25 ) & V_24 )
return 0 ;
return 1 ;
}
static void F_8 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_29 ) {
V_8 -> V_29 = 1 ;
V_8 -> V_30 = V_31 ;
}
}
static int F_9 ( struct V_7 * V_8 , struct V_32 * V_33 )
{
struct V_34 * V_35 = V_8 -> V_36 ;
int V_37 = V_8 -> V_38 ;
if ( F_10 ( V_37 ) ) {
V_35 -> V_39 [ -- V_37 ] = V_33 ;
V_8 -> V_38 = V_37 ;
return 1 ;
}
if ( ! V_35 )
return 0 ;
V_35 = V_35 -> V_40 ;
if ( V_35 ) {
V_35 -> V_39 [ 30 ] = V_33 ;
V_8 -> V_36 = V_35 ;
V_8 -> V_38 = 30 ;
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_34 * V_35 = V_8 -> V_36 ;
V_8 -> V_36 = F_12 ( sizeof( struct V_34 ) , V_41 ) ;
if ( ! V_8 -> V_36 ) {
V_8 -> V_36 = V_35 ;
return 0 ;
}
if ( V_35 )
V_35 -> V_40 = V_8 -> V_36 ;
else
V_8 -> V_42 = V_8 -> V_36 ;
V_8 -> V_38 = 31 ;
return 1 ;
}
static void F_13 ( struct V_7 * V_8 ,
struct V_34 * V_35 , int V_43 )
{
#ifdef F_14
struct V_34 * V_44 ;
int V_3 ;
if ( ! V_35 ) {
V_35 = V_8 -> V_42 ;
V_43 = 31 ;
if ( ! V_35 )
return;
}
V_3 = V_43 ;
for ( V_44 = V_35 ; V_44 != V_8 -> V_36 ; V_44 = V_44 -> V_40 , V_3 = 31 ) {
while ( V_3 -- ) {
F_15 ( V_44 -> V_39 [ V_3 ] ) ;
V_44 -> V_39 [ V_3 ] = NULL ;
}
}
while ( V_3 -- > V_8 -> V_38 ) {
F_15 ( V_44 -> V_39 [ V_3 ] ) ;
V_44 -> V_39 [ V_3 ] = NULL ;
}
V_8 -> V_36 = V_35 ;
V_8 -> V_38 = V_43 ;
#endif
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_34 * V_35 , * V_44 ;
for ( V_35 = V_8 -> V_42 ; V_35 ; V_35 = V_44 ) {
V_44 = V_35 -> V_40 ;
F_17 ( V_35 ) ;
}
}
static int F_18 ( struct V_7 * V_8 , struct V_45 * V_46 )
{
#ifdef F_14
struct V_34 * V_35 ;
int V_3 ;
if ( ! V_46 )
return 0 ;
for ( V_35 = V_8 -> V_42 ; V_35 != V_8 -> V_36 ; V_35 = V_35 -> V_40 ) {
for ( V_3 = 0 ; V_3 < 31 ; V_3 ++ )
if ( F_19 ( V_35 -> V_39 [ V_3 ] , V_46 ) )
return 1 ;
}
if ( V_35 ) {
for ( V_3 = V_8 -> V_38 ; V_3 < 31 ; V_3 ++ )
if ( F_19 ( V_35 -> V_39 [ V_3 ] , V_46 ) )
return 1 ;
}
#endif
return 0 ;
}
static int F_20 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_7 * V_8 ,
struct V_51 * V_52 ,
enum V_53 * V_54 ,
bool V_55 )
{
const struct V_56 * V_56 ;
int V_57 , V_58 , V_59 = 1 ;
T_2 V_60 ;
V_56 = F_21 ( V_48 -> V_56 , V_48 == V_61 || V_55 ) ;
for ( V_57 = 0 ; V_57 < V_50 -> V_62 ; V_57 ++ ) {
struct V_63 * V_64 = & V_50 -> V_65 [ V_57 ] ;
int V_66 = 0 ;
switch ( V_64 -> type ) {
case V_67 :
V_66 = F_22 ( V_48 -> V_68 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_71 :
if ( V_8 ) {
if ( ! V_8 -> V_72 )
V_8 -> V_72 = F_23 () ;
V_66 = F_22 ( V_8 -> V_72 , V_64 -> V_69 , V_64 -> V_70 ) ;
}
break;
case V_73 :
V_66 = F_22 ( V_56 -> V_74 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_75 :
V_66 = F_22 ( V_56 -> V_76 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_77 :
V_66 = F_22 ( V_56 -> V_78 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_79 :
V_66 = F_22 ( V_56 -> V_80 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_81 :
V_66 = F_22 ( V_56 -> V_82 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_83 :
V_66 = F_22 ( V_56 -> V_84 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_85 :
V_66 = F_22 ( V_56 -> V_86 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_87 :
V_66 = F_22 ( V_56 -> V_88 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_89 :
V_66 = F_22 ( V_48 -> V_90 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_91 :
if ( V_8 )
V_66 = F_22 ( V_8 -> V_10 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_92 :
if ( V_8 && V_8 -> V_93 )
V_66 = F_22 ( V_8 -> V_94 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_95 :
if ( V_8 && V_8 -> V_93 ) {
if ( V_64 -> V_70 )
V_66 = F_22 ( V_8 -> V_93 , V_64 -> V_69 , V_96 ) ;
else
V_66 = F_22 ( V_8 -> V_93 , V_64 -> V_69 , V_97 ) ;
}
break;
case V_98 :
if ( V_52 )
V_66 = F_22 ( F_24 ( V_52 -> V_99 ) ,
V_64 -> V_69 , V_64 -> V_70 ) ;
else if ( V_8 ) {
for ( V_58 = 0 ; V_58 < V_8 -> V_26 ; V_58 ++ ) {
if ( F_22 ( F_24 ( V_8 -> V_27 [ V_58 ] . V_99 ) , V_64 -> V_69 , V_64 -> V_70 ) ) {
++ V_66 ;
break;
}
}
}
break;
case V_100 :
if ( V_52 )
V_66 = F_22 ( F_25 ( V_52 -> V_99 ) ,
V_64 -> V_69 , V_64 -> V_70 ) ;
else if ( V_8 ) {
for ( V_58 = 0 ; V_58 < V_8 -> V_26 ; V_58 ++ ) {
if ( F_22 ( F_25 ( V_8 -> V_27 [ V_58 ] . V_99 ) , V_64 -> V_69 , V_64 -> V_70 ) ) {
++ V_66 ;
break;
}
}
}
break;
case V_101 :
if ( V_52 )
V_66 = ( V_52 -> V_28 == V_64 -> V_70 ) ;
else if ( V_8 ) {
for ( V_58 = 0 ; V_58 < V_8 -> V_26 ; V_58 ++ ) {
if ( F_22 ( V_8 -> V_27 [ V_58 ] . V_28 , V_64 -> V_69 , V_64 -> V_70 ) ) {
++ V_66 ;
break;
}
}
}
break;
case V_102 :
if ( V_52 )
V_66 = F_26 ( V_50 -> V_103 , V_52 -> V_28 , V_52 -> V_99 ) ;
break;
case V_104 :
if ( V_8 )
V_66 = F_18 ( V_8 , V_50 -> V_46 ) ;
break;
case V_105 :
V_66 = 0 ;
if ( V_8 )
V_66 = F_22 ( V_48 -> V_106 , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
if ( V_64 -> V_112 ) {
if ( V_59 ) {
F_27 ( V_48 , & V_60 ) ;
V_59 = 0 ;
}
V_66 = F_28 ( V_60 , V_64 -> type ,
V_64 -> V_69 ,
V_64 -> V_112 ,
V_8 ) ;
}
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
if ( V_64 -> V_112 ) {
if ( V_52 ) {
V_66 = F_28 (
V_52 -> V_118 , V_64 -> type , V_64 -> V_69 ,
V_64 -> V_112 , V_8 ) ;
} else if ( V_8 ) {
for ( V_58 = 0 ; V_58 < V_8 -> V_26 ; V_58 ++ ) {
if ( F_28 (
V_8 -> V_27 [ V_58 ] . V_118 ,
V_64 -> type , V_64 -> V_69 ,
V_64 -> V_112 , V_8 ) ) {
++ V_66 ;
break;
}
}
}
if ( ! V_8 || V_8 -> type != V_119 )
break;
if ( F_28 ( V_8 -> V_120 . V_118 ,
V_64 -> type , V_64 -> V_69 ,
V_64 -> V_112 , V_8 ) )
++ V_66 ;
}
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
if ( V_8 )
V_66 = F_22 ( V_8 -> V_19 [ V_64 -> type - V_121 ] , V_64 -> V_69 , V_64 -> V_70 ) ;
break;
case V_125 :
V_66 = 1 ;
break;
case V_126 :
V_66 = F_3 ( V_8 , V_64 -> V_70 ) ;
break;
case V_127 :
V_66 = F_7 ( V_8 , V_64 -> V_70 ) ;
break;
}
if ( ! V_66 )
return 0 ;
}
if ( V_8 ) {
if ( V_50 -> V_29 <= V_8 -> V_29 )
return 0 ;
if ( V_50 -> V_128 ) {
F_17 ( V_8 -> V_128 ) ;
V_8 -> V_128 = F_29 ( V_50 -> V_128 , V_129 ) ;
}
V_8 -> V_29 = V_50 -> V_29 ;
}
switch ( V_50 -> V_130 ) {
case V_131 : * V_54 = V_132 ; break;
case V_133 : * V_54 = V_31 ; break;
}
return 1 ;
}
static enum V_53 F_30 ( struct V_47 * V_48 , char * * V_134 )
{
struct V_135 * V_136 ;
enum V_53 V_54 ;
F_31 () ;
F_32 (e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if ( F_20 ( V_48 , & V_136 -> V_50 , NULL , NULL ,
& V_54 , true ) ) {
if ( V_54 == V_31 )
* V_134 = F_29 ( V_136 -> V_50 . V_128 , V_129 ) ;
F_33 () ;
return V_54 ;
}
}
F_33 () ;
return V_137 ;
}
static enum V_53 F_34 ( struct V_47 * V_48 ,
struct V_7 * V_8 ,
struct V_138 * V_139 )
{
struct V_135 * V_136 ;
enum V_53 V_54 ;
if ( V_140 && V_48 -> V_141 == V_140 )
return V_132 ;
F_31 () ;
if ( ! F_35 ( V_139 ) ) {
int V_142 = F_36 ( V_8 -> V_9 ) ;
int V_143 = F_37 ( V_8 -> V_9 ) ;
F_32 (e, list, list) {
if ( ( V_136 -> V_50 . V_2 [ V_142 ] & V_143 ) == V_143 &&
F_20 ( V_48 , & V_136 -> V_50 , V_8 , NULL ,
& V_54 , false ) ) {
F_33 () ;
V_8 -> V_30 = V_54 ;
return V_54 ;
}
}
}
F_33 () ;
return V_137 ;
}
void F_38 ( struct V_47 * V_48 , struct V_7 * V_8 )
{
int V_57 ;
struct V_135 * V_136 ;
enum V_53 V_54 ;
if ( V_140 && V_48 -> V_141 == V_140 )
return;
F_31 () ;
for ( V_57 = 0 ; V_57 < V_8 -> V_26 ; V_57 ++ ) {
int V_142 = F_36 ( V_8 -> V_9 ) ;
int V_143 = F_37 ( V_8 -> V_9 ) ;
struct V_51 * V_3 = & V_8 -> V_27 [ V_57 ] ;
int V_144 = F_39 ( ( T_2 ) V_3 -> V_28 ) ;
struct V_138 * V_139 = & V_145 [ V_144 ] ;
if ( F_35 ( V_139 ) )
continue;
F_32 (e, list, list) {
if ( ( V_136 -> V_50 . V_2 [ V_142 ] & V_143 ) == V_143 &&
F_20 ( V_48 , & V_136 -> V_50 , V_8 , V_3 ,
& V_54 , false ) ) {
F_33 () ;
V_8 -> V_30 = V_54 ;
return;
}
}
}
F_33 () ;
}
static inline struct V_7 * F_40 ( struct V_47 * V_48 ,
int V_93 ,
long V_94 )
{
struct V_7 * V_146 = V_48 -> V_7 ;
if ( F_10 ( ! V_146 ) )
return NULL ;
V_146 -> V_93 = V_93 ;
if ( F_4 ( V_94 <= - V_147 ) &&
( V_94 >= - V_148 ) &&
( V_94 != - V_149 ) )
V_146 -> V_94 = - V_150 ;
else
V_146 -> V_94 = V_94 ;
if ( V_146 -> V_151 && ! V_146 -> V_152 ) {
F_34 ( V_48 , V_146 , & V_153 [ V_154 ] ) ;
F_38 ( V_48 , V_146 ) ;
}
V_48 -> V_7 = NULL ;
return V_146 ;
}
static inline void F_41 ( struct V_7 * V_146 )
{
int V_57 ;
#if V_155 == 2
if ( V_146 -> V_156 + V_146 -> V_157 != V_146 -> V_26 ) {
F_42 ( V_158 L_1
L_2
L_3 ,
__FILE__ , __LINE__ ,
V_146 -> V_159 , V_146 -> V_9 , V_146 -> V_151 ,
V_146 -> V_26 , V_146 -> V_156 ,
V_146 -> V_157 ) ;
for ( V_57 = 0 ; V_57 < V_146 -> V_26 ; V_57 ++ ) {
F_42 ( V_158 L_4 , V_57 ,
V_146 -> V_27 [ V_57 ] . V_52 ,
V_146 -> V_27 [ V_57 ] . V_52 ? : L_5 ) ;
}
F_43 () ;
return;
}
#endif
#if V_155
V_146 -> V_156 = 0 ;
V_146 -> V_157 = 0 ;
#endif
for ( V_57 = 0 ; V_57 < V_146 -> V_26 ; V_57 ++ ) {
if ( V_146 -> V_27 [ V_57 ] . V_52 && V_146 -> V_27 [ V_57 ] . V_160 )
F_44 ( V_146 -> V_27 [ V_57 ] . V_52 ) ;
}
V_146 -> V_26 = 0 ;
F_45 ( & V_146 -> V_161 ) ;
V_146 -> V_161 . V_162 = NULL ;
V_146 -> V_161 . V_163 = NULL ;
}
static inline void F_46 ( struct V_7 * V_146 )
{
struct V_164 * V_165 ;
while ( ( V_165 = V_146 -> V_165 ) ) {
V_146 -> V_165 = V_165 -> V_40 ;
F_17 ( V_165 ) ;
}
while ( ( V_165 = V_146 -> V_166 ) ) {
V_146 -> V_166 = V_165 -> V_40 ;
F_17 ( V_165 ) ;
}
}
static inline void F_47 ( struct V_7 * V_146 ,
enum V_53 V_54 )
{
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> V_54 = V_54 ;
V_146 -> V_29 = V_54 == V_31 ? ~ 0ULL : 0 ;
}
static inline struct V_7 * F_48 ( enum V_53 V_54 )
{
struct V_7 * V_146 ;
if ( ! ( V_146 = F_49 ( sizeof( * V_146 ) , V_41 ) ) )
return NULL ;
F_47 ( V_146 , V_54 ) ;
F_50 ( & V_146 -> V_167 ) ;
return V_146 ;
}
int F_51 ( struct V_47 * V_48 )
{
struct V_7 * V_146 ;
enum V_53 V_54 ;
char * V_134 = NULL ;
if ( F_10 ( ! V_168 ) )
return 0 ;
V_54 = F_30 ( V_48 , & V_134 ) ;
if ( F_10 ( V_54 == V_132 ) )
return 0 ;
if ( ! ( V_146 = F_48 ( V_54 ) ) ) {
F_17 ( V_134 ) ;
F_52 ( L_6 ) ;
return - V_169 ;
}
V_146 -> V_128 = V_134 ;
V_48 -> V_7 = V_146 ;
F_53 ( V_48 , V_170 ) ;
return 0 ;
}
static inline void F_54 ( struct V_7 * V_146 )
{
struct V_7 * V_171 ;
int V_43 = 0 ;
do {
V_171 = V_146 -> V_171 ;
if ( V_171 || ( V_43 && V_43 < 10 ) ) {
++ V_43 ;
F_42 ( V_158 L_7
L_8 ,
V_146 -> V_159 , V_146 -> V_9 ,
V_146 -> V_26 , V_43 ) ;
}
F_41 ( V_146 ) ;
F_13 ( V_146 , NULL , 0 ) ;
F_16 ( V_146 ) ;
F_46 ( V_146 ) ;
F_17 ( V_146 -> V_128 ) ;
F_17 ( V_146 -> V_172 ) ;
F_17 ( V_146 ) ;
V_146 = V_171 ;
} while ( V_146 );
if ( V_43 >= 10 )
F_42 ( V_158 L_9 , V_43 ) ;
}
void F_55 ( struct V_173 * V_174 )
{
char * V_8 = NULL ;
unsigned V_175 ;
int error ;
T_2 V_60 ;
F_27 ( V_61 , & V_60 ) ;
if ( ! V_60 )
return;
error = F_56 ( V_60 , & V_8 , & V_175 ) ;
if ( error ) {
if ( error != - V_176 )
goto V_177;
return;
}
F_57 ( V_174 , L_10 , V_8 ) ;
F_58 ( V_8 , V_175 ) ;
return;
V_177:
F_59 ( L_11 ) ;
return;
}
static void F_60 ( struct V_173 * V_174 , struct V_47 * V_48 )
{
char V_52 [ sizeof( V_48 -> V_178 ) ] ;
struct V_179 * V_180 = V_48 -> V_180 ;
struct V_181 * V_182 ;
F_61 ( V_52 , V_48 ) ;
F_57 ( V_174 , L_12 ) ;
F_62 ( V_174 , V_52 ) ;
if ( V_180 ) {
F_63 ( & V_180 -> V_183 ) ;
V_182 = V_180 -> V_184 ;
while ( V_182 ) {
if ( ( V_182 -> V_185 & V_186 ) &&
V_182 -> V_187 ) {
F_64 ( V_174 , L_13 ,
& V_182 -> V_187 -> V_188 ) ;
break;
}
V_182 = V_182 -> V_189 ;
}
F_65 ( & V_180 -> V_183 ) ;
}
F_55 ( V_174 ) ;
}
static int F_66 ( struct V_7 * V_146 , T_3 V_68 ,
T_4 V_190 , T_4 V_74 , unsigned int V_191 ,
T_2 V_60 , char * V_178 )
{
struct V_173 * V_174 ;
char * V_8 = NULL ;
T_2 V_175 ;
int V_192 = 0 ;
V_174 = F_67 ( V_146 , V_41 , V_193 ) ;
if ( ! V_174 )
return V_192 ;
F_57 ( V_174 , L_14 , V_68 , V_190 ,
V_74 , V_191 ) ;
if ( F_56 ( V_60 , & V_8 , & V_175 ) ) {
F_57 ( V_174 , L_15 ) ;
V_192 = 1 ;
} else {
F_57 ( V_174 , L_16 , V_8 ) ;
F_58 ( V_8 , V_175 ) ;
}
F_57 ( V_174 , L_17 ) ;
F_62 ( V_174 , V_178 ) ;
F_68 ( V_174 ) ;
return V_192 ;
}
static int F_69 ( struct V_7 * V_146 ,
struct V_173 * * V_174 ,
int V_194 ,
T_5 * V_195 ,
const char T_6 * V_35 ,
char * V_196 )
{
char V_197 [ 12 ] ;
const char T_6 * V_198 = V_35 ;
T_5 V_199 = snprintf ( V_197 , 12 , L_18 , V_194 ) + 5 ;
T_5 V_175 , V_200 , V_201 ;
T_5 V_202 = V_203 ;
unsigned int V_57 , V_204 = 0 , V_205 = 0 ;
int V_206 ;
V_200 = V_175 = F_70 ( V_35 , V_207 ) - 1 ;
if ( F_4 ( ( V_175 == - 1 ) || V_175 > V_207 - 1 ) ) {
F_71 ( 1 ) ;
F_72 ( V_208 , V_61 , 0 ) ;
return - 1 ;
}
do {
if ( V_200 > V_203 )
V_201 = V_203 ;
else
V_201 = V_200 ;
V_206 = F_73 ( V_196 , V_198 , V_201 ) ;
if ( V_206 ) {
F_71 ( 1 ) ;
F_72 ( V_208 , V_61 , 0 ) ;
return - 1 ;
}
V_196 [ V_201 ] = '\0' ;
V_204 = F_74 ( V_196 , V_201 ) ;
if ( V_204 ) {
V_202 = V_203 / 2 ;
break;
}
V_200 -= V_201 ;
V_198 += V_201 ;
} while ( V_200 > 0 );
V_200 = V_175 ;
if ( V_175 > V_202 )
V_205 = 1 ;
for ( V_57 = 0 ; V_200 > 0 ; V_57 ++ ) {
int V_209 ;
if ( V_200 > V_202 )
V_201 = V_202 ;
else
V_201 = V_200 ;
V_209 = V_203 - V_199 - * V_195 ;
if ( V_204 )
V_209 -= ( V_201 * 2 ) ;
else
V_209 -= V_201 ;
if ( V_209 < 0 ) {
* V_195 = 0 ;
F_68 ( * V_174 ) ;
* V_174 = F_67 ( V_146 , V_41 , V_210 ) ;
if ( ! * V_174 )
return 0 ;
}
if ( ( V_57 == 0 ) && ( V_205 ) )
F_57 ( * V_174 , L_19 , V_194 ,
V_204 ? 2 * V_175 : V_175 ) ;
if ( V_175 >= V_202 )
V_206 = F_73 ( V_196 , V_35 , V_201 ) ;
else
V_206 = 0 ;
if ( V_206 ) {
F_71 ( 1 ) ;
F_72 ( V_208 , V_61 , 0 ) ;
return - 1 ;
}
V_196 [ V_201 ] = '\0' ;
F_57 ( * V_174 , L_20 , V_194 ) ;
if ( V_205 )
F_57 ( * V_174 , L_21 , V_57 ) ;
F_57 ( * V_174 , L_22 ) ;
if ( V_204 )
F_75 ( * V_174 , V_196 , V_201 ) ;
else
F_76 ( * V_174 , V_196 ) ;
V_35 += V_201 ;
V_200 -= V_201 ;
* V_195 += V_199 ;
if ( V_204 )
* V_195 += V_201 * 2 ;
else
* V_195 += V_201 ;
}
return V_175 + 1 ;
}
static void F_77 ( struct V_7 * V_146 ,
struct V_173 * * V_174 ,
struct V_211 * V_212 )
{
int V_57 ;
T_5 V_175 , V_195 = 0 ;
const char T_6 * V_35 ;
char * V_196 ;
if ( V_212 -> V_180 != V_61 -> V_180 )
return;
V_35 = ( const char T_6 * ) V_212 -> V_180 -> V_213 ;
F_57 ( * V_174 , L_23 , V_212 -> V_214 ) ;
V_196 = F_49 ( V_203 + 1 , V_41 ) ;
if ( ! V_196 ) {
F_59 ( L_24 ) ;
return;
}
for ( V_57 = 0 ; V_57 < V_212 -> V_214 ; V_57 ++ ) {
V_175 = F_69 ( V_146 , V_174 , V_57 ,
& V_195 , V_35 , V_196 ) ;
if ( V_175 <= 0 )
break;
V_35 += V_175 ;
}
F_17 ( V_196 ) ;
}
static void F_78 ( struct V_173 * V_174 , char * V_215 , T_7 * V_216 )
{
int V_57 ;
F_57 ( V_174 , L_25 , V_215 ) ;
F_79 (i) {
F_57 ( V_174 , L_26 , V_216 -> V_216 [ ( V_217 - 1 ) - V_57 ] ) ;
}
}
static void F_80 ( struct V_173 * V_174 , struct V_51 * V_52 )
{
T_7 * V_218 = & V_52 -> V_219 . V_220 ;
T_7 * V_221 = & V_52 -> V_219 . V_222 ;
int log = 0 ;
if ( ! F_81 ( * V_218 ) ) {
F_78 ( V_174 , L_27 , V_218 ) ;
log = 1 ;
}
if ( ! F_81 ( * V_221 ) ) {
F_78 ( V_174 , L_28 , V_221 ) ;
log = 1 ;
}
if ( log )
F_57 ( V_174 , L_29 , V_52 -> V_219 . V_223 , V_52 -> V_224 ) ;
}
static void F_82 ( struct V_7 * V_146 , int * V_225 )
{
struct V_173 * V_174 ;
int V_57 ;
V_174 = F_67 ( V_146 , V_41 , V_146 -> type ) ;
if ( ! V_174 )
return;
switch ( V_146 -> type ) {
case V_226 : {
int V_227 = V_146 -> V_228 . V_227 ;
F_57 ( V_174 , L_30 , V_227 ) ;
for ( V_57 = 0 ; V_57 < V_227 ; V_57 ++ )
F_57 ( V_174 , L_31 , V_57 ,
V_146 -> V_228 . args [ V_57 ] ) ;
break; }
case V_119 : {
T_2 V_118 = V_146 -> V_120 . V_118 ;
F_57 ( V_174 , L_32 ,
V_146 -> V_120 . V_74 , V_146 -> V_120 . V_82 , V_146 -> V_120 . V_25 ) ;
if ( V_118 ) {
char * V_8 = NULL ;
T_2 V_175 ;
if ( F_56 ( V_118 , & V_8 , & V_175 ) ) {
F_57 ( V_174 , L_33 , V_118 ) ;
* V_225 = 1 ;
} else {
F_57 ( V_174 , L_16 , V_8 ) ;
F_58 ( V_8 , V_175 ) ;
}
}
if ( V_146 -> V_120 . V_229 ) {
F_68 ( V_174 ) ;
V_174 = F_67 ( V_146 , V_41 ,
V_230 ) ;
F_57 ( V_174 ,
L_34 ,
V_146 -> V_120 . V_231 ,
V_146 -> V_120 . V_232 ,
V_146 -> V_120 . V_233 ,
V_146 -> V_120 . V_234 ) ;
if ( ! V_174 )
return;
}
break; }
case V_235 : {
F_57 ( V_174 ,
L_35
L_36 ,
V_146 -> V_236 . V_237 , V_146 -> V_236 . V_25 ,
V_146 -> V_236 . V_238 . V_239 ,
V_146 -> V_236 . V_238 . V_240 ,
V_146 -> V_236 . V_238 . V_241 ,
V_146 -> V_236 . V_238 . V_242 ) ;
break; }
case V_243 : {
F_57 ( V_174 ,
L_37
L_38 ,
V_146 -> V_244 . V_245 ,
V_146 -> V_244 . V_246 ,
V_146 -> V_244 . V_247 ,
V_146 -> V_244 . V_248 . V_249 ,
V_146 -> V_244 . V_248 . V_250 ) ;
break; }
case V_251 : {
F_57 ( V_174 , L_39 ,
V_146 -> V_252 . V_245 ,
V_146 -> V_252 . V_253 ) ;
break; }
case V_254 : {
struct V_255 * V_238 = & V_146 -> V_256 . V_257 ;
F_57 ( V_174 ,
L_40
L_41 ,
V_146 -> V_256 . V_245 ,
V_238 -> V_239 , V_238 -> V_240 ,
V_238 -> V_241 , V_238 -> V_242 ) ;
break; }
case V_258 : {
F_57 ( V_174 , L_42 , V_146 -> V_259 . V_68 ) ;
F_78 ( V_174 , L_43 , & V_146 -> V_259 . V_216 . V_222 ) ;
F_78 ( V_174 , L_44 , & V_146 -> V_259 . V_216 . V_220 ) ;
F_78 ( V_174 , L_45 , & V_146 -> V_259 . V_216 . V_260 ) ;
break; }
case V_261 : {
F_57 ( V_174 , L_46 , V_146 -> V_184 . V_262 ,
V_146 -> V_184 . V_1 ) ;
break; }
}
F_68 ( V_174 ) ;
}
static void F_83 ( struct V_7 * V_146 , struct V_47 * V_48 )
{
const struct V_56 * V_56 ;
int V_57 , V_225 = 0 ;
struct V_173 * V_174 ;
struct V_164 * V_165 ;
const char * V_263 ;
V_146 -> V_68 = V_48 -> V_68 ;
if ( ! V_146 -> V_72 )
V_146 -> V_72 = F_23 () ;
V_56 = F_84 () ;
V_146 -> V_74 = V_56 -> V_74 ;
V_146 -> V_82 = V_56 -> V_82 ;
V_146 -> V_76 = V_56 -> V_76 ;
V_146 -> V_78 = V_56 -> V_78 ;
V_146 -> V_80 = V_56 -> V_80 ;
V_146 -> V_84 = V_56 -> V_84 ;
V_146 -> V_86 = V_56 -> V_86 ;
V_146 -> V_88 = V_56 -> V_88 ;
V_146 -> V_90 = V_48 -> V_90 ;
V_174 = F_67 ( V_146 , V_41 , V_264 ) ;
if ( ! V_174 )
return;
F_57 ( V_174 , L_47 ,
V_146 -> V_10 , V_146 -> V_9 ) ;
if ( V_146 -> V_90 != V_265 )
F_57 ( V_174 , L_48 , V_146 -> V_90 ) ;
if ( V_146 -> V_93 )
F_57 ( V_174 , L_49 ,
( V_146 -> V_93 == V_96 ) ? L_50 : L_51 ,
V_146 -> V_94 ) ;
F_85 ( & V_48 -> V_266 -> V_267 ) ;
if ( V_48 -> signal && V_48 -> signal -> V_263 && V_48 -> signal -> V_263 -> V_52 )
V_263 = V_48 -> signal -> V_263 -> V_52 ;
else
V_263 = L_52 ;
F_86 ( & V_48 -> V_266 -> V_267 ) ;
F_57 ( V_174 ,
L_53
L_54
L_55
L_56 ,
V_146 -> V_19 [ 0 ] ,
V_146 -> V_19 [ 1 ] ,
V_146 -> V_19 [ 2 ] ,
V_146 -> V_19 [ 3 ] ,
V_146 -> V_26 ,
V_146 -> V_72 ,
V_146 -> V_68 ,
V_48 -> V_106 ,
V_146 -> V_74 ,
V_146 -> V_82 ,
V_146 -> V_76 , V_146 -> V_78 , V_146 -> V_80 ,
V_146 -> V_84 , V_146 -> V_86 , V_146 -> V_88 , V_263 ,
V_48 -> V_191 ) ;
F_60 ( V_174 , V_48 ) ;
F_87 ( V_174 , V_146 -> V_128 ) ;
F_68 ( V_174 ) ;
for ( V_165 = V_146 -> V_165 ; V_165 ; V_165 = V_165 -> V_40 ) {
V_174 = F_67 ( V_146 , V_41 , V_165 -> type ) ;
if ( ! V_174 )
continue;
switch ( V_165 -> type ) {
case V_210 : {
struct V_211 * V_212 = ( void * ) V_165 ;
F_77 ( V_146 , & V_174 , V_212 ) ;
break; }
case V_268 : {
struct V_269 * V_270 = ( void * ) V_165 ;
F_57 ( V_174 , L_57 , V_270 -> V_224 ) ;
F_78 ( V_174 , L_58 , & V_270 -> V_219 . V_220 ) ;
F_78 ( V_174 , L_59 , & V_270 -> V_219 . V_222 ) ;
F_57 ( V_174 , L_60 , V_270 -> V_219 . V_223 ) ;
F_78 ( V_174 , L_61 , & V_270 -> V_271 . V_220 ) ;
F_78 ( V_174 , L_62 , & V_270 -> V_271 . V_222 ) ;
F_78 ( V_174 , L_63 , & V_270 -> V_271 . V_260 ) ;
F_78 ( V_174 , L_64 , & V_270 -> V_272 . V_220 ) ;
F_78 ( V_174 , L_65 , & V_270 -> V_272 . V_222 ) ;
F_78 ( V_174 , L_66 , & V_270 -> V_272 . V_260 ) ;
break; }
}
F_68 ( V_174 ) ;
}
if ( V_146 -> type )
F_82 ( V_146 , & V_225 ) ;
if ( V_146 -> V_273 [ 0 ] >= 0 ) {
V_174 = F_67 ( V_146 , V_41 , V_274 ) ;
if ( V_174 ) {
F_57 ( V_174 , L_67 ,
V_146 -> V_273 [ 0 ] , V_146 -> V_273 [ 1 ] ) ;
F_68 ( V_174 ) ;
}
}
if ( V_146 -> V_275 ) {
V_174 = F_67 ( V_146 , V_41 , V_276 ) ;
if ( V_174 ) {
F_57 ( V_174 , L_68 ) ;
F_75 ( V_174 , ( void * ) V_146 -> V_172 ,
V_146 -> V_275 ) ;
F_68 ( V_174 ) ;
}
}
for ( V_165 = V_146 -> V_166 ; V_165 ; V_165 = V_165 -> V_40 ) {
struct V_277 * V_270 = ( void * ) V_165 ;
for ( V_57 = 0 ; V_57 < V_270 -> V_278 ; V_57 ++ )
if ( F_66 ( V_146 , V_270 -> V_279 [ V_57 ] ,
V_270 -> V_280 [ V_57 ] ,
V_270 -> V_281 [ V_57 ] ,
V_270 -> V_282 [ V_57 ] ,
V_270 -> V_283 [ V_57 ] ,
V_270 -> V_284 [ V_57 ] ) )
V_225 = 1 ;
}
if ( V_146 -> V_279 &&
F_66 ( V_146 , V_146 -> V_279 ,
V_146 -> V_280 , V_146 -> V_281 ,
V_146 -> V_282 ,
V_146 -> V_283 , V_146 -> V_284 ) )
V_225 = 1 ;
if ( V_146 -> V_161 . V_162 && V_146 -> V_161 . V_163 ) {
V_174 = F_67 ( V_146 , V_41 , V_285 ) ;
if ( V_174 ) {
F_64 ( V_174 , L_69 , & V_146 -> V_161 ) ;
F_68 ( V_174 ) ;
}
}
for ( V_57 = 0 ; V_57 < V_146 -> V_26 ; V_57 ++ ) {
struct V_51 * V_3 = & V_146 -> V_27 [ V_57 ] ;
V_174 = F_67 ( V_146 , V_41 , V_286 ) ;
if ( ! V_174 )
continue;
F_57 ( V_174 , L_70 , V_57 ) ;
if ( V_3 -> V_52 ) {
switch( V_3 -> V_287 ) {
case V_288 :
F_57 ( V_174 , L_71 ) ;
F_62 ( V_174 , V_3 -> V_52 ) ;
break;
case 0 :
F_64 ( V_174 , L_72 , & V_146 -> V_161 ) ;
break;
default:
F_57 ( V_174 , L_71 ) ;
F_88 ( V_174 , V_3 -> V_52 ,
V_3 -> V_287 ) ;
}
} else
F_57 ( V_174 , L_73 ) ;
if ( V_3 -> V_28 != ( unsigned long ) - 1 ) {
F_57 ( V_174 , L_74
L_75
L_76 ,
V_3 -> V_28 ,
F_24 ( V_3 -> V_99 ) ,
F_25 ( V_3 -> V_99 ) ,
V_3 -> V_25 ,
V_3 -> V_74 ,
V_3 -> V_82 ,
F_24 ( V_3 -> V_289 ) ,
F_25 ( V_3 -> V_289 ) ) ;
}
if ( V_3 -> V_118 != 0 ) {
char * V_8 = NULL ;
T_2 V_175 ;
if ( F_56 (
V_3 -> V_118 , & V_8 , & V_175 ) ) {
F_57 ( V_174 , L_33 , V_3 -> V_118 ) ;
V_225 = 2 ;
} else {
F_57 ( V_174 , L_16 , V_8 ) ;
F_58 ( V_8 , V_175 ) ;
}
}
F_80 ( V_174 , V_3 ) ;
F_68 ( V_174 ) ;
}
V_174 = F_67 ( V_146 , V_41 , V_290 ) ;
if ( V_174 )
F_68 ( V_174 ) ;
if ( V_225 )
F_59 ( L_77 ) ;
}
void F_89 ( struct V_47 * V_48 )
{
struct V_7 * V_146 ;
V_146 = F_40 ( V_48 , 0 , 0 ) ;
if ( F_10 ( ! V_146 ) )
return;
if ( V_146 -> V_151 && V_146 -> V_30 == V_31 )
F_83 ( V_146 , V_48 ) ;
if ( ! F_35 ( & V_146 -> V_167 ) )
F_90 ( & V_146 -> V_167 ) ;
F_54 ( V_146 ) ;
}
void F_91 ( int V_10 , int V_9 ,
unsigned long V_291 , unsigned long V_292 ,
unsigned long V_293 , unsigned long V_294 )
{
struct V_47 * V_48 = V_61 ;
struct V_7 * V_146 = V_48 -> V_7 ;
enum V_53 V_54 ;
if ( F_4 ( ! V_146 ) )
return;
if ( V_146 -> V_151 ) {
struct V_7 * V_295 ;
#if V_155
F_42 ( V_158
L_78
L_79 ,
V_146 -> V_159 , V_48 -> V_68 , V_146 -> V_9 , V_9 ) ;
#endif
V_295 = F_48 ( V_146 -> V_54 ) ;
if ( V_295 ) {
V_295 -> V_171 = V_146 ;
V_146 = V_295 ;
V_48 -> V_7 = V_295 ;
} else {
F_47 ( V_146 , V_146 -> V_54 ) ;
}
}
F_92 ( V_146 -> V_151 || V_146 -> V_26 ) ;
if ( ! V_296 )
return;
V_146 -> V_10 = V_10 ;
V_146 -> V_9 = V_9 ;
V_146 -> V_19 [ 0 ] = V_291 ;
V_146 -> V_19 [ 1 ] = V_292 ;
V_146 -> V_19 [ 2 ] = V_293 ;
V_146 -> V_19 [ 3 ] = V_294 ;
V_54 = V_146 -> V_54 ;
V_146 -> V_152 = ! V_297 ;
if ( ! V_146 -> V_152 && V_54 == V_137 ) {
V_146 -> V_29 = 0 ;
V_54 = F_34 ( V_48 , V_146 , & V_153 [ V_298 ] ) ;
}
if ( F_10 ( V_54 == V_132 ) )
return;
V_146 -> V_159 = 0 ;
V_146 -> ctime = V_299 ;
V_146 -> V_151 = 1 ;
V_146 -> V_30 = V_54 ;
V_146 -> V_72 = 0 ;
}
void F_93 ( struct V_47 * V_300 )
{
struct V_7 * V_8 = V_61 -> V_7 ;
struct V_7 * V_35 = V_300 -> V_7 ;
if ( ! V_35 || ! V_8 )
return;
if ( ! V_8 -> V_151 || V_8 -> V_30 != V_31 )
return;
V_35 -> V_10 = V_8 -> V_10 ;
V_35 -> V_9 = V_8 -> V_9 ;
memcpy ( V_35 -> V_19 , V_8 -> V_19 , sizeof( V_8 -> V_19 ) ) ;
V_35 -> ctime = V_8 -> ctime ;
V_35 -> V_152 = V_8 -> V_152 ;
V_35 -> V_151 = V_8 -> V_151 ;
V_35 -> V_128 = F_29 ( V_8 -> V_128 , V_41 ) ;
V_35 -> V_72 = V_61 -> V_68 ;
V_35 -> V_29 = V_8 -> V_29 ;
V_35 -> V_30 = V_8 -> V_30 ;
}
void F_94 ( int V_301 , long V_94 )
{
struct V_47 * V_48 = V_61 ;
struct V_7 * V_146 ;
V_146 = F_40 ( V_48 , V_301 , V_94 ) ;
if ( F_10 ( ! V_146 ) )
return;
if ( V_146 -> V_151 && V_146 -> V_30 == V_31 )
F_83 ( V_146 , V_48 ) ;
V_146 -> V_151 = 0 ;
V_146 -> V_29 = V_146 -> V_54 == V_31 ? ~ 0ULL : 0 ;
if ( ! F_35 ( & V_146 -> V_167 ) )
F_90 ( & V_146 -> V_167 ) ;
if ( V_146 -> V_171 ) {
struct V_7 * V_302 = V_146 -> V_171 ;
V_146 -> V_171 = NULL ;
F_54 ( V_146 ) ;
V_48 -> V_7 = V_302 ;
} else {
F_41 ( V_146 ) ;
F_13 ( V_146 , NULL , 0 ) ;
F_46 ( V_146 ) ;
V_146 -> V_165 = NULL ;
V_146 -> V_166 = NULL ;
V_146 -> V_279 = 0 ;
V_146 -> V_283 = 0 ;
V_146 -> V_275 = 0 ;
V_146 -> type = 0 ;
V_146 -> V_273 [ 0 ] = - 1 ;
if ( V_146 -> V_54 != V_31 ) {
F_17 ( V_146 -> V_128 ) ;
V_146 -> V_128 = NULL ;
}
V_48 -> V_7 = V_146 ;
}
}
static inline void F_95 ( const struct V_303 * V_303 )
{
#ifdef F_14
struct V_7 * V_146 ;
struct V_34 * V_35 ;
struct V_32 * V_33 ;
int V_43 ;
if ( F_10 ( F_96 ( & V_303 -> V_304 ) ) )
return;
V_146 = V_61 -> V_7 ;
V_35 = V_146 -> V_36 ;
V_43 = V_146 -> V_38 ;
F_31 () ;
V_33 = F_97 ( V_303 ) ;
F_33 () ;
if ( ! V_33 )
return;
if ( F_10 ( F_9 ( V_146 , V_33 ) ) )
return;
if ( F_4 ( ! F_11 ( V_146 ) ) ) {
F_42 ( V_305 L_80 ) ;
F_8 ( V_146 ) ;
F_15 ( V_33 ) ;
F_13 ( V_146 , V_35 , V_43 ) ;
return;
}
F_9 ( V_146 , V_33 ) ;
#endif
}
static void F_98 ( const struct V_162 * V_162 )
{
#ifdef F_14
struct V_7 * V_146 ;
struct V_34 * V_35 ;
const struct V_162 * V_306 , * V_307 ;
struct V_32 * V_308 ;
unsigned long V_309 ;
int V_43 ;
V_146 = V_61 -> V_7 ;
V_35 = V_146 -> V_36 ;
V_43 = V_146 -> V_38 ;
V_310:
V_308 = NULL ;
V_306 = V_162 ;
F_31 () ;
V_309 = F_99 ( & V_311 ) ;
for(; ; ) {
struct V_303 * V_303 = V_306 -> V_312 ;
if ( V_303 && F_4 ( ! F_96 ( & V_303 -> V_304 ) ) ) {
struct V_32 * V_33 ;
V_33 = F_97 ( V_303 ) ;
if ( V_33 ) {
if ( F_4 ( ! F_9 ( V_146 , V_33 ) ) ) {
V_308 = V_33 ;
break;
}
}
}
V_307 = V_306 -> V_313 ;
if ( V_307 == V_306 )
break;
V_306 = V_307 ;
}
if ( F_4 ( F_100 ( & V_311 , V_309 ) || V_308 ) ) {
F_33 () ;
if ( ! V_308 ) {
F_13 ( V_146 , V_35 , V_43 ) ;
goto V_310;
}
F_15 ( V_308 ) ;
if ( F_11 ( V_146 ) ) {
F_13 ( V_146 , V_35 , V_43 ) ;
goto V_310;
}
F_42 ( V_305
L_80 ) ;
F_13 ( V_146 , V_35 , V_43 ) ;
F_8 ( V_146 ) ;
return;
}
F_33 () ;
#endif
}
void F_101 ( const char * V_52 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
if ( F_102 ( V_52 ) || ! V_52 )
return;
if ( ! V_146 -> V_151 ) {
#if V_155 == 2
F_42 ( V_158 L_81 ,
__FILE__ , __LINE__ , V_146 -> V_159 , V_52 ) ;
F_43 () ;
#endif
return;
}
F_92 ( V_146 -> V_26 >= V_314 ) ;
V_146 -> V_27 [ V_146 -> V_26 ] . V_52 = V_52 ;
V_146 -> V_27 [ V_146 -> V_26 ] . V_287 = V_288 ;
V_146 -> V_27 [ V_146 -> V_26 ] . V_160 = 1 ;
V_146 -> V_27 [ V_146 -> V_26 ] . V_28 = ( unsigned long ) - 1 ;
V_146 -> V_27 [ V_146 -> V_26 ] . V_118 = 0 ;
++ V_146 -> V_26 ;
if ( ! V_146 -> V_161 . V_162 )
F_103 ( V_61 -> V_315 , & V_146 -> V_161 ) ;
}
void F_104 ( const char * V_52 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
F_92 ( ! V_146 ) ;
if ( ! V_146 -> V_151 ) {
#if V_155 == 2
F_42 ( V_158 L_82 ,
__FILE__ , __LINE__ , V_146 -> V_159 , V_52 ) ;
if ( V_146 -> V_26 ) {
int V_57 ;
for ( V_57 = 0 ; V_57 < V_146 -> V_26 ; V_57 ++ )
F_42 ( V_158 L_83 , V_57 ,
V_146 -> V_27 [ V_57 ] . V_52 ,
V_146 -> V_27 [ V_57 ] . V_52 ? : L_5 ) ;
}
#endif
F_44 ( V_52 ) ;
}
#if V_155
else {
++ V_146 -> V_156 ;
if ( V_146 -> V_156 > V_146 -> V_26 ) {
F_42 ( V_158 L_84
L_85
L_86 ,
__FILE__ , __LINE__ ,
V_146 -> V_159 , V_146 -> V_9 ,
V_146 -> V_151 , V_52 , V_146 -> V_26 ,
V_146 -> V_156 ) ;
F_43 () ;
}
}
#endif
}
static int F_105 ( struct V_7 * V_146 ,
const struct V_303 * V_303 )
{
if ( V_146 -> V_26 >= V_314 ) {
if ( V_303 )
F_42 ( V_316 L_87
L_88 ,
F_24 ( V_303 -> V_317 -> V_318 ) ,
F_25 ( V_303 -> V_317 -> V_318 ) ,
V_303 -> V_319 ) ;
else
F_42 ( V_316 L_89 ) ;
return 1 ;
}
V_146 -> V_26 ++ ;
#if V_155
V_146 -> V_157 ++ ;
#endif
return 0 ;
}
static inline int F_106 ( struct V_51 * V_52 , const struct V_162 * V_162 )
{
struct V_320 V_321 ;
int V_192 ;
memset ( & V_52 -> V_219 . V_220 , 0 , sizeof( T_7 ) ) ;
memset ( & V_52 -> V_219 . V_222 , 0 , sizeof( T_7 ) ) ;
V_52 -> V_219 . V_223 = 0 ;
V_52 -> V_224 = 0 ;
if ( ! V_162 )
return 0 ;
V_192 = F_107 ( V_162 , & V_321 ) ;
if ( V_192 )
return V_192 ;
V_52 -> V_219 . V_220 = V_321 . V_220 ;
V_52 -> V_219 . V_222 = V_321 . V_222 ;
V_52 -> V_219 . V_223 = ! ! ( V_321 . V_322 & V_323 ) ;
V_52 -> V_224 = ( V_321 . V_322 & V_324 ) >> V_325 ;
return 0 ;
}
static void F_108 ( struct V_51 * V_52 , const struct V_162 * V_162 ,
const struct V_303 * V_303 )
{
V_52 -> V_28 = V_303 -> V_319 ;
V_52 -> V_99 = V_303 -> V_317 -> V_318 ;
V_52 -> V_25 = V_303 -> V_326 ;
V_52 -> V_74 = V_303 -> V_327 ;
V_52 -> V_82 = V_303 -> V_328 ;
V_52 -> V_289 = V_303 -> V_329 ;
F_109 ( V_303 , & V_52 -> V_118 ) ;
F_106 ( V_52 , V_162 ) ;
}
void F_110 ( const char * V_52 , const struct V_162 * V_162 )
{
int V_330 ;
struct V_7 * V_146 = V_61 -> V_7 ;
const struct V_303 * V_303 = V_162 -> V_312 ;
if ( ! V_146 -> V_151 )
return;
if ( V_146 -> V_26
&& V_146 -> V_27 [ V_146 -> V_26 - 1 ] . V_52
&& V_146 -> V_27 [ V_146 -> V_26 - 1 ] . V_52 == V_52 )
V_330 = V_146 -> V_26 - 1 ;
else if ( V_146 -> V_26 > 1
&& V_146 -> V_27 [ V_146 -> V_26 - 2 ] . V_52
&& V_146 -> V_27 [ V_146 -> V_26 - 2 ] . V_52 == V_52 )
V_330 = V_146 -> V_26 - 2 ;
else {
if ( F_105 ( V_146 , V_303 ) )
return;
V_330 = V_146 -> V_26 - 1 ;
V_146 -> V_27 [ V_330 ] . V_52 = NULL ;
}
F_98 ( V_162 ) ;
F_108 ( & V_146 -> V_27 [ V_330 ] , V_162 , V_303 ) ;
}
void F_111 ( const struct V_162 * V_162 ,
const struct V_303 * V_307 )
{
int V_330 ;
struct V_7 * V_146 = V_61 -> V_7 ;
const char * V_331 = NULL , * V_332 = NULL ;
const struct V_303 * V_303 = V_162 -> V_312 ;
const char * V_333 = V_162 -> V_334 . V_52 ;
int V_335 = 0 ;
if ( ! V_146 -> V_151 )
return;
if ( V_303 )
F_95 ( V_303 ) ;
for ( V_330 = 0 ; V_330 < V_146 -> V_26 ; V_330 ++ ) {
struct V_51 * V_3 = & V_146 -> V_27 [ V_330 ] ;
if ( ! V_3 -> V_52 )
continue;
if ( V_3 -> V_28 == V_307 -> V_319 &&
! F_112 ( V_333 , V_3 -> V_52 , & V_335 ) ) {
V_3 -> V_287 = V_335 ;
V_331 = V_3 -> V_52 ;
goto V_336;
}
}
for ( V_330 = 0 ; V_330 < V_146 -> V_26 ; V_330 ++ ) {
struct V_51 * V_3 = & V_146 -> V_27 [ V_330 ] ;
if ( ! V_3 -> V_52 )
continue;
if ( ! strcmp ( V_333 , V_3 -> V_52 ) ||
! F_112 ( V_333 , V_3 -> V_52 , & V_335 ) ) {
if ( V_303 )
F_108 ( V_3 , NULL , V_303 ) ;
else
V_3 -> V_28 = ( unsigned long ) - 1 ;
V_332 = V_3 -> V_52 ;
goto V_336;
}
}
V_336:
if ( ! V_331 ) {
if ( F_105 ( V_146 , V_307 ) )
return;
V_330 = V_146 -> V_26 - 1 ;
V_146 -> V_27 [ V_330 ] . V_52 = NULL ;
F_108 ( & V_146 -> V_27 [ V_330 ] , NULL , V_307 ) ;
}
if ( ! V_332 ) {
if ( F_105 ( V_146 , V_303 ) )
return;
V_330 = V_146 -> V_26 - 1 ;
if ( V_331 ) {
V_146 -> V_27 [ V_330 ] . V_52 = V_331 ;
V_146 -> V_27 [ V_330 ] . V_287 = V_288 ;
V_146 -> V_27 [ V_330 ] . V_160 = 0 ;
} else {
V_146 -> V_27 [ V_330 ] . V_52 = NULL ;
}
if ( V_303 )
F_108 ( & V_146 -> V_27 [ V_330 ] , NULL , V_303 ) ;
else
V_146 -> V_27 [ V_330 ] . V_28 = ( unsigned long ) - 1 ;
}
}
int F_113 ( struct V_7 * V_8 ,
struct V_337 * V_338 , unsigned int * V_159 )
{
if ( ! V_8 -> V_151 )
return 0 ;
if ( ! V_8 -> V_159 )
V_8 -> V_159 = F_114 () ;
V_338 -> V_249 = V_8 -> ctime . V_249 ;
V_338 -> V_250 = V_8 -> ctime . V_250 ;
* V_159 = V_8 -> V_159 ;
if ( ! V_8 -> V_29 ) {
V_8 -> V_29 = 1 ;
V_8 -> V_30 = V_31 ;
}
return 1 ;
}
int F_115 ( struct V_47 * V_339 , T_4 V_106 )
{
unsigned int V_191 = F_116 ( & V_340 ) ;
struct V_7 * V_146 = V_339 -> V_7 ;
if ( V_146 && V_146 -> V_151 ) {
struct V_173 * V_174 ;
V_174 = F_67 ( NULL , V_41 , V_341 ) ;
if ( V_174 ) {
F_57 ( V_174 , L_90
L_91
L_92 ,
V_339 -> V_68 , F_117 ( V_339 ) ,
V_339 -> V_106 , V_106 ,
V_339 -> V_191 , V_191 ) ;
F_68 ( V_174 ) ;
}
}
V_339 -> V_191 = V_191 ;
V_339 -> V_106 = V_106 ;
return 0 ;
}
void F_118 ( int V_237 , T_1 V_25 , struct V_255 * V_238 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
if ( V_238 )
memcpy ( & V_146 -> V_236 . V_238 , V_238 , sizeof( struct V_255 ) ) ;
else
memset ( & V_146 -> V_236 . V_238 , 0 , sizeof( struct V_255 ) ) ;
V_146 -> V_236 . V_237 = V_237 ;
V_146 -> V_236 . V_25 = V_25 ;
V_146 -> type = V_235 ;
}
void F_119 ( T_8 V_245 , T_5 V_246 , unsigned int V_247 ,
const struct V_337 * V_248 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
struct V_337 * V_35 = & V_146 -> V_244 . V_248 ;
if ( V_248 )
memcpy ( V_35 , V_248 , sizeof( struct V_337 ) ) ;
else
memset ( V_35 , 0 , sizeof( struct V_337 ) ) ;
V_146 -> V_244 . V_245 = V_245 ;
V_146 -> V_244 . V_246 = V_246 ;
V_146 -> V_244 . V_247 = V_247 ;
V_146 -> type = V_243 ;
}
void F_120 ( T_8 V_245 , const struct V_342 * V_343 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
if ( V_343 )
V_146 -> V_252 . V_253 = V_343 -> V_253 ;
else
V_146 -> V_252 . V_253 = 0 ;
V_146 -> V_252 . V_245 = V_245 ;
V_146 -> type = V_251 ;
}
void F_121 ( T_8 V_245 , struct V_255 * V_257 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_256 . V_245 = V_245 ;
V_146 -> V_256 . V_257 = * V_257 ;
V_146 -> type = V_254 ;
}
void F_122 ( struct V_344 * V_345 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_120 . V_74 = V_345 -> V_74 ;
V_146 -> V_120 . V_82 = V_345 -> V_82 ;
V_146 -> V_120 . V_25 = V_345 -> V_25 ;
V_146 -> V_120 . V_229 = 0 ;
F_123 ( V_345 , & V_146 -> V_120 . V_118 ) ;
V_146 -> type = V_119 ;
}
void F_124 ( unsigned long V_231 , T_4 V_74 , T_9 V_82 , T_1 V_25 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_120 . V_231 = V_231 ;
V_146 -> V_120 . V_232 = V_74 ;
V_146 -> V_120 . V_233 = V_82 ;
V_146 -> V_120 . V_234 = V_25 ;
V_146 -> V_120 . V_229 = 1 ;
}
int F_125 ( struct V_346 * V_347 )
{
struct V_211 * V_348 ;
struct V_7 * V_146 = V_61 -> V_7 ;
if ( F_10 ( ! V_296 || ! V_146 || V_146 -> V_152 ) )
return 0 ;
V_348 = F_49 ( sizeof( * V_348 ) , V_41 ) ;
if ( ! V_348 )
return - V_169 ;
V_348 -> V_214 = V_347 -> V_214 ;
V_348 -> V_349 = V_347 -> V_349 ;
V_348 -> V_180 = V_347 -> V_180 ;
V_348 -> V_306 . type = V_210 ;
V_348 -> V_306 . V_40 = V_146 -> V_165 ;
V_146 -> V_165 = ( void * ) V_348 ;
return 0 ;
}
void F_126 ( int V_227 , unsigned long * args )
{
struct V_7 * V_146 = V_61 -> V_7 ;
if ( F_10 ( ! V_146 || V_146 -> V_152 ) )
return;
V_146 -> type = V_226 ;
V_146 -> V_228 . V_227 = V_227 ;
memcpy ( V_146 -> V_228 . args , args , V_227 * sizeof( unsigned long ) ) ;
}
void F_127 ( int V_350 , int V_351 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_273 [ 0 ] = V_350 ;
V_146 -> V_273 [ 1 ] = V_351 ;
}
int F_128 ( int V_175 , void * V_352 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
if ( F_10 ( ! V_146 || V_146 -> V_152 ) )
return 0 ;
if ( ! V_146 -> V_172 ) {
void * V_35 = F_49 ( sizeof( struct V_353 ) , V_41 ) ;
if ( ! V_35 )
return - V_169 ;
V_146 -> V_172 = V_35 ;
}
V_146 -> V_275 = V_175 ;
memcpy ( V_146 -> V_172 , V_352 , V_175 ) ;
return 0 ;
}
void F_129 ( struct V_47 * V_338 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_279 = V_338 -> V_68 ;
V_146 -> V_280 = F_130 ( V_338 ) ;
V_146 -> V_281 = F_117 ( V_338 ) ;
V_146 -> V_282 = F_131 ( V_338 ) ;
F_27 ( V_338 , & V_146 -> V_283 ) ;
memcpy ( V_146 -> V_284 , V_338 -> V_178 , V_354 ) ;
}
int F_132 ( int V_355 , struct V_47 * V_338 )
{
struct V_277 * V_356 ;
struct V_47 * V_48 = V_61 ;
struct V_7 * V_8 = V_48 -> V_7 ;
T_4 V_74 = F_133 () , V_357 = F_117 ( V_338 ) ;
if ( V_140 && V_338 -> V_141 == V_140 ) {
if ( V_355 == V_358 || V_355 == V_359 || V_355 == V_360 || V_355 == V_361 ) {
V_362 = V_48 -> V_68 ;
if ( V_48 -> V_106 != - 1 )
V_363 = V_48 -> V_106 ;
else
V_363 = V_74 ;
F_27 ( V_48 , & V_364 ) ;
}
if ( ! V_365 || F_134 () )
return 0 ;
}
if ( ! V_8 -> V_279 ) {
V_8 -> V_279 = V_338 -> V_141 ;
V_8 -> V_280 = F_130 ( V_338 ) ;
V_8 -> V_281 = V_357 ;
V_8 -> V_282 = F_131 ( V_338 ) ;
F_27 ( V_338 , & V_8 -> V_283 ) ;
memcpy ( V_8 -> V_284 , V_338 -> V_178 , V_354 ) ;
return 0 ;
}
V_356 = ( void * ) V_8 -> V_166 ;
if ( ! V_356 || V_356 -> V_278 == V_366 ) {
V_356 = F_12 ( sizeof( * V_356 ) , V_129 ) ;
if ( ! V_356 )
return - V_169 ;
V_356 -> V_306 . type = V_193 ;
V_356 -> V_306 . V_40 = V_8 -> V_166 ;
V_8 -> V_166 = ( void * ) V_356 ;
}
F_92 ( V_356 -> V_278 >= V_366 ) ;
V_356 -> V_279 [ V_356 -> V_278 ] = V_338 -> V_141 ;
V_356 -> V_280 [ V_356 -> V_278 ] = F_130 ( V_338 ) ;
V_356 -> V_281 [ V_356 -> V_278 ] = V_357 ;
V_356 -> V_282 [ V_356 -> V_278 ] = F_131 ( V_338 ) ;
F_27 ( V_338 , & V_356 -> V_283 [ V_356 -> V_278 ] ) ;
memcpy ( V_356 -> V_284 [ V_356 -> V_278 ] , V_338 -> V_178 , V_354 ) ;
V_356 -> V_278 ++ ;
return 0 ;
}
int F_135 ( struct V_346 * V_347 ,
const struct V_56 * V_367 , const struct V_56 * V_368 )
{
struct V_269 * V_348 ;
struct V_7 * V_146 = V_61 -> V_7 ;
struct V_320 V_369 ;
struct V_162 * V_162 ;
V_348 = F_49 ( sizeof( * V_348 ) , V_41 ) ;
if ( ! V_348 )
return - V_169 ;
V_348 -> V_306 . type = V_268 ;
V_348 -> V_306 . V_40 = V_146 -> V_165 ;
V_146 -> V_165 = ( void * ) V_348 ;
V_162 = F_136 ( V_347 -> V_370 -> V_371 ) ;
F_107 ( V_162 , & V_369 ) ;
F_137 ( V_162 ) ;
V_348 -> V_219 . V_220 = V_369 . V_220 ;
V_348 -> V_219 . V_222 = V_369 . V_222 ;
V_348 -> V_219 . V_223 = ! ! ( V_369 . V_322 & V_323 ) ;
V_348 -> V_224 = ( V_369 . V_322 & V_324 ) >> V_325 ;
V_348 -> V_271 . V_220 = V_368 -> V_372 ;
V_348 -> V_271 . V_222 = V_368 -> V_373 ;
V_348 -> V_271 . V_260 = V_368 -> V_374 ;
V_348 -> V_272 . V_220 = V_367 -> V_372 ;
V_348 -> V_272 . V_222 = V_367 -> V_373 ;
V_348 -> V_272 . V_260 = V_367 -> V_374 ;
return 0 ;
}
void F_138 ( T_3 V_68 ,
const struct V_56 * V_367 , const struct V_56 * V_368 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_259 . V_68 = V_68 ;
V_146 -> V_259 . V_216 . V_260 = V_367 -> V_374 ;
V_146 -> V_259 . V_216 . V_222 = V_367 -> V_374 ;
V_146 -> V_259 . V_216 . V_220 = V_367 -> V_372 ;
V_146 -> type = V_258 ;
}
void F_139 ( int V_262 , int V_1 )
{
struct V_7 * V_146 = V_61 -> V_7 ;
V_146 -> V_184 . V_262 = V_262 ;
V_146 -> V_184 . V_1 = V_1 ;
V_146 -> type = V_261 ;
}
void F_140 ( long V_375 )
{
struct V_173 * V_174 ;
T_2 V_60 ;
T_4 V_190 = F_130 ( V_61 ) , V_74 ;
T_9 V_82 ;
unsigned int V_191 = F_131 ( V_61 ) ;
if ( ! V_296 )
return;
if ( V_375 == V_376 )
return;
V_174 = F_67 ( NULL , V_41 , V_377 ) ;
F_141 ( & V_74 , & V_82 ) ;
F_57 ( V_174 , L_93 ,
V_190 , V_74 , V_82 , V_191 ) ;
F_27 ( V_61 , & V_60 ) ;
if ( V_60 ) {
char * V_8 = NULL ;
T_2 V_175 ;
if ( F_56 ( V_60 , & V_8 , & V_175 ) )
F_57 ( V_174 , L_94 , V_60 ) ;
else {
F_57 ( V_174 , L_10 , V_8 ) ;
F_58 ( V_8 , V_175 ) ;
}
}
F_57 ( V_174 , L_95 , V_61 -> V_68 ) ;
F_62 ( V_174 , V_61 -> V_178 ) ;
F_57 ( V_174 , L_96 , V_375 ) ;
F_68 ( V_174 ) ;
}
struct V_138 * F_142 ( void )
{
struct V_7 * V_8 = V_61 -> V_7 ;
if ( F_10 ( ! V_8 || ! V_8 -> V_151 ) )
return NULL ;
return & V_8 -> V_167 ;
}
