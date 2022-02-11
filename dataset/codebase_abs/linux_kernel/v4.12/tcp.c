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
F_69 ( & V_17 -> V_70 , V_86 ,
( unsigned long ) V_17 ) ;
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
struct V_87 * V_88 )
{
F_58 ( V_17 ) ;
if ( ! F_72 ( V_89 , V_88 ) )
F_56 ( V_17 ) ;
}
static void F_73 ( struct V_16 * V_17 ,
struct V_90 * V_88 ,
int V_91 )
{
F_58 ( V_17 ) ;
if ( ! F_74 ( V_89 , V_88 , V_91 ) )
F_56 ( V_17 ) ;
}
static void F_75 ( struct V_16 * V_17 ,
struct V_90 * V_88 )
{
if ( F_76 ( V_88 ) )
F_56 ( V_17 ) ;
}
int F_77 ( void )
{
return F_78 ( & V_92 ) ;
}
static void F_79 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
unsigned V_93 , int V_38 )
{
int V_94 = V_46 -> V_95 ;
int V_96 = V_46 -> V_97 ;
struct V_16 * V_98 = V_46 -> V_99 ;
F_35 ( & V_46 -> V_50 ) ;
if ( V_98 && ! V_17 )
F_80 ( & V_92 ) ;
else if ( ! V_98 && V_17 )
F_81 ( & V_92 ) ;
F_24 ( V_17 && V_46 -> V_99 && V_46 -> V_99 != V_17 ) ;
F_82 ( V_38 && V_93 , L_6 , V_38 , V_93 ) ;
F_82 ( V_93 && ! V_17 , L_7 , V_93 , V_17 ) ;
if ( V_94 && ! V_93 && V_38 == 0 )
V_38 = - V_100 ;
F_44 ( V_101 , L_8 ,
F_27 ( V_46 ) , V_46 -> V_99 , V_17 , V_46 -> V_95 , V_93 ,
V_46 -> V_97 , V_38 ) ;
V_46 -> V_99 = V_17 ;
V_46 -> V_95 = V_93 ? 1 : 0 ;
V_46 -> V_97 = V_38 ;
if ( V_46 -> V_97 || V_46 -> V_95 )
F_39 ( & V_46 -> V_102 ) ;
if ( V_94 && ! V_96 && V_46 -> V_97 ) {
F_83 ( F_27 ( V_46 ) ) ;
F_74 ( V_89 , & V_46 -> V_103 ,
F_84 ( V_104 ) ) ;
}
if ( V_94 && ! V_93 ) {
if ( V_98 )
F_85 ( V_105 L_9
V_106 L_10 , F_86 ( V_98 ) ) ;
F_42 ( V_46 ) ;
}
if ( ! V_94 && V_93 ) {
F_87 ( F_27 ( V_46 ) ) ;
F_76 ( & V_46 -> V_107 ) ;
F_85 ( V_105 L_11 V_106 L_10 ,
F_88 () > V_17 -> V_72 -> V_108 ?
L_12 : L_13 ,
F_86 ( V_17 ) ) ;
}
if ( ! V_93 && V_89 ) {
unsigned long V_91 ;
V_91 = ( V_46 -> V_109 +
F_84 ( F_20 () ) )
- V_110 ;
if ( V_91 > F_84 ( F_20 () ) )
V_91 = 0 ;
F_44 ( V_101 , L_14 , V_91 ) ;
F_74 ( V_89 , & V_46 -> V_111 , V_91 ) ;
V_91 += F_84 ( F_22 () ) ;
F_74 ( V_89 , & V_46 -> V_107 , V_91 ) ;
}
if ( ( V_98 == NULL ) && V_17 )
F_58 ( V_17 ) ;
if ( V_98 && ( V_98 != V_17 ) ) {
F_71 ( V_98 , & V_98 -> V_82 ) ;
F_56 ( V_98 ) ;
}
}
static void F_89 ( struct V_112 * V_113 )
{
void (* F_90)( struct V_112 * V_113 );
struct V_16 * V_17 ;
F_91 ( & V_113 -> V_114 ) ;
V_17 = V_113 -> V_115 ;
if ( V_17 ) {
F_49 ( V_17 , L_15 ) ;
F_10 ( V_17 ) ;
F_71 ( V_17 , & V_17 -> V_80 ) ;
F_90 = V_17 -> V_116 ;
} else {
F_90 = V_113 -> V_117 ;
}
F_92 ( & V_113 -> V_114 ) ;
F_90 ( V_113 ) ;
}
static void F_93 ( struct V_112 * V_113 )
{
void (* F_94)( struct V_112 * V_113 );
struct V_16 * V_17 ;
F_91 ( & V_113 -> V_114 ) ;
V_17 = V_113 -> V_115 ;
if ( V_17 == NULL ) {
F_94 = V_113 -> V_118 ;
goto V_63;
}
F_49 ( V_17 , L_16 , V_113 -> V_119 ) ;
F_94 = V_17 -> V_120 ;
switch( V_113 -> V_119 ) {
case V_121 :
case V_122 :
break;
case V_123 :
F_71 ( V_17 , & V_17 -> V_78 ) ;
break;
default:
F_85 ( V_124 L_17 V_106
L_18 ,
F_86 ( V_17 ) , V_113 -> V_119 ) ;
F_71 ( V_17 , & V_17 -> V_82 ) ;
break;
}
V_63:
F_92 ( & V_113 -> V_114 ) ;
F_94 ( V_113 ) ;
}
static void F_95 ( struct V_112 * V_113 ,
struct V_16 * V_17 )
{
F_96 ( & V_113 -> V_114 ) ;
if ( V_113 -> V_117 == V_125 ) {
V_113 -> V_117 = V_113 -> V_115 ;
V_113 -> V_115 = NULL ;
}
F_24 ( V_113 -> V_115 != NULL ) ;
V_113 -> V_115 = V_17 ;
F_58 ( V_17 ) ;
V_17 -> V_116 = V_113 -> V_117 ;
V_17 -> V_120 = V_113 -> V_118 ;
V_113 -> V_117 = F_89 ;
V_113 -> V_118 = F_93 ;
F_97 ( & V_17 -> V_126 ) ;
F_98 ( & V_113 -> V_114 ) ;
}
static int F_99 ( struct V_112 * V_113 ,
struct V_16 * V_17 )
{
int V_49 = 0 ;
F_96 ( & V_113 -> V_114 ) ;
if ( V_113 -> V_115 == V_17 ) {
V_49 = 1 ;
V_113 -> V_115 = NULL ;
V_113 -> V_117 = V_17 -> V_116 ;
V_113 -> V_118 = V_17 -> V_120 ;
}
F_98 ( & V_113 -> V_114 ) ;
return V_49 ;
}
static void F_100 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
int V_38 )
{
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_99 == V_17 )
F_79 ( V_46 , NULL , 0 , V_38 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
static void V_83 ( struct V_87 * V_88 )
{
struct V_16 * V_17 =
F_47 ( V_88 , struct V_16 ,
V_82 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
F_49 ( V_17 , L_19 ) ;
if ( F_99 ( V_17 -> V_71 -> V_113 , V_17 ) ) {
F_101 ( & V_17 -> V_70 ) ;
F_75 ( V_17 , & V_17 -> V_84 ) ;
F_56 ( V_17 ) ;
F_102 ( V_17 -> V_71 , V_127 ) ;
}
F_100 ( V_46 , V_17 , 0 ) ;
F_56 ( V_17 ) ;
}
static int F_103 ( struct V_128 * V_129 , T_1 V_130 ,
T_1 V_131 )
{
int V_49 = memcmp ( & V_129 -> V_132 , & V_131 , sizeof( V_131 ) ) ;
if ( V_49 == 0 )
V_49 = memcmp ( & V_129 -> V_133 , & V_130 , sizeof( V_130 ) ) ;
return V_49 ;
}
static struct V_128 *
F_104 ( T_1 V_130 , T_1 V_131 , struct V_134 * * * V_135 ,
struct V_134 * * V_136 )
{
struct V_134 * * V_137 = & V_138 . V_134 ;
struct V_134 * V_139 = NULL ;
struct V_128 * V_129 , * V_49 = NULL ;
int V_140 ;
while ( * V_137 ) {
V_139 = * V_137 ;
V_129 = F_105 ( V_139 , struct V_128 , V_141 ) ;
V_140 = F_103 ( V_129 , V_130 , V_131 ) ;
if ( V_140 < 0 )
V_137 = & ( * V_137 ) -> V_142 ;
else if ( V_140 > 0 )
V_137 = & ( * V_137 ) -> V_143 ;
else {
V_49 = V_129 ;
break;
}
}
if ( V_135 != NULL )
* V_135 = V_137 ;
if ( V_136 != NULL )
* V_136 = V_139 ;
return V_49 ;
}
static void F_106 ( struct V_68 * V_68 )
{
struct V_128 * V_129 ;
V_129 = F_47 ( V_68 , struct V_128 , V_144 ) ;
F_55 ( V_129 ) ;
}
static void F_107 ( struct V_128 * V_129 )
{
F_57 ( & V_129 -> V_144 , F_106 ) ;
}
int F_108 ( T_1 V_130 , T_1 V_131 , T_1 V_145 ,
T_6 * V_146 , void * V_147 ,
T_7 * V_148 ,
struct V_149 * V_150 )
{
struct V_128 * V_129 = NULL ;
struct V_134 * * V_137 , * V_139 ;
int V_49 = 0 ;
if ( V_145 > V_151 ) {
F_44 ( 0 , L_20 ,
V_145 ) ;
V_49 = - V_152 ;
goto V_63;
}
if ( ! V_130 ) {
F_44 ( 0 , L_21 , V_130 , V_146 ) ;
V_49 = - V_152 ;
goto V_63;
}
if ( ! V_146 ) {
F_44 ( 0 , L_22 ,
V_130 , V_146 ) ;
V_49 = - V_152 ;
goto V_63;
}
V_129 = F_62 ( sizeof( struct V_128 ) , V_77 ) ;
if ( V_129 == NULL ) {
V_49 = - V_153 ;
goto V_63;
}
V_129 -> V_154 = V_146 ;
V_129 -> V_155 = V_147 ;
V_129 -> V_156 = V_148 ;
V_129 -> V_133 = V_130 ;
V_129 -> V_157 = V_145 ;
V_129 -> V_132 = V_131 ;
F_63 ( & V_129 -> V_144 ) ;
F_2 ( & V_129 -> V_158 ) ;
F_109 ( & V_159 ) ;
if ( F_104 ( V_130 , V_131 , & V_137 , & V_139 ) )
V_49 = - V_160 ;
else {
F_110 ( & V_129 -> V_141 , V_139 , V_137 ) ;
F_111 ( & V_129 -> V_141 , & V_138 ) ;
F_31 ( & V_129 -> V_158 , V_150 ) ;
F_44 ( V_161 , L_23 ,
V_146 , V_130 , V_131 ) ;
F_82 ( F_104 ( V_130 , V_131 , & V_137 ,
& V_139 ) == NULL ,
L_24
L_25 , V_130 , V_131 ) ;
}
F_112 ( & V_159 ) ;
if ( V_49 )
goto V_63;
V_63:
if ( V_49 )
F_55 ( V_129 ) ;
return V_49 ;
}
void F_113 ( struct V_149 * V_162 )
{
struct V_128 * V_129 , * V_163 ;
F_109 ( & V_159 ) ;
F_43 (nmh, n, list, nh_unregister_item) {
F_44 ( V_161 , L_26 ,
V_129 -> V_154 , V_129 -> V_133 , V_129 -> V_132 ) ;
F_114 ( & V_129 -> V_141 , & V_138 ) ;
F_37 ( & V_129 -> V_158 ) ;
F_57 ( & V_129 -> V_144 , F_106 ) ;
}
F_112 ( & V_159 ) ;
}
static struct V_128 * F_115 ( T_1 V_130 , T_1 V_131 )
{
struct V_128 * V_129 ;
F_116 ( & V_159 ) ;
V_129 = F_104 ( V_130 , V_131 , NULL , NULL ) ;
if ( V_129 )
F_59 ( & V_129 -> V_144 ) ;
F_117 ( & V_159 ) ;
return V_129 ;
}
static int F_118 ( struct V_164 * V_112 , void * V_147 , T_8 V_165 )
{
struct V_166 V_167 = { . V_168 = V_165 , . V_169 = V_147 , } ;
struct V_170 V_171 = { . V_172 = V_173 , } ;
return F_119 ( V_112 , & V_171 , & V_167 , 1 , V_165 , V_171 . V_172 ) ;
}
static int F_120 ( struct V_164 * V_112 , struct V_166 * V_167 ,
T_8 V_174 , T_8 V_175 )
{
int V_49 ;
struct V_170 V_171 = { . V_172 = 0 ,} ;
if ( V_112 == NULL ) {
V_49 = - V_152 ;
goto V_63;
}
V_49 = F_121 ( V_112 , & V_171 , V_167 , V_174 , V_175 ) ;
if ( F_122 ( V_49 == V_175 ) )
return 0 ;
F_44 ( V_176 , L_27 , V_49 , V_175 ) ;
if ( V_49 >= 0 )
V_49 = - V_177 ;
V_63:
F_44 ( 0 , L_28 , V_49 ) ;
return V_49 ;
}
static void F_123 ( struct V_16 * V_17 ,
void * V_178 ,
T_8 V_179 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
T_9 V_49 ;
while ( 1 ) {
F_124 ( & V_17 -> V_126 ) ;
V_49 = V_17 -> V_71 -> V_180 -> V_181 ( V_17 -> V_71 ,
F_125 ( V_178 ) ,
F_126 ( V_178 ) ,
V_179 , V_173 ) ;
F_127 ( & V_17 -> V_126 ) ;
if ( V_49 == V_179 )
break;
if ( V_49 == ( T_9 ) - V_182 ) {
F_44 ( 0 , L_29 V_106
L_30 , V_179 , F_86 ( V_17 ) ) ;
F_128 () ;
continue;
}
F_44 ( V_176 , L_29 V_106
L_31 , V_179 , F_86 ( V_17 ) , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
break;
}
}
static void F_129 ( struct V_183 * V_171 , T_10 V_184 , T_10 V_130 , T_1 V_131 )
{
memset ( V_171 , 0 , sizeof( struct V_183 ) ) ;
V_171 -> V_185 = F_130 ( V_186 ) ;
V_171 -> V_184 = F_130 ( V_184 ) ;
V_171 -> V_130 = F_130 ( V_130 ) ;
V_171 -> V_59 = F_131 ( V_42 ) ;
V_171 -> V_60 = 0 ;
V_171 -> V_131 = F_131 ( V_131 ) ;
}
static int F_132 ( struct V_43 * V_46 ,
struct V_16 * * V_187 ,
int * error )
{
int V_49 = 0 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_97 ) {
V_49 = 1 ;
* V_187 = NULL ;
* error = V_46 -> V_97 ;
} else if ( V_46 -> V_95 ) {
F_59 ( & V_46 -> V_99 -> V_69 ) ;
V_49 = 1 ;
* V_187 = V_46 -> V_99 ;
* error = 0 ;
}
F_32 ( & V_46 -> V_50 ) ;
return V_49 ;
}
void F_133 ( unsigned long * V_188 , unsigned V_189 )
{
struct V_16 * V_17 ;
int V_7 , V_49 ;
F_24 ( V_189 < ( F_134 ( V_190 ) * sizeof( unsigned long ) ) ) ;
memset ( V_188 , 0 , V_189 ) ;
for ( V_7 = 0 ; V_7 < V_190 ; ++ V_7 ) {
if ( ! F_132 ( F_25 ( V_7 ) , & V_17 , & V_49 ) )
continue;
if ( ! V_49 ) {
F_135 ( V_7 , V_188 ) ;
F_56 ( V_17 ) ;
}
}
}
int F_136 ( T_1 V_130 , T_1 V_131 , struct V_166 * V_191 ,
T_8 V_192 , T_2 V_193 , int * V_60 )
{
int V_49 = 0 ;
struct V_183 * V_171 = NULL ;
T_8 V_174 , V_194 = 0 ;
struct V_166 * V_167 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 = F_25 ( V_193 ) ;
struct V_47 V_48 = {
. V_54 = F_137 ( V_48 . V_54 ) ,
} ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_130 , V_131 , V_195 , V_193 ) ;
if ( V_89 == NULL ) {
F_44 ( 0 , L_32 ) ;
V_49 = - V_196 ;
goto V_63;
}
if ( V_192 == 0 ) {
F_44 ( 0 , L_33 ) ;
V_49 = - V_152 ;
goto V_63;
}
V_194 = F_138 ( (struct V_197 * ) V_191 , V_192 ) ;
if ( V_194 > V_151 ) {
F_44 ( 0 , L_34 , V_194 ) ;
V_49 = - V_152 ;
goto V_63;
}
if ( V_193 == F_88 () ) {
V_49 = - V_198 ;
goto V_63;
}
F_139 ( & V_2 ) ;
F_3 ( & V_2 ) ;
F_140 ( V_46 -> V_102 , F_132 ( V_46 , & V_17 , & V_49 ) ) ;
if ( V_49 )
goto V_63;
F_7 ( & V_2 , V_17 ) ;
V_174 = V_192 + 1 ;
V_167 = F_141 ( sizeof( struct V_166 ) * V_174 , V_52 ) ;
if ( V_167 == NULL ) {
F_44 ( 0 , L_35 , V_174 ) ;
V_49 = - V_153 ;
goto V_63;
}
V_171 = F_141 ( sizeof( struct V_183 ) , V_52 ) ;
if ( ! V_171 ) {
F_44 ( 0 , L_36 ) ;
V_49 = - V_153 ;
goto V_63;
}
F_129 ( V_171 , V_194 , V_130 , V_131 ) ;
V_167 [ 0 ] . V_168 = sizeof( struct V_183 ) ;
V_167 [ 0 ] . V_169 = V_171 ;
memcpy ( & V_167 [ 1 ] , V_191 , V_192 * sizeof( struct V_166 ) ) ;
V_49 = F_28 ( V_46 , & V_48 ) ;
if ( V_49 )
goto V_63;
V_171 -> V_199 = F_131 ( V_48 . V_53 ) ;
F_8 ( & V_2 , V_48 . V_53 ) ;
F_5 ( & V_2 ) ;
F_124 ( & V_17 -> V_126 ) ;
V_49 = F_120 ( V_17 -> V_71 , V_167 , V_174 ,
sizeof( struct V_183 ) + V_194 ) ;
F_127 ( & V_17 -> V_126 ) ;
F_142 ( V_171 , L_37 , V_49 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_38 , V_49 ) ;
goto V_63;
}
F_6 ( & V_2 ) ;
F_140 ( V_48 . V_56 , F_45 ( V_46 , & V_48 ) ) ;
F_17 ( & V_2 , V_17 ) ;
V_49 = F_23 ( V_48 . V_57 ) ;
if ( V_60 && ! V_49 )
* V_60 = V_48 . V_58 ;
F_44 ( 0 , L_39 ,
V_49 , V_48 . V_58 ) ;
V_63:
F_143 ( & V_2 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
F_55 ( V_167 ) ;
F_55 ( V_171 ) ;
F_40 ( V_46 , & V_48 , 0 , 0 , 0 ) ;
return V_49 ;
}
int F_144 ( T_1 V_130 , T_1 V_131 , void * V_147 , T_1 V_165 ,
T_2 V_193 , int * V_60 )
{
struct V_166 V_167 = {
. V_169 = V_147 ,
. V_168 = V_165 ,
} ;
return F_136 ( V_130 , V_131 , & V_167 , 1 ,
V_193 , V_60 ) ;
}
static int F_145 ( struct V_164 * V_112 , struct V_183 * V_200 ,
enum V_37 V_201 , int V_38 )
{
struct V_166 V_167 = {
. V_169 = V_200 ,
. V_168 = sizeof( struct V_183 ) ,
} ;
F_24 ( V_201 >= V_40 ) ;
V_200 -> V_59 = F_131 ( V_201 ) ;
V_200 -> V_60 = F_131 ( V_38 ) ;
V_200 -> V_185 = F_130 ( V_202 ) ;
V_200 -> V_184 = 0 ;
F_142 ( V_200 , L_40 , V_38 ) ;
return F_120 ( V_112 , & V_167 , 1 , sizeof( struct V_183 ) ) ;
}
static int F_146 ( struct V_16 * V_17 ,
struct V_183 * V_200 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
int V_49 = 0 , V_203 ;
enum V_37 V_201 ;
struct V_128 * V_129 = NULL ;
void * V_204 = NULL ;
F_142 ( V_200 , L_41 ) ;
F_147 ( V_17 ) ;
switch( F_148 ( V_200 -> V_185 ) ) {
case V_202 :
F_40 ( V_46 , NULL ,
F_149 ( V_200 -> V_199 ) ,
F_149 ( V_200 -> V_59 ) ,
F_149 ( V_200 -> V_60 ) ) ;
goto V_63;
case V_205 :
F_123 ( V_17 , V_206 ,
sizeof( * V_206 ) ) ;
goto V_63;
case V_207 :
goto V_63;
case V_186 :
break;
default:
F_142 ( V_200 , L_42 ) ;
V_49 = - V_152 ;
goto V_63;
break;
}
V_203 = 0 ;
V_129 = F_115 ( F_148 ( V_200 -> V_130 ) ,
F_149 ( V_200 -> V_131 ) ) ;
if ( ! V_129 ) {
F_44 ( V_161 , L_43 ,
F_148 ( V_200 -> V_130 ) , F_149 ( V_200 -> V_131 ) ) ;
V_201 = V_208 ;
goto V_209;
}
V_201 = V_42 ;
if ( F_148 ( V_200 -> V_184 ) > V_129 -> V_157 )
V_201 = V_210 ;
if ( V_201 != V_42 )
goto V_209;
F_13 ( V_17 ) ;
V_17 -> V_211 = F_149 ( V_200 -> V_131 ) ;
V_17 -> V_212 = F_148 ( V_200 -> V_130 ) ;
V_203 = ( V_129 -> V_154 ) ( V_200 , sizeof( struct V_183 ) +
F_148 ( V_200 -> V_184 ) ,
V_129 -> V_155 , & V_204 ) ;
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
V_209:
F_124 ( & V_17 -> V_126 ) ;
V_49 = F_145 ( V_17 -> V_71 , V_200 , V_201 ,
V_203 ) ;
F_127 ( & V_17 -> V_126 ) ;
V_200 = NULL ;
F_44 ( 0 , L_44 ,
V_203 , V_201 , V_49 ) ;
if ( V_129 ) {
F_24 ( V_204 != NULL && V_129 -> V_156 == NULL ) ;
if ( V_129 -> V_156 )
( V_129 -> V_156 ) ( V_203 , V_129 -> V_155 ,
V_204 ) ;
}
V_63:
if ( V_129 )
F_107 ( V_129 ) ;
return V_49 ;
}
static int F_150 ( struct V_16 * V_17 )
{
struct V_213 * V_214 = F_151 ( V_17 -> V_74 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
if ( V_214 -> V_215 != F_152 ( V_216 ) ) {
F_85 ( V_105 L_45 V_106 L_46
L_47
L_48 , F_86 ( V_17 ) ,
( unsigned long long ) F_153 ( V_214 -> V_215 ) ,
V_216 ) ;
F_100 ( V_46 , V_17 , - V_100 ) ;
return - 1 ;
}
if ( F_149 ( V_214 -> V_217 ) !=
F_22 () ) {
F_85 ( V_105 L_45 V_106 L_49
L_50
L_48 , F_86 ( V_17 ) ,
F_149 ( V_214 -> V_217 ) ,
F_22 () ) ;
F_100 ( V_46 , V_17 , - V_100 ) ;
return - 1 ;
}
if ( F_149 ( V_214 -> V_218 ) !=
F_21 () ) {
F_85 ( V_105 L_45 V_106 L_51
L_52
L_48 , F_86 ( V_17 ) ,
F_149 ( V_214 -> V_218 ) ,
F_21 () ) ;
F_100 ( V_46 , V_17 , - V_100 ) ;
return - 1 ;
}
if ( F_149 ( V_214 -> V_219 ) !=
V_220 ) {
F_85 ( V_105 L_45 V_106 L_53
L_54
L_48 , F_86 ( V_17 ) ,
F_149 ( V_214 -> V_219 ) ,
V_220 ) ;
F_100 ( V_46 , V_17 , - V_100 ) ;
return - 1 ;
}
V_17 -> V_221 = 1 ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_99 == V_17 ) {
F_154 ( V_17 ) ;
F_155 ( & V_46 -> V_222 , 0 ) ;
F_79 ( V_46 , V_17 , 1 , 0 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
V_17 -> V_223 -= sizeof( struct V_213 ) ;
if ( V_17 -> V_223 )
memmove ( V_214 , V_214 + 1 , V_17 -> V_223 ) ;
return 0 ;
}
static int F_156 ( struct V_16 * V_17 )
{
struct V_183 * V_200 ;
int V_49 = 0 ;
void * V_147 ;
T_8 V_224 ;
F_49 ( V_17 , L_55 ) ;
F_11 ( V_17 ) ;
if ( F_157 ( V_17 -> V_221 == 0 ) ) {
if( V_17 -> V_223 < sizeof( struct V_213 ) ) {
V_147 = F_151 ( V_17 -> V_74 ) + V_17 -> V_223 ;
V_224 = sizeof( struct V_213 ) - V_17 -> V_223 ;
V_49 = F_118 ( V_17 -> V_71 , V_147 , V_224 ) ;
if ( V_49 > 0 )
V_17 -> V_223 += V_49 ;
}
if ( V_17 -> V_223 == sizeof( struct V_213 ) ) {
F_150 ( V_17 ) ;
if ( F_157 ( V_17 -> V_221 == 0 ) )
V_49 = - V_225 ;
}
goto V_63;
}
if ( V_17 -> V_223 < sizeof( struct V_183 ) ) {
V_147 = F_151 ( V_17 -> V_74 ) + V_17 -> V_223 ;
V_224 = sizeof( struct V_183 ) - V_17 -> V_223 ;
V_49 = F_118 ( V_17 -> V_71 , V_147 , V_224 ) ;
if ( V_49 > 0 ) {
V_17 -> V_223 += V_49 ;
if ( V_17 -> V_223 == sizeof( struct V_183 ) ) {
V_200 = F_151 ( V_17 -> V_74 ) ;
if ( F_148 ( V_200 -> V_184 ) >
V_151 )
V_49 = - V_226 ;
}
}
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_223 < sizeof( struct V_183 ) ) {
goto V_63;
}
V_200 = F_151 ( V_17 -> V_74 ) ;
F_142 ( V_200 , L_56 , V_17 -> V_223 ) ;
if ( V_17 -> V_223 - sizeof( struct V_183 ) < F_148 ( V_200 -> V_184 ) ) {
V_147 = F_151 ( V_17 -> V_74 ) + V_17 -> V_223 ;
V_224 = ( sizeof( struct V_183 ) + F_148 ( V_200 -> V_184 ) ) -
V_17 -> V_223 ;
V_49 = F_118 ( V_17 -> V_71 , V_147 , V_224 ) ;
if ( V_49 > 0 )
V_17 -> V_223 += V_49 ;
if ( V_49 <= 0 )
goto V_63;
}
if ( V_17 -> V_223 - sizeof( struct V_183 ) == F_148 ( V_200 -> V_184 ) ) {
V_49 = F_146 ( V_17 , V_200 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_17 -> V_223 = 0 ;
}
V_63:
F_49 ( V_17 , L_57 , V_49 ) ;
F_12 ( V_17 ) ;
return V_49 ;
}
static void V_81 ( struct V_87 * V_88 )
{
struct V_16 * V_17 =
F_47 ( V_88 , struct V_16 , V_80 ) ;
int V_49 ;
do {
V_49 = F_156 ( V_17 ) ;
} while ( V_49 > 0 );
if ( V_49 <= 0 && V_49 != - V_182 ) {
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
F_49 ( V_17 , L_58 , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
}
F_56 ( V_17 ) ;
}
static int F_158 ( struct V_164 * V_112 )
{
int V_227 = 1 ;
return F_159 ( V_112 , V_228 , V_229 ,
( void * ) & V_227 , sizeof( V_227 ) ) ;
}
static int F_160 ( struct V_164 * V_112 )
{
int V_230 = V_231 ;
return F_159 ( V_112 , V_228 , V_232 ,
( void * ) & V_230 , sizeof( V_230 ) ) ;
}
static void F_161 ( void )
{
V_233 -> V_219 = F_131 (
V_220 ) ;
V_233 -> V_217 = F_131 ( F_22 () ) ;
V_233 -> V_218 = F_131 (
F_21 () ) ;
V_233 -> V_234 = F_131 (
F_20 () ) ;
}
static void V_79 ( struct V_87 * V_88 )
{
struct V_16 * V_17 =
F_47 ( V_88 , struct V_16 ,
V_78 ) ;
F_44 ( V_235 , L_59 ,
( unsigned long long ) V_216 ,
( unsigned long long ) F_153 ( V_233 -> V_236 ) ) ;
F_161 () ;
F_123 ( V_17 , V_233 , sizeof( * V_233 ) ) ;
F_56 ( V_17 ) ;
}
static void V_85 ( struct V_87 * V_88 )
{
struct V_16 * V_17 =
F_47 ( V_88 , struct V_16 ,
V_84 . V_88 ) ;
F_123 ( V_17 , V_237 , sizeof( * V_237 ) ) ;
F_56 ( V_17 ) ;
}
static void V_86 ( unsigned long V_147 )
{
struct V_16 * V_17 = (struct V_16 * ) V_147 ;
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
#ifdef F_162
unsigned long V_238 = F_163 ( F_4 () ) -
F_163 ( V_17 -> V_21 ) ;
#else
unsigned long V_238 = F_22 () ;
#endif
F_85 ( V_105 L_17 V_106 L_60
L_61 ,
F_86 ( V_17 ) , V_238 / 1000 , V_238 % 1000 ) ;
F_155 ( & V_46 -> V_222 , 1 ) ;
F_83 ( F_27 ( V_46 ) ) ;
F_74 ( V_89 , & V_46 -> V_103 ,
F_84 ( V_104 ) ) ;
F_154 ( V_17 ) ;
}
static void F_154 ( struct V_16 * V_17 )
{
F_75 ( V_17 , & V_17 -> V_84 ) ;
F_73 ( V_17 , & V_17 -> V_84 ,
F_84 ( F_21 () ) ) ;
F_9 ( V_17 ) ;
F_164 ( & V_17 -> V_70 ,
V_110 + F_84 ( F_22 () ) ) ;
}
static void F_147 ( struct V_16 * V_17 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_72 -> V_108 ) ;
if ( F_78 ( & V_46 -> V_222 ) ) {
F_87 ( F_27 ( V_46 ) ) ;
F_76 ( & V_46 -> V_103 ) ;
F_155 ( & V_46 -> V_222 , 0 ) ;
}
if ( F_48 ( & V_17 -> V_70 ) )
F_154 ( V_17 ) ;
}
static void F_165 ( struct V_87 * V_88 )
{
struct V_43 * V_46 =
F_47 ( V_88 , struct V_43 , V_111 . V_88 ) ;
struct V_16 * V_17 = NULL ;
struct V_75 * V_7 = NULL , * V_239 = NULL ;
struct V_164 * V_112 = NULL ;
struct V_240 V_241 = { 0 , } , V_242 = { 0 , } ;
int V_49 = 0 , V_243 ;
unsigned int V_244 ;
unsigned int V_245 ;
V_245 = F_166 () ;
if ( F_88 () <= F_27 ( V_46 ) )
goto V_63;
V_7 = F_167 ( F_27 ( V_46 ) ) ;
if ( V_7 == NULL )
goto V_63;
V_239 = F_167 ( F_88 () ) ;
if ( V_239 == NULL )
goto V_63;
F_29 ( & V_46 -> V_50 ) ;
V_244 = F_78 ( & V_46 -> V_222 ) ;
V_243 = ( V_46 -> V_99 ||
( V_46 -> V_97 &&
( V_46 -> V_97 != - V_100 || V_244 == 0 ) ) ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_243 )
goto V_63;
V_46 -> V_109 = V_110 ;
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
F_44 ( 0 , L_62 ) ;
V_49 = - V_153 ;
goto V_63;
}
V_49 = F_168 ( V_246 , V_247 , V_248 , & V_112 ) ;
if ( V_49 < 0 ) {
F_44 ( 0 , L_63 , V_49 ) ;
goto V_63;
}
V_17 -> V_71 = V_112 ;
V_112 -> V_113 -> V_249 = V_52 ;
V_241 . V_250 = V_251 ;
V_241 . V_252 . V_253 = V_239 -> V_254 ;
V_241 . V_255 = F_169 ( 0 ) ;
V_49 = V_112 -> V_180 -> V_256 ( V_112 , (struct V_257 * ) & V_241 ,
sizeof( V_241 ) ) ;
if ( V_49 ) {
F_44 ( V_176 , L_64 ,
V_49 , & V_239 -> V_254 ) ;
goto V_63;
}
V_49 = F_158 ( V_17 -> V_71 ) ;
if ( V_49 ) {
F_44 ( V_176 , L_65 , V_49 ) ;
goto V_63;
}
V_49 = F_160 ( V_112 ) ;
if ( V_49 ) {
F_44 ( V_176 , L_66 , V_49 ) ;
goto V_63;
}
F_95 ( V_17 -> V_71 -> V_113 , V_17 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
V_242 . V_250 = V_251 ;
V_242 . V_252 . V_253 = V_7 -> V_254 ;
V_242 . V_255 = V_7 -> V_258 ;
V_49 = V_17 -> V_71 -> V_180 -> V_259 ( V_17 -> V_71 ,
(struct V_257 * ) & V_242 ,
sizeof( V_242 ) ,
V_260 ) ;
if ( V_49 == - V_261 )
V_49 = 0 ;
V_63:
if ( V_49 && V_17 ) {
F_85 ( V_105 L_67 V_106
L_68 , F_86 ( V_17 ) , V_49 ) ;
F_100 ( V_46 , V_17 , 0 ) ;
}
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_239 )
F_52 ( V_239 ) ;
F_170 ( V_245 ) ;
return;
}
static void F_171 ( struct V_87 * V_88 )
{
struct V_43 * V_46 =
F_47 ( V_88 , struct V_43 , V_107 . V_88 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( ! V_46 -> V_95 ) {
F_85 ( V_105 L_69
L_70
L_71 ,
F_27 ( V_46 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
F_79 ( V_46 , NULL , 0 , 0 ) ;
}
F_32 ( & V_46 -> V_50 ) ;
}
static void F_172 ( struct V_87 * V_88 )
{
struct V_43 * V_46 =
F_47 ( V_88 , struct V_43 , V_103 . V_88 ) ;
F_173 ( F_27 ( V_46 ) ) ;
}
void F_174 ( struct V_75 * V_7 )
{
struct V_43 * V_46 = F_25 ( V_7 -> V_108 ) ;
F_29 ( & V_46 -> V_50 ) ;
F_155 ( & V_46 -> V_222 , 0 ) ;
F_79 ( V_46 , NULL , 0 , - V_100 ) ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_89 ) {
F_76 ( & V_46 -> V_107 ) ;
F_76 ( & V_46 -> V_111 ) ;
F_76 ( & V_46 -> V_103 ) ;
F_175 ( V_89 ) ;
}
}
static void F_176 ( struct V_75 * V_7 , int V_44 ,
void * V_147 )
{
F_177 ( V_44 ) ;
if ( ! V_7 )
return;
if ( V_44 != F_88 () )
F_174 ( V_7 ) ;
F_24 ( F_78 ( & V_92 ) < 0 ) ;
}
static void F_178 ( struct V_75 * V_7 , int V_44 ,
void * V_147 )
{
struct V_43 * V_46 = F_25 ( V_44 ) ;
F_179 ( V_44 ) ;
F_24 ( ! V_7 ) ;
V_46 -> V_109 = V_110 -
( F_84 ( F_20 () ) + 1 ) ;
if ( V_44 != F_88 () ) {
F_29 ( & V_46 -> V_50 ) ;
F_155 ( & V_46 -> V_222 , 0 ) ;
if ( V_46 -> V_97 )
F_79 ( V_46 , NULL , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
}
}
void F_180 ( void )
{
F_181 ( NULL , & V_262 ) ;
F_181 ( NULL , & V_263 ) ;
}
int F_182 ( void )
{
int V_49 ;
F_183 ( & V_263 , V_264 ,
F_176 , NULL , V_265 ) ;
F_183 ( & V_262 , V_266 ,
F_178 , NULL , V_265 ) ;
V_49 = F_184 ( NULL , & V_262 ) ;
if ( V_49 == 0 )
V_49 = F_184 ( NULL , & V_263 ) ;
if ( V_49 )
F_180 () ;
return V_49 ;
}
static int F_185 ( struct V_164 * V_112 , int * V_267 )
{
int V_49 , V_268 ;
struct V_240 sin ;
struct V_164 * V_269 = NULL ;
struct V_75 * V_7 = NULL ;
struct V_75 * V_270 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 ;
unsigned int V_245 ;
V_245 = F_166 () ;
F_24 ( V_112 == NULL ) ;
* V_267 = 0 ;
V_49 = F_186 ( V_112 -> V_113 -> V_271 , V_112 -> V_113 -> V_272 ,
V_112 -> V_113 -> V_273 , & V_269 ) ;
if ( V_49 )
goto V_63;
V_269 -> type = V_112 -> type ;
V_269 -> V_180 = V_112 -> V_180 ;
V_49 = V_112 -> V_180 -> V_274 ( V_112 , V_269 , V_260 , false ) ;
if ( V_49 < 0 )
goto V_63;
* V_267 = 1 ;
V_269 -> V_113 -> V_249 = V_52 ;
V_49 = F_158 ( V_269 ) ;
if ( V_49 ) {
F_44 ( V_176 , L_65 , V_49 ) ;
goto V_63;
}
V_49 = F_160 ( V_269 ) ;
if ( V_49 ) {
F_44 ( V_176 , L_66 , V_49 ) ;
goto V_63;
}
V_268 = sizeof( sin ) ;
V_49 = V_269 -> V_180 -> V_275 ( V_269 , (struct V_257 * ) & sin ,
& V_268 , 1 ) ;
if ( V_49 < 0 )
goto V_63;
V_7 = F_187 ( sin . V_252 . V_253 ) ;
if ( V_7 == NULL ) {
F_85 ( V_105 L_72
L_73 , & sin . V_252 . V_253 ,
F_188 ( sin . V_255 ) ) ;
V_49 = - V_152 ;
goto V_63;
}
if ( F_88 () >= V_7 -> V_108 ) {
V_270 = F_167 ( F_88 () ) ;
if ( V_270 )
F_85 ( V_105 L_74
L_75
L_76 ,
V_270 -> V_276 , V_270 -> V_108 ,
& ( V_270 -> V_254 ) ,
F_188 ( V_270 -> V_258 ) ,
V_7 -> V_276 ,
V_7 -> V_108 , & sin . V_252 . V_253 ,
F_188 ( sin . V_255 ) ) ;
V_49 = - V_152 ;
goto V_63;
}
if ( ! F_189 ( V_7 -> V_108 ) ) {
F_44 ( V_101 , L_77
L_78 ,
V_7 -> V_276 , & sin . V_252 . V_253 ,
F_188 ( sin . V_255 ) ) ;
V_49 = - V_152 ;
goto V_63;
}
V_46 = F_25 ( V_7 -> V_108 ) ;
F_29 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_99 )
V_49 = - V_277 ;
else
V_49 = 0 ;
F_32 ( & V_46 -> V_50 ) ;
if ( V_49 ) {
F_85 ( V_105 L_79
L_80 ,
V_7 -> V_276 , & sin . V_252 . V_253 ,
F_188 ( sin . V_255 ) ) ;
goto V_63;
}
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
V_49 = - V_153 ;
goto V_63;
}
V_17 -> V_71 = V_269 ;
V_269 = NULL ;
F_29 ( & V_46 -> V_50 ) ;
F_155 ( & V_46 -> V_222 , 0 ) ;
F_79 ( V_46 , V_17 , 0 , 0 ) ;
F_32 ( & V_46 -> V_50 ) ;
F_95 ( V_17 -> V_71 -> V_113 , V_17 ) ;
F_71 ( V_17 , & V_17 -> V_80 ) ;
F_161 () ;
F_123 ( V_17 , V_233 , sizeof( * V_233 ) ) ;
V_63:
if ( V_269 )
F_50 ( V_269 ) ;
if ( V_7 )
F_52 ( V_7 ) ;
if ( V_270 )
F_52 ( V_270 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
F_170 ( V_245 ) ;
return V_49 ;
}
static void F_190 ( struct V_87 * V_88 )
{
struct V_164 * V_112 = V_278 ;
int V_267 ;
int V_38 ;
for (; ; ) {
V_38 = F_185 ( V_112 , & V_267 ) ;
if ( ! V_267 )
break;
F_128 () ;
}
}
static void V_125 ( struct V_112 * V_113 )
{
void (* F_90)( struct V_112 * V_113 );
F_91 ( & V_113 -> V_114 ) ;
F_90 = V_113 -> V_115 ;
if ( F_90 == NULL ) {
F_90 = V_113 -> V_117 ;
goto V_63;
}
if ( V_113 -> V_119 == V_279 ) {
F_72 ( V_89 , & V_280 ) ;
} else {
F_90 = NULL ;
}
V_63:
F_92 ( & V_113 -> V_114 ) ;
if ( F_90 != NULL )
F_90 ( V_113 ) ;
}
static int F_191 ( T_11 V_281 , T_12 V_282 )
{
struct V_164 * V_112 = NULL ;
int V_49 ;
struct V_240 sin = {
. V_250 = V_246 ,
. V_252 = { . V_253 = V_281 } ,
. V_255 = V_282 ,
} ;
V_49 = F_168 ( V_246 , V_247 , V_248 , & V_112 ) ;
if ( V_49 < 0 ) {
F_85 ( V_283 L_81 , V_49 ) ;
goto V_63;
}
V_112 -> V_113 -> V_249 = V_52 ;
F_96 ( & V_112 -> V_113 -> V_114 ) ;
V_112 -> V_113 -> V_115 = V_112 -> V_113 -> V_117 ;
V_112 -> V_113 -> V_117 = V_125 ;
F_98 ( & V_112 -> V_113 -> V_114 ) ;
V_278 = V_112 ;
F_67 ( & V_280 , F_190 ) ;
V_112 -> V_113 -> V_284 = V_285 ;
V_49 = V_112 -> V_180 -> V_256 ( V_112 , (struct V_257 * ) & sin , sizeof( sin ) ) ;
if ( V_49 < 0 ) {
F_85 ( V_283 L_82
L_83 , V_49 , & V_281 , F_188 ( V_282 ) ) ;
goto V_63;
}
V_49 = V_112 -> V_180 -> V_286 ( V_112 , 64 ) ;
if ( V_49 < 0 )
F_85 ( V_283 L_84 ,
V_49 , & V_281 , F_188 ( V_282 ) ) ;
V_63:
if ( V_49 ) {
V_278 = NULL ;
if ( V_112 )
F_50 ( V_112 ) ;
}
return V_49 ;
}
int F_192 ( struct V_75 * V_7 )
{
int V_49 = 0 ;
F_24 ( V_89 != NULL ) ;
F_24 ( V_278 != NULL ) ;
F_44 ( V_287 , L_85 ) ;
V_89 = F_193 ( L_86 , V_288 ) ;
if ( V_89 == NULL ) {
F_44 ( V_176 , L_87 ) ;
return - V_153 ;
}
V_49 = F_191 ( V_7 -> V_254 ,
V_7 -> V_258 ) ;
if ( V_49 ) {
F_194 ( V_89 ) ;
V_89 = NULL ;
} else
F_87 ( V_7 -> V_108 ) ;
return V_49 ;
}
void F_195 ( struct V_75 * V_7 )
{
struct V_164 * V_112 = V_278 ;
T_8 V_289 ;
F_24 ( V_89 == NULL ) ;
F_24 ( V_278 == NULL ) ;
F_96 ( & V_112 -> V_113 -> V_114 ) ;
V_112 -> V_113 -> V_117 = V_112 -> V_113 -> V_115 ;
V_112 -> V_113 -> V_115 = NULL ;
F_98 ( & V_112 -> V_113 -> V_114 ) ;
for ( V_289 = 0 ; V_289 < F_26 ( V_45 ) ; V_289 ++ ) {
struct V_75 * V_7 = F_167 ( V_289 ) ;
if ( V_7 ) {
F_174 ( V_7 ) ;
F_52 ( V_7 ) ;
}
}
F_44 ( V_287 , L_88 ) ;
F_194 ( V_89 ) ;
V_89 = NULL ;
F_50 ( V_278 ) ;
V_278 = NULL ;
F_83 ( V_7 -> V_108 ) ;
}
int F_196 ( void )
{
unsigned long V_289 ;
F_197 () ;
if ( F_198 () )
goto V_63;
V_233 = F_62 ( sizeof( struct V_213 ) , V_290 ) ;
V_237 = F_62 ( sizeof( struct V_183 ) , V_290 ) ;
V_206 = F_62 ( sizeof( struct V_183 ) , V_290 ) ;
if ( ! V_233 || ! V_237 || ! V_206 )
goto V_63;
V_233 -> V_215 = F_152 ( V_216 ) ;
V_233 -> V_236 = F_152 ( 1 ) ;
V_237 -> V_185 = F_130 ( V_205 ) ;
V_206 -> V_185 = F_130 ( V_207 ) ;
for ( V_289 = 0 ; V_289 < F_26 ( V_45 ) ; V_289 ++ ) {
struct V_43 * V_46 = F_25 ( V_289 ) ;
F_155 ( & V_46 -> V_222 , 0 ) ;
F_199 ( & V_46 -> V_50 ) ;
F_68 ( & V_46 -> V_111 , F_165 ) ;
F_68 ( & V_46 -> V_107 ,
F_171 ) ;
F_68 ( & V_46 -> V_103 , F_172 ) ;
V_46 -> V_97 = - V_100 ;
F_33 ( & V_46 -> V_102 ) ;
F_200 ( & V_46 -> V_51 ) ;
F_2 ( & V_46 -> V_55 ) ;
}
return 0 ;
V_63:
F_55 ( V_233 ) ;
F_55 ( V_237 ) ;
F_55 ( V_206 ) ;
F_201 () ;
F_202 () ;
return - V_153 ;
}
void F_203 ( void )
{
F_202 () ;
F_55 ( V_233 ) ;
F_55 ( V_237 ) ;
F_55 ( V_206 ) ;
F_201 () ;
}
