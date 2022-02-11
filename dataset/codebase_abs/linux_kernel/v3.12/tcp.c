static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , struct V_5 * V_6 , T_2 V_7 )
{
F_2 ( & V_2 -> V_8 ) ;
V_2 -> V_9 = V_6 ;
V_2 -> V_10 = V_3 ;
V_2 -> V_11 = V_4 ;
V_2 -> V_12 = V_7 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_13 = F_4 () ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_14 = F_4 () ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_15 = F_4 () ;
}
static inline void F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
V_2 -> V_18 = V_17 ;
}
static inline void F_8 ( struct V_1 * V_2 ,
T_1 V_19 )
{
V_2 -> V_20 = V_19 ;
}
static inline void F_9 ( struct V_16 * V_17 )
{
V_17 -> V_21 = F_4 () ;
}
static inline void F_10 ( struct V_16 * V_17 )
{
V_17 -> V_22 = F_4 () ;
}
static inline void F_11 ( struct V_16 * V_17 )
{
V_17 -> V_23 = F_4 () ;
}
static inline void F_12 ( struct V_16 * V_17 )
{
V_17 -> V_24 = F_4 () ;
}
static inline void F_13 ( struct V_16 * V_17 )
{
V_17 -> V_25 = F_4 () ;
}
static inline void F_14 ( struct V_16 * V_17 )
{
V_17 -> V_26 = F_4 () ;
}
static T_3 F_15 ( struct V_16 * V_17 )
{
return F_16 ( V_17 -> V_26 , V_17 -> V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
V_17 -> V_27 = F_18 ( V_17 -> V_27 ,
F_16 ( F_4 () ,
V_2 -> V_15 ) ) ;
V_17 -> V_28 = F_18 ( V_17 -> V_28 ,
F_16 ( V_2 -> V_15 ,
V_2 -> V_14 ) ) ;
V_17 -> V_29 = F_18 ( V_17 -> V_29 ,
F_16 ( V_2 -> V_14 ,
V_2 -> V_13 ) ) ;
V_17 -> V_30 ++ ;
}
static void F_19 ( struct V_16 * V_17 )
{
V_17 -> V_31 = F_18 ( V_17 -> V_31 ,
F_15 ( V_17 ) ) ;
V_17 -> V_32 ++ ;
}
static inline int F_20 ( void )
{
return V_33 -> V_34 ;
}
static inline int F_21 ( void )
{
return V_33 -> V_35 ;
}
static inline int F_22 ( void )
{
return V_33 -> V_36 ;
}
static inline int F_23 ( enum V_37 V_38 )
{
int V_39 ;
F_24 ( V_38 >= V_40 ) ;
V_39 = V_41 [ V_38 ] ;
F_24 ( V_38 != V_42 && V_39 == 0 ) ;
return V_39 ;
}
static struct V_43 * F_25 ( T_2 V_44 )
{
F_24 ( V_44 >= F_26 ( V_45 ) ) ;
return & V_45 [ V_44 ] ;
}
static T_2 F_27 ( struct V_43 * V_46 )
{
F_24 ( V_46 == NULL ) ;
return V_46 - V_45 ;
}
static int F_28 ( struct V_43 * V_46 , struct V_47 * V_48 )
{
int V_49 ;
F_29 ( & V_46 -> V_50 ) ;
V_49 = F_30 ( & V_46 -> V_51 , V_48 , 0 , 0 , V_52 ) ;
if ( V_49 >= 0 ) {
V_48 -> V_53 = V_49 ;
F_31 ( & V_48 -> V_54 , & V_46 -> V_55 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
if ( V_49 < 0 )
return V_49 ;
F_33 ( & V_48 -> V_56 ) ;
V_48 -> V_57 = V_42 ;
V_48 -> V_58 = 0 ;
return 0 ;
}
static void F_34 ( struct V_43 * V_46 ,
struct V_47 * V_48 ,
enum V_37 V_59 ,
T_4 V_60 )
{
F_35 ( & V_46 -> V_50 ) ;
if ( ! F_36 ( & V_48 -> V_54 ) ) {
F_37 ( & V_48 -> V_54 ) ;
V_48 -> V_57 = V_59 ;
V_48 -> V_58 = V_60 ;
F_38 ( & V_46 -> V_51 , V_48 -> V_53 ) ;
F_39 ( & V_48 -> V_56 ) ;
}
}
static void F_40 ( struct V_43 * V_46 ,
struct V_47 * V_48 ,
T_5 V_61 , enum V_37 V_59 ,
T_4 V_60 )
{
F_29 ( & V_46 -> V_50 ) ;
if ( V_48 == NULL ) {
if ( V_61 > V_62 )
goto V_63;
V_48 = F_41 ( & V_46 -> V_51 , V_61 ) ;
if ( V_48 == NULL )
goto V_63;
}
F_34 ( V_46 , V_48 , V_59 , V_60 ) ;
V_63:
F_32 ( & V_46 -> V_50 ) ;
return;
}
static void F_42 ( struct V_43 * V_46 )
{
struct V_47 * V_48 , * V_64 ;
unsigned int V_65 = 0 ;
F_35 ( & V_46 -> V_50 ) ;
F_43 (nsw, tmp, &nn->nn_status_list, ns_node_item) {
F_34 ( V_46 , V_48 , V_66 , 0 ) ;
V_65 ++ ;
}
F_44 ( 0 , L_1 , V_65 ,
F_27 ( V_46 ) ) ;
}
static int F_45 ( struct V_43 * V_46 ,
struct V_47 * V_48 )
{
int V_67 ;
F_29 ( & V_46 -> V_50 ) ;
V_67 = F_36 ( & V_48 -> V_54 ) ;
F_32 ( & V_46 -> V_50 ) ;
return V_67 ;
}
static void F_46 ( struct V_68 * V_68 )
{
struct V_16 * V_17 = F_47 ( V_68 ,
struct V_16 , V_69 ) ;
F_24 ( F_48 ( & V_17 -> V_70 ) ) ;
F_49 ( V_17 , L_2 ) ;
if ( V_17 -> V_71 ) {
F_50 ( V_17 -> V_71 ) ;
V_17 -> V_71 = NULL ;
}
F_51 ( & V_17 -> V_72 -> V_73 ) ;
F_52 ( V_17 -> V_72 ) ;
V_17 -> V_72 = NULL ;
F_53 ( V_17 ) ;
if ( V_17 -> V_74 )
F_54 ( V_17 -> V_74 ) ;
F_55 ( V_17 ) ;
}
static void F_56 ( struct V_16 * V_17 )
{
F_49 ( V_17 , L_3 ) ;
F_57 ( & V_17 -> V_69 , F_46 ) ;
}
static void F_58 ( struct V_16 * V_17 )
{
F_49 ( V_17 , L_4 ) ;
F_59 ( & V_17 -> V_69 ) ;
}
static struct V_16 * F_60 ( struct V_75 * V_7 )
{
struct V_16 * V_17 , * V_49 = NULL ;
struct V_76 * V_76 = NULL ;
int V_60 = 0 ;
V_76 = F_61 ( V_77 ) ;
V_17 = F_62 ( sizeof( * V_17 ) , V_77 ) ;
if ( V_17 == NULL || V_76 == NULL )
goto V_63;
F_63 ( & V_17 -> V_69 ) ;
F_64 ( V_7 ) ;
V_17 -> V_72 = V_7 ;
V_60 = F_65 ( & V_7 -> V_73 ) ;
if ( V_60 ) {
F_66 ( V_60 ) ;
F_52 ( V_7 ) ;
goto V_63;
}
F_67 ( & V_17 -> V_78 , V_79 ) ;
F_67 ( & V_17 -> V_80 , V_81 ) ;
F_67 ( & V_17 -> V_82 , V_83 ) ;
F_68 ( & V_17 -> V_84 , V_85 ) ;
F_69 ( & V_17 -> V_70 ) ;
V_17 -> V_70 . V_86 = V_87 ;
V_17 -> V_70 . V_88 = ( unsigned long ) V_17 ;
F_49 ( V_17 , L_5 ) ;
V_49 = V_17 ;
V_17 -> V_74 = V_76 ;
F_70 ( V_17 ) ;
V_17 = NULL ;
V_76 = NULL ;
V_63:
if ( V_76 )
F_54 ( V_76 ) ;
F_55 ( V_17 ) ;
return V_49 ;
}
static void F_71 ( struct V_16 * V_17 ,
struct V_89 * V_90 )
{
F_58 ( V_17 ) ;
if ( ! F_72 ( V_91 , V_90 ) )
F_56 ( V_17 ) ;
}
static void F_73 ( struct V_16 * V_17 ,
struct V_92 * V_90 ,
int V_93 )
{
F_58 ( V_17 ) ;
if ( ! F_74 ( V_91 , V_90 , V_93 ) )
F_56 ( V_17 ) ;
}
static void F_75 ( struct V_16 * V_17 ,
struct V_92 * V_90 )
{
if ( F_76 ( V_90 ) )
F_56 ( V_17 ) ;
}
int F_77 ( void )
{
return F_78 ( & V_94 ) ;
}
static void F_79 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
unsigned V_95 , int V_38 )
{
int V_96 = V_46 -> V_97 ;
int V_98 = V_46 -> V_99 ;
struct V_16 * V_100 = V_46 -> V_101 ;
F_35 ( & V_46 -> V_50 ) ;
if ( V_100 && ! V_17 )
F_80 ( & V_94 ) ;
else if ( ! V_100 && V_17 )
F_81 ( & V_94 ) ;
F_24 ( V_17 && V_46 -> V_101 && V_46 -> V_101 != V_17 ) ;
F_82 ( V_38 && V_95 , L_6 , V_38 , V_95 ) ;
F_82 ( V_95 && ! V_17 , L_7 , V_95 , V_17 ) ;
if ( V_96 && ! V_95 && V_38 == 0 )
V_38 = - V_102 ;
F_44 ( V_103 , L_8 ,
F_27 ( V_46 ) , V_46 -> V_101 , V_17 , V_46 -> V_97 , V_95 ,
V_46 -> V_99 , V_38 ) ;
V_46 -> V_101 = V_17 ;
V_46 -> V_97 = V_95 ? 1 : 0 ;
V_46 -> V_99 = V_38 ;
if ( V_46 -> V_99 || V_46 -> V_97 )
F_39 ( & V_46 -> V_104 ) ;
if ( ! V_98 && V_46 -> V_99 ) {
F_83 ( F_27 ( V_46 ) ) ;
F_74 ( V_91 , & V_46 -> V_105 ,
F_84 ( V_106 ) ) ;
}
if ( V_96 && ! V_95 ) {
if ( V_100 )
F_85 ( V_107 L_9
V_108 L_10 , F_86 ( V_100 ) ) ;
F_42 ( V_46 ) ;
}
if ( ! V_96 && V_95 ) {
F_87 ( F_27 ( V_46 ) ) ;
F_76 ( & V_46 -> V_109 ) ;
F_85 ( V_107 L_11 V_108 L_10 ,
F_88 () > V_17 -> V_72 -> V_110 ?
L_12 : L_13 ,
F_86 ( V_17 ) ) ;
}
if ( ! V_95 && V_91 ) {
unsigned long V_93 ;
V_93 = ( V_46 -> V_111 +
F_84 ( F_20 () ) )
- V_112 ;
if ( V_93 > F_84 ( F_20 () ) )
V_93 = 0 ;
F_44 ( V_103 , L_14 , V_93 ) ;
F_74 ( V_91 , & V_46 -> V_113 , V_93 ) ;
V_93 += F_84 ( F_22 () ) ;
F_74 ( V_91 , & V_46 -> V_109 , V_93 ) ;
}
if ( ( V_100 == NULL ) && V_17 )
F_58 ( V_17 ) ;
if ( V_100 && ( V_100 != V_17 ) ) {
F_71 ( V_100 , & V_100 -> V_82 ) ;
F_56 ( V_100 ) ;
}
}
static void F_89 ( struct V_114 * V_115 , int V_116 )
{
void (* F_90)( struct V_114 * V_115 , int V_116 );
F_91 ( & V_115 -> V_117 ) ;
if ( V_115 -> V_118 ) {
struct V_16 * V_17 = V_115 -> V_118 ;
F_49 ( V_17 , L_15 ) ;
F_10 ( V_17 ) ;
F_71 ( V_17 , & V_17 -> V_80 ) ;
F_90 = V_17 -> V_119 ;
} else {
F_90 = V_115 -> V_120 ;
}
F_92 ( & V_115 -> V_117 ) ;
F_90 ( V_115 , V_116 ) ;
}
static void F_93 ( struct V_114 * V_115 )
{
void (* F_94)( struct V_114 * V_115 );
struct V_16 * V_17 ;
F_91 ( & V_115 -> V_117 ) ;
V_17 = V_115 -> V_118 ;
if ( V_17 == NULL ) {
F_94 = V_115 -> V_121 ;
goto V_63;
}
F_49 ( V_17 , L_16 , V_115 -> V_122 ) ;
F_94 = V_17 -> V_123 ;
switch( V_115 -> V_122 ) {
case V_124 :
case V_125 :
break;
case V_126 :
F_71 ( V_17 , & V_17 -> V_78 ) ;
break;
default:
F_85 ( V_127 L_17 V_108
L_18 ,
F_86 ( V_17 ) , V_115 -> V_122 ) ;
F_71 ( V_17 , & V_17 -> V_82 ) ;
break;
}
V_63:
F_92 ( & V_115 -> V_117 ) ;
F_94 ( V_115 ) ;
}
static void F_95 ( struct V_114 * V_115 ,
struct V_16 * V_17 )
{
F_96 ( & V_115 -> V_117 ) ;
if ( V_115 -> V_120 == V_128 ) {
V_115 -> V_120 = V_115 -> V_118 ;
V_115 -> V_118 = NULL ;
}
F_24 ( V_115 -> V_118 != NULL ) ;
V_115 -> V_118 = V_17 ;
F_58 ( V_17 ) ;
V_17 -> V_119 = V_115 -> V_120 ;
V_17 -> V_123 = V_115 -> V_121 ;
V_115 -> V_120 = F_89 ;
V_115 -> V_121 = F_93 ;
F_97 ( & V_17 -> V_129 ) ;
F_98 ( & V_115 -> V_117 ) ;
}
static int F_99 ( struct V_114 * V_115 ,
struct V_16 * V_17 )
{
int V_49 = 0 ;
F_96 ( & V_115 -> V_117 ) ;
if ( V_115 -> V_118 == V_17 ) {
V_49 = 1 ;
V_115 -> V_118 = NULL ;
V_115 -> V_120 = V_17 -> V_119 ;
V_115 -> V_121 = V_17 -> V_123 ;
}
F_98 ( & V_115 -> V_117 ) ;
return V_49 ;
}
static void F_100 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
int V_38 )
{
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 == V_17 )
F_79 ( V_46 , NULL , 0 , V_38 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
static void V_83 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_82 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
F_49 ( V_17 , L_19 ) ;
if ( F_99 ( V_17 -> V_71 -> V_115 , V_17 ) ) {
F_101 ( & V_17 -> V_70 ) ;
F_75 ( V_17 , & V_17 -> V_84 ) ;
F_56 ( V_17 ) ;
F_102 ( V_17 -> V_71 , V_130 ) ;
}
F_100 ( V_46 , V_17 , 0 ) ;
F_56 ( V_17 ) ;
}
static int F_103 ( struct V_131 * V_132 , T_1 V_133 ,
T_1 V_134 )
{
int V_49 = memcmp ( & V_132 -> V_135 , & V_134 , sizeof( V_134 ) ) ;
if ( V_49 == 0 )
V_49 = memcmp ( & V_132 -> V_136 , & V_133 , sizeof( V_133 ) ) ;
return V_49 ;
}
static struct V_131 *
F_104 ( T_1 V_133 , T_1 V_134 , struct V_137 * * * V_138 ,
struct V_137 * * V_139 )
{
struct V_137 * * V_140 = & V_141 . V_137 ;
struct V_137 * V_142 = NULL ;
struct V_131 * V_132 , * V_49 = NULL ;
int V_143 ;
while ( * V_140 ) {
V_142 = * V_140 ;
V_132 = F_105 ( V_142 , struct V_131 , V_144 ) ;
V_143 = F_103 ( V_132 , V_133 , V_134 ) ;
if ( V_143 < 0 )
V_140 = & ( * V_140 ) -> V_145 ;
else if ( V_143 > 0 )
V_140 = & ( * V_140 ) -> V_146 ;
else {
V_49 = V_132 ;
break;
}
}
if ( V_138 != NULL )
* V_138 = V_140 ;
if ( V_139 != NULL )
* V_139 = V_142 ;
return V_49 ;
}
static void F_106 ( struct V_68 * V_68 )
{
struct V_131 * V_132 ;
V_132 = F_47 ( V_68 , struct V_131 , V_147 ) ;
F_55 ( V_132 ) ;
}
static void F_107 ( struct V_131 * V_132 )
{
F_57 ( & V_132 -> V_147 , F_106 ) ;
}
int F_108 ( T_1 V_133 , T_1 V_134 , T_1 V_148 ,
T_6 * V_149 , void * V_88 ,
T_7 * V_150 ,
struct V_151 * V_152 )
{
struct V_131 * V_132 = NULL ;
struct V_137 * * V_140 , * V_142 ;
int V_49 = 0 ;
if ( V_148 > V_153 ) {
F_44 ( 0 , L_20 ,
V_148 ) ;
V_49 = - V_154 ;
goto V_63;
}
if ( ! V_133 ) {
F_44 ( 0 , L_21 , V_133 , V_149 ) ;
V_49 = - V_154 ;
goto V_63;
}
if ( ! V_149 ) {
F_44 ( 0 , L_22 ,
V_133 , V_149 ) ;
V_49 = - V_154 ;
goto V_63;
}
V_132 = F_62 ( sizeof( struct V_131 ) , V_77 ) ;
if ( V_132 == NULL ) {
V_49 = - V_155 ;
goto V_63;
}
V_132 -> V_156 = V_149 ;
V_132 -> V_157 = V_88 ;
V_132 -> V_158 = V_150 ;
V_132 -> V_136 = V_133 ;
V_132 -> V_159 = V_148 ;
V_132 -> V_135 = V_134 ;
F_63 ( & V_132 -> V_147 ) ;
F_2 ( & V_132 -> V_160 ) ;
F_109 ( & V_161 ) ;
if ( F_104 ( V_133 , V_134 , & V_140 , & V_142 ) )
V_49 = - V_162 ;
else {
F_110 ( & V_132 -> V_144 , V_142 , V_140 ) ;
F_111 ( & V_132 -> V_144 , & V_141 ) ;
F_31 ( & V_132 -> V_160 , V_152 ) ;
F_44 ( V_163 , L_23 ,
V_149 , V_133 , V_134 ) ;
F_82 ( F_104 ( V_133 , V_134 , & V_140 ,
& V_142 ) == NULL ,
L_24
L_25 , V_133 , V_134 ) ;
}
F_112 ( & V_161 ) ;
if ( V_49 )
goto V_63;
V_63:
if ( V_49 )
F_55 ( V_132 ) ;
return V_49 ;
}
void F_113 ( struct V_151 * V_164 )
{
struct V_131 * V_132 , * V_165 ;
F_109 ( & V_161 ) ;
F_43 (nmh, n, list, nh_unregister_item) {
F_44 ( V_163 , L_26 ,
V_132 -> V_156 , V_132 -> V_136 , V_132 -> V_135 ) ;
F_114 ( & V_132 -> V_144 , & V_141 ) ;
F_37 ( & V_132 -> V_160 ) ;
F_57 ( & V_132 -> V_147 , F_106 ) ;
}
F_112 ( & V_161 ) ;
}
static struct V_131 * F_115 ( T_1 V_133 , T_1 V_134 )
{
struct V_131 * V_132 ;
F_91 ( & V_161 ) ;
V_132 = F_104 ( V_133 , V_134 , NULL , NULL ) ;
if ( V_132 )
F_59 ( & V_132 -> V_147 ) ;
F_92 ( & V_161 ) ;
return V_132 ;
}
static int F_116 ( struct V_166 * V_114 , void * V_88 , T_8 V_167 )
{
int V_49 ;
T_9 V_168 ;
struct V_169 V_170 = {
. V_171 = V_167 ,
. V_172 = V_88 ,
} ;
struct V_173 V_174 = {
. V_175 = 1 ,
. V_176 = (struct V_177 * ) & V_170 ,
. V_178 = V_179 ,
} ;
V_168 = F_117 () ;
F_118 ( F_119 () ) ;
V_49 = F_120 ( V_114 , & V_174 , V_167 , V_174 . V_178 ) ;
F_118 ( V_168 ) ;
return V_49 ;
}
static int F_121 ( struct V_166 * V_114 , struct V_169 * V_170 ,
T_8 V_180 , T_8 V_181 )
{
int V_49 ;
T_9 V_168 ;
struct V_173 V_174 = {
. V_176 = (struct V_177 * ) V_170 ,
. V_175 = V_180 ,
} ;
if ( V_114 == NULL ) {
V_49 = - V_154 ;
goto V_63;
}
V_168 = F_117 () ;
F_118 ( F_119 () ) ;
V_49 = F_122 ( V_114 , & V_174 , V_181 ) ;
F_118 ( V_168 ) ;
if ( V_49 != V_181 ) {
F_44 ( V_182 , L_27 , V_49 ,
V_181 ) ;
if ( V_49 >= 0 )
V_49 = - V_183 ;
goto V_63;
}
V_49 = 0 ;
V_63:
if ( V_49 < 0 )
F_44 ( 0 , L_28 , V_49 ) ;
return V_49 ;
}
static void F_123 ( struct V_16 * V_17 ,
void * V_184 ,
T_8 V_185 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
T_10 V_49 ;
while ( 1 ) {
F_124 ( & V_17 -> V_129 ) ;
V_49 = V_17 -> V_71 -> V_186 -> V_187 ( V_17 -> V_71 ,
F_125 ( V_184 ) ,
( long ) V_184 & ~ V_188 ,
V_185 , V_179 ) ;
F_126 ( & V_17 -> V_129 ) ;
if ( V_49 == V_185 )
break;
if ( V_49 == ( T_10 ) - V_189 ) {
F_44 ( 0 , L_29 V_108
L_30 , V_185 , F_86 ( V_17 ) ) ;
F_127 () ;
continue;
}
F_44 ( V_182 , L_29 V_108
L_31 , V_185 , F_86 ( V_17 ) , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
break;
}
}
static void F_128 ( struct V_190 * V_174 , T_11 V_191 , T_11 V_133 , T_1 V_134 )
{
memset ( V_174 , 0 , sizeof( struct V_190 ) ) ;
V_174 -> V_192 = F_129 ( V_193 ) ;
V_174 -> V_191 = F_129 ( V_191 ) ;
V_174 -> V_133 = F_129 ( V_133 ) ;
V_174 -> V_59 = F_130 ( V_42 ) ;
V_174 -> V_60 = 0 ;
V_174 -> V_134 = F_130 ( V_134 ) ;
}
static int F_131 ( struct V_43 * V_46 ,
struct V_16 * * V_194 ,
int * error )
{
int V_49 = 0 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_99 ) {
V_49 = 1 ;
* V_194 = NULL ;
* error = V_46 -> V_99 ;
} else if ( V_46 -> V_97 ) {
F_59 ( & V_46 -> V_101 -> V_69 ) ;
V_49 = 1 ;
* V_194 = V_46 -> V_101 ;
* error = 0 ;
}
F_32 ( & V_46 -> V_50 ) ;
return V_49 ;
}
void F_132 ( unsigned long * V_195 , unsigned V_116 )
{
struct V_16 * V_17 ;
int V_7 , V_49 ;
F_24 ( V_116 < ( F_133 ( V_196 ) * sizeof( unsigned long ) ) ) ;
memset ( V_195 , 0 , V_116 ) ;
for ( V_7 = 0 ; V_7 < V_196 ; ++ V_7 ) {
F_131 ( F_25 ( V_7 ) , & V_17 , & V_49 ) ;
if ( ! V_49 ) {
F_134 ( V_7 , V_195 ) ;
F_56 ( V_17 ) ;
}
}
}
int F_135 ( T_1 V_133 , T_1 V_134 , struct V_169 * V_197 ,
T_8 V_198 , T_2 V_199 , int * V_60 )
{
int V_49 = 0 ;
struct V_190 * V_174 = NULL ;
T_8 V_180 , V_200 = 0 ;
struct V_169 * V_170 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 = F_25 ( V_199 ) ;
struct V_47 V_48 = {
. V_54 = F_136 ( V_48 . V_54 ) ,
} ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_133 , V_134 , V_201 , V_199 ) ;
if ( V_91 == NULL ) {
F_44 ( 0 , L_32 ) ;
V_49 = - V_202 ;
goto V_63;
}
if ( V_198 == 0 ) {
F_44 ( 0 , L_33 ) ;
V_49 = - V_154 ;
goto V_63;
}
V_200 = F_137 ( (struct V_177 * ) V_197 , V_198 ) ;
if ( V_200 > V_153 ) {
F_44 ( 0 , L_34 , V_200 ) ;
V_49 = - V_154 ;
goto V_63;
}
if ( V_199 == F_88 () ) {
V_49 = - V_203 ;
goto V_63;
}
F_138 ( & V_2 ) ;
F_3 ( & V_2 ) ;
F_139 ( V_46 -> V_104 , F_131 ( V_46 , & V_17 , & V_49 ) ) ;
if ( V_49 )
goto V_63;
F_7 ( & V_2 , V_17 ) ;
V_180 = V_198 + 1 ;
V_170 = F_140 ( sizeof( struct V_169 ) * V_180 , V_52 ) ;
if ( V_170 == NULL ) {
F_44 ( 0 , L_35 , V_180 ) ;
V_49 = - V_155 ;
goto V_63;
}
V_174 = F_140 ( sizeof( struct V_190 ) , V_52 ) ;
if ( ! V_174 ) {
F_44 ( 0 , L_36 ) ;
V_49 = - V_155 ;
goto V_63;
}
F_128 ( V_174 , V_200 , V_133 , V_134 ) ;
V_170 [ 0 ] . V_171 = sizeof( struct V_190 ) ;
V_170 [ 0 ] . V_172 = V_174 ;
memcpy ( & V_170 [ 1 ] , V_197 , V_198 * sizeof( struct V_169 ) ) ;
V_49 = F_28 ( V_46 , & V_48 ) ;
if ( V_49 )
goto V_63;
V_174 -> V_204 = F_130 ( V_48 . V_53 ) ;
F_8 ( & V_2 , V_48 . V_53 ) ;
F_5 ( & V_2 ) ;
F_124 ( & V_17 -> V_129 ) ;
V_49 = F_121 ( V_17 -> V_71 , V_170 , V_180 ,
sizeof( struct V_190 ) + V_200 ) ;
F_126 ( & V_17 -> V_129 ) ;
F_141 ( V_174 , L_37 , V_49 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_38 , V_49 ) ;
goto V_63;
}
F_6 ( & V_2 ) ;
F_139 ( V_48 . V_56 , F_45 ( V_46 , & V_48 ) ) ;
F_17 ( & V_2 , V_17 ) ;
V_49 = F_23 ( V_48 . V_57 ) ;
if ( V_60 && ! V_49 )
* V_60 = V_48 . V_58 ;
F_44 ( 0 , L_39 ,
V_49 , V_48 . V_58 ) ;
V_63:
F_142 ( & V_2 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
F_55 ( V_170 ) ;
F_55 ( V_174 ) ;
F_40 ( V_46 , & V_48 , 0 , 0 , 0 ) ;
return V_49 ;
}
int F_143 ( T_1 V_133 , T_1 V_134 , void * V_88 , T_1 V_167 ,
T_2 V_199 , int * V_60 )
{
struct V_169 V_170 = {
. V_172 = V_88 ,
. V_171 = V_167 ,
} ;
return F_135 ( V_133 , V_134 , & V_170 , 1 ,
V_199 , V_60 ) ;
}
static int F_144 ( struct V_166 * V_114 , struct V_190 * V_205 ,
enum V_37 V_206 , int V_38 )
{
struct V_169 V_170 = {
. V_172 = V_205 ,
. V_171 = sizeof( struct V_190 ) ,
} ;
F_24 ( V_206 >= V_40 ) ;
V_205 -> V_59 = F_130 ( V_206 ) ;
V_205 -> V_60 = F_130 ( V_38 ) ;
V_205 -> V_192 = F_129 ( V_207 ) ;
V_205 -> V_191 = 0 ;
F_141 ( V_205 , L_40 , V_38 ) ;
return F_121 ( V_114 , & V_170 , 1 , sizeof( struct V_190 ) ) ;
}
static int F_145 ( struct V_16 * V_17 ,
struct V_190 * V_205 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
int V_49 = 0 , V_208 ;
enum V_37 V_206 ;
struct V_131 * V_132 = NULL ;
void * V_209 = NULL ;
F_141 ( V_205 , L_41 ) ;
F_146 ( V_17 ) ;
switch( F_147 ( V_205 -> V_192 ) ) {
case V_207 :
F_40 ( V_46 , NULL ,
F_148 ( V_205 -> V_204 ) ,
F_148 ( V_205 -> V_59 ) ,
F_148 ( V_205 -> V_60 ) ) ;
goto V_63;
case V_210 :
F_123 ( V_17 , V_211 ,
sizeof( * V_211 ) ) ;
goto V_63;
case V_212 :
goto V_63;
case V_193 :
break;
default:
F_141 ( V_205 , L_42 ) ;
V_49 = - V_154 ;
goto V_63;
break;
}
V_208 = 0 ;
V_132 = F_115 ( F_147 ( V_205 -> V_133 ) ,
F_148 ( V_205 -> V_134 ) ) ;
if ( ! V_132 ) {
F_44 ( V_163 , L_43 ,
F_147 ( V_205 -> V_133 ) , F_148 ( V_205 -> V_134 ) ) ;
V_206 = V_213 ;
goto V_214;
}
V_206 = V_42 ;
if ( F_147 ( V_205 -> V_191 ) > V_132 -> V_159 )
V_206 = V_215 ;
if ( V_206 != V_42 )
goto V_214;
F_13 ( V_17 ) ;
V_17 -> V_216 = F_148 ( V_205 -> V_134 ) ;
V_17 -> V_217 = F_147 ( V_205 -> V_133 ) ;
V_208 = ( V_132 -> V_156 ) ( V_205 , sizeof( struct V_190 ) +
F_147 ( V_205 -> V_191 ) ,
V_132 -> V_157 , & V_209 ) ;
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
V_214:
F_124 ( & V_17 -> V_129 ) ;
V_49 = F_144 ( V_17 -> V_71 , V_205 , V_206 ,
V_208 ) ;
F_126 ( & V_17 -> V_129 ) ;
V_205 = NULL ;
F_44 ( 0 , L_44 ,
V_208 , V_206 , V_49 ) ;
if ( V_132 ) {
F_24 ( V_209 != NULL && V_132 -> V_158 == NULL ) ;
if ( V_132 -> V_158 )
( V_132 -> V_158 ) ( V_208 , V_132 -> V_157 ,
V_209 ) ;
}
V_63:
if ( V_132 )
F_107 ( V_132 ) ;
return V_49 ;
}
static int F_149 ( struct V_16 * V_17 )
{
struct V_218 * V_219 = F_150 ( V_17 -> V_74 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
if ( V_219 -> V_220 != F_151 ( V_221 ) ) {
F_85 ( V_107 L_45 V_108 L_46
L_47
L_48 , F_86 ( V_17 ) ,
( unsigned long long ) F_152 ( V_219 -> V_220 ) ,
V_221 ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_148 ( V_219 -> V_222 ) !=
F_22 () ) {
F_85 ( V_107 L_45 V_108 L_49
L_50
L_48 , F_86 ( V_17 ) ,
F_148 ( V_219 -> V_222 ) ,
F_22 () ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_148 ( V_219 -> V_223 ) !=
F_21 () ) {
F_85 ( V_107 L_45 V_108 L_51
L_52
L_48 , F_86 ( V_17 ) ,
F_148 ( V_219 -> V_223 ) ,
F_21 () ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_148 ( V_219 -> V_224 ) !=
V_225 ) {
F_85 ( V_107 L_45 V_108 L_53
L_54
L_48 , F_86 ( V_17 ) ,
F_148 ( V_219 -> V_224 ) ,
V_225 ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
V_17 -> V_226 = 1 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 == V_17 ) {
F_153 ( V_17 ) ;
F_154 ( & V_46 -> V_227 , 0 ) ;
F_79 ( V_46 , V_17 , 1 , 0 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
V_17 -> V_228 -= sizeof( struct V_218 ) ;
if ( V_17 -> V_228 )
memmove ( V_219 , V_219 + 1 , V_17 -> V_228 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_17 )
{
struct V_190 * V_205 ;
int V_49 = 0 ;
void * V_88 ;
T_8 V_229 ;
F_49 ( V_17 , L_55 ) ;
F_11 ( V_17 ) ;
if ( F_156 ( V_17 -> V_226 == 0 ) ) {
if( V_17 -> V_228 < sizeof( struct V_218 ) ) {
V_88 = F_150 ( V_17 -> V_74 ) + V_17 -> V_228 ;
V_229 = sizeof( struct V_218 ) - V_17 -> V_228 ;
V_49 = F_116 ( V_17 -> V_71 , V_88 , V_229 ) ;
if ( V_49 > 0 )
V_17 -> V_228 += V_49 ;
}
if ( V_17 -> V_228 == sizeof( struct V_218 ) ) {
F_149 ( V_17 ) ;
if ( F_156 ( V_17 -> V_226 == 0 ) )
V_49 = - V_230 ;
}
goto V_63;
}
if ( V_17 -> V_228 < sizeof( struct V_190 ) ) {
V_88 = F_150 ( V_17 -> V_74 ) + V_17 -> V_228 ;
V_229 = sizeof( struct V_190 ) - V_17 -> V_228 ;
V_49 = F_116 ( V_17 -> V_71 , V_88 , V_229 ) ;
if ( V_49 > 0 ) {
V_17 -> V_228 += V_49 ;
if ( V_17 -> V_228 == sizeof( struct V_190 ) ) {
V_205 = F_150 ( V_17 -> V_74 ) ;
if ( F_147 ( V_205 -> V_191 ) >
V_153 )
V_49 = - V_231 ;
}
}
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_228 < sizeof( struct V_190 ) ) {
goto V_63;
}
V_205 = F_150 ( V_17 -> V_74 ) ;
F_141 ( V_205 , L_56 , V_17 -> V_228 ) ;
if ( V_17 -> V_228 - sizeof( struct V_190 ) < F_147 ( V_205 -> V_191 ) ) {
V_88 = F_150 ( V_17 -> V_74 ) + V_17 -> V_228 ;
V_229 = ( sizeof( struct V_190 ) + F_147 ( V_205 -> V_191 ) ) -
V_17 -> V_228 ;
V_49 = F_116 ( V_17 -> V_71 , V_88 , V_229 ) ;
if ( V_49 > 0 )
V_17 -> V_228 += V_49 ;
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_228 - sizeof( struct V_190 ) == F_147 ( V_205 -> V_191 ) ) {
V_49 = F_145 ( V_17 , V_205 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_17 -> V_228 = 0 ;
}
V_63:
F_49 ( V_17 , L_57 , V_49 ) ;
F_12 ( V_17 ) ;
return V_49 ;
}
static void V_81 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 , V_80 ) ;
int V_49 ;
do {
V_49 = F_155 ( V_17 ) ;
} while ( V_49 > 0 );
if ( V_49 <= 0 && V_49 != - V_189 ) {
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
F_49 ( V_17 , L_58 , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
}
F_56 ( V_17 ) ;
}
static int F_157 ( struct V_166 * V_114 )
{
int V_49 , V_232 = 1 ;
T_9 V_168 ;
V_168 = F_117 () ;
F_118 ( V_233 ) ;
V_49 = V_114 -> V_186 -> V_234 ( V_114 , V_235 , V_236 ,
( char V_237 * ) & V_232 , sizeof( V_232 ) ) ;
F_118 ( V_168 ) ;
return V_49 ;
}
static void F_158 ( void )
{
V_238 -> V_224 = F_130 (
V_225 ) ;
V_238 -> V_222 = F_130 ( F_22 () ) ;
V_238 -> V_223 = F_130 (
F_21 () ) ;
V_238 -> V_239 = F_130 (
F_20 () ) ;
}
static void V_79 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_78 ) ;
F_44 ( V_240 , L_59 ,
( unsigned long long ) V_221 ,
( unsigned long long ) F_152 ( V_238 -> V_241 ) ) ;
F_158 () ;
F_123 ( V_17 , V_238 , sizeof( * V_238 ) ) ;
F_56 ( V_17 ) ;
}
static void V_85 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_84 . V_90 ) ;
F_123 ( V_17 , V_242 , sizeof( * V_242 ) ) ;
F_56 ( V_17 ) ;
}
static void V_87 ( unsigned long V_88 )
{
struct V_16 * V_17 = (struct V_16 * ) V_88 ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
#ifdef F_159
unsigned long V_243 = F_160 ( F_4 () ) -
F_160 ( V_17 -> V_21 ) ;
#else
unsigned long V_243 = F_22 () ;
#endif
F_85 ( V_107 L_17 V_108 L_60
L_61 , F_86 ( V_17 ) ,
V_243 / 1000 , V_243 % 1000 ) ;
F_154 ( & V_46 -> V_227 , 1 ) ;
F_71 ( V_17 , & V_17 -> V_82 ) ;
}
static void F_153 ( struct V_16 * V_17 )
{
F_75 ( V_17 , & V_17 -> V_84 ) ;
F_73 ( V_17 , & V_17 -> V_84 ,
F_84 ( F_21 () ) ) ;
F_9 ( V_17 ) ;
F_161 ( & V_17 -> V_70 ,
V_112 + F_84 ( F_22 () ) ) ;
}
static void F_146 ( struct V_16 * V_17 )
{
if ( F_48 ( & V_17 -> V_70 ) )
F_153 ( V_17 ) ;
}
static void F_162 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_113 . V_90 ) ;
struct V_16 * V_17 = NULL ;
struct V_75 * V_7 = NULL , * V_244 = NULL ;
struct V_166 * V_114 = NULL ;
struct V_245 V_246 = { 0 , } , V_247 = { 0 , } ;
int V_49 = 0 , V_248 ;
unsigned int V_249 ;
if ( F_88 () <= F_27 ( V_46 ) )
goto V_63;
V_7 = F_163 ( F_27 ( V_46 ) ) ;
if ( V_7 == NULL ) {
V_49 = 0 ;
goto V_63;
}
V_244 = F_163 ( F_88 () ) ;
if ( V_244 == NULL ) {
V_49 = 0 ;
goto V_63;
}
F_29 ( & V_46 -> V_50 ) ;
V_249 = F_78 ( & V_46 -> V_227 ) ;
V_248 = ( V_46 -> V_101 ||
( V_46 -> V_99 &&
( V_46 -> V_99 != - V_102 || V_249 == 0 ) ) ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_248 )
goto V_63;
V_46 -> V_111 = V_112 ;
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
F_44 ( 0 , L_62 ) ;
V_49 = - V_155 ;
goto V_63;
}
V_49 = F_164 ( V_250 , V_251 , V_252 , & V_114 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_63 , V_49 ) ;
goto V_63;
}
V_17 -> V_71 = V_114 ;
V_114 -> V_115 -> V_253 = V_52 ;
V_246 . V_254 = V_255 ;
V_246 . V_256 . V_257 = V_244 -> V_258 ;
V_246 . V_259 = F_165 ( 0 ) ;
V_49 = V_114 -> V_186 -> V_260 ( V_114 , (struct V_261 * ) & V_246 ,
sizeof( V_246 ) ) ;
if ( V_49 ) {
F_44 ( V_182 , L_64 ,
V_49 , & V_244 -> V_258 ) ;
goto V_63;
}
V_49 = F_157 ( V_17 -> V_71 ) ;
if ( V_49 ) {
F_44 ( V_182 , L_65 , V_49 ) ;
goto V_63;
}
F_95 ( V_17 -> V_71 -> V_115 , V_17 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
V_247 . V_254 = V_255 ;
V_247 . V_256 . V_257 = V_7 -> V_258 ;
V_247 . V_259 = V_7 -> V_262 ;
V_49 = V_17 -> V_71 -> V_186 -> V_263 ( V_17 -> V_71 ,
(struct V_261 * ) & V_247 ,
sizeof( V_247 ) ,
V_264 ) ;
if ( V_49 == - V_265 )
V_49 = 0 ;
V_63:
if ( V_49 && V_17 ) {
F_85 ( V_107 L_66 V_108
L_67 , F_86 ( V_17 ) , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
}
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_244 )
F_52 ( V_244 ) ;
return;
}
static void F_166 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_109 . V_90 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( ! V_46 -> V_97 ) {
F_85 ( V_107 L_68
L_69 ,
F_27 ( V_46 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
F_79 ( V_46 , NULL , 0 , - V_102 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
}
static void F_167 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_105 . V_90 ) ;
F_168 ( F_27 ( V_46 ) ) ;
}
void F_169 ( struct V_75 * V_7 )
{
struct V_43 * V_46 = F_25 ( V_7 -> V_110 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_154 ( & V_46 -> V_227 , 0 ) ;
F_79 ( V_46 , NULL , 0 , - V_102 ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_91 ) {
F_76 ( & V_46 -> V_109 ) ;
F_76 ( & V_46 -> V_113 ) ;
F_76 ( & V_46 -> V_105 ) ;
F_170 ( V_91 ) ;
}
}
static void F_171 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
F_172 ( V_44 ) ;
if ( ! V_7 )
return;
if ( V_44 != F_88 () )
F_169 ( V_7 ) ;
F_24 ( F_78 ( & V_94 ) < 0 ) ;
}
static void F_173 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
struct V_43 * V_46 = F_25 ( V_44 ) ;
F_174 ( V_44 ) ;
F_24 ( ! V_7 ) ;
V_46 -> V_111 = V_112 -
( F_84 ( F_20 () ) + 1 ) ;
if ( V_44 != F_88 () ) {
F_29 ( & V_46 -> V_50 ) ;
F_154 ( & V_46 -> V_227 , 0 ) ;
if ( V_46 -> V_99 )
F_79 ( V_46 , NULL , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
}
void F_175 ( void )
{
F_176 ( NULL , & V_266 ) ;
F_176 ( NULL , & V_267 ) ;
}
int F_177 ( void )
{
int V_49 ;
F_178 ( & V_267 , V_268 ,
F_171 , NULL , V_269 ) ;
F_178 ( & V_266 , V_270 ,
F_173 , NULL , V_269 ) ;
V_49 = F_179 ( NULL , & V_266 ) ;
if ( V_49 == 0 )
V_49 = F_179 ( NULL , & V_267 ) ;
if ( V_49 )
F_175 () ;
return V_49 ;
}
static int F_180 ( struct V_166 * V_114 )
{
int V_49 , V_271 ;
struct V_245 sin ;
struct V_166 * V_272 = NULL ;
struct V_75 * V_7 = NULL ;
struct V_75 * V_273 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 ;
F_24 ( V_114 == NULL ) ;
V_49 = F_181 ( V_114 -> V_115 -> V_274 , V_114 -> V_115 -> V_275 ,
V_114 -> V_115 -> V_276 , & V_272 ) ;
if ( V_49 )
goto V_63;
V_272 -> type = V_114 -> type ;
V_272 -> V_186 = V_114 -> V_186 ;
V_49 = V_114 -> V_186 -> V_277 ( V_114 , V_272 , V_264 ) ;
if ( V_49 < 0 )
goto V_63;
V_272 -> V_115 -> V_253 = V_52 ;
V_49 = F_157 ( V_272 ) ;
if ( V_49 ) {
F_44 ( V_182 , L_65 , V_49 ) ;
goto V_63;
}
V_271 = sizeof( sin ) ;
V_49 = V_272 -> V_186 -> V_278 ( V_272 , (struct V_261 * ) & sin ,
& V_271 , 1 ) ;
if ( V_49 < 0 )
goto V_63;
V_7 = F_182 ( sin . V_256 . V_257 ) ;
if ( V_7 == NULL ) {
F_85 ( V_107 L_70
L_71 , & sin . V_256 . V_257 ,
F_183 ( sin . V_259 ) ) ;
V_49 = - V_154 ;
goto V_63;
}
if ( F_88 () >= V_7 -> V_110 ) {
V_273 = F_163 ( F_88 () ) ;
if ( V_273 )
F_85 ( V_107 L_72
L_73
L_74 ,
V_273 -> V_279 , V_273 -> V_110 ,
& ( V_273 -> V_258 ) ,
F_183 ( V_273 -> V_262 ) ,
V_7 -> V_279 ,
V_7 -> V_110 , & sin . V_256 . V_257 ,
F_183 ( sin . V_259 ) ) ;
V_49 = - V_154 ;
goto V_63;
}
if ( ! F_184 ( V_7 -> V_110 ) ) {
F_44 ( V_103 , L_75
L_76 ,
V_7 -> V_279 , & sin . V_256 . V_257 ,
F_183 ( sin . V_259 ) ) ;
V_49 = - V_154 ;
goto V_63;
}
V_46 = F_25 ( V_7 -> V_110 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 )
V_49 = - V_280 ;
else
V_49 = 0 ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_49 ) {
F_85 ( V_107 L_77
L_78 ,
V_7 -> V_279 , & sin . V_256 . V_257 ,
F_183 ( sin . V_259 ) ) ;
goto V_63;
}
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
V_49 = - V_155 ;
goto V_63;
}
V_17 -> V_71 = V_272 ;
V_272 = NULL ;
F_29 ( & V_46 -> V_50 ) ;
F_154 ( & V_46 -> V_227 , 0 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
F_95 ( V_17 -> V_71 -> V_115 , V_17 ) ;
F_71 ( V_17 , & V_17 -> V_80 ) ;
F_158 () ;
F_123 ( V_17 , V_238 , sizeof( * V_238 ) ) ;
V_63:
if ( V_272 )
F_50 ( V_272 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_273 )
F_52 ( V_273 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
return V_49 ;
}
static void F_185 ( struct V_89 * V_90 )
{
struct V_166 * V_114 = V_281 ;
while ( F_180 ( V_114 ) == 0 )
F_127 () ;
}
static void V_128 ( struct V_114 * V_115 , int V_116 )
{
void (* F_90)( struct V_114 * V_115 , int V_116 );
F_91 ( & V_115 -> V_117 ) ;
F_90 = V_115 -> V_118 ;
if ( F_90 == NULL ) {
F_90 = V_115 -> V_120 ;
goto V_63;
}
if ( V_115 -> V_122 == V_282 ) {
F_44 ( V_163 , L_79 , V_116 ) ;
F_72 ( V_91 , & V_283 ) ;
}
V_63:
F_92 ( & V_115 -> V_117 ) ;
F_90 ( V_115 , V_116 ) ;
}
static int F_186 ( T_12 V_284 , T_13 V_285 )
{
struct V_166 * V_114 = NULL ;
int V_49 ;
struct V_245 sin = {
. V_254 = V_250 ,
. V_256 = { . V_257 = V_284 } ,
. V_259 = V_285 ,
} ;
V_49 = F_164 ( V_250 , V_251 , V_252 , & V_114 ) ;
if ( V_49 < 0 ) {
F_85 ( V_286 L_80 , V_49 ) ;
goto V_63;
}
V_114 -> V_115 -> V_253 = V_52 ;
F_96 ( & V_114 -> V_115 -> V_117 ) ;
V_114 -> V_115 -> V_118 = V_114 -> V_115 -> V_120 ;
V_114 -> V_115 -> V_120 = V_128 ;
F_98 ( & V_114 -> V_115 -> V_117 ) ;
V_281 = V_114 ;
F_67 ( & V_283 , F_185 ) ;
V_114 -> V_115 -> V_287 = V_288 ;
V_49 = V_114 -> V_186 -> V_260 ( V_114 , (struct V_261 * ) & sin , sizeof( sin ) ) ;
if ( V_49 < 0 ) {
F_85 ( V_286 L_81
L_82 , V_49 , & V_284 , F_183 ( V_285 ) ) ;
goto V_63;
}
V_49 = V_114 -> V_186 -> V_289 ( V_114 , 64 ) ;
if ( V_49 < 0 )
F_85 ( V_286 L_83 ,
V_49 , & V_284 , F_183 ( V_285 ) ) ;
V_63:
if ( V_49 ) {
V_281 = NULL ;
if ( V_114 )
F_50 ( V_114 ) ;
}
return V_49 ;
}
int F_187 ( struct V_75 * V_7 )
{
int V_49 = 0 ;
F_24 ( V_91 != NULL ) ;
F_24 ( V_281 != NULL ) ;
F_44 ( V_290 , L_84 ) ;
V_91 = F_188 ( L_85 ) ;
if ( V_91 == NULL ) {
F_44 ( V_182 , L_86 ) ;
return - V_155 ;
}
V_49 = F_186 ( V_7 -> V_258 ,
V_7 -> V_262 ) ;
if ( V_49 ) {
F_189 ( V_91 ) ;
V_91 = NULL ;
} else
F_87 ( V_7 -> V_110 ) ;
return V_49 ;
}
void F_190 ( struct V_75 * V_7 )
{
struct V_166 * V_114 = V_281 ;
T_8 V_291 ;
F_24 ( V_91 == NULL ) ;
F_24 ( V_281 == NULL ) ;
F_96 ( & V_114 -> V_115 -> V_117 ) ;
V_114 -> V_115 -> V_120 = V_114 -> V_115 -> V_118 ;
V_114 -> V_115 -> V_118 = NULL ;
F_98 ( & V_114 -> V_115 -> V_117 ) ;
for ( V_291 = 0 ; V_291 < F_26 ( V_45 ) ; V_291 ++ ) {
struct V_75 * V_7 = F_163 ( V_291 ) ;
if ( V_7 ) {
F_169 ( V_7 ) ;
F_52 ( V_7 ) ;
}
}
F_44 ( V_290 , L_87 ) ;
F_189 ( V_91 ) ;
V_91 = NULL ;
F_50 ( V_281 ) ;
V_281 = NULL ;
F_83 ( V_7 -> V_110 ) ;
}
int F_191 ( void )
{
unsigned long V_291 ;
F_192 () ;
if ( F_193 () )
return - V_155 ;
V_238 = F_62 ( sizeof( struct V_218 ) , V_292 ) ;
V_242 = F_62 ( sizeof( struct V_190 ) , V_292 ) ;
V_211 = F_62 ( sizeof( struct V_190 ) , V_292 ) ;
if ( ! V_238 || ! V_242 || ! V_211 ) {
F_55 ( V_238 ) ;
F_55 ( V_242 ) ;
F_55 ( V_211 ) ;
return - V_155 ;
}
V_238 -> V_220 = F_151 ( V_221 ) ;
V_238 -> V_241 = F_151 ( 1 ) ;
V_242 -> V_192 = F_129 ( V_210 ) ;
V_211 -> V_192 = F_129 ( V_212 ) ;
for ( V_291 = 0 ; V_291 < F_26 ( V_45 ) ; V_291 ++ ) {
struct V_43 * V_46 = F_25 ( V_291 ) ;
F_154 ( & V_46 -> V_227 , 0 ) ;
F_194 ( & V_46 -> V_50 ) ;
F_68 ( & V_46 -> V_113 , F_162 ) ;
F_68 ( & V_46 -> V_109 ,
F_166 ) ;
F_68 ( & V_46 -> V_105 , F_167 ) ;
V_46 -> V_99 = - V_102 ;
F_33 ( & V_46 -> V_104 ) ;
F_195 ( & V_46 -> V_51 ) ;
F_2 ( & V_46 -> V_55 ) ;
}
return 0 ;
}
void F_196 ( void )
{
F_197 () ;
F_55 ( V_238 ) ;
F_55 ( V_242 ) ;
F_55 ( V_211 ) ;
F_198 () ;
}
