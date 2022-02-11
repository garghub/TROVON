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
struct V_43 * F_25 ( T_2 V_44 )
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
if ( V_49 >= 0 ) {
F_33 ( & V_48 -> V_56 ) ;
V_48 -> V_57 = V_42 ;
V_48 -> V_58 = 0 ;
return 0 ;
}
return V_49 ;
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
F_54 ( V_17 ) ;
}
static void F_55 ( struct V_16 * V_17 )
{
F_49 ( V_17 , L_3 ) ;
F_56 ( & V_17 -> V_69 , F_46 ) ;
}
static void F_57 ( struct V_16 * V_17 )
{
F_49 ( V_17 , L_4 ) ;
F_58 ( & V_17 -> V_69 ) ;
}
static struct V_16 * F_59 ( struct V_74 * V_7 )
{
struct V_16 * V_17 , * V_49 = NULL ;
struct V_75 * V_75 = NULL ;
int V_60 = 0 ;
V_75 = F_60 ( V_76 ) ;
V_17 = F_61 ( sizeof( * V_17 ) , V_76 ) ;
if ( V_17 == NULL || V_75 == NULL )
goto V_63;
F_62 ( & V_17 -> V_69 ) ;
F_63 ( V_7 ) ;
V_17 -> V_72 = V_7 ;
V_60 = F_64 ( & V_7 -> V_73 ) ;
if ( V_60 ) {
F_65 ( V_60 ) ;
F_52 ( V_7 ) ;
goto V_63;
}
F_66 ( & V_17 -> V_77 , V_78 ) ;
F_66 ( & V_17 -> V_79 , V_80 ) ;
F_66 ( & V_17 -> V_81 , V_82 ) ;
F_67 ( & V_17 -> V_83 , V_84 ) ;
F_68 ( & V_17 -> V_70 ) ;
V_17 -> V_70 . V_85 = V_86 ;
V_17 -> V_70 . V_87 = ( unsigned long ) V_17 ;
F_49 ( V_17 , L_5 ) ;
V_49 = V_17 ;
V_17 -> V_88 = V_75 ;
F_69 ( V_17 ) ;
V_17 = NULL ;
V_75 = NULL ;
V_63:
if ( V_75 )
F_70 ( V_75 ) ;
F_54 ( V_17 ) ;
return V_49 ;
}
static void F_71 ( struct V_16 * V_17 ,
struct V_89 * V_90 )
{
F_57 ( V_17 ) ;
if ( ! F_72 ( V_91 , V_90 ) )
F_55 ( V_17 ) ;
}
static void F_73 ( struct V_16 * V_17 ,
struct V_92 * V_90 ,
int V_93 )
{
F_57 ( V_17 ) ;
if ( ! F_74 ( V_91 , V_90 , V_93 ) )
F_55 ( V_17 ) ;
}
static void F_75 ( struct V_16 * V_17 ,
struct V_92 * V_90 )
{
if ( F_76 ( V_90 ) )
F_55 ( V_17 ) ;
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
F_74 ( V_91 , & V_46 -> V_105 ,
F_83 ( V_106 ) ) ;
}
if ( V_96 && ! V_95 ) {
F_84 ( L_9 V_107 L_10 ,
V_100 -> V_72 -> V_108 , V_100 -> V_72 -> V_109 ,
& V_100 -> V_72 -> V_110 ,
F_85 ( V_100 -> V_72 -> V_111 ) ) ;
F_42 ( V_46 ) ;
}
if ( ! V_96 && V_95 ) {
F_76 ( & V_46 -> V_112 ) ;
F_84 ( L_11 V_107 L_10 ,
F_86 () > V_17 -> V_72 -> V_109 ?
L_12 : L_13 ,
V_17 -> V_72 -> V_108 , V_17 -> V_72 -> V_109 ,
& V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) ) ;
}
if ( ! V_95 && V_91 ) {
unsigned long V_93 ;
V_93 = ( V_46 -> V_113 +
F_83 ( F_20 () ) )
- V_114 ;
if ( V_93 > F_83 ( F_20 () ) )
V_93 = 0 ;
F_44 ( V_103 , L_14 , V_93 ) ;
F_74 ( V_91 , & V_46 -> V_115 , V_93 ) ;
V_93 += F_83 ( F_22 () ) ;
F_74 ( V_91 , & V_46 -> V_112 , V_93 ) ;
}
if ( ( V_100 == NULL ) && V_17 )
F_57 ( V_17 ) ;
if ( V_100 && ( V_100 != V_17 ) ) {
F_71 ( V_100 , & V_100 -> V_81 ) ;
F_55 ( V_100 ) ;
}
}
static void F_87 ( struct V_116 * V_117 , int V_118 )
{
void (* F_88)( struct V_116 * V_117 , int V_118 );
F_89 ( & V_117 -> V_119 ) ;
if ( V_117 -> V_120 ) {
struct V_16 * V_17 = V_117 -> V_120 ;
F_49 ( V_17 , L_15 ) ;
F_10 ( V_17 ) ;
F_71 ( V_17 , & V_17 -> V_79 ) ;
F_88 = V_17 -> V_121 ;
} else {
F_88 = V_117 -> V_122 ;
}
F_90 ( & V_117 -> V_119 ) ;
F_88 ( V_117 , V_118 ) ;
}
static void F_91 ( struct V_116 * V_117 )
{
void (* F_92)( struct V_116 * V_117 );
struct V_16 * V_17 ;
F_89 ( & V_117 -> V_119 ) ;
V_17 = V_117 -> V_120 ;
if ( V_17 == NULL ) {
F_92 = V_117 -> V_123 ;
goto V_63;
}
F_49 ( V_17 , L_16 , V_117 -> V_124 ) ;
F_92 = V_17 -> V_125 ;
switch ( V_117 -> V_124 ) {
case V_126 :
case V_127 :
break;
case V_128 :
F_71 ( V_17 , & V_17 -> V_77 ) ;
break;
default:
F_93 ( L_17
V_107 L_18 ,
V_17 -> V_72 -> V_108 , V_17 -> V_72 -> V_109 ,
& V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) , V_117 -> V_124 ) ;
F_71 ( V_17 , & V_17 -> V_81 ) ;
break;
}
V_63:
F_90 ( & V_117 -> V_119 ) ;
F_92 ( V_117 ) ;
}
static void F_94 ( struct V_116 * V_117 ,
struct V_16 * V_17 )
{
F_95 ( & V_117 -> V_119 ) ;
if ( V_117 -> V_122 == V_129 ) {
V_117 -> V_122 = V_117 -> V_120 ;
V_117 -> V_120 = NULL ;
}
F_24 ( V_117 -> V_120 != NULL ) ;
V_117 -> V_120 = V_17 ;
F_57 ( V_17 ) ;
V_17 -> V_121 = V_117 -> V_122 ;
V_17 -> V_125 = V_117 -> V_123 ;
V_117 -> V_122 = F_87 ;
V_117 -> V_123 = F_91 ;
F_96 ( & V_17 -> V_130 ) ;
F_97 ( & V_117 -> V_119 ) ;
}
static int F_98 ( struct V_116 * V_117 ,
struct V_16 * V_17 )
{
int V_49 = 0 ;
F_95 ( & V_117 -> V_119 ) ;
if ( V_117 -> V_120 == V_17 ) {
V_49 = 1 ;
V_117 -> V_120 = NULL ;
V_117 -> V_122 = V_17 -> V_121 ;
V_117 -> V_123 = V_17 -> V_125 ;
}
F_97 ( & V_117 -> V_119 ) ;
return V_49 ;
}
static void F_99 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
int V_38 )
{
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 == V_17 )
F_79 ( V_46 , NULL , 0 , V_38 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
static void V_82 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_81 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_109 ) ;
F_49 ( V_17 , L_19 ) ;
if ( F_98 ( V_17 -> V_71 -> V_117 , V_17 ) ) {
F_100 ( & V_17 -> V_70 ) ;
F_75 ( V_17 , & V_17 -> V_83 ) ;
F_55 ( V_17 ) ;
F_101 ( V_17 -> V_71 , V_131 ) ;
}
F_99 ( V_46 , V_17 , 0 ) ;
F_55 ( V_17 ) ;
}
static int F_102 ( struct V_132 * V_133 , T_1 V_134 ,
T_1 V_135 )
{
int V_49 = memcmp ( & V_133 -> V_136 , & V_135 , sizeof( V_135 ) ) ;
if ( V_49 == 0 )
V_49 = memcmp ( & V_133 -> V_137 , & V_134 , sizeof( V_134 ) ) ;
return V_49 ;
}
static struct V_132 *
F_103 ( T_1 V_134 , T_1 V_135 , struct V_138 * * * V_139 ,
struct V_138 * * V_140 )
{
struct V_138 * * V_141 = & V_142 . V_138 ;
struct V_138 * V_143 = NULL ;
struct V_132 * V_133 , * V_49 = NULL ;
int V_144 ;
while ( * V_141 ) {
V_143 = * V_141 ;
V_133 = F_104 ( V_143 , struct V_132 , V_145 ) ;
V_144 = F_102 ( V_133 , V_134 , V_135 ) ;
if ( V_144 < 0 )
V_141 = & ( * V_141 ) -> V_146 ;
else if ( V_144 > 0 )
V_141 = & ( * V_141 ) -> V_147 ;
else {
V_49 = V_133 ;
break;
}
}
if ( V_139 != NULL )
* V_139 = V_141 ;
if ( V_140 != NULL )
* V_140 = V_143 ;
return V_49 ;
}
static void F_105 ( struct V_68 * V_68 )
{
struct V_132 * V_133 ;
V_133 = F_47 ( V_68 , struct V_132 , V_148 ) ;
F_54 ( V_133 ) ;
}
static void F_106 ( struct V_132 * V_133 )
{
F_56 ( & V_133 -> V_148 , F_105 ) ;
}
int F_107 ( T_1 V_134 , T_1 V_135 , T_1 V_149 ,
T_6 * V_150 , void * V_87 ,
T_7 * V_151 ,
struct V_152 * V_153 )
{
struct V_132 * V_133 = NULL ;
struct V_138 * * V_141 , * V_143 ;
int V_49 = 0 ;
if ( V_149 > V_154 ) {
F_44 ( 0 , L_20 ,
V_149 ) ;
V_49 = - V_155 ;
goto V_63;
}
if ( ! V_134 ) {
F_44 ( 0 , L_21 , V_134 , V_150 ) ;
V_49 = - V_155 ;
goto V_63;
}
if ( ! V_150 ) {
F_44 ( 0 , L_22 ,
V_134 , V_150 ) ;
V_49 = - V_155 ;
goto V_63;
}
V_133 = F_61 ( sizeof( struct V_132 ) , V_76 ) ;
if ( V_133 == NULL ) {
V_49 = - V_156 ;
goto V_63;
}
V_133 -> V_157 = V_150 ;
V_133 -> V_158 = V_87 ;
V_133 -> V_159 = V_151 ;
V_133 -> V_137 = V_134 ;
V_133 -> V_160 = V_149 ;
V_133 -> V_136 = V_135 ;
F_62 ( & V_133 -> V_148 ) ;
F_2 ( & V_133 -> V_161 ) ;
F_108 ( & V_162 ) ;
if ( F_103 ( V_134 , V_135 , & V_141 , & V_143 ) )
V_49 = - V_163 ;
else {
F_109 ( & V_133 -> V_145 , V_143 , V_141 ) ;
F_110 ( & V_133 -> V_145 , & V_142 ) ;
F_31 ( & V_133 -> V_161 , V_153 ) ;
F_44 ( V_164 , L_23 ,
V_150 , V_134 , V_135 ) ;
F_82 ( F_103 ( V_134 , V_135 , & V_141 ,
& V_143 ) == NULL ,
L_24
L_25 , V_134 , V_135 ) ;
}
F_111 ( & V_162 ) ;
if ( V_49 )
goto V_63;
V_63:
if ( V_49 )
F_54 ( V_133 ) ;
return V_49 ;
}
void F_112 ( struct V_152 * V_165 )
{
struct V_132 * V_133 , * V_166 ;
F_108 ( & V_162 ) ;
F_43 (nmh, n, list, nh_unregister_item) {
F_44 ( V_164 , L_26 ,
V_133 -> V_157 , V_133 -> V_137 , V_133 -> V_136 ) ;
F_113 ( & V_133 -> V_145 , & V_142 ) ;
F_37 ( & V_133 -> V_161 ) ;
F_56 ( & V_133 -> V_148 , F_105 ) ;
}
F_111 ( & V_162 ) ;
}
static struct V_132 * F_114 ( T_1 V_134 , T_1 V_135 )
{
struct V_132 * V_133 ;
F_89 ( & V_162 ) ;
V_133 = F_103 ( V_134 , V_135 , NULL , NULL ) ;
if ( V_133 )
F_58 ( & V_133 -> V_148 ) ;
F_90 ( & V_162 ) ;
return V_133 ;
}
static int F_115 ( struct V_167 * V_116 , void * V_87 , T_8 V_168 )
{
int V_49 ;
T_9 V_169 ;
struct V_170 V_171 = {
. V_172 = V_168 ,
. V_173 = V_87 ,
} ;
struct V_174 V_175 = {
. V_176 = 1 ,
. V_177 = (struct V_178 * ) & V_171 ,
. V_179 = V_180 ,
} ;
V_169 = F_116 () ;
F_117 ( F_118 () ) ;
V_49 = F_119 ( V_116 , & V_175 , V_168 , V_175 . V_179 ) ;
F_117 ( V_169 ) ;
return V_49 ;
}
static int F_120 ( struct V_167 * V_116 , struct V_170 * V_171 ,
T_8 V_181 , T_8 V_182 )
{
int V_49 ;
T_9 V_169 ;
struct V_174 V_175 = {
. V_177 = (struct V_178 * ) V_171 ,
. V_176 = V_181 ,
} ;
if ( V_116 == NULL ) {
V_49 = - V_155 ;
goto V_63;
}
V_169 = F_116 () ;
F_117 ( F_118 () ) ;
V_49 = F_121 ( V_116 , & V_175 , V_182 ) ;
F_117 ( V_169 ) ;
if ( V_49 != V_182 ) {
F_44 ( V_183 , L_27 , V_49 ,
V_182 ) ;
if ( V_49 >= 0 )
V_49 = - V_184 ;
goto V_63;
}
V_49 = 0 ;
V_63:
if ( V_49 < 0 )
F_44 ( 0 , L_28 , V_49 ) ;
return V_49 ;
}
static void F_122 ( struct V_16 * V_17 ,
void * V_185 ,
T_8 V_186 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_109 ) ;
T_10 V_49 ;
while ( 1 ) {
F_123 ( & V_17 -> V_130 ) ;
V_49 = V_17 -> V_71 -> V_187 -> V_188 ( V_17 -> V_71 ,
F_124 ( V_185 ) ,
( long ) V_185 & ~ V_189 ,
V_186 , V_180 ) ;
F_125 ( & V_17 -> V_130 ) ;
if ( V_49 == V_186 )
break;
if ( V_49 == ( T_10 ) - V_190 ) {
F_44 ( 0 , L_29 V_107
L_30 , V_186 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 ,
& V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) ) ;
F_126 () ;
continue;
}
F_44 ( V_183 , L_29 V_107
L_31 , V_186 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 , & V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) , V_49 ) ;
F_99 ( V_46 , V_17 , 0 ) ;
break;
}
}
static void F_127 ( struct V_191 * V_175 , T_11 V_192 ,
T_11 V_134 , T_1 V_135 )
{
memset ( V_175 , 0 , sizeof( struct V_191 ) ) ;
V_175 -> V_193 = F_128 ( V_194 ) ;
V_175 -> V_192 = F_128 ( V_192 ) ;
V_175 -> V_134 = F_128 ( V_134 ) ;
V_175 -> V_59 = F_129 ( V_42 ) ;
V_175 -> V_60 = 0 ;
V_175 -> V_135 = F_129 ( V_135 ) ;
}
static int F_130 ( struct V_43 * V_46 ,
struct V_16 * * V_195 ,
int * error )
{
int V_49 = 0 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_99 ) {
V_49 = 1 ;
* V_195 = NULL ;
* error = V_46 -> V_99 ;
} else if ( V_46 -> V_97 ) {
F_58 ( & V_46 -> V_101 -> V_69 ) ;
V_49 = 1 ;
* V_195 = V_46 -> V_101 ;
* error = 0 ;
}
F_32 ( & V_46 -> V_50 ) ;
return V_49 ;
}
void F_131 ( unsigned long * V_196 , unsigned V_118 )
{
struct V_16 * V_17 ;
int V_7 , V_49 ;
F_24 ( V_118 < ( F_132 ( V_197 ) * sizeof( unsigned long ) ) ) ;
memset ( V_196 , 0 , V_118 ) ;
for ( V_7 = 0 ; V_7 < V_197 ; ++ V_7 ) {
F_130 ( F_25 ( V_7 ) , & V_17 , & V_49 ) ;
if ( ! V_49 ) {
F_133 ( V_7 , V_196 ) ;
F_55 ( V_17 ) ;
}
}
}
int F_134 ( T_1 V_134 , T_1 V_135 , struct V_170 * V_198 ,
T_8 V_199 , T_2 V_200 , int * V_60 )
{
int V_49 = 0 ;
struct V_191 * V_175 = NULL ;
T_8 V_181 , V_201 = 0 ;
struct V_170 * V_171 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 = F_25 ( V_200 ) ;
struct V_47 V_48 = {
. V_54 = F_135 ( V_48 . V_54 ) ,
} ;
struct V_1 V_2 ;
F_33 ( & V_48 . V_56 ) ;
F_1 ( & V_2 , V_134 , V_135 , V_202 , V_200 ) ;
if ( V_91 == NULL ) {
F_44 ( 0 , L_32 ) ;
V_49 = - V_203 ;
goto V_63;
}
if ( V_199 == 0 ) {
F_44 ( 0 , L_33 ) ;
V_49 = - V_155 ;
goto V_63;
}
V_201 = F_136 ( (struct V_178 * ) V_198 , V_199 ) ;
if ( V_201 > V_154 ) {
F_44 ( 0 , L_34 , V_201 ) ;
V_49 = - V_155 ;
goto V_63;
}
if ( V_200 == F_86 () ) {
V_49 = - V_204 ;
goto V_63;
}
F_137 ( & V_2 ) ;
F_3 ( & V_2 ) ;
F_138 ( V_46 -> V_104 , F_130 ( V_46 , & V_17 , & V_49 ) ) ;
if ( V_49 )
goto V_63;
F_7 ( & V_2 , V_17 ) ;
V_181 = V_199 + 1 ;
V_171 = F_139 ( sizeof( struct V_170 ) * V_181 , V_52 ) ;
if ( V_171 == NULL ) {
F_44 ( 0 , L_35 , V_181 ) ;
V_49 = - V_156 ;
goto V_63;
}
V_175 = F_139 ( sizeof( struct V_191 ) , V_52 ) ;
if ( ! V_175 ) {
F_44 ( 0 , L_36 ) ;
V_49 = - V_156 ;
goto V_63;
}
F_127 ( V_175 , V_201 , V_134 , V_135 ) ;
V_171 [ 0 ] . V_172 = sizeof( struct V_191 ) ;
V_171 [ 0 ] . V_173 = V_175 ;
memcpy ( & V_171 [ 1 ] , V_198 , V_199 * sizeof( struct V_170 ) ) ;
V_49 = F_28 ( V_46 , & V_48 ) ;
if ( V_49 )
goto V_63;
V_175 -> V_205 = F_129 ( V_48 . V_53 ) ;
F_8 ( & V_2 , V_48 . V_53 ) ;
F_5 ( & V_2 ) ;
F_123 ( & V_17 -> V_130 ) ;
V_49 = F_120 ( V_17 -> V_71 , V_171 , V_181 ,
sizeof( struct V_191 ) + V_201 ) ;
F_125 ( & V_17 -> V_130 ) ;
F_140 ( V_175 , L_37 , V_49 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_38 , V_49 ) ;
goto V_63;
}
F_6 ( & V_2 ) ;
F_138 ( V_48 . V_56 , F_45 ( V_46 , & V_48 ) ||
V_46 -> V_99 || ! V_46 -> V_97 ) ;
F_17 ( & V_2 , V_17 ) ;
V_49 = F_23 ( V_48 . V_57 ) ;
if ( V_60 && ! V_49 )
* V_60 = V_48 . V_58 ;
F_44 ( 0 , L_39 ,
V_49 , V_48 . V_58 ) ;
V_63:
F_141 ( & V_2 ) ;
if ( V_17 )
F_55 ( V_17 ) ;
F_54 ( V_171 ) ;
F_54 ( V_175 ) ;
F_40 ( V_46 , & V_48 , 0 , 0 , 0 ) ;
return V_49 ;
}
int F_142 ( T_1 V_134 , T_1 V_135 , void * V_87 , T_1 V_168 ,
T_2 V_200 , int * V_60 )
{
struct V_170 V_171 = {
. V_173 = V_87 ,
. V_172 = V_168 ,
} ;
return F_134 ( V_134 , V_135 , & V_171 , 1 ,
V_200 , V_60 ) ;
}
static int F_143 ( struct V_167 * V_116 , struct V_191 * V_206 ,
enum V_37 V_207 , int V_38 )
{
struct V_170 V_171 = {
. V_173 = V_206 ,
. V_172 = sizeof( struct V_191 ) ,
} ;
F_24 ( V_207 >= V_40 ) ;
V_206 -> V_59 = F_129 ( V_207 ) ;
V_206 -> V_60 = F_129 ( V_38 ) ;
V_206 -> V_193 = F_128 ( V_208 ) ;
V_206 -> V_192 = 0 ;
F_140 ( V_206 , L_40 , V_38 ) ;
return F_120 ( V_116 , & V_171 , 1 , sizeof( struct V_191 ) ) ;
}
static int F_144 ( struct V_16 * V_17 ,
struct V_191 * V_206 ,
void * V_87 , T_8 V_192 ,
enum V_37 V_207 , int V_38 )
{
struct V_170 V_171 [ 2 ] ;
int V_49 ;
V_171 [ 0 ] . V_173 = V_206 ;
V_171 [ 0 ] . V_172 = sizeof( struct V_191 ) ;
V_171 [ 1 ] . V_173 = V_87 ;
V_171 [ 1 ] . V_172 = V_192 ;
F_24 ( V_207 >= V_40 ) ;
V_206 -> V_59 = F_129 ( V_207 ) ;
V_206 -> V_60 = F_129 ( V_38 ) ;
V_206 -> V_193 = F_128 ( V_209 ) ;
V_206 -> V_192 = F_128 ( V_192 ) ;
F_140 ( V_206 , L_41 , V_38 ) ;
V_49 = F_120 ( V_17 -> V_71 , V_171 , 2 ,
sizeof( struct V_191 ) + V_192 ) ;
return V_49 ;
}
void F_145 ( struct V_191 * V_206 , T_11 V_3 , T_1 V_4 )
{
V_206 -> V_193 = F_128 ( V_209 ) ;
V_206 -> V_134 = F_128 ( V_3 ) ;
V_206 -> V_135 = F_129 ( V_4 ) ;
}
static int F_146 ( struct V_16 * V_17 ,
struct V_191 * V_206 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_109 ) ;
int V_49 = 0 , V_210 ;
enum V_37 V_207 ;
struct V_132 * V_133 = NULL ;
void * V_211 = NULL ;
int V_212 = 0 ;
F_140 ( V_206 , L_42 ) ;
F_147 ( V_17 ) ;
switch ( F_148 ( V_206 -> V_193 ) ) {
case V_208 :
F_40 ( V_46 , NULL , F_149 ( V_206 -> V_205 ) ,
F_149 ( V_206 -> V_59 ) ,
F_149 ( V_206 -> V_60 ) ) ;
goto V_63;
case V_213 :
F_122 ( V_17 , V_214 , sizeof( * V_214 ) ) ;
goto V_63;
case V_215 :
goto V_63;
case V_194 :
break;
case V_209 :
V_212 = 1 ;
break;
default:
F_140 ( V_206 , L_43 ) ;
V_49 = - V_155 ;
goto V_63;
break;
}
V_210 = 0 ;
V_133 = F_114 ( F_148 ( V_206 -> V_134 ) ,
F_149 ( V_206 -> V_135 ) ) ;
if ( ! V_133 ) {
F_44 ( V_164 , L_44 ,
F_148 ( V_206 -> V_134 ) , F_149 ( V_206 -> V_135 ) ) ;
V_207 = V_216 ;
goto V_217;
}
V_207 = V_42 ;
if ( F_148 ( V_206 -> V_192 ) > V_133 -> V_160 )
V_207 = V_218 ;
if ( V_207 != V_42 ) {
F_150 ( L_45 ) ;
goto V_217;
}
F_13 ( V_17 ) ;
V_17 -> V_219 = F_149 ( V_206 -> V_135 ) ;
V_17 -> V_220 = F_148 ( V_206 -> V_134 ) ;
V_210 = ( V_133 -> V_157 ) ( V_206 , sizeof( struct V_191 ) +
F_148 ( V_206 -> V_192 ) ,
V_133 -> V_158 , & V_211 ) ;
if ( V_212 ) {
F_40 ( V_46 , NULL , F_149 ( V_206 -> V_205 ) ,
F_149 ( V_206 -> V_59 ) , V_210 ) ;
goto V_63;
}
if ( F_148 ( V_206 -> V_193 ) == V_209 ) {
V_49 = F_144 ( V_17 , V_206 ,
V_211 , V_210 ,
V_207 , 0 ) ;
V_206 = NULL ;
F_44 ( 0 , L_46 ,
V_210 , V_207 , V_49 ) ;
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
goto V_63;
}
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
V_217:
F_123 ( & V_17 -> V_130 ) ;
V_49 = F_143 ( V_17 -> V_71 , V_206 , V_207 ,
V_210 ) ;
F_125 ( & V_17 -> V_130 ) ;
V_206 = NULL ;
F_44 ( 0 , L_47 ,
V_210 , V_207 , V_49 ) ;
if ( V_133 ) {
F_24 ( V_211 != NULL && V_133 -> V_159 == NULL ) ;
if ( V_133 -> V_159 )
( V_133 -> V_159 ) ( V_210 , V_133 -> V_158 ,
V_211 ) ;
}
V_63:
if ( V_133 )
F_106 ( V_133 ) ;
return V_49 ;
}
static int F_151 ( struct V_16 * V_17 )
{
struct V_221 * V_222 = F_152 ( V_17 -> V_88 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_109 ) ;
if ( V_222 -> V_223 != F_153 ( V_224 ) ) {
F_84 ( L_48 V_107 L_49
L_50
L_51 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 , & V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) ,
( unsigned long long ) F_154 ( V_222 -> V_223 ) ,
V_224 ) ;
F_99 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_149 ( V_222 -> V_225 ) !=
F_22 () ) {
F_84 ( L_48 V_107 L_52
L_53
L_51 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 , & V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) ,
F_149 ( V_222 -> V_225 ) ,
F_22 () ) ;
F_99 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_149 ( V_222 -> V_226 ) !=
F_21 () ) {
F_84 ( L_48 V_107 L_54
L_55
L_51 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 , & V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) ,
F_149 ( V_222 -> V_226 ) ,
F_21 () ) ;
F_99 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_149 ( V_222 -> V_227 ) !=
V_228 ) {
F_84 ( L_48 V_107 L_56
L_57
L_51 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 , & V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) ,
F_149 ( V_222 -> V_227 ) ,
V_228 ) ;
F_99 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
V_17 -> V_229 = 1 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 == V_17 ) {
F_155 ( V_17 ) ;
F_156 ( & V_46 -> V_230 , 0 ) ;
F_79 ( V_46 , V_17 , 1 , 0 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
V_17 -> V_231 -= sizeof( struct V_221 ) ;
if ( V_17 -> V_231 )
memmove ( V_222 , V_222 + 1 , V_17 -> V_231 ) ;
return 0 ;
}
static int F_157 ( struct V_16 * V_17 )
{
struct V_191 * V_206 ;
int V_49 = 0 ;
void * V_87 ;
T_8 V_232 ;
F_49 ( V_17 , L_58 ) ;
F_11 ( V_17 ) ;
if ( F_158 ( V_17 -> V_229 == 0 ) ) {
if ( V_17 -> V_231 < sizeof( struct V_221 ) ) {
V_87 = F_152 ( V_17 -> V_88 ) + V_17 -> V_231 ;
V_232 = sizeof( struct V_221 ) -
V_17 -> V_231 ;
V_49 = F_115 ( V_17 -> V_71 , V_87 , V_232 ) ;
if ( V_49 > 0 )
V_17 -> V_231 += V_49 ;
}
if ( V_17 -> V_231 == sizeof( struct V_221 ) ) {
F_151 ( V_17 ) ;
if ( F_158 ( V_17 -> V_229 == 0 ) )
V_49 = - V_233 ;
}
goto V_63;
}
if ( V_17 -> V_231 < sizeof( struct V_191 ) ) {
V_87 = F_152 ( V_17 -> V_88 ) + V_17 -> V_231 ;
V_232 = sizeof( struct V_191 ) - V_17 -> V_231 ;
V_49 = F_115 ( V_17 -> V_71 , V_87 , V_232 ) ;
if ( V_49 > 0 ) {
V_17 -> V_231 += V_49 ;
if ( V_17 -> V_231 == sizeof( struct V_191 ) ) {
V_206 = F_152 ( V_17 -> V_88 ) ;
if ( F_148 ( V_206 -> V_192 ) >
V_154 )
V_49 = - V_234 ;
F_159 ( V_49 == - V_234 ) ;
}
}
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_231 < sizeof( struct V_191 ) ) {
goto V_63;
}
V_206 = F_152 ( V_17 -> V_88 ) ;
F_140 ( V_206 , L_59 , V_17 -> V_231 ) ;
if ( V_17 -> V_231 - sizeof( struct V_191 ) <
F_148 ( V_206 -> V_192 ) ) {
V_87 = F_152 ( V_17 -> V_88 ) + V_17 -> V_231 ;
V_232 = ( sizeof( struct V_191 ) +
F_148 ( V_206 -> V_192 ) ) -
V_17 -> V_231 ;
V_49 = F_115 ( V_17 -> V_71 , V_87 , V_232 ) ;
if ( V_49 > 0 )
V_17 -> V_231 += V_49 ;
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_231 - sizeof( struct V_191 ) ==
F_148 ( V_206 -> V_192 ) ) {
V_49 = F_146 ( V_17 , V_206 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_17 -> V_231 = 0 ;
}
V_63:
F_49 ( V_17 , L_60 , V_49 ) ;
F_12 ( V_17 ) ;
return V_49 ;
}
static void V_80 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 , V_79 ) ;
int V_49 ;
do {
V_49 = F_157 ( V_17 ) ;
} while ( V_49 > 0 );
if ( V_49 <= 0 && V_49 != - V_190 ) {
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_109 ) ;
F_49 ( V_17 , L_61 , V_49 ) ;
F_99 ( V_46 , V_17 , 0 ) ;
}
F_55 ( V_17 ) ;
}
static int F_160 ( struct V_167 * V_116 )
{
int V_49 , V_235 = 1 ;
T_9 V_169 ;
V_169 = F_116 () ;
F_117 ( V_236 ) ;
V_49 = V_116 -> V_187 -> V_237 ( V_116 , V_238 , V_239 ,
( char V_240 * ) & V_235 , sizeof( V_235 ) ) ;
F_117 ( V_169 ) ;
return V_49 ;
}
static void F_161 ( void )
{
V_241 -> V_227 = F_129 (
V_228 ) ;
V_241 -> V_225 = F_129 ( F_22 () ) ;
V_241 -> V_226 = F_129 (
F_21 () ) ;
V_241 -> V_242 = F_129 (
F_20 () ) ;
}
static void V_78 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_77 ) ;
F_44 ( V_243 , L_62 ,
( unsigned long long ) V_224 ,
( unsigned long long ) F_154 ( V_241 -> V_244 ) ) ;
F_161 () ;
F_122 ( V_17 , V_241 , sizeof( * V_241 ) ) ;
F_55 ( V_17 ) ;
}
static void V_84 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_83 . V_90 ) ;
F_122 ( V_17 , V_245 , sizeof( * V_245 ) ) ;
F_55 ( V_17 ) ;
}
static void V_86 ( unsigned long V_87 )
{
struct V_16 * V_17 = (struct V_16 * ) V_87 ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_109 ) ;
#ifdef F_162
unsigned long V_246 = F_163 ( F_4 () ) -
F_163 ( V_17 -> V_21 ) ;
#else
unsigned long V_246 = F_22 () ;
#endif
F_84 ( L_17 V_107 L_63
L_64 ,
V_17 -> V_72 -> V_108 , V_17 -> V_72 -> V_109 ,
& V_17 -> V_72 -> V_110 , F_85 ( V_17 -> V_72 -> V_111 ) ,
V_246 / 1000 , V_246 % 1000 ) ;
F_156 ( & V_46 -> V_230 , 1 ) ;
F_71 ( V_17 , & V_17 -> V_81 ) ;
}
static void F_155 ( struct V_16 * V_17 )
{
F_75 ( V_17 , & V_17 -> V_83 ) ;
F_73 ( V_17 , & V_17 -> V_83 ,
F_83 ( F_21 () ) ) ;
F_9 ( V_17 ) ;
F_164 ( & V_17 -> V_70 ,
V_114 + F_83 ( F_22 () ) ) ;
}
static void F_147 ( struct V_16 * V_17 )
{
if ( F_48 ( & V_17 -> V_70 ) )
F_155 ( V_17 ) ;
}
static void F_165 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_115 . V_90 ) ;
struct V_16 * V_17 = NULL ;
struct V_74 * V_7 = NULL , * V_247 = NULL ;
struct V_167 * V_116 = NULL ;
struct V_248 V_249 = { 0 , } , V_250 = { 0 , } ;
int V_49 = 0 , V_251 ;
unsigned int V_252 ;
if ( F_86 () <= F_27 ( V_46 ) )
goto V_63;
V_7 = F_166 ( F_27 ( V_46 ) ) ;
if ( V_7 == NULL ) {
V_49 = 0 ;
goto V_63;
}
V_247 = F_166 ( F_86 () ) ;
if ( V_247 == NULL ) {
V_49 = 0 ;
goto V_63;
}
F_29 ( & V_46 -> V_50 ) ;
V_252 = F_78 ( & V_46 -> V_230 ) ;
V_251 = ( V_46 -> V_101 ||
( V_46 -> V_99 &&
( V_46 -> V_99 != - V_102 || V_252 == 0 ) ) ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_251 )
goto V_63;
V_46 -> V_113 = V_114 ;
V_17 = F_59 ( V_7 ) ;
if ( V_17 == NULL ) {
F_44 ( 0 , L_65 ) ;
V_49 = - V_156 ;
goto V_63;
}
V_49 = F_167 ( V_253 , V_254 , V_255 , & V_116 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_66 , V_49 ) ;
goto V_63;
}
V_17 -> V_71 = V_116 ;
V_116 -> V_117 -> V_256 = V_52 ;
V_249 . V_257 = V_258 ;
V_249 . V_259 . V_260 = V_247 -> V_110 ;
V_249 . V_261 = F_168 ( 0 ) ;
V_49 = V_116 -> V_187 -> V_262 ( V_116 , (struct V_263 * ) & V_249 ,
sizeof( V_249 ) ) ;
if ( V_49 ) {
F_44 ( V_183 , L_67 ,
V_49 , & V_247 -> V_110 ) ;
goto V_63;
}
V_49 = F_160 ( V_17 -> V_71 ) ;
if ( V_49 ) {
F_44 ( V_183 , L_68 , V_49 ) ;
goto V_63;
}
F_94 ( V_17 -> V_71 -> V_117 , V_17 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
V_250 . V_257 = V_258 ;
V_250 . V_259 . V_260 = V_7 -> V_110 ;
V_250 . V_261 = V_7 -> V_111 ;
V_49 = V_17 -> V_71 -> V_187 -> V_264 ( V_17 -> V_71 ,
(struct V_263 * ) & V_250 ,
sizeof( V_250 ) ,
V_265 ) ;
if ( V_49 == - V_266 )
V_49 = 0 ;
V_63:
if ( V_49 ) {
F_84 ( L_69 V_107
L_70 , V_17 -> V_72 -> V_108 ,
V_17 -> V_72 -> V_109 , & V_17 -> V_72 -> V_110 ,
F_85 ( V_17 -> V_72 -> V_111 ) , V_49 ) ;
if ( V_17 )
F_99 ( V_46 , V_17 , 0 ) ;
}
if ( V_17 )
F_55 ( V_17 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_247 )
F_52 ( V_247 ) ;
return;
}
static void F_169 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_112 . V_90 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( ! V_46 -> V_97 ) {
F_84 ( L_71
L_72 ,
F_27 ( V_46 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
F_79 ( V_46 , NULL , 0 , - V_102 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
}
static void F_170 ( struct V_89 * V_90 )
{
}
void F_171 ( struct V_74 * V_7 )
{
struct V_43 * V_46 = F_25 ( V_7 -> V_109 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_156 ( & V_46 -> V_230 , 0 ) ;
F_79 ( V_46 , NULL , 0 , - V_102 ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_91 ) {
F_76 ( & V_46 -> V_112 ) ;
F_76 ( & V_46 -> V_115 ) ;
F_76 ( & V_46 -> V_105 ) ;
F_172 ( V_91 ) ;
}
}
static void F_173 ( struct V_74 * V_7 , int V_44 ,
void * V_87 )
{
if ( ! V_7 )
return;
if ( V_44 != F_86 () )
F_171 ( V_7 ) ;
F_24 ( F_78 ( & V_94 ) < 0 ) ;
}
static void F_174 ( struct V_74 * V_7 , int V_44 ,
void * V_87 )
{
struct V_43 * V_46 = F_25 ( V_44 ) ;
F_24 ( ! V_7 ) ;
V_46 -> V_113 = V_114 -
( F_83 ( F_20 () ) + 1 ) ;
if ( V_44 != F_86 () ) {
F_29 ( & V_46 -> V_50 ) ;
F_156 ( & V_46 -> V_230 , 0 ) ;
if ( V_46 -> V_99 )
F_79 ( V_46 , NULL , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
}
void F_175 ( void )
{
F_176 ( NULL , & V_267 ) ;
F_176 ( NULL , & V_268 ) ;
}
int F_177 ( void )
{
int V_49 ;
F_178 ( & V_268 , V_269 ,
F_173 , NULL , V_270 ) ;
F_178 ( & V_267 , V_271 ,
F_174 , NULL , V_270 ) ;
V_49 = F_179 ( NULL , & V_267 ) ;
if ( V_49 == 0 )
V_49 = F_179 ( NULL , & V_268 ) ;
if ( V_49 )
F_175 () ;
return V_49 ;
}
static int F_180 ( struct V_167 * V_116 )
{
int V_49 , V_272 ;
struct V_248 sin ;
struct V_167 * V_273 = NULL ;
struct V_74 * V_7 = NULL ;
struct V_74 * V_274 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 ;
F_24 ( V_116 == NULL ) ;
V_49 = F_181 ( V_116 -> V_117 -> V_275 , V_116 -> V_117 -> V_276 ,
V_116 -> V_117 -> V_277 , & V_273 ) ;
if ( V_49 )
goto V_63;
V_273 -> type = V_116 -> type ;
V_273 -> V_187 = V_116 -> V_187 ;
V_49 = V_116 -> V_187 -> V_278 ( V_116 , V_273 , V_265 ) ;
if ( V_49 < 0 )
goto V_63;
V_273 -> V_117 -> V_256 = V_52 ;
V_49 = F_160 ( V_273 ) ;
if ( V_49 ) {
F_44 ( V_183 , L_68 , V_49 ) ;
goto V_63;
}
V_272 = sizeof( sin ) ;
V_49 = V_273 -> V_187 -> V_279 ( V_273 , (struct V_263 * ) & sin ,
& V_272 , 1 ) ;
if ( V_49 < 0 )
goto V_63;
V_7 = F_182 ( sin . V_259 . V_260 ) ;
if ( V_7 == NULL ) {
F_84 ( L_73
L_74 , & sin . V_259 . V_260 ,
F_85 ( sin . V_261 ) ) ;
V_49 = - V_155 ;
goto V_63;
}
if ( F_86 () >= V_7 -> V_109 ) {
V_274 = F_166 ( F_86 () ) ;
F_84 ( L_75
L_76
L_77 , V_274 -> V_108 , V_274 -> V_109 ,
& ( V_274 -> V_110 ) ,
F_85 ( V_274 -> V_111 ) , V_7 -> V_108 ,
V_7 -> V_109 , & sin . V_259 . V_260 , F_85 ( sin . V_261 ) ) ;
V_49 = - V_155 ;
goto V_63;
}
if ( ! F_183 ( V_7 -> V_109 ) ) {
F_44 ( V_103 , L_78
L_79 ,
V_7 -> V_108 , & sin . V_259 . V_260 ,
F_85 ( sin . V_261 ) ) ;
V_49 = - V_155 ;
goto V_63;
}
V_46 = F_25 ( V_7 -> V_109 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 )
V_49 = - V_280 ;
else
V_49 = 0 ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_49 ) {
F_84 ( L_80
L_81 ,
V_7 -> V_108 , & sin . V_259 . V_260 ,
F_85 ( sin . V_261 ) ) ;
goto V_63;
}
V_17 = F_59 ( V_7 ) ;
if ( V_17 == NULL ) {
V_49 = - V_156 ;
goto V_63;
}
V_17 -> V_71 = V_273 ;
V_273 = NULL ;
F_29 ( & V_46 -> V_50 ) ;
F_156 ( & V_46 -> V_230 , 0 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
F_94 ( V_17 -> V_71 -> V_117 , V_17 ) ;
F_71 ( V_17 , & V_17 -> V_79 ) ;
F_161 () ;
F_122 ( V_17 , V_241 , sizeof( * V_241 ) ) ;
V_63:
if ( V_273 )
F_50 ( V_273 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_274 )
F_52 ( V_274 ) ;
if ( V_17 )
F_55 ( V_17 ) ;
return V_49 ;
}
static void F_184 ( struct V_89 * V_90 )
{
struct V_167 * V_116 = V_281 ;
while ( F_180 ( V_116 ) == 0 )
F_126 () ;
}
static void V_129 ( struct V_116 * V_117 , int V_118 )
{
void (* F_88)( struct V_116 * V_117 , int V_118 );
F_89 ( & V_117 -> V_119 ) ;
F_88 = V_117 -> V_120 ;
if ( F_88 == NULL ) {
F_88 = V_117 -> V_122 ;
goto V_63;
}
if ( V_117 -> V_124 == V_282 ) {
F_44 ( V_164 , L_82 , V_118 ) ;
F_72 ( V_91 , & V_283 ) ;
}
V_63:
F_90 ( & V_117 -> V_119 ) ;
F_88 ( V_117 , V_118 ) ;
}
static int F_185 ( T_12 V_284 , T_13 V_285 )
{
struct V_167 * V_116 = NULL ;
int V_49 ;
struct V_248 sin = {
. V_257 = V_253 ,
. V_259 = { . V_260 = V_284 } ,
. V_261 = V_285 ,
} ;
V_49 = F_167 ( V_253 , V_254 , V_255 , & V_116 ) ;
if ( V_49 < 0 ) {
F_150 ( L_83 , V_49 ) ;
goto V_63;
}
V_116 -> V_117 -> V_256 = V_52 ;
F_95 ( & V_116 -> V_117 -> V_119 ) ;
V_116 -> V_117 -> V_120 = V_116 -> V_117 -> V_122 ;
V_116 -> V_117 -> V_122 = V_129 ;
F_97 ( & V_116 -> V_117 -> V_119 ) ;
V_281 = V_116 ;
F_66 ( & V_283 , F_184 ) ;
V_116 -> V_117 -> V_286 = 1 ;
V_49 = V_116 -> V_187 -> V_262 ( V_116 , (struct V_263 * ) & sin , sizeof( sin ) ) ;
if ( V_49 < 0 ) {
F_150 ( L_84 ,
V_49 , & V_284 , F_85 ( V_285 ) ) ;
goto V_63;
}
V_49 = V_116 -> V_187 -> V_287 ( V_116 , 64 ) ;
if ( V_49 < 0 )
F_150 ( L_85 ,
V_49 , & V_284 , F_85 ( V_285 ) ) ;
V_63:
if ( V_49 ) {
V_281 = NULL ;
if ( V_116 )
F_50 ( V_116 ) ;
}
return V_49 ;
}
int F_186 ( struct V_74 * V_7 )
{
int V_49 = 0 ;
F_24 ( V_91 != NULL ) ;
F_24 ( V_281 != NULL ) ;
F_44 ( V_288 , L_86 ) ;
V_91 = F_187 ( L_87 ) ;
if ( V_91 == NULL ) {
F_44 ( V_183 , L_88 ) ;
return - V_156 ;
}
V_49 = F_185 ( V_7 -> V_110 ,
V_7 -> V_111 ) ;
if ( V_49 ) {
F_188 ( V_91 ) ;
V_91 = NULL ;
}
return V_49 ;
}
void F_189 ( struct V_74 * V_7 )
{
struct V_167 * V_116 = V_281 ;
T_8 V_289 ;
F_24 ( V_91 == NULL ) ;
F_24 ( V_281 == NULL ) ;
F_95 ( & V_116 -> V_117 -> V_119 ) ;
V_116 -> V_117 -> V_122 = V_116 -> V_117 -> V_120 ;
V_116 -> V_117 -> V_120 = NULL ;
F_97 ( & V_116 -> V_117 -> V_119 ) ;
for ( V_289 = 0 ; V_289 < F_26 ( V_45 ) ; V_289 ++ ) {
struct V_74 * V_7 = F_166 ( V_289 ) ;
if ( V_7 ) {
F_171 ( V_7 ) ;
F_52 ( V_7 ) ;
}
}
F_44 ( V_288 , L_89 ) ;
F_188 ( V_91 ) ;
V_91 = NULL ;
F_50 ( V_281 ) ;
V_281 = NULL ;
}
void F_190 ( int V_44 )
{
struct V_74 V_290 ;
if ( V_33 == NULL )
F_150 ( L_90 ) ;
else {
F_191 ( V_44 ) ;
F_174 ( & V_290 , V_44 , NULL ) ;
}
}
int F_192 ( void )
{
unsigned long V_289 ;
if ( F_193 () )
return - V_156 ;
V_241 = F_61 ( sizeof( struct V_221 ) , V_291 ) ;
V_245 = F_61 ( sizeof( struct V_191 ) , V_291 ) ;
V_214 = F_61 ( sizeof( struct V_191 ) , V_291 ) ;
if ( ! V_241 || ! V_245 || ! V_214 ) {
F_54 ( V_241 ) ;
F_54 ( V_245 ) ;
F_54 ( V_214 ) ;
return - V_156 ;
}
V_241 -> V_223 = F_153 ( V_224 ) ;
V_241 -> V_244 = F_153 ( 1 ) ;
V_245 -> V_193 = F_128 ( V_213 ) ;
V_214 -> V_193 = F_128 ( V_215 ) ;
for ( V_289 = 0 ; V_289 < F_26 ( V_45 ) ; V_289 ++ ) {
struct V_43 * V_46 = F_25 ( V_289 ) ;
F_156 ( & V_46 -> V_230 , 0 ) ;
F_194 ( & V_46 -> V_50 ) ;
F_67 ( & V_46 -> V_115 , F_165 ) ;
F_67 ( & V_46 -> V_112 ,
F_169 ) ;
F_67 ( & V_46 -> V_105 , F_170 ) ;
V_46 -> V_99 = - V_102 ;
F_33 ( & V_46 -> V_104 ) ;
F_195 ( & V_46 -> V_51 ) ;
F_2 ( & V_46 -> V_55 ) ;
}
return 0 ;
}
void F_196 ( void )
{
F_54 ( V_241 ) ;
F_54 ( V_245 ) ;
F_54 ( V_214 ) ;
F_197 () ;
}
