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
static inline unsigned int F_20 ( void )
{
return V_33 -> V_34 ;
}
static inline unsigned int F_21 ( void )
{
return V_33 -> V_35 ;
}
static inline unsigned int F_22 ( void )
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
if ( V_96 && ! V_98 && V_46 -> V_99 ) {
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
static void F_89 ( struct V_114 * V_115 )
{
void (* F_90)( struct V_114 * V_115 );
struct V_16 * V_17 ;
F_91 ( & V_115 -> V_116 ) ;
V_17 = V_115 -> V_117 ;
if ( V_17 ) {
F_49 ( V_17 , L_15 ) ;
F_10 ( V_17 ) ;
F_71 ( V_17 , & V_17 -> V_80 ) ;
F_90 = V_17 -> V_118 ;
} else {
F_90 = V_115 -> V_119 ;
}
F_92 ( & V_115 -> V_116 ) ;
F_90 ( V_115 ) ;
}
static void F_93 ( struct V_114 * V_115 )
{
void (* F_94)( struct V_114 * V_115 );
struct V_16 * V_17 ;
F_91 ( & V_115 -> V_116 ) ;
V_17 = V_115 -> V_117 ;
if ( V_17 == NULL ) {
F_94 = V_115 -> V_120 ;
goto V_63;
}
F_49 ( V_17 , L_16 , V_115 -> V_121 ) ;
F_94 = V_17 -> V_122 ;
switch( V_115 -> V_121 ) {
case V_123 :
case V_124 :
break;
case V_125 :
F_71 ( V_17 , & V_17 -> V_78 ) ;
break;
default:
F_85 ( V_126 L_17 V_108
L_18 ,
F_86 ( V_17 ) , V_115 -> V_121 ) ;
F_71 ( V_17 , & V_17 -> V_82 ) ;
break;
}
V_63:
F_92 ( & V_115 -> V_116 ) ;
F_94 ( V_115 ) ;
}
static void F_95 ( struct V_114 * V_115 ,
struct V_16 * V_17 )
{
F_96 ( & V_115 -> V_116 ) ;
if ( V_115 -> V_119 == V_127 ) {
V_115 -> V_119 = V_115 -> V_117 ;
V_115 -> V_117 = NULL ;
}
F_24 ( V_115 -> V_117 != NULL ) ;
V_115 -> V_117 = V_17 ;
F_58 ( V_17 ) ;
V_17 -> V_118 = V_115 -> V_119 ;
V_17 -> V_122 = V_115 -> V_120 ;
V_115 -> V_119 = F_89 ;
V_115 -> V_120 = F_93 ;
F_97 ( & V_17 -> V_128 ) ;
F_98 ( & V_115 -> V_116 ) ;
}
static int F_99 ( struct V_114 * V_115 ,
struct V_16 * V_17 )
{
int V_49 = 0 ;
F_96 ( & V_115 -> V_116 ) ;
if ( V_115 -> V_117 == V_17 ) {
V_49 = 1 ;
V_115 -> V_117 = NULL ;
V_115 -> V_119 = V_17 -> V_118 ;
V_115 -> V_120 = V_17 -> V_122 ;
}
F_98 ( & V_115 -> V_116 ) ;
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
F_102 ( V_17 -> V_71 , V_129 ) ;
}
F_100 ( V_46 , V_17 , 0 ) ;
F_56 ( V_17 ) ;
}
static int F_103 ( struct V_130 * V_131 , T_1 V_132 ,
T_1 V_133 )
{
int V_49 = memcmp ( & V_131 -> V_134 , & V_133 , sizeof( V_133 ) ) ;
if ( V_49 == 0 )
V_49 = memcmp ( & V_131 -> V_135 , & V_132 , sizeof( V_132 ) ) ;
return V_49 ;
}
static struct V_130 *
F_104 ( T_1 V_132 , T_1 V_133 , struct V_136 * * * V_137 ,
struct V_136 * * V_138 )
{
struct V_136 * * V_139 = & V_140 . V_136 ;
struct V_136 * V_141 = NULL ;
struct V_130 * V_131 , * V_49 = NULL ;
int V_142 ;
while ( * V_139 ) {
V_141 = * V_139 ;
V_131 = F_105 ( V_141 , struct V_130 , V_143 ) ;
V_142 = F_103 ( V_131 , V_132 , V_133 ) ;
if ( V_142 < 0 )
V_139 = & ( * V_139 ) -> V_144 ;
else if ( V_142 > 0 )
V_139 = & ( * V_139 ) -> V_145 ;
else {
V_49 = V_131 ;
break;
}
}
if ( V_137 != NULL )
* V_137 = V_139 ;
if ( V_138 != NULL )
* V_138 = V_141 ;
return V_49 ;
}
static void F_106 ( struct V_68 * V_68 )
{
struct V_130 * V_131 ;
V_131 = F_47 ( V_68 , struct V_130 , V_146 ) ;
F_55 ( V_131 ) ;
}
static void F_107 ( struct V_130 * V_131 )
{
F_57 ( & V_131 -> V_146 , F_106 ) ;
}
int F_108 ( T_1 V_132 , T_1 V_133 , T_1 V_147 ,
T_6 * V_148 , void * V_88 ,
T_7 * V_149 ,
struct V_150 * V_151 )
{
struct V_130 * V_131 = NULL ;
struct V_136 * * V_139 , * V_141 ;
int V_49 = 0 ;
if ( V_147 > V_152 ) {
F_44 ( 0 , L_20 ,
V_147 ) ;
V_49 = - V_153 ;
goto V_63;
}
if ( ! V_132 ) {
F_44 ( 0 , L_21 , V_132 , V_148 ) ;
V_49 = - V_153 ;
goto V_63;
}
if ( ! V_148 ) {
F_44 ( 0 , L_22 ,
V_132 , V_148 ) ;
V_49 = - V_153 ;
goto V_63;
}
V_131 = F_62 ( sizeof( struct V_130 ) , V_77 ) ;
if ( V_131 == NULL ) {
V_49 = - V_154 ;
goto V_63;
}
V_131 -> V_155 = V_148 ;
V_131 -> V_156 = V_88 ;
V_131 -> V_157 = V_149 ;
V_131 -> V_135 = V_132 ;
V_131 -> V_158 = V_147 ;
V_131 -> V_134 = V_133 ;
F_63 ( & V_131 -> V_146 ) ;
F_2 ( & V_131 -> V_159 ) ;
F_109 ( & V_160 ) ;
if ( F_104 ( V_132 , V_133 , & V_139 , & V_141 ) )
V_49 = - V_161 ;
else {
F_110 ( & V_131 -> V_143 , V_141 , V_139 ) ;
F_111 ( & V_131 -> V_143 , & V_140 ) ;
F_31 ( & V_131 -> V_159 , V_151 ) ;
F_44 ( V_162 , L_23 ,
V_148 , V_132 , V_133 ) ;
F_82 ( F_104 ( V_132 , V_133 , & V_139 ,
& V_141 ) == NULL ,
L_24
L_25 , V_132 , V_133 ) ;
}
F_112 ( & V_160 ) ;
if ( V_49 )
goto V_63;
V_63:
if ( V_49 )
F_55 ( V_131 ) ;
return V_49 ;
}
void F_113 ( struct V_150 * V_163 )
{
struct V_130 * V_131 , * V_164 ;
F_109 ( & V_160 ) ;
F_43 (nmh, n, list, nh_unregister_item) {
F_44 ( V_162 , L_26 ,
V_131 -> V_155 , V_131 -> V_135 , V_131 -> V_134 ) ;
F_114 ( & V_131 -> V_143 , & V_140 ) ;
F_37 ( & V_131 -> V_159 ) ;
F_57 ( & V_131 -> V_146 , F_106 ) ;
}
F_112 ( & V_160 ) ;
}
static struct V_130 * F_115 ( T_1 V_132 , T_1 V_133 )
{
struct V_130 * V_131 ;
F_116 ( & V_160 ) ;
V_131 = F_104 ( V_132 , V_133 , NULL , NULL ) ;
if ( V_131 )
F_59 ( & V_131 -> V_146 ) ;
F_117 ( & V_160 ) ;
return V_131 ;
}
static int F_118 ( struct V_165 * V_114 , void * V_88 , T_8 V_166 )
{
struct V_167 V_168 = { . V_169 = V_166 , . V_170 = V_88 , } ;
struct V_171 V_172 = { . V_173 = V_174 , } ;
return F_119 ( V_114 , & V_172 , & V_168 , 1 , V_166 , V_172 . V_173 ) ;
}
static int F_120 ( struct V_165 * V_114 , struct V_167 * V_168 ,
T_8 V_175 , T_8 V_176 )
{
int V_49 ;
struct V_171 V_172 = { . V_173 = 0 ,} ;
if ( V_114 == NULL ) {
V_49 = - V_153 ;
goto V_63;
}
V_49 = F_121 ( V_114 , & V_172 , V_168 , V_175 , V_176 ) ;
if ( F_122 ( V_49 == V_176 ) )
return 0 ;
F_44 ( V_177 , L_27 , V_49 , V_176 ) ;
if ( V_49 >= 0 )
V_49 = - V_178 ;
V_63:
F_44 ( 0 , L_28 , V_49 ) ;
return V_49 ;
}
static void F_123 ( struct V_16 * V_17 ,
void * V_179 ,
T_8 V_180 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
T_9 V_49 ;
while ( 1 ) {
F_124 ( & V_17 -> V_128 ) ;
V_49 = V_17 -> V_71 -> V_181 -> V_182 ( V_17 -> V_71 ,
F_125 ( V_179 ) ,
( long ) V_179 & ~ V_183 ,
V_180 , V_174 ) ;
F_126 ( & V_17 -> V_128 ) ;
if ( V_49 == V_180 )
break;
if ( V_49 == ( T_9 ) - V_184 ) {
F_44 ( 0 , L_29 V_108
L_30 , V_180 , F_86 ( V_17 ) ) ;
F_127 () ;
continue;
}
F_44 ( V_177 , L_29 V_108
L_31 , V_180 , F_86 ( V_17 ) , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
break;
}
}
static void F_128 ( struct V_185 * V_172 , T_10 V_186 , T_10 V_132 , T_1 V_133 )
{
memset ( V_172 , 0 , sizeof( struct V_185 ) ) ;
V_172 -> V_187 = F_129 ( V_188 ) ;
V_172 -> V_186 = F_129 ( V_186 ) ;
V_172 -> V_132 = F_129 ( V_132 ) ;
V_172 -> V_59 = F_130 ( V_42 ) ;
V_172 -> V_60 = 0 ;
V_172 -> V_133 = F_130 ( V_133 ) ;
}
static int F_131 ( struct V_43 * V_46 ,
struct V_16 * * V_189 ,
int * error )
{
int V_49 = 0 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_99 ) {
V_49 = 1 ;
* V_189 = NULL ;
* error = V_46 -> V_99 ;
} else if ( V_46 -> V_97 ) {
F_59 ( & V_46 -> V_101 -> V_69 ) ;
V_49 = 1 ;
* V_189 = V_46 -> V_101 ;
* error = 0 ;
}
F_32 ( & V_46 -> V_50 ) ;
return V_49 ;
}
void F_132 ( unsigned long * V_190 , unsigned V_191 )
{
struct V_16 * V_17 ;
int V_7 , V_49 ;
F_24 ( V_191 < ( F_133 ( V_192 ) * sizeof( unsigned long ) ) ) ;
memset ( V_190 , 0 , V_191 ) ;
for ( V_7 = 0 ; V_7 < V_192 ; ++ V_7 ) {
if ( ! F_131 ( F_25 ( V_7 ) , & V_17 , & V_49 ) )
continue;
if ( ! V_49 ) {
F_134 ( V_7 , V_190 ) ;
F_56 ( V_17 ) ;
}
}
}
int F_135 ( T_1 V_132 , T_1 V_133 , struct V_167 * V_193 ,
T_8 V_194 , T_2 V_195 , int * V_60 )
{
int V_49 = 0 ;
struct V_185 * V_172 = NULL ;
T_8 V_175 , V_196 = 0 ;
struct V_167 * V_168 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 = F_25 ( V_195 ) ;
struct V_47 V_48 = {
. V_54 = F_136 ( V_48 . V_54 ) ,
} ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_132 , V_133 , V_197 , V_195 ) ;
if ( V_91 == NULL ) {
F_44 ( 0 , L_32 ) ;
V_49 = - V_198 ;
goto V_63;
}
if ( V_194 == 0 ) {
F_44 ( 0 , L_33 ) ;
V_49 = - V_153 ;
goto V_63;
}
V_196 = F_137 ( (struct V_199 * ) V_193 , V_194 ) ;
if ( V_196 > V_152 ) {
F_44 ( 0 , L_34 , V_196 ) ;
V_49 = - V_153 ;
goto V_63;
}
if ( V_195 == F_88 () ) {
V_49 = - V_200 ;
goto V_63;
}
F_138 ( & V_2 ) ;
F_3 ( & V_2 ) ;
F_139 ( V_46 -> V_104 , F_131 ( V_46 , & V_17 , & V_49 ) ) ;
if ( V_49 )
goto V_63;
F_7 ( & V_2 , V_17 ) ;
V_175 = V_194 + 1 ;
V_168 = F_140 ( sizeof( struct V_167 ) * V_175 , V_52 ) ;
if ( V_168 == NULL ) {
F_44 ( 0 , L_35 , V_175 ) ;
V_49 = - V_154 ;
goto V_63;
}
V_172 = F_140 ( sizeof( struct V_185 ) , V_52 ) ;
if ( ! V_172 ) {
F_44 ( 0 , L_36 ) ;
V_49 = - V_154 ;
goto V_63;
}
F_128 ( V_172 , V_196 , V_132 , V_133 ) ;
V_168 [ 0 ] . V_169 = sizeof( struct V_185 ) ;
V_168 [ 0 ] . V_170 = V_172 ;
memcpy ( & V_168 [ 1 ] , V_193 , V_194 * sizeof( struct V_167 ) ) ;
V_49 = F_28 ( V_46 , & V_48 ) ;
if ( V_49 )
goto V_63;
V_172 -> V_201 = F_130 ( V_48 . V_53 ) ;
F_8 ( & V_2 , V_48 . V_53 ) ;
F_5 ( & V_2 ) ;
F_124 ( & V_17 -> V_128 ) ;
V_49 = F_120 ( V_17 -> V_71 , V_168 , V_175 ,
sizeof( struct V_185 ) + V_196 ) ;
F_126 ( & V_17 -> V_128 ) ;
F_141 ( V_172 , L_37 , V_49 ) ;
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
F_55 ( V_168 ) ;
F_55 ( V_172 ) ;
F_40 ( V_46 , & V_48 , 0 , 0 , 0 ) ;
return V_49 ;
}
int F_143 ( T_1 V_132 , T_1 V_133 , void * V_88 , T_1 V_166 ,
T_2 V_195 , int * V_60 )
{
struct V_167 V_168 = {
. V_170 = V_88 ,
. V_169 = V_166 ,
} ;
return F_135 ( V_132 , V_133 , & V_168 , 1 ,
V_195 , V_60 ) ;
}
static int F_144 ( struct V_165 * V_114 , struct V_185 * V_202 ,
enum V_37 V_203 , int V_38 )
{
struct V_167 V_168 = {
. V_170 = V_202 ,
. V_169 = sizeof( struct V_185 ) ,
} ;
F_24 ( V_203 >= V_40 ) ;
V_202 -> V_59 = F_130 ( V_203 ) ;
V_202 -> V_60 = F_130 ( V_38 ) ;
V_202 -> V_187 = F_129 ( V_204 ) ;
V_202 -> V_186 = 0 ;
F_141 ( V_202 , L_40 , V_38 ) ;
return F_120 ( V_114 , & V_168 , 1 , sizeof( struct V_185 ) ) ;
}
static int F_145 ( struct V_16 * V_17 ,
struct V_185 * V_202 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
int V_49 = 0 , V_205 ;
enum V_37 V_203 ;
struct V_130 * V_131 = NULL ;
void * V_206 = NULL ;
F_141 ( V_202 , L_41 ) ;
F_146 ( V_17 ) ;
switch( F_147 ( V_202 -> V_187 ) ) {
case V_204 :
F_40 ( V_46 , NULL ,
F_148 ( V_202 -> V_201 ) ,
F_148 ( V_202 -> V_59 ) ,
F_148 ( V_202 -> V_60 ) ) ;
goto V_63;
case V_207 :
F_123 ( V_17 , V_208 ,
sizeof( * V_208 ) ) ;
goto V_63;
case V_209 :
goto V_63;
case V_188 :
break;
default:
F_141 ( V_202 , L_42 ) ;
V_49 = - V_153 ;
goto V_63;
break;
}
V_205 = 0 ;
V_131 = F_115 ( F_147 ( V_202 -> V_132 ) ,
F_148 ( V_202 -> V_133 ) ) ;
if ( ! V_131 ) {
F_44 ( V_162 , L_43 ,
F_147 ( V_202 -> V_132 ) , F_148 ( V_202 -> V_133 ) ) ;
V_203 = V_210 ;
goto V_211;
}
V_203 = V_42 ;
if ( F_147 ( V_202 -> V_186 ) > V_131 -> V_158 )
V_203 = V_212 ;
if ( V_203 != V_42 )
goto V_211;
F_13 ( V_17 ) ;
V_17 -> V_213 = F_148 ( V_202 -> V_133 ) ;
V_17 -> V_214 = F_147 ( V_202 -> V_132 ) ;
V_205 = ( V_131 -> V_155 ) ( V_202 , sizeof( struct V_185 ) +
F_147 ( V_202 -> V_186 ) ,
V_131 -> V_156 , & V_206 ) ;
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
V_211:
F_124 ( & V_17 -> V_128 ) ;
V_49 = F_144 ( V_17 -> V_71 , V_202 , V_203 ,
V_205 ) ;
F_126 ( & V_17 -> V_128 ) ;
V_202 = NULL ;
F_44 ( 0 , L_44 ,
V_205 , V_203 , V_49 ) ;
if ( V_131 ) {
F_24 ( V_206 != NULL && V_131 -> V_157 == NULL ) ;
if ( V_131 -> V_157 )
( V_131 -> V_157 ) ( V_205 , V_131 -> V_156 ,
V_206 ) ;
}
V_63:
if ( V_131 )
F_107 ( V_131 ) ;
return V_49 ;
}
static int F_149 ( struct V_16 * V_17 )
{
struct V_215 * V_216 = F_150 ( V_17 -> V_74 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
if ( V_216 -> V_217 != F_151 ( V_218 ) ) {
F_85 ( V_107 L_45 V_108 L_46
L_47
L_48 , F_86 ( V_17 ) ,
( unsigned long long ) F_152 ( V_216 -> V_217 ) ,
V_218 ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_148 ( V_216 -> V_219 ) !=
F_22 () ) {
F_85 ( V_107 L_45 V_108 L_49
L_50
L_48 , F_86 ( V_17 ) ,
F_148 ( V_216 -> V_219 ) ,
F_22 () ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_148 ( V_216 -> V_220 ) !=
F_21 () ) {
F_85 ( V_107 L_45 V_108 L_51
L_52
L_48 , F_86 ( V_17 ) ,
F_148 ( V_216 -> V_220 ) ,
F_21 () ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
if ( F_148 ( V_216 -> V_221 ) !=
V_222 ) {
F_85 ( V_107 L_45 V_108 L_53
L_54
L_48 , F_86 ( V_17 ) ,
F_148 ( V_216 -> V_221 ) ,
V_222 ) ;
F_100 ( V_46 , V_17 , - V_102 ) ;
return - 1 ;
}
V_17 -> V_223 = 1 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 == V_17 ) {
F_153 ( V_17 ) ;
F_154 ( & V_46 -> V_224 , 0 ) ;
F_79 ( V_46 , V_17 , 1 , 0 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
V_17 -> V_225 -= sizeof( struct V_215 ) ;
if ( V_17 -> V_225 )
memmove ( V_216 , V_216 + 1 , V_17 -> V_225 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_17 )
{
struct V_185 * V_202 ;
int V_49 = 0 ;
void * V_88 ;
T_8 V_226 ;
F_49 ( V_17 , L_55 ) ;
F_11 ( V_17 ) ;
if ( F_156 ( V_17 -> V_223 == 0 ) ) {
if( V_17 -> V_225 < sizeof( struct V_215 ) ) {
V_88 = F_150 ( V_17 -> V_74 ) + V_17 -> V_225 ;
V_226 = sizeof( struct V_215 ) - V_17 -> V_225 ;
V_49 = F_118 ( V_17 -> V_71 , V_88 , V_226 ) ;
if ( V_49 > 0 )
V_17 -> V_225 += V_49 ;
}
if ( V_17 -> V_225 == sizeof( struct V_215 ) ) {
F_149 ( V_17 ) ;
if ( F_156 ( V_17 -> V_223 == 0 ) )
V_49 = - V_227 ;
}
goto V_63;
}
if ( V_17 -> V_225 < sizeof( struct V_185 ) ) {
V_88 = F_150 ( V_17 -> V_74 ) + V_17 -> V_225 ;
V_226 = sizeof( struct V_185 ) - V_17 -> V_225 ;
V_49 = F_118 ( V_17 -> V_71 , V_88 , V_226 ) ;
if ( V_49 > 0 ) {
V_17 -> V_225 += V_49 ;
if ( V_17 -> V_225 == sizeof( struct V_185 ) ) {
V_202 = F_150 ( V_17 -> V_74 ) ;
if ( F_147 ( V_202 -> V_186 ) >
V_152 )
V_49 = - V_228 ;
}
}
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_225 < sizeof( struct V_185 ) ) {
goto V_63;
}
V_202 = F_150 ( V_17 -> V_74 ) ;
F_141 ( V_202 , L_56 , V_17 -> V_225 ) ;
if ( V_17 -> V_225 - sizeof( struct V_185 ) < F_147 ( V_202 -> V_186 ) ) {
V_88 = F_150 ( V_17 -> V_74 ) + V_17 -> V_225 ;
V_226 = ( sizeof( struct V_185 ) + F_147 ( V_202 -> V_186 ) ) -
V_17 -> V_225 ;
V_49 = F_118 ( V_17 -> V_71 , V_88 , V_226 ) ;
if ( V_49 > 0 )
V_17 -> V_225 += V_49 ;
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_225 - sizeof( struct V_185 ) == F_147 ( V_202 -> V_186 ) ) {
V_49 = F_145 ( V_17 , V_202 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_17 -> V_225 = 0 ;
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
if ( V_49 <= 0 && V_49 != - V_184 ) {
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
F_49 ( V_17 , L_58 , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
}
F_56 ( V_17 ) ;
}
static int F_157 ( struct V_165 * V_114 )
{
int V_49 , V_229 = 1 ;
T_11 V_230 ;
V_230 = F_158 () ;
F_159 ( V_231 ) ;
V_49 = V_114 -> V_181 -> V_232 ( V_114 , V_233 , V_234 ,
( char V_235 * ) & V_229 , sizeof( V_229 ) ) ;
F_159 ( V_230 ) ;
return V_49 ;
}
static int F_160 ( struct V_165 * V_114 )
{
int V_236 = V_237 ;
return F_161 ( V_114 , V_233 , V_238 ,
( char * ) & V_236 , sizeof( V_236 ) ) ;
}
static void F_162 ( void )
{
V_239 -> V_221 = F_130 (
V_222 ) ;
V_239 -> V_219 = F_130 ( F_22 () ) ;
V_239 -> V_220 = F_130 (
F_21 () ) ;
V_239 -> V_240 = F_130 (
F_20 () ) ;
}
static void V_79 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_78 ) ;
F_44 ( V_241 , L_59 ,
( unsigned long long ) V_218 ,
( unsigned long long ) F_152 ( V_239 -> V_242 ) ) ;
F_162 () ;
F_123 ( V_17 , V_239 , sizeof( * V_239 ) ) ;
F_56 ( V_17 ) ;
}
static void V_85 ( struct V_89 * V_90 )
{
struct V_16 * V_17 =
F_47 ( V_90 , struct V_16 ,
V_84 . V_90 ) ;
F_123 ( V_17 , V_243 , sizeof( * V_243 ) ) ;
F_56 ( V_17 ) ;
}
static void V_87 ( unsigned long V_88 )
{
struct V_16 * V_17 = (struct V_16 * ) V_88 ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
#ifdef F_163
unsigned long V_244 = F_164 ( F_4 () ) -
F_164 ( V_17 -> V_21 ) ;
#else
unsigned long V_244 = F_22 () ;
#endif
F_85 ( V_107 L_17 V_108 L_60
L_61 ,
F_86 ( V_17 ) , V_244 / 1000 , V_244 % 1000 ) ;
F_154 ( & V_46 -> V_224 , 1 ) ;
F_83 ( F_27 ( V_46 ) ) ;
F_74 ( V_91 , & V_46 -> V_105 ,
F_84 ( V_106 ) ) ;
F_153 ( V_17 ) ;
}
static void F_153 ( struct V_16 * V_17 )
{
F_75 ( V_17 , & V_17 -> V_84 ) ;
F_73 ( V_17 , & V_17 -> V_84 ,
F_84 ( F_21 () ) ) ;
F_9 ( V_17 ) ;
F_165 ( & V_17 -> V_70 ,
V_112 + F_84 ( F_22 () ) ) ;
}
static void F_146 ( struct V_16 * V_17 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_110 ) ;
if ( F_78 ( & V_46 -> V_224 ) ) {
F_87 ( F_27 ( V_46 ) ) ;
F_76 ( & V_46 -> V_105 ) ;
F_154 ( & V_46 -> V_224 , 0 ) ;
}
if ( F_48 ( & V_17 -> V_70 ) )
F_153 ( V_17 ) ;
}
static void F_166 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_113 . V_90 ) ;
struct V_16 * V_17 = NULL ;
struct V_75 * V_7 = NULL , * V_245 = NULL ;
struct V_165 * V_114 = NULL ;
struct V_246 V_247 = { 0 , } , V_248 = { 0 , } ;
int V_49 = 0 , V_249 ;
unsigned int V_250 ;
unsigned int V_251 ;
V_251 = F_167 () ;
if ( F_88 () <= F_27 ( V_46 ) )
goto V_63;
V_7 = F_168 ( F_27 ( V_46 ) ) ;
if ( V_7 == NULL )
goto V_63;
V_245 = F_168 ( F_88 () ) ;
if ( V_245 == NULL )
goto V_63;
F_29 ( & V_46 -> V_50 ) ;
V_250 = F_78 ( & V_46 -> V_224 ) ;
V_249 = ( V_46 -> V_101 ||
( V_46 -> V_99 &&
( V_46 -> V_99 != - V_102 || V_250 == 0 ) ) ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_249 )
goto V_63;
V_46 -> V_111 = V_112 ;
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
F_44 ( 0 , L_62 ) ;
V_49 = - V_154 ;
goto V_63;
}
V_49 = F_169 ( V_252 , V_253 , V_254 , & V_114 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_63 , V_49 ) ;
goto V_63;
}
V_17 -> V_71 = V_114 ;
V_114 -> V_115 -> V_255 = V_52 ;
V_247 . V_256 = V_257 ;
V_247 . V_258 . V_259 = V_245 -> V_260 ;
V_247 . V_261 = F_170 ( 0 ) ;
V_49 = V_114 -> V_181 -> V_262 ( V_114 , (struct V_263 * ) & V_247 ,
sizeof( V_247 ) ) ;
if ( V_49 ) {
F_44 ( V_177 , L_64 ,
V_49 , & V_245 -> V_260 ) ;
goto V_63;
}
V_49 = F_157 ( V_17 -> V_71 ) ;
if ( V_49 ) {
F_44 ( V_177 , L_65 , V_49 ) ;
goto V_63;
}
V_49 = F_160 ( V_114 ) ;
if ( V_49 ) {
F_44 ( V_177 , L_66 , V_49 ) ;
goto V_63;
}
F_95 ( V_17 -> V_71 -> V_115 , V_17 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
V_248 . V_256 = V_257 ;
V_248 . V_258 . V_259 = V_7 -> V_260 ;
V_248 . V_261 = V_7 -> V_264 ;
V_49 = V_17 -> V_71 -> V_181 -> V_265 ( V_17 -> V_71 ,
(struct V_263 * ) & V_248 ,
sizeof( V_248 ) ,
V_266 ) ;
if ( V_49 == - V_267 )
V_49 = 0 ;
V_63:
if ( V_49 && V_17 ) {
F_85 ( V_107 L_67 V_108
L_68 , F_86 ( V_17 ) , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
}
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_245 )
F_52 ( V_245 ) ;
F_171 ( V_251 ) ;
return;
}
static void F_172 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_109 . V_90 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( ! V_46 -> V_97 ) {
F_85 ( V_107 L_69
L_70
L_71 ,
F_27 ( V_46 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
F_79 ( V_46 , NULL , 0 , 0 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
}
static void F_173 ( struct V_89 * V_90 )
{
struct V_43 * V_46 =
F_47 ( V_90 , struct V_43 , V_105 . V_90 ) ;
F_174 ( F_27 ( V_46 ) ) ;
}
void F_175 ( struct V_75 * V_7 )
{
struct V_43 * V_46 = F_25 ( V_7 -> V_110 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_154 ( & V_46 -> V_224 , 0 ) ;
F_79 ( V_46 , NULL , 0 , - V_102 ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_91 ) {
F_76 ( & V_46 -> V_109 ) ;
F_76 ( & V_46 -> V_113 ) ;
F_76 ( & V_46 -> V_105 ) ;
F_176 ( V_91 ) ;
}
}
static void F_177 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
F_178 ( V_44 ) ;
if ( ! V_7 )
return;
if ( V_44 != F_88 () )
F_175 ( V_7 ) ;
F_24 ( F_78 ( & V_94 ) < 0 ) ;
}
static void F_179 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
struct V_43 * V_46 = F_25 ( V_44 ) ;
F_180 ( V_44 ) ;
F_24 ( ! V_7 ) ;
V_46 -> V_111 = V_112 -
( F_84 ( F_20 () ) + 1 ) ;
if ( V_44 != F_88 () ) {
F_29 ( & V_46 -> V_50 ) ;
F_154 ( & V_46 -> V_224 , 0 ) ;
if ( V_46 -> V_99 )
F_79 ( V_46 , NULL , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
}
void F_181 ( void )
{
F_182 ( NULL , & V_268 ) ;
F_182 ( NULL , & V_269 ) ;
}
int F_183 ( void )
{
int V_49 ;
F_184 ( & V_269 , V_270 ,
F_177 , NULL , V_271 ) ;
F_184 ( & V_268 , V_272 ,
F_179 , NULL , V_271 ) ;
V_49 = F_185 ( NULL , & V_268 ) ;
if ( V_49 == 0 )
V_49 = F_185 ( NULL , & V_269 ) ;
if ( V_49 )
F_181 () ;
return V_49 ;
}
static int F_186 ( struct V_165 * V_114 , int * V_273 )
{
int V_49 , V_274 ;
struct V_246 sin ;
struct V_165 * V_275 = NULL ;
struct V_75 * V_7 = NULL ;
struct V_75 * V_276 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 ;
unsigned int V_251 ;
V_251 = F_167 () ;
F_24 ( V_114 == NULL ) ;
* V_273 = 0 ;
V_49 = F_187 ( V_114 -> V_115 -> V_277 , V_114 -> V_115 -> V_278 ,
V_114 -> V_115 -> V_279 , & V_275 ) ;
if ( V_49 )
goto V_63;
V_275 -> type = V_114 -> type ;
V_275 -> V_181 = V_114 -> V_181 ;
V_49 = V_114 -> V_181 -> V_280 ( V_114 , V_275 , V_266 , false ) ;
if ( V_49 < 0 )
goto V_63;
* V_273 = 1 ;
V_275 -> V_115 -> V_255 = V_52 ;
V_49 = F_157 ( V_275 ) ;
if ( V_49 ) {
F_44 ( V_177 , L_65 , V_49 ) ;
goto V_63;
}
V_49 = F_160 ( V_275 ) ;
if ( V_49 ) {
F_44 ( V_177 , L_66 , V_49 ) ;
goto V_63;
}
V_274 = sizeof( sin ) ;
V_49 = V_275 -> V_181 -> V_281 ( V_275 , (struct V_263 * ) & sin ,
& V_274 , 1 ) ;
if ( V_49 < 0 )
goto V_63;
V_7 = F_188 ( sin . V_258 . V_259 ) ;
if ( V_7 == NULL ) {
F_85 ( V_107 L_72
L_73 , & sin . V_258 . V_259 ,
F_189 ( sin . V_261 ) ) ;
V_49 = - V_153 ;
goto V_63;
}
if ( F_88 () >= V_7 -> V_110 ) {
V_276 = F_168 ( F_88 () ) ;
if ( V_276 )
F_85 ( V_107 L_74
L_75
L_76 ,
V_276 -> V_282 , V_276 -> V_110 ,
& ( V_276 -> V_260 ) ,
F_189 ( V_276 -> V_264 ) ,
V_7 -> V_282 ,
V_7 -> V_110 , & sin . V_258 . V_259 ,
F_189 ( sin . V_261 ) ) ;
V_49 = - V_153 ;
goto V_63;
}
if ( ! F_190 ( V_7 -> V_110 ) ) {
F_44 ( V_103 , L_77
L_78 ,
V_7 -> V_282 , & sin . V_258 . V_259 ,
F_189 ( sin . V_261 ) ) ;
V_49 = - V_153 ;
goto V_63;
}
V_46 = F_25 ( V_7 -> V_110 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_101 )
V_49 = - V_283 ;
else
V_49 = 0 ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_49 ) {
F_85 ( V_107 L_79
L_80 ,
V_7 -> V_282 , & sin . V_258 . V_259 ,
F_189 ( sin . V_261 ) ) ;
goto V_63;
}
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
V_49 = - V_154 ;
goto V_63;
}
V_17 -> V_71 = V_275 ;
V_275 = NULL ;
F_29 ( & V_46 -> V_50 ) ;
F_154 ( & V_46 -> V_224 , 0 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
F_95 ( V_17 -> V_71 -> V_115 , V_17 ) ;
F_71 ( V_17 , & V_17 -> V_80 ) ;
F_162 () ;
F_123 ( V_17 , V_239 , sizeof( * V_239 ) ) ;
V_63:
if ( V_275 )
F_50 ( V_275 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_276 )
F_52 ( V_276 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
F_171 ( V_251 ) ;
return V_49 ;
}
static void F_191 ( struct V_89 * V_90 )
{
struct V_165 * V_114 = V_284 ;
int V_273 ;
int V_38 ;
for (; ; ) {
V_38 = F_186 ( V_114 , & V_273 ) ;
if ( ! V_273 )
break;
F_127 () ;
}
}
static void V_127 ( struct V_114 * V_115 )
{
void (* F_90)( struct V_114 * V_115 );
F_91 ( & V_115 -> V_116 ) ;
F_90 = V_115 -> V_117 ;
if ( F_90 == NULL ) {
F_90 = V_115 -> V_119 ;
goto V_63;
}
if ( V_115 -> V_121 == V_285 ) {
F_72 ( V_91 , & V_286 ) ;
} else {
F_90 = NULL ;
}
V_63:
F_92 ( & V_115 -> V_116 ) ;
if ( F_90 != NULL )
F_90 ( V_115 ) ;
}
static int F_192 ( T_12 V_287 , T_13 V_288 )
{
struct V_165 * V_114 = NULL ;
int V_49 ;
struct V_246 sin = {
. V_256 = V_252 ,
. V_258 = { . V_259 = V_287 } ,
. V_261 = V_288 ,
} ;
V_49 = F_169 ( V_252 , V_253 , V_254 , & V_114 ) ;
if ( V_49 < 0 ) {
F_85 ( V_289 L_81 , V_49 ) ;
goto V_63;
}
V_114 -> V_115 -> V_255 = V_52 ;
F_96 ( & V_114 -> V_115 -> V_116 ) ;
V_114 -> V_115 -> V_117 = V_114 -> V_115 -> V_119 ;
V_114 -> V_115 -> V_119 = V_127 ;
F_98 ( & V_114 -> V_115 -> V_116 ) ;
V_284 = V_114 ;
F_67 ( & V_286 , F_191 ) ;
V_114 -> V_115 -> V_290 = V_291 ;
V_49 = V_114 -> V_181 -> V_262 ( V_114 , (struct V_263 * ) & sin , sizeof( sin ) ) ;
if ( V_49 < 0 ) {
F_85 ( V_289 L_82
L_83 , V_49 , & V_287 , F_189 ( V_288 ) ) ;
goto V_63;
}
V_49 = V_114 -> V_181 -> V_292 ( V_114 , 64 ) ;
if ( V_49 < 0 )
F_85 ( V_289 L_84 ,
V_49 , & V_287 , F_189 ( V_288 ) ) ;
V_63:
if ( V_49 ) {
V_284 = NULL ;
if ( V_114 )
F_50 ( V_114 ) ;
}
return V_49 ;
}
int F_193 ( struct V_75 * V_7 )
{
int V_49 = 0 ;
F_24 ( V_91 != NULL ) ;
F_24 ( V_284 != NULL ) ;
F_44 ( V_293 , L_85 ) ;
V_91 = F_194 ( L_86 , V_294 ) ;
if ( V_91 == NULL ) {
F_44 ( V_177 , L_87 ) ;
return - V_154 ;
}
V_49 = F_192 ( V_7 -> V_260 ,
V_7 -> V_264 ) ;
if ( V_49 ) {
F_195 ( V_91 ) ;
V_91 = NULL ;
} else
F_87 ( V_7 -> V_110 ) ;
return V_49 ;
}
void F_196 ( struct V_75 * V_7 )
{
struct V_165 * V_114 = V_284 ;
T_8 V_295 ;
F_24 ( V_91 == NULL ) ;
F_24 ( V_284 == NULL ) ;
F_96 ( & V_114 -> V_115 -> V_116 ) ;
V_114 -> V_115 -> V_119 = V_114 -> V_115 -> V_117 ;
V_114 -> V_115 -> V_117 = NULL ;
F_98 ( & V_114 -> V_115 -> V_116 ) ;
for ( V_295 = 0 ; V_295 < F_26 ( V_45 ) ; V_295 ++ ) {
struct V_75 * V_7 = F_168 ( V_295 ) ;
if ( V_7 ) {
F_175 ( V_7 ) ;
F_52 ( V_7 ) ;
}
}
F_44 ( V_293 , L_88 ) ;
F_195 ( V_91 ) ;
V_91 = NULL ;
F_50 ( V_284 ) ;
V_284 = NULL ;
F_83 ( V_7 -> V_110 ) ;
}
int F_197 ( void )
{
unsigned long V_295 ;
F_198 () ;
if ( F_199 () )
goto V_63;
V_239 = F_62 ( sizeof( struct V_215 ) , V_296 ) ;
V_243 = F_62 ( sizeof( struct V_185 ) , V_296 ) ;
V_208 = F_62 ( sizeof( struct V_185 ) , V_296 ) ;
if ( ! V_239 || ! V_243 || ! V_208 )
goto V_63;
V_239 -> V_217 = F_151 ( V_218 ) ;
V_239 -> V_242 = F_151 ( 1 ) ;
V_243 -> V_187 = F_129 ( V_207 ) ;
V_208 -> V_187 = F_129 ( V_209 ) ;
for ( V_295 = 0 ; V_295 < F_26 ( V_45 ) ; V_295 ++ ) {
struct V_43 * V_46 = F_25 ( V_295 ) ;
F_154 ( & V_46 -> V_224 , 0 ) ;
F_200 ( & V_46 -> V_50 ) ;
F_68 ( & V_46 -> V_113 , F_166 ) ;
F_68 ( & V_46 -> V_109 ,
F_172 ) ;
F_68 ( & V_46 -> V_105 , F_173 ) ;
V_46 -> V_99 = - V_102 ;
F_33 ( & V_46 -> V_104 ) ;
F_201 ( & V_46 -> V_51 ) ;
F_2 ( & V_46 -> V_55 ) ;
}
return 0 ;
V_63:
F_55 ( V_239 ) ;
F_55 ( V_243 ) ;
F_55 ( V_208 ) ;
F_202 () ;
F_203 () ;
return - V_154 ;
}
void F_204 ( void )
{
F_203 () ;
F_55 ( V_239 ) ;
F_55 ( V_243 ) ;
F_55 ( V_208 ) ;
F_202 () ;
}
