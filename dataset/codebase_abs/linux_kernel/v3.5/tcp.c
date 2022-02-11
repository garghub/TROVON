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
void F_133 ( unsigned long * V_195 , unsigned V_117 )
{
struct V_16 * V_17 ;
int V_7 , V_49 ;
F_24 ( V_117 < ( F_134 ( V_196 ) * sizeof( unsigned long ) ) ) ;
memset ( V_195 , 0 , V_117 ) ;
for ( V_7 = 0 ; V_7 < V_196 ; ++ V_7 ) {
F_132 ( F_25 ( V_7 ) , & V_17 , & V_49 ) ;
if ( ! V_49 ) {
F_135 ( V_7 , V_195 ) ;
F_56 ( V_17 ) ;
}
}
}
int F_136 ( T_1 V_134 , T_1 V_135 , struct V_170 * V_197 ,
T_8 V_198 , T_2 V_199 , int * V_61 )
{
int V_49 = 0 ;
struct V_190 * V_175 = NULL ;
T_8 V_181 , V_200 = 0 ;
struct V_170 * V_171 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 = F_25 ( V_199 ) ;
struct V_47 V_48 = {
. V_55 = F_137 ( V_48 . V_55 ) ,
} ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_134 , V_135 , V_201 , V_199 ) ;
if ( V_92 == NULL ) {
F_45 ( 0 , L_32 ) ;
V_49 = - V_202 ;
goto V_64;
}
if ( V_198 == 0 ) {
F_45 ( 0 , L_33 ) ;
V_49 = - V_155 ;
goto V_64;
}
V_200 = F_138 ( (struct V_178 * ) V_197 , V_198 ) ;
if ( V_200 > V_154 ) {
F_45 ( 0 , L_34 , V_200 ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( V_199 == F_89 () ) {
V_49 = - V_203 ;
goto V_64;
}
F_139 ( & V_2 ) ;
F_3 ( & V_2 ) ;
F_140 ( V_46 -> V_105 , F_132 ( V_46 , & V_17 , & V_49 ) ) ;
if ( V_49 )
goto V_64;
F_7 ( & V_2 , V_17 ) ;
V_181 = V_198 + 1 ;
V_171 = F_141 ( sizeof( struct V_170 ) * V_181 , V_51 ) ;
if ( V_171 == NULL ) {
F_45 ( 0 , L_35 , V_181 ) ;
V_49 = - V_156 ;
goto V_64;
}
V_175 = F_141 ( sizeof( struct V_190 ) , V_51 ) ;
if ( ! V_175 ) {
F_45 ( 0 , L_36 ) ;
V_49 = - V_156 ;
goto V_64;
}
F_129 ( V_175 , V_200 , V_134 , V_135 ) ;
V_171 [ 0 ] . V_172 = sizeof( struct V_190 ) ;
V_171 [ 0 ] . V_173 = V_175 ;
memcpy ( & V_171 [ 1 ] , V_197 , V_198 * sizeof( struct V_170 ) ) ;
V_49 = F_28 ( V_46 , & V_48 ) ;
if ( V_49 )
goto V_64;
V_175 -> V_204 = F_131 ( V_48 . V_54 ) ;
F_8 ( & V_2 , V_48 . V_54 ) ;
F_5 ( & V_2 ) ;
F_125 ( & V_17 -> V_130 ) ;
V_49 = F_122 ( V_17 -> V_72 , V_171 , V_181 ,
sizeof( struct V_190 ) + V_200 ) ;
F_127 ( & V_17 -> V_130 ) ;
F_142 ( V_175 , L_37 , V_49 ) ;
if ( V_49 < 0 ) {
F_45 ( 0 , L_38 , V_49 ) ;
goto V_64;
}
F_6 ( & V_2 ) ;
F_140 ( V_48 . V_57 , F_46 ( V_46 , & V_48 ) ) ;
F_17 ( & V_2 , V_17 ) ;
V_49 = F_23 ( V_48 . V_58 ) ;
if ( V_61 && ! V_49 )
* V_61 = V_48 . V_59 ;
F_45 ( 0 , L_39 ,
V_49 , V_48 . V_59 ) ;
V_64:
F_143 ( & V_2 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_171 )
F_55 ( V_171 ) ;
if ( V_175 )
F_55 ( V_175 ) ;
F_41 ( V_46 , & V_48 , 0 , 0 , 0 ) ;
return V_49 ;
}
int F_144 ( T_1 V_134 , T_1 V_135 , void * V_88 , T_1 V_168 ,
T_2 V_199 , int * V_61 )
{
struct V_170 V_171 = {
. V_173 = V_88 ,
. V_172 = V_168 ,
} ;
return F_136 ( V_134 , V_135 , & V_171 , 1 ,
V_199 , V_61 ) ;
}
static int F_145 ( struct V_167 * V_115 , struct V_190 * V_205 ,
enum V_37 V_206 , int V_38 )
{
struct V_170 V_171 = {
. V_173 = V_205 ,
. V_172 = sizeof( struct V_190 ) ,
} ;
F_24 ( V_206 >= V_40 ) ;
V_205 -> V_60 = F_131 ( V_206 ) ;
V_205 -> V_61 = F_131 ( V_38 ) ;
V_205 -> V_192 = F_130 ( V_207 ) ;
V_205 -> V_191 = 0 ;
F_142 ( V_205 , L_40 , V_38 ) ;
return F_122 ( V_115 , & V_171 , 1 , sizeof( struct V_190 ) ) ;
}
static int F_146 ( struct V_16 * V_17 ,
struct V_190 * V_205 )
{
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
int V_49 = 0 , V_208 ;
enum V_37 V_206 ;
struct V_132 * V_133 = NULL ;
void * V_209 = NULL ;
F_142 ( V_205 , L_41 ) ;
F_147 ( V_17 ) ;
switch( F_148 ( V_205 -> V_192 ) ) {
case V_207 :
F_41 ( V_46 , NULL ,
F_149 ( V_205 -> V_204 ) ,
F_149 ( V_205 -> V_60 ) ,
F_149 ( V_205 -> V_61 ) ) ;
goto V_64;
case V_210 :
F_124 ( V_17 , V_211 ,
sizeof( * V_211 ) ) ;
goto V_64;
case V_212 :
goto V_64;
case V_193 :
break;
default:
F_142 ( V_205 , L_42 ) ;
V_49 = - V_155 ;
goto V_64;
break;
}
V_208 = 0 ;
V_133 = F_116 ( F_148 ( V_205 -> V_134 ) ,
F_149 ( V_205 -> V_135 ) ) ;
if ( ! V_133 ) {
F_45 ( V_164 , L_43 ,
F_148 ( V_205 -> V_134 ) , F_149 ( V_205 -> V_135 ) ) ;
V_206 = V_213 ;
goto V_214;
}
V_206 = V_42 ;
if ( F_148 ( V_205 -> V_191 ) > V_133 -> V_160 )
V_206 = V_215 ;
if ( V_206 != V_42 )
goto V_214;
F_13 ( V_17 ) ;
V_17 -> V_216 = F_149 ( V_205 -> V_135 ) ;
V_17 -> V_217 = F_148 ( V_205 -> V_134 ) ;
V_208 = ( V_133 -> V_157 ) ( V_205 , sizeof( struct V_190 ) +
F_148 ( V_205 -> V_191 ) ,
V_133 -> V_158 , & V_209 ) ;
F_14 ( V_17 ) ;
F_19 ( V_17 ) ;
V_214:
F_125 ( & V_17 -> V_130 ) ;
V_49 = F_145 ( V_17 -> V_72 , V_205 , V_206 ,
V_208 ) ;
F_127 ( & V_17 -> V_130 ) ;
V_205 = NULL ;
F_45 ( 0 , L_44 ,
V_208 , V_206 , V_49 ) ;
if ( V_133 ) {
F_24 ( V_209 != NULL && V_133 -> V_159 == NULL ) ;
if ( V_133 -> V_159 )
( V_133 -> V_159 ) ( V_208 , V_133 -> V_158 ,
V_209 ) ;
}
V_64:
if ( V_133 )
F_108 ( V_133 ) ;
return V_49 ;
}
static int F_150 ( struct V_16 * V_17 )
{
struct V_218 * V_219 = F_151 ( V_17 -> V_89 ) ;
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
if ( V_219 -> V_220 != F_152 ( V_221 ) ) {
F_86 ( V_108 L_45 V_109 L_46
L_47
L_48 , F_87 ( V_17 ) ,
( unsigned long long ) F_153 ( V_219 -> V_220 ) ,
V_221 ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
if ( F_149 ( V_219 -> V_222 ) !=
F_22 () ) {
F_86 ( V_108 L_45 V_109 L_49
L_50
L_48 , F_87 ( V_17 ) ,
F_149 ( V_219 -> V_222 ) ,
F_22 () ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
if ( F_149 ( V_219 -> V_223 ) !=
F_21 () ) {
F_86 ( V_108 L_45 V_109 L_51
L_52
L_48 , F_87 ( V_17 ) ,
F_149 ( V_219 -> V_223 ) ,
F_21 () ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
if ( F_149 ( V_219 -> V_224 ) !=
V_225 ) {
F_86 ( V_108 L_45 V_109 L_53
L_54
L_48 , F_87 ( V_17 ) ,
F_149 ( V_219 -> V_224 ) ,
V_225 ) ;
F_101 ( V_46 , V_17 , - V_103 ) ;
return - 1 ;
}
V_17 -> V_226 = 1 ;
F_30 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_102 == V_17 ) {
F_154 ( V_17 ) ;
F_155 ( & V_46 -> V_227 , 0 ) ;
F_80 ( V_46 , V_17 , 1 , 0 ) ;
}
F_33 ( & V_46 -> V_53 ) ;
V_17 -> V_228 -= sizeof( struct V_218 ) ;
if ( V_17 -> V_228 )
memmove ( V_219 , V_219 + 1 , V_17 -> V_228 ) ;
return 0 ;
}
static int F_156 ( struct V_16 * V_17 )
{
struct V_190 * V_205 ;
int V_49 = 0 ;
void * V_88 ;
T_8 V_229 ;
F_50 ( V_17 , L_55 ) ;
F_11 ( V_17 ) ;
if ( F_157 ( V_17 -> V_226 == 0 ) ) {
if( V_17 -> V_228 < sizeof( struct V_218 ) ) {
V_88 = F_151 ( V_17 -> V_89 ) + V_17 -> V_228 ;
V_229 = sizeof( struct V_218 ) - V_17 -> V_228 ;
V_49 = F_117 ( V_17 -> V_72 , V_88 , V_229 ) ;
if ( V_49 > 0 )
V_17 -> V_228 += V_49 ;
}
if ( V_17 -> V_228 == sizeof( struct V_218 ) ) {
F_150 ( V_17 ) ;
if ( F_157 ( V_17 -> V_226 == 0 ) )
V_49 = - V_230 ;
}
goto V_64;
}
if ( V_17 -> V_228 < sizeof( struct V_190 ) ) {
V_88 = F_151 ( V_17 -> V_89 ) + V_17 -> V_228 ;
V_229 = sizeof( struct V_190 ) - V_17 -> V_228 ;
V_49 = F_117 ( V_17 -> V_72 , V_88 , V_229 ) ;
if ( V_49 > 0 ) {
V_17 -> V_228 += V_49 ;
if ( V_17 -> V_228 == sizeof( struct V_190 ) ) {
V_205 = F_151 ( V_17 -> V_89 ) ;
if ( F_148 ( V_205 -> V_191 ) >
V_154 )
V_49 = - V_231 ;
}
}
if ( V_49 <= 0 )
goto V_64;
}
if ( V_17 -> V_228 < sizeof( struct V_190 ) ) {
goto V_64;
}
V_205 = F_151 ( V_17 -> V_89 ) ;
F_142 ( V_205 , L_56 , V_17 -> V_228 ) ;
if ( V_17 -> V_228 - sizeof( struct V_190 ) < F_148 ( V_205 -> V_191 ) ) {
V_88 = F_151 ( V_17 -> V_89 ) + V_17 -> V_228 ;
V_229 = ( sizeof( struct V_190 ) + F_148 ( V_205 -> V_191 ) ) -
V_17 -> V_228 ;
V_49 = F_117 ( V_17 -> V_72 , V_88 , V_229 ) ;
if ( V_49 > 0 )
V_17 -> V_228 += V_49 ;
if ( V_49 <= 0 )
goto V_64;
}
if ( V_17 -> V_228 - sizeof( struct V_190 ) == F_148 ( V_205 -> V_191 ) ) {
V_49 = F_146 ( V_17 , V_205 ) ;
if ( V_49 == 0 )
V_49 = 1 ;
V_17 -> V_228 = 0 ;
}
V_64:
F_50 ( V_17 , L_57 , V_49 ) ;
F_12 ( V_17 ) ;
return V_49 ;
}
static void V_81 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 , V_80 ) ;
int V_49 ;
do {
V_49 = F_156 ( V_17 ) ;
} while ( V_49 > 0 );
if ( V_49 <= 0 && V_49 != - V_52 ) {
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
F_50 ( V_17 , L_58 , V_49 ) ;
F_101 ( V_46 , V_17 , 0 ) ;
}
F_56 ( V_17 ) ;
}
static int F_158 ( struct V_167 * V_115 )
{
int V_49 , V_232 = 1 ;
T_9 V_169 ;
V_169 = F_118 () ;
F_119 ( V_233 ) ;
V_49 = V_115 -> V_187 -> V_234 ( V_115 , V_235 , V_236 ,
( char V_237 * ) & V_232 , sizeof( V_232 ) ) ;
F_119 ( V_169 ) ;
return V_49 ;
}
static void F_159 ( void )
{
V_238 -> V_224 = F_131 (
V_225 ) ;
V_238 -> V_222 = F_131 ( F_22 () ) ;
V_238 -> V_223 = F_131 (
F_21 () ) ;
V_238 -> V_239 = F_131 (
F_20 () ) ;
}
static void V_79 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 ,
V_78 ) ;
F_45 ( V_240 , L_59 ,
( unsigned long long ) V_221 ,
( unsigned long long ) F_153 ( V_238 -> V_241 ) ) ;
F_159 () ;
F_124 ( V_17 , V_238 , sizeof( * V_238 ) ) ;
F_56 ( V_17 ) ;
}
static void V_85 ( struct V_90 * V_91 )
{
struct V_16 * V_17 =
F_48 ( V_91 , struct V_16 ,
V_84 . V_91 ) ;
F_124 ( V_17 , V_242 , sizeof( * V_242 ) ) ;
F_56 ( V_17 ) ;
}
static void V_87 ( unsigned long V_88 )
{
struct V_16 * V_17 = (struct V_16 * ) V_88 ;
struct V_43 * V_46 = F_25 ( V_17 -> V_73 -> V_111 ) ;
#ifdef F_160
unsigned long V_243 = F_161 ( F_4 () ) -
F_161 ( V_17 -> V_21 ) ;
#else
unsigned long V_243 = F_22 () ;
#endif
F_86 ( V_108 L_17 V_109 L_60
L_61 , F_87 ( V_17 ) ,
V_243 / 1000 , V_243 % 1000 ) ;
F_155 ( & V_46 -> V_227 , 1 ) ;
F_72 ( V_17 , & V_17 -> V_82 ) ;
}
static void F_154 ( struct V_16 * V_17 )
{
F_76 ( V_17 , & V_17 -> V_84 ) ;
F_74 ( V_17 , & V_17 -> V_84 ,
F_85 ( F_21 () ) ) ;
F_9 ( V_17 ) ;
F_162 ( & V_17 -> V_71 ,
V_113 + F_85 ( F_22 () ) ) ;
}
static void F_147 ( struct V_16 * V_17 )
{
if ( F_49 ( & V_17 -> V_71 ) )
F_154 ( V_17 ) ;
}
static void F_163 ( struct V_90 * V_91 )
{
struct V_43 * V_46 =
F_48 ( V_91 , struct V_43 , V_114 . V_91 ) ;
struct V_16 * V_17 = NULL ;
struct V_75 * V_7 = NULL , * V_244 = NULL ;
struct V_167 * V_115 = NULL ;
struct V_245 V_246 = { 0 , } , V_247 = { 0 , } ;
int V_49 = 0 , V_248 ;
unsigned int V_249 ;
if ( F_89 () <= F_27 ( V_46 ) )
goto V_64;
V_7 = F_164 ( F_27 ( V_46 ) ) ;
if ( V_7 == NULL ) {
V_49 = 0 ;
goto V_64;
}
V_244 = F_164 ( F_89 () ) ;
if ( V_244 == NULL ) {
V_49 = 0 ;
goto V_64;
}
F_30 ( & V_46 -> V_53 ) ;
V_249 = F_79 ( & V_46 -> V_227 ) ;
V_248 = ( V_46 -> V_102 ||
( V_46 -> V_100 &&
( V_46 -> V_100 != - V_103 || V_249 == 0 ) ) ) ;
F_33 ( & V_46 -> V_53 ) ;
if ( V_248 )
goto V_64;
V_46 -> V_112 = V_113 ;
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
F_45 ( 0 , L_62 ) ;
V_49 = - V_156 ;
goto V_64;
}
V_49 = F_165 ( V_250 , V_251 , V_252 , & V_115 ) ;
if ( V_49 < 0 ) {
F_45 ( 0 , L_63 , V_49 ) ;
goto V_64;
}
V_17 -> V_72 = V_115 ;
V_115 -> V_116 -> V_253 = V_51 ;
V_246 . V_254 = V_255 ;
V_246 . V_256 . V_257 = V_244 -> V_258 ;
V_246 . V_259 = F_166 ( 0 ) ;
V_49 = V_115 -> V_187 -> V_260 ( V_115 , (struct V_261 * ) & V_246 ,
sizeof( V_246 ) ) ;
if ( V_49 ) {
F_45 ( V_183 , L_64 ,
V_49 , & V_244 -> V_258 ) ;
goto V_64;
}
V_49 = F_158 ( V_17 -> V_72 ) ;
if ( V_49 ) {
F_45 ( V_183 , L_65 , V_49 ) ;
goto V_64;
}
F_96 ( V_17 -> V_72 -> V_116 , V_17 ) ;
F_30 ( & V_46 -> V_53 ) ;
F_80 ( V_46 , V_17 , 0 , 0 ) ;
F_33 ( & V_46 -> V_53 ) ;
V_247 . V_254 = V_255 ;
V_247 . V_256 . V_257 = V_7 -> V_258 ;
V_247 . V_259 = V_7 -> V_262 ;
V_49 = V_17 -> V_72 -> V_187 -> V_263 ( V_17 -> V_72 ,
(struct V_261 * ) & V_247 ,
sizeof( V_247 ) ,
V_264 ) ;
if ( V_49 == - V_265 )
V_49 = 0 ;
V_64:
if ( V_49 ) {
F_86 ( V_108 L_66 V_109
L_67 , F_87 ( V_17 ) , V_49 ) ;
if ( V_17 )
F_101 ( V_46 , V_17 , 0 ) ;
}
if ( V_17 )
F_56 ( V_17 ) ;
if ( V_7 )
F_53 ( V_7 ) ;
if ( V_244 )
F_53 ( V_244 ) ;
return;
}
static void F_167 ( struct V_90 * V_91 )
{
struct V_43 * V_46 =
F_48 ( V_91 , struct V_43 , V_110 . V_91 ) ;
F_30 ( & V_46 -> V_53 ) ;
if ( ! V_46 -> V_98 ) {
F_86 ( V_108 L_68
L_69 ,
F_27 ( V_46 ) ,
F_22 () / 1000 ,
F_22 () % 1000 ) ;
F_80 ( V_46 , NULL , 0 , - V_103 ) ;
}
F_33 ( & V_46 -> V_53 ) ;
}
static void F_168 ( struct V_90 * V_91 )
{
struct V_43 * V_46 =
F_48 ( V_91 , struct V_43 , V_106 . V_91 ) ;
F_169 ( F_27 ( V_46 ) ) ;
}
void F_170 ( struct V_75 * V_7 )
{
struct V_43 * V_46 = F_25 ( V_7 -> V_111 ) ;
F_30 ( & V_46 -> V_53 ) ;
F_155 ( & V_46 -> V_227 , 0 ) ;
F_80 ( V_46 , NULL , 0 , - V_103 ) ;
F_33 ( & V_46 -> V_53 ) ;
if ( V_92 ) {
F_77 ( & V_46 -> V_110 ) ;
F_77 ( & V_46 -> V_114 ) ;
F_77 ( & V_46 -> V_106 ) ;
F_171 ( V_92 ) ;
}
}
static void F_172 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
F_173 ( V_44 ) ;
if ( ! V_7 )
return;
if ( V_44 != F_89 () )
F_170 ( V_7 ) ;
F_24 ( F_79 ( & V_95 ) < 0 ) ;
}
static void F_174 ( struct V_75 * V_7 , int V_44 ,
void * V_88 )
{
struct V_43 * V_46 = F_25 ( V_44 ) ;
F_175 ( V_44 ) ;
F_24 ( ! V_7 ) ;
V_46 -> V_112 = V_113 -
( F_85 ( F_20 () ) + 1 ) ;
if ( V_44 != F_89 () ) {
F_30 ( & V_46 -> V_53 ) ;
F_155 ( & V_46 -> V_227 , 0 ) ;
if ( V_46 -> V_100 )
F_80 ( V_46 , NULL , 0 , 0 ) ;
F_33 ( & V_46 -> V_53 ) ;
}
}
void F_176 ( void )
{
F_177 ( NULL , & V_266 ) ;
F_177 ( NULL , & V_267 ) ;
}
int F_178 ( void )
{
int V_49 ;
F_179 ( & V_267 , V_268 ,
F_172 , NULL , V_269 ) ;
F_179 ( & V_266 , V_270 ,
F_174 , NULL , V_269 ) ;
V_49 = F_180 ( NULL , & V_266 ) ;
if ( V_49 == 0 )
V_49 = F_180 ( NULL , & V_267 ) ;
if ( V_49 )
F_176 () ;
return V_49 ;
}
static int F_181 ( struct V_167 * V_115 )
{
int V_49 , V_271 ;
struct V_245 sin ;
struct V_167 * V_272 = NULL ;
struct V_75 * V_7 = NULL ;
struct V_75 * V_273 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_43 * V_46 ;
F_24 ( V_115 == NULL ) ;
V_49 = F_182 ( V_115 -> V_116 -> V_274 , V_115 -> V_116 -> V_275 ,
V_115 -> V_116 -> V_276 , & V_272 ) ;
if ( V_49 )
goto V_64;
V_272 -> type = V_115 -> type ;
V_272 -> V_187 = V_115 -> V_187 ;
V_49 = V_115 -> V_187 -> V_277 ( V_115 , V_272 , V_264 ) ;
if ( V_49 < 0 )
goto V_64;
V_272 -> V_116 -> V_253 = V_51 ;
V_49 = F_158 ( V_272 ) ;
if ( V_49 ) {
F_45 ( V_183 , L_65 , V_49 ) ;
goto V_64;
}
V_271 = sizeof( sin ) ;
V_49 = V_272 -> V_187 -> V_278 ( V_272 , (struct V_261 * ) & sin ,
& V_271 , 1 ) ;
if ( V_49 < 0 )
goto V_64;
V_7 = F_183 ( sin . V_256 . V_257 ) ;
if ( V_7 == NULL ) {
F_86 ( V_108 L_70
L_71 , & sin . V_256 . V_257 ,
F_184 ( sin . V_259 ) ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( F_89 () >= V_7 -> V_111 ) {
V_273 = F_164 ( F_89 () ) ;
F_86 ( V_108 L_72
L_73
L_74 , V_273 -> V_279 , V_273 -> V_111 ,
& ( V_273 -> V_258 ) ,
F_184 ( V_273 -> V_262 ) , V_7 -> V_279 ,
V_7 -> V_111 , & sin . V_256 . V_257 , F_184 ( sin . V_259 ) ) ;
V_49 = - V_155 ;
goto V_64;
}
if ( ! F_185 ( V_7 -> V_111 ) ) {
F_45 ( V_104 , L_75
L_76 ,
V_7 -> V_279 , & sin . V_256 . V_257 ,
F_184 ( sin . V_259 ) ) ;
V_49 = - V_155 ;
goto V_64;
}
V_46 = F_25 ( V_7 -> V_111 ) ;
F_30 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_102 )
V_49 = - V_280 ;
else
V_49 = 0 ;
F_33 ( & V_46 -> V_53 ) ;
if ( V_49 ) {
F_86 ( V_108 L_77
L_78 ,
V_7 -> V_279 , & sin . V_256 . V_257 ,
F_184 ( sin . V_259 ) ) ;
goto V_64;
}
V_17 = F_60 ( V_7 ) ;
if ( V_17 == NULL ) {
V_49 = - V_156 ;
goto V_64;
}
V_17 -> V_72 = V_272 ;
V_272 = NULL ;
F_30 ( & V_46 -> V_53 ) ;
F_155 ( & V_46 -> V_227 , 0 ) ;
F_80 ( V_46 , V_17 , 0 , 0 ) ;
F_33 ( & V_46 -> V_53 ) ;
F_96 ( V_17 -> V_72 -> V_116 , V_17 ) ;
F_72 ( V_17 , & V_17 -> V_80 ) ;
F_159 () ;
F_124 ( V_17 , V_238 , sizeof( * V_238 ) ) ;
V_64:
if ( V_272 )
F_51 ( V_272 ) ;
if ( V_7 )
F_53 ( V_7 ) ;
if ( V_273 )
F_53 ( V_273 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
return V_49 ;
}
static void F_186 ( struct V_90 * V_91 )
{
struct V_167 * V_115 = V_281 ;
while ( F_181 ( V_115 ) == 0 )
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
if ( V_116 -> V_123 == V_282 ) {
F_45 ( V_164 , L_79 , V_117 ) ;
F_73 ( V_92 , & V_283 ) ;
}
V_64:
F_93 ( & V_116 -> V_118 ) ;
F_91 ( V_116 , V_117 ) ;
}
static int F_187 ( T_12 V_284 , T_13 V_285 )
{
struct V_167 * V_115 = NULL ;
int V_49 ;
struct V_245 sin = {
. V_254 = V_250 ,
. V_256 = { . V_257 = V_284 } ,
. V_259 = V_285 ,
} ;
V_49 = F_165 ( V_250 , V_251 , V_252 , & V_115 ) ;
if ( V_49 < 0 ) {
F_86 ( V_286 L_80 , V_49 ) ;
goto V_64;
}
V_115 -> V_116 -> V_253 = V_51 ;
F_97 ( & V_115 -> V_116 -> V_118 ) ;
V_115 -> V_116 -> V_119 = V_115 -> V_116 -> V_121 ;
V_115 -> V_116 -> V_121 = V_129 ;
F_99 ( & V_115 -> V_116 -> V_118 ) ;
V_281 = V_115 ;
F_67 ( & V_283 , F_186 ) ;
V_115 -> V_116 -> V_287 = V_288 ;
V_49 = V_115 -> V_187 -> V_260 ( V_115 , (struct V_261 * ) & sin , sizeof( sin ) ) ;
if ( V_49 < 0 ) {
F_86 ( V_286 L_81
L_82 , V_49 , & V_284 , F_184 ( V_285 ) ) ;
goto V_64;
}
V_49 = V_115 -> V_187 -> V_289 ( V_115 , 64 ) ;
if ( V_49 < 0 )
F_86 ( V_286 L_83 ,
V_49 , & V_284 , F_184 ( V_285 ) ) ;
V_64:
if ( V_49 ) {
V_281 = NULL ;
if ( V_115 )
F_51 ( V_115 ) ;
}
return V_49 ;
}
int F_188 ( struct V_75 * V_7 )
{
int V_49 = 0 ;
F_24 ( V_92 != NULL ) ;
F_24 ( V_281 != NULL ) ;
F_45 ( V_290 , L_84 ) ;
V_92 = F_189 ( L_85 ) ;
if ( V_92 == NULL ) {
F_45 ( V_183 , L_86 ) ;
return - V_156 ;
}
V_49 = F_187 ( V_7 -> V_258 ,
V_7 -> V_262 ) ;
if ( V_49 ) {
F_190 ( V_92 ) ;
V_92 = NULL ;
} else
F_88 ( V_7 -> V_111 ) ;
return V_49 ;
}
void F_191 ( struct V_75 * V_7 )
{
struct V_167 * V_115 = V_281 ;
T_8 V_291 ;
F_24 ( V_92 == NULL ) ;
F_24 ( V_281 == NULL ) ;
F_97 ( & V_115 -> V_116 -> V_118 ) ;
V_115 -> V_116 -> V_121 = V_115 -> V_116 -> V_119 ;
V_115 -> V_116 -> V_119 = NULL ;
F_99 ( & V_115 -> V_116 -> V_118 ) ;
for ( V_291 = 0 ; V_291 < F_26 ( V_45 ) ; V_291 ++ ) {
struct V_75 * V_7 = F_164 ( V_291 ) ;
if ( V_7 ) {
F_170 ( V_7 ) ;
F_53 ( V_7 ) ;
}
}
F_45 ( V_290 , L_87 ) ;
F_190 ( V_92 ) ;
V_92 = NULL ;
F_51 ( V_281 ) ;
V_281 = NULL ;
F_84 ( V_7 -> V_111 ) ;
}
int F_192 ( void )
{
unsigned long V_291 ;
F_193 () ;
if ( F_194 () )
return - V_156 ;
V_238 = F_62 ( sizeof( struct V_218 ) , V_292 ) ;
V_242 = F_62 ( sizeof( struct V_190 ) , V_292 ) ;
V_211 = F_62 ( sizeof( struct V_190 ) , V_292 ) ;
if ( ! V_238 || ! V_242 || ! V_211 ) {
F_55 ( V_238 ) ;
F_55 ( V_242 ) ;
F_55 ( V_211 ) ;
return - V_156 ;
}
V_238 -> V_220 = F_152 ( V_221 ) ;
V_238 -> V_241 = F_152 ( 1 ) ;
V_242 -> V_192 = F_130 ( V_210 ) ;
V_211 -> V_192 = F_130 ( V_212 ) ;
for ( V_291 = 0 ; V_291 < F_26 ( V_45 ) ; V_291 ++ ) {
struct V_43 * V_46 = F_25 ( V_291 ) ;
F_155 ( & V_46 -> V_227 , 0 ) ;
F_195 ( & V_46 -> V_53 ) ;
F_68 ( & V_46 -> V_114 , F_163 ) ;
F_68 ( & V_46 -> V_110 ,
F_167 ) ;
F_68 ( & V_46 -> V_106 , F_168 ) ;
V_46 -> V_100 = - V_103 ;
F_34 ( & V_46 -> V_105 ) ;
F_196 ( & V_46 -> V_50 ) ;
F_2 ( & V_46 -> V_56 ) ;
}
return 0 ;
}
void F_197 ( void )
{
F_198 () ;
F_55 ( V_238 ) ;
F_55 ( V_242 ) ;
F_55 ( V_211 ) ;
F_199 () ;
}
