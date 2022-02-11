static int F_1 ( unsigned long V_1 )
{
T_1 V_2 = F_2 ( V_1 ) ;
T_1 V_3 = F_3 ( V_1 ) ;
int V_4 ;
if ( V_1 & ~ V_5 )
return - V_6 ;
switch ( V_2 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
V_4 = V_12 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_4 = V_16 ;
break;
default:
return - V_6 ;
}
if ( V_3 >= V_17 -> V_18 -> V_19 [ V_4 ] . V_20 &&
V_3 <= V_17 -> V_18 -> V_19 [ V_4 ] . V_21 )
return V_1 ;
return - V_6 ;
}
static int F_4 ( void )
{
int V_22 ;
V_22 = F_5 ( V_23 + V_24 ) & V_25 ;
V_22 >>= V_26 ;
if ( V_22 < V_27 )
return V_28 ;
else
return V_29 ;
}
static const struct V_30 * F_6 ( struct V_31 * V_32 )
{
if ( F_7 () )
return & V_33 [ F_4 () ] ;
return NULL ;
}
static int F_8 ( struct V_34 * V_34 , int V_35 )
{
return V_36 <= V_35 &&
V_35 <= F_9 ( V_34 ) ;
}
static T_2 F_10 ( int V_35 , unsigned int V_37 )
{
return F_5 ( V_17 -> V_38 + F_11 ( V_35 ) + V_37 ) ;
}
static void F_12 ( T_2 V_39 , int V_35 , unsigned int V_37 )
{
return F_13 ( V_39 , V_17 -> V_38 + F_11 ( V_35 ) + V_37 ) ;
}
static void F_14 ( int V_35 )
{
F_12 ( 0 , V_35 , V_40 ) ;
}
static void F_15 ( int V_35 )
{
F_12 ( 1 , V_35 , V_40 ) ;
}
static void F_16 ( int V_35 , unsigned long V_41 )
{
F_12 ( V_41 , V_35 , V_42 ) ;
}
static T_2 F_17 ( void )
{
T_2 V_43 = ( F_5 ( V_23 + V_44 ) &
V_45 ) >> V_46 ;
return V_43 + 1 ;
}
static int F_18 ( struct V_47 * V_48 , struct V_49 * V_41 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_50 * V_1 = & V_41 -> V_48 ;
unsigned long V_51 = V_1 -> V_52 ;
int V_35 ;
if ( V_51 == V_53 ) {
if ( F_20 ( V_36 , V_48 -> V_54 ) )
return - V_55 ;
return V_36 ;
}
for ( V_35 = V_56 ; V_35 <= F_9 ( V_34 ) ; ++ V_35 )
if ( ! F_20 ( V_35 , V_48 -> V_54 ) )
return V_35 ;
return - V_55 ;
}
static int F_21 ( struct V_49 * V_41 )
{
int V_57 ;
unsigned long V_58 = V_41 -> V_59 . V_58 ;
if ( V_41 -> V_59 . type < V_60 )
return - V_6 ;
if ( V_58 == V_53 )
V_57 = V_58 ;
else
V_57 = F_1 ( V_58 ) ;
return V_57 ;
}
static int F_22 ( struct V_34 * V_34 , T_3 V_61 )
{
int V_62 ;
struct V_31 * V_63 = V_34 -> V_64 ;
if ( F_23 ( ! V_63 ) )
return - V_65 ;
if ( V_17 -> V_66 < 1 ) {
F_24 ( & V_63 -> V_67 , L_1 ) ;
return - V_65 ;
}
for ( V_62 = 0 ; V_62 < V_17 -> V_66 ; V_62 ++ ) {
int V_68 = F_25 ( V_17 -> V_69 [ V_62 ] , V_61 , V_70 ,
L_2 , V_34 ) ;
if ( V_68 ) {
F_24 ( & V_63 -> V_67 , L_3 ,
V_17 -> V_69 [ V_62 ] ) ;
return V_68 ;
}
F_26 ( V_62 , & V_17 -> V_71 ) ;
}
return 0 ;
}
static void F_27 ( struct V_34 * V_34 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_17 -> V_66 ; V_62 ++ ) {
if ( ! F_28 ( V_62 , & V_17 -> V_71 ) )
continue;
F_29 ( V_17 -> V_69 [ V_62 ] , V_34 ) ;
}
}
static T_2 F_30 ( struct V_49 * V_41 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_50 * V_72 = & V_41 -> V_48 ;
int V_35 = V_72 -> V_35 ;
T_2 V_39 ;
if ( F_23 ( ! F_8 ( V_34 , V_35 ) ) ) {
F_24 ( & V_34 -> V_64 -> V_67 , L_4 , V_35 ) ;
return 0 ;
}
V_39 = F_10 ( V_35 , V_73 ) ;
return V_39 ;
}
static void F_31 ( struct V_49 * V_41 , T_2 V_39 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_50 * V_72 = & V_41 -> V_48 ;
int V_35 = V_72 -> V_35 ;
if ( F_23 ( ! F_8 ( V_34 , V_35 ) ) )
F_24 ( & V_34 -> V_64 -> V_67 , L_4 , V_35 ) ;
else
F_12 ( V_39 , V_35 , V_73 ) ;
}
static T_4 F_32 ( struct V_49 * V_41 )
{
struct V_50 * V_74 = & V_41 -> V_48 ;
T_4 V_75 , V_76 , V_77 ;
do {
V_76 = F_33 ( & V_74 -> V_78 ) ;
V_77 = F_30 ( V_41 ) ;
} while ( F_34 ( & V_74 -> V_78 , V_76 ,
V_77 ) != V_76 );
V_75 = ( V_77 - V_76 ) & V_79 ;
F_35 ( V_75 , & V_41 -> V_80 ) ;
return V_77 ;
}
static void F_36 ( struct V_49 * V_41 )
{
F_32 ( V_41 ) ;
}
void F_37 ( struct V_49 * V_41 )
{
struct V_50 * V_74 = & V_41 -> V_48 ;
T_4 V_81 = 1ULL << 31 ;
F_38 ( & V_74 -> V_78 , V_81 ) ;
F_31 ( V_41 , V_81 ) ;
}
static T_5 F_39 ( int V_82 , void * V_67 )
{
unsigned long V_83 ;
struct V_34 * V_34 = V_67 ;
struct V_47 * V_84 = & V_17 -> V_85 ;
int V_35 , V_86 = V_87 ;
F_40 ( & V_84 -> V_88 , V_83 ) ;
for ( V_35 = V_36 ; V_35 <= F_9 ( V_34 ) ; V_35 ++ ) {
struct V_49 * V_41 = V_84 -> V_84 [ V_35 ] ;
struct V_50 * V_72 ;
if ( ! V_41 )
continue;
V_72 = & V_41 -> V_48 ;
if ( ! ( F_10 ( V_35 , V_89 ) &
V_90 ) )
continue;
F_12 ( V_90 , V_35 , V_89 ) ;
F_32 ( V_41 ) ;
F_37 ( V_41 ) ;
V_86 = V_91 ;
}
F_41 ( & V_84 -> V_88 , V_83 ) ;
return F_42 ( V_86 ) ;
}
static int F_43 ( struct V_34 * V_34 )
{
int V_92 = F_22 ( V_34 , F_39 ) ;
if ( V_92 ) {
F_27 ( V_34 ) ;
return V_92 ;
}
return 0 ;
}
static void F_44 ( struct V_34 * V_34 )
{
F_27 ( V_34 ) ;
}
static void F_45 ( struct V_49 * V_41 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
T_6 * V_93 = & V_34 -> V_93 ;
struct V_94 * V_95 = & V_34 -> V_95 ;
if ( F_46 ( V_93 , V_95 ) ) {
F_44 ( V_34 ) ;
F_47 ( V_95 ) ;
}
}
static void F_48 ( struct V_17 * V_17 )
{
struct V_34 * V_34 = F_19 ( V_17 ) ;
struct V_47 * V_85 = & V_34 -> V_85 ;
int V_96 = F_49 ( V_85 -> V_54 , V_34 -> V_97 ) ;
unsigned long V_83 ;
T_2 V_81 ;
if ( ! V_96 )
return;
F_40 ( & V_85 -> V_88 , V_83 ) ;
V_81 = F_5 ( V_23 + V_44 ) | V_98 ;
F_50 ( V_81 , V_23 + V_44 ) ;
F_41 ( & V_85 -> V_88 , V_83 ) ;
}
static void F_51 ( struct V_17 * V_17 )
{
struct V_34 * V_34 = F_19 ( V_17 ) ;
struct V_47 * V_85 = & V_34 -> V_85 ;
unsigned long V_83 ;
T_2 V_81 ;
F_40 ( & V_85 -> V_88 , V_83 ) ;
V_81 = F_5 ( V_23 + V_44 ) & ~ V_98 ;
F_50 ( V_81 , V_23 + V_44 ) ;
F_41 ( & V_85 -> V_88 , V_83 ) ;
}
static void F_52 ( struct V_49 * V_41 , int V_99 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_47 * V_85 = & V_34 -> V_85 ;
struct V_50 * V_74 = & V_41 -> V_48 ;
int V_35 = V_74 -> V_35 ;
unsigned long V_83 ;
if ( V_99 & V_100 )
F_53 ( ! ( V_74 -> V_101 & V_102 ) ) ;
V_74 -> V_101 = 0 ;
if ( F_23 ( ! F_8 ( V_34 , V_35 ) ) ) {
F_24 ( & V_34 -> V_64 -> V_67 , L_4 , V_35 ) ;
return;
}
F_40 ( & V_85 -> V_88 , V_83 ) ;
if ( V_35 != V_36 )
F_16 ( V_35 , V_74 -> V_52 ) ;
F_37 ( V_41 ) ;
F_15 ( V_35 ) ;
F_41 ( & V_85 -> V_88 , V_83 ) ;
}
static void F_54 ( struct V_49 * V_41 , int V_99 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_50 * V_74 = & V_41 -> V_48 ;
int V_35 = V_74 -> V_35 ;
if ( V_74 -> V_101 & V_103 )
return;
if ( F_23 ( ! F_8 ( V_34 , V_35 ) ) ) {
F_24 ( & V_34 -> V_64 -> V_67 , L_4 , V_35 ) ;
return;
}
F_14 ( V_35 ) ;
F_32 ( V_41 ) ;
V_74 -> V_101 |= V_103 | V_102 ;
}
static int F_55 ( struct V_49 * V_41 , int V_83 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_47 * V_85 = & V_34 -> V_85 ;
struct V_50 * V_74 = & V_41 -> V_48 ;
int V_35 ;
int V_68 = 0 ;
F_56 ( V_41 -> V_17 ) ;
V_35 = F_18 ( V_85 , V_41 ) ;
if ( V_35 < 0 ) {
V_68 = V_35 ;
goto V_104;
}
V_41 -> V_48 . V_35 = V_35 ;
V_85 -> V_84 [ V_35 ] = V_41 ;
V_74 -> V_101 = V_103 | V_102 ;
if ( V_83 & V_105 )
F_52 ( V_41 , V_100 ) ;
F_57 ( V_41 ) ;
V_104:
F_58 ( V_41 -> V_17 ) ;
return V_68 ;
}
static void F_59 ( struct V_49 * V_41 , int V_83 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
struct V_47 * V_85 = & V_34 -> V_85 ;
struct V_50 * V_74 = & V_41 -> V_48 ;
int V_35 = V_74 -> V_35 ;
F_54 ( V_41 , V_106 ) ;
V_85 -> V_84 [ V_35 ] = NULL ;
F_60 ( V_35 , V_85 -> V_54 ) ;
F_57 ( V_41 ) ;
}
static int
F_61 ( struct V_17 * V_34 ,
struct V_47 * V_85 ,
struct V_49 * V_41 )
{
if ( F_62 ( V_41 ) )
return 1 ;
if ( V_41 -> V_17 != V_34 )
return 0 ;
if ( V_41 -> V_101 < V_107 )
return 1 ;
if ( V_41 -> V_101 == V_107 && ! V_41 -> V_59 . V_108 )
return 1 ;
return F_18 ( V_85 , V_41 ) >= 0 ;
}
static int
F_63 ( struct V_49 * V_41 )
{
struct V_49 * V_109 , * V_110 = V_41 -> V_111 ;
struct V_47 V_112 = {
. V_54 = { 0 } ,
} ;
if ( ! F_61 ( V_41 -> V_17 , & V_112 , V_110 ) )
return - V_113 ;
F_64 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_61 ( V_41 -> V_17 , & V_112 , V_109 ) )
return - V_113 ;
}
if ( ! F_61 ( V_41 -> V_17 , & V_112 , V_41 ) )
return - V_113 ;
return 0 ;
}
static int
F_65 ( struct V_49 * V_41 )
{
struct V_50 * V_74 = & V_41 -> V_48 ;
int V_57 ;
V_57 = F_21 ( V_41 ) ;
if ( V_57 < 0 ) {
F_66 ( L_5 , V_41 -> V_59 . type ,
V_41 -> V_59 . V_58 ) ;
return V_57 ;
}
V_74 -> V_35 = - 1 ;
V_74 -> V_52 = 0 ;
V_74 -> V_58 = 0 ;
V_74 -> V_114 = 0 ;
V_74 -> V_52 |= ( unsigned long ) V_57 ;
V_74 -> V_115 = V_79 >> 1 ;
V_74 -> V_116 = V_74 -> V_115 ;
F_38 ( & V_74 -> V_117 , V_74 -> V_115 ) ;
if ( V_41 -> V_111 != V_41 ) {
if ( F_63 ( V_41 ) != 0 )
return - V_113 ;
}
return 0 ;
}
static int F_67 ( struct V_49 * V_41 )
{
struct V_34 * V_34 = F_19 ( V_41 -> V_17 ) ;
T_6 * V_93 = & V_34 -> V_93 ;
int V_68 = 0 ;
int V_118 ;
if ( V_41 -> V_59 . type != V_41 -> V_17 -> type )
return - V_6 ;
if ( F_68 ( V_41 ) || V_41 -> V_119 & V_120 )
return - V_121 ;
if ( V_41 -> V_59 . V_122 ||
V_41 -> V_59 . V_123 ||
V_41 -> V_59 . V_124 ||
V_41 -> V_59 . V_125 ||
V_41 -> V_59 . V_126 ||
V_41 -> V_59 . V_127 )
return - V_113 ;
V_118 = F_69 ( & V_34 -> V_128 ) ;
if ( V_41 -> V_118 < 0 || V_118 < 0 )
return - V_113 ;
V_41 -> V_118 = V_118 ;
V_41 -> V_129 = F_45 ;
if ( ! F_70 ( V_93 ) ) {
F_71 ( & V_34 -> V_95 ) ;
if ( F_72 ( V_93 ) == 0 )
V_68 = F_43 ( V_34 ) ;
if ( ! V_68 )
F_73 ( V_93 ) ;
F_47 ( & V_34 -> V_95 ) ;
}
if ( V_68 )
return V_68 ;
V_68 = F_65 ( V_41 ) ;
if ( V_68 )
F_45 ( V_41 ) ;
return V_68 ;
}
static T_7 F_74 ( struct V_130 * V_67 ,
struct V_131 * V_59 , char * V_132 )
{
int V_133 = F_75 ( V_132 , V_134 - 1 , L_6 ,
F_76 ( & V_17 -> V_128 ) ) ;
V_132 [ V_133 ++ ] = '\n' ;
V_132 [ V_133 ] = '\0' ;
return V_133 ;
}
static int F_77 ( struct V_34 * V_34 , struct V_31 * V_32 )
{
char * V_135 = V_34 -> V_18 -> V_135 ;
V_34 -> V_17 = (struct V_17 ) {
. V_135 = V_34 -> V_18 -> V_135 ,
. V_136 = V_137 ,
. V_138 = F_48 ,
. V_139 = F_51 ,
. V_140 = F_67 ,
. V_141 = F_55 ,
. V_142 = F_59 ,
. V_143 = F_52 ,
. V_144 = F_54 ,
. V_145 = F_36 ,
. V_146 = V_147 ,
} ;
V_34 -> V_64 = V_32 ;
V_34 -> V_97 = F_17 () ;
return F_78 ( & V_34 -> V_17 , V_135 , - 1 ) ;
}
static int F_79 ( struct V_148 * V_149 ,
unsigned long V_150 , void * V_151 )
{
unsigned int V_118 = ( long ) V_151 ;
unsigned int V_152 ;
switch ( V_150 & ~ V_153 ) {
case V_154 :
if ( ! F_80 ( V_118 , & V_17 -> V_128 ) )
break;
V_152 = F_81 ( V_155 , V_118 ) ;
if ( V_152 < 0 )
break;
F_82 ( V_152 , & V_17 -> V_128 ) ;
default:
break;
}
return V_156 ;
}
static inline const struct V_30 * F_83 ( struct V_31 * V_32 )
{
const struct V_157 * V_158 = F_84 ( V_159 ,
V_32 -> V_67 . V_160 ) ;
if ( ! V_158 )
return NULL ;
if ( V_158 -> V_161 )
return V_158 -> V_161 ;
F_85 ( & V_32 -> V_67 , L_7
L_8 ) ;
return F_6 ( V_32 ) ;
}
static bool F_86 ( int V_162 , int * V_69 , int V_66 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ )
if ( V_162 == V_69 [ V_62 ] )
return true ;
return false ;
}
static int F_87 ( struct V_31 * V_32 )
{
struct V_163 * V_164 ;
int V_62 , V_92 , V_162 ;
const struct V_30 * V_18 ;
V_18 = F_83 ( V_32 ) ;
if ( ! V_18 ) {
F_85 ( & V_32 -> V_67 , L_9 ) ;
return - V_65 ;
}
V_17 = F_88 ( & V_32 -> V_67 , sizeof( * V_17 ) , V_165 ) ;
if ( ! V_17 )
return - V_166 ;
V_17 -> V_18 = V_18 ;
V_164 = F_89 ( V_32 , V_167 , 0 ) ;
V_17 -> V_38 = F_90 ( & V_32 -> V_67 , V_164 ) ;
if ( F_91 ( V_17 -> V_38 ) )
return - V_166 ;
V_17 -> V_66 = 0 ;
for ( V_62 = 0 ; V_62 < V_168 ; V_62 ++ ) {
V_162 = F_92 ( V_32 , V_62 ) ;
if ( V_162 < 0 )
break;
if ( F_86 ( V_162 , V_17 -> V_69 , V_17 -> V_66 ) )
continue;
V_17 -> V_69 [ V_17 -> V_66 ++ ] = V_162 ;
}
if ( V_62 < V_168 ) {
F_85 ( & V_32 -> V_67 , L_10 ,
V_62 , V_168 ) ;
return - V_113 ;
}
F_93 ( & V_17 -> V_85 . V_88 ) ;
F_94 ( & V_17 -> V_95 ) ;
F_95 ( & V_17 -> V_93 , 0 ) ;
F_82 ( F_96 () , & V_17 -> V_128 ) ;
V_92 = F_97 ( & V_169 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_77 ( V_17 , V_32 ) ;
if ( V_92 )
return V_92 ;
F_98 ( L_11 , V_17 -> V_18 -> V_135 ) ;
return 0 ;
}
static int F_99 ( struct V_31 * V_32 )
{
if ( ! F_100 () )
return - V_65 ;
return F_101 ( V_32 -> V_67 . V_160 , NULL , NULL , & V_32 -> V_67 ) ;
}
static int T_8 F_102 ( void )
{
int V_92 ;
V_92 = F_103 ( & V_170 ) ;
if ( V_92 )
return V_92 ;
return F_103 ( & V_171 ) ;
}
static int T_8 F_102 ( void )
{
return 0 ;
}
static inline void F_104 ( struct V_172 * V_173 , T_2 V_174 , T_4 V_175 )
{
V_173 -> V_173 = V_176 | V_174 ;
V_173 -> V_175 = V_175 ;
}
static inline bool F_105 ( struct V_172 * V_173 )
{
return ! ! ( V_173 -> V_173 & V_176 ) ;
}
static inline bool F_106 ( struct V_172 * V_173 , T_4 V_175 )
{
return V_173 -> V_175 == ( V_175 & V_177 ) ;
}
static int F_107 ( struct V_178 * V_179 , int type )
{
int V_62 ;
bool V_180 ;
struct V_178 * V_181 ;
V_181 = F_108 ( V_179 , L_12 , 0 ) ;
for ( V_62 = 0 ; V_62 < V_182 ; V_62 ++ ) {
V_180 = V_183 [ V_62 ] . type == type ;
if ( V_180 && V_181 == V_183 [ V_62 ] . V_179 )
return V_62 ;
}
return - V_65 ;
}
int F_109 ( struct V_178 * V_179 )
{
return F_107 ( V_179 , V_184 ) ;
}
static void F_110 ( void )
{
int V_173 , V_118 ;
struct V_178 * V_185 ;
F_111 (cpu) {
V_185 = F_112 ( V_118 , NULL ) ;
if ( F_113 ( ! V_185 , L_13 ) )
continue;
V_173 = F_107 ( V_185 , V_186 ) ;
if ( V_173 < 0 )
continue;
F_104 ( & V_172 [ V_118 ] , V_173 , F_114 ( V_118 ) ) ;
}
F_111 (cpu) {
F_113 ( ! F_105 ( & V_172 [ V_118 ] ) ,
L_14 ,
V_118 ) ;
}
}
static void T_9 F_115 ( unsigned int V_173 , bool V_187 )
{
void T_10 * V_38 = V_183 [ V_173 ] . V_38 ;
F_13 ( V_187 ? V_188 : 0 , V_38 + V_189 ) ;
while ( F_5 ( V_23 + V_190 ) & 0x1 )
;
}
int T_9 F_116 ( T_4 V_175 )
{
int V_118 ;
bool V_191 ;
for ( V_118 = 0 ; V_118 < V_192 ; V_118 ++ ) {
V_191 = F_105 ( & V_172 [ V_118 ] ) ;
if ( V_191 && F_106 ( & V_172 [ V_118 ] , V_175 ) ) {
F_115 ( V_172 [ V_118 ] . V_173 , false ) ;
return 0 ;
}
}
return - V_65 ;
}
T_11 void T_12 F_117 ( void )
{
asm volatile ("\n"
" .arch armv7-a\n"
" mrc p15, 0, r0, c0, c0, 5 @ get MPIDR value \n"
" and r0, r0, #"__stringify(MPIDR_HWID_BITMASK)" \n"
" adr r1, 5f \n"
" ldr r2, [r1] \n"
" add r1, r1, r2 @ &cpu_port \n"
" add ip, r1, %[sizeof_cpu_port] \n"
"1: ldr r2, [r1, %[offsetof_cpu_port_mpidr_lsb]] \n"
" cmp r2, r0 @ compare MPIDR \n"
" bne 2f \n"
" ldr r3, [r1, %[offsetof_cpu_port_port]] \n"
" tst r3, #"__stringify(PORT_VALID)" \n"
" bne 3f \n"
"2: add r1, r1, %[sizeof_struct_cpu_port] \n"
" cmp r1, ip @ done? \n"
" blo 1b \n"
"cci_port_not_found: \n"
" wfi \n"
" wfe \n"
" b cci_port_not_found \n"
"3: bic r3, r3, #"__stringify(PORT_VALID)" \n"
" adr r0, 6f \n"
" ldmia r0, {r1, r2} \n"
" sub r1, r1, r0 @ virt - phys \n"
" ldr r0, [r0, r2] @ *(&ports) \n"
" mov r2, %[sizeof_struct_ace_port] \n"
" mla r0, r2, r3, r0 @ &ports[index] \n"
" sub r0, r0, r1 @ virt_to_phys() \n"
" ldr r0, [r0, %[offsetof_port_phys]] \n"
" mov r3, %[cci_enable_req]\n"
" str r3, [r0, #"__stringify(CCI_PORT_CTRL)"] \n"
" adr r1, 7f \n"
" ldr r0, [r1] \n"
" ldr r0, [r0, r1] @ cci_ctrl_base \n"
"4: ldr r1, [r0, #"__stringify(CCI_CTRL_STATUS)"] \n"
" tst r1, %[cci_control_status_bits] \n"
" bne 4b \n"
" mov r0, #0 \n"
" bx lr \n"
" .align 2 \n"
"5: .word cpu_port - . \n"
"6: .word . \n"
" .word ports - 6b \n"
"7: .word cci_ctrl_phys - . \n"
: :
[sizeof_cpu_port] "i" (sizeof(cpu_port)),
[cci_enable_req] "i" cpu_to_le32(CCI_ENABLE_REQ),
[cci_control_status_bits] "i" cpu_to_le32(1),
#ifndef F_118
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_119 () ;
}
int T_9 F_120 ( struct V_178 * V_179 , bool V_187 )
{
int V_173 ;
if ( ! V_179 )
return - V_65 ;
V_173 = F_107 ( V_179 , V_184 ) ;
if ( F_121 ( V_173 < 0 , L_15 ,
V_179 -> V_193 ) )
return - V_65 ;
F_115 ( V_173 , V_187 ) ;
return 0 ;
}
int T_9 F_122 ( T_2 V_173 , bool V_187 )
{
if ( V_173 >= V_182 || V_183 [ V_173 ] . type == V_194 )
return - V_65 ;
if ( V_183 [ V_173 ] . type == V_186 )
return - V_195 ;
F_115 ( V_173 , V_187 ) ;
return 0 ;
}
static int F_123 ( struct V_178 * V_196 )
{
struct V_197 const * V_198 ;
int V_92 , V_62 , V_199 = 0 , V_200 = 0 ;
struct V_178 * V_201 ;
struct V_163 V_164 ;
const char * V_202 ;
bool V_203 ;
V_198 = F_84 ( V_204 , V_196 ) -> V_161 ;
if ( ! V_198 )
return - V_65 ;
V_182 = V_198 -> V_199 + V_198 -> V_200 ;
V_183 = F_124 ( V_182 , sizeof( * V_183 ) , V_165 ) ;
if ( ! V_183 )
return - V_166 ;
F_125 (np, cp) {
if ( ! F_84 ( V_205 , V_201 ) )
continue;
V_62 = V_199 + V_200 ;
if ( V_62 >= V_182 )
break;
if ( F_126 ( V_201 , L_16 ,
& V_202 ) ) {
F_113 ( 1 , L_17 ,
V_201 -> V_193 ) ;
continue;
}
V_203 = strcmp ( V_202 , L_18 ) == 0 ;
if ( ! V_203 && strcmp ( V_202 , L_19 ) ) {
F_113 ( 1 , L_20 ,
V_201 -> V_193 ) ;
continue;
}
V_92 = F_127 ( V_201 , 0 , & V_164 ) ;
if ( ! V_92 ) {
V_183 [ V_62 ] . V_38 = F_128 ( V_164 . V_143 , F_129 ( & V_164 ) ) ;
V_183 [ V_62 ] . V_206 = V_164 . V_143 ;
}
if ( V_92 || ! V_183 [ V_62 ] . V_38 ) {
F_113 ( 1 , L_21 , V_62 ) ;
continue;
}
if ( V_203 ) {
if ( F_130 ( V_199 >= V_198 -> V_199 ) )
continue;
V_183 [ V_62 ] . type = V_186 ;
++ V_199 ;
} else {
if ( F_130 ( V_200 >= V_198 -> V_200 ) )
continue;
V_183 [ V_62 ] . type = V_184 ;
++ V_200 ;
}
V_183 [ V_62 ] . V_179 = V_201 ;
}
F_110 () ;
F_131 ( & V_23 ) ;
F_131 ( & V_207 ) ;
F_131 ( & V_183 ) ;
F_131 ( & V_172 ) ;
F_132 ( V_183 , sizeof( * V_183 ) * V_182 ) ;
F_98 ( L_22 ) ;
return 0 ;
}
static inline int F_123 ( struct V_178 * V_196 )
{
return 0 ;
}
static int F_133 ( void )
{
int V_92 ;
struct V_178 * V_196 ;
struct V_163 V_164 ;
V_196 = F_134 ( NULL , V_204 ) ;
if( ! V_196 || ! F_135 ( V_196 ) )
return - V_65 ;
V_92 = F_127 ( V_196 , 0 , & V_164 ) ;
if ( ! V_92 ) {
V_23 = F_128 ( V_164 . V_143 , F_129 ( & V_164 ) ) ;
V_207 = V_164 . V_143 ;
}
if ( V_92 || ! V_23 ) {
F_113 ( 1 , L_23 ) ;
return - V_208 ;
}
return F_123 ( V_196 ) ;
}
static int F_136 ( void )
{
if ( V_209 != - V_55 )
return V_209 ;
F_71 ( & V_210 ) ;
if ( V_209 == - V_55 )
V_209 = F_133 () ;
F_47 ( & V_210 ) ;
return V_209 ;
}
bool F_100 ( void )
{
return F_136 () == 0 ;
}
