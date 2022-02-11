static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_1 , ( unsigned long ) V_7 -> V_9 ) ;
}
static int F_3 ( struct V_10 * V_10 ,
struct V_11 * V_12 ,
unsigned long V_13 )
{
int V_14 ;
if ( V_13 == V_15 ) {
if ( F_4 ( V_16 , V_12 -> V_17 ) )
return - V_18 ;
return V_16 ;
}
for ( V_14 = V_19 ; V_14 <= F_5 ( V_10 ) ; ++ V_14 )
if ( ! F_4 ( V_14 , V_12 -> V_17 ) )
return V_14 ;
return - V_18 ;
}
static int F_6 ( struct V_10 * V_10 , unsigned long V_20 )
{
T_2 V_21 = F_7 ( V_20 ) ;
T_2 V_22 = F_8 ( V_20 ) ;
int V_23 ;
if ( V_20 & ~ V_24 )
return - V_25 ;
if ( V_20 == V_15 )
return V_20 ;
switch ( V_21 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_23 = V_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
V_23 = V_35 ;
break;
default:
return - V_25 ;
}
if ( V_22 >= V_10 -> V_36 -> V_37 [ V_23 ] . V_38 &&
V_22 <= V_10 -> V_36 -> V_37 [ V_23 ] . V_39 )
return V_20 ;
return - V_25 ;
}
static int F_9 ( void )
{
int V_40 ;
V_40 = F_10 ( V_41 + V_42 ) & V_43 ;
V_40 >>= V_44 ;
if ( V_40 < V_45 )
return V_46 ;
else
return V_47 ;
}
static const struct V_48 * F_11 ( struct V_49 * V_50 )
{
if ( F_12 () )
return & V_51 [ F_9 () ] ;
return NULL ;
}
static inline struct V_48 * F_11 ( struct V_49 * V_50 )
{
return NULL ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_2 ,
( unsigned long ) V_7 -> V_9 , V_52 ) ;
}
static int F_14 ( struct V_10 * V_10 ,
unsigned long V_20 )
{
T_3 V_21 = F_15 ( V_20 ) ;
T_3 V_22 = F_16 ( V_20 ) ;
int V_23 ;
if ( V_20 & ~ V_53 )
return - V_25 ;
switch ( V_21 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_23 = V_31 ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_23 = V_35 ;
break;
case V_52 :
V_23 = V_67 ;
break;
default:
return - V_25 ;
}
if ( V_22 >= V_10 -> V_36 -> V_37 [ V_23 ] . V_38 &&
V_22 <= V_10 -> V_36 -> V_37 [ V_23 ] . V_39 )
return V_20 ;
return - V_25 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_3 , ( char * ) V_7 -> V_9 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
return snprintf ( V_5 , V_8 , L_4 ,
( unsigned long ) V_7 -> V_9 ) ;
}
static int F_19 ( struct V_10 * V_10 , int V_14 )
{
return 0 <= V_14 && V_14 <= F_5 ( V_10 ) ;
}
static T_3 F_20 ( struct V_10 * V_10 , int V_14 , unsigned int V_68 )
{
return F_10 ( V_10 -> V_69 +
F_21 ( V_10 -> V_36 , V_14 ) + V_68 ) ;
}
static void F_22 ( struct V_10 * V_10 , T_3 V_70 ,
int V_14 , unsigned int V_68 )
{
return F_23 ( V_70 , V_10 -> V_69 +
F_21 ( V_10 -> V_36 , V_14 ) + V_68 ) ;
}
static void F_24 ( struct V_10 * V_10 , int V_14 )
{
F_22 ( V_10 , 0 , V_14 , V_71 ) ;
}
static void F_25 ( struct V_10 * V_10 , int V_14 )
{
F_22 ( V_10 , 1 , V_14 , V_71 ) ;
}
static void F_26 ( struct V_10 * V_10 , int V_14 , unsigned long V_72 )
{
F_22 ( V_10 , V_72 , V_14 , V_73 ) ;
}
static T_3 F_27 ( void )
{
return ( F_10 ( V_41 + V_74 ) &
V_75 ) >> V_76 ;
}
static int F_28 ( struct V_11 * V_12 , struct V_77 * V_72 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
unsigned long V_13 = V_72 -> V_12 . V_79 ;
int V_14 ;
if ( V_10 -> V_36 -> V_80 )
return V_10 -> V_36 -> V_80 ( V_10 , V_12 , V_13 ) ;
for( V_14 = 0 ; V_14 <= F_5 ( V_10 ) ; V_14 ++ )
if ( ! F_4 ( V_14 , V_12 -> V_17 ) )
return V_14 ;
return - V_18 ;
}
static int F_30 ( struct V_77 * V_72 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
if ( V_72 -> V_4 . type < V_81 ||
! V_10 -> V_36 -> V_82 )
return - V_25 ;
return V_10 -> V_36 -> V_82 ( V_10 , V_72 -> V_4 . V_83 ) ;
}
static int F_31 ( struct V_10 * V_10 , T_4 V_84 )
{
int V_85 ;
struct V_49 * V_86 = V_10 -> V_87 ;
if ( F_32 ( ! V_86 ) )
return - V_88 ;
if ( V_10 -> V_89 < 1 ) {
F_33 ( & V_86 -> V_2 , L_5 ) ;
return - V_88 ;
}
for ( V_85 = 0 ; V_85 < V_10 -> V_89 ; V_85 ++ ) {
int V_90 = F_34 ( V_10 -> V_91 [ V_85 ] , V_84 , V_92 ,
L_6 , V_10 ) ;
if ( V_90 ) {
F_33 ( & V_86 -> V_2 , L_7 ,
V_10 -> V_91 [ V_85 ] ) ;
return V_90 ;
}
F_35 ( V_85 , & V_10 -> V_93 ) ;
}
return 0 ;
}
static void F_36 ( struct V_10 * V_10 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_10 -> V_89 ; V_85 ++ ) {
if ( ! F_37 ( V_85 , & V_10 -> V_93 ) )
continue;
F_38 ( V_10 -> V_91 [ V_85 ] , V_10 ) ;
}
}
static T_3 F_39 ( struct V_77 * V_72 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
struct V_94 * V_95 = & V_72 -> V_12 ;
int V_14 = V_95 -> V_14 ;
T_3 V_70 ;
if ( F_32 ( ! F_19 ( V_10 , V_14 ) ) ) {
F_33 ( & V_10 -> V_87 -> V_2 , L_8 , V_14 ) ;
return 0 ;
}
V_70 = F_20 ( V_10 , V_14 , V_96 ) ;
return V_70 ;
}
static void F_40 ( struct V_77 * V_72 , T_3 V_70 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
struct V_94 * V_95 = & V_72 -> V_12 ;
int V_14 = V_95 -> V_14 ;
if ( F_32 ( ! F_19 ( V_10 , V_14 ) ) )
F_33 ( & V_10 -> V_87 -> V_2 , L_8 , V_14 ) ;
else
F_22 ( V_10 , V_70 , V_14 , V_96 ) ;
}
static T_5 F_41 ( struct V_77 * V_72 )
{
struct V_94 * V_97 = & V_72 -> V_12 ;
T_5 V_98 , V_99 , V_100 ;
do {
V_99 = F_42 ( & V_97 -> V_101 ) ;
V_100 = F_39 ( V_72 ) ;
} while ( F_43 ( & V_97 -> V_101 , V_99 ,
V_100 ) != V_99 );
V_98 = ( V_100 - V_99 ) & V_102 ;
F_44 ( V_98 , & V_72 -> V_103 ) ;
return V_100 ;
}
static void F_45 ( struct V_77 * V_72 )
{
F_41 ( V_72 ) ;
}
void F_46 ( struct V_77 * V_72 )
{
struct V_94 * V_97 = & V_72 -> V_12 ;
T_5 V_104 = 1ULL << 31 ;
F_47 ( & V_97 -> V_101 , V_104 ) ;
F_40 ( V_72 , V_104 ) ;
}
static T_6 F_48 ( int V_105 , void * V_2 )
{
unsigned long V_106 ;
struct V_10 * V_10 = V_2 ;
struct V_11 * V_107 = & V_10 -> V_108 ;
int V_14 , V_109 = V_110 ;
F_49 ( & V_107 -> V_111 , V_106 ) ;
for ( V_14 = 0 ; V_14 <= F_5 ( V_10 ) ; V_14 ++ ) {
struct V_77 * V_72 = V_107 -> V_107 [ V_14 ] ;
struct V_94 * V_95 ;
if ( ! V_72 )
continue;
V_95 = & V_72 -> V_12 ;
if ( ! ( F_20 ( V_10 , V_14 , V_112 ) &
V_113 ) )
continue;
F_22 ( V_10 , V_113 , V_14 ,
V_112 ) ;
F_41 ( V_72 ) ;
F_46 ( V_72 ) ;
V_109 = V_114 ;
}
F_50 ( & V_107 -> V_111 , V_106 ) ;
return F_51 ( V_109 ) ;
}
static int F_52 ( struct V_10 * V_10 )
{
int V_115 = F_31 ( V_10 , F_48 ) ;
if ( V_115 ) {
F_36 ( V_10 ) ;
return V_115 ;
}
return 0 ;
}
static void F_53 ( struct V_10 * V_10 )
{
F_36 ( V_10 ) ;
}
static void F_54 ( struct V_77 * V_72 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
T_7 * V_116 = & V_10 -> V_116 ;
struct V_117 * V_118 = & V_10 -> V_118 ;
if ( F_55 ( V_116 , V_118 ) ) {
F_53 ( V_10 ) ;
F_56 ( V_118 ) ;
}
}
static void F_57 ( struct V_78 * V_78 )
{
struct V_10 * V_10 = F_29 ( V_78 ) ;
struct V_11 * V_108 = & V_10 -> V_108 ;
int V_119 = F_58 ( V_108 -> V_17 , V_10 -> V_120 ) ;
unsigned long V_106 ;
T_3 V_104 ;
if ( ! V_119 )
return;
F_49 ( & V_108 -> V_111 , V_106 ) ;
V_104 = F_10 ( V_41 + V_74 ) | V_121 ;
F_59 ( V_104 , V_41 + V_74 ) ;
F_50 ( & V_108 -> V_111 , V_106 ) ;
}
static void F_60 ( struct V_78 * V_78 )
{
struct V_10 * V_10 = F_29 ( V_78 ) ;
struct V_11 * V_108 = & V_10 -> V_108 ;
unsigned long V_106 ;
T_3 V_104 ;
F_49 ( & V_108 -> V_111 , V_106 ) ;
V_104 = F_10 ( V_41 + V_74 ) & ~ V_121 ;
F_59 ( V_104 , V_41 + V_74 ) ;
F_50 ( & V_108 -> V_111 , V_106 ) ;
}
static bool F_61 ( struct V_10 * V_10 , int V_14 )
{
return ( V_14 >= 0 ) && ( V_14 < V_10 -> V_36 -> V_122 ) ;
}
static void F_62 ( struct V_77 * V_72 , int V_123 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
struct V_11 * V_108 = & V_10 -> V_108 ;
struct V_94 * V_97 = & V_72 -> V_12 ;
int V_14 = V_97 -> V_14 ;
unsigned long V_106 ;
if ( V_123 & V_124 )
F_63 ( ! ( V_97 -> V_125 & V_126 ) ) ;
V_97 -> V_125 = 0 ;
if ( F_32 ( ! F_19 ( V_10 , V_14 ) ) ) {
F_33 ( & V_10 -> V_87 -> V_2 , L_8 , V_14 ) ;
return;
}
F_49 ( & V_108 -> V_111 , V_106 ) ;
if ( ! F_61 ( V_10 , V_14 ) )
F_26 ( V_10 , V_14 , V_97 -> V_79 ) ;
F_46 ( V_72 ) ;
F_25 ( V_10 , V_14 ) ;
F_50 ( & V_108 -> V_111 , V_106 ) ;
}
static void F_64 ( struct V_77 * V_72 , int V_123 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
struct V_94 * V_97 = & V_72 -> V_12 ;
int V_14 = V_97 -> V_14 ;
if ( V_97 -> V_125 & V_127 )
return;
if ( F_32 ( ! F_19 ( V_10 , V_14 ) ) ) {
F_33 ( & V_10 -> V_87 -> V_2 , L_8 , V_14 ) ;
return;
}
F_24 ( V_10 , V_14 ) ;
F_41 ( V_72 ) ;
V_97 -> V_125 |= V_127 | V_126 ;
}
static int F_65 ( struct V_77 * V_72 , int V_106 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
struct V_11 * V_108 = & V_10 -> V_108 ;
struct V_94 * V_97 = & V_72 -> V_12 ;
int V_14 ;
int V_90 = 0 ;
F_66 ( V_72 -> V_78 ) ;
V_14 = F_28 ( V_108 , V_72 ) ;
if ( V_14 < 0 ) {
V_90 = V_14 ;
goto V_128;
}
V_72 -> V_12 . V_14 = V_14 ;
V_108 -> V_107 [ V_14 ] = V_72 ;
V_97 -> V_125 = V_127 | V_126 ;
if ( V_106 & V_129 )
F_62 ( V_72 , V_124 ) ;
F_67 ( V_72 ) ;
V_128:
F_68 ( V_72 -> V_78 ) ;
return V_90 ;
}
static void F_69 ( struct V_77 * V_72 , int V_106 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
struct V_11 * V_108 = & V_10 -> V_108 ;
struct V_94 * V_97 = & V_72 -> V_12 ;
int V_14 = V_97 -> V_14 ;
F_64 ( V_72 , V_130 ) ;
V_108 -> V_107 [ V_14 ] = NULL ;
F_70 ( V_14 , V_108 -> V_17 ) ;
F_67 ( V_72 ) ;
}
static int
F_71 ( struct V_78 * V_10 ,
struct V_11 * V_108 ,
struct V_77 * V_72 )
{
if ( F_72 ( V_72 ) )
return 1 ;
if ( V_72 -> V_78 != V_10 )
return 0 ;
if ( V_72 -> V_125 < V_131 )
return 1 ;
if ( V_72 -> V_125 == V_131 && ! V_72 -> V_4 . V_132 )
return 1 ;
return F_28 ( V_108 , V_72 ) >= 0 ;
}
static int
F_73 ( struct V_77 * V_72 )
{
struct V_77 * V_133 , * V_134 = V_72 -> V_135 ;
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
unsigned long V_136 [ F_74 ( V_10 -> V_120 ) ] ;
struct V_11 V_137 = {
. V_17 = V_136 ,
} ;
memset ( V_136 , 0 , F_74 ( V_10 -> V_120 ) * sizeof( unsigned long ) ) ;
if ( ! F_71 ( V_72 -> V_78 , & V_137 , V_134 ) )
return - V_138 ;
F_75 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_71 ( V_72 -> V_78 , & V_137 , V_133 ) )
return - V_138 ;
}
if ( ! F_71 ( V_72 -> V_78 , & V_137 , V_72 ) )
return - V_138 ;
return 0 ;
}
static int
F_76 ( struct V_77 * V_72 )
{
struct V_94 * V_97 = & V_72 -> V_12 ;
int V_139 ;
V_139 = F_30 ( V_72 ) ;
if ( V_139 < 0 ) {
F_77 ( L_9 , V_72 -> V_4 . type ,
V_72 -> V_4 . V_83 ) ;
return V_139 ;
}
V_97 -> V_14 = - 1 ;
V_97 -> V_79 = 0 ;
V_97 -> V_83 = 0 ;
V_97 -> V_140 = 0 ;
V_97 -> V_79 |= ( unsigned long ) V_139 ;
V_97 -> V_141 = V_102 >> 1 ;
V_97 -> V_142 = V_97 -> V_141 ;
F_47 ( & V_97 -> V_143 , V_97 -> V_141 ) ;
if ( V_72 -> V_135 != V_72 ) {
if ( F_73 ( V_72 ) != 0 )
return - V_138 ;
}
return 0 ;
}
static int F_78 ( struct V_77 * V_72 )
{
struct V_10 * V_10 = F_29 ( V_72 -> V_78 ) ;
T_7 * V_116 = & V_10 -> V_116 ;
int V_90 = 0 ;
int V_144 ;
if ( V_72 -> V_4 . type != V_72 -> V_78 -> type )
return - V_25 ;
if ( F_79 ( V_72 ) || V_72 -> V_145 & V_146 )
return - V_147 ;
if ( V_72 -> V_4 . V_148 ||
V_72 -> V_4 . V_149 ||
V_72 -> V_4 . V_150 ||
V_72 -> V_4 . V_151 ||
V_72 -> V_4 . V_152 ||
V_72 -> V_4 . V_153 )
return - V_138 ;
V_144 = F_80 ( & V_10 -> V_154 ) ;
if ( V_72 -> V_144 < 0 || V_144 < 0 )
return - V_138 ;
V_72 -> V_144 = V_144 ;
V_72 -> V_155 = F_54 ;
if ( ! F_81 ( V_116 ) ) {
F_82 ( & V_10 -> V_118 ) ;
if ( F_83 ( V_116 ) == 0 )
V_90 = F_52 ( V_10 ) ;
if ( ! V_90 )
F_84 ( V_116 ) ;
F_56 ( & V_10 -> V_118 ) ;
}
if ( V_90 )
return V_90 ;
V_90 = F_76 ( V_72 ) ;
if ( V_90 )
F_54 ( V_72 ) ;
return V_90 ;
}
static T_1 F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ,
struct V_6 , V_4 ) ;
struct V_10 * V_10 = V_7 -> V_9 ;
int V_156 = F_86 ( V_5 , V_8 - 1 , L_10 ,
F_87 ( & V_10 -> V_154 ) ) ;
V_5 [ V_156 ++ ] = '\n' ;
V_5 [ V_156 ] = '\0' ;
return V_156 ;
}
static struct V_157 * * F_88 ( struct V_49 * V_50 ,
int V_156 , struct V_6 * V_158 )
{
int V_85 ;
struct V_157 * * V_159 ;
V_159 = F_89 ( & V_50 -> V_2 , V_156 + 1 , sizeof( struct V_157 * ) ,
V_160 ) ;
if ( ! V_159 )
return V_159 ;
for( V_85 = 0 ; V_85 < V_156 ; V_85 ++ )
V_159 [ V_85 ] = & V_158 [ V_85 ] . V_4 . V_4 ;
return V_159 ;
}
static int F_90 ( struct V_10 * V_10 , struct V_49 * V_50 )
{
const struct V_48 * V_36 = V_10 -> V_36 ;
struct V_157 * * V_159 ;
if ( V_36 -> V_161 ) {
V_159 = F_88 ( V_50 , V_36 -> V_161 ,
V_36 -> V_162 ) ;
if ( ! V_159 )
return - V_163 ;
V_164 . V_159 = V_159 ;
}
if ( V_36 -> V_165 ) {
V_159 = F_88 ( V_50 , V_36 -> V_165 ,
V_36 -> V_166 ) ;
if ( ! V_159 )
return - V_163 ;
V_167 . V_159 = V_159 ;
}
V_168 . V_9 = V_10 ;
return 0 ;
}
static int F_91 ( struct V_10 * V_10 , struct V_49 * V_50 )
{
char * V_169 = V_10 -> V_36 -> V_169 ;
T_3 V_120 ;
int V_170 ;
V_170 = F_90 ( V_10 , V_50 ) ;
if ( V_170 )
return V_170 ;
V_10 -> V_78 = (struct V_78 ) {
. V_169 = V_10 -> V_36 -> V_169 ,
. V_171 = V_172 ,
. V_173 = F_57 ,
. V_174 = F_60 ,
. V_175 = F_78 ,
. V_176 = F_65 ,
. V_177 = F_69 ,
. V_178 = F_62 ,
. V_179 = F_64 ,
. V_180 = F_45 ,
. V_181 = V_182 ,
} ;
V_10 -> V_87 = V_50 ;
V_120 = F_27 () ;
if ( V_120 > V_10 -> V_36 -> V_183 ) {
F_92 ( & V_50 -> V_2 ,
L_11
L_12 ,
V_120 , V_10 -> V_36 -> V_183 ) ;
V_120 = V_10 -> V_36 -> V_183 ;
}
V_10 -> V_120 = V_120 + V_10 -> V_36 -> V_122 ;
return F_93 ( & V_10 -> V_78 , V_169 , - 1 ) ;
}
static int F_94 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
struct V_10 * V_10 = F_2 ( V_185 ,
struct V_10 , V_188 ) ;
unsigned int V_144 = ( long ) V_187 ;
unsigned int V_189 ;
switch ( V_186 & ~ V_190 ) {
case V_191 :
if ( ! F_95 ( V_144 , & V_10 -> V_154 ) )
break;
V_189 = F_96 ( V_192 , V_144 ) ;
if ( V_189 < 0 )
break;
F_97 ( V_189 , & V_10 -> V_154 ) ;
default:
break;
}
return V_193 ;
}
static inline const struct V_48 * F_98 ( struct V_49 * V_50 )
{
const struct V_194 * V_195 = F_99 ( V_196 ,
V_50 -> V_2 . V_197 ) ;
if ( ! V_195 )
return NULL ;
if ( V_195 -> V_198 )
return V_195 -> V_198 ;
F_92 ( & V_50 -> V_2 , L_13
L_14 ) ;
return F_11 ( V_50 ) ;
}
static bool F_100 ( int V_199 , int * V_91 , int V_89 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_89 ; V_85 ++ )
if ( V_199 == V_91 [ V_85 ] )
return true ;
return false ;
}
static struct V_10 * F_101 ( struct V_49 * V_50 )
{
struct V_10 * V_10 ;
const struct V_48 * V_36 ;
V_36 = F_98 ( V_50 ) ;
if ( ! V_36 ) {
F_92 ( & V_50 -> V_2 , L_15 ) ;
return F_102 ( - V_88 ) ;
}
V_10 = F_103 ( & V_50 -> V_2 , sizeof( * V_10 ) , V_160 ) ;
if ( ! V_10 )
return F_102 ( - V_163 ) ;
V_10 -> V_36 = V_36 ;
V_10 -> V_91 = F_89 ( & V_50 -> V_2 , F_104 ( V_36 ) ,
sizeof( * V_10 -> V_91 ) , V_160 ) ;
if ( ! V_10 -> V_91 )
return F_102 ( - V_163 ) ;
V_10 -> V_108 . V_107 = F_89 ( & V_50 -> V_2 ,
F_104 ( V_36 ) ,
sizeof( * V_10 -> V_108 . V_107 ) ,
V_160 ) ;
if ( ! V_10 -> V_108 . V_107 )
return F_102 ( - V_163 ) ;
V_10 -> V_108 . V_17 = F_89 ( & V_50 -> V_2 ,
F_74 ( F_104 ( V_36 ) ) ,
sizeof( * V_10 -> V_108 . V_17 ) ,
V_160 ) ;
if ( ! V_10 -> V_108 . V_17 )
return F_102 ( - V_163 ) ;
return V_10 ;
}
static int F_105 ( struct V_49 * V_50 )
{
struct V_200 * V_201 ;
struct V_10 * V_10 ;
int V_85 , V_115 , V_199 ;
V_10 = F_101 ( V_50 ) ;
if ( F_106 ( V_10 ) )
return F_107 ( V_10 ) ;
V_201 = F_108 ( V_50 , V_202 , 0 ) ;
V_10 -> V_69 = F_109 ( & V_50 -> V_2 , V_201 ) ;
if ( F_106 ( V_10 -> V_69 ) )
return - V_163 ;
V_10 -> V_89 = 0 ;
for ( V_85 = 0 ; V_85 < F_104 ( V_10 -> V_36 ) ; V_85 ++ ) {
V_199 = F_110 ( V_50 , V_85 ) ;
if ( V_199 < 0 )
break;
if ( F_100 ( V_199 , V_10 -> V_91 , V_10 -> V_89 ) )
continue;
V_10 -> V_91 [ V_10 -> V_89 ++ ] = V_199 ;
}
if ( V_85 < F_104 ( V_10 -> V_36 ) ) {
F_92 ( & V_50 -> V_2 , L_16 ,
V_85 , F_104 ( V_10 -> V_36 ) ) ;
return - V_138 ;
}
F_111 ( & V_10 -> V_108 . V_111 ) ;
F_112 ( & V_10 -> V_118 ) ;
F_113 ( & V_10 -> V_116 , 0 ) ;
F_97 ( F_114 () , & V_10 -> V_154 ) ;
V_10 -> V_188 = (struct V_184 ) {
. V_203 = F_94 ,
. V_204 = V_205 + 1 ,
} ;
V_115 = F_115 ( & V_10 -> V_188 ) ;
if ( V_115 )
return V_115 ;
V_115 = F_91 ( V_10 , V_50 ) ;
if ( V_115 ) {
F_116 ( & V_10 -> V_188 ) ;
return V_115 ;
}
F_117 ( L_17 , V_10 -> V_36 -> V_169 ) ;
return 0 ;
}
static int F_118 ( struct V_49 * V_50 )
{
if ( ! F_119 () )
return - V_88 ;
return F_120 ( V_50 -> V_2 . V_197 , NULL , NULL , & V_50 -> V_2 ) ;
}
static int T_8 F_121 ( void )
{
int V_115 ;
V_115 = F_122 ( & V_206 ) ;
if ( V_115 )
return V_115 ;
return F_122 ( & V_207 ) ;
}
static int T_8 F_121 ( void )
{
return 0 ;
}
static inline void F_123 ( struct V_208 * V_209 , T_3 V_210 , T_5 V_211 )
{
V_209 -> V_209 = V_212 | V_210 ;
V_209 -> V_211 = V_211 ;
}
static inline bool F_124 ( struct V_208 * V_209 )
{
return ! ! ( V_209 -> V_209 & V_212 ) ;
}
static inline bool F_125 ( struct V_208 * V_209 , T_5 V_211 )
{
return V_209 -> V_211 == ( V_211 & V_213 ) ;
}
static int F_126 ( struct V_214 * V_215 , int type )
{
int V_85 ;
bool V_216 ;
struct V_214 * V_217 ;
V_217 = F_127 ( V_215 , L_18 , 0 ) ;
for ( V_85 = 0 ; V_85 < V_218 ; V_85 ++ ) {
V_216 = V_219 [ V_85 ] . type == type ;
if ( V_216 && V_217 == V_219 [ V_85 ] . V_215 )
return V_85 ;
}
return - V_88 ;
}
int F_128 ( struct V_214 * V_215 )
{
return F_126 ( V_215 , V_220 ) ;
}
static void F_129 ( void )
{
int V_209 , V_144 ;
struct V_214 * V_221 ;
F_130 (cpu) {
V_221 = F_131 ( V_144 , NULL ) ;
if ( F_132 ( ! V_221 , L_19 ) )
continue;
V_209 = F_126 ( V_221 , V_222 ) ;
if ( V_209 < 0 )
continue;
F_123 ( & V_208 [ V_144 ] , V_209 , F_133 ( V_144 ) ) ;
}
F_130 (cpu) {
F_132 ( ! F_124 ( & V_208 [ V_144 ] ) ,
L_20 ,
V_144 ) ;
}
}
static void T_9 F_134 ( unsigned int V_209 , bool V_223 )
{
void T_10 * V_69 = V_219 [ V_209 ] . V_69 ;
F_23 ( V_223 ? V_224 : 0 , V_69 + V_225 ) ;
while ( F_10 ( V_41 + V_226 ) & 0x1 )
;
}
int T_9 F_135 ( T_5 V_211 )
{
int V_144 ;
bool V_227 ;
for ( V_144 = 0 ; V_144 < V_228 ; V_144 ++ ) {
V_227 = F_124 ( & V_208 [ V_144 ] ) ;
if ( V_227 && F_125 ( & V_208 [ V_144 ] , V_211 ) ) {
F_134 ( V_208 [ V_144 ] . V_209 , false ) ;
return 0 ;
}
}
return - V_88 ;
}
T_11 void T_12 F_136 ( void )
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
#ifndef F_137
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
F_138 () ;
}
int T_9 F_139 ( struct V_214 * V_215 , bool V_223 )
{
int V_209 ;
if ( ! V_215 )
return - V_88 ;
V_209 = F_126 ( V_215 , V_220 ) ;
if ( F_140 ( V_209 < 0 , L_21 ,
V_215 -> V_229 ) )
return - V_88 ;
F_134 ( V_209 , V_223 ) ;
return 0 ;
}
int T_9 F_141 ( T_3 V_209 , bool V_223 )
{
if ( V_209 >= V_218 || V_219 [ V_209 ] . type == V_230 )
return - V_88 ;
if ( V_219 [ V_209 ] . type == V_222 )
return - V_231 ;
F_134 ( V_209 , V_223 ) ;
return 0 ;
}
static int F_142 ( struct V_214 * V_232 )
{
struct V_233 const * V_234 ;
int V_115 , V_85 , V_235 = 0 , V_236 = 0 ;
struct V_214 * V_237 ;
struct V_200 V_201 ;
const char * V_238 ;
bool V_239 ;
V_234 = F_99 ( V_240 , V_232 ) -> V_198 ;
if ( ! V_234 )
return - V_88 ;
V_218 = V_234 -> V_235 + V_234 -> V_236 ;
V_219 = F_143 ( V_218 , sizeof( * V_219 ) , V_160 ) ;
if ( ! V_219 )
return - V_163 ;
F_144 (np, cp) {
if ( ! F_99 ( V_241 , V_237 ) )
continue;
V_85 = V_235 + V_236 ;
if ( V_85 >= V_218 )
break;
if ( F_145 ( V_237 , L_22 ,
& V_238 ) ) {
F_132 ( 1 , L_23 ,
V_237 -> V_229 ) ;
continue;
}
V_239 = strcmp ( V_238 , L_24 ) == 0 ;
if ( ! V_239 && strcmp ( V_238 , L_25 ) ) {
F_132 ( 1 , L_26 ,
V_237 -> V_229 ) ;
continue;
}
V_115 = F_146 ( V_237 , 0 , & V_201 ) ;
if ( ! V_115 ) {
V_219 [ V_85 ] . V_69 = F_147 ( V_201 . V_178 , F_148 ( & V_201 ) ) ;
V_219 [ V_85 ] . V_242 = V_201 . V_178 ;
}
if ( V_115 || ! V_219 [ V_85 ] . V_69 ) {
F_132 ( 1 , L_27 , V_85 ) ;
continue;
}
if ( V_239 ) {
if ( F_149 ( V_235 >= V_234 -> V_235 ) )
continue;
V_219 [ V_85 ] . type = V_222 ;
++ V_235 ;
} else {
if ( F_149 ( V_236 >= V_234 -> V_236 ) )
continue;
V_219 [ V_85 ] . type = V_220 ;
++ V_236 ;
}
V_219 [ V_85 ] . V_215 = V_237 ;
}
F_129 () ;
F_150 ( & V_41 ) ;
F_150 ( & V_243 ) ;
F_150 ( & V_219 ) ;
F_150 ( & V_208 ) ;
F_151 ( V_219 , sizeof( * V_219 ) * V_218 ) ;
F_117 ( L_28 ) ;
return 0 ;
}
static inline int F_142 ( struct V_214 * V_232 )
{
return 0 ;
}
static int F_152 ( void )
{
int V_115 ;
struct V_214 * V_232 ;
struct V_200 V_201 ;
V_232 = F_153 ( NULL , V_240 ) ;
if( ! V_232 || ! F_154 ( V_232 ) )
return - V_88 ;
V_115 = F_146 ( V_232 , 0 , & V_201 ) ;
if ( ! V_115 ) {
V_41 = F_147 ( V_201 . V_178 , F_148 ( & V_201 ) ) ;
V_243 = V_201 . V_178 ;
}
if ( V_115 || ! V_41 ) {
F_132 ( 1 , L_29 ) ;
return - V_244 ;
}
return F_142 ( V_232 ) ;
}
static int F_155 ( void )
{
if ( V_245 != - V_18 )
return V_245 ;
F_82 ( & V_246 ) ;
if ( V_245 == - V_18 )
V_245 = F_152 () ;
F_56 ( & V_246 ) ;
return V_245 ;
}
bool F_119 ( void )
{
return F_155 () == 0 ;
}
