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
int V_49 = 0 ;
do {
if ( ! F_29 ( & V_46 -> V_50 , V_51 ) ) {
V_49 = - V_52 ;
break;
}
F_30 ( & V_46 -> V_53 ) ;
V_49 = F_31 ( & V_46 -> V_50 , V_48 , & V_48 -> V_54 ) ;
if ( V_49 == 0 )
F_32 ( & V_48 -> V_55 ,
& V_46 -> V_56 ) ;
F_33 ( & V_46 -> V_53 ) ;
} while ( V_49 == - V_52 );
if ( V_49 == 0 ) {
F_34 ( & V_48 -> V_57 ) ;
V_48 -> V_58 = V_42 ;
V_48 -> V_59 = 0 ;
}
return V_49 ;
}
static void F_35 ( struct V_43 * V_46 ,
struct V_47 * V_48 ,
enum V_37 V_60 ,
T_4 V_61 )
{
F_36 ( & V_46 -> V_53 ) ;
if ( ! F_37 ( & V_48 -> V_55 ) ) {
F_38 ( & V_48 -> V_55 ) ;
V_48 -> V_58 = V_60 ;
V_48 -> V_59 = V_61 ;
F_39 ( & V_46 -> V_50 , V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_57 ) ;
}
}
static void F_41 ( struct V_43 * V_46 ,
struct V_47 * V_48 ,
T_5 V_62 , enum V_37 V_60 ,
T_4 V_61 )
{
F_30 ( & V_46 -> V_53 ) ;
if ( V_48 == NULL ) {
if ( V_62 > V_63 )
goto V_64;
V_48 = F_42 ( & V_46 -> V_50 , V_62 ) ;
if ( V_48 == NULL )
goto V_64;
}
F_35 ( V_46 , V_48 , V_60 , V_61 ) ;
V_64:
F_33 ( & V_46 -> V_53 ) ;
return;
}
static void F_43 ( struct V_43 * V_46 )
{
struct V_47 * V_48 , * V_65 ;
unsigned int V_66 = 0 ;
F_36 ( & V_46 -> V_53 ) ;
F_44 (nsw, tmp, &nn->nn_status_list, ns_node_item) {
F_35 ( V_46 , V_48 , V_67 , 0 ) ;
V_66 ++ ;
}
F_45 ( 0 , L_1 , V_66 ,
F_27 ( V_46 ) ) ;
}
static int F_46 ( struct V_43 * V_46 ,
struct V_47 * V_48 )
{
int V_68 ;
F_30 ( & V_46 -> V_53 ) ;
V_68 = F_37 ( & V_48 -> V_55 ) ;
F_33 ( & V_46 -> V_53 ) ;
return V_68 ;
}
static void F_47 ( struct V_69 * V_69 )
{
struct V_16 * V_17 = F_48 ( V_69 ,
struct V_16 , V_70 ) ;
F_24 ( F_49 ( & V_17 -> V_71 ) ) ;
F_50 ( V_17 , L_2 ) ;
if ( V_17 -> V_72 ) {
F_51 ( V_17 -> V_72 ) ;
V_17 -> V_72 = NULL ;
}
F_52 ( & V_17 -> V_73 -> V_74 ) ;
F_53 ( V_17 -> V_73 ) ;
V_17 -> V_73 = NULL ;
F_54 ( V_17 ) ;
F_55 ( V_17 ) ;
}
static void F_56 ( struct V_16 * V_17 )
{
F_50 ( V_17 , L_3 ) ;
F_57 ( & V_17 -> V_70 , F_47 ) ;
}
static void F_58 ( struct V_16 * V_17 )
{
F_50 ( V_17 , L_4 ) ;
F_59 ( & V_17 -> V_70 ) ;
}
static struct V_16 * F_60 ( struct V_75 * V_7 )
{
struct V_16 * V_17 , * V_49 = NULL ;
struct V_76 * V_76 = NULL ;
int V_61 = 0 ;
V_76 = F_61 ( V_77 ) ;
V_17 = F_62 ( sizeof( * V_17 ) , V_77 ) ;
if ( V_17 == NULL || V_76 == NULL )
goto V_64;
F_63 ( & V_17 -> V_70 ) ;
F_64 ( V_7 ) ;
V_17 -> V_73 = V_7 ;
V_61 = F_65 ( & V_7 -> V_74 ) ;
if ( V_61 ) {
F_66 ( V_61 ) ;
F_53 ( V_7 ) ;
goto V_64;
}
F_67 ( & V_17 -> V_78 , V_79 ) ;
F_67 ( & V_17 -> V_80 , V_81 ) ;
F_67 ( & V_17 -> V_82 , V_83 ) ;
F_68 ( & V_17 -> V_84 , V_85 ) ;
F_69 ( & V_17 -> V_71 ) ;
V_17 -> V_71 . V_86 = V_87 ;
V_17 -> V_71 . V_88 = ( unsigned long ) V_17 ;
F_50 ( V_17 , L_5 ) ;
V_49 = V_17 ;
V_17 -> V_89 = V_76 ;
F_70 ( V_17 ) ;
V_17 = NULL ;
V_76 = NULL ;
V_64:
if ( V_76 )
F_71 ( V_76 ) ;
F_55 ( V_17 ) ;
return V_49 ;
}
static void F_72 ( struct V_16 * V_17 ,
struct V_90 * V_91 )
{
F_58 ( V_17 ) ;
if ( ! F_73 ( V_92 , V_91 ) )
F_56 ( V_17 ) ;
}
static void F_74 ( struct V_16 * V_17 ,
struct V_93 * V_91 ,
int V_94 )
{
F_58 ( V_17 ) ;
if ( ! F_75 ( V_92 , V_91 , V_94 ) )
F_56 ( V_17 ) ;
}
static void F_76 ( struct V_16 * V_17 ,
struct V_93 * V_91 )
{
if ( F_77 ( V_91 ) )
F_56 ( V_17 ) ;
}
int F_78 ( void )
{
return F_79 ( & V_95 ) ;
}
static void F_80 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
unsigned V_96 , int V_38 )
{
int V_97 = V_46 -> V_98 ;
int V_99 = V_46 -> V_100 ;
struct V_16 * V_101 = V_46 -> V_102 ;
F_36 ( & V_46 -> V_53 ) ;
if ( V_101 && ! V_17 )
F_81 ( & V_95 ) ;
else if ( ! V_101 && V_17 )
F_82 ( & V_95 ) ;
F_24 ( V_17 && V_46 -> V_102 && V_46 -> V_102 != V_17 ) ;
F_83 ( V_38 && V_96 , L_6 , V_38 , V_96 ) ;
F_83 ( V_96 && ! V_17 , L_7 , V_96 , V_17 ) ;
if ( V_97 && ! V_96 && V_38 == 0 )
V_38 = - V_103 ;
F_45 ( V_104 , L_8 ,
F_27 ( V_46 ) , V_46 -> V_102 , V_17 , V_46 -> V_98 , V_96 ,
V_46 -> V_100 , V_38 ) ;
V_46 -> V_102 = V_17 ;
V_46 -> V_98 = V_96 ? 1 : 0 ;
V_46 -> V_100 = V_38 ;
if ( V_46 -> V_100 || V_46 -> V_98 )
F_40 ( & V_46 -> V_105 ) ;
if ( ! V_99 && V_46 -> V_100 ) {
F_84 ( F_27 ( V_46 ) ) ;
F_75 ( V_92 , & V_46 -> V_106 ,
F_85 ( V_107 ) ) ;
}
if ( V_97 && ! V_96 ) {
F_86 ( V_108 L_9
V_109 L_10 , F_87 ( V_101 ) ) ;
F_43 ( V_46 ) ;
}
if ( ! V_97 && V_96 ) {
F_88 ( F_27 ( V_46 ) ) ;
F_77 ( & V_46 -> V_110 ) ;
F_86 ( V_108 L_11 V_109 L_10 ,
F_89 () > V_17 -> V_73 -> V_111 ?
L_12 : L_13 ,
F_87 ( V_17 ) ) ;
}
if ( ! V_96 && V_92 ) {
unsigned long V_94 ;
V_94 = ( V_46 -> V_112 +
F_85 ( F_20 () ) )
- V_113 ;
if ( V_94 > F_85 ( F_20 () ) )
V_94 = 0 ;
F_45 ( V_104 , L_14 , V_94 ) ;
F_75 ( V_92 , & V_46 -> V_114 , V_94 ) ;
V_94 += F_85 ( F_22 () ) ;
F_75 ( V_92 , & V_46 -> V_110 , V_94 ) ;
}
if ( ( V_101 == NULL ) && V_17 )
F_58 ( V_17 ) ;
if ( V_101 && ( V_101 != V_17 ) ) {
F_72 ( V_101 , & V_101 -> V_82 ) ;
F_56 ( V_101 ) ;
}
}
static void F_90 ( struct V_115 * V_116 , int V_117 )
{
void (* F_91)( struct V_115 * V_116 , int V_117 );
F_92 ( & V_116 -> V_118 ) ;
if ( V_116 -> V_119 ) {
struct V_16 * V_17 = V_116 -> V_119 ;
F_50 ( V_17 , L_15 ) ;
F_10 ( V_17 ) ;
F_72 ( V_17 , & V_17 -> V_80 ) ;
F_91 = V_17 -> V_120 ;
} else {
F_91 = V_116 -> V_121 ;
}
F_93 ( & V_116 -> V_118 ) ;
F_91 ( V_116 , V_117 ) ;
}
static void F_94 ( struct V_115 * V_116 )
{
void (* F_95)( struct V_115 * V_116 );
struct V_16 * V_17 ;
F_92 ( & V_116 -> V_118 ) ;
V_17 = V_116 -> V_119 ;
if ( V_17 == NULL ) {
F_95 = V_116 -> V_122 ;
goto V_64;
}
F_50 ( V_17 , L_16 , V_116 -> V_123 ) ;
F_95 = V_17 -> V_124 ;
switch( V_116 -> V_123 ) {
case V_125 :
case V_126 :
break;
case V_127 :
F_72 ( V_17 , & V_17 -> V_78 ) ;
break;
default:
F_86 ( V_128 L_17 V_109
L_18 ,
F_87 ( V_17 ) , V_116 -> V_123 ) ;
F_72 ( V_17 , & V_17 -> V_82 ) ;
break;
}
V_64:
F_93 ( & V_116 -> V_118 ) ;
F_95 ( V_116 ) ;
}
static void F_96 ( struct V_115 * V_116 ,
struct V_16 * V_17 )
{
F_97 ( & V_116 -> V_118 ) ;
if ( V_116 -> V_121 == V_129 ) {
V_116 -> V_121 = V_116 -> V_119 ;
V_116 -> V_119 = NULL ;
}
F_24 ( V_116 -> V_119 != NULL ) ;
V_116 -> V_119 = V_17 ;
F_58 ( V_17 ) ;
V_17 -> V_120 = V_116 -> V_121 ;
V_17 -> V_124 = V_116 -> V_122 ;
V_116 -> V_121 = F_90 ;
V_116 -> V_122 = F_94 ;
F_98 ( & V_17 -> V_130 ) ;
F_99 ( & V_116 -> V_118 ) ;
}
static int F_100 ( struct V_115 * V_116 ,
struct V_16 * V_17 )
{
int V_49 = 0 ;
F_97 ( & V_116 -> V_118 ) ;
if ( V_116 -> V_119 == V_17 ) {
V_49 = 1 ;
V_116 -> V_119 = NULL ;
V_116 -> V_121 = V_17 -> V_120 ;
V_116 -> V_122 = V_17 -> V_124 ;
}
F_99 ( & V_116 -> V_118 ) ;
return V_49 ;
}
static void F_101 ( struct V_43 * V_46 ,
struct V_16 * V_17 ,
int V_38 )
{
F_30 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_102 == V_17 )
F_80 ( V_46 , NULL , 0 , V_38 ) ;
F_33 ( & V_46 -> V_53 ) ;
}
static void V_83 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 ,
V_82 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
F_50 ( V_17 , L_19 ) ;
if ( F_100 ( V_17 -> V_72 -> V_116 , V_17 ) ) {
F_102 ( & V_17 -> V_71 ) ;
F_76 ( V_17 , & V_17 -> V_84 ) ;
F_56 ( V_17 ) ;
F_103 ( V_17 -> V_72 , V_131 ) ;
}
F_101 ( V_46 , V_17 , 0 ) ;
F_56 ( V_17 ) ;
}
static int F_104 ( struct V_132 * V_133 , T_1 V_134 ,
T_1 V_135 )
{
int V_49 = memcmp ( & V_133 -> V_136 , & V_135 , sizeof( V_135 ) ) ;
if ( V_49 == 0 )
V_49 = memcmp ( & V_133 -> V_137 , & V_134 , sizeof( V_134 ) ) ;
return V_49 ;
}
static struct V_132 *
F_105 ( T_1 V_134 , T_1 V_135 , struct V_138 * * * V_139 ,
struct V_138 * * V_140 )
{
struct V_138 * * V_141 = & V_142 . V_138 ;
struct V_138 * V_143 = NULL ;
struct V_132 * V_133 , * V_49 = NULL ;
int V_144 ;
while ( * V_141 ) {
V_143 = * V_141 ;
V_133 = F_106 ( V_143 , struct V_132 , V_145 ) ;
V_144 = F_104 ( V_133 , V_134 , V_135 ) ;
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
static void F_107 ( struct V_69 * V_69 )
{
struct V_132 * V_133 ;
V_133 = F_48 ( V_69 , struct V_132 , V_148 ) ;
F_55 ( V_133 ) ;
}
static void F_108 ( struct V_132 * V_133 )
{
F_57 ( & V_133 -> V_148 , F_107 ) ;
}
int F_109 ( T_1 V_134 , T_1 V_135 , T_1 V_149 ,
T_6 * V_150 , void * V_88 ,
T_7 * V_151 ,
struct V_152 * V_153 )
{
struct V_132 * V_133 = NULL ;
struct V_138 * * V_141 , * V_143 ;
int V_49 = 0 ;
if ( V_149 > V_154 ) {
F_45 ( 0 , L_20 ,
V_149 ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( ! V_134 ) {
F_45 ( 0 , L_21 , V_134 , V_150 ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( ! V_150 ) {
F_45 ( 0 , L_22 ,
V_134 , V_150 ) ;
V_49 = - V_155 ;
goto V_64;
}
V_133 = F_62 ( sizeof( struct V_132 ) , V_77 ) ;
if ( V_133 == NULL ) {
V_49 = - V_156 ;
goto V_64;
}
V_133 -> V_157 = V_150 ;
V_133 -> V_158 = V_88 ;
V_133 -> V_159 = V_151 ;
V_133 -> V_137 = V_134 ;
V_133 -> V_160 = V_149 ;
V_133 -> V_136 = V_135 ;
F_63 ( & V_133 -> V_148 ) ;
F_2 ( & V_133 -> V_161 ) ;
F_110 ( & V_162 ) ;
if ( F_105 ( V_134 , V_135 , & V_141 , & V_143 ) )
V_49 = - V_163 ;
else {
F_111 ( & V_133 -> V_145 , V_143 , V_141 ) ;
F_112 ( & V_133 -> V_145 , & V_142 ) ;
F_32 ( & V_133 -> V_161 , V_153 ) ;
F_45 ( V_164 , L_23 ,
V_150 , V_134 , V_135 ) ;
F_83 ( F_105 ( V_134 , V_135 , & V_141 ,
& V_143 ) == NULL ,
L_24
L_25 , V_134 , V_135 ) ;
}
F_113 ( & V_162 ) ;
if ( V_49 )
goto V_64;
V_64:
if ( V_49 )
F_55 ( V_133 ) ;
return V_49 ;
}
void F_114 ( struct V_152 * V_165 )
{
struct V_132 * V_133 , * V_166 ;
F_110 ( & V_162 ) ;
F_44 (nmh, n, list, nh_unregister_item) {
F_45 ( V_164 , L_26 ,
V_133 -> V_157 , V_133 -> V_137 , V_133 -> V_136 ) ;
F_115 ( & V_133 -> V_145 , & V_142 ) ;
F_38 ( & V_133 -> V_161 ) ;
F_57 ( & V_133 -> V_148 , F_107 ) ;
}
F_113 ( & V_162 ) ;
}
static struct V_132 * F_116 ( T_1 V_134 , T_1 V_135 )
{
struct V_132 * V_133 ;
F_92 ( & V_162 ) ;
V_133 = F_105 ( V_134 , V_135 , NULL , NULL ) ;
if ( V_133 )
F_59 ( & V_133 -> V_148 ) ;
F_93 ( & V_162 ) ;
return V_133 ;
}
static int F_117 ( struct V_167 * V_115 , void * V_88 , T_8 V_168 )
{
int V_49 ;
T_9 V_169 ;
struct V_170 V_171 = {
. V_172 = V_168 ,
. V_173 = V_88 ,
} ;
struct V_174 V_175 = {
. V_176 = 1 ,
. V_177 = (struct V_178 * ) & V_171 ,
. V_179 = V_180 ,
} ;
V_169 = F_118 () ;
F_119 ( F_120 () ) ;
V_49 = F_121 ( V_115 , & V_175 , V_168 , V_175 . V_179 ) ;
F_119 ( V_169 ) ;
return V_49 ;
}
static int F_122 ( struct V_167 * V_115 , struct V_170 * V_171 ,
T_8 V_181 , T_8 V_182 )
{
int V_49 ;
T_9 V_169 ;
struct V_174 V_175 = {
. V_177 = (struct V_178 * ) V_171 ,
. V_176 = V_181 ,
} ;
if ( V_115 == NULL ) {
V_49 = - V_155 ;
goto V_64;
}
V_169 = F_118 () ;
F_119 ( F_120 () ) ;
V_49 = F_123 ( V_115 , & V_175 , V_182 ) ;
F_119 ( V_169 ) ;
if ( V_49 != V_182 ) {
F_45 ( V_183 , L_27 , V_49 ,
V_182 ) ;
if ( V_49 >= 0 )
V_49 = - V_184 ;
goto V_64;
}
V_49 = 0 ;
V_64:
if ( V_49 < 0 )
F_45 ( 0 , L_28 , V_49 ) ;
return V_49 ;
}
static void F_124 ( struct V_16 * V_17 ,
void * V_185 ,
T_8 V_186 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
T_10 V_49 ;
while ( 1 ) {
F_125 ( & V_17 -> V_130 ) ;
V_49 = V_17 -> V_72 -> V_187 -> V_188 ( V_17 -> V_72 ,
F_126 ( V_185 ) ,
( long ) V_185 & ~ V_189 ,
V_186 , V_180 ) ;
F_127 ( & V_17 -> V_130 ) ;
if ( V_49 == V_186 )
break;
if ( V_49 == ( T_10 ) - V_52 ) {
F_45 ( 0 , L_29 V_109
L_30 , V_186 , F_87 ( V_17 ) ) ;
F_128 () ;
continue;
}
F_45 ( V_183 , L_29 V_109
L_31 , V_186 , F_87 ( V_17 ) , V_49 ) ;
F_101 ( V_46 , V_17 , 0 ) ;
break;
}
}
static void F_129 ( struct V_190 * V_175 , T_11 V_191 , T_11 V_134 , T_1 V_135 )
{
memset ( V_175 , 0 , sizeof( struct V_190 ) ) ;
V_175 -> V_192 = F_130 ( V_193 ) ;
V_175 -> V_191 = F_130 ( V_191 ) ;
V_175 -> V_134 = F_130 ( V_134 ) ;
V_175 -> V_60 = F_131 ( V_42 ) ;
V_175 -> V_61 = 0 ;
V_175 -> V_135 = F_131 ( V_135 ) ;
}
static int F_132 ( struct V_43 * V_46 ,
struct V_16 * * V_194 ,
int * error )
{
int V_49 = 0 ;
F_30 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_100 ) {
V_49 = 1 ;
* V_194 = NULL ;
* error = V_46 -> V_100 ;
} else if ( V_46 -> V_98 ) {
F_59 ( & V_46 -> V_102 -> V_70 ) ;
V_49 = 1 ;
* V_194 = V_46 -> V_102 ;
* error = 0 ;
}
F_33 ( & V_46 -> V_53 ) ;
return V_49 ;
}
int F_133 ( T_1 V_134 , T_1 V_135 , struct V_170 * V_195 ,
T_8 V_196 , T_2 V_197 , int * V_61 )
{
int V_49 = 0 ;
struct V_190 * V_175 = NULL ;
T_8 V_181 , V_198 = 0 ;
struct V_170 * V_171 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 = F_25 ( V_197 ) ;
struct V_47 V_48 = {
. V_55 = F_134 ( V_48 . V_55 ) ,
} ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_134 , V_135 , V_199 , V_197 ) ;
if ( V_92 == NULL ) {
F_45 ( 0 , L_32 ) ;
V_49 = - V_200 ;
goto V_64;
}
if ( V_196 == 0 ) {
F_45 ( 0 , L_33 ) ;
V_49 = - V_155 ;
goto V_64;
}
V_198 = F_135 ( (struct V_178 * ) V_195 , V_196 ) ;
if ( V_198 > V_154 ) {
F_45 ( 0 , L_34 , V_198 ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( V_197 == F_89 () ) {
V_49 = - V_201 ;
goto V_64;
}
F_136 ( & V_2 ) ;
F_3 ( & V_2 ) ;
F_137 ( V_46 -> V_105 , F_132 ( V_46 , & V_17 , & V_49 ) ) ;
if ( V_49 )
goto V_64;
F_7 ( & V_2 , V_17 ) ;
V_181 = V_196 + 1 ;
V_171 = F_138 ( sizeof( struct V_170 ) * V_181 , V_51 ) ;
if ( V_171 == NULL ) {
F_45 ( 0 , L_35 , V_181 ) ;
V_49 = - V_156 ;
goto V_64;
}
V_175 = F_138 ( sizeof( struct V_190 ) , V_51 ) ;
if ( ! V_175 ) {
F_45 ( 0 , L_36 ) ;
V_49 = - V_156 ;
goto V_64;
}
F_129 ( V_175 , V_198 , V_134 , V_135 ) ;
V_171 [ 0 ] . V_172 = sizeof( struct V_190 ) ;
V_171 [ 0 ] . V_173 = V_175 ;
memcpy ( & V_171 [ 1 ] , V_195 , V_196 * sizeof( struct V_170 ) ) ;
V_49 = F_28 ( V_46 , & V_48 ) ;
if ( V_49 )
goto V_64;
V_175 -> V_202 = F_131 ( V_48 . V_54 ) ;
F_8 ( & V_2 , V_48 . V_54 ) ;
F_5 ( & V_2 ) ;
F_125 ( & V_17 -> V_130 ) ;
V_49 = F_122 ( V_17 -> V_72 , V_171 , V_181 ,
sizeof( struct V_190 ) + V_198 ) ;
F_127 ( & V_17 -> V_130 ) ;
F_139 ( V_175 , L_37 , V_49 ) ;
if ( V_49 < 0 ) {
F_45 ( 0 , L_38 , V_49 ) ;
goto V_64;
}
F_6 ( & V_2 ) ;
F_137 ( V_48 . V_57 , F_46 ( V_46 , & V_48 ) ) ;
F_17 ( & V_2 , V_17 ) ;
V_49 = F_23 ( V_48 . V_58 ) ;
if ( V_61 && ! V_49 )
* V_61 = V_48 . V_59 ;
F_45 ( 0 , L_39 ,
V_49 , V_48 . V_59 ) ;
V_64:
F_140 ( & V_2 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_171 )
F_55 ( V_171 ) ;
if ( V_175 )
F_55 ( V_175 ) ;
F_41 ( V_46 , & V_48 , 0 , 0 , 0 ) ;
return V_49 ;
}
int F_141 ( T_1 V_134 , T_1 V_135 , void * V_88 , T_1 V_168 ,
T_2 V_197 , int * V_61 )
{
struct V_170 V_171 = {
. V_173 = V_88 ,
. V_172 = V_168 ,
} ;
return F_133 ( V_134 , V_135 , & V_171 , 1 ,
V_197 , V_61 ) ;
}
static int F_142 ( struct V_167 * V_115 , struct V_190 * V_203 ,
enum V_37 V_204 , int V_38 )
{
struct V_170 V_171 = {
. V_173 = V_203 ,
. V_172 = sizeof( struct V_190 ) ,
} ;
F_24 ( V_204 >= V_40 ) ;
V_203 -> V_60 = F_131 ( V_204 ) ;
V_203 -> V_61 = F_131 ( V_38 ) ;
V_203 -> V_192 = F_130 ( V_205 ) ;
V_203 -> V_191 = 0 ;
F_139 ( V_203 , L_40 , V_38 ) ;
return F_122 ( V_115 , & V_171 , 1 , sizeof( struct V_190 ) ) ;
}
static int F_143 ( struct V_16 * V_17 ,
struct V_190 * V_203 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
int V_49 = 0 , V_206 ;
enum V_37 V_204 ;
struct V_132 * V_133 = NULL ;
void * V_207 = NULL ;
F_139 ( V_203 , L_41 ) ;
F_144 ( V_17 ) ;
switch( F_145 ( V_203 -> V_192 ) ) {
case V_205 :
F_41 ( V_46 , NULL ,
F_146 ( V_203 -> V_202 ) ,
F_146 ( V_203 -> V_60 ) ,
F_146 ( V_203 -> V_61 ) ) ;
goto V_64;
case V_208 :
F_124 ( V_17 , V_209 ,
sizeof( * V_209 ) ) ;
goto V_64;
case V_210 :
goto V_64;
case V_193 :
break;
default:
F_139 ( V_203 , L_42 ) ;
V_49 = - V_155 ;
goto V_64;
break;
}
V_206 = 0 ;
V_133 = F_116 ( F_145 ( V_203 -> V_134 ) ,
F_146 ( V_203 -> V_135 ) ) ;
if ( ! V_133 ) {
F_45 ( V_164 , L_43 ,
F_145 ( V_203 -> V_134 ) , F_146 ( V_203 -> V_135 ) ) ;
V_204 = V_211 ;
goto V_212;
}
V_204 = V_42 ;
if ( F_145 ( V_203 -> V_191 ) > V_133 -> V_160 )
V_204 = V_213 ;
if ( V_204 != V_42 )
goto V_212;
F_13 ( V_17 ) ;
V_17 -> V_214 = F_146 ( V_203 -> V_135 ) ;
V_17 -> V_215 = F_145 ( V_203 -> V_134 ) ;
V_206 = ( V_133 -> V_157 ) ( V_203 , sizeof( struct V_190 ) +
F_145 ( V_203 -> V_191 ) ,
V_133 -> V_158 , & V_207 ) ;
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
V_212:
F_125 ( & V_17 -> V_130 ) ;
V_49 = F_142 ( V_17 -> V_72 , V_203 , V_204 ,
V_206 ) ;
F_127 ( & V_17 -> V_130 ) ;
V_203 = NULL ;
F_45 ( 0 , L_44 ,
V_206 , V_204 , V_49 ) ;
if ( V_133 ) {
F_24 ( V_207 != NULL && V_133 -> V_159 == NULL ) ;
if ( V_133 -> V_159 )
( V_133 -> V_159 ) ( V_206 , V_133 -> V_158 ,
V_207 ) ;
}
V_64:
if ( V_133 )
F_108 ( V_133 ) ;
return V_49 ;
}
static int F_147 ( struct V_16 * V_17 )
{
struct V_216 * V_217 = F_148 ( V_17 -> V_89 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
if ( V_217 -> V_218 != F_149 ( V_219 ) ) {
F_45 ( V_220 , V_109 L_45
L_46 ,
F_87 ( V_17 ) ,
( unsigned long long ) F_150 ( V_217 -> V_218 ) ,
V_219 ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
if ( F_146 ( V_217 -> V_221 ) !=
F_22 () ) {
F_45 ( V_220 , V_109 L_47
L_48 ,
F_87 ( V_17 ) ,
F_146 ( V_217 -> V_221 ) ,
F_22 () ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
if ( F_146 ( V_217 -> V_222 ) !=
F_21 () ) {
F_45 ( V_220 , V_109 L_49
L_48 ,
F_87 ( V_17 ) ,
F_146 ( V_217 -> V_222 ) ,
F_21 () ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
if ( F_146 ( V_217 -> V_223 ) !=
V_224 ) {
F_45 ( V_220 , V_109 L_50
L_48 ,
F_87 ( V_17 ) ,
F_146 ( V_217 -> V_223 ) ,
V_224 ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
V_17 -> V_225 = 1 ;
F_30 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_102 == V_17 ) {
F_151 ( V_17 ) ;
F_152 ( & V_46 -> V_226 , 0 ) ;
F_80 ( V_46 , V_17 , 1 , 0 ) ;
}
F_33 ( & V_46 -> V_53 ) ;
V_17 -> V_227 -= sizeof( struct V_216 ) ;
if ( V_17 -> V_227 )
memmove ( V_217 , V_217 + 1 , V_17 -> V_227 ) ;
return 0 ;
}
static int F_153 ( struct V_16 * V_17 )
{
struct V_190 * V_203 ;
int V_49 = 0 ;
void * V_88 ;
T_8 V_228 ;
F_50 ( V_17 , L_51 ) ;
F_11 ( V_17 ) ;
if ( F_154 ( V_17 -> V_225 == 0 ) ) {
if( V_17 -> V_227 < sizeof( struct V_216 ) ) {
V_88 = F_148 ( V_17 -> V_89 ) + V_17 -> V_227 ;
V_228 = sizeof( struct V_216 ) - V_17 -> V_227 ;
V_49 = F_117 ( V_17 -> V_72 , V_88 , V_228 ) ;
if ( V_49 > 0 )
V_17 -> V_227 += V_49 ;
}
if ( V_17 -> V_227 == sizeof( struct V_216 ) ) {
F_147 ( V_17 ) ;
if ( F_154 ( V_17 -> V_225 == 0 ) )
V_49 = - V_229 ;
}
goto V_64;
}
if ( V_17 -> V_227 < sizeof( struct V_190 ) ) {
V_88 = F_148 ( V_17 -> V_89 ) + V_17 -> V_227 ;
V_228 = sizeof( struct V_190 ) - V_17 -> V_227 ;
V_49 = F_117 ( V_17 -> V_72 , V_88 , V_228 ) ;
if ( V_49 > 0 ) {
V_17 -> V_227 += V_49 ;
if ( V_17 -> V_227 == sizeof( struct V_190 ) ) {
V_203 = F_148 ( V_17 -> V_89 ) ;
if ( F_145 ( V_203 -> V_191 ) >
V_154 )
V_49 = - V_230 ;
}
}
if ( V_49 <= 0 )
goto V_64;
}
if ( V_17 -> V_227 < sizeof( struct V_190 ) ) {
goto V_64;
}
V_203 = F_148 ( V_17 -> V_89 ) ;
F_139 ( V_203 , L_52 , V_17 -> V_227 ) ;
if ( V_17 -> V_227 - sizeof( struct V_190 ) < F_145 ( V_203 -> V_191 ) ) {
V_88 = F_148 ( V_17 -> V_89 ) + V_17 -> V_227 ;
V_228 = ( sizeof( struct V_190 ) + F_145 ( V_203 -> V_191 ) ) -
V_17 -> V_227 ;
V_49 = F_117 ( V_17 -> V_72 , V_88 , V_228 ) ;
if ( V_49 > 0 )
V_17 -> V_227 += V_49 ;
if ( V_49 <= 0 )
goto V_64;
}
if ( V_17 -> V_227 - sizeof( struct V_190 ) == F_145 ( V_203 -> V_191 ) ) {
V_49 = F_143 ( V_17 , V_203 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_17 -> V_227 = 0 ;
}
V_64:
F_50 ( V_17 , L_53 , V_49 ) ;
F_12 ( V_17 ) ;
return V_49 ;
}
static void V_81 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 , V_80 ) ;
int V_49 ;
do {
V_49 = F_153 ( V_17 ) ;
} while ( V_49 > 0 );
if ( V_49 <= 0 && V_49 != - V_52 ) {
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
F_50 ( V_17 , L_54 , V_49 ) ;
F_101 ( V_46 , V_17 , 0 ) ;
}
F_56 ( V_17 ) ;
}
static int F_155 ( struct V_167 * V_115 )
{
int V_49 , V_231 = 1 ;
T_9 V_169 ;
V_169 = F_118 () ;
F_119 ( V_232 ) ;
V_49 = V_115 -> V_187 -> V_233 ( V_115 , V_234 , V_235 ,
( char V_236 * ) & V_231 , sizeof( V_231 ) ) ;
F_119 ( V_169 ) ;
return V_49 ;
}
static void F_156 ( void )
{
V_237 -> V_223 = F_131 (
V_224 ) ;
V_237 -> V_221 = F_131 ( F_22 () ) ;
V_237 -> V_222 = F_131 (
F_21 () ) ;
V_237 -> V_238 = F_131 (
F_20 () ) ;
}
static void V_79 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 ,
V_78 ) ;
F_45 ( V_239 , L_55 ,
( unsigned long long ) V_219 ,
( unsigned long long ) F_150 ( V_237 -> V_240 ) ) ;
F_156 () ;
F_124 ( V_17 , V_237 , sizeof( * V_237 ) ) ;
F_56 ( V_17 ) ;
}
static void V_85 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 ,
V_84 . V_91 ) ;
F_124 ( V_17 , V_241 , sizeof( * V_241 ) ) ;
F_56 ( V_17 ) ;
}
static void V_87 ( unsigned long V_88 )
{
struct V_16 * V_17 = (struct V_16 * ) V_88 ;
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
#ifdef F_157
T_3 V_242 = F_4 () ;
#endif
F_86 ( V_108 L_17 V_109 L_56
L_57 , F_87 ( V_17 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
#ifdef F_157
F_45 ( V_220 , L_58
L_59
L_60 ,
( long long ) F_158 ( V_17 -> V_21 ) , ( long long ) F_158 ( V_242 ) ,
( long long ) F_158 ( V_17 -> V_22 ) ,
( long long ) F_158 ( V_17 -> V_23 ) ,
( long long ) F_158 ( V_17 -> V_24 ) ,
V_17 -> V_214 , V_17 -> V_215 ,
( long long ) F_158 ( V_17 -> V_25 ) ,
( long long ) F_158 ( V_17 -> V_26 ) ) ;
#endif
F_152 ( & V_46 -> V_226 , 1 ) ;
F_72 ( V_17 , & V_17 -> V_82 ) ;
}
static void F_151 ( struct V_16 * V_17 )
{
F_76 ( V_17 , & V_17 -> V_84 ) ;
F_74 ( V_17 , & V_17 -> V_84 ,
F_85 ( F_21 () ) ) ;
F_9 ( V_17 ) ;
F_159 ( & V_17 -> V_71 ,
V_113 + F_85 ( F_22 () ) ) ;
}
static void F_144 ( struct V_16 * V_17 )
{
if ( F_49 ( & V_17 -> V_71 ) )
F_151 ( V_17 ) ;
}
static void F_160 ( struct V_90 * V_91 )
{
struct V_43 * V_46 =
F_48 ( V_91 , struct V_43 , V_114 . V_91 ) ;
struct V_16 * V_17 = NULL ;
struct V_75 * V_7 = NULL , * V_243 = NULL ;
struct V_167 * V_115 = NULL ;
struct V_244 V_245 = { 0 , } , V_246 = { 0 , } ;
int V_49 = 0 , V_247 ;
unsigned int V_248 ;
if ( F_89 () <= F_27 ( V_46 ) )
goto V_64;
V_7 = F_161 ( F_27 ( V_46 ) ) ;
if ( V_7 == NULL ) {
V_49 = 0 ;
goto V_64;
}
V_243 = F_161 ( F_89 () ) ;
if ( V_243 == NULL ) {
V_49 = 0 ;
goto V_64;
}
F_30 ( & V_46 -> V_53 ) ;
V_248 = F_79 ( & V_46 -> V_226 ) ;
V_247 = ( V_46 -> V_102 ||
( V_46 -> V_100 &&
( V_46 -> V_100 != - V_103 || V_248 == 0 ) ) ) ;
F_33 ( & V_46 -> V_53 ) ;
if ( V_247 )
goto V_64;
V_46 -> V_112 = V_113 ;
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
F_45 ( 0 , L_61 ) ;
V_49 = - V_156 ;
goto V_64;
}
V_49 = F_162 ( V_249 , V_250 , V_251 , & V_115 ) ;
if ( V_49 < 0 ) {
F_45 ( 0 , L_62 , V_49 ) ;
goto V_64;
}
V_17 -> V_72 = V_115 ;
V_115 -> V_116 -> V_252 = V_51 ;
V_245 . V_253 = V_254 ;
V_245 . V_255 . V_256 = V_243 -> V_257 ;
V_245 . V_258 = F_163 ( 0 ) ;
V_49 = V_115 -> V_187 -> V_259 ( V_115 , (struct V_260 * ) & V_245 ,
sizeof( V_245 ) ) ;
if ( V_49 ) {
F_45 ( V_183 , L_63 ,
V_49 , & V_243 -> V_257 ) ;
goto V_64;
}
V_49 = F_155 ( V_17 -> V_72 ) ;
if ( V_49 ) {
F_45 ( V_183 , L_64 , V_49 ) ;
goto V_64;
}
F_96 ( V_17 -> V_72 -> V_116 , V_17 ) ;
F_30 ( & V_46 -> V_53 ) ;
F_80 ( V_46 , V_17 , 0 , 0 ) ;
F_33 ( & V_46 -> V_53 ) ;
V_246 . V_253 = V_254 ;
V_246 . V_255 . V_256 = V_7 -> V_257 ;
V_246 . V_258 = V_7 -> V_261 ;
V_49 = V_17 -> V_72 -> V_187 -> V_262 ( V_17 -> V_72 ,
(struct V_260 * ) & V_246 ,
sizeof( V_246 ) ,
V_263 ) ;
if ( V_49 == - V_264 )
V_49 = 0 ;
V_64:
if ( V_49 ) {
F_45 ( V_220 , L_65 V_109 L_66
L_67 , F_87 ( V_17 ) , V_49 ) ;
if ( V_17 )
F_101 ( V_46 , V_17 , 0 ) ;
}
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_7 )
F_53 ( V_7 ) ;
if ( V_243 )
F_53 ( V_243 ) ;
return;
}
static void F_164 ( struct V_90 * V_91 )
{
struct V_43 * V_46 =
F_48 ( V_91 , struct V_43 , V_110 . V_91 ) ;
F_30 ( & V_46 -> V_53 ) ;
if ( ! V_46 -> V_98 ) {
F_45 ( V_183 , L_68
L_69 ,
F_27 ( V_46 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
F_80 ( V_46 , NULL , 0 , - V_103 ) ;
}
F_33 ( & V_46 -> V_53 ) ;
}
static void F_165 ( struct V_90 * V_91 )
{
struct V_43 * V_46 =
F_48 ( V_91 , struct V_43 , V_106 . V_91 ) ;
F_166 ( F_27 ( V_46 ) ) ;
}
void F_167 ( struct V_75 * V_7 )
{
struct V_43 * V_46 = F_25 ( V_7 -> V_111 ) ;
F_30 ( & V_46 -> V_53 ) ;
F_152 ( & V_46 -> V_226 , 0 ) ;
F_80 ( V_46 , NULL , 0 , - V_103 ) ;
F_33 ( & V_46 -> V_53 ) ;
if ( V_92 ) {
F_77 ( & V_46 -> V_110 ) ;
F_77 ( & V_46 -> V_114 ) ;
F_77 ( & V_46 -> V_106 ) ;
F_168 ( V_92 ) ;
}
}
static void F_169 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
F_170 ( V_44 ) ;
if ( ! V_7 )
return;
if ( V_44 != F_89 () )
F_167 ( V_7 ) ;
F_24 ( F_79 ( & V_95 ) < 0 ) ;
}
static void F_171 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
struct V_43 * V_46 = F_25 ( V_44 ) ;
F_172 ( V_44 ) ;
F_24 ( ! V_7 ) ;
V_46 -> V_112 = V_113 -
( F_85 ( F_20 () ) + 1 ) ;
if ( V_44 != F_89 () ) {
F_30 ( & V_46 -> V_53 ) ;
F_152 ( & V_46 -> V_226 , 0 ) ;
if ( V_46 -> V_100 )
F_80 ( V_46 , NULL , 0 , 0 ) ;
F_33 ( & V_46 -> V_53 ) ;
}
}
void F_173 ( void )
{
F_174 ( NULL , & V_265 ) ;
F_174 ( NULL , & V_266 ) ;
}
int F_175 ( void )
{
int V_49 ;
F_176 ( & V_266 , V_267 ,
F_169 , NULL , V_268 ) ;
F_176 ( & V_265 , V_269 ,
F_171 , NULL , V_268 ) ;
V_49 = F_177 ( NULL , & V_265 ) ;
if ( V_49 == 0 )
V_49 = F_177 ( NULL , & V_266 ) ;
if ( V_49 )
F_173 () ;
return V_49 ;
}
static int F_178 ( struct V_167 * V_115 )
{
int V_49 , V_270 ;
struct V_244 sin ;
struct V_167 * V_271 = NULL ;
struct V_75 * V_7 = NULL ;
struct V_75 * V_272 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 ;
F_24 ( V_115 == NULL ) ;
V_49 = F_179 ( V_115 -> V_116 -> V_273 , V_115 -> V_116 -> V_274 ,
V_115 -> V_116 -> V_275 , & V_271 ) ;
if ( V_49 )
goto V_64;
V_271 -> type = V_115 -> type ;
V_271 -> V_187 = V_115 -> V_187 ;
V_49 = V_115 -> V_187 -> V_276 ( V_115 , V_271 , V_263 ) ;
if ( V_49 < 0 )
goto V_64;
V_271 -> V_116 -> V_252 = V_51 ;
V_49 = F_155 ( V_271 ) ;
if ( V_49 ) {
F_45 ( V_183 , L_64 , V_49 ) ;
goto V_64;
}
V_270 = sizeof( sin ) ;
V_49 = V_271 -> V_187 -> V_277 ( V_271 , (struct V_260 * ) & sin ,
& V_270 , 1 ) ;
if ( V_49 < 0 )
goto V_64;
V_7 = F_180 ( sin . V_255 . V_256 ) ;
if ( V_7 == NULL ) {
F_45 ( V_220 , L_70 ,
& sin . V_255 . V_256 , F_181 ( sin . V_258 ) ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( F_89 () >= V_7 -> V_111 ) {
V_272 = F_161 ( F_89 () ) ;
F_45 ( V_220 , L_71
L_72 ,
V_272 -> V_278 , V_272 -> V_111 ,
& ( V_272 -> V_257 ) ,
F_181 ( V_272 -> V_261 ) ,
V_7 -> V_278 , V_7 -> V_111 , & sin . V_255 . V_256 ,
F_181 ( sin . V_258 ) ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( ! F_182 ( V_7 -> V_111 ) ) {
F_45 ( V_104 , L_73
L_74 ,
V_7 -> V_278 , & sin . V_255 . V_256 ,
F_181 ( sin . V_258 ) ) ;
V_49 = - V_155 ;
goto V_64;
}
V_46 = F_25 ( V_7 -> V_111 ) ;
F_30 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_102 )
V_49 = - V_279 ;
else
V_49 = 0 ;
F_33 ( & V_46 -> V_53 ) ;
if ( V_49 ) {
F_45 ( V_220 , L_73
L_75 ,
V_7 -> V_278 , & sin . V_255 . V_256 ,
F_181 ( sin . V_258 ) ) ;
goto V_64;
}
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
V_49 = - V_156 ;
goto V_64;
}
V_17 -> V_72 = V_271 ;
V_271 = NULL ;
F_30 ( & V_46 -> V_53 ) ;
F_152 ( & V_46 -> V_226 , 0 ) ;
F_80 ( V_46 , V_17 , 0 , 0 ) ;
F_33 ( & V_46 -> V_53 ) ;
F_96 ( V_17 -> V_72 -> V_116 , V_17 ) ;
F_72 ( V_17 , & V_17 -> V_80 ) ;
F_156 () ;
F_124 ( V_17 , V_237 , sizeof( * V_237 ) ) ;
V_64:
if ( V_271 )
F_51 ( V_271 ) ;
if ( V_7 )
F_53 ( V_7 ) ;
if ( V_272 )
F_53 ( V_272 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
return V_49 ;
}
static void F_183 ( struct V_90 * V_91 )
{
struct V_167 * V_115 = V_280 ;
while ( F_178 ( V_115 ) == 0 )
F_128 () ;
}
static void V_129 ( struct V_115 * V_116 , int V_117 )
{
void (* F_91)( struct V_115 * V_116 , int V_117 );
F_92 ( & V_116 -> V_118 ) ;
F_91 = V_116 -> V_119 ;
if ( F_91 == NULL ) {
F_91 = V_116 -> V_121 ;
goto V_64;
}
if ( V_116 -> V_123 == V_281 ) {
F_45 ( V_164 , L_76 , V_117 ) ;
F_73 ( V_92 , & V_282 ) ;
}
V_64:
F_93 ( & V_116 -> V_118 ) ;
F_91 ( V_116 , V_117 ) ;
}
static int F_184 ( T_12 V_283 , T_13 V_284 )
{
struct V_167 * V_115 = NULL ;
int V_49 ;
struct V_244 sin = {
. V_253 = V_249 ,
. V_255 = { . V_256 = V_283 } ,
. V_258 = V_284 ,
} ;
V_49 = F_162 ( V_249 , V_250 , V_251 , & V_115 ) ;
if ( V_49 < 0 ) {
F_45 ( V_183 , L_77 , V_49 ) ;
goto V_64;
}
V_115 -> V_116 -> V_252 = V_51 ;
F_97 ( & V_115 -> V_116 -> V_118 ) ;
V_115 -> V_116 -> V_119 = V_115 -> V_116 -> V_121 ;
V_115 -> V_116 -> V_121 = V_129 ;
F_99 ( & V_115 -> V_116 -> V_118 ) ;
V_280 = V_115 ;
F_67 ( & V_282 , F_183 ) ;
V_115 -> V_116 -> V_285 = 1 ;
V_49 = V_115 -> V_187 -> V_259 ( V_115 , (struct V_260 * ) & sin , sizeof( sin ) ) ;
if ( V_49 < 0 ) {
F_45 ( V_183 , L_78
L_79 , & V_283 , F_181 ( V_284 ) , V_49 ) ;
goto V_64;
}
V_49 = V_115 -> V_187 -> V_286 ( V_115 , 64 ) ;
if ( V_49 < 0 ) {
F_45 ( V_183 , L_80 ,
& V_283 , F_181 ( V_284 ) , V_49 ) ;
}
V_64:
if ( V_49 ) {
V_280 = NULL ;
if ( V_115 )
F_51 ( V_115 ) ;
}
return V_49 ;
}
int F_185 ( struct V_75 * V_7 )
{
int V_49 = 0 ;
F_24 ( V_92 != NULL ) ;
F_24 ( V_280 != NULL ) ;
F_45 ( V_287 , L_81 ) ;
V_92 = F_186 ( L_82 ) ;
if ( V_92 == NULL ) {
F_45 ( V_183 , L_83 ) ;
return - V_156 ;
}
V_49 = F_184 ( V_7 -> V_257 ,
V_7 -> V_261 ) ;
if ( V_49 ) {
F_187 ( V_92 ) ;
V_92 = NULL ;
} else
F_88 ( V_7 -> V_111 ) ;
return V_49 ;
}
void F_188 ( struct V_75 * V_7 )
{
struct V_167 * V_115 = V_280 ;
T_8 V_288 ;
F_24 ( V_92 == NULL ) ;
F_24 ( V_280 == NULL ) ;
F_97 ( & V_115 -> V_116 -> V_118 ) ;
V_115 -> V_116 -> V_121 = V_115 -> V_116 -> V_119 ;
V_115 -> V_116 -> V_119 = NULL ;
F_99 ( & V_115 -> V_116 -> V_118 ) ;
for ( V_288 = 0 ; V_288 < F_26 ( V_45 ) ; V_288 ++ ) {
struct V_75 * V_7 = F_161 ( V_288 ) ;
if ( V_7 ) {
F_167 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
F_45 ( V_287 , L_84 ) ;
F_187 ( V_92 ) ;
V_92 = NULL ;
F_51 ( V_280 ) ;
V_280 = NULL ;
F_84 ( V_7 -> V_111 ) ;
}
int F_189 ( void )
{
unsigned long V_288 ;
F_190 () ;
if ( F_191 () )
return - V_156 ;
V_237 = F_62 ( sizeof( struct V_216 ) , V_289 ) ;
V_241 = F_62 ( sizeof( struct V_190 ) , V_289 ) ;
V_209 = F_62 ( sizeof( struct V_190 ) , V_289 ) ;
if ( ! V_237 || ! V_241 || ! V_209 ) {
F_55 ( V_237 ) ;
F_55 ( V_241 ) ;
F_55 ( V_209 ) ;
return - V_156 ;
}
V_237 -> V_218 = F_149 ( V_219 ) ;
V_237 -> V_240 = F_149 ( 1 ) ;
V_241 -> V_192 = F_130 ( V_208 ) ;
V_209 -> V_192 = F_130 ( V_210 ) ;
for ( V_288 = 0 ; V_288 < F_26 ( V_45 ) ; V_288 ++ ) {
struct V_43 * V_46 = F_25 ( V_288 ) ;
F_152 ( & V_46 -> V_226 , 0 ) ;
F_192 ( & V_46 -> V_53 ) ;
F_68 ( & V_46 -> V_114 , F_160 ) ;
F_68 ( & V_46 -> V_110 ,
F_164 ) ;
F_68 ( & V_46 -> V_106 , F_165 ) ;
V_46 -> V_100 = - V_103 ;
F_34 ( & V_46 -> V_105 ) ;
F_193 ( & V_46 -> V_50 ) ;
F_2 ( & V_46 -> V_56 ) ;
}
return 0 ;
}
void F_194 ( void )
{
F_195 () ;
F_55 ( V_237 ) ;
F_55 ( V_241 ) ;
F_55 ( V_209 ) ;
F_196 () ;
}
